PORTNAME=	msl
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.0
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Shader language based off GLSL
WWW=		https://github.com/akb825/ModularShaderLanguage

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	flatc:devel/flatbuffers
LIB_DEPENDS=	libboost_system.so:devel/boost-libs

USES=		cmake:testing compiler:c++11-lang python:3.6+,build

CMAKE_ON=	BUILD_SHARED_LIBS MSL_SHARED
CMAKE_OFF=	SPIRV_TOOLS_BUILD_STATIC
CMAKE_OFF=	MSL_BUILD_TESTS MSL_BUILD_DOCS
CMAKE_TESTING_ON=	MSL_BUILD_TESTS

USE_GITHUB=	yes
GH_ACCOUNT=	akb825
GH_PROJECT=	ModularShaderLanguage

GH_TUPLE=	akb825:glslang:ee363ae487621ba836a8ce3ad0759b3dcba5fc90:akb825_glslang/Compile/glslang \
		KhronosGroup:SPIRV-Cross:81ba8f78f6646e5635129bd738f25bb3f43bbdb9:KhronosGroup_SPIRV_Cross/Compile/SPIRV-Cross \
		akb825:SPIRV-Tools:056da37af83cbb0b0aeaf459ef2e43fc599bb79a:akb825_SPIRV_Tools/Compile/SPIRV-Tools \
		KhronosGroup:SPIRV-Headers:4995a2f2723c401eb0ea3e10c81298906bf1422b:KhronosGroup_SPIRV_Headers/Compile/SPIRV-Tools/external/SPIRV-Headers \

.include <bsd.port.mk>
