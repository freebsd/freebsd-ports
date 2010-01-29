#!/usr/bin/perl
#
# $FreeBSD$
#
# Usage: p5-deps.pl
#
# List up unneeded dependencies which is in perl 5.8.9 dist.
#
# This script will be used when perl5.8 port removed.

use strict;
use warnings;
use File::Slurp;

my (%OLD, %VER);
init();

open(my $fh, "<", "/usr/ports/INDEX-8") or die;
while (<$fh>) {
  chomp;
  my ($port, $dir, $prefix, $comment, $descr, $maint, $cat, $bdep, $rdep) = split(/\|/);
#  next if ($maint !~ m/^(kuriyama|perl|port)\@freebsd\.org$/i);
#  next if ($dir !~ m#^/usr/ports/devel/#);
  my $go = 0;
  foreach my $old (values %OLD) {
    if ($bdep =~ m|\b$old-\d| or $rdep =~ m|\b$old-\d|) {
      $go = 1;
      last;
    }
  }
  if ($go) {
    foreach my $m (keys %OLD) {
      my $make = read_file("$dir/Makefile");
      if ($make =~ m#([0-9.]+)?:\${PORTSDIR}/$m($| )#s) {
	if ($1) {
	  # Compare versions in Makefile vs in core.
	  chomp(my $cmp = `pkg_version -t $1 $VER{$m}`);
	  if ($cmp eq '>') {	# newer version required, OK.
	    last;
	  }
	}
	if (($m eq 'converters/p5-Encode' and $port eq 'p5-Padre-0.50_1') or
	    ($m eq 'devel/p5-Test-Harness' and $port eq 'p5-Games-Bingo-Print-0.04_1')) {
	  # Known to skip.
	} else {
	  printf "$dir	$port	$m\n";
	  last;
	}
      }
    }
  }
}

sub init {
  while (<DATA>) {
    chomp;
    my ($dir, $ver) = split(/\s+/, $_);
    chdir "/usr/ports/$dir" or die "chdir($dir): $!";
    chomp(my $tri = `make -VPKGNAMEPREFIX -VPORTNAME -VPKGNAMESUFFIX`);
    my $name = join("", split(/\n/, $tri));
    $OLD{$dir} = $name;
    $VER{$dir} = $ver;
  }
}

# TAP::Harness is p5-Test-Harness>=3.00

__DATA__;
converters/p5-Encode		2.26
converters/p5-MIME-Base64	3.07
devel/p5-Data-Dumper		2.121
devel/p5-ExtUtils-Command	1.16
devel/p5-ExtUtils-Constant	0.21
devel/p5-ExtUtils-Install	1.52
devel/p5-ExtUtils-MakeMaker	6.48
devel/p5-ExtUtils-Manifest	1.56
devel/p5-ExtUtils-ParseXS	2.19
devel/p5-File-Path		2.07
devel/p5-File-Temp		0.20
devel/p5-Getopt-Long		2.37
devel/p5-IO			1.23
devel/p5-Locale-Maketext	1.13
devel/p5-Memoize		1.01
devel/p5-Module-CoreList	2.17
devel/p5-Module-Pluggable	3.9
devel/p5-NEXT			0.64
devel/p5-PathTools		3.31
devel/p5-Storable		2.19
devel/p5-Term-ANSIColor		1.12
devel/p5-Test-Harness		2.64
devel/p5-Test-Simple		0.80
devel/p5-Time-HiRes		1.9715
devel/p5-Time-Local		1.1901
devel/p5-XSLoader		0.10
lang/p5-Scalar-List-Utils	1.19
math/p5-Math-BigInt		1.89
math/p5-Math-BigRat		0.22
math/p5-Math-Complex		1.54
net/p5-Net			1.11
security/p5-Digest		1.15
security/p5-Digest-MD5		2.37
textproc/p5-Filter-Simple	0.83
textproc/p5-Pod-Parser		1.35
textproc/p5-Text-Balanced	1.98
textproc/p5-Text-ParseWords	3.27
www/p5-CGI.pm			3.42
