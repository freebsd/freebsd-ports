#!/usr/bin/perl -w
#
# $FreeBSD$

use strict;

my $base = "$ENV{HOME}/.ssh";
foreach (@ARGV) {
  my $dir = "$base/$_";
  system("mkdir -p $dir") == 0 or die;
  if (not -r "$dir/id_dsa.pub") {
    system("ssh-keygen -t dsa -N '' -C $ENV{USER}\@$_ -f $dir/id_dsa") == 0
      or die
  }
  system("ssh-keyscan -t dsa $_ >> $base/known_hosts") == 0 or die;
  system("sort $base/known_hosts | uniq > $base/tmp.$$") == 0 or die;
  system("mv $base/tmp.$$ $base/known_hosts") == 0 or die;
}
foreach (@ARGV) {
  my $dir = "$base/$_";
  system("cat $base/*/id_dsa.pub > $dir/authorized_keys") == 0 or die;
  system("cp $base/known_hosts $dir/known_hosts") == 0 or die;
}

