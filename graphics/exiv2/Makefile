PORTNAME=	exiv2
DISTVERSION=	0.28.0
DISTVERSIONSUFFIX=	-Source
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/Exiv2/exiv2/releases/download/v${DISTVERSION}/

# https://git.alpinelinux.org/aports/log/community/exiv2
# https://github.com/Exiv2/exiv2/compare/v0.28.0...0.28.x
PATCH_SITES=	https://github.com/Exiv2/exiv2/commit/
PATCHFILES=	16c1cd7da0cd159ee2d53c39088564edaf046c77.patch:-p1 \
		2876c8c5f70f71b5b51b0f26b31dd0dc08583212.patch:-p1 \
		3664f5b826f5688b82470235d1dceef0c9c4c47d.patch:-p1 \
		b4f435a4ecceba0ef3a785dbe8eead6f55f49cc1.patch:-p1 \
		c5c4a54d4cf4ea544c30fe6780dab2755f404300.patch:-p1 \
		f47e7bd666aa063d016bdf00ea8f62c97a5b5a7a.patch:-p1

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Exif, IPTC, and XMP metadata manipulation library and tools
WWW=		https://www.exiv2.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libbrotlidec.so:archivers/brotli \
		libexpat.so:textproc/expat2 \
		libinih.so:devel/inih \
		libpng.so:graphics/png

USES=		cmake compiler:c++17-lang cpe dos2unix gettext-tools iconv \
		localbase:ldflags pathfix shebangfix
DOS2UNIX_FILES=	cmake/compilerFlags.cmake
USE_LDCONFIG=	yes
SHEBANG_FILES=	fuzz/mkdictionary.py tests/runner.py

CMAKE_ARGS=	-DPython${PYTHON_MAJOR_VER}_EXECUTABLE:FILEPATH="${PYTHON_CMD}"

CMAKE_ON=	EXIV2_ENABLE_VIDEO
CMAKE_OFF=	EXIV2_ENABLE_EXTERNAL_XMP

LDFLAGS_mips=	-lintl
LDFLAGS_mips64=	-lintl

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}-Source

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
TEST_LIB_DEPENDS=	libgtest.so:devel/googletest
TEST_TEST_DEPENDS=	bash:shells/bash
TEST_USES=		python:build,test
TEST_CMAKE_BOOL=	EXIV2_BUILD_UNIT_TESTS
TEST_TEST_TARGET=	test

.include <bsd.port.mk>
