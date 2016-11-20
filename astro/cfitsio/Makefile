# Created by: Markus Brueffer <markus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cfitsio
PORTVERSION=	3.390
CATEGORIES=	astro
MASTER_SITES=	http://heasarc.gsfc.nasa.gov/FTP/software/fitsio/c/ \
		http://heasarc.gsfc.nasa.gov/FTP/software/fitsio/c/oldvers/ \
		ftp://heasarc.gsfc.nasa.gov/software/fitsio/c/ \
		ftp://heasarc.gsfc.nasa.gov/software/fitsio/c/oldvers/ \
		LOCAL/sunpoet
DISTNAME=	${PORTNAME}${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library for reading and writing files in FITS data format

LIB_DEPENDS=	libf2c.so:lang/f2c

OPTIONS_DEFINE=	DOCS

ALL_TARGET=	libcfitsio.a shared
CONFIGURE_ARGS=	ac_cv_prog_FC=f2c
GNU_CONFIGURE=	yes
MAKE_ARGS=	ZLIB_SOURCES="zlib/zcompress.c zlib/zuncompress.c"
USE_LDCONFIG=	yes
USES=		localbase pkgconfig
WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_SUB=	SHLIB_MAJOR=${SHLIB_MAJOR} \
		SHLIB_MINOR=${SHLIB_MINOR}
PORTDOCS=	*

SHLIB_MAJOR=	5
SHLIB_MINOR=	${PORTVERSION:S|0$||}

post-patch:
	@${REINPLACE_CMD} -e 's|<malloc.h>|<stdlib.h>|' ${WRKSRC}/*.[chl] ${WRKSRC}/zlib/*.h

do-install:
	cd ${WRKSRC}/ && ${INSTALL_DATA} drvrsmem.h fitsio.h fitsio2.h longnam.h ${STAGEDIR}${PREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/libcfitsio.a ${STAGEDIR}${PREFIX}/lib/
	${INSTALL_LIB} ${WRKSRC}/libcfitsio.so.${SHLIB_MAJOR}.${SHLIB_MINOR} ${STAGEDIR}${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/cfitsio.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig/
	${LN} -fs libcfitsio.so.${SHLIB_MAJOR}.${SHLIB_MINOR} ${STAGEDIR}${PREFIX}/lib/libcfitsio.so.${SHLIB_MAJOR}
	${LN} -fs libcfitsio.so.${SHLIB_MAJOR}.${SHLIB_MINOR} ${STAGEDIR}${PREFIX}/lib/libcfitsio.so

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/docs/*.doc ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
