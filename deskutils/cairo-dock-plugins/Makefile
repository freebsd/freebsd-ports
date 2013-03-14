# Created by: Ivan Klymenko <fidaj@ukr.net>
# $FreeBSD$

PORTNAME=	cairo-dock-plugins
DISTVERSION=	2.3.0~3
PORTREVISION=	5
CATEGORIES=	deskutils
MASTER_SITES=	http://launchpadlibrarian.net/73753265/ \
		http://pazzle.otdux.com.ua/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${ICONS_PACKAGE}${EXTRACT_SUFX}

MAINTAINER=	fidaj@ukr.net
COMMENT=	Cairo-Dock-Plugins for Cairo-Dock

RUN_DEPENDS=	wget:${PORTSDIR}/ftp/wget
LIB_DEPENDS=	etpan:${PORTSDIR}/mail/libetpan \
		gldi.2:${PORTSDIR}/deskutils/cairo-dock

DATADIR=	${PREFIX}/share/cairo-dock

ICONS_PACKAGE=	cairo-dock-plugins-png-icons
GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack pkgconfig glib20 gtk20 librsvg2 libxml2
USE_LDCONFIG=	yes
USE_PYTHON=	yes
USE_XORG=	xrender
USE_DOS2UNIX=	YES
USE_CMAKE=	yes
USE_GCC=	4.6+
MAKE_JOBS_SAFE=	YES
PLIST_SUB+=	PYVER="${PYTHON_VERSION:S/thon//}"



OPTIONS_DEFINE=		GMENU KEYBOARD_INDICATOR TERMINAL WEBLETS \
			XFCE_INTEGRATION ALSA_MIXER
OPTIONS_DEFAULT=	GMENU TERMINAL WEBLETS
GMENU_DESC=		Common Applications menu
KEYBOARD_INDICATOR_DESC=	 Control the keyboard layout
TERMINAL_DESC=		 Add a terminal to your dock
WEBLETS_DESC=		 To show an interactive web page
XFCE_INTEGRATION_DESC=	For XFCE environnement
ALSA_MIXER_DESC=	For ALSA compatibility utils

.include <bsd.port.options.mk>

post-patch:
	@${CP} -R ${WRKDIR}/${ICONS_PACKAGE}/* ${WRKSRC}

.if ${PORT_OPTIONS:MGMENU}
LIB_DEPENDS+=	gnome-menu.2:${PORTSDIR}/x11/gnome-menus
CMAKE_ARGS+=	-Denable_gmenu:STRING=yes
PLIST_SUB+=	GMENU=""
.else
CMAKE_ARGS+=	-Denable_gmenu:STRING=no
PLIST_SUB+=	GMENU="@comment "
.endif

.if ${PORT_OPTIONS:MKEYBOARD_INDICATOR}
LIB_DEPENDS+=	exif.12:${PORTSDIR}/graphics/libexif \
		xklavier.12:${PORTSDIR}/x11/libxklavier
CMAKE_ARGS+=	-Denable_keyboard_indicator:STRING=yes
PLIST_SUB+=	KEYBOARD_INDICATOR=""
.else
CMAKE_ARGS+=	-Denable_keyboard_indicator:STRING=no
PLIST_SUB+=	KEYBOARD_INDICATOR="@comment "
.endif

.if ${PORT_OPTIONS:MTERMINAL}
LIB_DEPENDS+=	vte.9:${PORTSDIR}/x11-toolkits/vte
CMAKE_ARGS+=	-Denable_terminal:STRING=yes
PLIST_SUB+=	TERMINAL=""
.else
CMAKE_ARGS+=	-Denable_terminal:STRING=no
PLIST_SUB+=	TERMINAL="@comment "
.endif

.if ${PORT_OPTIONS:MWEBLETS}
LIB_DEPENDS+=	webkitgtk-1.0.0:${PORTSDIR}/www/webkit-gtk2
CMAKE_ARGS+=	-Denable_weblets:STRING=yes
PLIST_SUB+=	WEBLETS=""
.else
CMAKE_ARGS+=	-Denable_weblets:STRING=no
PLIST_SUB+=	WEBLETS="@comment "
.endif

.if ${PORT_OPTIONS:MXFCE_INTEGRATION}
LIB_DEPENDS+=	thunar-vfs-1.5:${PORTSDIR}/x11-fm/thunar \
		exif.12:${PORTSDIR}/graphics/libexif
CMAKE_ARGS+=	-Denable_xfce_integration:STRING=yes
PLIST_SUB+=	XFCE_INTEGRATION=""
.else
CMAKE_ARGS+=	-Denable_xfce_integration:STRING=no
PLIST_SUB+=	XFCE_INTEGRATION="@comment "
.endif

.if ${PORT_OPTIONS:MALSA_MIXER}
LIB_DEPENDS+=	asound.2:${PORTSDIR}/audio/alsa-lib
RUN_DEPENDS+=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:${PORTSDIR}/audio/alsa-plugins
CMAKE_ARGS+=	-Denable_alsa_mixer:STRING=yes
PLIST_SUB+=	ALSA_MIXER=""
.else
CMAKE_ARGS+=	-Denable_alsa_mixer:STRING=no
PLIST_SUB+=	ALSA_MIXER="@comment "
.endif

.include <bsd.port.mk>
