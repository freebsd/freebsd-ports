# New ports collection makefile for:	laszip
# Date created:				09 January 2012
# Whom:					Rainer Hurling <rhurlin@gwdg.de>
# $FreeBSD$

PORTNAME=	laszip
PORTVERSION=	2.1.0
CATEGORIES=	archivers
MASTER_SITES=	http://download.osgeo.org/laszip/

MAINTAINER=	rhurlin@gwdg.de
COMMENT=	A library for lossless LAS compression

LICENSE=	LGPL3

GNU_CONFIGURE=	yes
USE_CMAKE=	yes
USE_LDCONFIG=	yes

CMAKE_DEFS+=	-DCMAKE_USE_PTHREADS:BOOL=ON

post-install:
	@${LN} -s ${PREFIX}/lib/liblaszip.so.5.0.0 ${PREFIX}/lib/liblaszip.so.5

.include <bsd.port.mk>
