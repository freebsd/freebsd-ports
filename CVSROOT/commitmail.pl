#! /usr/bin/perl -w
#
# $FreeBSD$

use strict;

my $access = "/home/ncvs/CVSROOT/access";
my @names = ();
my $mailcmd = "/home/majordomo/wrapper resend.nobm -l $ARGV[0] " .
    "-f owner-$ARGV[0] -h FreeBSD.org";
#$mailcmd = "/usr/sbin/sendmail -oem -f owner-$ARGV[0]";

open(ACCESS, "< $access") || exit 75;
while (<ACCESS>) {
	next if /^[#\/;]/;
	chomp;

	my ($committer, $alt_emailaddr) = split;
	if ($alt_emailaddr) {
		push @names, $alt_emailaddr;
	} else {
		push @names, $committer;
	}
}

my $list = join " ", sort @names;
if ($list ne '') {
	exec "$mailcmd $list";
	die "Can't exec `$mailcmd': $!";
} else {
	die "Can't generate names from $access!";
}


# Jan 15 09:47:55 hub sendmail[14995]: JAB14995: to=/home/mail/archive/cvs-committers, delay=00:00:00, xdelay=00:00:00, mailer=*file*, stat=Sent
# Jan 15 09:48:00 hub sendmail[14995]: JAB14995: to="|/home/mail/mailtogroup.pl ncvs cvs-committers", delay=00:00:05, xdelay=00:00:05, mailer=prog, stat=unknown mailer error 13

