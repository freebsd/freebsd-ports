PORTNAME=	strawberry
DISTVERSION=	1.0.21
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	https://github.com/strawberrymusicplayer/${PORTNAME}/releases/download/${DISTVERSION}/ \
		https://files.jkvinge.net/packages/strawberry/
PKGNAMESUFFIX=	-${FLAVOR}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Music player and collection organizer
WWW=		https://www.strawberrymusicplayer.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs
LIB_DEPENDS=	libprotobuf.so:devel/protobuf \
		libtag.so:audio/taglib

FLAVORS=		qt6 qt5
FLAVOR?=		${FLAVORS:[1]}
qt5_CONFLICTS_INSTALL=	strawberry strawberry-qt6
qt6_CONFLICTS_INSTALL=	strawberry strawberry-qt5

USES=		cmake compiler:c++17-lang desktop-file-utils gettext-runtime \
		gl gnome pkgconfig qt:${FLAVOR:S/qt//} sqlite tar:xz xorg

USE_GNOME=	glib20
_USE_GL_qt5=	#
_USE_GL_qt6=	opengl
USE_GL=		${_USE_GL_${FLAVOR}}
_USE_QT_qt5=	concurrent core dbus gui network sql sql-sqlite3:run widgets \
		x11extras buildtools:build linguisttools:build qmake:build
_USE_QT_qt6=	base sqldriver-sqlite:run tools:build
USE_QT=		${_USE_QT_${FLAVOR}}
USE_XORG=	ice sm x11 xcb xext

CMAKE_ON=	BUILD_WITH_${FLAVOR:tu}
CMAKE_OFF=	ENABLE_UDISKS2

SUB_FILES=	pkg-message

OPTIONS_MULTI=		BACKEND SOUND
OPTIONS_MULTI_BACKEND=	GSTREAMER VLC
OPTIONS_MULTI_SOUND=	ALSA PULSEAUDIO
OPTIONS_SINGLE=		UNICODE
OPTIONS_SINGLE_UNICODE=	ICONV ICU
OPTIONS_DEFINE=		CDIO EBUR128 IPOD MOODBAR MTP MUSICBRAINZ NLS TEST
OPTIONS_DEFAULT=	ALSA EBUR128 GSTREAMER ICU MOODBAR MUSICBRAINZ
OPTIONS_SUB=		yes

BACKEND_DESC=		Playback engine
IPOD_DESC=		iPod Classic support
MOODBAR_DESC=		Moodbar support
MUSICBRAINZ_DESC=	Tagging/fingerprinting from MusicBrainz
VLC_DESC=		Multimedia support via (lib)vlc

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CMAKE_BOOL=	ENABLE_ALSA

CDIO_LIB_DEPENDS=	libcdio.so:sysutils/libcdio
CDIO_CMAKE_BOOL=	ENABLE_AUDIOCD
CDIO_IMPLIES=		GSTREAMER

EBUR128_DESC=		EBU R 128 loudness normalization
EBUR128_USES=		ebur128
EBUR128_CMAKE_BOOL=	ENABLE_EBUR128
EBUR128_IMPLIES=	GSTREAMER

GSTREAMER_USES=		gstreamer
GSTREAMER_CMAKE_BOOL=	ENABLE_GSTREAMER

ICONV_USES=		iconv:translit

ICU_LIB_DEPENDS=	libicui18n.so:devel/icu
ICU_CMAKE_BOOL=		USE_ICU

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
.if ${FLAVOR:U} == qt5
TEST_USE=		QT=testlib:build
.endif
TEST_TEST_TARGET=	strawberry_tests

.include <bsd.port.mk>
