# New ports collection makefile for:	cairo-dock-plugins
# Date created:		2010-03-19
# Whom:			Ivan Klymenko <fidaj@ukr.net>
#
# $FreeBSD$
#

PORTNAME=	cairo-dock-plugins
DISTVERSION=	2.2.0-4
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	http://launchpadlibrarian.net/56955156/

MAINTAINER=	fidaj@ukr.net
COMMENT=	Cairo-Dock-Plugins for Cairo-Dock

RUN_DEPENDS=	wget:${PORTSDIR}/ftp/wget
LIB_DEPENDS=	etpan:${PORTSDIR}/mail/libetpan \
		gldi.2:${PORTSDIR}/deskutils/cairo-dock

DATADIR=	${PREFIX}/share/cairo-dock

GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack pkgconfig glib20 gtk20 librsvg2 libxml2
USE_LDCONFIG=	yes
USE_XORG=	xrender
USE_DOS2UNIX=	YES
USE_CMAKE=	yes
USE_GCC=	4.5+
MAKE_JOBS_SAFE=	YES

OPTIONS=	GMENU "Common Applications menu" On \
		KEYBOARD_INDICATOR "Control the keyboard layout" Off \
		TERMINAL "Add a terminal to your dock" On \
		WEBLETS "To show an interactive web page" On \
		XFCE_INTEGRATION "For XFCE environnement" Off \
		ALSA_MIXER "For ALSA compatibility utils" Off

.include <bsd.port.options.mk>

.if defined(WITH_GMENU)
LIB_DEPENDS+=	gnome-menu.2:${PORTSDIR}/x11/gnome-menus
CMAKE_ARGS+=	-Denable_gmenu:STRING=yes
PLIST_SUB+=	GMENU=""
.else
CMAKE_ARGS+=	-Denable_gmenu:STRING=no
PLIST_SUB+=	GMENU="@comment "
.endif

.if defined(WITH_KEYBOARD_INDICATOR)
LIB_DEPENDS+=	exif.12:${PORTSDIR}/graphics/libexif \
		xklavier.12:${PORTSDIR}/x11/libxklavier
CMAKE_ARGS+=	-Denable_keyboard_indicator:STRING=yes
PLIST_SUB+=	KEYBOARD_INDICATOR=""
.else
CMAKE_ARGS+=	-Denable_keyboard_indicator:STRING=no
PLIST_SUB+=	KEYBOARD_INDICATOR="@comment "
.endif

.if defined(WITH_TERMINAL)
LIB_DEPENDS+=	vte.9:${PORTSDIR}/x11-toolkits/vte
CMAKE_ARGS+=	-Denable_terminal:STRING=yes
PLIST_SUB+=	TERMINAL=""
.else
CMAKE_ARGS+=	-Denable_terminal:STRING=no
PLIST_SUB+=	TERMINAL="@comment "
.endif

.if defined(WITH_WEBLETS)
LIB_DEPENDS+=	webkit-1.0.13:${PORTSDIR}/www/webkit-gtk2
CMAKE_ARGS+=	-Denable_weblets:STRING=yes
PLIST_SUB+=	WEBLETS=""
.else
CMAKE_ARGS+=	-Denable_weblets:STRING=no
PLIST_SUB+=	WEBLETS="@comment "
.endif

.if defined(WITH_XFCE_INTEGRATION)
LIB_DEPENDS+=	thunar-vfs-1.5:${PORTSDIR}/x11-fm/thunar \
		exif.12:${PORTSDIR}/graphics/libexif
CMAKE_ARGS+=	-Denable_xfce_integration:STRING=yes
PLIST_SUB+=	XFCE_INTEGRATION=""
.else
CMAKE_ARGS+=	-Denable_xfce_integration:STRING=no
PLIST_SUB+=	XFCE_INTEGRATION="@comment "
.endif

.if defined(WITH_ALSA_MIXER)
LIB_DEPENDS+=	asound.2:${PORTSDIR}/audio/alsa-lib
CMAKE_ARGS+=	-Denable_alsa_mixer:STRING=yes
PLIST_SUB+=	ALSA_MIXER=""
.else
CMAKE_ARGS+=	-Denable_alsa_mixer:STRING=no
PLIST_SUB+=	ALSA_MIXER="@comment "
.endif

.include <bsd.port.mk>
