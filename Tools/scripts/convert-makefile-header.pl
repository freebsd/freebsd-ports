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
  -N, --nopreserve      don't preserve original file

_ENOUSAGE
}

# You may add yourself to the following list if you agree to waive on the
# "Created by" attribution
sub get_nice_people() {
	my $committers=[
		'araujo',
		'az',
		'avilla',
		'bapt',
		'bdrewery',
		'beat',
		'brooks',
		'crees',
		'eadler',
		'flo',
		'flz',
		'garga',
		'kuriyama',
		'linimon',
		'makc',
		'pgollucci',
		'rm',
		'tabthorpe',
		'wxs'
	];

	# append FreeBSD.org domain to the list of committers
	map ($_ .= '\@FreeBSD\.org', @$committers);

	my $maintainers=[
		'cvs-src\@yandex\.ru',
		'makc\@issp\.ac\.ru',
		'villa\.alberto\@',
		'pgollucci\@p6m7g8\.com',
		'bsdkaffee\@',
		'baptiste\.daroussin\@gmail\.com'
	];

	# merge committer and maintainer addresses
	my @nice_people=(@$committers, @$maintainers);

	# prepend regex
	map ($_ = '(\\s|<|^)' . $_, @nice_people);

	return \@nice_people;
}

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

MAIN: {
	# get options
	my $opt={};
	my $nice_people=get_nice_people();
	GetOptions($opt, 'help|h', 'rcsonly|r', 'createdby|c', 'nowrite|n', 'nopreserve|N');

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
		my @header_exception;
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

				# tolerate $MCom RCS tags
				if($line=~m'\$MCom') {
					push(@header_exception, $line);
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
				if(defined($creator)) {
					my $is_nice=0;
					for my $c (@$nice_people) {
						if($creator=~m"${c}"i) {
							$is_nice=1;
							last;
						}
					}

					# normalize FreeBSD.org
					$creator=~s#\@freebsd\.org#\@FreeBSD.org#i;

					print $outh "# Created by: $creator\n" if(!$is_nice);
				} else {
					print STDERR "$mf creator not found. Reverting to RCS string only.\n";
				}
				print $outh "# \$FreeBSD\$\n";

				# append header exceptions
				for my $h (@header_exception) {
					print $outh $h . "\n";
				}
			}
		
			for my $line (@makefile) {
				print $outh $line . "\n";
			}

			if(not defined($opt->{nowrite})) {
				# move new Makefile
				`mv $mf $mf.orig` if(not defined($opt->{nopreserve}));
				`mv $mf.tmp_header_rename $mf`;
				print STDERR "$mf converted.\n";
			}

		} else {
			print STDERR "$arg/Makefile does not exist.\n";
		}
	}
}
