# New ports collection makefile for:	cfitsio
# Date created:				Fri Apr 30 16:49:36 CEST 2004
# Whom:					Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cfitsio
PORTVERSION=	2.490
CATEGORIES=	astro
MASTER_SITES=	ftp://heasarc.gsfc.nasa.gov/software/fitsio/c/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for reading and writing files in FITS data format

WRKSRC=		${WRKDIR}/${PORTNAME}
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

ALL_TARGET=	shared

post-install:
	${MV} ${PREFIX}/lib/libcfitsio.so ${PREFIX}/lib/libcfitsio.so.0
	${LN} -s ${PREFIX}/lib/libcfitsio.so.0 ${PREFIX}/lib/libcfitsio.so
.ifndef(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/*.doc ${DOCSDIR}
.endif

.include <bsd.port.mk>
