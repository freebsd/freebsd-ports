PORTNAME=	libsndfile
DISTVERSION=	1.0.31
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/${DISTVERSION}/

PATCH_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/commit/
PATCHFILES=	cc342f9e45315f9f3de12ae493bc6b3a2bd0a0b1.patch:-p1

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Reading and writing files containing sampled sound (like WAV or AIFF)

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake cpe localbase pkgconfig python:build,test shebangfix \
		tar:bz2
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
EXTERNAL_DESC=	Enable FLAC, Ogg Vorbis, Opus support
TEST_DESC=	Build tests (forces static library only)
TEST_IMPLIES=	STATIC

EXTERNAL_LIB_DEPENDS=	libFLAC.so:audio/flac \
			libogg.so:audio/libogg \
			libopus.so:audio/opus \
			libvorbis.so:audio/libvorbis

MANPAGES_CMAKE_BOOL=	INSTALL_MANPAGES
STATIC_CMAKE_OFF=	-DBUILD_SHARED_LIBS:BOOL=ON
TEST_CMAKE_BOOL=	BUILD_TESTING

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MEXTERNAL}
EXTRA_PATCHES=	${FILESDIR}/extrapatch-cmake_SndFileChecks.cmake-disableexternallibs
.endif

do-test:
	(cd ${TEST_WRKSRC} && CTEST_OUTPUT_ON_FAILURE=1 ctest -V)

.include <bsd.port.mk>
