PORTNAME=	libsndfile
DISTVERSION=	1.2.2
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/${DISTVERSION}/

PATCH_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/commit/
PATCHFILES=	0754562e13d2e63a248a1c82f90b30bc0ffe307c.patch:-p1

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Reading and writing files containing sampled sound (like WAV or AIFF)
WWW=		http://www.mega-nerd.com/libsndfile/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake cpe localbase pkgconfig python:build,test \
		shebangfix tar:xz
SHEBANG_FILES=	programs/test-sndfile-metadata-set.py \
		src/binheader_writef_check.py \
		src/create_symbols_file.py

CPE_VENDOR=	${CPE_PRODUCT}_project

USE_LDCONFIG=	yes

CMAKE_ARGS=	-DCMAKE_DISABLE_FIND_PACKAGE_ALSA:BOOL=True \
		-DCMAKE_DISABLE_FIND_PACKAGE_Sndio:BOOL=True \
		-DCMAKE_DISABLE_FIND_PACKAGE_Speex:BOOL=True \
		-DCMAKE_DISABLE_FIND_PACKAGE_SQLite3:BOOL=True

OPTIONS_DEFINE=	DOCS EXTERNAL MANPAGES STATIC TEST
OPTIONS_SUB=	yes
OPTIONS_DEFAULT=	EXTERNAL
EXTERNAL_DESC=	Enable FLAC, MP3, Ogg Vorbis, Opus support
TEST_DESC=	Build tests (forces static library only)
TEST_IMPLIES=	STATIC

EXTERNAL_LIB_DEPENDS=	libFLAC.so:audio/flac \
			libmp3lame.so:audio/lame \
			libmpg123.so:audio/mpg123 \
			libogg.so:audio/libogg \
			libopus.so:audio/opus \
			libvorbis.so:audio/libvorbis
EXTERNAL_CMAKE_BOOL=	ENABLE_EXTERNAL_LIBS ENABLE_MPEG
MANPAGES_CMAKE_BOOL=	INSTALL_MANPAGES
STATIC_CMAKE_OFF=	-DBUILD_SHARED_LIBS:BOOL=ON
TEST_CMAKE_BOOL=	BUILD_TESTING

do-test:
	(cd ${TEST_WRKSRC} && CTEST_OUTPUT_ON_FAILURE=1 ctest -V)

.include <bsd.port.mk>
