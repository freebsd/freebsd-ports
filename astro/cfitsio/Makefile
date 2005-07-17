# New ports collection makefile for:	cfitsio
# Date created:				Fri Apr 30 16:49:36 CEST 2004
# Whom:					Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cfitsio
PORTVERSION=	2.510
CATEGORIES=	astro
MASTER_SITES=	ftp://heasarc.gsfc.nasa.gov/software/fitsio/c/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for reading and writing files in FITS data format

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

ALL_TARGET=	stand_alone shared

post-patch:
	@${GREP} -lR "<malloc.\h>" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|<malloc\.h>|<stdlib.h>|g'
	@${REINPLACE_CMD} -e 's|="\.so"|=".so.0"|g' ${WRKSRC}/configure

do-install:
.for file in drvrsmem.h fitsio.h fitsio2.h longnam.h
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/include
.endfor
.for file in libcfitsio.a libcfitsio.so.0
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/lib
.endfor
	@${LN} -sf libcfitsio.so.0 ${PREFIX}/lib/libcfitsio.so
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.doc ${DOCSDIR}
.endif

.include <bsd.port.mk>
