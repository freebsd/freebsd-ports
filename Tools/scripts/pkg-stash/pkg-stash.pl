#!/usr/bin/perl -wT
# $FreeBSD$

use strict;

use Sys::Hostname;
use File::Basename;
use Getopt::Std;
use POSIX qw(strftime);

sub usage() {

	die("Usage:\n"
	    ."\tpkg-stash [-D base] [-d dir] [-g group] [-o owner] [-cfNn] filename..\n"
	    ."\tpkg-stash [-D base] [-d dir] [-g group] [-o owner] -p\n");
}

sub stashfile($ %) {
	my ($path, %args) = @_;
	my ($dir, $base, $ext);
	my ($ts, $fname);
	my (@opts, @cmd);

	($base, $dir, $ext) = fileparse($path, '\.tgz', '\.tar\.gz', '\.tbz', '\.tbz2');
	if ($args{'nostamp'}) {
		$ts = "";
	} else {
		$ts = "-ts".strftime("%Y%m%d%H%M", localtime());
	}
	$fname = "$base$ts$ext";

	@cmd = ("install");
	push(@cmd, '-v') if ($args{'verbose'});
	push(@cmd, $args{'copy'}) if ($args{'copy'} ne "");
	push(@cmd, $args{'owner'}) if ($args{'owner'} ne "");
	push(@cmd, $args{'group'}) if ($args{'group'} ne "");
	push(@cmd, $path, "$args{dir}/$fname");

	if ($args{'noact'}) {
		print join(' ', @cmd)."\n";
		return 1;
	}
	if (system(@cmd) != 0) {
		warn "Installing $path to $args{dir}/$fname failed: $?\n";
	}
	if (system('rm', $path) != 0) {
		warn "Removing %path failed: $?\n";
	}
}

MAIN:{
	my %stashargs = (
		"base"	=> "/var/backups/packages/",
		"copy"	=> "",
		"dir"	=> "",
		"group"	=> "",
		"noact"	=> 0,
		"nostamp"	=> 0,
		"owner"	=> "",
		"verbose"	=> 0,
	);
	my $printonly = 0;
	my %opts;
	my $path;
	
	getopts("CcD:d:fg:Nno:pv", \%opts) or
		usage();
	$stashargs{'base'} = $opts{'D'} if (defined($opts{'D'}));
	$stashargs{'copy'} = 'c' if (defined($opts{'c'}));
	$stashargs{'copy'} = 'C' if (defined($opts{'C'}));
	$stashargs{'dir'} = $opts{'d'} if (defined($opts{'d'}));
	$stashargs{'force'} = 1 if (defined($opts{'f'}));
	$stashargs{'group'} = "-g $opts{g}" if (defined($opts{'g'}));
	$stashargs{'nostamp'} = 1 if (defined($opts{'N'}));
	$stashargs{'noact'} = 1 if (defined($opts{'n'}));
	$stashargs{'owner'} = "-o $opts{o}" if (defined($opts{'o'}));
	$stashargs{'verbose'} = 1 if (defined($opts{'v'}));
	$printonly = 1 if (defined($opts{'p'}));

	if ($stashargs{'dir'} eq "") {
		my $hostname = hostname();

		$hostname =~ s/\..*//;
		$stashargs{'dir'} = $stashargs{'base'}.$hostname;
	}

	# Do nada?
	if ($printonly) {
		print $stashargs{'dir'}."\n";
		exit(0);
	}

	# Force taint mode into submission
	delete @ENV{'IFS', 'CDPATH', 'ENV', 'BASH_ENV'};
	$ENV{'PATH'} = '/bin:/usr/bin';

	# Okay, process the arguments..
	if ($#ARGV == -1) {
		usage();
	}
	foreach $path (@ARGV) {
		stashfile($path, %stashargs);
	}
}
