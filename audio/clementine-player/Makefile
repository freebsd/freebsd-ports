# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	clementine
DISTVERSION=	1.3.1-661
DISTVERSIONSUFFIX=	-g4ff370ce1
PORTREVISION=	1
CATEGORIES=	audio
PKGNAMESUFFIX=	-player

MAINTAINER=	sbruno@FreeBSD.org
COMMENT=	Cross-platform music player based on Amarok 1.4

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:devel/boost-libs
LIB_DEPENDS=	libtag.so:audio/taglib \
		libchromaprint.so:audio/chromaprint \
		libprotobuf.so:devel/protobuf \
		libqca-qt5.so:devel/qca@qt5 \
		libqjson-qt5.so:devel/qjson@qt5 \
		libfftw3.so:math/fftw3 \
		libechonest5.so:audio/libechonest \
		libcryptopp.so:security/cryptopp

USES=		cmake \
		compiler:c++11-lib \
		desktop-file-utils \
		gettext-tools \
		pkgconfig \
		qt:5 \
		sqlite \
		gl

USE_CXXSTD=	c++11

USE_GITHUB=	yes
GH_ACCOUNT=	clementine-player
GH_PROJECT=	Clementine

USE_GL=		gl glew glu
USE_XORG=	x11

USE_QT=		buildtools_build \
		concurrent \
		core \
		dbus \
		gui \
		imageformats \
		linguist_build \
		network \
		opengl \
		qmake_build \
		testlib_build \
		sql \
		widgets \
		x11extras \
		xml

USE_GSTREAMER1=	cdparanoia \
		chromaprint \
		faac \
		faad \
		flac \
		lame \
		mpg123 \
		neon \
		opus \
		shout2 \
		soup \
		taglib \
		twolame \
		vorbis

INSTALLS_ICONS=	yes

CFLAGS+=	-Wno-inconsistent-missing-override \
		-Wno-unused-variable \
		-Wno-unused-function

CMAKE_ARGS+=	-DCMAKE_LIBRARY_PATH:PATH="${LOCALBASE}/lib:${PREFIX}/lib" \
		-DENABLE_DBUS=ON \
		-DENABLE_SPOTIFY_BLOB=OFF

OPTIONS_SUB=		yes
OPTIONS_DEFINE=		AMAZON \
			AUDIOCD \
			BOX \
			BREAKPAD \
			DEVICEKIT \
			DROPBOX \
			GIO \
			GOOGLE_DRIVE \
			GPOD \
			LASTFM \
			MOODBAR \
			MTP \
			PULSEAUDIO \
			SKYDRIVE \
			VISUALISATION \
			WIIMOTEDEV

AMAZON_DESC=		Amazon Drive support
AUDIOCD_DESC=		Devices: Audio CD support
BOX_DESC=		Box Drive support
BREAKPAD_DESC=		Crash reporting
DEVICEKIT_DESC=		Devices: DeviceKit backend
DROPBOX_DESC=		Dropbox Support
GIO_DESC=		Devices: GIO device backend
GOOGLE_DRIVE_DESC=	Google Drive support
GPOD_DESC=		iPod support
LASTFM_DESC=		Support Last.fm service (requires ruby)
MOODBAR_DESC=		Moodbar Support
MTP_DESC=		MTP device support
PULSEAUDIO_DESC=	Enable Pulseaudio Support
SKYDRIVE_DESC=		Microsoft SkyDrive Support
VISUALISATION_DESC=	Visualisations from projectM
WIIMOTEDEV_DESC=	Wiimote support

OPTIONS_DEFAULT=	AMAZON \
			AUDIOCD \
			BOX \
			DEVICEKIT \
			DROPBOX \
			GIO \
			GOOGLE_DRIVE \
			GPOD \
			LASTFM \
			MOODBAR \
			MTP \
			SKYDRIVE \
			VISUALISATION \
			WIIMOTEDEV

AMAZON_CMAKE_ON=	-DENABLE_AMAZON_CLOUD_DRIVE=ON
AMAZON_CMAKE_OFF=	-DENABLE_AMAZON_CLOUD_DRIVE=OFF

AUDIOCD_LIB_DEPENDS=	libcdio.so:sysutils/libcdio
AUDIOCD_CMAKE_ON=	-DENABLE_AUDIOCD=ON
AUDIOCD_CMAKE_OFF=	-DENABLE_AUDIOCD=OFF

BOX_BUILD_DEPENDS=	sparsehash>=2.0.2:devel/sparsehash
BOX_CMAKE_ON=		-DENABLE_BOX=ON
BOX_CMAKE_OFF=		-DENABLE_BOX=OFF

BREAKPAD_CMAKE_ON=	-DENABLE_BREAKPAD=ON
BREAKPAD_CMAKE_OFF=	-DENABLE_BREAKPAD=OFF

DEVICEKIT_CMAKE_ON=	-DENABLE_DEVICEKIT=ON
DEVICEKIT_CMAKE_OFF=	-DENABLE_DEVICEKIT=OFF

DROPBOX_BUILD_DEPENDS=	sparsehash>=2.0.2:devel/sparsehash
DROPBOX_CMAKE_ON=	-DENABLE_DROPBOX=ON
DROPBOX_CMAKE_OFF=	-DENABLE_DROPBOX=OFF

GIO_USES=		gnome
GIO_USE=		GNOME=glib20
GIO_CMAKE_ON=		-DENABLE_GIO=ON
GIO_CMAKE_OFF=		-DENABLE_GIO=OFF

GOOGLE_DRIVE_BUILD_DEPENDS=	sparsehash>=2.0.2:devel/sparsehash
GOOGLE_DRIVE_CMAKE_ON=	-DENABLE_GOOGLE_DRIVE=ON
GOOGLE_DRIVE_CMAKE_OFF=	-DENABLE_GOOGLE_DRIVE=OFF

GPOD_LIB_DEPENDS=	libgpod.so:audio/libgpod \
			libplist.so:devel/libplist \
			libusbmuxd.so:comms/libusbmuxd \
			libimobiledevice.so:comms/libimobiledevice
GPOD_CMAKE_ON=		-DENABLE_LIBGPOD=ON
GPOD_CMAKE_OFF=		-DENABLE_LIBGPOD=OFF

LASTFM_LIB_DEPENDS=	liblastfm5.so:audio/liblastfm-qt5
LASTFM_CMAKE_ON=	-DENABLE_LIBLASTFM=ON
LASTFM_CMAKE_OFF=	-DENABLE_LIBLASTFM=OFF

MOODBAR_CMAKE_ON=	-DENABLE_MOODBAR=ON
MOODBAR_CMAKE_OFF=	-DENABLE_MOODBAR=OFF

MTP_LIB_DEPENDS=	libmtp.so:multimedia/libmtp
MTP_CMAKE_ON=		-DENABLE_LIBMTP=ON
MTP_CMAKE_OFF=		-DENABLE_LIBMTP=OFF

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CMAKE_ON=	-DENABLE_LIBPULSE=ON
PULSEAUDIO_CMAKE_OFF=	-DENABLE_LIBPULSE=OFF

SKYDRIVE_BUILD_DEPENDS=	sparsehash>=2.0.2:devel/sparsehash
SKYDRIVE_CMAKE_ON=	-DENABLE_SKYDRIVE=ON
SKYDRIVE_CMAKE_OFF=	-DENABLE_SKYDRIVE=OFF

VISUALISATION_CMAKE_ON=	-DENABLE_VISUALISATIONS=ON
VISUALISATION_CMAKE_OFF=-DENABLE_VISUALISATIONS=OFF

WIIMOTEDEV_CMAKE_ON=	-DENABLE_WIIMOTEDEV=ON
WIIMOTEDEV_CMAKE_OFF=	-DENABLE_WIIMOTEDEV=OFF

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == clang
CXXFLAGS+=	-Wno-unknown-warning-option -Wno-undefined-var-template
.endif

.include <bsd.port.post.mk>
