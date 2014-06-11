# Created by: Markus Brueffer <markus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cfitsio
PORTVERSION=	3.360
PORTREVISION=	2
CATEGORIES=	astro
MASTER_SITES=	http://heasarc.gsfc.nasa.gov/FTP/software/fitsio/c/ \
		http://heasarc.gsfc.nasa.gov/FTP/software/fitsio/c/oldvers/ \
		ftp://heasarc.gsfc.nasa.gov/software/fitsio/c/ \
		ftp://heasarc.gsfc.nasa.gov/software/fitsio/c/oldvers/ \
		LOCAL/sunpoet
DISTNAME=	${PORTNAME}${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library for reading and writing files in FITS data format

LICENSE=	MIT

LIB_DEPENDS=	libf2c.so:${PORTSDIR}/lang/f2c

OPTIONS_DEFINE=	DOCS

ALL_TARGET=	libcfitsio.a shared
CFLAGS+=	-I${INCLUDEDIR}
LIBS+=		-L${LIBDIR} -lz
CONFIGURE_ARGS=	ac_cv_prog_FC=f2c
GNU_CONFIGURE=	yes
MAKE_ARGS=	ZLIB_SOURCES="zlib/zcompress.c zlib/zuncompress.c"
USE_LDCONFIG=	yes
USES=		pkgconfig
WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_SUB=	SHLIB_MAJOR_VER=${SHLIB_MAJOR_VER} \
		SHLIB_MINOR_VER=${SHLIB_MINOR_VER}
PORTDOCS=	*

SHLIB_MAJOR_VER=2
SHLIB_MINOR_VER=${PORTVERSION:S/0$//}

do-install:
	cd ${WRKSRC}/ && ${INSTALL_DATA} drvrsmem.h fitsio.h fitsio2.h longnam.h ${STAGEDIR}${PREFIX}/include/
	cd ${WRKSRC}/ && ${INSTALL_LIB} libcfitsio.a libcfitsio.so.${SHLIB_MAJOR_VER}.${SHLIB_MINOR_VER} ${STAGEDIR}${PREFIX}/lib/
	cd ${WRKSRC}/ && ${INSTALL_DATA} cfitsio.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig/
	${LN} -fs libcfitsio.so.${SHLIB_MAJOR_VER}.${SHLIB_MINOR_VER} ${STAGEDIR}${PREFIX}/lib/libcfitsio.so.${SHLIB_MAJOR_VER}
	${LN} -fs libcfitsio.so.${SHLIB_MAJOR_VER} ${STAGEDIR}${PREFIX}/lib/libcfitsio.so
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/docs/*.doc ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
