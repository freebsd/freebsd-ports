# New ports collection makefile for:	devel/p5-CPANPLUS
# Date created:				2 February 2005
# Whom:					Alex Kapranoff <kappa@rambler-co.ru>
#
# $FreeBSD$
#

PORTNAME=	CPANPLUS
PORTVERSION=	0.8400
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/0+$//}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Ameliorated interface to the CPAN

RUN_DEPENDS=	p5-Module-Signature>=0:${PORTSDIR}/security/p5-Module-Signature

USE_PERL5=	5.6.1+
PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	AUTOINSTALL=1
INSTALL_TARGET=	pure_install

OPTIONS=	TEST_REPORTER "Send reports to cpan-testers" off \
		YAML "Check reports from cpan-testers" off

MAN3=	CPANPLUS.3 \
	CPANPLUS::Backend.3 \
	CPANPLUS::Backend::RV.3 \
	CPANPLUS::Config.3 \
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
	CPANPLUS::Selfupdate.3 \
	CPANPLUS::Shell.3 \
	CPANPLUS::Shell::Classic.3 \
	CPANPLUS::Shell::Default.3 \
	CPANPLUS::Shell::Default::Plugins::CustomSource.3 \
	CPANPLUS::Shell::Default::Plugins::HOWTO.3 \
	CPANPLUS::Shell::Default::Plugins::Remote.3 \
	CPANPLUS::Shell::Default::Plugins::Source.3 \
	CPANPLUS::inc.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500904
RUN_DEPENDS+=	p5-Module-Load>=0.10:${PORTSDIR}/devel/p5-Module-Load \
		p5-Module-Loaded>=0.01:${PORTSDIR}/devel/p5-Module-Loaded \
		p5-Package-Constants>=0.01:${PORTSDIR}/devel/p5-Package-Constants
.endif

.if ${PERL_LEVEL} < 500905
RUN_DEPENDS+=	p5-Archive-Extract>=0.16:${PORTSDIR}/archivers/p5-Archive-Extract \
		p5-IPC-Cmd>=0.36:${PORTSDIR}/devel/p5-IPC-Cmd \
		p5-Locale-Maketext-Simple>=0.01:${PORTSDIR}/devel/p5-Locale-Maketext-Simple \
		p5-Log-Message>=0.01:${PORTSDIR}/devel/p5-Log-Message \
		p5-Object-Accessor>=0.32:${PORTSDIR}/devel/p5-Object-Accessor \
		p5-Params-Check>=0.22:${PORTSDIR}/devel/p5-Params-Check
.endif

.if ${PERL_LEVEL} < 501000
RUN_DEPENDS+=	p5-File-Fetch>=0.13_04:${PORTSDIR}/ftp/p5-File-Fetch \
		p5-Module-Load-Conditional>=0.18:${PORTSDIR}/devel/p5-Module-Load-Conditional \
		p5-Term-UI>=0.18:${PORTSDIR}/devel/p5-Term-UI
PLIST_SUB+=	EXE_FILES=""
MAN1=		cpanp.1 cpan2dist.1
.else
PLIST_SUB+=	EXE_FILES="@comment "
.endif

post-patch:
.if ${PERL_LEVEL} >= 501000
	@${REINPLACE_CMD} -e 's/5.009/5.666/; /install_script/d' ${WRKSRC}/Makefile.PL
.endif

.if defined(WITH_TEST_REPORTER)
RUN_DEPENDS+=	${SITE_PERL}/Test/Reporter.pm:${PORTSDIR}/devel/p5-Test-Reporter
.endif

.if defined(WITH_YAML)
RUN_DEPENDS+=	${SITE_PERL}/YAML.pm:${PORTSDIR}/textproc/p5-YAML
.endif

.include <bsd.port.post.mk>
