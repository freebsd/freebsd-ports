# $FreeBSD$

PORTNAME=	cairo-dock-plugins
PORTVERSION=	3.4.1
PORTREVISION=	3
CATEGORIES=	deskutils

MAINTAINER=	fidaj@ukr.net
COMMENT=	Cairo-Dock-Plugins for Cairo-Dock

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	wget:ftp/wget
LIB_DEPENDS=	libgldi.so:deskutils/cairo-dock

DATADIR=	${PREFIX}/share/cairo-dock

USE_GITHUB=	yes
GH_ACCOUNT=	Cairo-Dock
GH_PROJECT=	cairo-dock-plug-ins

ICONS_PACKAGE=	cairo-dock-plugins-png-icons
GNU_CONFIGURE=	yes
USE_GNOME=	glib20 gtk30 librsvg2 libxml2
USE_LDCONFIG=	yes
USE_XORG=	xrender
USES=		cmake gettext pkgconfig python
LDFLAGS+=	-L${LOCALBASE}/lib
PLIST_SUB+=	PYVER="${PYTHON_VERSION:S/thon//}"
CMAKE_ARGS+=	-DROOT_PREFIX:PATH=${STAGEDIR}

OPTIONS_DEFINE=
OPTIONS_GROUP=		INTEGR PLUGINS ADDON TPI
OPTIONS_GROUP_INTEGR=	GNOME_INTEGRATION KDE_INTEGRATION XFCE_INTEGRATION
OPTIONS_GROUP_PLUGINS=	ALSA_MIXER GMENU IMPULSE KEYBOARD_INDICATOR \
			MAIL SOUND_EFFECTS WEBLETS XGAMMA ZEITGEIST
OPTIONS_GROUP_ADDON=	EXIF ICAL UPOWER
#OPTIONS_GROUP_TPI=	PYTHON RUBY MONO VALA

OPTIONS_SUB=	yes

OPTIONS_DEFAULT=	GMENU WEBLETS

ALSA_MIXER_DESC=	Alsa-Mixer applet
EXIF_DESC=		Read file meta-data
GMENU_DESC=		GMenu applet
GNOME_INTEGRATION_DESC=	GNOME integration support
ICAL_DESC=		IETF Calendaring and Scheduling protocols
IMPULSE_DESC=		Impulse applet
KDE_INTEGRATION_DESC=	KDE integration support
KEYBOARD_INDICATOR_DESC=	 Keyboard-indicator applet
MAIL_DESC=		Mail applet
#MONO_DESC=		Mono interface
#PYTHON_DESC=		Python interface
#RUBY_DESC=		Ruby interface
SOUND_EFFECTS_DESC=	Sound Effects applet
UPOWER_DESC=		D-Bus daemon for power management tasks
TERMINAL_DESC=		Terminal applet
#VALA_DESC=		Vala interface
WEBLETS_DESC=		Weblets applet
XGAMMA_DESC=		Xgamma applet
XFCE_INTEGRATION_DESC=	XFCE integration support
ZEITGEIST_DESC=		User logs activities

INTEGR_DESC=		Integration plug-ins
PLUGINS_DESC=		Plug-ins
ADDON_DESC=		Add On
#TPI_DESC=		Third Party Interfaces

ALSA_MIXER_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_MIXER_RUN_DEPENDS=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:audio/alsa-plugins
ALSA_MIXER_CMAKE_ON=	-Denable-alsa-mixer:BOOL=TRUE
ALSA_MIXER_CMAKE_OFF=	-Denable-alsa-mixer:BOOL=FALSE

EXIF_LIB_DEPENDS=	libexif.so:graphics/libexif
EXIF_CMAKE_ON=		-Denable-exif-support:BOOL=TRUE
EXIF_CMAKE_OFF=		-Denable-exif-support:BOOL=FALSE

GMENU_LIB_DEPENDS=	libgnome-menu-3.so:x11/gnome-menus
GMENU_CMAKE_ON=		-Denable-gmenu:BOOL=TRUE
GMENU_CMAKE_OFF=	-Denable-gmenu:BOOL=FALSE

#GNOME_INTEGRATION_LIB_DEPENDS=
GNOME_INTEGRATION_CMAKE_ON=	-Denable-gnome-integration:BOOL=TRUE
GNOME_INTEGRATION_CMAKE_OFF=	-Denable-gnome-integration:BOOL=FALSE

ICAL_LIB_DEPENDS=	libical.so:devel/libical
ICAL_CMAKE_ON=		-Denable-ical-support:BOOL=TRUE
ICAL_CMAKE_OFF=		-Denable-ical-support:BOOL=FALSE

IMPULSE_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
IMPULSE_CMAKE_ON=	-Denable-impulse:BOOL=TRUE
IMPULSE_CMAKE_OFF=	-Denable-impulse:BOOL=FALSE

#KDE_INTEGRATION_LIB_DEPENDS=
KDE_INTEGRATION_USE_QT4=	corelib
KDE_INTEGRATION_USE_KDE4=	kdelibs
KDE_INTEGRATION_CMAKE_ON=	-Denable-kde-integration:BOOL=TRUE
KDE_INTEGRATION_CMAKE_OFF=	-Denable-kde-integration:BOOL=FALSE

KEYBOARD_INDICATOR_LIB_DEPENDS=	libexif.so:graphics/libexif \
				libxklavier.so:x11/libxklavier
KEYBOARD_INDICATOR_CMAKE_ON=	-Denable-keyboard-indicator:BOOL=TRUE
KEYBOARD_INDICATOR_CMAKE_OFF=	-Denable-keyboard-indicator:BOOL=FALSE

MAIL_LIB_DEPENDS=	libetpan.so:mail/libetpan
MAIL_CMAKE_ON=		-Denable-mail:BOOL=TRUE
MAIL_CMAKE_OFF=		-Denable-mail:BOOL=FALSE

#MONO_BUILD_DEPENDS=	mono:lang/mono
#MONO_RUN_DEPENDS=	mono:lang/mono
#MONO_CMAKE_ON=		-Denable-mono-interface:BOOL=TRUE
#MONO_CMAKE_OFF=		-Denable-mono-interface:BOOL=FALSE
CMAKE_ARGS+=		-Denable-mono-interface:BOOL=FALSE

#PYTHON_LIB_DEPENDS=
#PYTHON_CMAKE_ON=	-Denable-python-interface:BOOL=TRUE
#PYTHON_CMAKE_OFF=	-Denable-python-interface:BOOL=FALSE
CMAKE_ARGS+=		-Denable-python-interface:BOOL=FALSE

#RUBY_LIB_DEPENDS=
#RUBY_CMAKE_ON=		-Denable-ruby-interface:BOOL=TRUE
#RUBY_CMAKE_OFF=		-Denable-ruby-interface:BOOL=FALSE
CMAKE_ARGS+=		-Denable-ruby-interface:BOOL=FALSE

SOUND_EFFECTS_LIB_DEPENDS=	libasound.so:audio/alsa-lib
SOUND_EFFECTS_RUN_DEPENDS=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:audio/alsa-plugins
SOUND_EFFECTS_CMAKE_ON=		-Denable-sound-effects:BOOL=TRUE
SOUND_EFFECTS_CMAKE_OFF=	-Denable-sound-effects:BOOL=FALSE

# Needs newer vte
#TERMINAL_LIB_DEPENDS=	vte:x11-toolkits/vte
#TERMINAL_CMAKE_ON=	-Denable-terminal:BOOL=TRUE
#TERMINAL_CMAKE_OFF=	-Denable-terminal:BOOL=FALSE

UPOWER_LIB_DEPENDS=	libupower-glib.so:sysutils/upower
UPOWER_CMAKE_ON=	-Denable-upower-support:BOOL=TRUE
UPOWER_CMAKE_OFF=	-Denable-upower-support:BOOL=FALSE

#VALA_LIB_DEPENDS=
#VALA_CMAKE_ON=		-Denable-vala-interface:BOOL=TRUE
#VALA_CMAKE_OFF=		-Denable-vala-interface:BOOL=FALSE
CMAKE_ARGS+=		-Denable-vala-interface:BOOL=FALSE

WEBLETS_LIB_DEPENDS=	libwebkitgtk-3.0.so:www/webkit-gtk3
WEBLETS_CMAKE_ON=	-Denable-weblets:BOOL=TRUE
WEBLETS_CMAKE_OFF=	-Denable-weblets:BOOL=FALSE

XGAMMA_RUN_DEPENDS=	xgamma:x11/xgamma
XGAMMA_CMAKE_ON=	-Denable-xgamma:BOOL=TRUE
XGAMMA_CMAKE_OFF=	-Denable-xgamma:BOOL=FALSE

XFCE_INTEGRATION_LIB_DEPENDS=	libexif.so:graphics/libexif
XFCE_INTEGRATION_CMAKE_ON=	-Denable-xfce-integration:BOOL=TRUE
XFCE_INTEGRATION_CMAKE_OFF=	-Denable-xfce-integration:BOOL=FALSE

ZEITGEIST_LIB_DEPENDS=	libzeitgeist-2.0.so:sysutils/zeitgeist
ZEITGEIST_CMAKE_ON=	-Denable-recent-events:BOOL=TRUE
ZEITGEIST_CMAKE_OFF=	-Denable-recent-events:BOOL=FALSE

post-patch:
	@${FIND} ${WRKSRC} -type f \( -name "*.c" -o -name "*.conf" \
		-o -name netspeed -o -name nvidia-config -o -name "*.sh" \
		-o -name "*.rb" \) | ${XARGS} ${REINPLACE_CMD} -i.orig -e \
	    's|/bin/bash|${LOCALBASE}/bin/bash|g; \
	     s|/usr/bin/python|${PYTHON_CMD}|g; \
	     s|/usr/bin/ruby|${LOCALBASE}/bin/ruby|g; \
	     s|/usr/share/applications|${LOCALBASE}/share/applications|g; \
	     s|/usr/share/cairo-dock|${LOCALBASE}/share/cairo-dock|g'

post-install:
#.if defined(VALA)
#	${MV} ${STAGEDIR}${PREFIX}/lib/pkgconfig/CDApplet.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig/
#.endif
	${RM} -R ${STAGEDIR}${PREFIX}/lib/pkgconfig

.include <bsd.port.mk>
