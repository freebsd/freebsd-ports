#!/usr/bin/env perl
# $FreeBSD$
# perltidy -bext=/ -i=8 -et=8 -l=132 -pt=2 -ce -cti=1

use strict;
use utf8;
use warnings;

my $extension = '.orig';
my $oldargv   = q{};
my $indent;
my $argvout;
LINE: while (<>) {

	# For each file, save a .orig backup.
	if ($ARGV ne $oldargv) {
		my $backup;
		if ($extension !~ /[*]/) {
			$backup = $ARGV . $extension;
		} else {
			($backup = $extension) =~ s/[*]/$ARGV/g;
		}
		rename $ARGV, $backup;
		open $argvout, '>', $ARGV;
		$oldargv = $ARGV;
		$indent  = 0;
	}

	if (/^[.]\s*(?:if|for)/o) {    # if/for -> indent and increase indent
		s/^[.]\s*/"." . "  " x $indent/oe;
		$indent++;
	} elsif (/^[.]\s*end(?:if|for)/o) {    # endif/endfor -> decrease indent and indent
		$indent--;
		s/^[.]\s*/"." . "  " x $indent/oe;
	} elsif (/^[.]\s*(?:else|elif)/o) {    # else/elif -> indent one level down
		s/^[.]\s*/"." . "  " x ($indent - 1)/oe;
	}
} continue {

	# Print the line.
	print {$argvout} $_;
}
