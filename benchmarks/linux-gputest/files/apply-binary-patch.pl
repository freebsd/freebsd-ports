#!/usr/bin/env perl

use strict;
use warnings;
use Sys::Mmap;

my $fh;
my $flen;
my $fdata;

sub commit {
	return unless $fh;
	munmap $fdata or die "munmap: $!";
	close $fh or die "close: $!";
}

while (<>) {
	chomp;
	if (/^([0-9A-F]{8}):? ([0-9A-F]{2}) ([0-9A-F]{2})$/i) {
		my ($offset, $old, $new) = map hex, $1, $2, $3;
		next unless $fdata;
		next unless $offset < $flen;
		next if ord substr($fdata, $offset, 1) != $old;
		substr($fdata, $offset, 1) = chr $new;
	} elsif (-e) {
		commit;
		open $fh, '+<', $_ or die "open: $!";
		mmap $fdata, 0, PROT_READ | PROT_WRITE, MAP_SHARED, $fh
		or die "mmap: $!";
		$flen = -s;
	}
}
commit;
