PORTNAME=	mumble
DISTVERSION=	1.5.634
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	https://github.com/${PORTNAME}-voip/${PORTNAME}/releases/download/v${DISTVERSION}/

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
		libabsl_base.so:devel/abseil \
		libpcre2-8.so:devel/pcre2 \
		libPocoXML.so:devel/poco \
		libPocoZip.so:devel/poco \
		libprotobuf.so:devel/protobuf \
		libexpat.so:textproc/expat2

USES=		cmake compiler:c++17-lang cpe desktop-file-utils \
		pkgconfig python:build qt:5 ssl xorg
USE_CXXSTD=	c++17
USE_LDCONFIG=	yes
USE_QT=		buildtools:build concurrent core dbus gui l10n linguist:build network \
		qmake:build sql sql-sqlite3:run svg widgets xml
USE_XORG=	x11 xext xi

CMAKE_ARGS=	-DCMAKE_CXX_STANDARD=17
CMAKE_ON=	client oss overlay plugins translations xinput2
CMAKE_OFF=	bundled-gsl bundled-json bundle-qt-translations bundled-speex \
		crash-report g15 server tracy update

CONFIGURE_ENV=	MUMBLE_PYTHON=${PYTHON_CMD}
CXXFLAGS+=	-Wno-deprecated-declarations

PLIST_SUB=	MUMBLE_VERSION="${DISTVERSION:R}"

OPTIONS_DEFINE=		ALSA AVAHI JACK LTO PIPEWIRE PORTAUDIO PULSEAUDIO RENAMENOISE
OPTIONS_DEFINE_amd64=	OVERLAY_32BIT
OPTIONS_DEFAULT=	RENAMENOISE
OPTIONS_DEFAULT_amd64=	OVERLAY_32BIT
OPTIONS_RADIO=		SPEECH
OPTIONS_RADIO_SPEECH=	QTSPEECH SPEECHD

OVERLAY_32BIT_DESC=	Build and install 32bit overlay module
QTSPEECH_DESC=		Use Qt's text-to-speech system
RENAMENOISE_DESC=	Use ReNameNoise for machine learning noise reduction
SPEECHD_DESC=		Support for Speech Dispatcher
SPEECH_DESC=		Support text-to-speech

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CMAKE_BOOL=	alsa

AVAHI_LIB_DEPENDS=	libdns_sd.so:net/avahi-libdns
AVAHI_CMAKE_BOOL=	zeroconf

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

RENAMENOISE_CMAKE_BOOL=	bundled-renamenoise renamenoise

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
