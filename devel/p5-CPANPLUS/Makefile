# Created by: Alex Kapranoff <kappa@rambler-co.ru>
# $FreeBSD$

PORTNAME=	CPANPLUS
PORTVERSION=	0.9142
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:BINGOS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Ameliorated interface to the CPAN

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Module-Signature>=0:${PORTSDIR}/security/p5-Module-Signature
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_DEFINE=	TEST_REPORTER YAML
TEST_REPORTER_DESC=	Send reports to cpan-testers

CONFIGURE_ARGS=	AUTOINSTALL=1
INSTALL_TARGET=	pure_install
MAKE_JOBS_UNSAFE=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTEST_REPORTER}
BUILD_DEPENDS+=	p5-Test-Reporter>=0:${PORTSDIR}/devel/p5-Test-Reporter
RUN_DEPENDS+=	p5-Test-Reporter>=0:${PORTSDIR}/devel/p5-Test-Reporter
.endif

.if ${PORT_OPTIONS:MYAML}
BUILD_DEPENDS+=	p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML
RUN_DEPENDS+=	p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML
.endif

post-patch:
	@${REINPLACE_CMD} -e '/install_script/d' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
