#!/usr/bin/perl
# $FreeBSD$

die "$0 <pkgdir> <indexfile>\n" if ($#ARGV != 1);

$pkg_dir = shift(@ARGV);

while (<>) {
  chomp;
  @f = split(/\|/);
  @deps = split(/\s+/, $f[8]);
  foreach (@deps) {
    print "$_\n" if (! -f "$pkg_dir/$_.tgz");
  }
}
