#!/usr/bin/perl -w
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
# $FreeBSD$
#
# MAINTAINER=   eik@FreeBSD.org
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
#  CVSBLAME=yes
#  ALLPORTS=yes
#  RCPT_ORIGIN=you@domain.example
#  RCPT_VERSION=you@domain.example
#  0	*/2	*	*	*	/usr/ports/Tools/scripts/chkversion.pl
#
# into `crontab -u ports -e', or run the script by hand if you can spare the time.
#
# If the environment variable CVSBLAME is set and the ports tree is checked
# out by CVS, every entry is listed with a record of the last CVS commit.
#

require 5.005;
use strict;
use File::Find;
use Cwd 'abs_path';

my $portsdir   = $ENV{PORTSDIR}         ? $ENV{PORTSDIR}         : '/usr/ports';
my $versiondir = $ENV{VERSIONDIR}       ? $ENV{VERSIONDIR}       : '/var/db/chkversion';
my $cvsblame   = $ENV{CVSBLAME}         ? 1                      : 0;
my $allports   = $ENV{ALLPORTS}         ? 1                      : 0;

my $watchre    = $ENV{WATCH_REGEX}      ? $ENV{WATCH_REGEX}      : '';
my $returnpath = $ENV{RETURNPATH}       ? $ENV{RETURNPATH}       : '';
my $h_from     = $ENV{HEADER_FROM}      ? $ENV{HEADER_FROM}      : "$ENV{USER}\@$ENV{HOST}";
my $h_replyto  = $ENV{HEADER_REPLYTO}   ? $ENV{HEADER_REPLYTO}   : $h_from;
my $rcpt_watch = $ENV{RCPT_WATCH}       ? $ENV{RCPT_WATCH}       : '';
my $rcpt_orig  = $ENV{RCPT_ORIGIN}      ? $ENV{RCPT_ORIGIN}      : '';
my $rcpt_vers  = $ENV{RCPT_VERSION}     ? $ENV{RCPT_VERSION}     : '';

my $make        = '/usr/bin/make';
my $cvs         = '/usr/bin/cvs';
my $pkg_version =
    $ENV{PKG_VERSION} && -x $ENV{PKG_VERSION} ? $ENV{PKG_VERSION}
  : -x '/usr/local/sbin/pkg_version' ? '/usr/local/sbin/pkg_version'
  : '/usr/sbin/pkg_version';
my $sendmail    = '/usr/sbin/sendmail';

my $watch_re = join "|", split " ", $watchre;

-d $portsdir or die "Can't find ports tree at $portsdir.\n";
$portsdir = abs_path($portsdir);

my $versionfile = "$versiondir/VERSIONS";
my $useindex    = !-w $versiondir;

sub readfrom {
    my $dir = shift;

    if (!open CHILD, '-|') {
        open STDERR, '>/dev/null';
        chdir $dir if $dir;
        exec @_;
        die;
    }
    my @childout = <CHILD>;
    close CHILD;

    map chomp, @childout;

    return wantarray ? @childout : $childout[0];
}

foreach (qw(ARCH OPSYS OSREL OSVERSION PKGINSTALLVER PORTOBJFORMAT UID)) {
    my @cachedenv = readfrom $portsdir, $make, "-V$_";
    $ENV{$_} = $cachedenv[0];
}
$ENV{WITH_OPENSSL_BASE} = 'yes';

my %pkgname;
my %pkgorigin;
my %maintainer;

sub wanted {
    return
      if !-d;

    if (/^CVS$/
        || $File::Find::name =~
          m"^$portsdir/(?:Mk|Templates|Tools|distfiles|packages)$"os
        || $File::Find::name =~ m"^$portsdir/[^/]+/pkg$"os)
    {
        $File::Find::prune = 1;
    }
    elsif ($File::Find::name =~ m"^$portsdir/([^/]+/[^/]+)$"os) {
        $File::Find::prune = 1;
        my @makevar = readfrom $File::Find::name,
          $make, '-VPKGORIGIN', '-VPKGNAME';

        $pkgorigin{$1} = $makevar[0]
          if $makevar[0] && $1 ne $makevar[0];
        $pkgname{$1} = $makevar[1]
          if $makevar[1];
        $maintainer{$_} = $makevar[2]
          if $makevar[2];
    }
}

if ($allports) {
    find(\&wanted, $portsdir);
}
else {
    my @categories = split ' ', readfrom $portsdir, $make, '-VSUBDIR';

    foreach my $category (@categories) {
        -f "$portsdir/$category/Makefile" || next;
        my @ports = split ' ',
          readfrom "$portsdir/$category", $make, '-VSUBDIR';
        foreach (map "$category/$_", @ports) {
            -f "$portsdir/$_/Makefile" || next;
            my @makevar = readfrom "$portsdir/$_",
              $make, '-VPKGORIGIN', '-VPKGNAME', '-VMAINTAINER';

            $pkgorigin{$_} = $makevar[0]
              if $makevar[0] && $_ ne $makevar[0];
            $pkgname{$_} = $makevar[1]
              if $makevar[1];
            $maintainer{$_} = $makevar[2]
              if $makevar[2];
        }
    }
}

my %backwards;
my %watched;

if ($useindex) {
    my $indexname = readfrom $portsdir, $make, '-VINDEXFILE';
    $versionfile = "$portsdir/$indexname";
}

open VERSIONS, "<$versionfile";

while (<VERSIONS>) {
    chomp;
    next if /^(#|$)/;
    my ($origin, $version);
    if ($useindex) {
        ($version, $origin) = split /\|/;
        $origin =~ s,^.*/([^/]+/[^/]+)/?$,$1,;
    }
    else {
        ($origin, $version) = split;
    }
    if (defined $pkgname{$origin}) {
        my $newversion = $pkgname{$origin};
        my $oldversion = $version;

        $newversion =~ s/^.*-//;
        $oldversion =~ s/^.*-//;

        my $result = $newversion eq $oldversion ? '=' : readfrom '',
          $pkg_version, '-t', $newversion, $oldversion;

        $watched{$origin} = "$version -> $pkgname{$origin}"
          if ($result ne '=' && $watch_re && $pkgname{$origin} =~ /^(?:$watch_re)$/o);

        if ($result eq '<') {
            $backwards{$origin} = "$pkgname{$origin} < $version";
            $pkgname{$origin}   = $version;
        }
    }
    else {
        $pkgname{$origin} = $version;
    }
}
close VERSIONS;

if (!$useindex) {
    system 'mv', '-f', $versionfile, "$versionfile.bak";

    open VERSIONS, ">$versionfile";
    foreach (sort keys %pkgname) {
        print VERSIONS "$_\t$pkgname{$_}\n";
    }
    close VERSIONS;
}

sub blame {
    my ($fh, $ports) = @_;

    if (%{$ports}) {
        foreach my $origin (sort keys %{$ports}) {
            my $maint = $maintainer{$origin} ? " <$maintainer{$origin}>" : '';
            print $fh "- *$origin*$maint: $ports->{$origin}\n";
            if ($cvsblame && -d "$portsdir/$origin/CVS") {
                my @cvslog = readfrom "$portsdir/$origin",
                  $cvs, '-R', 'log', '-N', '-r.', 'Makefile';
                foreach (@cvslog) {
                    my $in_log = /^-/ ... /^=/;
                    print $fh "   | $_\n"
                      if ($in_log && $in_log != 1 && $in_log !~ /E0$/);
                }
                print $fh "\n";
            }
        }
        print $fh "\n";
    }
}

sub template {
    my ($from, $rcpt, $replyto) = @_;

    my $header = '';
    while (<main::DATA>) {
        last if /^\.\n?$/;
        $_ =~ s/%%FROM%%/$from/og;
        $_ =~ s/%%RCPT%%/$rcpt/og;
        $_ =~ s/%%REPLYTO%%/$replyto/og;
        $header .= $_;
    }
    return $header;
}

sub mail {
    my ($template, $rcpt, $ports) = @_;

    if (%{$ports}) {
        if ($rcpt) {
            if (!open MAIL, '|-') {
                exec $sendmail, '-oi', '-t', '-f', $returnpath;
                die;
            }
            print MAIL $template;
            blame *MAIL, $ports;
            close MAIL;
        } else {
            $template =~ s/^.*?\n\n//os;
            print $template;
            blame *STDOUT, $ports;
        }
    }
}

my $tmpl;

$tmpl = template $h_from, $rcpt_orig, $h_replyto;
mail $tmpl, $rcpt_orig, \%pkgorigin;

$tmpl = template $h_from, $rcpt_vers, $h_replyto;
mail $tmpl, $rcpt_vers, \%backwards;

$tmpl = template $h_from, $rcpt_watch, $h_replyto;
mail $tmpl, $rcpt_watch, \%watched;

exit((%pkgorigin || %backwards) ? 1 : 0);

__END__
From: %%FROM%%
To: %%RCPT%%
Reply-To: %%REPLYTO%%
Subject: Ports with a wrong PKGORIGIN

** The following ports have a wrong PKGORIGIN **

 PKGORIGIN connects packaged or installed ports to the directory they
 originated from. This is essential for tools like pkg_version or
 portupgrade to work correctly. Wrong PKGORIGINs are often caused by a
 wrong order of CATEGORIES after a repocopy.

.
From: %%FROM%%
To: %%RCPT%%
Reply-To: %%REPLYTO%%
Subject: Ports with version numbers going backwards

** The following ports have a version number that sorts before a previous one **

 For many package tools to work correctly, it is of utmost importance that
 version numbers of a port form a monotonic increasing sequence over time.
 Refer to the FreeBSD Porter's Handbook, 'Package Naming Conventions' for
 more information. Tools that won't work include pkg_version, portupgrade
 and portaudit. A common problem is an accidental deletion of PORTEPOCH.

.
From: %%FROM%%
To: %%RCPT%%
Reply-To: %%REPLYTO%%
Subject: Version changes in watched ports

** The following ports have changed version numbers **

 You have requested to be notified of version changes in the following
 ports:

.
