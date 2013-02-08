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
LIB_DEPENDS=	fcitx-config:${PORTSDIR}/chinese/fcitx

USE_XZ=		yes
USE_GNOME=	intltool gnomehack
USE_GETTEXT=	yes
USE_CMAKE=	yes

OPTIONS_DEFINE=	GTK2 GTK3
OPTIONS_DEFAULT=GTK2

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGTK2}
CMAKE_ARGS+=	-DENABLE_GTK2=ON
USE_GNOME+=	gtk20
PLIST_SUB+=	GTK2=""
.else
PLIST_SUB+=	GTK2="@comment "
.endif

.if ${PORT_OPTIONS:MGTK3}
USE_GNOME+=	gtk30
PLIST_SUB+=	GTK3=""
.else
CMAKE_ARGS+=	-DENABLE_GTK3=OFF
PLIST_SUB+=	GTK3="@comment "
.endif

.if !${PORT_OPTIONS:MGTK2} && !${PORT_OPTIONS:MGTK3}
IGNORE=		a GUI is required
.endif

.include <bsd.port.mk>
