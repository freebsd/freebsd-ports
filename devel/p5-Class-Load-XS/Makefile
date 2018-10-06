# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Class-Load-XS
PORTVERSION=	0.10
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	XS implementation of parts of Class::Load

LICENSE=	ART20

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-Load>=0.20:devel/p5-Class-Load
TEST_DEPENDS=	p5-Module-Implementation>=0.04:devel/p5-Module-Implementation \
		p5-Test-Fatal>=0:devel/p5-Test-Fatal \
		p5-Test-Needs>=0:devel/p5-Test-Needs \
		p5-Test-Without-Module>=0:devel/p5-Test-Without-Module

USE_PERL5=	configure
USES=		perl5

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Class/Load/XS/XS.so

.include <bsd.port.mk>
