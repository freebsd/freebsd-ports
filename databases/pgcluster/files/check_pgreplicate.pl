#!/usr/bin/perl -w
#
# Copyright (c) 2004  IMG SRC, Inc.  All rights reserved.
#
# $Id: check_pgreplicate.pl,v 1.1 2004/02/23 06:06:13 kuriyama Exp $
#
# Plugin for nagios.
#
# define command{
# 	command_name	check_pgreplicate
# 	command_line	$USER1$/check_pgreplicate -H $HOSTADDRESS$ -p $ARG1$ -w $ARG2$ -c $ARG3$
# 	}
#
# # Declare cluster which has 2 pgcluster instances.
# # Send a warning if usable pgcluster is under 2.
# # Send a critical if usable pgcluster is under 1.
# define service{
# 	use		generic-service
# 	host_name	replicator.example.org
# 	service_description	PGREPLICATE
# 	check_command	check_pgreplicate!8777!2!1
# }

use strict;
use Getopt::Std;
use IO::Socket::INET;

my %O;
getopts('H:p:w:c:v', \%O);

my $w = $O{w};
my $c = $O{c};
usage() if (not $w or not $c);

my $host = sprintf("%s:%d", $O{H} || "localhost", $O{p} || 8777);
my $sock = IO::Socket::INET->new($host) or die "$!";

my $HOSTNAME_MAX_LENGTH = 128;
my $DBNAME_MAX_LENGTH = 128;
my $USERNAME_MAX_LENGTH = 128;

my $query = "dummy";
my $packet = pack "CCCCllla128a128a128a128ll", 0, 0, 0, ord("o"),
  0, 0, 5, "except host", "from host", "db name", "user name",
  time, 0;

print $sock $packet;
print $sock $query;

my ($use, @Host, %tmp) = (0);
while (<$sock>) {
  chomp;
  if ($_ eq "") {
    push @Host, { %tmp };
    $use++ if ($tmp{useFlag} == 2);
    %tmp = ();
  } else {
    my ($var, $val) = split(/=/, $_, 2);
    $tmp{$var} = $val;
  }
}
close($sock);

my $ret = 0;
if ($use < $O{c}) {
  $ret = 2;
} elsif ($use < $O{w}) {
  $ret = 1;
}
my %STATUS = (2 => "CRITICAL", 1 => "WARNING", 0 => "OK");
printf "PGREPLICATE %s: %d hosts active\n", $STATUS{$ret}, $use;
if ($O{v}) {
  foreach (@Host) {
    printf "%s:%d, useFlag=%d, recoveryPort=%d\n",
      $_->{hostName}, $_->{port}, $_->{useFlag}, $_->{recoveryPort};
  }
}
exit $ret;

# ============================================================
sub usage {
  print "Usage: check_pgreplicate -H host -p port -w <warn> -c <crit> [-v]\n";
  exit(3);
}
