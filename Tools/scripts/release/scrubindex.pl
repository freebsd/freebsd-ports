#!/usr/bin/perl
# $FreeBSD$

die "$0 <pkgdir> <indexfile>\n" if ($#ARGV != 1);

$xdep = 'XFree86-3\.3\.6_10';
$pkgdir = shift(@ARGV);
#$ext = 'tbz';
$ext = 'tgz';

print STDERR "scrubindex pkgdir: $pkgdir\n";

my $cnt = 0;

LOOP:
while (<>) {
	s/$xdep//g;
	s/  */ /g;
	s/\| /\|/g;

	@f = split('\|');
	next if (! -f "$pkgdir/$f[0].$ext");

	foreach $dep (split(' ', $f[8])) {
		next LOOP if (! -f "$pkgdir/$dep.$ext");
	}

	$cnt++;
	print;
}
print STDERR "$cnt lines copied from scrubindex.pl"
