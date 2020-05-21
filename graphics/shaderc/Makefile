# $FreeBSD$

PORTNAME=	shaderc
DISTVERSIONPREFIX=v
DISTVERSION=	2020.0
CATEGORIES=	graphics devel

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	21c8be385b3f.patch:-p1 # https://github.com/google/shaderc/pull/463

MAINTAINER=	greg@unrelenting.technology
COMMENT=	GLSL/HLSL to SPIR-V shader compiler

LICENSE=	APACHE20

BUILD_DEPENDS=	${LOCALBASE}/lib/libSPIRV-Tools-opt.a:devel/spirv-tools \
		${LOCALBASE}/lib/libHLSL.a:devel/glslang

USES=		cmake compiler:c++11-lib pkgconfig localbase:ldflags python:build
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	google
GH_TUPLE=	KhronosGroup:SPIRV-Headers:1.5.3:headers/third_party/spirv-headers

CMAKE_ON+=	SHADERC_SKIP_TESTS
CMAKE_ARGS+=	-DSPIRV-Headers_SOURCE_DIR=${WRKSRC}/third_party/spirv-headers

# https://git.archlinux.org/svntogit/packages.git/tree/trunk/PKGBUILD?h=packages/shaderc

post-patch:
	${REINPLACE_CMD} '/examples/d;/third_party/d' ${WRKSRC}/CMakeLists.txt
	${REINPLACE_CMD} '/build-version/d' ${WRKSRC}/glslc/CMakeLists.txt
	${ECHO} "\"${DISTVERSIONFULL}\"" > ${WRKSRC}/glslc/src/build-version.inc

.include <bsd.port.mk>
