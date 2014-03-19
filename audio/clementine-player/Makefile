# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	clementine
PORTVERSION=	1.2.1
PORTREVISION=	7
CATEGORIES=	audio
MASTER_SITES=	GOOGLE_CODE
PKGNAMESUFFIX=	-player

MAINTAINER=	sbruno@FreeBSD.org
COMMENT=	Cross-platform music player based on Amarok 1.4

LICENSE=	GPLv3

LIB_DEPENDS=	libexecinfo.so:${PORTSDIR}/devel/libexecinfo \
		libtag.so:${PORTSDIR}/audio/taglib \
		libchromaprint.so:${PORTSDIR}/audio/chromaprint \
		libprotobuf.so:${PORTSDIR}/devel/protobuf \
 	 	libqca.so:${PORTSDIR}/devel/qca \
		libqjson.so:${PORTSDIR}/devel/qjson \
		libfftw3.so:${PORTSDIR}/math/fftw3

BUILD_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:${PORTSDIR}/devel/boost-libs

# avoid clash with x11-wm/clementine
LATEST_LINK=	${PORTNAME}${PKGNAMESUFFIX}
PROJECTHOST=	${PORTNAME}${PKGNAMESUFFIX}

USES=		compiler:c++11-lib cmake pkgconfig desktop-file-utils
USE_GL=		glew
USE_QT4=	dbus gui xml qmake_build uic_build moc_build rcc_build \
		linguist_build network sql opengl qtestlib corelib webkit \
		imageformats

INSTALLS_ICONS=	yes
USE_GSTREAMER=	gio ogg mp3 flac soup vorbis
CONFLICTS_BUILD=	qt-3.*

CFLAGS+=	-Wno-deprecated-register

CMAKE_ARGS+=	-DCMAKE_LIBRARY_PATH:PATH="${LOCALBASE}/lib:${PREFIX}/lib" \
		-DENABLE_DBUS=ON -DENABLE_SPARKLE=OFF \
		-DENABLE_SOUNDMENU=OFF -DENABLE_SPOTIFY_BLOB=OFF \
		-DENABLE_UBUNTU_ONE=OFF -DENABLE_SKYDRIVE=OFF

OPTIONS_DEFINE=		AUDIOCD BREAKPAD DEVICEKIT DROPBOX BOX GIO GOOGLE_DRIVE \
			GPOD LASTFM MTP VISUALISATION WIIMOTEDEV MOODBAR

OPTIONS_SUB=		VISUALISATION

AUDIOCD_DESC=		Devices: Audio CD support
BREAKPAD_DESC=		Crash reporting
BOX_DESC=		Box Drive support
DEVICEKIT_DESC=		Devices: DeviceKit backend
DROPBOX_DESC=		Dropbox Support
GIO_DESC=		Devices: GIO device backend
GOOGLE_DRIVE_DESC=	Google Drive support
GPOD_DESC=		iPod support
LASTFM_DESC=		Support Last.fm service (requires ruby)
MTP_DESC=		MTP device support
VISUALISATION_DESC=	Visualisations from projectM
WIIMOTEDEV_DESC=	Wiimote support
MOODBAR_DESC=		Moodbar Support

OPTIONS_DEFAULT=	AUDIOCD BOX DEVICEKIT DROPBOX GIO GOOGLE_DRIVE GPOD \
			LASTFM MTP VISUALISATION WIIMOTEDEV MOODBAR

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDROPBOX}
CMAKE_ARGS+=	-DENABLE_DROPBOX=ON
.else
CMAKE_ARGS+=	-DENABLE_DROPBOX=OFF
.endif

.if ${PORT_OPTIONS:MMOODBAR}
CMAKE_ARGS+=	-DENABLE_MOODBAR=ON
.else
CMAKE_ARGS+=	-DENABLE_MOODBAR=OFF
.endif

.if ${PORT_OPTIONS:MAUDIOCD}
CMAKE_ARGS+=	-DENABLE_AUDIOCD=ON
LIB_DEPENDS+=	libcdio.so:${PORTSDIR}/sysutils/libcdio
.else
CMAKE_ARGS+=	-DENABLE_AUDIOCD=OFF
.endif

.if ${PORT_OPTIONS:MBOX}
CMAKE_ARGS+=	-DENABLE_BOX=ON
.else
CMAKE_ARGS+=	-DENABLE_BOX=OFF
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
LIB_DEPENDS+=	libgpod.so:${PORTSDIR}/audio/libgpod
.else
CMAKE_ARGS+=	-DENABLE_LIBGPOD=OFF
.endif

.if ${PORT_OPTIONS:MLASTFM}
CMAKE_ARGS+=	-DENABLE_LIBLASTFM=ON
LIB_DEPENDS+=	liblastfm.so:${PORTSDIR}/audio/liblastfm
.else
CMAKE_ARGS+=	-DENABLE_LIBLASTFM=OFF
.endif

.if ${PORT_OPTIONS:MMTP}
CMAKE_ARGS+=	-DENABLE_LIBMTP=ON
LIB_DEPENDS+=	libmtp.so:${PORTSDIR}/multimedia/libmtp
.else
CMAKE_ARGS+=	-DENABLE_LIBMTP=OFF
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
