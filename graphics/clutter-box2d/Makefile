# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	clutter-box2d
PORTVERSION=	0.10.0
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	http://source.clutter-project.org/sources/${PORTNAME}/0.10/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Clutter Box2D integration library

LIB_DEPENDS=	clutter-glx-1.0:${PORTSDIR}/graphics/clutter

USE_AUTOTOOLS=	libtool
USES=		gmake pathfix pkgconfig
USE_GNOME=	ltverhack gnomeprefix
USE_GL=		gl
USE_XORG=	xp x11
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-introspection=no

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes
.include <bsd.port.mk>
