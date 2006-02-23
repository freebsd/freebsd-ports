# New ports collection makefile for:	cairomm
# Date created:		2005-12-07
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cairomm
PORTVERSION=	0.4.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://cairographics.org/releases/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ interface to cairo

LIB_DEPENDS=	xml\\+\\+-2.6:${PORTSDIR}/textproc/libxml++26 \
		cairo.2:${PORTSDIR}/graphics/cairo

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
USE_GNOME=	gnomehack gnometarget
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN="Does not build"
.endif

.include <bsd.port.post.mk>
