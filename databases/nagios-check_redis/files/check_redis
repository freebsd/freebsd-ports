#!/usr/bin/env perl

use warnings;
use strict;
use Getopt::Long qw(:config gnu_getopt);
use Redis;
use Nagios::Plugin;

my $VERSION="0.1";
my $np;

$np = Nagios::Plugin->new(usage => "Usage: %s [--host|-H <host>] [--port|-p <port>] [ -c|--critical=<threshold> ] [ -w|--warning=<threshold>] [-?|--usage] [-V|--version] [-h|--help] [-v|--verbose] [-t|--timeout=<timeout>]",
                          version => $VERSION,
                          blurb => 'This plugin checks the availability of a redis server, expecting that a slave server is sync with master, and the replication delay is not too high.',
                          license => "Brought to you AS IS, WITHOUT WARRANTY, under GPL. (C) Remi Paulmier <remi.paulmier\@gmail.com>",
                          shortname => "CHECK_REDIS",
                         );

$np->add_arg(spec => 'host|H=s',
             help => q(Check the host indicated in STRING),
             required => 0,
             default => 'localhost',
            );

$np->add_arg(spec => 'port|p=i',
             help => q(Use the TCP port indicated in INTEGER),
             required => 0,
             default => 4730,
            );

$np->add_arg(spec => 'critical|c=s',
             help => q(Exit with CRITICAL status if replication delay is greater than INTEGER),
             required => 0,
             default => 10,
            );

$np->add_arg(spec => 'warning|w=s',
             help => q(Exit with WARNING status if replication delay is greater than INTEGER),
             required => 0,
             default => 1,
            );

$np->getopts;
my $ng = $np->opts;

# manage timeout
alarm $ng->timeout;

# host & port
my $host = $ng->get('host');
my $port = $ng->get('port');

# verbosity
my $verbose = $ng->get('verbose');

my $redis;
eval {
	$redis = Redis->new( server => "$host:$port", debug => 0);
};
if ($@) {
	$np->nagios_exit( CRITICAL, "Can't connect to $host:$port" );
}

my $info = $redis->info();
my $code = OK;
my $msg = "Everything is OK";

$redis->ping || $np->nagios_exit( CRITICAL, "Can't ping server $host:$port" );

if ($info->{'role'} eq "slave") {
	$code = $np->check_threshold(check => $info->{'master_last_io_seconds_ago'});
	$msg = ("redis replication is late (" .
	        $info->{'master_last_io_seconds_ago'} .
	        "s)"
	       ) if $code != OK;

	if ($info->{'master_sync_in_progress'} != 0) {
		$msg = "redis replication sync is in progress";
		$code = CRITICAL;
	}
}

$np->nagios_exit( $code, $msg );
