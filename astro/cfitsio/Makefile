# Created by: Markus Brueffer <markus@FreeBSD.org>

PORTNAME=	cfitsio
PORTVERSION=	3.490
CATEGORIES=	astro
MASTER_SITES=	https://heasarc.gsfc.nasa.gov/FTP/software/fitsio/c/ \
		https://heasarc.gsfc.nasa.gov/FTP/software/fitsio/c/oldvers/ \
		ftp://heasarc.gsfc.nasa.gov/software/fitsio/c/ \
		ftp://heasarc.gsfc.nasa.gov/software/fitsio/c/oldvers/ \
		LOCAL/sunpoet
DISTNAME=	${PORTNAME}-${PORTVERSION:S|0$||}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library for reading and writing files in FITS data format

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libf2c.so:lang/f2c

USES=		cpe localbase pkgconfig

CPE_VENDOR=	nasa

ALL_TARGET=	libcfitsio.a shared
CONFIGURE_ARGS=	ac_cv_prog_FC=f2c
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

PLIST_SUB=	SHLIB_MAJOR=${SHLIB_MAJOR} \
		SHLIB_MINOR=${SHLIB_MINOR}

SHLIB_MAJOR=	9
SHLIB_MINOR=	${PORTVERSION:S|0$||}

OPTIONS_DEFINE=	DOCS

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
