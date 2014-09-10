# $FreeBSD$

PORTNAME=	cairo-dock-plugins
DISTVERSION=	3.2.1
PORTREVISION=	5
CATEGORIES=	deskutils
MASTER_SITES=	https://launchpadlibrarian.net/137290159/ \
		http://pazzle.otdux.com.ua/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${ICONS_PACKAGE}${EXTRACT_SUFX}

MAINTAINER=	fidaj@ukr.net
COMMENT=	Cairo-Dock-Plugins for Cairo-Dock

RUN_DEPENDS=	wget:${PORTSDIR}/ftp/wget
LIB_DEPENDS=	libetpan.so:${PORTSDIR}/mail/libetpan \
		libgldi.so:${PORTSDIR}/deskutils/cairo-dock

DATADIR=	${PREFIX}/share/cairo-dock

ICONS_PACKAGE=	cairo-dock-plugins-png-icons
GNU_CONFIGURE=	yes
USE_GNOME=	glib20 gtk20 librsvg2 libxml2
USE_LDCONFIG=	yes
USE_PYTHON=	yes
USE_XORG=	xrender
USES=		cmake gettext pkgconfig
LDFLAGS+=	-L${LOCALBASE}/lib
PLIST_SUB+=	PYVER="${PYTHON_VERSION:S/thon//}"
CMAKE_ARGS+=	-DROOT_PREFIX:PATH=${STAGEDIR}

OPTIONS_DEFINE=		XFCE_INTEGRATION ALSA_MIXER GMENU \
			KEYBOARD_INDICATOR IMPULSE \
			SOUND_EFFECTS WEBLETS
OPTIONS_DEFAULT=	GMENU WEBLETS
XFCE_INTEGRATION_DESC=	XFCE integration support
ALSA_MIXER_DESC=	Alsa-Mixer applet
GMENU_DESC=		GMenu applet
KEYBOARD_INDICATOR_DESC=	 Keyboard-indicator applet
IMPULSE_DESC=		Impulse applet
SOUND_EFFECTS_DESC=	Sound Effects applet
TERMINAL_DESC=		Terminal applet
WEBLETS_DESC=		Weblets applet

OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

post-patch:
	@${CP} -R ${WRKDIR}/${ICONS_PACKAGE}/* ${WRKSRC}
	@${FIND} ${WRKSRC} -type f \( -name "*.c" -o -name "*.conf" \
		-o -name netspeed -o -name nvidia-config -o -name "*.sh" \
		-o -name "*.rb" \) | ${XARGS} ${REINPLACE_CMD} -i.orig -e \
	    's|/bin/bash|${LOCALBASE}/bin/bash|g; \
	     s|/usr/bin/python|${PYTHON_CMD}|g; \
	     s|/usr/bin/ruby|${LOCALBASE}/bin/ruby|g; \
	     s|/usr/share/applications|${LOCALBASE}/share/applications|g; \
	     s|/usr/share/cairo-dock|${LOCALBASE}/share/cairo-dock|g'

.if ${PORT_OPTIONS:MXFCE_INTEGRATION}
LIB_DEPENDS+=	libexif.so:${PORTSDIR}/graphics/libexif
CMAKE_ARGS+=	-Denable-xfce-integration:BOOL=TRUE
.else
CMAKE_ARGS+=	-Denable-xfce-integration:BOOL=FALSE
.endif

.if ${PORT_OPTIONS:MALSA_MIXER}
LIB_DEPENDS+=	libasound.so:${PORTSDIR}/audio/alsa-lib
RUN_DEPENDS+=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:${PORTSDIR}/audio/alsa-plugins
CMAKE_ARGS+=	-Denable-alsa-mixer:BOOL=TRUE
.else
CMAKE_ARGS+=	-Denable-alsa-mixer:BOOL=FALSE
.endif

.if ${PORT_OPTIONS:MGMENU}
LIB_DEPENDS+=	libgnome-menu.so:${PORTSDIR}/x11/gnome-menus
CMAKE_ARGS+=	-Denable-gmenu:BOOL=TRUE
.else
CMAKE_ARGS+=	-Denable-gmenu:BOOL=FALSE
.endif

.if ${PORT_OPTIONS:MKEYBOARD_INDICATOR}
LIB_DEPENDS+=	libexif.so:${PORTSDIR}/graphics/libexif \
		libxklavier.so:${PORTSDIR}/x11/libxklavier
CMAKE_ARGS+=	-Denable-keyboard-indicator:BOOL=TRUE
.else
CMAKE_ARGS+=	-Denable-keyboard-indicator:BOOL=FALSE
.endif

.if ${PORT_OPTIONS:MIMPULSE}
LIB_DEPENDS+=	libpulse.so:${PORTSDIR}/audio/pulseaudio
CMAKE_ARGS+=	-Denable-impulse:BOOL=TRUE
.else
CMAKE_ARGS+=	-Denable-impulse:BOOL=FALSE
.endif

.if ${PORT_OPTIONS:MSOUND_EFFECTS}
LIB_DEPENDS+=	libasound.so:${PORTSDIR}/audio/alsa-lib
RUN_DEPENDS+=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:${PORTSDIR}/audio/alsa-plugins
CMAKE_ARGS+=	-Denable-sound-effects:BOOL=TRUE
.else
CMAKE_ARGS+=	-Denable-sound-effects:BOOL=FALSE
.endif

# Needs newer vte
#.if ${PORT_OPTIONS:MTERMINAL}
#LIB_DEPENDS+=	vte:${PORTSDIR}/x11-toolkits/vte
#CMAKE_ARGS+=	-Denable-terminal:BOOL=TRUE
#.else
#CMAKE_ARGS+=	-Denable-terminal:BOOL=FALSE
#.endif

.if ${PORT_OPTIONS:MWEBLETS}
LIB_DEPENDS+=	libwebkitgtk-1.0.so:${PORTSDIR}/www/webkit-gtk2
CMAKE_ARGS+=	-Denable-weblets:BOOL=TRUE
.else
CMAKE_ARGS+=	-Denable-weblets:BOOL=FALSE
.endif

.include <bsd.port.mk>
