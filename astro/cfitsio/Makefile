# Created by: Markus Brueffer <markus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cfitsio
PORTVERSION=	3.350
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

ALL_TARGET=	shared
CONFIGURE_ARGS=	ac_cv_prog_FC="f2c"
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		pkgconfig
WRKSRC=		${WRKDIR}/${PORTNAME}

PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -e 's|="\.so"|=".so.0"|g' ${WRKSRC}/configure
	@${MV} ${WRKSRC}/zlib.h ${WRKSRC}/zlib.h.dist
	@${GREP} -lR "<malloc.\h>" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e 's|<malloc\.h>|<stdlib.h>|g'

do-install:
	cd ${WRKSRC}/ && ${INSTALL_DATA} drvrsmem.h fitsio.h fitsio2.h longnam.h ${STAGEDIR}${PREFIX}/include/
	cd ${WRKSRC}/ && ${INSTALL_LIB} libcfitsio.so.0 ${STAGEDIR}${PREFIX}/lib/
	cd ${WRKSRC}/ && ${INSTALL_DATA} cfitsio.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig/
	${LN} -fs libcfitsio.so.0 ${STAGEDIR}${PREFIX}/lib/libcfitsio.so
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/*.doc ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
