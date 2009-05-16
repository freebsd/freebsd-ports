#!/usr/bin/perl -w

# $FreeBSD$
#
# MAINTAINER=   pgollucci@FreeBSD.org

## core
use strict;
use warnings FATAL => 'all';
use Carp;

use File::Find ();
use Getopt::Long ();
use Pod::Usage ();

### constants
## exit codes
use constant EXIT_SUCCESS   => 0;
use constant EXIT_FAILED_INVALID_ARGS_OR_ENV => 1;

## other
use constant PROGNAME => $0;

### signal handlers
local $SIG{__DIE__}  = \&Carp::confess;
local $SIG{__WARN__} = \&Carp::cluck;

### version
our $VERSION = do { my @r = (q$FreeBSD$ =~ /\d+/g); sprintf "%d." . "%02d" x $#r, @r };

### globals
# cmdline options (standard) with defaults
my $Help      = 0;
my $Version   = 0;
my $Debug     = 0;
my $Verbose   = 0;
my $NoExec    = 0;

# cmdline options (custom) with defaults
my $Maintainer = "$ENV{USER}\@FreeBSD.org";
my $Ports = 0;
my $Safe = 1;
my $Index = 'INDEX-8';

# internals
my $PORTSDIR = $ENV{PORTSDIR} || '/usr/ports';
my %RPARTS = (
    0 => 'pkg_name',
    1 => 'dir',
    2 => 'prefix',
    3 => 'comment',
    4 => 'pkg_descr',
    5 => 'maintainer',
    6 => 'categories',
    7 => 'ldep',
    8 => 'rdep',
    9 => 'www',
);

my %PARTS = reverse %RPARTS;

### Utility Functions
sub error   { print STDERR "ERROR: $_[0]"                              }
sub debug   { print STDERR "DEBUG: $_[0]"          if $Debug           }
sub verbose { print STDOUT "VERBOSE($_[0]): $_[1]" if $Verbose > $_[0] }

### main
sub getopts_wrapper {

  my $rv =
    Getopt::Long::GetOptions(
      "debug|d"      => \$Debug,
      "verbose=i"    => \$Verbose,
      "help|h"       => \$Help,
      "version|V"    => \$Version,
      "noexec|n"     => \$NoExec,

      "maintainer|m=s" => \$Maintainer,
      "ports|p"        => \$Ports,

      "safe|s=i"       => \$Safe,
      "index|i=s"      => \$Index,
    );

  Pod::Usage::pod2usage(-verbose => 1) unless $rv;

  unless ($Help || valid_args()) {
     $rv = 0;
     Pod::Usage::pod2usage(-verbose => 1);
  }

  return $rv ? 1 : 0;
}

sub valid_args {

  my $errors = 0;

  ## NoExec implies Verbosity level 1
  $Verbose = 1 if $NoExec;

  return $errors > 0 ? 0 : 1;
}

sub work {

  my $rv = EXIT_SUCCESS;

  my $ports = ports_get();
  mark($ports);

  return $rv;
}

sub mark {
  my ($ports) = @_;

  foreach my $port_dir (@$ports) {
    my $mfile = "$port_dir/Makefile";
    print "Mfile: $mfile\n";
    open my $mk, '<', $mfile or die "Can't open [$mfile] b/c [$!]";
    my @lines = <$mk>;
    close $mk or die "Can't close [$mfile] b/c [$!]";
    
    next if grep { /MAKE_JOBS_(?:UN)?SAFE/ } @lines;

    my $i_depends = 0;
    my $i_comment = 0;
    my $i_maintainer = 0;
    my $i = 0;
    foreach my $line (@lines) {
      ## ORDER MATTERs, lowest in file is last
      $i_depends    = $i if $line =~ /DEPENDS/;
      $i_comment    = $i if $line =~ /COMMENT/;
      $i_maintainer = $i if $line =~ /MAINTAINER/;
      ++$i;
    }

    my $loc = $i_depends    > 0 ? $i_depends :
              $i_comment    > 0 ? $i_comment :
              $i_maintainer > 0 ? $i_maintainer : die "Can't find location to insert";

    my @newlines = @lines[0..$loc];
    push @newlines, "\n", "MAKE_JOBS_" . ($Safe ? "SAFE" : "UNSAFE")  . "=  yes\n";
    push @newlines, @lines[$loc+1..$#lines];

    open my $mk_o, '>', $mfile or die "Can't open [$mfile] b/c [$!]";
    foreach my $line (@newlines) {
      print $mk_o $line;
    }
    close $mk_o or die "Can't close [$mfile] b/c [$!]";
  }

  return;
}

sub ports_get {

  my @ports = ();

  if ($Ports) {
    @ports = map { "$PORTSDIR/$_" } @ARGV;
  }
  else {
    my $index = "$PORTSDIR/$Index";
    print "Index: $index\n";

    open my $fh, '<', $index or die "Can't open [$index] b/c [$!]";
    while (<$fh>) {
      my @parts = split /\|/;
      my $port_dir = $parts[$PARTS{dir}];
      $port_dir =~ s!/usr/ports!$PORTSDIR!;
      my $maintainer = $parts[$PARTS{maintainer}];
   
      push @ports, $port_dir if $maintainer =~ /^$Maintainer$/io;
    }
    close $fh or die "Can't close [$index] b/c [$!]";
  }

  @ports = grep { !/^rubygem-// } @ports;

  return \@ports;
}

sub main {

  getopts_wrapper() or return EXIT_FAILED_INVALID_ARGS_OR_ENV;

  if ($Help) {
    Pod::Usage::pod2usage(-verbose => 1);
    return EXIT_SUCCESS;
  }

  if ($Version) {
    print PROGNAME . " - v$VERSION\n\n";
    return EXIT_SUCCESS;
  }

  return work();
}

MAIN: {
  exit main();
}

__END__

=pod

=head1 NAME

mark_safe.pl - Mark a port or ports as MAKE_JOBS_(UN)SAFE=yes

=head1 SYNOPSIS

  mark_safe.pl <options>

=head1 STD OPTIONS

=over 4

=item B<--verbose=1,2,3,4,....>

Display messages while running on STDOUT. Increasing the level
will increase the amount.

DEFAULT: off/0

=item B<--debug|d>

Copious messages not useful unless you are a developer AND
debuging this script are output to STDERR

DEFAULT: off/0

=item B<--help|h>

Print this message and exit EXIT_SUCCESS

DEFAULT: off/0

=item B<--version|V>

Output the version and exit with EXIT_SUCCESS

DEFAULT: off/0

=item B<--noexec|n>

Any External commands will simply be echo'd and not run
Assume all of them suceed.

IMPLIES: --verbose=1

DEFAULT: off/0

=head1 Dependencies

=head1 EXIT CODES

Exits 0 on success
Exits > 0 <= 255 on error

  EXIT_SUCCESS                    => 0
    EXIT_FAILED_INVALID_ARGS_OR_ENV => 1

=head1 HISTORY

20009-04-22 by pgollucci:
   Created

=head1 AUTHOR

Philip M. Gollucci E<lt>pgollucci@FreeBSD.orgE<gt>

=cut

