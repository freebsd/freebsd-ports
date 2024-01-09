PORTNAME=	alizams
DISTVERSIONPREFIX=	v
DISTVERSION=	1.9.7
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DICOM Viewer
WWW=		https://github.com/AlizaMedicalImaging/AlizaMS

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	compilation fails: use of undeclared identifier '_mm_cvtsd_si64', see https://github.com/InsightSoftwareConsortium/ITK/issues/3771

LIB_DEPENDS=	libITKCommon-${ITK_VER}.so:science/InsightToolkit \
		libvnl.so:misc/vxl
TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake desktop-file-utils eigen:3 qt:5 gl
USE_QT=		core gui printsupport sql svg widgets
USE_GL=		gl opengl

USE_GITHUB=	yes
GH_ACCOUNT=	AlizaMedicalImaging
GH_PROJECT=	AlizaMS

CMAKE_ARGS=	-DALIZA_QT_VERSION=5

.include <bsd.port.options.mk>

.if ${ARCH} != amd64
CMAKE_ARGS+=	-DALIZA_DISABLE_SIMDMATH:BOOL=YES # i386 also needs disabling SIND, see https://github.com/InsightSoftwareConsortium/ITK/issues/3771#issuecomment-1328839390
.endif

.include <../../science/InsightToolkit/Makefile.version>
.include <bsd.port.mk>
