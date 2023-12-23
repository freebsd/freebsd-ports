PORTNAME=	libchamplain
PORTVERSION=	0.12.20
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C library aimed to provide a Gtk+ widget to display rasterized maps and markers
WWW=		https://projects.gnome.org/libchamplain/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcogl.so:graphics/cogl \
		libclutter-1.0.so:graphics/clutter \
		libclutter-gtk-1.0.so:graphics/clutter-gtk3 \
		libjson-glib-1.0.so:devel/json-glib \
		libsoup-2.4.so:devel/libsoup

USES=		gettext-runtime gl gnome localbase meson \
		pkgconfig sqlite tar:xz vala:build xorg
USE_GNOME=	cairo gdkpixbuf2 gtk30 introspection:build
USE_GL=		egl
USE_XORG=	x11 xcomposite xdamage xext xfixes xi xrandr
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

PLIST_SUB=	VERSION=0.12

.include <bsd.port.mk>
