# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$
#  $MCom: ports/trunk/graphics/cogl/Makefile 20024 2014-10-27 12:59:06Z gusi $

PORTNAME=	cogl
PORTVERSION=	1.20.0
CATEGORIES=	graphics
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Clutter OpenGL abstraction library

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS=	clutter-1.6.[0-9]*

USES=		gettext gmake libtool pathfix pkgconfig tar:xz
GNU_CONFIGURE=	yes
USE_GNOME=	gdkpixbuf2 gnomeprefix atk pango introspection:build
USE_GL=		gl egl
USE_XORG=	x11 xfixes xdamage xcomposite xi xrandr
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-x \
		 --enable-xlib-egl-platform=yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

PLIST_SUB=	LIBVER=20 LIBVERSION=20.3.0

.include <bsd.port.mk>
