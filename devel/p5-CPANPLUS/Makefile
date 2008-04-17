# New ports collection makefile for:	devel/p5-CPANPLUS
# Date created:				2 February 2005
# Whom:					Alex Kapranoff <kappa@rambler-co.ru>
#
# $FreeBSD$
#

PORTNAME=	CPANPLUS
PORTVERSION=	0.0760
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-0.076

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	Ameliorated interface to the CPAN

BUILD_DEPENDS=	p5-File-Fetch>=0.07:${PORTSDIR}/ftp/p5-File-Fetch \
		p5-IPC-Cmd>=0.24:${PORTSDIR}/devel/p5-IPC-Cmd \
		p5-Locale-Maketext-Simple>0:${PORTSDIR}/devel/p5-Locale-Maketext-Simple \
		p5-Log-Message>0:${PORTSDIR}/devel/p5-Log-Message \
		p5-Module-Load>=0.10:${PORTSDIR}/devel/p5-Module-Load \
		p5-Module-Load-Conditional>=0.07:${PORTSDIR}/devel/p5-Module-Load-Conditional \
		p5-Params-Check>=0.22:${PORTSDIR}/devel/p5-Params-Check \
		p5-Package-Constants>0:${PORTSDIR}/devel/p5-Package-Constants \
		p5-Term-UI>=0.05:${PORTSDIR}/devel/p5-Term-UI \
		p5-Test-Harness>=2.62:${PORTSDIR}/devel/p5-Test-Harness \
		p5-Test-Simple>=0.47:${PORTSDIR}/devel/p5-Test-Simple \
		p5-Archive-Extract>=0.07:${PORTSDIR}/archivers/p5-Archive-Extract \
		p5-Archive-Tar>=1.23:${PORTSDIR}/archivers/p5-Archive-Tar \
		p5-IO-Zlib>=1.04:${PORTSDIR}/archivers/p5-IO-Zlib \
		p5-Object-Accessor>=0.03:${PORTSDIR}/devel/p5-Object-Accessor \
		p5-Module-CoreList>=1.97:${PORTSDIR}/devel/p5-Module-CoreList \
		p5-Module-Pluggable>=2.4:${PORTSDIR}/devel/p5-Module-Pluggable \
		p5-Module-Loaded>0:${PORTSDIR}/devel/p5-Module-Loaded
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	AUTOINSTALL=1
INSTALL_TARGET=	pure_install

OPTIONS=	TEST_REPORTER "Send reports to cpan-testers" off \
		YAML "Check reports from cpan-testers" off

.include <bsd.port.pre.mk>

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
	CPANPLUS::Configure.3 \
	CPANPLUS::Dist.3 \
	CPANPLUS::Dist::Base.3 \
	CPANPLUS::Dist::MM.3 \
	CPANPLUS::Dist::Sample.3 \
	CPANPLUS::Error.3 \
	CPANPLUS::FAQ.3 \
	CPANPLUS::Hacking.3 \
	CPANPLUS::Internals.3 \
	CPANPLUS::Internals::Extract.3 \
	CPANPLUS::Internals::Fetch.3 \
	CPANPLUS::Internals::Report.3 \
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
