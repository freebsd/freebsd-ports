# Created by: Martin Wilke <miwi@FreeBSD.org>

PORTNAME=	cogl
PORTVERSION=	1.22.8
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Clutter OpenGL abstraction library

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS=	clutter-1.6.[0-9]*

USES=		gettext gl gmake gnome libtool localbase pathfix pkgconfig \
		tar:xz xorg
GNU_CONFIGURE=	yes
USE_GNOME=	cairo gdkpixbuf2 pango introspection:build
USE_GL=		egl gbm
USE_XORG=	x11 xcomposite xext xdamage xfixes xrandr
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-x \
		 --enable-xlib-egl-platform=yes
INSTALL_TARGET=	install-strip

PLIST_SUB=	LIBVER=20 LIBVERSION=20.4.3

.include <bsd.port.mk>
