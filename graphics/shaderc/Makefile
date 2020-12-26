# $FreeBSD$

PORTNAME=	shaderc
DISTVERSIONPREFIX=v
DISTVERSION=	2020.4
PORTREVISION=	1
CATEGORIES=	graphics devel

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	GLSL/HLSL to SPIR-V shader compiler

LICENSE=	APACHE20

BUILD_DEPENDS=	${LOCALBASE}/lib/libHLSL.a:graphics/glslang \
		${LOCALBASE}/lib/libSPIRV-Tools-opt.a:graphics/spirv-tools

USES=		cmake compiler:c++11-lib pkgconfig localbase:ldflags python:build
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	google
GH_TUPLE=	KhronosGroup:SPIRV-Headers:1.5.3:headers/third_party/spirv-headers

CMAKE_ON+=	SHADERC_SKIP_TESTS
CMAKE_ARGS+=	-DSPIRV-Headers_SOURCE_DIR=${WRKSRC}/third_party/spirv-headers
CMAKE_ARGS+=	-Dglslang_SOURCE_DIR=${LOCALBASE}/include/glslang

# https://git.archlinux.org/svntogit/packages.git/tree/trunk/PKGBUILD?h=packages/shaderc

post-patch:
	${REINPLACE_CMD} '/examples/d;/third_party/d' ${WRKSRC}/CMakeLists.txt
	${REINPLACE_CMD} '/build-version/d' ${WRKSRC}/glslc/CMakeLists.txt
	${ECHO} "\"${DISTVERSIONFULL}\"" > ${WRKSRC}/glslc/src/build-version.inc

.include <bsd.port.mk>
