#!/usr/bin/perl
# $FreeBSD$

die "$0 <pkgdir> <indexfile>\n" if ($#ARGV != 1);

$xdep = 'XFree86-3\.3\.6_10';
$pkgdir = shift(@ARGV);

LOOP:
while (<>) {
	s/$xdep//g;
	s/  */ /g;
	s/\| /\|/g;

	@f = split('\|');
	next if (! -f "$pkgdir/$f[0].tgz");

	foreach $dep (split(' ', $f[8])) {
		next LOOP if (! -f "$pkgdir/$dep.tgz");
	}

	print;
}
