# Created by: Alexander Kuehn <freebsd@nagilum.org>
# $FreeBSD$

PORTNAME=	zopfli
PORTVERSION=	1.0.3
DISTVERSIONPREFIX=	zopfli-
PORTREVISION=	1
CATEGORIES=	archivers

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Zopfli Compression Algorithm

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake

USE_GITHUB=	yes
GH_ACCOUNT=	google

ALL_TARGET=	libzopfli libzopfli.a libzopflipng libzopflipng.a zopfli zopflipng
MAKE_JOBS_UNSAFE=	yes
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/zopfli ${WRKSRC}/zopflipng ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${PREFIX}/include/zopfli ${STAGEDIR}${PREFIX}/include/zopflipng/lodepng
	${INSTALL_DATA} ${WRKSRC}/src/zopfli/*.h ${STAGEDIR}${PREFIX}/include/zopfli
	${INSTALL_DATA} ${WRKSRC}/src/zopflipng/*.h ${STAGEDIR}${PREFIX}/include/zopflipng
	${INSTALL_DATA} ${WRKSRC}/src/zopflipng/lodepng/*.h ${STAGEDIR}${PREFIX}/include/zopflipng/lodepng
	${INSTALL_DATA} ${WRKSRC}/libzopfli.a ${WRKSRC}/libzopflipng.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/libzopfli.so.${PORTVERSION} ${WRKSRC}/libzopflipng.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib
	${LN} -s libzopfli.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libzopfli.so
	${LN} -s libzopfli.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libzopfli.so.${PORTVERSION:R:R}
	${LN} -s libzopflipng.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libzopflipng.so
	${LN} -s libzopflipng.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libzopflipng.so.${PORTVERSION:R:R}

.include <bsd.port.mk>
