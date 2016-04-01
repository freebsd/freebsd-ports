# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	fcitx-configtool
PORTVERSION=	0.4.8
CATEGORIES=	chinese x11
MASTER_SITES=	http://download.fcitx-im.org/${PORTNAME}/
DIST_SUBDIR=	fcitx

MAINTAINER=	lichray@gmail.com
COMMENT=	Fcitx IM framework configuration tool

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:misc/iso-codes \
		${LOCALBASE}/libdata/pkgconfig/dbus-glib-1.pc:devel/dbus-glib
LIB_DEPENDS=	libfcitx-config.so:chinese/fcitx

USE_GNOME=	intltool
USES=		cmake gettext pkgconfig tar:xz
LDFLAGS+=	-lintl

OPTIONS_SINGLE=	UI
UI_DESC=	Gtk version to use
OPTIONS_SINGLE_UI=	GTK2 GTK3
OPTIONS_DEFAULT=GTK2
OPTIONS_SUB=	yes

GTK2_CMAKE_ON=	-DENABLE_GTK2=ON
GTK2_USE=	GNOME=gtk20

GTK3_USE=	GNOME=gtk30
GTK3_CMAKE_OFF=	-DENABLE_GTK3=OFF

.include <bsd.port.mk>
