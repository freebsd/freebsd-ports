# Created by: ijliao
# $FreeBSD$

PORTNAME=	libsndfile
DISTVERSION=	1.0.29pre.20200620
CATEGORIES=	audio

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Reading and writing files containing sampled sound (like WAV or AIFF)

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake cpe localbase pkgconfig python:build,test shebangfix
SHEBANG_FILES=	programs/test-sndfile-metadata-set.py \
		src/binheader_writef_check.py \
		src/create_symbols_file.py

CPE_VENDOR=	${CPE_PRODUCT}_project

USE_GITHUB=	yes
GH_ACCOUNT=	erikd
GH_TAGNAME=	2ccb23f

USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS EXTERNAL STATIC TEST
OPTIONS_SUB=	yes
OPTIONS_DEFAULT=	EXTERNAL
EXTERNAL_DESC=	Enable FLAC, Ogg Vorbis, Opus support
TEST_IMPLIES=	STATIC

EXTERNAL_LIB_DEPENDS=	libFLAC.so:audio/flac \
			libogg.so:audio/libogg \
			libopus.so:audio/opus \
			libvorbis.so:audio/libvorbis

STATIC_CMAKE_OFF=	-DBUILD_SHARED_LIBS:BOOL=ON

TEST_CMAKE_ON=	-DBUILD_TESTING:BOOL=ON
TEST_CMAKE_OFF=	-DBUILD_TESTING:BOOL=OFF

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MEXTERNAL}
EXTRA_PATCHES=	${FILESDIR}/extrapatch-cmake_SndFileChecks.cmake-disableexternallibs
.endif

do-test:
	(cd ${TEST_WRKSRC} && CTEST_OUTPUT_ON_FAILURE=1 ctest -V)

.include <bsd.port.mk>
