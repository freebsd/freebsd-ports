#! /usr/bin/perl
#
# $Id$

$access = "/home/ncvs/CVSROOT/access";
@names = ();
$mailcmd = "/home/majordomo/wrapper resend.nobm -l $ARGV[0] -f owner-$ARGV[0] -h FreeBSD.org";
#$mailcmd = "/usr/sbin/sendmail -oem -f owner-$ARGV[0]";

open(ACCESS, "< $access") || exit 75;
while (<ACCESS>) {
	chop;
	@words = split;
	if ($words[0] =~ /^[#\/;]/) {
		next;
	}
	push @names, $words[0];
}
$list = join(" ", @names);
if ($list ne '') {
	exec "$mailcmd $list";
	die "cant exec `$mailcmd': $!";
} else {
	die "cannot generate names from $access!";
}


# Jan 15 09:47:55 hub sendmail[14995]: JAB14995: to=/home/mail/archive/cvs-committers, delay=00:00:00, xdelay=00:00:00, mailer=*file*, stat=Sent
# Jan 15 09:48:00 hub sendmail[14995]: JAB14995: to="|/home/mail/mailtogroup.pl ncvs cvs-committers", delay=00:00:05, xdelay=00:00:05, mailer=prog, stat=unknown mailer error 13

