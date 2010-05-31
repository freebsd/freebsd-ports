# New ports collection makefile for:	cairo-dock-plugins
# Date created:		2010-03-19
# Whom:			Ivan Klymenko <fidaj@ukr.net>
#
# $FreeBSD$
#

PORTNAME=	cairo-dock-plugins
DISTVERSION=	2.1.0
PORTREVISION=	2
CATEGORIES=	deskutils
MASTER_SITES=	BERLIOS/cairo-dock

MAINTAINER=	fidaj@ukr.net
COMMENT=	Cairo-Dock-Plugins for Cairo-Dock

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/cairo-dock.pc:${PORTSDIR}/deskutils/cairo-dock
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/cairo-dock.pc:${PORTSDIR}/deskutils/cairo-dock

DATADIR=	${PREFIX}/share/cairo-dock

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack pkgconfig glib20 gtk20 librsvg2 libxml2
USE_LDCONFIG=	yes
USE_XORG=	xrender

OPTIONS+=	GMENU "Common Applications menu" On \
		KEYBOARD_INDICATOR "Control the keyboard layout" Off \
		TERMINAL "Add a terminal to your dock" On \
		WEBLETS "To show an interactive web page" On \
		XFCE_INTEGRATION "For XFCE environnement" Off

.include <bsd.port.options.mk>

CONFIGURE_ARGS+=	--disable-alsa-mixer \
			--disable-old-gnome-integration

.if defined(WITH_GMENU)
LIB_DEPENDS+=		gnome-menu.2:${PORTSDIR}/x11/gnome-menus
CONFIGURE_ARGS+=	--enable-gmenu
PLIST_SUB+=	GMENU=""
.else
CONFIGURE_ARGS+=	--disable-gmenu
PLIST_SUB+=	GMENU="@comment "
.endif

.if defined(WITH_KEYBOARD_INDICATOR)
LIB_DEPENDS+=		exif.12:${PORTSDIR}/graphics/libexif \
			xklavier.12:${PORTSDIR}/x11/libxklavier
CONFIGURE_ARGS+=	--enable-keyboard-indicator
PLIST_SUB+=	KEYBOARD_INDICATOR=""
.else
CONFIGURE_ARGS+=	--disable-keyboard-indicator
PLIST_SUB+=	KEYBOARD_INDICATOR="@comment "
.endif

.if defined(WITH_TERMINAL)
LIB_DEPENDS+=		vte.9:${PORTSDIR}/x11-toolkits/vte
CONFIGURE_ARGS+=	--enable-terminal
PLIST_SUB+=	TERMINAL=""
.else
CONFIGURE_ARGS+=	--disable-terminal
PLIST_SUB+=	TERMINAL="@comment "
.endif

.if defined(WITH_WEBLETS)
LIB_DEPENDS+=		webkit-1.0.13:${PORTSDIR}/www/webkit-gtk2
CONFIGURE_ARGS+=	--enable-weblets
PLIST_SUB+=	WEBLETS=""
.else
CONFIGURE_ARGS+=	--disable-weblets
PLIST_SUB+=	WEBLETS="@comment "
.endif

.if defined(WITH_XFCE_INTEGRATION)
LIB_DEPENDS+=		thunar-vfs-1.5:${PORTSDIR}/x11-fm/thunar \
			exif.12:${PORTSDIR}/graphics/libexif
CONFIGURE_ARGS+=	--enable-xfce-integration
PLIST_SUB+=	XFCE_INTEGRATION=""
.else
CONFIGURE_ARGS+=	--disable-xfce-integration
PLIST_SUB+=	XFCE_INTEGRATION="@comment "
.endif

.include <bsd.port.mk>
