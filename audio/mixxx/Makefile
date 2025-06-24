PORTNAME=	mixxx
DISTVERSION=	2.5.2
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
		libmp3lame.so:audio/lame

USES=		cmake:testing compiler:c++20-lang ebur128 gl iconv ninja pkgconfig \
		sqlite ssl xorg

FLAVORS=	qt5 qt6
FLAVOR?=	${FLAVORS:[1]}

qt5_CONFLICTS=          mixxx-qt6
qt6_CONFLICTS=          mixxx-qt5

USE_XORG=	ice sm x11 xext
USE_GL=		gl glu
USE_GITHUB=	yes
GH_ACCOUNT=	mixxxdj

.if ${FLAVOR} == qt6
PKGNAMESUFFIX=  -qt6

USES+=		qt:6
USE_QT=		5compat base:run declarative:build tools:build shadertools \
		sqldriver-sqlite:run svg
CMAKE_ARGS+=	-DQT6=ON

QTKEYCHAIN_LIB_DEPENDS=	libqt6keychain.so:security/qtkeychain@qt6

PLIST_SUB+=	QT6=""
.else
PKGNAMESUFFIX=	-qt5

USES+=		qt:5
USE_QT=		buildtools concurrent core dbus declarative gui linguisttools:build \
		network opengl printsupport qmake:build sql sql-sqlite3 svg testlib \
		widgets x11extras xml
CMAKE_ARGS+=	-DQT6=OFF

QTKEYCHAIN_LIB_DEPENDS=	libqt5keychain.so:security/qtkeychain@qt5

PLIST_SUB+=	QT6="@comment "
.endif

CMAKE_ARGS+=	-DINSTALL_USER_UDEV_RULES:BOOL=OFF \
		-DOPTIMIZE:STRING=portable \
		-DBATTERY:BOOL=OFF \
		-DFAAD:BOOL=OFF \
		-DMODPLUG:BOOL=ON \
		-DMAD:BOOL=ON

PORTDOCS=	*

OPTIONS_DEFINE=		BROADCAST DOCS ENGINEPRIME FFMPEG GPERFTOOLS HID OPUS \
			QTKEYCHAIN WAVPACK
OPTIONS_DEFAULT=	BROADCAST FFMPEG HID OPUS QTKEYCHAIN WAVPACK
OPTIONS_SUB=		yes

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
WAVPACK_LIB_DEPENDS=	libwavpack.so:audio/wavpack
WAVPACK_CMAKE_BOOL=	WAVPACK

post-patch:
	@${REINPLACE_CMD} -e "s|^Exec=.*|Exec=mixxx|" \
		${WRKSRC}/res/linux/org.mixxx.Mixxx.desktop
	@${REINPLACE_CMD} -e "s,(Q_OS_LINUX),(Q_OS_LINUX) || defined(Q_OS_FREEBSD),g" \
		${WRKSRC}/src/util/screensaver.h
	@${REINPLACE_CMD} -e "s|QUIET hidapi-libusb|QUIET hidapi|" \
		${WRKSRC}/cmake/modules/Findhidapi.cmake
.for i in midi/midimessage.h
	@${ECHO_CMD} >> ${WRKSRC}/src/controllers/${i}
.endfor

.include <bsd.port.mk>
