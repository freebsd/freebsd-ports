#!/usr/bin/env perl
#
# convert-makefile-header.pl - perl script that converts old style Makefile
# headers to the new format.
#
# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
#
# MAINTAINER=   ehaupt@FreeBSD.org
#
# $FreeBSD$

use strict;
use warnings;

use File::Basename;
use Getopt::Long qw(:config posix_default no_ignore_case);

sub usage() {
	my $bn=basename($0);
	print(<< "_ENOUSAGE");
Usage: $bn [OPTION] PORT
  -c                    use 'created by' header (default)
  -r                    use simple \$FreeBSD\$ RCS string header
                        (make sure the original creator is ok with this)
  -h, --help            this help
  -n, --nowrite         don't change file, just print what would be done

_ENOUSAGE
}

my $nicepeople=".*(avilla@|bapt@|bdrewery@|beat@|eadler@|flo@|flz@|garga@|bsdkaffee@|linimon@|makc@|araujo@|rm@|villa.alberto@).*";

sub get_creator($) {
	my $header=shift;
	my $creator;
	for my $line (@$header) {
		if($line=~m'\s+whom:\s+(.*)'i) {
			return $1;
		} elsif($line=~m'\s+Created by:\s+(.*)'i) {
			return $1;
		}
	}
	return $creator;
}

sub get_mcom($) {
	my $header=shift;
	my $mcom;
	for my $line (@$header) {
		if ($line=~m'\$MCom:'i) {
			return $line;
		}
	}
	return "";
}

MAIN: {
	# get options
	my $opt={};
	GetOptions($opt, 'help|h', 'rcsonly|r', 'createdby|c', 'nowrite|n');

	if(defined($opt->{help})) {
		usage();
		exit 0;
	}

	if(not @ARGV) {
		push(@ARGV, '.');
	}

	for my $arg (@ARGV) {
		my @header;
		my @makefile;
		my $in_header=1;
		if(-f "$arg/Makefile") {
			my $mf=$arg . "/Makefile";
			open(F,'<'.$mf);
			while(my $line=<F>) {
				chomp($line);
				if($line=~m'^#' and $in_header) {
					push(@header, $line);
				} else {
					$in_header=0;
					push(@makefile, $line);
				}
			}
			close(F);

			my $outh;
			if(defined($opt->{nowrite})) {
				$outh = \*STDOUT;
			} else {
				open(MF,'>'.$mf.'.tmp_header_rename');
				$outh = \*MF;
			}

			# write new Makefile
			if(defined($opt->{rcsonly})) {
				print $outh "# \$FreeBSD\$\n";
			} elsif(defined($opt->{createdby}) || !defined($opt->{rcsonly})) {
				my $creator=get_creator(\@header);
				my $mcom=get_mcom(\@header);
				if(defined($creator)) {
					if ($creator!~m"$nicepeople"i) {
						print $outh "# Created by: $creator\n";
					}
				} else {
					print STDERR "$mf creator not found. Reverting to RCS string only.\n";
				}
				print $outh "# \$FreeBSD\$\n";
				print $outh $mcom;
			}
		
			for my $line (@makefile) {
				print $outh $line . "\n";
			}

			if(not defined($opt->{nowrite})) {
				# move new Makefile
				`mv $mf $mf.orig`;
				`mv $mf.tmp_header_rename $mf`;
				print STDERR "$mf converted.\n";
			}

		} else {
			print STDERR "$arg/Makefile does not exist.\n";
		}
	}
}
