# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	DateTime-Astro
PORTVERSION=	1.00
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DMAKI
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Functions For Astromical Calendars

LICENSE=	ART20

BUILD_DEPENDS=	p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-DateTime-Set>=0:${PORTSDIR}/devel/p5-DateTime-Set
LIB_DEPENDS=	libmpfr.so:${PORTSDIR}/math/mpfr
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception

USE_PERL5=	configure
USES=		gmake localbase perl5

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/DateTime/Astro/Astro.so

.include <bsd.port.mk>
