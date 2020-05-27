# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ario
PORTVERSION=	1.6
CATEGORIES=	audio
MASTER_SITES=	SF/ario-player/ario-player/${PORTVERSION}

MAINTAINER=	alfix86@gmail.com
COMMENT=	GTK client for MPD

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	intltoolize:textproc/intltool
LIB_DEPENDS=	libcurl.so:ftp/curl

GNU_CONFIGURE=	yes
USES=		gmake gnome libtool pkgconfig
USE_LDCONFIG=	yes
USE_GNOME=	gtk30 pango atk cairo gdkpixbuf2 glib20 libxml2
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	AVAHI DBUS DEBUG LIBMPDCLIENT2 MPDIDLE NLS PLAYLISTS SEARCH TAGLIB

OPTIONS_SUB=	yes

LIBMPDCLIENT2_DESC=	API library for interfacing MPD
MPDIDLE_DESC=	MPD idle mode support
PLAYLISTS_DESC=	Playlists support
SEARCH_DESC=	Search view support
TAGLIB_DESC=	Manage ID3 tags and Ogg comments

OPTIONS_DEFAULT=	DBUS LIBMPDCLIENT2 MPDIDLE PLAYLISTS SEARCH TAGLIB

AVAHI_LIB_DEPENDS=	libavahi-client.so:net/avahi-app
AVAHI_CONFIGURE_ENABLE=	avahi

DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus libdbus-glib-1.so:devel/dbus-glib
DBUS_CONFIGURE_ENABLE=	dbus

DEBUG_CONFIGURE_ENABLE=	debug

LIBMPDCLIENT2_LIB_DEPENDS=	libmpdclient.so:audio/libmpdclient
LIBMPDCLIENT2_CONFIGURE_ENABLE=	libmpdclient2

MPDIDLE_CONFIGURE_ENABLE=	mpdidle

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

PLAYLISTS_CONFIGURE_ENABLE=	playlists

SEARCH_CONFIGURE_ENABLE=	search

TAGLIB_LIB_DEPENDS=		libtag_c.so:audio/taglib libtag.so:audio/taglib
TAGLIB_CONFIGURE_ENABLE=	taglib

.include <bsd.port.mk>
