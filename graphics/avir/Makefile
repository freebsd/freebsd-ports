# $FreeBSD$

PORTNAME=	avir
DISTVERSION=	2.4
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	High-quality image resizing/scaling C++ library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	avaneev

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	include/avir/avir.h \
		include/avir/avir_dil.h \
		include/avir/avir_float4_sse.h \
		include/avir/avir_float8_avx.h \
		include/avir/lancir.h

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/avir
	${INSTALL_DATA} ${WRKSRC}/*.h ${STAGEDIR}${PREFIX}/include/avir/

.include <bsd.port.mk>
