#!/usr/bin/perl -w
#-
# Copyright (c) 2000 Dag-Erling Coïdan Smørgrav
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer
#    in this position and unchanged.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
# 3. The name of the author may not be used to endorse or promote products
#    derived from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
# IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
# OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
# IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
# INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
# NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
# DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
# THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
# THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
#      $Id$
#

use strict;
use Fcntl;
use POSIX qw(EEXIST);
use Getopt::Long;

my $VERSION	= "1.0";

# Global parameters
my $plist;			# Packing list
my $prefix;			# Installation prefix
my $srcdir;			# Source directory

# Global flags
my $verbose;			# Verbose flag

#
# Install a directory
#
sub install_dir($) {
    my $dn = shift;		# Directory name

    my @sb;			# File status

    if ($verbose) {
	print(STDERR "Creating directory $prefix/$dn\n");
    }
    if (!(@sb = stat("$srcdir/$dn"))) {
	die("stat('$dn'): $!\n");
    }
    if (!mkdir("$prefix/$dn", 0755) && $! != EEXIST) {
	die("mkdir('$prefix/$dn'): $!\n");
    }
    if (!chmod($sb[2] & 07777, "$prefix/$dn")) {
	die("chmod('$prefix/$dn'): $!\n");
    }
    if (!chown($sb[4], $sb[5], "$prefix/$dn")) {
	die("chown('$prefix/$dn'): $!\n");
    }
}

#
# Install a file
#
sub install_file($) {
    my $fn = shift;		# Filename

    my @sb;			# File status

    if ($verbose) {
	print(STDERR "Installing $fn as $prefix/$fn\n");
    }
    if (!(@sb = stat("$srcdir/$fn"))) {
	die("stat('$fn'): $!\n");
    }
    if (system("install", "-c", "-m", sprintf("0%o", $sb[2] & 07777),
	       "-o", $sb[4], "-g", $sb[5], "$srcdir/$fn", "$prefix/$fn")) {
	die("install('$fn'): failed\n");
    }
}

#
# Print usage message and exit
#
sub usage() {
    
    print(STDERR "Usage: pinstall [-hv] [-d srcdir] [-f plist] [-p prefix]\n");
    exit(1);
}

#
# Print help text
#
sub help() {
    
    print(STDERR "pinstall $VERSION
Copyright (c) 2000 Dag-Erling Smørgrav. All rights reserved.

Options:
  -h, --help               Show this information
  -v, --verbose            Verbose mode

Parameters:
  -d, --srcdir=DIR         Specify source directory
  -f, --plist=FILE         Specify packing list
  -p, --prefix=DIR         Specify installation prefix

Report bugs to <des\@freebsd.org>.
");
    exit(1);
}

MAIN:{
    local *PLIST;		# File handle
    my @dirs;			# Directories
    my @files;			# Files
    my $item;			# Iterator
    
    # Scan command line options
    (Getopt::Long::Configure("auto_abbrev", "bundling"));
    GetOptions(
	       "d|src-dir=s"	=> \$srcdir,
	       "f|plist=s"	=> \$plist,
	       "h|help"		=> \&help,
	       "p|prefix=s"	=> \$prefix,
	       "v|verbose"	=> \$verbose,
	       )
	or usage();

    # Check prefix
    if (!$prefix) {
	$prefix = $ENV{'PREFIX'} || "/usr/local";
    }
    $prefix =~ s|/*$||;
    if ($prefix !~ m|^/|) {
	die("Invalid prefix\n");
    }

    # Check packing list
    if (!$plist) {
	$plist = "pkg-plist";
    }
    if (!-f $plist) {
	die("No packing list\n");
    }

    # Check source directory
    if (!$srcdir || !-d $srcdir) {
	die("No source directory\n");
    }

    # Read plist
    sysopen(PLIST, $plist, O_RDONLY)
	or die("open(): $!\n");
    while (<PLIST>) {
	chomp();
	if (m/^([a-z]\S+)\s*$/) {
	    push(@files, $1);
	} elsif (m/^\@dirrm\s+(\S+)\s*$/) {
	    push(@dirs, $1);
	} else {
	    warn("Unrecognized directive: $_\n");
	}
    }
    close(PLIST)
	or die("close(): $!\n");

    # Create directories
    foreach $item (sort(@dirs)) {
	install_dir($item);
    }

    # Copy files
    foreach $item (sort(@files)) {
	install_file($item);
    }
}
