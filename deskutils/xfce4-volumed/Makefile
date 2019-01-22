# Created by: Sergey V. Dyatko <sergey.dyatko@gmail.com>
# $FreeBSD$

PORTNAME=	xfce4-volumed
PORTVERSION=	0.1.13
PORTREVISION=	3
CATEGORIES=	deskutils xfce
MASTER_SITES=	XFCE/src/apps/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	sergey.dyatko@gmail.com
COMMENT=	Volume management daemon for the Xfce desktop

LICENSE=	GPLv3

LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib \
		libdbus-1.so:devel/dbus \
		libnotify.so:devel/libnotify \
		libkeybinder.so:x11/keybinder \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		gmake gnome pkgconfig tar:bzip2 xfce
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk20 libxml2 pango
USE_GSTREAMER=	yes
USE_XFCE=	xfconf

GNU_CONFIGURE=	yes

.include <bsd.port.mk>
