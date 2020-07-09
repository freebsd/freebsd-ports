# Created by: Michael Johnson <ahze@ahze.net>
# $FreeBSD$

PORTNAME=	exiv2
DISTVERSION=	0.27.3
DISTVERSIONSUFFIX=	-Source
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	https://www.exiv2.org/builds/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Exif, IPTC, and XMP metadata manipulation library and tools

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libexpat.so:textproc/expat2
TEST_DEPENDS=	bash:shells/bash

USES=		cmake compiler:c++11-lang cpe dos2unix gettext iconv pathfix \
		python:3.5+,test localbase:ldflags
USE_LDCONFIG=	yes
DOS2UNIX_FILES=	cmake/compilerFlags.cmake

TEST_TARGET=	tests

LDFLAGS+=	-lintl

CMAKE_ON=	EXIV2_ENABLE_VIDEO \
		EXIV2_ENABLE_NLS
CMAKE_OFF=	EXIV2_ENABLE_LIBXMP

OPTIONS_DEFINE=	SAMPLE TEST
OPTIONS_SUB=	yes
TEST_IMPLIES=	SAMPLE

SAMPLE_DESC=	Include sample applications
SAMPLE_CMAKE_BOOL=	EXIV2_BUILD_SAMPLES

TEST_CMAKE_BOOL=	EXIV2_BUILD_UNIT_TESTS

PATHFIX_CMAKELISTSTXT=	CMakeChecks.txt

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-Source

post-patch:
	@${REINPLACE_CMD} -e 's|python3|${PYTHON_CMD}|' \
		${WRKSRC}/test/Makefile
	@${REINPLACE_CMD} -e 's|python3|${PYTHON_CMD}|' \
		${WRKSRC}/test/functions.source

.include <bsd.port.mk>
