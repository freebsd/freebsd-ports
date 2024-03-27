PORTNAME=	msl
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.5
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Shader language based off GLSL
WWW=		https://github.com/akb825/ModularShaderLanguage

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	flatc:devel/flatbuffers
LIB_DEPENDS=	libboost_system.so:devel/boost-libs

USES=		cmake:testing compiler:c++14-lang python:build

CMAKE_ON=	BUILD_SHARED_LIBS MSL_SHARED
CMAKE_OFF=	SPIRV_TOOLS_BUILD_STATIC
CMAKE_OFF=	MSL_BUILD_TESTS MSL_BUILD_DOCS
CMAKE_ARGS=	-DFREEBSD_PYTHON_VER=${PYTHON_VER}
CMAKE_TESTING_ON=	MSL_BUILD_TESTS

USE_GITHUB=	yes
GH_ACCOUNT=	akb825
GH_PROJECT=	ModularShaderLanguage

GH_TUPLE=	akb825:glslang:7429d0e:akb825_glslang/Compile/glslang \
		KhronosGroup:SPIRV-Cross:2a7c818:KhronosGroup_SPIRV_Cross/Compile/SPIRV-Cross \
		akb825:SPIRV-Tools:a864e53:akb825_SPIRV_Tools/Compile/SPIRV-Tools \
			KhronosGroup:SPIRV-Headers:8b246ff:KhronosGroup_SPIRV_Headers/Compile/SPIRV-Tools/external/spirv-headers

.include <bsd.port.mk>
