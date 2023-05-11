#!/usr/bin/env -S perl -wt

#
# This script helps with bumping the PORTREVISION of all ports that depend on a
# set of ports, for instance, when in the latter set one of the ports bumped the
# .so library version.
#
# The shebang line above includes -T (taint) to be more distrustful 
# about the environment, for security reasons, and is considered
# good Perl practice.
#
# You can use either the
# -l (shaLlow, avoid grandparent dependencies, slower) or
# -g option (include grandparent dependencies) option.
#
# MAINTAINER=	mandree@FreeBSD.org
#

use strict;
use Getopt::Std;
use Carp 'verbose';
use Cwd;
use File::Basename;
use Data::Dumper;
$Data::Dumper::Indent = 1; # simple indent
$Data::Dumper::Purity = 1; # Perl syntax
my $debug = 0;

use vars qw/$opt_n $opt_f $opt_i $opt_u $opt_l $opt_g $opt_p $opt_h/;

# launder environment
delete @ENV{'IFS', 'CDPATH', 'ENV', 'BASH_ENV'};
$ENV{'PATH'} = '/bin:/usr/bin:/usr/local/bin';

sub usage {
	print <<EOF;
Usage: $0 [options] [<category>/]<portname>

Options:
    -l              - shaLlow, only bump ports with direct dependencies. (default).
    -g              - Grandchildren, also bump for indirect dependencies.
    -n              - Check only (dry-run), do not change Makefiles.
    -f              - No tmpdir, just use the directory where INDEX resides.
    -i <filename>   - Use this for INDEX name. Defaults to \${PORTSDIR}/INDEX-n,
                      where n is the major version of the OS, or \${PORTSDIR}/INDEX if missing.
    -p <dirname>    - Set portsdir, if different from /usr/ports.

Improvements, suggestions, questions -> mandree\@FreeBSD.org
EOF
	exit 1;
}

# flush STDOUT for each and every write even if writing to a pipe.
$| = 1;

sub bumpMakefile {
    my ($taintedorigin) = @_; 
    my $origin;

    if ($taintedorigin =~ /^([-\@\w.\/]+)$/) {
	$origin = $1;
    }  else {
       	Carp::carp "cannot untaint $taintedorigin - invalid characters";
	return;
    }

    my $makefile = "$origin/Makefile";
    my $fin;
    unless(open($fin, $makefile)) {
	print "-- Cannot open Makefile of $origin, ignored.\n";
	return;
    }
    my @lines = <$fin>;
    if ($!) { die "Error while reading $makefile: $!. Aborting"; }
    close($fin) or die "Can't close $makefile b/c $!";
    chomp(@lines);

    my $revision = 1;

    foreach my $line (@lines) {
	last if ($line =~ /^MAINTAINER/);
	$revision += $1 if ($line =~ /PORTREVISION\??=[ \t]*(\d+)$/);
    }

    my $printedrev = 0;
    open(my $fout, '>', "$makefile.bumped");
    foreach my $line (@lines) {
	if (!$printedrev) {
	    if ($line =~ /^CATEGORIES??=/ || $line =~ /^PORTEPOCH??=/) {
		print $fout "PORTREVISION=	$revision\n";
		$printedrev = 1;
		# Fall through!
	    }
	    if ($line =~ /^PORTREVISION\?=/) {
		print $fout "PORTREVISION?=	$revision\n";
		$printedrev = 1;
		next;
	    }
	    if ($line =~ /^PORTREVISION=/) {
		print $fout "PORTREVISION=	$revision\n";
		$printedrev = 1;
		next;
	    }
	}
	print $fout "$line\n";
    }
    close($fout) or die "Can't close $makefile b/c $!";
    rename "$makefile.bumped", $makefile or die "Can't rename $makefile.bumped to $makefile: $!";
}

my $osversion = `uname -r`;
chomp $osversion;
$osversion =~ s/\..*//;

my $shallow = 0;
my ($portsdir, $INDEX);
{
    $opt_i = "";
    $opt_u = "";
    getopts("fghi:lnu:p:") or die "Aborting";
    usage() if $opt_h;
    if ($ENV{'DEBUG'}) { $debug = $ENV{'DEBUG'}; }
    $shallow = $opt_l if $opt_l;
    if ($opt_l and $opt_g) {
	die "Options -g and -l given, which are mutually exclusive. Pick either.";
    }
    if (not $opt_l and not $opt_g) {
	warn "Neither -g nor -l given. Defaulting to -l";
	$opt_l = 1;
    }
    $portsdir = $opt_p ? $opt_p : '/usr/ports';

    $INDEX = "$portsdir/INDEX-$osversion";
    $INDEX = $opt_i if ($opt_i);
    if (!-f $INDEX) { $INDEX = "$portsdir/INDEX"; }

    die "$INDEX doesn't seem to exist. Please check the value supplied with -i,\n" .
	    "or use -i /path/to/INDEX, or check your -p PORTSDIR." unless(-f $INDEX);
}
usage() unless(@ARGV);

my $TMPDIR = File::Basename::dirname($INDEX);

#
# Sanity checking
#
if (-d "$TMPDIR/.git" and not $opt_f and not $opt_n) {
    die "$TMPDIR/.git exists, cowardly refusing to proceed.\n";
}


# must launder $portsdir (from command line => tainted) first
if ($portsdir =~ /^([-\@\w.\/]+)$/) {
    $portsdir = $1; }
else {
    die "Portsdir \"$portsdir\" contains unsafe characters. Aborting";
}

chdir "$portsdir" or die "cannot cd to $portsdir: $!\nAborting";

#
# Read the index, save some interesting keys
#
my %index = ();
{
    print "Reading $INDEX\n";
    open(my $fin, '<', "$INDEX") or die "Cannot open $INDEX for reading.";
    my @lines = <$fin>;
    if ($!) { die "Error while reading $INDEX: $! Aborting"; }
    chomp(@lines);
    close($fin);

    my @a;
    my @b;
    my $origin;
    my $cat_port;
    my $pkgname;
    map {
	@a = split(/\|/, $_); # columns per PORTINDEX(5) aka INDEX(5)
	@b = split(/\//, $a[1]);

	$cat_port = $b[-2]."/".$a[0];
	$cat_port =~ s/-[^-]+$//;
	$origin = $b[-2]."/".$b[-1];

	unless ($b[-1]) { die "undefined portname"; }
	unless ($origin) { die "undefined origin"; }

	@{ $index{$a[0]} }{'portname', 'origin', 'comment', 'deps'}
	    = ($b[-1], $origin, $a[3], ());

	if ($a[8]) { # run dependencies
	    @b = split(" ", $a[8]);
	    @{ $index{$a[0]}{deps} }{@b} = (1) x @b;
	}
	undef;
    } @lines;

    print "- Processed ", scalar keys(%index), " entries.\n";
    if ($debug and $debug > 1) {
	   print STDERR Dumper(\%index);
    }
}

my %DEPPORTS = ();

my %byorigin =   map { ($index{$_}{'origin'} => $_)   } keys %index;
my %byportname = map { ($index{$_}{'portname'} => $_) } keys %index;

foreach my $PORT (@ARGV) {
    #
    # See if the port really exists.
    # If specified as category/portname, that should be enough.
    # If specified as portname, check all categories for existence or duplicates.
    #
    my $r = $index{$PORT};
    if (!defined $r) { $r = $byportname{$PORT}; }
    if (!defined $r) { $r = $byorigin{$PORT}; }
    if (defined $r) { print "Found $PORT as $r.\n"; $PORT = $r; }
    else { die "Cannot find $PORT in $INDEX! Aborting"; }

    #
    # Figure out all the ports depending on this one.
    #
    {
	print "Searching for ports depending on $PORT\n";
	my $count = 0;

	foreach my $p (keys(%index)) {
	    my $q = $index{$p}{'deps'}{$PORT};
	    if ($q) {
		$DEPPORTS{$p} = 1;
		++$count;
	    }
	}
	print "- Found $count ports depending on $PORT.\n";
    }
}

#
# In shallow mode, strip all those who don't have a direct dependency
#
sub direct_dependency($@) {
    if ($debug) { print STDERR Dumper \@_; }
    my ($port, @requisites) = @_;
    open F, '-|', '/usr/bin/make', '-C', $port, qw/-V _RUN_DEPENDS -V _LIB_DEPENDS/ or die "cannot launch make: $!";
    my @lines = <F>;
    chomp @lines;
    my $deps = join(" ", @lines);
    my %deps = map { $_ =~ s[/usr/ports/][]; $_ =~ s[$portsdir/][]; ($_ => 1) } split " ", $deps;
    if ($!) { die "cannot read depends from make: $!"; }
    close F or Carp::carp "cannot read depends from make: $!";
    my $required = grep { $_ } map { defined $deps{$_} } @requisites;
    return $required;
}

if ($shallow) {
    my $n = keys %DEPPORTS;
    my $idx = 1;
    foreach my $p (keys %DEPPORTS) {
	print "- Checking requisites of port $idx/$n... \r";
	print "\n" if $debug;
	++$idx;
	my $pp = $index{$p}->{'origin'};
	unless (direct_dependency($pp, map { $index{$_}{origin} } @ARGV)) {
	    delete $DEPPORTS{$p};
	}
    }
    print "- Found ", scalar keys(%DEPPORTS), " ports depending directly on either of @ARGV.\n";
}

my $ports = join(" ", keys %DEPPORTS);

#
# Create a temp directory and cvs checkout the ports
# (don't do error checking, too complicated right now)
#
unless ($opt_f or $opt_n) {
  $TMPDIR = ".bump_revision_pl_tmpdir.$$";
  die "This code fragment has not been updated for Git yet.";
  print "svn checkout into $TMPDIR...\n";
  mkdir($TMPDIR, 0755);
  chdir($TMPDIR);
  system "svn checkout --depth=immediates svn+ssh://repo.freebsd.org/ports/head/ ports" and die "SVN checkout failed (wait value $?), aborting";
  chdir('ports');
  system "svn update --set-depth=infinity $ports" and die "SVN checkout failed (wait value $?), aborting";
}

#
# Bump portrevisions
#
{
    print "Updating Makefiles\n";
    foreach my $p (sort keys(%DEPPORTS)) {
	my $origin = $index{$p}->{'origin'};
	print "- Updating Makefile of $origin\n";
        unless($opt_n) { 
	    bumpMakefile "$origin";
	}
    }
}

#
# Commit the changes. Not automated.
#
unless ($opt_n) {
    print <<EOF;
All PORTREVISIONs have been updated.  You are nearly done, only one
thing remains:  Committing to the ports tree.  This program is not
going to do that for you, you have to do it manually.

\$ cd $TMPDIR
\$ git commit
	
Then, remove the temp directory ($TMPDIR).
EOF
}
