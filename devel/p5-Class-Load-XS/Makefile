# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Class-Load-XS
PORTVERSION=	0.06
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	XS implementation of parts of Class::Load

LICENSE=	ART20

BUILD_DEPENDS=	p5-Class-Load>=0.20:${PORTSDIR}/devel/p5-Class-Load
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Module-Implementation>=0.04:${PORTSDIR}/devel/p5-Module-Implementation \
		p5-Test-Fatal>=0:${PORTSDIR}/devel/p5-Test-Fatal \
		p5-Test-Requires>=0:${PORTSDIR}/devel/p5-Test-Requires \
		p5-Test-Without-Module>=0:${PORTSDIR}/devel/p5-Test-Without-Module

USE_PERL5=	modbuild
USES=		perl5

.include <bsd.port.mk>
