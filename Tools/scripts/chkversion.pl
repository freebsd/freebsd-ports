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
# install port sysutils/pkg_install-devel (optional)
#  mkdir -p /var/db/chkversion
#  touch /var/db/chkversion/VERSIONS
#  chown -R ports /var/db/chkversion
# and enter chkversions.pl into the crontab of ports, or run it by hand
# if you can spare the time.
#
# If the environment variable CVSBLAME is set and the ports tree is checked
# out by CVS, every entry is listed with a record of the last CVS commit.
#

require 5.005;
use strict;
use File::Find;
use Cwd 'abs_path';

my $portsdir   = $ENV{PORTSDIR}   ? $ENV{PORTSDIR}   : '/usr/ports';
my $versiondir = $ENV{VERSIONDIR} ? $ENV{VERSIONDIR} : '/var/db/chkversion';
my $cvsblame   = $ENV{CVSBLAME}   ? 1                : 0;
my $allports   = $ENV{ALLPORTS}   ? 1                : 0;

my $make        = '/usr/bin/make';
my $cvs         = '/usr/bin/cvs';
my $pkg_version =
    $ENV{PKG_VERSION} && -x $ENV{PKG_VERSION} ? $ENV{PKG_VERSION}
  : -x '/usr/local/sbin/pkg_version' ? '/usr/local/sbin/pkg_version'
  : '/usr/sbin/pkg_version';

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
        my @makevar = readfrom $File::Find::name,
          $make, '-VPKGORIGIN', '-VPKGNAME';

        $pkgorigin{$1} = $makevar[0]
          if $makevar[0] && $1 ne $makevar[0];
        $pkgname{$1} = $makevar[1]
          if $makevar[1];

        $File::Find::prune = 1;
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
              $make, '-VPKGORIGIN', '-VPKGNAME';
            $pkgorigin{$_} = $makevar[0]
              if $makevar[0] && $_ ne $makevar[0];
            $pkgname{$_} = $makevar[1]
              if $makevar[1];
        }
    }
}

my %backwards;

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
    print VERSIONS join("\n", map("$_\t$pkgname{$_}", sort keys %pkgname)),
      "\n";
    close VERSIONS;
}

sub blame {
    my ($msg, $ports) = @_;

    if (%{$ports}) {
        print "$msg\n";
        foreach (sort keys %{$ports}) {
            print "- $_: $ports->{$_}\n";
            if ($cvsblame && -d "$portsdir/$_/CVS") {
                my @cvslog = readfrom "$portsdir/$_",
                  $cvs, '-R', 'log', '-N', '-r.', 'Makefile';
                print "  ", join("\n  " , grep(/^-/ .. /^=/, @cvslog)), "\n\n";
            }
        }
        print "\n";
    }
}

blame
  "** The following ports have a wrong PKGORIGIN **\n\n"
  . " PKGORIGIN connects packaged or installed ports to the directory they\n"
  . " originated from. This is essential for tools like pkg_version or\n"
  . " portupgrade to work correctly. Wrong PKGORIGINs are often caused by a\n"
  . " wrong order of CATEGORIES after a repocopy.\n",
  \%pkgorigin;

blame
  "** The following ports have a version number that sorts before a previous one **\n\n"
  . " For many package tools to work correctly, it is of utmost importance that\n"
  . " version numbers of a port form a monotonic increasing sequence over time.\n"
  . " Refer to the FreeBSD Porter's Handbook, 'Package Naming Conventions' for\n"
  . " more information. Tools that won't work include pkg_version, portupgrade\n"
  . " and portaudit. A common problem is an accidental deletion of PORTEPOCH.\n",
  \%backwards;

exit((%pkgorigin || %backwards) ? 1 : 0);
