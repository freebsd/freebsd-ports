# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	fcitx-configtool
PORTVERSION=	0.4.5.2
CATEGORIES=	chinese x11
MASTER_SITES=	GOOGLE_CODE
PROJECTHOST=	fcitx
DIST_SUBDIR=	fcitx

MAINTAINER=	lichray@gmail.com
COMMENT=	Fcitx IM framework configuration tool

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes \
		${LOCALBASE}/libdata/pkgconfig/dbus-glib-1.pc:${PORTSDIR}/devel/dbus-glib
LIB_DEPENDS=	libfcitx-config.so:${PORTSDIR}/chinese/fcitx

USE_GNOME=	intltool
USES=		cmake gettext pkgconfig tar:xz

OPTIONS_SINGLE=	UI
UI_DESC=	Gtk version to use
OPTIONS_SINGLE_UI=	GTK2 GTK3
OPTIONS_DEFAULT=GTK2
OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGTK2}
CMAKE_ARGS+=	-DENABLE_GTK2=ON
USE_GNOME+=	gtk20
.endif

.if ${PORT_OPTIONS:MGTK3}
USE_GNOME+=	gtk30
.else
CMAKE_ARGS+=	-DENABLE_GTK3=OFF
.endif

.include <bsd.port.mk>
