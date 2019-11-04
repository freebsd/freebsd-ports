# Created by: Alexander Nedotsukov <bland@FreeBSD.org>
# $FreeBSD$

PORTNAME=	goobox
PORTVERSION=	3.4.2
CATEGORIES=	audio gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	CD player and ripper for GNOME Desktop environment

LICENSE=	GPLv2

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libdiscid.so:audio/libdiscid \
		libcoverart.so.0:audio/libcoverart \
		libmusicbrainz5.so:audio/libmusicbrainz5 \
		libbrasero-media3.so:sysutils/brasero \
		libunique-1.0.so:x11-toolkits/unique

USES=		desktop-file-utils gettext gmake gnome localbase pkgconfig \
		tar:xz xorg
USE_GNOME=	glib20 gtk30 intlhack
USE_XORG=	x11
USE_GSTREAMER1=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.Goobox.gschema.xml

OPTIONS_DEFINE=	NOTIFY
OPTIONS_DEFAULT=NOTIFY

NOTIFY_LIB_DEPENDS=	libnotify.so:devel/libnotify
NOTIFY_CONFIGURE_ENABLE=notification

.include <bsd.port.mk>
