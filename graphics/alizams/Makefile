PORTNAME=	alizams
DISTVERSIONPREFIX=	v
DISTVERSION=	1.8.3-34
DISTVERSIONSUFFIX=	-ge36859b
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DICOM Viewer
WWW=		https://github.com/AlizaMedicalImaging/AlizaMS

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libITKCommon-${ITK_VER}.so:science/InsightToolkit
TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake:testing desktop-file-utils eigen:3 qt:5 gl
USE_QT=		core gui printsupport sql svg widgets
USE_GL=		gl opengl

USE_GITHUB=	yes
GH_ACCOUNT=	AlizaMedicalImaging
GH_PROJECT=	AlizaMS

CMAKE_ARGS=	-DALIZA_QT_VERSION=5

CXXFLAGS_i386=	-msse2 # to fix this error: always_inline function '_mm_set1_ps' requires target feature 'sse'

.include <../../science/InsightToolkit/Makefile.version>
.include <bsd.port.mk>
