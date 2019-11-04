# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-contacts
PORTVERSION=	3.28.2
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Contacts manager for gnome

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	vala>=0.14.0:lang/vala
LIB_DEPENDS=	libchamplain-0.12.so:graphics/libchamplain \
		libclutter-gtk-1.0.so:graphics/clutter-gtk3 \
		libclutter-1.0.so:graphics/clutter \
		libcogl.so:graphics/cogl \
		libdrm.so:graphics/libdrm \
		libexpat.so:textproc/expat2 \
		libfolks.so:net-im/folks \
		libgee-0.8.so:devel/libgee \
		libgeocode-glib.so:net/geocode-glib \
		libgoa-1.0.so:net/gnome-online-accounts \
		libgstreamer-1.0.so:multimedia/gstreamer1 \
		libjson-glib-1.0.so:devel/json-glib \
		libnotify.so:devel/libnotify \
		libnspr4.so:devel/nspr \
		libsecret-1.so:security/libsecret \
		libsoup-2.4.so:devel/libsoup \
		libtelepathy-glib.so:net-im/telepathy-glib

PORTSCOUT=	limitw:1,even

USE_GL=		egl
USE_GNOME=	cairo evolutiondataserver3 gdkpixbuf2 gnomedesktop3 gtk30 \
		intlhack introspection:build
USE_XORG=	x11 xcomposite xdamage xext xfixes xi xrandr
USES=		gettext gl gnome localbase meson perl5 pkgconfig \
		python:3.4+,build shebangfix sqlite tar:xz xorg
SHEBANG_FILES=	meson_post_install.py

GLIB_SCHEMAS=	org.gnome.Contacts.gschema.xml

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	MANPAGES
OPTIONS_DEFAULT=MANPAGES

OPTIONS_DEFINE_i386=	CHEESE
OPTIONS_DEFINE_amd64=	CHEESE
OPTIONS_DEFAULT_i386=	CHEESE
OPTIONS_DEFAULT_amd64=	CHEESE

MANPAGES_MESON_TRUE=	with-manpage
MANPAGES_USE=		GNOME=libxslt:build
MANPAGES_BUILD_DEPENDS=	docbook-xml>=0:textproc/docbook-xml \
			docbook-xsl>=0:textproc/docbook-xsl

CHEESE_DESC=		Cheese webcam support
CHEESE_MESON_YES=	with-cheese
CHEESE_LIB_DEPENDS=	libcheese-gtk.so:multimedia/cheese

.include <bsd.port.mk>
