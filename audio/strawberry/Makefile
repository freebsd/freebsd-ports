PORTNAME=	strawberry
DISTVERSION=	1.1.1
CATEGORIES=	audio
MASTER_SITES=	https://github.com/strawberrymusicplayer/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Music player and collection organizer
WWW=		https://www.strawberrymusicplayer.org/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs
LIB_DEPENDS=	libabsl_base.so:devel/abseil \
		libicui18n.so:devel/icu \
		libprotobuf.so:devel/protobuf \
		libtag.so:audio/taglib

USES=		cmake compiler:c++17-lang desktop-file-utils gettext-runtime \
		gl gnome pkgconfig qt:6 sqlite tar:xz xorg

USE_GNOME=	glib20
USE_GL=		opengl
USE_QT=		base sqldriver-sqlite:run tools:build
USE_XORG=	ice sm x11 xcb xext

CMAKE_ON=	BUILD_WITH_QT6
CMAKE_OFF=	ENABLE_UDISKS2

OPTIONS_MULTI=		BACKEND SOUND
OPTIONS_MULTI_BACKEND=	GSTREAMER VLC
OPTIONS_MULTI_SOUND=	ALSA PULSEAUDIO
OPTIONS_DEFINE=		CDIO EBUR128 IPOD MOODBAR MTP MUSICBRAINZ NLS TEST
OPTIONS_DEFAULT=	ALSA EBUR128 GSTREAMER MOODBAR MUSICBRAINZ
OPTIONS_SUB=		yes

BACKEND_DESC=		Playback engine
IPOD_DESC=		iPod Classic support
MOODBAR_DESC=		Moodbar support
MUSICBRAINZ_DESC=	Tagging/fingerprinting from MusicBrainz
VLC_DESC=		Multimedia support via (lib)vlc

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CMAKE_BOOL=	ENABLE_ALSA

CDIO_LIB_DEPENDS=	libcdio.so:sysutils/libcdio
CDIO_USE=		GSTREAMER=cdparanoia
CDIO_CMAKE_BOOL=	ENABLE_AUDIOCD
CDIO_IMPLIES=		GSTREAMER

EBUR128_DESC=		EBU R 128 loudness normalization
EBUR128_USES=		ebur128
EBUR128_CMAKE_BOOL=	ENABLE_EBUR128
EBUR128_IMPLIES=	GSTREAMER

GSTREAMER_USES=		gstreamer
GSTREAMER_USE=		GSTREAMER=faac,faad,flac,lame,libav,mpg123,opus,taglib,vorbis
GSTREAMER_CMAKE_BOOL=	ENABLE_GSTREAMER

IPOD_LIB_DEPENDS=	libgpod.so:audio/libgpod \
			libimobiledevice-1.0.so:comms/libimobiledevice \
			libplist-2.0.so:devel/libplist
IPOD_CMAKE_BOOL=	ENABLE_LIBGPOD

MOODBAR_LIB_DEPENDS=	libfftw3.so:math/fftw3
MOODBAR_CMAKE_BOOL=	ENABLE_MOODBAR
MOODBAR_IMPLIES=	GSTREAMER

MTP_LIB_DEPENDS=	libmtp.so:multimedia/libmtp
MTP_CMAKE_BOOL=		ENABLE_LIBMTP

MUSICBRAINZ_LIB_DEPENDS=	libchromaprint.so:audio/chromaprint
MUSICBRAINZ_CMAKE_BOOL=		ENABLE_MUSICBRAINZ \
				ENABLE_SONGFINGERPRINTING
MUSICBRAINZ_IMPLIES=		GSTREAMER

NLS_USES=		gettext-tools
NLS_CMAKE_BOOL=		ENABLE_TRANSLATIONS

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CMAKE_BOOL=	ENABLE_LIBPULSE

VLC_LIB_DEPENDS=	libvlc.so:multimedia/vlc
VLC_CMAKE_BOOL=		ENABLE_VLC

TEST_BUILD_DEPENDS=	googletest>=0:devel/googletest
TEST_TEST_TARGET=	strawberry_tests

.include <bsd.port.mk>
