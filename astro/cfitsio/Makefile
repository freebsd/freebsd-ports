# Created by: Markus Brueffer <markus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cfitsio
PORTVERSION=	3.310
CATEGORIES=	astro
MASTER_SITES=	ftp://heasarc.gsfc.nasa.gov/software/fitsio/c/%SUBDIR%/ \
		http://heasarc.gsfc.nasa.gov/FTP/software/fitsio/c/%SUBDIR%/
MASTER_SITE_SUBDIR=	. oldvers
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for reading and writing files in FITS data format

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/License.txt

LIB_DEPENDS=	f2c:${PORTSDIR}/lang/f2c

OPTIONS_DEFINE=	DOCS

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_PKGCONFIG=	build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	ac_cv_prog_FC="f2c"
ALL_TARGET=	shared
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

.include <bsd.port.options.mk>

post-extract:
	@cd ${WRKSRC} && ${MV} zlib.h zlib.h.dist

post-patch:
	@${GREP} -lR "<malloc.\h>" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|<malloc\.h>|<stdlib.h>|g'
	@${REINPLACE_CMD} -e 's|="\.so"|=".so.0"|g' ${WRKSRC}/configure

do-install:
.for file in drvrsmem.h fitsio.h fitsio2.h longnam.h
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/include
.endfor
.for f in libcfitsio.so.0
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/lib
.endfor
	@${LN} -sf libcfitsio.so.0 ${PREFIX}/lib/libcfitsio.so
.for f in cfitsio.pc
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/libdata/pkgconfig
.endfor
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.doc ${DOCSDIR}
.endif

.include <bsd.port.mk>
