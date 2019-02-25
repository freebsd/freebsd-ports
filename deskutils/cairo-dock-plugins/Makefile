# $FreeBSD$

PORTNAME=	cairo-dock-plugins
PORTVERSION=	3.4.1
PORTREVISION=	7
CATEGORIES=	deskutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cairo-Dock-Plugins for Cairo-Dock

LICENSE=	GPLv3+
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
PLIST_SUB=	PYVER="${PYTHON_VERSION:S/thon//}"
CMAKE_ARGS=	-DROOT_PREFIX:PATH=${STAGEDIR} \
		-Denable-weblets:BOOL=FALSE

OPTIONS_GROUP=		INTEGR PLUGINS ADDON TPI
OPTIONS_GROUP_INTEGR=	GNOME_INTEGRATION XFCE_INTEGRATION
OPTIONS_GROUP_PLUGINS=	ALSA_MIXER GMENU IMPULSE KEYBOARD_INDICATOR \
			MAIL SOUND_EFFECTS XGAMMA ZEITGEIST
OPTIONS_GROUP_ADDON=	EXIF ICAL UPOWER
#OPTIONS_GROUP_TPI=	PYTHON RUBY MONO VALA

OPTIONS_SUB=		yes

OPTIONS_DEFAULT=	GMENU

ALSA_MIXER_DESC=	Alsa-Mixer applet
EXIF_DESC=		Read file meta-data
GMENU_DESC=		GMenu applet
GNOME_INTEGRATION_DESC=	GNOME integration support
ICAL_DESC=		IETF Calendaring and Scheduling protocols
IMPULSE_DESC=		Impulse applet
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
ALSA_MIXER_CMAKE_BOOL=	enable-alsa-mixer

EXIF_LIB_DEPENDS=	libexif.so:graphics/libexif
EXIF_CMAKE_BOOL=	enable-exif-support

GMENU_LIB_DEPENDS=	libgnome-menu-3.so:x11/gnome-menus
GMENU_CMAKE_BOOL=	enable-gmenu

#GNOME_INTEGRATION_LIB_DEPENDS=
GNOME_INTEGRATION_CMAKE_BOOL=	enable-gnome-integration

ICAL_LIB_DEPENDS=	libical.so:devel/libical
ICAL_CMAKE_BOOL=	enable-ical-support

IMPULSE_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
IMPULSE_CMAKE_BOOL=	enable-impulse

KEYBOARD_INDICATOR_LIB_DEPENDS=	libexif.so:graphics/libexif \
				libxklavier.so:x11/libxklavier
KEYBOARD_INDICATOR_CMAKE_BOOL=	enable-keyboard-indicator

MAIL_LIB_DEPENDS=	libetpan.so:mail/libetpan
MAIL_CMAKE_BOOL=	enable-mail

#MONO_BUILD_DEPENDS=	mono:lang/mono
#MONO_RUN_DEPENDS=	mono:lang/mono
#MONO_CMAKE_BOOL=	enable-mono-interface
CMAKE_ARGS+=		-Denable-mono-interface:BOOL=FALSE

#PYTHON_LIB_DEPENDS=
#PYTHON_CMAKE_BOOL=	enable-python-interface
CMAKE_ARGS+=		-Denable-python-interface:BOOL=FALSE

#RUBY_LIB_DEPENDS=
#RUBY_CMAKE_BOOL=	enable-ruby-interface
CMAKE_ARGS+=		-Denable-ruby-interface:BOOL=FALSE

SOUND_EFFECTS_LIB_DEPENDS=	libasound.so:audio/alsa-lib
SOUND_EFFECTS_RUN_DEPENDS=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:audio/alsa-plugins
SOUND_EFFECTS_CMAKE_BOOL=	enable-sound-effects

# Needs newer vte
#TERMINAL_LIB_DEPENDS=	vte:x11-toolkits/vte
#TERMINAL_CMAKE_BOOL=	enable-terminal

UPOWER_LIB_DEPENDS=	libupower-glib.so:sysutils/upower
UPOWER_CMAKE_BOOL=	enable-upower-support

#VALA_LIB_DEPENDS=
#VALA_CMAKE_BOOL=	enable-vala-interface
CMAKE_ARGS+=		-Denable-vala-interface:BOOL=FALSE

XGAMMA_RUN_DEPENDS=	xgamma:x11/xgamma
XGAMMA_CMAKE_BOOL=	enable-xgamma

XFCE_INTEGRATION_LIB_DEPENDS=	libexif.so:graphics/libexif
XFCE_INTEGRATION_CMAKE_BOOL=	enable-xfce-integration

ZEITGEIST_LIB_DEPENDS=	libzeitgeist-2.0.so:sysutils/zeitgeist
ZEITGEIST_CMAKE_BOOL=	enable-recent-events

.include <bsd.port.options.mk>

post-patch:
	@${FIND} ${WRKSRC} -type f \( -name "*.c" -o -name "*.conf" \
		-o -name netspeed -o -name nvidia-config -o -name "*.sh" \
		-o -name "*.rb" \) | ${XARGS} ${REINPLACE_CMD} -i.orig -e \
	    's|/bin/bash|${LOCALBASE}/bin/bash|g; \
	     s|/usr/bin/python|${PYTHON_CMD}|g; \
	     s|/usr/bin/ruby|${LOCALBASE}/bin/ruby|g; \
	     s|/usr/share/applications|${LOCALBASE}/share/applications|g; \
	     s|/usr/share/cairo-dock|${LOCALBASE}/share/cairo-dock|g'

#post-install:
#.if defined(VALA)
#	${MV} ${STAGEDIR}${PREFIX}/lib/pkgconfig/CDApplet.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig/
#.endif

.include <bsd.port.mk>
