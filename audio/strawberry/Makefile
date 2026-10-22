PORTNAME=	strawberry
DISTVERSION=	1.2.31
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
		libuchardet.so:textproc/uchardet \
		libxkbcommon.so:x11/libxkbcommon
TEST_DEPENDS=	googletest>=0:devel/googletest

USES=		cmake:testing compiler:c++17-lang desktop-file-utils \
		display:test gl gnome gstreamer pkgconfig qt:6 sqlite ssl \
		tar:xz xorg
USE_GL=		opengl
USE_GNOME=	glib20
USE_GSTREAMER=	faac faad flac lame libav mpg123 opus soup taglib vorbis
USE_QT=		base sqldriver-sqlite:build imageformats:run sqldriver-sqlite:run
USE_XORG=	ice sm x11 xcb xext

CMAKE_OFF=		ENABLE_UDISKS2
CMAKE_TESTING_SETENV=	yes
CMAKE_TESTING_TARGET=	strawberry_tests

OPTIONS_DEFINE=		CDIO CHROMAPRINT EBUR128 IPOD MOODBAR MTP NLS
OPTIONS_DEFAULT=	ALSA CHROMAPRINT EBUR128 GNOMEKEYRING KWALLET \
			LIBSECRET MOODBAR
OPTIONS_GROUP=		CREDS
OPTIONS_GROUP_CREDS=	GNOMEKEYRING KWALLET LIBSECRET
OPTIONS_MULTI=		SOUND
OPTIONS_MULTI_SOUND=	ALSA PULSEAUDIO
OPTIONS_SUB=		yes

CHROMAPRINT_DESC=	Song tagging and fingerprinting
CREDS_DESC=		Credentials manager support
EBUR128_DESC=		EBU R 128 loudness normalization
IPOD_DESC=		iPod Classic support
LIBSECRET_DESC=		Libsecret credentials manager support
MOODBAR_DESC=		Moodbar support

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CMAKE_BOOL=	ENABLE_ALSA

CDIO_LIB_DEPENDS=	libcdio.so:sysutils/libcdio
CDIO_USE=		GSTREAMER=cdparanoia
CDIO_CMAKE_BOOL=	ENABLE_AUDIOCD

CHROMAPRINT_LIB_DEPENDS=	libchromaprint.so:audio/chromaprint
CHROMAPRINT_CMAKE_BOOL=		ENABLE_CHROMAPRINT \
				ENABLE_SONGTRACKING \
				ENABLE_TAGFETCHER

EBUR128_USES=		ebur128
EBUR128_CMAKE_BOOL=	ENABLE_EBUR128

GNOMEKEYRING_CMAKE_BOOL=	ENABLE_GNOME_KEYRING

IPOD_LIB_DEPENDS=	libgpod.so:audio/libgpod
IPOD_USE=		GNOME=gdkpixbuf
IPOD_CMAKE_BOOL=	ENABLE_GPOD

KWALLET_CMAKE_BOOL=	ENABLE_KWALLET

LIBSECRET_LIB_DEPENDS=	libsecret-1.so:security/libsecret
LIBSECRET_CMAKE_BOOL=	ENABLE_LIBSECRET

MOODBAR_LIB_DEPENDS=	libfftw3.so:math/fftw3
MOODBAR_CMAKE_BOOL=	ENABLE_GSTFASTSPECTRUM \
			ENABLE_MOODBAR

MTP_LIB_DEPENDS=	libmtp.so:multimedia/libmtp
MTP_CMAKE_BOOL=		ENABLE_MTP

NLS_USE=		QT=tools:build
NLS_CMAKE_BOOL=		ENABLE_TRANSLATIONS

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CMAKE_BOOL=	ENABLE_PULSE

.include <bsd.port.mk>
