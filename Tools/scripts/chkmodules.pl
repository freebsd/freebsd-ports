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
# CVSROOT-ports/modules auditing script, based on a shell script by
# Clement Laforet.
#

require 5.005;
use strict;
use File::Find;
use Cwd 'abs_path';

my $portsdir = $ENV{PORTSDIR} ? $ENV{PORTSDIR} : '/usr/ports';
my $cvsroot  = $ENV{CVSROOT}  ? $ENV{CVSROOT}  : '/home/ncvs/CVSROOT-ports';
my @excludes = $ENV{EXCLUDE}  ? split(' ', $ENV{EXCLUDE}) : ('local', 'rookies');

-d "$portsdir"        or die "Can't find ports tree at $portsdir.\n";
-f "$cvsroot/modules" or die "Can't read modules file $cvsroot/modules.\n";
$portsdir = abs_path($portsdir);

my %ports = ('ports' => 1);

my $excludepattern = '(?:'.join('|', 'distfiles', 'packages', @excludes).')';

sub wanted {
    !-d
    || (
      /^CVS$/
      || $File::Find::name =~ m"^$portsdir/$excludepattern$"os
      || $File::Find::name =~ m"^$portsdir/[^/]+/pkg$"os
    )
      && ($File::Find::prune = 1)
    || $File::Find::name =~ m"^$portsdir/([^/]+/[^/]+)$"os
      && ($ports{$1} = undef)
      && ($File::Find::prune = 1)
    || $File::Find::name =~ m"^$portsdir/((?:Mk|Templates|Tools)(?:/.+)?)"os
      && ($ports{$1} = 1)
    || $File::Find::name =~ m"^$portsdir/([^/]+)$"os
      && ($ports{$1} = undef);
}

find(\&wanted, $portsdir);

my %extraneous;
my %missorted;
my %illegal;

my $lastmodule = '';

open(MODULES, "$cvsroot/modules");
while (<MODULES>) {
    chomp;
    next if 1 .. /^# !!MERGE!!/;
    next if /^(#|$)/;
    my ($module, $portsdir) = split;
    if ($lastmodule gt $module) {
        $missorted{$.} = $_;
    }
    $lastmodule = $module;
    next if $portsdir eq 'ports';
    if ($module !~ /^[a-z\d]/i || $portsdir !~ m"^ports/([^/]+(?:/[^/]+)?)") {
        $illegal{$.} = $_;
        next;
    }
    if (exists $ports{$1}) {
        $ports{$1} = $.;
    }
    else {
        $extraneous{$.} = $_;
    }
}
close(MODULES);

my @missing = grep(!defined $ports{$_}, keys %ports);

print "** chkmodules report: **\n"
  if %extraneous || %illegal || %missorted || @missing;

print join("\n ",
    "\nModules with illegal names:",
    map("$_: $illegal{$_}", sort { $a <=> $b } keys %illegal)), "\n"
  if %illegal;

print join("\n ",
    "\nModules that are not sorted correctly:",
    map("$_: $missorted{$_}", sort { $a <=> $b } keys %missorted)), "\n"
  if %missorted;

print join("\n ",
    "\nOrphaned entries:",
    map("$_: $extraneous{$_}", sort { $a <=> $b } keys %extraneous)), "\n"
  if %extraneous;

print join("\n - ",
    "\nMissing entries in modules:",
    sort @missing), "\n"
  if @missing;

exit %extraneous || %illegal || %missorted || @missing ? 1 : 0;
