PORTNAME=	strawberry
DISTVERSION=	1.2.12
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	https://github.com/strawberrymusicplayer/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Music player and collection organizer
WWW=		https://www.strawberrymusicplayer.org/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs \
		rapidjson>0:devel/rapidjson \
		sparsehash>0:devel/sparsehash
LIB_DEPENDS=	libicui18n.so:devel/icu \
		libkdsingleapplication-qt6.so:devel/kdsingleapplication \
		libtag.so:audio/taglib \
		libxkbcommon.so:x11/libxkbcommon
TEST_DEPENDS=	googletest>=0:devel/googletest

USES=		cmake:testing compiler:c++17-lang desktop-file-utils \
		gl gnome gstreamer pkgconfig qt:6 sqlite tar:xz xorg
USE_GL=		opengl
USE_GNOME=	glib20
USE_GSTREAMER=	faac faad flac lame libav mpg123 opus taglib vorbis
USE_QT=		base sqldriver-sqlite:run
USE_XORG=	ice sm x11 xcb xext

CMAKE_OFF=		ENABLE_UDISKS2
CMAKE_TESTING_SETENV=	yes
CMAKE_TESTING_TARGET=	strawberry_tests

OPTIONS_DEFINE=		CDIO EBUR128 IPOD MOODBAR MTP MUSICBRAINZ NLS
OPTIONS_DEFAULT=	ALSA EBUR128 MOODBAR MUSICBRAINZ
OPTIONS_MULTI=		SOUND
OPTIONS_MULTI_SOUND=	ALSA PULSEAUDIO
OPTIONS_SUB=		yes

EBUR128_DESC=		EBU R 128 loudness normalization
IPOD_DESC=		iPod Classic support
MOODBAR_DESC=		Moodbar support
MUSICBRAINZ_DESC=	Tagging/fingerprinting from MusicBrainz

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CMAKE_BOOL=	ENABLE_ALSA

CDIO_LIB_DEPENDS=	libcdio.so:sysutils/libcdio
CDIO_USE=		GSTREAMER=cdparanoia
CDIO_CMAKE_BOOL=	ENABLE_AUDIOCD

EBUR128_USES=		ebur128
EBUR128_CMAKE_BOOL=	ENABLE_EBUR128

IPOD_LIB_DEPENDS=	libgpod.so:audio/libgpod \
			libimobiledevice-1.0.so:comms/libimobiledevice \
			libplist-2.0.so:devel/libplist
IPOD_USE=		GNOME=gdkpixbuf
IPOD_CMAKE_BOOL=	ENABLE_GPOD

MOODBAR_LIB_DEPENDS=	libfftw3.so:math/fftw3
MOODBAR_CMAKE_BOOL=	ENABLE_MOODBAR

MTP_LIB_DEPENDS=	libmtp.so:multimedia/libmtp
MTP_CMAKE_BOOL=		ENABLE_MTP

MUSICBRAINZ_LIB_DEPENDS=	libchromaprint.so:audio/chromaprint
MUSICBRAINZ_CMAKE_BOOL=		ENABLE_MUSICBRAINZ \
				ENABLE_SONGFINGERPRINTING

NLS_USE=		QT=tools:build
NLS_CMAKE_BOOL=		ENABLE_TRANSLATIONS

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CMAKE_BOOL=	ENABLE_PULSE

.include <bsd.port.mk>
