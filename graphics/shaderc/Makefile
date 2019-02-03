# $FreeBSD$

PORTNAME=	shaderc
DISTVERSIONPREFIX=v
DISTVERSION=	2018.0
CATEGORIES=	graphics devel

PATCH_SITES=	https://github.com/haasn/${GH_PROJECT}/commit/
PATCHFILES=	21c8be385b3f.patch:-p1

MAINTAINER=	greg@unrelenting.technology
COMMENT=	GLSL/HLSL to SPIR-V shader compiler

LICENSE=	APACHE20

BUILD_DEPENDS=	${LOCALBASE}/lib/libSPIRV-Tools-opt.a:devel/spirv-tools \
		${LOCALBASE}/lib/libHLSL.a:devel/glslang

USES=		cmake compiler:c++11-lib pkgconfig localbase:ldflags python:build
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	google

CMAKE_ON+=	SHADERC_SKIP_TESTS
CMAKE_OFF+=	SHADERC_ENABLE_NV_EXTENSIONS
CMAKE_ARGS+=	-DPYTHON_EXE:STRING="${PYTHON_CMD}"
CFLAGS+=	-Wno-ignored-attributes -Wno-c++11-narrowing

# https://git.archlinux.org/svntogit/packages.git/tree/trunk/PKGBUILD?h=packages/shaderc

post-patch:
	${REINPLACE_CMD} '/examples/d;/third_party/d' ${WRKSRC}/CMakeLists.txt
	${REINPLACE_CMD} '/build-version/d' ${WRKSRC}/glslc/CMakeLists.txt
	${ECHO} "\"${DISTVERSIONFULL}\"" > ${WRKSRC}/glslc/src/build-version.inc

.include <bsd.port.mk>
