#! %%PREFIX%%/bin/perl -w
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

my $port_perl = '%%PREFIX%%/bin/perl';
$port_perl =~ tr|/|/|s;

@ARGV == 1 or usage();
if ($ARGV[0] eq 'port') {
	switch_to_port();
} elsif ($ARGV[0] eq 'system') {
	switch_to_system();
} else {
	usage();
}
exit 0;

# Both functions depend on the idea that switch_to_port leaves
# perl5 alone.  If the wrapper is installed on a -current system,
# /usr/bin/perl5 will also be the wrapper.

sub switch_to_system
{
	# protect against cases where people use PREFIX=/usr
	if ($port_perl ne '/usr/bin/perl') {
		unlink '/usr/bin/perl', '/usr/bin/suidperl',
			'/usr/bin/perl%%PERL_VERSION%%';

		link '/usr/bin/perl5', '/usr/bin/perl';
		link '/usr/bin/perl5', '/usr/bin/perl%%PERL_VERSION%%';

		my $ident = `/usr/bin/ident -q /usr/bin/perl5`;
		if ($ident =~ m#src/usr.bin/perl/perl.c#) {
			link '/usr/bin/perl5', '/usr/bin/suidperl';
		} else {
			link '/usr/bin/sperl5', '/usr/bin/suidperl';
		}
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
.undef NO_PERL

EOF
	close MK;

	open MPOLD, "< /etc/manpath.config" or die "/etc/manpath.config: $!";
	open MPNEW, "> /etc/manpath.config.new" or die "/etc/manpath.config.new: $!";
	while (<MPOLD>) {
		next if m|use.perl generated line|;
		next if m|^\s*OPTIONAL_MANPATH\s+\S+/lib/perl5/%%PERL_VERSION%%/man\s*$|;
		print MPNEW;
	}
	close MPNEW;
	close MPOLD;
	rename '/etc/manpath.config', '/etc/manpath.config.bak';
	rename '/etc/manpath.config.new', '/etc/manpath.config';
}

sub switch_to_port
{
	# protect against cases where people use PREFIX=/usr
	if ($port_perl ne '/usr/bin/perl') {

		my $need_perl5_link;
		if (-e "/usr/bin/perl5" && !-l "/usr/bin/perl5") {
			my $ident = `/usr/bin/ident -q /usr/bin/perl5`;
			if ($ident =~ m#src/usr.bin/perl/perl.c#) {
				rename '/usr/bin/perl', '/usr/bin/perl-wrapper';
			} else {
				unlink '/usr/bin/perl';
			}
		} else {
			unlink "/usr/bin/perl5";
			$need_perl5_link = 1;
		}

		unlink '/usr/bin/suidperl', '/usr/bin/perl%%PERL_VERSION%%';

		symlink '%%PREFIX%%/bin/perl', '/usr/bin/perl';
		symlink '%%PREFIX%%/bin/suidperl', '/usr/bin/suidperl';
		symlink '%%PREFIX%%/bin/perl', '/usr/bin/perl%%PERL_VERSION%%';
		symlink '%%PREFIX%%/bin/perl', '/usr/bin/perl5' if $need_perl5_link;
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
NO_PERL=yo
NO_PERL_WRAPPER=yo

EOF
	close MK;

	my $perl_port_manpath = <<EOF;
# -- use.perl generated line -- #
OPTIONAL_MANPATH	%%PREFIX%%/lib/perl5/%%PERL_VERSION%%/man
EOF

	open MPOLD, "< /etc/manpath.config" or die "/etc/manpath.config: $!";
	open MPNEW, "> /etc/manpath.config.new" or die "/etc/manpath.config.new: $!";
	my $modified = 0;
	while (<MPOLD>) {
		if (!$modified && m|^\s*OPTIONAL_MANPATH\s+\S+/lib/perl5/\S+/man\s*$|) {
			print MPNEW $perl_port_manpath;
			$modified = 1;
		}
		print MPNEW;
	}
	print MPNEW $perl_port_manpath unless $modified;
	close MPNEW;
	close MPOLD;
	rename '/etc/manpath.config', '/etc/manpath.config.bak';
	rename '/etc/manpath.config.new', '/etc/manpath.config';
}
