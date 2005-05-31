# New ports collection makefile for:	shapelib for reading ARC Shape Files
# Date created:				23 Apr 2001
# Whom:					Randall Hopper <aa8vb@nc.rr.com>
#
# $FreeBSD$
#

PORTNAME=	shapelib
PORTVERSION=	1.2.10
CATEGORIES=	devel
MASTER_SITES=	http://dl.maptools.org/dl/shapelib/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C API for reading and writing ArcView Shapefiles

WANT_LIBTOOL_VER=15
ALL_TARGET=	lib
INSTALLS_SHLIB=	yes

do-configure:
	@${CP} ${LIBTOOL} ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/.libs/libshp.so.1 ${PREFIX}/lib
	${LN} -sf libshp.so.1 ${PREFIX}/lib/libshp.so
	${INSTALL_DATA} ${WRKSRC}/.libs/libshp.a ${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/shapefil.h ${PREFIX}/include
	${MKDIR} ${PREFIX}/share/doc/shapelib
	${INSTALL_DATA} ${WRKSRC}/*.html ${PREFIX}/share/doc/shapelib

.include <bsd.port.mk>
