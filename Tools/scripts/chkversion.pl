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
# MAINTAINER=	eik@FreeBSD.org
#
# PORTVERSION auditing script
#
# For many port tools to work correctly, it is of utmost importance that
# PORTVERSION/-REVISION/-EPOCH of a port is a monotonic increasing sequence
# over time. See also
#   <http://www.freebsd.org/doc/en_US.ISO8859-1/books/porters-handbook/makefile-naming.html>
# for more information. Tools that won't work include pkg_version, portupgrade
# and portaudit. One common example is an accidentially deleted PORTEPOCH.
#
# This scripts compares version numbers with previously known ones, and is
# primarily intended to be run from a (non-root) cron job.
#
# If you simply call it, it will compare all ports with their INDEX entry
# and complain if version numbers have gone backwards. You need and old
# INDEX for this, of course. An up-to-date INDEX will accomplish nothing.
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

require 5.005;
use strict;
use File::Find;
use Cwd 'abs_path';

my $portsdir   = $ENV{PORTSDIR}   ? $ENV{PORTSDIR}   : '/usr/ports';
my $versiondir = $ENV{VERSIONDIR} ? $ENV{VERSIONDIR} : '/var/db/chkversion';
my $cvsblame   = $ENV{CVSBLAME}   ? 1                : 0;

my $pkg_version =
  -x '/usr/local/sbin/pkg_version'
   ? '/usr/local/sbin/pkg_version'
   : '/usr/sbin/pkg_version';

-d "$portsdir" or die "Can't find ports tree at $portsdir.\n";
$portsdir = abs_path($portsdir);

my $useindex = !-w "$versiondir";

my $versionfile =
  $useindex
  ? "$portsdir/".`cd $portsdir; /usr/bin/make -VINDEXFILE`
  : "$versiondir/VERSIONS";
chomp $versionfile;

my %cachedenv = ('WITH_OPENSSL_BASE' => 'yes');
foreach (qw(ARCH OPSYS OSREL OSVERSION PKGINSTALLVER PORTOBJFORMAT UID)) {
    $cachedenv{$_} = `cd $portsdir; /usr/bin/make -V$_`;
    chomp $cachedenv{$_};
}
my $makeenv = join ' ', '/usr/bin/env', map { "$_='$cachedenv{$_}'" } keys %cachedenv;

my %pkgname;

sub wanted {
    !-d
    || (/^CVS$/
        || $File::Find::name =~
          m"^$portsdir/(?:Mk|Templates|Tools|distfiles|packages)$"os
        || $File::Find::name =~ m"^$portsdir/[^/]+/pkg$"os
    )
      && ($File::Find::prune = 1)
    || $File::Find::name =~ m"^$portsdir/([^/]+/[^/]+)$"os
      && ($File::Find::prune = 1)
      && (
        $pkgname{$1} =
          `cd "$File::Find::name"; $makeenv /usr/bin/make -VPKGNAME 2>/dev/null`,
        chomp $pkgname{$1}
      );
}

find(\&wanted, $portsdir);

my %backwards;

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

        my $result = `$pkg_version -t '$newversion' '$oldversion'`;
        chomp $result;
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
    system "mv -f '$versionfile' '$versionfile.bak'";

    open VERSIONS, ">$versionfile";
    print VERSIONS join("\n", map("$_\t$pkgname{$_}", sort keys %pkgname)),
      "\n";
    close VERSIONS;
}

if (%backwards) {
    print "Package versions going backwards:\n";
    foreach (sort keys %backwards) {
        print " - $_: $backwards{$_}\n";
        if ($cvsblame && -d "$portsdir/$_/CVS") {
            my @cvslog =
              `cd "$portsdir/$_"; /usr/bin/cvs -R log -N -r. Makefile`;
            print map "\t" . $_, grep /^-/ .. /^=/, @cvslog;
            print "\n";
        }
    }
}
