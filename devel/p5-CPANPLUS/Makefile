# New ports collection makefile for:	devel/p5-CPANPLUS
# Date created:				2 February 2005
# Whom:					Alex Kapranoff <kappa@rambler-co.ru>
#
# $FreeBSD$
#

PORTNAME=	CPANPLUS
PORTVERSION=	0.9133
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:BINGOS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Ameliorated interface to the CPAN

RUN_DEPENDS=	p5-Module-Signature>=0:${PORTSDIR}/security/p5-Module-Signature

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	AUTOINSTALL=1
INSTALL_TARGET=	pure_install

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	TEST_REPORTER YAML

TEST_REPORTER_DESC=	Send reports to cpan-testers

MAN3=	CPANPLUS.3 \
	CPANPLUS::Backend.3 \
	CPANPLUS::Backend::RV.3 \
	CPANPLUS::Config.3 \
	CPANPLUS::Config::HomeEnv.3 \
	CPANPLUS::Configure.3 \
	CPANPLUS::Dist.3 \
	CPANPLUS::Dist::Autobundle.3 \
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
	CPANPLUS::Internals::Source::Memory.3 \
	CPANPLUS::Internals::Source::SQLite.3 \
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
	CPANPLUS::Shell::Default::Plugins::Source.3

.include <bsd.port.pre.mk>

# XXX:az pkg-plist
PLIST_SUB+=	EXE_FILES="@comment "

post-patch:
	@${REINPLACE_CMD} -e 's/5.009/5.666/; /install_script/d' ${WRKSRC}/Makefile.PL

.if ${PORT_OPTIONS:MTEST_REPORTER}
RUN_DEPENDS+=	p5-Test-Reporter>=0:${PORTSDIR}/devel/p5-Test-Reporter
.endif

.if ${PORT_OPTIONS:MYAML}
RUN_DEPENDS+=	p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML
.endif

.include <bsd.port.post.mk>
