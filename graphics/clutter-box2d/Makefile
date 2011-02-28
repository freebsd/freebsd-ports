# New ports collection makefile for:	clutter-box2d
# Date created:		2008-12-25
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	clutter-box2d
PORTVERSION=	0.10.0
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://source.clutter-project.org/sources/${PORTNAME}/0.10/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Clutter Box2D integration library

LIB_DEPENDS=	clutter-glx-1.0:${PORTSDIR}/graphics/clutter

USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	gnomehack ltverhack gnomeprefix
USE_XORG=	xp x11
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-introspection=no
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.mk>
