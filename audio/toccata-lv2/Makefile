# $FreeBSD$

PORTNAME=	toccata
DISTVERSION=	g20200819
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simple wavetable-based church organ as an LV2 plugin

LICENSE=	LGPL3

BUILD_DEPENDS=	lv2>0:audio/lv2
LIB_DEPENDS=	libsfizz.so:audio/sfizz

USES=		cmake localbase:ldflags

USE_GITHUB=	yes
GH_ACCOUNT=	sfztools
GH_PROJECT=	${PORTNAME}.lv2
GH_TAGNAME=	d909db6

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lv2/${PORTNAME}.lv2/${PORTNAME}.so

.include <bsd.port.mk>
