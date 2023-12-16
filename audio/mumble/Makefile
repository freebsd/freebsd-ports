PORTNAME=	mumble
DISTVERSION=	1.5.517
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	https://github.com/${PORTNAME}-voip/${PORTNAME}/releases/download/v${DISTVERSION}/

PATCH_SITES=	https://github.com/${PORTNAME}-voip/${PORTNAME}/commit/
PATCHFILES=	952dfaf4983097d7b9c9b5d9f5b01ffeb6d3463d.patch:-p1 # Fix detection of unbundled GSL
#PATCHFILES+=	589bfbfd634925b47b3a812745bc5a423b7f4285.patch:-p1 # Install 32-bit lib on FreeBSD

MAINTAINER=	vvd@FreeBSD.org
COMMENT=	Voice chat software primarily intended for use while gaming
WWW=		https://www.mumble.info/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs \
		microsoft-gsl>=3.0.0:devel/microsoft-gsl \
		${LOCALBASE}/include/nlohmann/json.hpp:devel/nlohmann-json
LIB_DEPENDS=	libsndfile.so:audio/libsndfile \
		libopus.so:audio/opus \
		libspeexdsp.so:audio/speexdsp \
		libpcre2-8.so:devel/pcre2 \
		libPocoXML.so:devel/poco \
		libPocoZip.so:devel/poco \
		libprotobuf.so:devel/protobuf \
		libexpat.so:textproc/expat2

USES=		cmake compiler:c++17-lang cpe desktop-file-utils gl \
		pkgconfig python:build qt:5 ssl xorg
USE_CXXSTD=	c++17
USE_GL=		gl
USE_LDCONFIG=	yes
USE_QT=		buildtools:build concurrent core gui l10n linguist:build network \
		qmake:build sql sql-sqlite3:run svg widgets xml
USE_XORG=	x11 xext xi

CMAKE_ON=	client oss overlay plugins translations xinput2
CMAKE_OFF=	bundled-gsl bundled-json bundle-qt-translations bundled-speex \
		crash-report g15 server tracy update

CONFIGURE_ENV=	MUMBLE_PYTHON=${PYTHON_CMD}
CXXFLAGS+=	-Wno-deprecated-declarations

PLIST_SUB=	MUMBLE_VERSION="${DISTVERSION:R}"

OPTIONS_DEFINE=		ALSA AVAHI DBUS JACK LTO PIPEWIRE PORTAUDIO PULSEAUDIO RNNOISE
OPTIONS_DEFINE_amd64=	OVERLAY_32BIT
OPTIONS_DEFAULT=	DBUS
OPTIONS_DEFAULT_amd64=	OVERLAY_32BIT
OPTIONS_RADIO=		SPEECH
OPTIONS_RADIO_SPEECH=	QTSPEECH SPEECHD

OVERLAY_32BIT_DESC=	Build and install 32bit overlay module
QTSPEECH_DESC=		Use Qt's text-to-speech system
RNNOISE_DESC=		Use RNNoise for machine learning noise reduction
SPEECH_DESC=		Support text-to-speech
SPEECHD_DESC=		Support for Speech Dispatcher

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CMAKE_BOOL=	alsa

AVAHI_LIB_DEPENDS=	libdns_sd.so:net/avahi-libdns
AVAHI_CMAKE_BOOL=	zeroconf

DBUS_USE=		QT=dbus
DBUS_CMAKE_BOOL=	dbus

JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CMAKE_BOOL=	jackaudio

LTO_BROKEN=		"QWidget: Cannot create a QWidget without QApplication": \
			https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=273078
LTO_CMAKE_BOOL=		lto

OVERLAY_32BIT_CMAKE_BOOL=	overlay-xcompile

PIPEWIRE_LIB_DEPENDS=	libpipewire-0.3.so:multimedia/pipewire
PIPEWIRE_CMAKE_BOOL=	pipewire

PORTAUDIO_LIB_DEPENDS=	libportaudio.so:audio/portaudio
PORTAUDIO_CMAKE_BOOL=	portaudio

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CMAKE_BOOL=	pulseaudio

QTSPEECH_USE=		QT=speech
QTSPEECH_CMAKE_BOOL=	qtspeech

RNNOISE_LIB_DEPENDS=	librnnoise.so:audio/rnnoise
RNNOISE_CMAKE_BOOL=	rnnoise
RNNOISE_CMAKE_ON=	-Dbundled-rnnoise:BOOL=off

SPEECHD_LIB_DEPENDS=	libspeechd.so:accessibility/speech-dispatcher
SPEECHD_USES=		gettext-runtime gnome
SPEECHD_USE=		GNOME=glib20
SPEECHD_CMAKE_BOOL=	speechd

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOVERLAY_32BIT}
. if ${ARCH} == amd64
PLIST_SUB+=	OVERLAY_32BIT=""
PLIST_SUB+=	OVERLAY_32BIT_SUFFIX=.x86
PLIST_SUB+=	OVERLAY_NATIVE_SUFFIX=.x86_64
. endif
.else
PLIST_SUB+=	OVERLAY_32BIT="@comment "
PLIST_SUB+=	OVERLAY_NATIVE_SUFFIX=""
.endif

.include <bsd.port.mk>
