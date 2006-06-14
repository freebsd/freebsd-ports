# New ports collection makefile for:	devel/p5-CPANPLUS
# Date created:				2 February 2005
# Whom:					Alex Kapranoff <kappa@rambler-co.ru>
#
# $FreeBSD$
#

PORTNAME=	CPANPLUS
PORTVERSION=	0.0610
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/K/KA/KANE
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-0.061

MAINTAINER=	kappa@freebsd.org.ua
COMMENT=	Ameliorated interface to the CPAN

BUILD_DEPENDS=	${SITE_PERL}/IPC/Cmd.pm:${PORTSDIR}/devel/p5-IPC-Cmd \
		${SITE_PERL}/Object/Accessor.pm:${PORTSDIR}/devel/p5-Object-Accessor \
		${SITE_PERL}/Module/CoreList.pm:${PORTSDIR}/devel/p5-Module-CoreList \
		${SITE_PERL}/Archive/Extract.pm:${PORTSDIR}/archivers/p5-Archive-Extract \
		${SITE_PERL}/File/Fetch.pm:${PORTSDIR}/ftp/p5-File-Fetch \
		${SITE_PERL}/Log/Message.pm:${PORTSDIR}/devel/p5-Log-Message \
		${SITE_PERL}/Module/Loaded.pm:${PORTSDIR}/devel/p5-Module-Loaded \
		${SITE_PERL}/Term/UI.pm:${PORTSDIR}/devel/p5-Term-UI \
		${SITE_PERL}/Archive/Tar.pm:${PORTSDIR}/archivers/p5-Archive-Tar \
		${SITE_PERL}/IO/Zlib.pm:${PORTSDIR}/archivers/p5-IO-Zlib \
		${SITE_PERL}/Module/Pluggable.pm:${PORTSDIR}/devel/p5-Module-Pluggable
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	AUTOINSTALL=1
INSTALL_TARGET=	pure_install

OPTIONS=	TEST_REPORTER "Send reports to cpan-testers" off \
		YAML "Check reports from cpan-testers" off

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		requires perl 5.6.1 or later. Install lang/perl5 then try again
.endif

.if defined(WITH_TEST_REPORTER)
BUILD_DEPENDS+=	${SITE_PERL}/Test/Reporter.pm:${PORTSDIR}/devel/p5-Test-Reporter
RUN_DEPENDS+=	${SITE_PERL}/Test/Reporter.pm:${PORTSDIR}/devel/p5-Test-Reporter
.endif

.if defined(WITH_YAML)
BUILD_DEPENDS+=	${SITE_PERL}/YAML.pm:${PORTSDIR}/textproc/p5-YAML
RUN_DEPENDS+=	${SITE_PERL}/YAML.pm:${PORTSDIR}/textproc/p5-YAML
.endif

MAN1=	cpanp.1 cpan2dist.1
MAN3=	CPANPLUS.3 \
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
	CPANPLUS::Shell::Default::Plugins::HOWTO.3 \
	CPANPLUS::Shell::Default::Plugins::Remote.3 \
	CPANPLUS::Shell::Default::Plugins::Source.3 \
	CPANPLUS::inc.3

post-patch:
	@${FIND} ${WRKSRC} -name "*\.orig" -delete

post-configure:
	@${REINPLACE_CMD} -Ee \
		"s|('base' => )'.*(/.cpanplus)',|\1\"\$$ENV{'HOME'}\2\",|" \
		${WRKSRC}/lib/CPANPLUS/Config.pm

.include <bsd.port.post.mk>
