# New ports collection makefile for:	devel/p5-CPANPLUS
# Date created:				2 February 2005
# Whom:					Alex Kapranoff <kappa@rambler-co.ru>
#
# $FreeBSD$
#

PORTNAME=	CPANPLUS
PORTVERSION=	0.0562
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/K/KA/KANE
PKGNAMEPREFIX=	p5-

MAINTAINER=	kappa@freebsd.org.ua
COMMENT=	Ameliorated interface to the CPAN

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	AUTOINSTALL=1
INSTALL_TARGET=	pure_install

OPTIONS=	TEST_REPORTER "Send reports to cpan-testers" off \
		YAML "Check reports from cpan-testers" off

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		This port requires perl 5.6.0 or later. Install lang/perl5 then try again
.endif

.if defined(WITH_TEST_REPORTER)
BUILD_DEPENDS+=	${SITE_PERL}/Test/Reporter.pm:${PORTSDIR}/devel/p5-Test-Reporter
RUN_DEPENDS+=	${SITE_PERL}/Test/Reporter.pm:${PORTSDIR}/devel/p5-Test-Reporter
.endif

.if defined(WITH_YAML)
BUILD_DEPENDS+=	${SITE_PERL}/YAML.pm:${PORTSDIR}/textproc/p5-YAML
RUN_DEPENDS+=	${SITE_PERL}/YAML.pm:${PORTSDIR}/textproc/p5-YAML
.endif

MAN1=		cpanp.1 cpan2dist.1
MAN3=		CPANPLUS.3 \
		CPANPLUS::Backend.3 \
		CPANPLUS::Backend::RV.3 \
		CPANPLUS::Config.3 \
		CPANPLUS::Configure.3 \
		CPANPLUS::Dist.3 \
		CPANPLUS::Dist::MM.3 \
		CPANPLUS::Dist::Sample.3 \
		CPANPLUS::Error.3 \
		CPANPLUS::FAQ.3 \
		CPANPLUS::Hacking.3 \
		CPANPLUS::Internals.3 \
		CPANPLUS::Internals::Extract.3 \
		CPANPLUS::Internals::Fetch.3 \
		CPANPLUS::Internals::Search.3 \
		CPANPLUS::Internals::Source.3 \
		CPANPLUS::Internals::Utils.3 \
		CPANPLUS::Module.3 \
		CPANPLUS::Module::Author.3 \
		CPANPLUS::Module::Author::Fake.3 \
		CPANPLUS::Module::Checksums.3 \
		CPANPLUS::Module::Fake.3 \
		CPANPLUS::Shell.3 \
		CPANPLUS::Shell::Classic.3 \
		CPANPLUS::Shell::Default.3 \
		CPANPLUS::inc.3 \
		CPANPLUS::inc::Archive::Extract.3 \
		CPANPLUS::inc::Archive::Tar.3 \
		CPANPLUS::inc::Archive::Tar::File.3 \
		CPANPLUS::inc::Config::Auto.3 \
		CPANPLUS::inc::DBIx::Simple::OO.3 \
		CPANPLUS::inc::File::Fetch.3 \
		CPANPLUS::inc::File::Spec.3 \
		CPANPLUS::inc::File::Spec::Cygwin.3 \
		CPANPLUS::inc::File::Spec::Epoc.3 \
		CPANPLUS::inc::File::Spec::Functions.3 \
		CPANPLUS::inc::File::Spec::Mac.3 \
		CPANPLUS::inc::File::Spec::OS2.3 \
		CPANPLUS::inc::File::Spec::Unix.3 \
		CPANPLUS::inc::File::Spec::VMS.3 \
		CPANPLUS::inc::File::Spec::Win32.3 \
		CPANPLUS::inc::IO::String.3 \
		CPANPLUS::inc::IO::Zlib.3 \
		CPANPLUS::inc::IPC::Cmd.3 \
		CPANPLUS::inc::IPC::Run.3 \
		CPANPLUS::inc::IPC::Run::Debug.3 \
		CPANPLUS::inc::IPC::Run::IO.3 \
		CPANPLUS::inc::IPC::Run::Timer.3 \
		CPANPLUS::inc::IPC::Run::Win32Helper.3 \
		CPANPLUS::inc::IPC::Run::Win32IO.3 \
		CPANPLUS::inc::IPC::Run::Win32Pump.3 \
		CPANPLUS::inc::Locale::Maketext::Simple.3 \
		CPANPLUS::inc::Log::Message.3 \
		CPANPLUS::inc::Log::Message::Config.3 \
		CPANPLUS::inc::Log::Message::Handlers.3 \
		CPANPLUS::inc::Log::Message::Item.3 \
		CPANPLUS::inc::Log::Message::Simple.3 \
		CPANPLUS::inc::Module::CoreList.3 \
		CPANPLUS::inc::Module::Load.3 \
		CPANPLUS::inc::Module::Load::Conditional.3 \
		CPANPLUS::inc::Module::Pluggable.3 \
		CPANPLUS::inc::Object::Accessor.3 \
		CPANPLUS::inc::Params::Check.3 \
		CPANPLUS::inc::Term::UI.3 \
		CPANPLUS::inc::Term::UI::History.3

post-patch:
	@${FIND} ${WRKSRC} -name "*\.orig" -delete

post-configure:
	@${REINPLACE_CMD} -Ee \
		"s|('base' => )'.*(/.cpanplus)',|\1\"\$$ENV{'HOME'}\2\",|" \
		${WRKSRC}/lib/CPANPLUS/Config.pm

.include <bsd.port.post.mk>
