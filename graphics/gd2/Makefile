# New ports collection makefile for:	gd
# Date created:         27 Mar 1998
# Whom:                 jeff@cetlink.net
#
# $FreeBSD$
#

PORTNAME=	gd
PORTVERSION=	1.8.4
PORTREVISION=	1
CATEGORIES+=	graphics
MASTER_SITES=	http://www.boutell.com/gd/http/ \
		ftp://ftp.boutell.com/pub/boutell/gd/ \
		${MASTER_SITE_RINGSERVER}
MASTER_SITE_SUBDIR=	graphics/gd

MAINTAINER?=	billf@FreeBSD.org

BUILD_DEPENDS=	freetype-config:${PORTSDIR}/print/freetype2	# XXX
LIB_DEPENDS=	png.4:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		freetype.6:${PORTSDIR}/print/freetype2

.if defined(WITH_X11)
USE_XLIB=	yes
USE_XPM=	yes
.endif

INSTALLS_SHLIB=	yes

pre-everything:
.if !defined(WITH_X11)
	@${ECHO_MSG} "If you want to compile in X support use "
	@${ECHO_MSG} "'make -DWITH_X11' instead"
.endif

.include <bsd.port.mk>
