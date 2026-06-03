PORTNAME=	gnome-contacts
PORTVERSION=	47.1.1
PORTREVISION=	2
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Contacts manager for gnome
WWW=		https://wiki.gnome.org/Apps/Contacts

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfolks.so:net-im/folks \
		libgee-0.8.so:devel/libgee \
		libgeocode-glib.so:net/geocode-glib \
		libgoa-1.0.so:net/gnome-online-accounts \
		libgstreamer-1.0.so:multimedia/gstreamer1 \
		libportal-gtk4.so:deskutils/libportal-gtk4 \
		libqrencode.so:graphics/libqrencode

USE_GL=		egl
USE_GNOME=	cairo evolutiondataserver3 gdkpixbuf gnomedesktop3 gtk30 \
		intlhack introspection:build libadwaita
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
