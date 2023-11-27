PORTNAME=	cfitsio
PORTVERSION=	4.3.1
CATEGORIES=	astro
MASTER_SITES=	https://heasarc.gsfc.nasa.gov/FTP/software/fitsio/c/ \
		https://heasarc.gsfc.nasa.gov/FTP/software/fitsio/c/oldvers/ \
		ftp://heasarc.gsfc.nasa.gov/software/fitsio/c/ \
		ftp://heasarc.gsfc.nasa.gov/software/fitsio/c/oldvers/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library for reading and writing files in FITS data format
WWW=		https://heasarc.gsfc.nasa.gov/docs/software/fitsio/

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libf2c.so:lang/f2c

USES=		cpe localbase pkgconfig

ALL_TARGET=	libcfitsio.a shared
CONFIGURE_ARGS=	ac_cv_prog_FC=f2c --enable-reentrant --with-bzip2=/usr
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

CPE_VENDOR=	nasa

OPTIONS_DEFINE=	DOCS

do-install:
	cd ${WRKSRC}/ && ${INSTALL_DATA} drvrsmem.h fitsio.h fitsio2.h longnam.h ${STAGEDIR}${PREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/libcfitsio.a ${STAGEDIR}${PREFIX}/lib/
	${INSTALL_LIB} ${WRKSRC}/libcfitsio.so.10.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/cfitsio.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig/
	${LN} -fs libcfitsio.so.10.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libcfitsio.so.10
	${LN} -fs libcfitsio.so.10.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libcfitsio.so

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/docs/*.doc ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
