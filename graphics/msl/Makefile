PORTNAME=	msl
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.1
PORTREVISION=	3
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
CMAKE_TESTING_ON=	MSL_BUILD_TESTS

USE_GITHUB=	yes
GH_ACCOUNT=	akb825
GH_PROJECT=	ModularShaderLanguage

GH_TUPLE=	akb825:glslang:1e4bae6:akb825_glslang/Compile/glslang \
		akb825:SPIRV-Tools:056da37:akb825_SPIRV_Tools/Compile/SPIRV-Tools \
		KhronosGroup:SPIRV-Cross:f09ba27:KhronosGroup_SPIRV_Cross/Compile/SPIRV-Cross \
		KhronosGroup:SPIRV-Headers:4995a2f:KhronosGroup_SPIRV_Headers/Compile/SPIRV-Tools/external/SPIRV-Headers

.include <bsd.port.mk>
