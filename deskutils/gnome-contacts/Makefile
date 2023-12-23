PORTNAME=	gnome-contacts
PORTVERSION=	41.0
PORTREVISION=	4
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME/sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+)\..*/\1/}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Contacts manager for gnome
WWW=		https://wiki.gnome.org/Apps/Contacts

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libchamplain-0.12.so:graphics/libchamplain \
		libcheese-gtk.so:multimedia/cheese \
		libclutter-1.0.so:graphics/clutter \
		libclutter-gtk-1.0.so:graphics/clutter-gtk3 \
		libcogl.so:graphics/cogl \
		libdrm.so:graphics/libdrm \
		libexpat.so:textproc/expat2 \
		libfolks.so:net-im/folks \
		libgee-0.8.so:devel/libgee \
		libgeocode-glib.so:net/geocode-glib \
		libgoa-1.0.so:net/gnome-online-accounts \
		libgstreamer-1.0.so:multimedia/gstreamer1 \
		libhandy-1.so:x11-toolkits/libhandy \
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
USES=		compiler:c11 gettext gl gnome localbase meson perl5 pkgconfig \
		python:build sqlite tar:xz vala:build xorg

GLIB_SCHEMAS=	org.gnome.Contacts.gschema.xml

OPTIONS_SUB=		yes
OPTIONS_DEFINE=		MANPAGES
OPTIONS_DEFAULT=	MANPAGES

MANPAGES_MESON_TRUE=	manpage
MANPAGES_USE=		GNOME=libxslt:build
MANPAGES_BUILD_DEPENDS=	docbook-xml>=0:textproc/docbook-xml \
			docbook-xsl-ns>=0:textproc/docbook-xsl-ns \
			docbook-xsl>=0:textproc/docbook-xsl

.include <bsd.port.mk>
