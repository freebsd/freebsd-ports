PORTNAME=	mumble
DISTVERSION=	1.5.517
PORTREVISION=	1
CATEGORIES=	audio

MAINTAINER=	vvd@FreeBSD.org
COMMENT=	Voice chat software primarily intended for use while gaming
WWW=		https://www.mumble.info/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs \
		${LOCALBASE}/include/nlohmann/json.hpp:devel/nlohmann-json
LIB_DEPENDS=	libsndfile.so:audio/libsndfile \
		libopus.so:audio/opus \
		libspeexdsp.so:audio/speexdsp \
		libpcre2-8.so:devel/pcre2 \
		libPocoXML.so:devel/poco \
		libPocoZip.so:devel/poco \
		libprotobuf.so:devel/protobuf \
		libexpat.so:textproc/expat2

USES=		cmake compiler:c++14-lang cpe desktop-file-utils gl \
		pkgconfig python:build qmake qt:5 ssl xorg

PATCHVERSION=	${DISTVERSION}
MINORVERSION=	${DISTVERSION:R}
MAJORVERSION=	${DISTVERSION:R:R}

PLIST_SUB+=	PATCHVERSION="${PATCHVERSION}"
PLIST_SUB+=	MINORVERSION="${MINORVERSION}"
PLIST_SUB+=	MAJORVERSION="${MAJORVERSION}"

USE_CXXSTD=	c++14
USE_GITHUB=	yes
GH_TUPLE=	mumble-voip:mumble:v${DISTVERSION} \
		Krzmbrzl:FindPythonInterpreter:bb4d3ea:mumble_FindPythonInterpreter/3rdparty/FindPythonInterpreter \
		microsoft:GSL:0f6dbc9:mumble_gsl/3rdparty/gsl \
		mumble-voip:mach_override:919148f:mumble_mach_override/3rdparty/mach-override-src \
		mumble-voip:minhook:5e338f8:mumble_minhook/3rdparty/minhook \
		mumble-voip:speexdsp:6e4634f:mumble_speexdsp/3rdparty/speexdsp \
		wolfpld:tracy:1a4f369:mumble_tracy/3rdparty/tracy

USE_QT=		buildtools:build concurrent core gui l10n linguist:build network \
		sql sql-sqlite3:run svg widgets xml
USE_LDCONFIG=	yes

USE_XORG=	x11 xext xi
USE_GL=		gl

CMAKE_ON=	bundled-gsl client oss overlay overlay-xcompile plugins \
		translations xinput2
CMAKE_OFF=	bundled-json bundle-qt-translations bundled-speex crash-report \
		g15 server tracy update

OPTIONS_DEFINE=		ALSA AVAHI DBUS JACK LTO PIPEWIRE PORTAUDIO PULSEAUDIO RNNOISE
OPTIONS_DEFAULT=	DBUS LTO
OPTIONS_RADIO=		SPEECH
OPTIONS_RADIO_SPEECH=	QTSPEECH SPEECHD

QTSPEECH_DESC=		Use Qt's text-to-speech system
RNNOISE_DESC=		Use RNNoise for machine learning noise reduction
SPEECH_DESC=		Support text-to-speech
SPEECHD_DESC=		Support for Speech Dispatcher

ALSA_CMAKE_BOOL=	alsa
ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib

AVAHI_CMAKE_BOOL=	zeroconf
AVAHI_LIB_DEPENDS=	libdns_sd.so:net/avahi-libdns

DBUS_USES=		qt:5
DBUS_USE=		QT=dbus
DBUS_CMAKE_BOOL=	dbus

JACK_CMAKE_BOOL=	jackaudio
JACK_LIB_DEPENDS=	libjack.so:audio/jack

LTO_CMAKE_BOOL=		lto

PIPEWIRE_CMAKE_BOOL=	pipewire
PIPEWIRE_LIB_DEPENDS=	libpipewire-0.3.so:multimedia/pipewire

PORTAUDIO_CMAKE_BOOL=	portaudio
PORTAUDIO_LIB_DEPENDS=	libportaudio.so:audio/portaudio

PULSEAUDIO_CMAKE_BOOL=	pulseaudio
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio

QTSPEECH_USES=		qt:5
QTSPEECH_USE=		QT=speech
QTSPEECH_CMAKE_BOOL=	qtspeech

RNNOISE_CMAKE_BOOL=	rnnoise
RNNOISE_CMAKE_ON=	-Dbundled-rnnoise:BOOL=off
RNNOISE_LIB_DEPENDS=	librnnoise.so:audio/rnnoise

SPEECHD_USES=		gettext-runtime gnome
SPEECHD_USE=		GNOME=glib20
SPEECHD_CMAKE_BOOL=	speechd
SPEECHD_LIB_DEPENDS=	libspeechd.so:accessibility/speech-dispatcher

CONFIGURE_ENV+=		MUMBLE_PYTHON=${PYTHON_CMD}

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.build/mumble ${STAGEDIR}${PREFIX}/bin
	${INSTALL_LIB} ${WRKDIR}/.build/libmumbleoverlay.x86_64.so.${MINORVERSION}.0 \
		${STAGEDIR}${PREFIX}/lib/libmumbleoverlay.x86_64.so.${PATCHVERSION}
	${RLN} ${STAGEDIR}${PREFIX}/lib/libmumbleoverlay.x86_64.so.${PATCHVERSION} \
		${STAGEDIR}${PREFIX}/lib/libmumbleoverlay.x86_64.so
	${RLN} ${STAGEDIR}${PREFIX}/lib/libmumbleoverlay.x86_64.so.${PATCHVERSION} \
		${STAGEDIR}${PREFIX}/lib/libmumbleoverlay.x86_64.so.${MAJORVERSION}
	${RLN} ${STAGEDIR}${PREFIX}/lib/libmumbleoverlay.x86_64.so.${PATCHVERSION} \
		${STAGEDIR}${PREFIX}/lib/libmumbleoverlay.x86_64.so.${MINORVERSION}
	${INSTALL_LIB} ${WRKDIR}/.build/libmumbleoverlay.x86.so.${MINORVERSION}.0 \
		${STAGEDIR}${PREFIX}/lib/libmumbleoverlay.x86.so.${PATCHVERSION}
	${RLN} ${STAGEDIR}${PREFIX}/lib/libmumbleoverlay.x86.so.${PATCHVERSION} \
		${STAGEDIR}${PREFIX}/lib/libmumbleoverlay.x86.so
	${RLN} ${STAGEDIR}${PREFIX}/lib/libmumbleoverlay.x86.so.${PATCHVERSION} \
		${STAGEDIR}${PREFIX}/lib/libmumbleoverlay.x86.so.${MAJORVERSION}
	${RLN} ${STAGEDIR}${PREFIX}/lib/libmumbleoverlay.x86.so.${PATCHVERSION} \
		${STAGEDIR}${PREFIX}/lib/libmumbleoverlay.x86.so.${MINORVERSION}
	${INSTALL_DATA} ${WRKDIR}/.build/auxiliary_files/info.mumble.Mumble.desktop \
			${STAGEDIR}${PREFIX}/share/applications/mumble.desktop
	${INSTALL_DATA} ${WRKSRC}/icons/mumble.xpm ${STAGEDIR}${PREFIX}/share/pixmaps
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/256x256/apps \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/icons/mumble.svg \
			${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/icons/mumble_256x256.png \
			${STAGEDIR}${PREFIX}/share/icons/hicolor/256x256/apps/mumble.png
	${INSTALL_MAN} ${WRKSRC}/auxiliary_files/man_files/mumble.1 \
			${STAGEDIR}${MANPREFIX}/share/man/man1/mumble.1

.include <bsd.port.post.mk>
