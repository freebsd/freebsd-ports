# New ports collection makefile for: gd
# Date created:         27 Mar 1998
# Whom:                 jeff@cetlink.net
#
# $FreeBSD$
#

PORTNAME=       gd
PORTVERSION=	1.8.3
CATEGORIES=	graphics
MASTER_SITES=   http://www.boutell.com/gd/http/ \
		ftp://ftp.boutell.com/pub/boutell/gd/

MAINTAINER=	billf@FreeBSD.org

LIB_DEPENDS=	png.3:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg
.if defined(WITH_X11)
LIB_DEPENDS+=	ttf.4:${PORTSDIR}/print/freetype \
		Xpm.4:${PORTSDIR}/graphics/xpm

USE_XLIB=	YES
.endif

pre-fetch:
.if !defined(WITH_X11)
	@${ECHO} -n "If you want to compile in X support use "
	@${ECHO} "'make -DWITH_X11' instead"
.endif

pre-install:
	${MKDIR} ${PREFIX}/include/gd

post-install:
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
