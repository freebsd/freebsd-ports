# Created by: Martin Wilke <miwi@FreeBSD.org>

PORTNAME=	clutter
PORTVERSION=	1.26.2
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	OpenGL based interactive canvas library

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libcogl.so:graphics/cogl

PORTSCOUT=	limit:1,even

USES=		gettext gl gmake gnome libtool localbase pathfix pkgconfig \
		tar:xz xorg
USE_GNOME=	atk cairo gdkpixbuf2 pango introspection:build
USE_GL=		egl
USE_XORG=	x11 xcomposite xdamage xext xfixes xi xrandr
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-x --enable-conformance=no \
		--disable-evdev-input \
		--enable-egl-backend=yes \
		--enable-x11-backend=yes \
		--enable-gdk-backend=no \
		--enable-wayland-compositor=no
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
