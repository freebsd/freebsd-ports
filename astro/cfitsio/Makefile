# New ports collection makefile for:	cfitsio
# Date created:				Fri Apr 30 16:49:36 CEST 2004
# Whom:					Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cfitsio
PORTVERSION=	3.090
CATEGORIES=	astro
MASTER_SITES=	ftp://heasarc.gsfc.nasa.gov/software/fitsio/c/ \
		ftp://heasarc.gsfc.nasa.gov/software/fitsio/c/oldvers/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for reading and writing files in FITS data format

LIB_DEPENDS=	f2c.2:${PORTSDIR}/lang/f2c

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_GNOME=	gnometarget pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	ac_cv_prog_FC="f2c"
ALL_TARGET=	shared
USE_LDCONFIG=	yes

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
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.doc ${DOCSDIR}
.endif

.include <bsd.port.mk>
