# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Test-Trap
PORTVERSION=	0.2.3
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Trap exit codes, exceptions, output, etc

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Data-Dump>=0:${PORTSDIR}/devel/p5-Data-Dump
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Tester>=0.10.7:${PORTSDIR}/devel/p5-Test-Tester

USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
