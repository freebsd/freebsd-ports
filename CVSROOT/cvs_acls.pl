#!/usr/bin/perl -w
#
# $FreeBSD$
#
# Access control lists for CVS.  dgg@ksr.com (David G. Grubbs)
#
# ==== FORMAT OF THE avail FILE:
#
# The avail file determines whether you may commit files.  It contains lines
# read from top to bottom, keeping track of a single "bit".  The "bit"
# defaults to "on".  It can be turned "off" by "unavail" lines and "on" by
# "avail" lines.  ==> Last one counts.
#
# Any line not beginning with "avail" or "unavail" is ignored.
#
# Lines beginning with "avail" or "unavail" are assumed to be '|'-separated
# triples: (All spaces and tabs are ignored in a line.)
#
#   {avail.*,unavail.*} [| user,user,... [| repos,repos,...]]
#
#    1. String starting with "avail" or "unavail".
#    2. Optional, comma-separated list of usernames.
#    3. Optional, comma-separated list of repository pathnames.
#	These are pathnames relative to $CVSROOT.  They can be directories or
#	filenames.  A directory name allows access to all files and
#	directories below it.
#
# Example:  (Text from the ';;' rightward may not appear in the file.)
#
#	unavail			;; Make whole repository unavailable.
#	avail|dgg		;; Except for user "dgg".
#	avail|fred, john|bin/ls	;; Except when "fred" or "john" commit to
#				;; the module whose repository is "bin/ls"
#
# PROGRAM LOGIC:
#
#	CVS passes to @ARGV an absolute directory pathname (the repository
#	appended to your $CVSROOT variable), followed by a list of filenames
#	within that directory.
#
#	We walk through the avail file looking for a line that matches both
#	the username and repository.
#
#	A username match is simply the user's name appearing in the second
#	column of the avail line in a space-or-comma separate list.
#
#	A repository match is either:
#		- One element of the third column matches $ARGV[0], or some
#		  parent directory of $ARGV[0].
#		- Otherwise *all* file arguments ($ARGV[1..$#ARGV]) must be
#		  in the file list in one avail line.
#	    - In other words, using directory names in the third column of
#	      the avail file allows committing of any file (or group of
#	      files in a single commit) in the tree below that directory.
#	    - If individual file names are used in the third column of
#	      the avail file, then files must be committed individually or
#	      all files specified in a single commit must all appear in
#	      third column of a single avail line.
#
# Additional (2001/11/16): I've added a group function for labelling
# groups of users.  To define a group add a line in the avail file of
# the form:
#	group|grpname1|joe,fred,bob
#	group|grpname2|pete,:grpname1,simon
#	group|grpname2|sid,:grpname2,mike
#
# The group name can be used in any place a user name could be used in
# an avail or unavail line.  Just precede the group name with a ':'
# character.  In the example above you'll note that you can define a
# group more than once.  Each definition overrides the previous one,
# but can include itself to add to it.


use strict;

use lib $ENV{CVSROOT};
use CVSROOT::cfg;
my $CVSROOT = $ENV{'CVSROOT'} || die "Can't determine \$CVSROOT!";

my $debug = $cfg::DEBUG;

my %GROUPS;		# List of committer groups
my $exit_val = 0;	# Good Exit value
my $universal_off = 0;


#######################################
# process any variable=value switches
#######################################
my $die = '';
eval "print STDERR \$die='Unknown parameter $1\n' if !defined \$$1; \$$1=\$';"
    while ($ARGV[0] =~ /^(\w+)=/ && shift(@ARGV));
exit 255 if $die;


#######################################
# Work out where in the repo we're at.
#######################################
my $repos = shift;
$repos =~ s:^$CVSROOT/::;
grep($_ = $repos . '/' . $_, @ARGV);

print "$$ Repos: $repos\n","$$ ==== ",join("\n$$ ==== ",@ARGV),"\n" if $debug;


#######################################
# Check that the user has permission.
#######################################

# It is ok for the avail file not to exist.
exit 0 unless -e $cfg::AVAIL_FILE;

# Suck in a list of committer groups from the avail file.
open (AVAIL, $cfg::AVAIL_FILE) || die "Can't open $cfg::AVAIL_FILE!\n";
while (<AVAIL>) {
	next unless /^group\|/;
	chomp;

	my ($keywrd, $gname, $members) = split /\|/, $_;
	$GROUPS{$gname} = expand_users($members);
}
close(AVAIL);


open (AVAIL, $cfg::AVAIL_FILE) || die "Can't open $cfg::AVAIL_FILE!\n";
while (<AVAIL>) {
	chomp;
	next if /^\s*\#/;
	next if /^\s*$/;
	next if /^group\|/;

	print "--------------------\n" if $debug;

	my ($flagstr, $u, $m) = split(/[\s,]*\|[\s,]*/, $_);

	# Skip anything not starting with "avail" or "unavail" and complain.
	if ($flagstr !~ /^avail/ && $flagstr !~ /^unavail/) {
		print "Bad avail line: $_\n";
		next;
	}

	# Set which bit we are playing with. ('0' is OK == Available).
	my $flag = (($& eq "avail") ? 0 : 1);

	# If we find a "universal off" flag (i.e. a simple "unavail")
	# remember it
	my $universal_off = 1 if ($flag && !$u && !$m);

 	# Expand any group names into a full user list.
 	$u = expand_users($u);

	# $cfg::COMMITTER considered "in user list" if actually in list
	# or is NULL
	my $in_user = (!$u || grep ($_ eq $cfg::COMMITTER, split(/[\s,]+/,$u)));
	print "$$ \$cfg::COMMITTER ($cfg::COMMITTER) in user list: $_\n"
	    if $debug && $in_user;

	# Module matches if it is a NULL module list in the avail line.
	# If module list is not null, we check every argument combination.
	my $in_repo = (!$m || 0);
	if (!$in_repo) {
		my @tmp = split(/[\s,]+/,$m);
		for my $j (@tmp) {
			# If the repos from avail is a parent(or equal)
			# dir of $repos, OK
			$in_repo = 1, last if ($repos eq $j || $repos =~ /^$j\//);
		}
		if (!$in_repo) {
			#$in_repo = 1;
			for my $j (@ARGV) {
				last if !($in_repo = grep ($_ eq $j, @tmp));
			}
		}
	}
	print "$$ \$repos($repos) in repository list: $_\n"
	    if $debug && $in_repo;

	print "$$ Expanded user list: $u\n" if $debug;

	$exit_val = $flag if ($in_user && $in_repo);
	print "$$ ==== \$exit_val = $exit_val\n$$ ==== \$flag = $flag\n"
	    if $debug;
}
close(AVAIL);
print "$$ ==== \$exit_val = $exit_val\n" if $debug;
print "**** Access denied: Insufficient Karma ($cfg::COMMITTER|$repos)\n"
    if $exit_val;
print "**** Access allowed: Personal Karma exceeds Environmental Karma.\n"
    if $debug && $universal_off && !$exit_val;
exit($exit_val);


# Expand a user specification containing group names and deltas into
# a definitive list of users.
sub expand_users {
	my $user_list = shift || "";

	# Parse the members.
	my @members = split /,/, $user_list;
	my %members;
	foreach my $m (@members) {
		if ($m =~ s/^://) {
			if (!defined($GROUPS{$m})) {
				warn "Group '$m' not defined before use in " . 
				    "$cfg::AVAIL_FILE.\n";
				next;
			}
			# Add the specified group to the membership.
			foreach my $u (split /,/, $GROUPS{$m}) {
				$members{$u} = 1;
			}
		} else {
			$members{$m} = 1;
		}
	}

	return join("," , sort keys %members);
}
