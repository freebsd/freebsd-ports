PORTNAME=	exiv2
DISTVERSIONPREFIX=	v
DISTVERSION=	0.28.7
PORTEPOCH=	1
CATEGORIES=	graphics

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Exif, IPTC, and XMP metadata manipulation library and tools
WWW=		https://www.exiv2.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libbrotlidec.so:archivers/brotli \
		libexpat.so:textproc/expat2 \
		libinih.so:devel/inih

USES=		cmake compiler:c++17-lang cpe dos2unix gettext-tools iconv \
		localbase:ldflags pathfix shebangfix
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	Exiv2

DOS2UNIX_FILES=	cmake/compilerFlags.cmake

SHEBANG_FILES=	fuzz/mkdictionary.py \
		tests/runner.py

CMAKE_ON=	EXIV2_ENABLE_VIDEO
CMAKE_OFF=	EXIV2_ENABLE_EXTERNAL_XMP

LDFLAGS_mips=	-lintl
LDFLAGS_mips64=	-lintl

PLIST_SUB=	SOVER=${DISTVERSION:R:E} \
		SOVERSION=${DISTVERSION}

OPTIONS_DEFINE=	DOCS DOXYGEN NLS SAMPLE TEST
OPTIONS_SUB=	yes

SAMPLE_DESC=	Include sample applications

DOXYGEN_BUILD_DEPENDS=	dot:graphics/graphviz \
			doxygen:devel/doxygen
DOXYGEN_CMAKE_BOOL=	EXIV2_BUILD_DOC
DOXYGEN_ALL_TARGET=	all doc
DOXYGEN_PORTDOCS=	*

NLS_USES=	gettext-runtime
NLS_CMAKE_BOOL=	EXIV2_ENABLE_NLS

SAMPLE_CMAKE_BOOL=	EXIV2_BUILD_SAMPLES

TEST_IMPLIES=		SAMPLE
TEST_BUILD_DEPENDS=	googletest>0:devel/googletest
TEST_TEST_DEPENDS=	bash:shells/bash
TEST_USES=		python:build,test
TEST_CMAKE_BOOL=	EXIV2_BUILD_UNIT_TESTS
TEST_CMAKE_ON=		-DPython${PYTHON_MAJOR_VER}_EXECUTABLE:FILEPATH="${PYTHON_CMD}"
TEST_TEST_TARGET=	test

.include <bsd.port.mk>
