#!/usr/bin/env perl
#
# Copyright (c) 2004 Oliver Eikemeier. All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are
# met:
#
# 1. Redistributions of source code must retain the above copyright notice
#    this list of conditions and the following disclaimer.
#
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
#
# 3. Neither the name of the author nor the names of its contributors may be
#    used to endorse or promote products derived from this software without
#    specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
# INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
# AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
# COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
# INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
# NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
# DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
# THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
# THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
# $FreeBSD: head/Tools/scripts/chkversion.pl 562503 2021-01-24 18:42:29Z adamw $
#
# MAINTAINER=   portmgr@FreeBSD.org
#
# PORTVERSION and PKGORIGIN auditing script
#
# This scripts compares version numbers with previously known ones, and
# checks ports for a correct PKGORIGIN. It is primarily intended to be run
# from a (non-root) cron job.
#
# If you just call it with no preparation, it will compare all port versions
# with their INDEX entries and complain if they have gone backwards. You need
# You need an old INDEX for this, of course. An up-to-date INDEX will accomplish
# nothing.
#
# To use the script as intended, do the following (assuming you want to
# run the script as user `ports'):
#
# install port sysutils/pkg_install-devel (optional)
#  mkdir -p /var/db/chkversion
#  touch /var/db/chkversion/VERSIONS
#  chown -R ports /var/db/chkversion
# and enter something like
#
#  BLAME=yes (git specific)
#  SVNBLAME=yes   # XXX: SVN specific
#  ALLPORTS=yes
#  RCPT_ORIGIN=you@domain.example
#  RCPT_VERSION=you@domain.example
#  0	*/2	*	*	*	/usr/ports/Tools/scripts/chkversion.pl
#
# into `crontab -u ports -e', or run the script by hand if you can spare the time.
#
# If the environment variable BLAME is set and the ports tree is checked
# out by git, every entry is listed with a record of the last git commit.
#
# XXX: SVN specific:
# If the environment variable SVNBLAME is set and the ports tree is checked
# out by SVN, every entry is listed with a record of the last SVN commit.
#

use v5.20;
use strict;
use warnings;

use feature qw(signatures);
no warnings qw(experimental::signatures);

use Cwd 'abs_path';
use File::Find;
use List::Util qw(first);
use POSIX;

my $portsdir    = $ENV{PORTSDIR}        // '/usr/ports';
my $versiondir  = $ENV{VERSIONDIR}      // '/var/db/chkversion';
my $svnblame    = exists $ENV{SVNBLAME};  # XXX: SVN specific
my $blame       = exists $ENV{BLAME};
my $allports    = exists $ENV{ALLPORTS};

my $watch_re    = $ENV{WATCH_REGEX}     // '';
my $watchm_re   = $ENV{WATCHM_REGEX}    // '';
my $returnpath  = $ENV{RETURNPATH}      // '';
my $h_from      = $ENV{HEADER_FROM}     // $ENV{USER} . '@' . ($ENV{HOST} // `/bin/hostname`);
my $h_replyto   = $ENV{HEADER_REPLYTO}  // $h_from;
my $rcpt_watch  = $ENV{RCPT_WATCH}      // '';
my $rcpt_watchm = $ENV{RCPT_WATCHM}     // '';
my $rcpt_orig   = $ENV{RCPT_ORIGIN}     // '';
my $rcpt_vers   = $ENV{RCPT_VERSION}    // '';
my $cc_author   = exists $ENV{CC_AUTHOR};
my $cc_mntnr    = exists $ENV{CC_MAINTAINER};

my $make        = '/usr/bin/make';
my $svn         = '/usr/local/bin/svn';  # XXX: SVN specific
my $git         = '/usr/local/bin/git';
my $sendmail    = '/usr/sbin/sendmail';
my $pkg         = first { -x $_ } ($ENV{PKG} // '', '/usr/local/sbin/pkg', '/usr/sbin/pkg');

$watch_re  =~ s/ /|/g;
$watchm_re =~ s/ /|/g;

-d $portsdir or die "Can't find ports tree at $portsdir.\n";
$portsdir = abs_path($portsdir);

my $versionfile = "$versiondir/VERSIONS";
my $useindex    = !-w $versiondir;

my $starttime = strftime "%a %b %e %G %k:%M:%S %Z", localtime;

# @output_lines = readfrom(dir, cmd, arg1, arg2, ...)
sub readfrom($dir, @cmd) {
    my $CHILD;
    if (!open $CHILD, '-|') {
        open STDERR, '>', '/dev/null';
        chdir $dir if $dir;
        exec @cmd;
        die;
    }
    my @childout = <$CHILD>;
    close $CHILD;

    map chomp, @childout;

    return wantarray ? @childout : $childout[0];
}

for (qw(ARCH OPSYS OSREL OSVERSION UID)) {
    my @cachedenv = readfrom($portsdir, $make, "-V$_");
    $ENV{$_} = $cachedenv[0];
}

# These map a 2-dir path (editors/vim) to variables set in
# that port's Makefile
my %pkgname;
my %pkgorigin;
my %masterdir;
my %pkgmntnr;

sub wanted() {
    return unless -d;

    # Skip directories we shouldn't descend into
    # if (/^.git$/
    if (/^\.git$/
        || /^\.svn$/   # XXX: SVN specific
        || $File::Find::name =~ m"^$portsdir/(?:Mk|Templates|Tools|distfiles|packages)$"os
        || $File::Find::name =~ m"^$portsdir/[^/]+/pkg$"os)
    {
        $File::Find::prune = 1;
    }
    elsif ($File::Find::name =~ m"^$portsdir/([^/]+/[^/]+)$"os) {
        $File::Find::prune = 1;
        if (-f "$File::Find::name/Makefile") {
            my @makevar = readfrom $File::Find::name, $make, qw(-VPKGORIGIN -VPKGNAME -VMAINTAINER -VMASTERDIR);

            # $1 is the current 2-dir path
            if ($#makevar == 3 && $makevar[1]) {
                # %pkgorigin is the list of dirs that gets monitored. Only monitor a
                # path if it matches the PKGORIGIN.
                $pkgorigin{$1} = $makevar[0] if $1 ne $makevar[0];
                $pkgname{$1}   = $makevar[1];
                $pkgmntnr{$1}  = $makevar[2];
                $masterdir{$1} = $makevar[3];
            }
        }
    }
}

if ($allports) {
    find(\&wanted, $portsdir);
}
else {
    my @categories = split ' ' => readfrom($portsdir, $make, '-VSUBDIR');

    for my $category (@categories) {
        next unless -f "$portsdir/$category/Makefile";
        my @ports = split ' ' => readfrom("$portsdir/$category", $make, '-VSUBDIR');
        for (map "$category/$_", @ports) {
            next unless -f "$portsdir/$_/Makefile";

            my @makevar = readfrom "$portsdir/$_", $make, qw(-VPKGORIGIN -VPKGNAME -VMAINTAINER -VMASTERDIR);

            next if $#makevar != 3 || ! $makevar[1];
            $pkgorigin{$_} = $makevar[0] if $_ ne $makevar[0];
            $pkgname{$_}   = $makevar[1];
            $pkgmntnr{$_}  = $makevar[2];
            $masterdir{$_} = $makevar[3];
        }
    }
}

my %backwards;
my %watched;
my %watchedm;

if ($useindex) {
    my $indexname = readfrom $portsdir, $make, '-VINDEXFILE';
    $versionfile = "$portsdir/$indexname";
}

# Read in the old (expected) values
open my $VERSIONS, '<', $versionfile;
while (<$VERSIONS>) {
    chomp;
    next if /^(#|$)/;

    # These are the old (expected) values
    my ($origin, $version, $maintainer);

    if ($useindex) {
        ($origin, $version, $maintainer) = (split '|')[1,0,5];
        # Only keep the 2-dir path (editors/vim)
        $origin =~ s,^.*/([^/]+/[^/]+)/?$,$1,;
    }
    else {
        ($origin, $version, $maintainer) = split /\t/;
    }
    if (defined $pkgname{$origin}) {
        my $newversion = $pkgname{$origin};
        my $oldversion = $version;

        $newversion =~ s/^.*-//;
        $oldversion =~ s/^.*-//;

        # If the two values differ, use `pkg version` to find which one is bigger
        my $result = $newversion eq $oldversion ? '='
                   : readfrom '', $pkg, 'version', '-t', $newversion, $oldversion;

        $watched{$origin} = "$version -> $pkgname{$origin}"
          if ($watch_re && $result ne '=' && $origin =~ /^(?:$watch_re)$/o);

        $watchedm{$origin} = "(was <$maintainer>) $version -> $pkgname{$origin}"
          if ($watchm_re && $maintainer && $pkgmntnr{$origin}
            && $maintainer ne $pkgmntnr{$origin} && $origin =~ /^(?:$watchm_re)$/o);

        if ($result eq '<') {
            $backwards{$origin} = "$pkgname{$origin} < $version";
            $pkgname{$origin}   = $version;
        }
    }
    elsif ($origin) {
        $pkgname{$origin} = $version;
        $pkgmntnr{$origin} = $maintainer;
    }
}
close $VERSIONS;

if (!$useindex) {
    rename $versionfile, "$versionfile.bak";

    open my $VERSIONS, '>', $versionfile;
    for (sort keys %pkgname) {
        print $VERSIONS "$_\t$pkgname{$_}\t$pkgmntnr{$_}\n";
    }
    close $VERSIONS;
}

my %revision;

# Parses the $FreeBSD$ line to return revision, date, author
sub parsemakefile($portdir) {
    open my $MAKEFILE, '<', "$portdir/Makefile";
    while (<$MAKEFILE>) {
        if (m/^# \$FreeBSD: [^ ]+ (?<rev>\d{6}) (?<date>\d{4}-\d\d-\d\d) [\d:]+Z (?<author>\w+) \$$/) {
            close $MAKEFILE;
            return ($+{rev}, $+{date}, $+{author});
        }
    }
    close $MAKEFILE;
}

sub getauthors($ports) {
    my %author;
    for my $origin (keys %{$ports}) {
        if (!$revision{$origin}) {
            my ($r, $d, $a) = parsemakefile "$portsdir/$origin";
            push @{$revision{$origin}}, $r;
            push @{$author{$origin}}, $a;

            if ($masterdir{$origin} ne "$portsdir/$origin") {
                ($r, $d, $a) = parsemakefile $masterdir{$origin};
                push @{$revision{$origin}}, $r;
                push @{$author{$origin}}, $a;
            }
        }

    }

    return %author;
}

# Gets the Makefile log starting from the last known rev for a port
sub printlog($fh, $portdir, $rev) {
    if ($blame && -d "$portsdir/.git") {
        my @log = readfrom $portdir, $git, 'log', "${rev}^..HEAD", 'Makefile';
        print $fh "   | $_\n" for @log;
    }
    # XXX: SVN specific:
    elsif ($svnblame && -d "$portsdir/.svn") {
        my @svnlog = readfrom $portdir, $svn, 'log', ($rev ? "-r$rev" : ''), 'Makefile';
        for (@svnlog) {
            my $in_log = /^-{20,}$/ ... /^(-{20,}|={70,})$/;
            print $fh "   | $_\n"
              if ($in_log && $in_log ne 1 && $in_log !~ /E0$/);
        }
    }
}

# Git version:
# sub printlog($fh, $portdir, $rev) {
# }

sub blame($fh, $ports) {
    if (%{$ports}) {
        for my $origin (sort keys %{$ports}) {
            print $fh "- *$origin* <$pkgmntnr{$origin}>: $ports->{$origin}\n";
            printlog $fh, "$portsdir/$origin", $revision{$origin}[0];
            if ($masterdir{$origin} ne "$portsdir/$origin") {
                my $master = $masterdir{$origin};
                $master =~ s|^$portsdir/||o;
                while ($master =~ s!(^|/)[^/]+/\.\.(?:/|$)!$1!) {}
                print $fh "  (master: $master)\n";
                printlog $fh, $masterdir{$origin}, $revision{$origin}[1];
            }
            print $fh "\n";
        }
        print $fh "\n";
    }
}

sub template($from, $rcpt, $replyto, $starttime, $ports) {
    my $portlist = join ', ' => sort keys %{$ports};
    substr($portlist, 32) = '...'
        if length $portlist > 35;

    my %cclist;
    my %author = getauthors $ports;

    if ($cc_author) {
        for (map @{$author{$_} ? $author{$_} : []}, keys %{$ports}) {
            $cclist{"$_\@FreeBSD.org"} = 1
                if $_;
        }
    }
    if ($cc_mntnr) {
        for (map $pkgmntnr{$_}, keys %{$ports}) {
            $cclist{$_} = 1
                if $_;
        }
    }
    my $cc = join ', ' => sort keys %cclist;

    my $header = '';
    while (<main::DATA>) {
        last if /^\.\n?$/;
        $header .= $_
          =~ s/%%FROM%%/$from/ogr
          =~ s/%%RCPT%%/$rcpt/ogr
          =~ s/%%CC%%/$cc/ogr
          =~ s/%%REPLYTO%%/$replyto/ogr
          =~ s/%%SUBJECT%%/$portlist/ogr
          =~ s/%%STARTTIME%%/$starttime/ogr;
    }
    return $header;
}

sub mail($template, $rcpt, $ports) {
    if (%{$ports}) {
        # If the RCPT_* variables are empty, just print the mail to STDOUT
        if ($rcpt) {
            my $MAIL;
            if (!open $MAIL, '|-') {
                exec $sendmail, qw(-oi -t -f), $returnpath;
                die;
            }
            print $MAIL $template;
            blame $MAIL, $ports;
            close $MAIL;
        } else {
            $template =~ s/^.*?\n\n//os;
            print $template;
            blame *STDOUT, $ports;
        }
    }
}

my $tmpl;

$tmpl = template $h_from, $rcpt_orig, $h_replyto, $starttime, \%pkgorigin;
mail $tmpl, $rcpt_orig, \%pkgorigin;

$tmpl = template $h_from, $rcpt_vers, $h_replyto, $starttime, \%backwards;
mail $tmpl, $rcpt_vers, \%backwards;

$tmpl = template $h_from, $rcpt_watch, $h_replyto, $starttime, \%watched;
mail $tmpl, $rcpt_watch, \%watched;

$tmpl = template $h_from, $rcpt_watch, $h_replyto, $starttime, \%watchedm;
mail $tmpl, $rcpt_watchm, \%watchedm;

exit((%pkgorigin || %backwards) ? 1 : 0);

__END__
From: %%FROM%%
To: %%RCPT%%
CC: %%CC%%
Reply-To: %%REPLYTO%%
Subject: Ports with a broken PKGORIGIN: %%SUBJECT%%
X-FreeBSD-Chkversion: PKGORIGIN

** The following ports have an incorrect PKGORIGIN **

 PKGORIGIN connects packaged or installed ports to the directory they
 originated from. This is essential for tools like pkg_version or
 portupgrade to work correctly. Wrong PKGORIGINs are often caused by a
 wrong order of CATEGORIES after a repocopy.

 Please fix any errors as soon as possible.

 The ports tree was updated at %%STARTTIME%%.

.
From: %%FROM%%
To: %%RCPT%%
CC: %%CC%%
Reply-To: %%REPLYTO%%
Subject: Ports with version numbers going backwards: %%SUBJECT%%
X-FreeBSD-Chkversion: backwards

** The following ports have a version number that sorts before a previous one **

 For many package tools to work correctly, it is of utmost importance that
 version numbers of a port form a monotonic increasing sequence over time.
 Refer to the FreeBSD Porter's Handbook, 'Package Naming Conventions' for
 more information. Tools that won't work include pkg_version, portupgrade
 and portaudit. A common error is an accidental deletion of PORTEPOCH.

 Please fix any errors as soon as possible.

 The ports tree was updated at %%STARTTIME%%.

.
From: %%FROM%%
To: %%RCPT%%
Reply-To: %%REPLYTO%%
Subject: Version changes in your watched ports: %%SUBJECT%%
X-FreeBSD-Chkversion: vwatch

** The following ports have changed version numbers **

 You have requested to be notified of version changes in the following
 ports:

 The ports tree was updated at %%STARTTIME%%.

.
From: %%FROM%%
To: %%RCPT%%
Reply-To: %%REPLYTO%%
Subject: Maintainer changes in your watched ports: %%SUBJECT%%
X-FreeBSD-Chkversion: mwatch

** The following ports have changed maintainers **

 You have requested to be notified of maintainer changes in the following
 ports:

 The ports tree was updated at %%STARTTIME%%.

.
