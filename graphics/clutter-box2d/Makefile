# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	clutter-box2d
PORTVERSION=	0.10.0
PORTREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	http://source.clutter-project.org/sources/${PORTNAME}/0.10/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Clutter Box2D integration library

BROKEN=		No public distfiles
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-11-26

LIB_DEPENDS=	libclutter-glx-1.0.so:${PORTSDIR}/graphics/clutter

USES=		gmake libtool:keepla pathfix pkgconfig
USE_GNOME=	gnomeprefix
USE_GL=		gl
USE_XORG=	xp x11
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-introspection=no
INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
