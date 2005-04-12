#!/usr/bin/perl -w

# $FreeBSD$

#
# MAINTAINER=	edwin@freebsd.org
#

use Getopt::Std;
use strict;
use Cwd;
use Data::Dumper;

use vars qw/$opt_i $opt_u/;

sub usage {
	print <<EOF;
Usage: $0 [options] [<category>/]<portname>

	-u <username>	- Your freebsd.org username. Defaults to \$ENV{USER}.
	-i <filename>	- Use this for INDEX name. Defaults to /usr/ports/INDEX.

Questions, suggestions etc -> edwin\@freebsd.org
EOF
	exit 1;
}

my $INDEX="/usr/ports/INDEX";
my $USER=$ENV{USER};
{
    $opt_i="";
    $opt_u="";
    getopts("i:u:");
    $INDEX=$opt_i if ($opt_i);
    $USER=$opt_u if ($opt_u);

    die "$INDEX doesn't seem to exist. Please check the value supplied with -i or use -i." if (! -f $INDEX);
}
my $PORT=$ARGV[0];
usage() if (!$PORT);

my $CVSROOT=":ext:$USER\@pcvs.freebsd.org:/home/pcvs";

#
# Read the index, save some interesting keys
#
my %index=();
{
    print "Reading $INDEX\n";
    open(FIN,"$INDEX") or die "Cannot open $INDEX for reading.";
    my @lines=<FIN>;
    chomp(@lines);
    close(FIN);

    foreach my $line (@lines) {
	my @a=split(/\|/,$line);
	my @b=split(/\//,$a[1]);

	my $port=$b[-2]."/".$b[-1];

	$index{$port}{portname}=$b[-1];
	$index{$port}{portnameversion}=$a[0];
	$index{$port}{portdir}=$a[1];
	$index{$port}{comment}=$a[3];
	$index{$port}{deps}=();

	if ($a[8]) {
	    @b=split(" ",$a[8]);
	    foreach my $b (@b) {
		$index{$port}{deps}{$b}=1;
	    }
	}
    }
    my @k=keys(%index);
    print "- Processed ",$#k+1," entries.\n";
}

#
# See if the port does really exists.
# If specified as category/portname, that should be enough.
# If specified as portname, check all indexes for existence or duplicates.
#
if (defined $index{$PORT}) {
    # all okay
} else {
    my $count=0;
    my $n="";
    foreach my $p (keys(%index)) {
	if ($p=~/\/$PORT$/) {
	    $n.=" " if ($n);
	    $n.=$p;
	    $count++;
	}
    }
    if ($count==0) {
	die "Cannot find ${PORT} in ${INDEX}.";
    } elsif ($count==1) {
	$PORT=$n;
    } else {
	die "Found ${PORT} more than once in ${INDEX}: $n. Try category/portname.";
    }
}

my $PORTNAMEVERSION=$index{$PORT}{portnameversion};
print "Found $PORT as $PORTNAMEVERSION\n";

#
# Figure out all the ports depending on this one.
#
my %DEPPORTS=();
my $ports="";
{
    print "Searching for ports depending on $PORT\n";
    foreach my $p (keys(%index)) {
	if (defined $index{$p}{deps}{$PORTNAMEVERSION}) {
	    $DEPPORTS{$p}=1;
	    $ports.=" " if ($ports);
	    $ports.="ports/$p";
	}
    }
    my @k=keys(%DEPPORTS);
    print "- Found ",$#k+1," ports depending on it.\n";
}

#
# Create a temp directory and cvs checkout the ports
# (don't do error checking, too complicated right now)
#
my $TMPDIR=getcwd()."/.tmpdir.$$";
{
    mkdir($TMPDIR,0755);
    chdir($TMPDIR);
    `cvs -d $CVSROOT co -T $ports`;
}
chdir($TMPDIR);

#
# Bump portrevisions
#
{
    print "Updating Makefiles\n";
    foreach my $p (keys(%DEPPORTS)) {
	my $makefile="ports/$p/Makefile";

	print "- Updating Makefile of $p\n";

	if (!open(FIN,$makefile)) {
	    print "-- Cannot open Makefile of $p, ignored.\n";
	    next;
	}
	my @lines=<FIN>;
	close(FIN);
	chomp(@lines);

	my $revision=1;

	foreach my $line (@lines) {
	    last if ($line=~/^MAINTAINER/);
	    $revision+=$1 if ($line=~/PORTREVISION=[ \t](\d+)$/);
	}

	my $printedrev=0;
	open(FOUT,">$makefile");
	foreach my $line (@lines) {
	    if (!$printedrev) {
		if ($line=~/^CATEGORIES=/ || $line=~/^PORTREVISION=/) {
		    print FOUT "PORTREVISION=	$revision\n";
		    $printedrev=1;
		}
	    }
	    next if ($line=~/^PORTREVISION=/);
	    print FOUT "$line\n";
	}
	close(FOUT);
    }
}

#
# Commit the changes. Not automated.
#
print <<EOF;
All portrevisions have been updated. You are nearly done, only one thing
remains: The commiting in the ports tree. This program is not going to do
that for you, you have to do it manually.

\$ cd $TMPDIR/ports
\$ cvs commit

Then, remove the temp directory.
EOF
