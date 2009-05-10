#! /usr/bin/perl -w
# ----------------------------------------------------------------------------
# "THE BEER-WARE LICENSE" (Revision 42)
# <tobez@FreeBSD.org> wrote this file.  As long as you retain this notice you
# can do whatever you want with this stuff. If we meet some day, and you think
# this stuff is worth it, you can buy me a beer in return.   Anton Berezin
# ----------------------------------------------------------------------------
#
# $FreeBSD$
use strict;

# good tests:
# /usr/ports/archivers/zoo/files/patch-aa  (context diff)
# /usr/ports/astro/xplanet/files/patch-aa  (unified with paths)

my ($in,$fl,$abort,$state,$out);

if (!@ARGV || $ARGV[0] =~ /^-/) {
	print STDERR "Usage:
	$0 patchfile ...
"
}

while (@ARGV) {
	$in = shift;
	$state = \&nofile;
	if (open IN, "< $in") {
		$abort = 0;
		$out = "";
		$fl = "";
		while (<IN>) {
			$state->();
			last if $abort;
		}
		close IN;
		if ($out && !$abort) {
			print "Wrote $out\n";
		}
	} else {
		print STDERR "cannot open $in: $!\n";
	}
}

sub nofile
{
	if (/^\*\*\*\s+/ && !/^\*\*\*\s+\d+,\d+\s+/) {
		$state = \&cstart;
		$fl = $_;
	} elsif (/^---\s+/ && !/^---\s+\d+,\d+\s+/) {
		$state = \&ustart;
		$fl = $_;
	}
}

sub cstart
{
	if (!/^---\s+\d+,\d+\s+/ && /^---\s+(\S+)\s+/) {
		$state = \&body;
		$out = $1;
		$out =~ s|/|__|g;
		$out = "patch-$out";
		if (open OUT, "> $out") {
			print OUT $fl;
			print OUT $_;
		} else {
			print STDERR "Cannot create $out: $!, aborting\n";
			$abort = 1;
		}
	} else {
		print STDERR "Bad context diff in $in, aborting\n";
		$abort = 1;
	}
}

sub ustart
{
	if (/^\+\+\+\s+(\S+)\s+/) {
		$state = \&body;
		$out = $1;
		$out =~ s|/|_|g;
		$out = "patch-$out";
		if (open OUT, "> $out") {
			print OUT $fl;
			print OUT $_;
		} else {
			print STDERR "Cannot create $out: $!, aborting\n";
			$abort = 1;
		}
	} else {
		print STDERR "Bad unified diff in $in, aborting\n";
		$abort = 1;
	}
}

sub body
{
	if (/^\*\*\*\s+/ && !/^\*\*\*\s+\d+,\d+\s+/) {
		close OUT;
		print "Wrote $out\n";
		$state = \&cstart;
		$fl = $_;
	} elsif (/^---\s+/ && !/^---\s+\d+,\d+\s+/) {
		close OUT;
		print "Wrote $out\n";
		$state = \&ustart;
		$fl = $_;
	} else {
		print OUT $_;
	}
}
