PORTNAME=	goobox
PORTVERSION=	3.6.0
PORTREVISION=	4
CATEGORIES=	audio gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	CD player and ripper for GNOME Desktop environment

LICENSE=	GPLv2

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libdiscid.so:audio/libdiscid \
		libcoverart.so.0:audio/libcoverart \
		libmusicbrainz5.so:audio/libmusicbrainz5 \
		libbrasero-media3.so:sysutils/brasero \
		libunique-1.0.so:x11-toolkits/unique

USES=		desktop-file-utils gettext gnome gstreamer meson pkgconfig \
		python:build tar:xz xorg
USE_GNOME=	glib20 gtk30 intlhack
USE_XORG=	x11
INSTALL_TARGET=	install-strip
BINARY_ALIAS=	python3=${PYTHON_CMD}

GLIB_SCHEMAS=	org.gnome.Goobox.gschema.xml

OPTIONS_DEFINE=	NOTIFY
OPTIONS_DEFAULT=NOTIFY

NOTIFY_LIB_DEPENDS=	libnotify.so:devel/libnotify
NOTIFY_MESON_TRUE=disable-libnotify

.include <bsd.port.mk>
