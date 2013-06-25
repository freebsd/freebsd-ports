# Created by: Veniamin Gvozdikov <vg@freebsd.org>
# $FreeBSD$

PORTNAME=	clementine
PORTVERSION=	1.1.1
CATEGORIES=	audio
MASTER_SITES=	GOOGLE_CODE
PKGNAMESUFFIX=	-player

MAINTAINER=	vg@freebsd.org
COMMENT=	Cross-platform music player based on Amarok 1.4

LICENSE=	GPLv3

LIB_DEPENDS=	execinfo:${PORTSDIR}/devel/libexecinfo \
		tag:${PORTSDIR}/audio/taglib \
		chromaprint:${PORTSDIR}/audio/chromaprint \
		protobuf-lite:${PORTSDIR}/devel/protobuf \
		qjson:${PORTSDIR}/devel/qjson \
		fftw3:${PORTSDIR}/math/fftw3
BUILD_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:${PORTSDIR}/devel/boost-libs

# avoid clash with x11-wm/clementine
LATEST_LINK=	${PORTNAME}${PKGNAMESUFFIX}
PROJECTHOST=	${PORTNAME}${PKGNAMESUFFIX}

USES=		cmake
USE_GL=		glew
USE_QT4=	dbus gui xml qmake_build uic_build moc_build rcc_build \
		linguist_build network sql opengl qtestlib corelib webkit
USE_GCC=	4.2+
INSTALLS_ICONS=	yes
USE_GSTREAMER=	gio ogg mp3 flac soup vorbis
MAKE_JOBS_UNSAFE=	yes

CMAKE_ARGS+=	-DCMAKE_LIBRARY_PATH:PATH="${LOCALBASE}/lib:${PREFIX}/lib"

OPTIONS_DEFINE=		AUDIOCD BREAKPAD DEVICEKIT GIO GOOGLE_DRIVE GPOD \
			IMOBILEDEVICE LASTFM MTP SPOTIFY VISUALISATION WIIMOTEDEV

AUDIOCD_DESC=		Devices: Audio CD support
BREAKPAD_DESC=		Crash reporting
DEVICEKIT_DESC=		Devices: DeviceKit backend
GIO_DESC=		Devices: GIO device backend
GOOGLE_DRIVE_DESC=	Google Drive support
GPOD_DESC=		iPod support
IMOBILEDEVICE_DESC=	Devices: iPod Touch, iPhone, iPad support
LASTFM_DESC=		Support Last.fm service (requires ruby)
MTP_DESC=		MTP device support
SPOTIFY_DESC=		Support for Spotify service
VISUALISATION_DESC=	Visualisations from projectM
WIIMOTEDEV_DESC=	Wiimote support

OPTIONS_DEFAULT=	AUDIOCD DEVICEKIT GIO GOOGLE_DRIVE LASTFM MTP SPOTIFY \
			VISUALISATION WIIMOTEDEV

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAUDIOCD}
CMAKE_ARGS+=	-DENABLE_AUDIOCD=ON
LIB_DEPENDS+=	cdio:${PORTSDIR}/sysutils/libcdio
.else
CMAKE_ARGS+=	-DENABLE_AUDIOCD=OFF
.endif

.if ${PORT_OPTIONS:MBREAKPAD}
CMAKE_ARGS+=	-DENABLE_BREAKPAD=ON
.else
CMAKE_ARGS+=	-DENABLE_BREAKPAD=OFF
.endif

.if ${PORT_OPTIONS:MDEVICEKIT}
CMAKE_ARGS+=	-DENABLE_DEVICEKIT=ON
.else
CMAKE_ARGS+=	-DENABLE_DEVICEKIT=OFF
.endif

.if ${PORT_OPTIONS:MGIO}
CMAKE_ARGS+=	-DENABLE_GIO=ON
USE_GNOME=	glib20
.else
CMAKE_ARGS+=	-DENABLE_GIO=OFF
.endif

.if ${PORT_OPTIONS:MGOOGLE_DRIVE}
CMAKE_ARGS+=	-DENABLE_GOOGLE_DRIVE=ON
BUILD_DEPENDS+=	google-sparsehash>=2.0.2:${PORTSDIR}/devel/google-sparsehash
.else
CMAKE_ARGS+=	-DENABLE_GOOGLE_DRIVE=OFF
.endif

.if ${PORT_OPTIONS:MGPOD}
CMAKE_ARGS+=	-DENABLE_LIBGPOD=ON
LIB_DEPENDS+=	gpod:${PORTSDIR}/audio/libgpod
.else
CMAKE_ARGS+=	-DENABLE_LIBGPOD=OFF
.endif

.if ${PORT_OPTIONS:MIMOBILEDEVICE}
CMAKE_ARGS+=	-DENABLE_IMOBILEDEVICE=ON
LIB_DEPENDS+=	imobiledevice:${PORTSDIR}/comms/libimobiledevice \
		plist:${PORTSDIR}/devel/libplist \
		usbmuxd:${PORTSDIR}/comms/usbmuxd
.else
CMAKE_ARGS+=	-DENABLE_IMOBILEDEVICE=OFF
.endif

.if ${PORT_OPTIONS:MLASTFM}
CMAKE_ARGS+=	-DENABLE_LIBLASTFM=ON
LIB_DEPENDS+=	lastfm:${PORTSDIR}/audio/liblastfm
.else
CMAKE_ARGS+=	-DENABLE_LIBLASTFM=OFF
.endif

.if ${PORT_OPTIONS:MMTP}
CMAKE_ARGS+=	-DENABLE_LIBMTP=ON
LIB_DEPENDS+=	mtp:${PORTSDIR}/audio/libmtp
.else
CMAKE_ARGS+=	-DENABLE_LIBMTP=OFF
.endif

.if ${PORT_OPTIONS:MSPOTIFY}
CMAKE_ARGS+=	-DENABLE_SPOTIFY=ON
LIB_DEPENDS+=	qca:${PORTSDIR}/devel/qca
.else
CMAKE_ARGS+=	-DENABLE_SPOTIFY=OFF
.endif

.if ${PORT_OPTIONS:MVISUALISATION}
CMAKE_ARGS+=	-DENABLE_VISUALISATIONS=ON
.else
CMAKE_ARGS+=	-DENABLE_VISUALISATIONS=OFF
.endif

.if ${PORT_OPTIONS:MWIIMOTEDEV}
CMAKE_ARGS+=	-DENABLE_WIIMOTEDEV=ON
.else
CMAKE_ARGS+=	-DENABLE_WIIMOTEDEV=OFF
.endif

.include <bsd.port.mk>
