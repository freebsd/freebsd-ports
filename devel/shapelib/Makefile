# New ports collection makefile for:	shapelib for reading ARC Shape Files
# Date created:				23 Apr 2001
# Whom:					Randall Hopper <aa8vb@nc.rr.com>
#
# $FreeBSD$
#

PORTNAME=	shapelib
PORTVERSION=	1.2.10
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://dl.maptools.org/dl/shapelib/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C API for reading and writing ArcView Shapefiles

USE_AUTOTOOLS=	libtool:15:env
ALL_TARGET=	lib
INSTALLS_SHLIB=	yes
INSTALL_TARGET=	lib_install

post-patch:
	@${REINPLACE_CMD} -e 's#%%PREFIX%%#${PREFIX}#g' \
		-e 's#%%LIBTOOL%%#${LIBTOOL}#g' \
		-e 's#%%INSTALL%%#${INSTALL}#g' ${WRKSRC}/Makefile
post-install:
	${MKDIR} ${PREFIX}/share/doc/shapelib
	${INSTALL_DATA} ${WRKSRC}/*.html ${PREFIX}/share/doc/shapelib

.include <bsd.port.mk>
