# New ports collection makefile for:	xsvg
# Date created:		2005-02-16
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xsvg
PORTVERSION=	0.2.0
CATEGORIES=	graphics
MASTER_SITES=	http://cairographics.org/snapshots/

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	X11 SVG viewer

LIB_DEPENDS=	svg-cairo.1:${PORTSDIR}/graphics/libsvg-cairo

GNU_CONFIGURE=	yes
USE_GETOPT_LONG=yes
USE_XLIB=	yes

PLIST_FILES=	bin/xsvg

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=	Does not build
.endif

.include <bsd.port.post.mk>
