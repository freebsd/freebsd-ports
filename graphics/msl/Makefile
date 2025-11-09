PORTNAME=	msl
DISTVERSIONPREFIX=	v
DISTVERSION=	1.8.1
PORTREVISION=	3
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Shader language based off GLSL
WWW=		https://github.com/akb825/ModularShaderLanguage

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	flatc:devel/flatbuffers
LIB_DEPENDS=	libboost_thread.so:devel/boost-libs

USES=		cmake:testing compiler:c++14-lang python:build

CMAKE_ON=	BUILD_SHARED_LIBS MSL_SHARED
CMAKE_OFF=	SPIRV_TOOLS_BUILD_STATIC
CMAKE_OFF=	MSL_BUILD_TESTS MSL_BUILD_DOCS
CMAKE_ARGS=	-DFREEBSD_PYTHON_VER=${PYTHON_VER}
CMAKE_TESTING_ON=	MSL_BUILD_TESTS

USE_GITHUB=	yes
GH_ACCOUNT=	akb825
GH_PROJECT=	ModularShaderLanguage

GH_TUPLE=	akb825:glslang:ec0d2be:akb825_glslang/Compile/glslang \
		KhronosGroup:SPIRV-Cross:5e7db82:KhronosGroup_SPIRV_Cross/Compile/SPIRV-Cross \
		akb825:SPIRV-Tools:0926045:akb825_SPIRV_Tools/Compile/SPIRV-Tools \
			KhronosGroup:SPIRV-Headers:2acb319:KhronosGroup_SPIRV_Headers/Compile/SPIRV-Tools/external/spirv-headers

# tests as of 1.8.1: 100% tests passed, 0 tests failed out of 25

.include <bsd.port.mk>
