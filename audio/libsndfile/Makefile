PORTNAME=	libsndfile
DISTVERSION=	1.2.2.20251216
CATEGORIES=	audio
#MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/${DISTVERSION}/

PATCH_SITES=   https://github.com/${PORTNAME}/${PORTNAME}/commit/
PATCHFILES=    f8cc69656cf401cc33e4e380dfb972c9fdca0750.patch:-p1

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Reading and writing files containing sampled sound (like WAV or AIFF)
WWW=		http://www.mega-nerd.com/libsndfile/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake:testing cpe localbase pkgconfig python:build,test \
		shebangfix tar:xz
CPE_VENDOR=	${CPE_PRODUCT}_project
SHEBANG_FILES=	programs/test-sndfile-metadata-set.py \
		src/binheader_writef_check.py \
		src/create_symbols_file.py
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_TAGNAME=	68f6c16

.if make(test)
# Tests only works with STATIC lib so don't pollute default build dir
BUILD_WRKSRC=	${WRKDIR}/.build-testing
INSTALL_WRKSRC=	${WRKDIR}/.build-testing
TEST_WRKSRC=	${WRKDIR}/.build-testing
.endif

CMAKE_TESTING_OFF=	BUILD_SHARED_LIBS

CMAKE_ON=	BUILD_SHARED_LIBS \
		CMAKE_DISABLE_FIND_PACKAGE_ALSA \
		CMAKE_DISABLE_FIND_PACKAGE_Sndio \
		CMAKE_DISABLE_FIND_PACKAGE_Speex \
		CMAKE_DISABLE_FIND_PACKAGE_SQLite3
CMAKE_ARGS=	-DCMAKE_CTEST_ARGUMENTS="-E;lossy_comp_test_ogg_opus"

OPTIONS_DEFINE=	DOCS EXTERNAL MANPAGES TEST
OPTIONS_SUB=	yes
OPTIONS_DEFAULT=	EXTERNAL

EXTERNAL_DESC=	Enable FLAC, MP3, Ogg Vorbis, Opus support

EXTERNAL_LIB_DEPENDS=	libFLAC.so:audio/flac \
			libmp3lame.so:audio/lame \
			libmpg123.so:audio/mpg123 \
			libogg.so:audio/libogg \
			libopus.so:audio/opus \
			libvorbis.so:audio/libvorbis
EXTERNAL_CMAKE_BOOL=	ENABLE_EXTERNAL_LIBS ENABLE_MPEG

MANPAGES_CMAKE_BOOL=	INSTALL_MANPAGES

pre-test:
	${MKDIR} ${EXTRACT_WRKDIR}/.build-testing

.include <bsd.port.mk>
