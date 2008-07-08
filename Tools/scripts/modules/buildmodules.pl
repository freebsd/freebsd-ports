#!/usr/bin/perl -w

#
# $FreeBSD$
#

#
# This script is used to automatically generate the CVSROOT-ports/modules
# file, based on the content of the ports INDEX file and the modules files
# of the other CVSROOT-* directories.
#
# Created by Edwin Groothuis <edwin@FreeBSD.org>
#
# This script lives on hub in /home/gnats-aa and is called from a crontab
# once per day. 
#

use strict;
use Data::Dumper;
use Getopt::Long;

my $portsdir = "";
my $index = "";
my $header = "";
my $modules = "";
my $modules_src = "";
my $modules_doc = "";
my $modules_proj = "";
my $outdir = "modules.dir";
my $outmod = "modules.out";
GetOptions(	"portsdir=s"	=> \$portsdir,
		"index=s"	=> \$index,
		"modules=s"	=> \$modules,
		"modules-src=s"	=> \$modules_src,
		"modules-doc=s"	=> \$modules_doc,
		"modules-proj=s"=> \$modules_proj,
		"header=s"	=> \$header,
		"outdir=s"	=> \$outdir,
		"outmod=s"	=> \$outmod
);

#
# Get all directories in /usr/ports, and see if there is a PKGNAMEPREFIX to
# be worried about
#
my %dirs = ();
{
	opendir(DH, $portsdir);
	my @dirs = readdir(DH);
	closedir(DH);
	foreach my $dir (@dirs) {
		next if (! -d "$portsdir/$dir");
		next if ($dir =~ /^\./);
		next if ($dir eq "distfiles");
		next if ($dir eq "packages");

		$dirs{$dir} = "";

		next if (! -f "$portsdir/$dir/Makefile.inc");

		my $prefix =
		    `make -C $portsdir/$dir -f Makefile.inc -V PKGNAMEPREFIX`;
		chomp($prefix);
		$dirs{$dir} = $prefix;
	}
}

#
# Write the modules.dir file in the following format: "ports_" + DIR
#
{
	open(FOUT, ">$outdir");
	print FOUT "\n#\n# Ports directories\n#\n";
	printone("ports", "ports");
	foreach my $d (sort(keys(%dirs))) {
		my $d_ = $d;
		$d_ =~ s/\-/_/g;
		printone("ports_" . $d_, "ports/$d");
	}
	close(FOUT);
}

#
# Import the modules file from CVSROOT-src and friends.
#
my %src_mods = ();
{
	my $line;

	foreach my $mod (($modules_src, $modules_doc, $modules_proj)) {
		my $foundMERGE = 0;
		next if ($mod eq "");
		open(FIN, $mod);
		while (defined($line = <FIN>)) {
			if ($line =~ /!!MERGE!!/) {
				$foundMERGE = 1;
				next;
			}
			next if (!$foundMERGE);
			next if ($line =~ /^\#/);

			my @a = split(" ", $line);
			next if ($#a != 1);
			$src_mods{$a[0]} = $a[1];
		}
		close(FIN);
	}
}

#
# Import the modules from modules.head
#
{
	my $line;
	open(FIN, $header);
	while (defined($line = <FIN>)) {
		next if ($line =~ /^\#/);

		my @a = split(" ", $line);
		next if ($#a <= 0);
		$src_mods{$a[0]} = $a[1];
	}
	close(FIN);
}

#
# Read the INDEX file and store it as a hash with the key modname 
# (PKGNAMEPREFIX + portname) in %mods.
#
# If a duplicate is found with CVSROOT-src/modules, rename the modname
# to "ports_" + modname.
#
# If a duplicate modname is is found, copy the original to DIR + modname
# and continue for these modnames (and any future ones) as DIR + modname.
#
my %mods = ();
my %dupes = ();
{
	my $line;
	open(FIN, "$portsdir/$index");
	while (defined($line = <FIN>)) {
		my @a = split(/\|/, $line);
		@a = split(/\//, $a[1]);
		my %names = ( lc($a[4]) => 1, $a[4] => 1 );
		my $path = "$a[2]/$a[3]/$a[4]";
		my $dir = $a[3];

#		next if ($a[4] ne "p5-Chemistry-Elements");

		if (!defined $dirs{$dir}) {
			print "Unknown dir: $dir\n";
			exit(1);
		}

		foreach my $name (sort(keys(%names))) {
			my $modname = $dirs{$dir} . $name;

			$modname = "ports_" . $modname
				if (defined($src_mods{$modname}));

			if (defined $dupes{$modname}) {
				$modname = $dir . "_" . $modname;
			} else {
				if (defined($mods{$modname})) {
					$dupes{$name} = 1;

					# save earlier one
					my $dupemodname = $mods{$modname}{dir} .
					    "_" . $modname;
					my $newmodname = $dir . "_" . $modname;
					$mods{$dupemodname}{dir} =
					    $mods{$modname}{dir};
					$mods{$dupemodname}{name} =
					    $mods{$modname}{dir} . "_" .
					    $mods{$modname}{name};
					$mods{$dupemodname}{path} =
					    $mods{$modname}{path};
					$mods{$modname}{ignore} = 1;

					$modname = $dir . "_" . $modname;
				}
			}

			$mods{$modname}{dir} = $dir;
			$mods{$modname}{name} = $modname;
			$mods{$modname}{path} = $path;
			$mods{$modname}{ignore} = 0;
		}
	}
	close(FIN);

	open(FOUT, ">$outmod");
	print FOUT "\n#\n# Ports modules\n#\n";
	foreach my $mod (sort(keys(%mods))) {
		next if ($mods{$mod}{ignore});
		printone($mods{$mod}{name}, $mods{$mod}{path});
	}
	close(FOUT);
}

sub printone {
	my $name = shift;
	my $path = shift;
	print FOUT "$name ", " " x (30 - length($name)), " $path\n";
}
