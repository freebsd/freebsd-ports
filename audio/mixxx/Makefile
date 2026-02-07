PORTNAME=	mixxx
DISTVERSION=	2.5.4
CATEGORIES=	audio

MAINTAINER=	acm@FreeBSD.org
COMMENT=	DJ mixing application
WWW=		https://mixxx.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	benchmark>0:devel/benchmark \
		googletest>0:devel/googletest \
		lv2>=1.14.0:audio/lv2 \
		microsoft-gsl>0:devel/microsoft-gsl
LIB_DEPENDS=	libabsl_base.so:devel/abseil \
		libchromaprint.so:audio/chromaprint \
		libFLAC.so:audio/flac \
		libfftw3.so:math/fftw3 \
		libhidapi.so:comms/hidapi \
		libid3tag.so:audio/libid3tag \
		libmad.so:audio/libmad \
		libmodplug.so:audio/libmodplug \
		libportaudio.so:audio/portaudio \
		libSoundTouch.so:audio/soundtouch \
		librubberband.so:audio/rubberband \
		libsndfile.so:audio/libsndfile \
		libogg.so:audio/libogg \
		libvorbisfile.so:audio/libvorbis \
		libtag.so:audio/taglib \
		libprotobuf.so:devel/protobuf \
		liblilv-0.so:audio/lilv \
		libportmidi.so:audio/portmidi \
		libupower-glib.so:sysutils/upower \
		libkeyfinder.so:audio/libkeyfinder \
		libmp3lame.so:audio/lame \
		libxkbcommon.so:x11/libxkbcommon

USES=		cmake:testing compiler:c++20-lang ebur128 gl iconv ninja pkgconfig \
		qt:6 sqlite ssl xorg
USE_QT=		5compat base declarative shadertools sqldriver-sqlite:run svg \
		tools:build
USE_XORG=	ice sm x11 xext
USE_GL=		gl glu
USE_GITHUB=	yes
GH_ACCOUNT=	mixxxdj

CMAKE_ARGS+=	-DINSTALL_USER_UDEV_RULES:BOOL=OFF \
		-DOPTIMIZE:STRING=portable \
		-DBATTERY:BOOL=OFF \
		-DMODPLUG:BOOL=ON \
		-DMAD:BOOL=ON \
		-DQT6=ON

PORTDOCS=	*

OPTIONS_DEFINE=		AAC BROADCAST DOCS ENGINEPRIME FFMPEG GPERFTOOLS HID OPUS \
			QTKEYCHAIN WAVPACK
OPTIONS_DEFAULT=	BROADCAST FFMPEG HID OPUS QTKEYCHAIN WAVPACK
OPTIONS_SUB=		yes

AAC_DESC=		AAC (m4a and mp4) support
AAC_CMAKE_BOOL=		FAAD
AAC_LIB_DEPENDS=	libfaad.so:audio/faad \
			libmp4v2.so:multimedia/mp4v2
BROADCAST_DESC=		Live Broadcasting (Shoutcast) support
#BROADCAST_LIB_DEPENDS=	libshout-idjc.so:audio/shout-idjc
BROADCAST_CMAKE_BOOL=	BROADCAST

ENGINEPRIME_DESC=	Denon Engine Prime library export support
ENGINEPRIME_LIB_DEPENDS=	libdjinterop.so:audio/libdjinterop
ENGINEPRIME_CMAKE_BOOL=	ENGINEPRIME

FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg
FFMPEG_CMAKE_BOOL=	FFMPEG

GPERFTOOLS_LIB_DEPENDS=	libtcmalloc.so:devel/google-perftools
GPERFTOOLS_CMAKE_BOOL=	GPERFTOOLS

HID_DESC=		USB HID controllers support
HID_CMAKE_BOOL=		HID

OPUS_LIB_DEPENDS=	libopus.so:audio/opus \
			libopusfile.so:audio/opusfile
OPUS_CMAKE_BOOL=	OPUS

QTKEYCHAIN_DESC=	Secure credentials storage for Live Broadcasting profiles
QTKEYCHAIN_CMAKE_BOOL=	QTKEYCHAIN
QTKEYCHAIN_LIB_DEPENDS=	libqt6keychain.so:security/qtkeychain@qt6

WAVPACK_LIB_DEPENDS=	libwavpack.so:audio/wavpack
WAVPACK_CMAKE_BOOL=	WAVPACK

post-patch:
	@${REINPLACE_CMD} -e "s|^Exec=.*|Exec=mixxx|" \
		${WRKSRC}/res/linux/org.mixxx.Mixxx.desktop
	@${REINPLACE_CMD} -e "s,(Q_OS_LINUX),(Q_OS_LINUX) || defined(Q_OS_FREEBSD),g" \
		${WRKSRC}/src/util/screensaver.h
.for i in midi/midimessage.h
	@${ECHO_CMD} >> ${WRKSRC}/src/controllers/${i}
.endfor

.include <bsd.port.mk>
