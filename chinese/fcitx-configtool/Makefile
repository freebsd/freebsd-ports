# New ports collection makefile for:	fcitx-configtool
# Date created:				09 Nov 2011
# Whom:			Zhihao Yuan <lichray@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	fcitx-configtool
PORTVERSION=	0.4.4
CATEGORIES=	chinese x11
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DIST_SUBDIR=	fcitx

MAINTAINER=	lichray@gmail.com
COMMENT=	Fcitx IM framework configure tool

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes \
		${LOCALBASE}/libdata/pkgconfig/dbus-glib-1.pc:${PORTSDIR}/devel/dbus-glib
LIB_DEPENDS=	fcitx-config:${PORTSDIR}/chinese/fcitx

USE_XZ=		yes
USE_GNOME=	intltool gnomehack
USE_GETTEXT=	yes
USE_CMAKE=	yes

OPTIONS=	GTK2		"Enable Gtk2 Version" on \
		GTK3		"Enable Gtk3 Version" off

.include <bsd.port.options.mk>

.if defined(WITH_GTK2)
CMAKE_ARGS+=	-DENABLE_GTK2=ON
USE_GNOME+=	gtk20
PLIST_SUB+=	GTK2=""
.else
PLIST_SUB+=	GTK2="@comment "
.endif

.if defined(WITH_GTK3)
USE_GNOME+=	gtk30
PLIST_SUB+=	GTK3=""
.else
CMAKE_ARGS+=	-DENABLE_GTK3=OFF
PLIST_SUB+=	GTK3="@comment "
.endif

.if defined(WITHOUT_GTK2) && defined(WITHOUT_GTK3)
IGNORE=		a GUI is required
.endif

PROJECTHOST=	fcitx

.include <bsd.port.mk>
