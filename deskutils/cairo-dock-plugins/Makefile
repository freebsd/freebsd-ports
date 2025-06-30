PORTNAME=	cairo-dock-plugins
DISTVERSION=	3.5.2
PORTREVISION=	1
CATEGORIES=	deskutils

MAINTAINER=	nxjoseph@protonmail.com
COMMENT=	Cairo-Dock-Plugins for Cairo-Dock
WWW=		https://www.glx-dock.org/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libdbusmenu-glib.so:devel/libdbusmenu \
		libdbusmenu-gtk3.so:devel/libdbusmenu \
		libgldi.so:deskutils/cairo-dock \
		libharfbuzz.so:print/harfbuzz \
		libwayland-client.so:graphics/wayland
RUN_DEPENDS=	wget:ftp/wget

USES=		cmake gettext-tools gl gnome localbase:ldflags pkgconfig python \
		ssl xorg
USE_GITHUB=	yes
GH_ACCOUNT=	Cairo-Dock
GH_PROJECT=	cairo-dock-plug-ins
USE_GL=		gl glu opengl
USE_GNOME=	cairo glib20 gtk30 librsvg2 libxml2 vte3
USE_XORG=	x11 xcomposite xrandr xrender xtst

CMAKE_ARGS=	-Denable-mono-interface:BOOL=FALSE \
		-Denable-python-interface:BOOL=FALSE \
		-Denable-ruby-interface:BOOL=FALSE \
		-Denable-vala-interface:BOOL=FALSE \
		-Denable-weblets:BOOL=FALSE \
		-DROOT_PREFIX:PATH=${STAGEDIR}

DATADIR=	${PREFIX}/share/cairo-dock

OPTIONS_DEFAULT=	GMENU
OPTIONS_GROUP=		ADDON INTEGR PLUGINS
OPTIONS_GROUP_ADDON=	EXIF ICAL UPOWER
OPTIONS_GROUP_INTEGR=	GNOME_INTEGRATION XFCE_INTEGRATION
OPTIONS_GROUP_PLUGINS=	ALSA_MIXER GMENU IMPULSE KEYBOARD_INDICATOR MAIL \
			SOUND_EFFECTS XGAMMA ZEITGEIST
OPTIONS_SUB=		yes

ADDON_DESC=			Add On
ALSA_MIXER_DESC=		Alsa-Mixer applet
EXIF_DESC=			Read file meta-data
GMENU_DESC=			GMenu applet
GNOME_INTEGRATION_DESC=		GNOME integration support
ICAL_DESC=			IETF Calendaring and Scheduling protocols
IMPULSE_DESC=			Impulse applet
INTEGR_DESC=			Integration plug-ins
KEYBOARD_INDICATOR_DESC=	Keyboard-indicator applet
MAIL_DESC=			Mail applet
PLUGINS_DESC=			Plug-ins
SOUND_EFFECTS_DESC=		Sound Effects applet
UPOWER_DESC=			D-Bus daemon for power management tasks
XFCE_INTEGRATION_DESC=		XFCE integration support
XGAMMA_DESC=			Xgamma applet
ZEITGEIST_DESC=			User logs activities

ALSA_MIXER_LIB_DEPENDS=		libasound.so:audio/alsa-lib
ALSA_MIXER_RUN_DEPENDS=		${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:audio/alsa-plugins
ALSA_MIXER_CMAKE_BOOL=		enable-alsa-mixer
EXIF_LIB_DEPENDS=		libexif.so:graphics/libexif
EXIF_CMAKE_BOOL=		enable-exif-support
GMENU_LIB_DEPENDS=		libgnome-menu-3.so:x11/gnome-menus
GMENU_CMAKE_BOOL=		enable-gmenu
GNOME_INTEGRATION_CMAKE_BOOL=	enable-gnome-integration
ICAL_LIB_DEPENDS=		libical.so:devel/libical
ICAL_CMAKE_BOOL=		enable-ical-support
IMPULSE_LIB_DEPENDS=		libfftw3.so:math/fftw3 \
				libpulse.so:audio/pulseaudio
IMPULSE_CMAKE_BOOL=		enable-impulse
KEYBOARD_INDICATOR_LIB_DEPENDS=	libexif.so:graphics/libexif \
				libxklavier.so:x11/libxklavier
KEYBOARD_INDICATOR_CMAKE_BOOL=	enable-keyboard-indicator
MAIL_BUILD_DEPENDS=		libetpan>=1.9.4:mail/libetpan
MAIL_LIB_DEPENDS=		libetpan.so:mail/libetpan
MAIL_CMAKE_BOOL=		enable-mail
SOUND_EFFECTS_LIB_DEPENDS=	libasound.so:audio/alsa-lib
SOUND_EFFECTS_RUN_DEPENDS=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:audio/alsa-plugins
SOUND_EFFECTS_CMAKE_BOOL=	enable-sound-effects
UPOWER_LIB_DEPENDS=		libpolkit-gobject-1.so:sysutils/polkit \
				libupower-glib.so:sysutils/upower
UPOWER_CMAKE_BOOL=		enable-upower-support
XFCE_INTEGRATION_LIB_DEPENDS=	libexif.so:graphics/libexif
XFCE_INTEGRATION_CMAKE_BOOL=	enable-xfce-integration
XGAMMA_LIB_DEPENDS=		libXxf86vm.so:x11/libXxf86vm
XGAMMA_RUN_DEPENDS=		xgamma:x11/xgamma
XGAMMA_CMAKE_BOOL=		enable-xgamma
ZEITGEIST_LIB_DEPENDS=		libzeitgeist-2.0.so:sysutils/zeitgeist
ZEITGEIST_CMAKE_BOOL=		enable-recent-events

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=int-conversion
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/env python3|${PYTHON_CMD}|g' \
		${WRKSRC}/Dbus/data/cairo-dock-launcher-API-daemon.py
	@${FIND} ${WRKSRC} -type f \( -name "*.c" -o -name "*.conf" -o -name netspeed \
		-o -name nvidia-config -o -name "*.sh" -o -name "*.rb" \) | \
		${XARGS} ${REINPLACE_CMD} -i.orig -e 's|/bin/bash|${LOCALBASE}/bin/bash|g; s|/usr/bin/python|${PYTHON_CMD}|g; s|/usr/bin/ruby|${LOCALBASE}/bin/ruby|g; s|/usr/share/applications|${LOCALBASE}/share/applications|g; s|/usr/share/cairo-dock|${LOCALBASE}/share/cairo-dock|g'

.include <bsd.port.mk>
