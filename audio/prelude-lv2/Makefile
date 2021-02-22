# $FreeBSD$

PORTNAME=	prelude
DISTVERSION=	g20210218
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
GH_PROJECT=	prelude.lv2
GH_TAGNAME=	1934247

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lv2/prelude.lv2/prelude.so

.include <bsd.port.mk>
