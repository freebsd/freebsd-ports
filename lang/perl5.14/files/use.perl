#! /usr/bin/perl5 -w
# $FreeBSD$
use strict;

# XXX what to do with perldoc, pelbug, perlcc ??

sub usage
{
	print STDERR <<EOF;
Usage:
  $0 port       -> /usr/bin/perl is the perl5 port
  $0 system     -> /usr/bin/perl is the system perl
EOF
	exit 2;
}

@ARGV == 1 or usage();
if ($ARGV[0] eq 'port') {
	switch_to_port();
} elsif ($ARGV[0] eq 'system') {
	switch_to_system();
} else {
	usage();
}
exit 0;

sub switch_to_system
{
	my $port_perl = '%%PREFIX%%/bin/perl';
	$port_perl =~ tr|/|/|s;

	# protect against cases where people use PREFIX=/usr
	if ($port_perl ne '/usr/bin/perl') {
		unlink '/usr/bin/perl', '/usr/bin/suidperl',
			'/usr/bin/perl%%PERL_VERSION%%';

		link '/usr/bin/perl5', '/usr/bin/perl';
		link '/usr/bin/sperl5', '/usr/bin/suidperl';
	}

	open MK, ">> /etc/make.conf" or die "/etc/make.conf: $!";
	print MK <<EOF;
# -- use.perl generated deltas -- #
# Created: @{[scalar localtime]}
# Setting to use base system perl:
.undef PERL_VER
.undef PERL_VERSION
.undef PERL_ARCH
.undef NOPERL

EOF
	close MK;
}

sub switch_to_port
{
	my $port_perl = '%%PREFIX%%/bin/perl';
	$port_perl =~ tr|/|/|s;

	# protect against cases where people use PREFIX=/usr
	if ($port_perl ne '/usr/bin/perl') {
		unlink '/usr/bin/perl', '/usr/bin/suidperl',
			'/usr/bin/perl%%PERL_VERSION%%';

		symlink '%%PREFIX%%/bin/perl', '/usr/bin/perl';
		symlink '%%PREFIX%%/bin/suidperl', '/usr/bin/suidperl';
		symlink '%%PREFIX%%/bin/perl', '/usr/bin/perl%%PERL_VERSION%%';
	}

	open MK, ">> /etc/make.conf" or die "/etc/make.conf: $!";
	print MK <<EOF;
# -- use.perl generated deltas -- #
# Created: @{[scalar localtime]}
# Setting to use base perl from ports:
PERL_VER=%%PERL_VER%%
PERL_VERSION=%%PERL_VERSION%%
PERL_ARCH=%%PERL_ARCH%%
NOPERL=yo

EOF
	close MK;
}
