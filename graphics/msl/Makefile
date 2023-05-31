PORTNAME=	msl
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.3
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Shader language based off GLSL
WWW=		https://github.com/akb825/ModularShaderLanguage

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	flatc:devel/flatbuffers
LIB_DEPENDS=	libboost_system.so:devel/boost-libs

USES=		cmake:testing compiler:c++14-lang python:3.6+,build

CMAKE_ON=	BUILD_SHARED_LIBS MSL_SHARED
CMAKE_OFF=	SPIRV_TOOLS_BUILD_STATIC
CMAKE_OFF=	MSL_BUILD_TESTS MSL_BUILD_DOCS
CMAKE_ARGS=	-DFREEBSD_PYTHON_VER=${PYTHON_VER}
CMAKE_TESTING_ON=	MSL_BUILD_TESTS

USE_GITHUB=	yes
GH_ACCOUNT=	akb825
GH_PROJECT=	ModularShaderLanguage

GH_TUPLE=	akb825:glslang:45234bb:akb825_glslang/Compile/glslang \
		KhronosGroup:SPIRV-Cross:12542fc:KhronosGroup_SPIRV_Cross/Compile/SPIRV-Cross \
		akb825:SPIRV-Tools:0783a8d:akb825_SPIRV_Tools/Compile/SPIRV-Tools \
			KhronosGroup:SPIRV-Headers:aa331ab:KhronosGroup_SPIRV_Headers/Compile/SPIRV-Tools/external/spirv-headers

.include <bsd.port.mk>
