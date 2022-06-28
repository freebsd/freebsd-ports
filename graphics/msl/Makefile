PORTNAME=	msl
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.3
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Shader language based off GLSL

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

GH_TUPLE=	akb825:glslang:04a12be6bb031aff18b456bfe108f4bffdbf413d:akb825_glslang/Compile/glslang \
		KhronosGroup:SPIRV-Cross:99b59b35288c95fa7352158930cc068705d3c2e3:KhronosGroup_SPIRV_Cross/Compile/SPIRV-Cross \
		akb825:SPIRV-Tools:c80f8b752f50de446cc2408ffbb8572f6008e52b:akb825_SPIRV_Tools/Compile/SPIRV-Tools \
		KhronosGroup:SPIRV-Headers:4995a2f2723c401eb0ea3e10c81298906bf1422b:KhronosGroup_SPIRV_Headers/Compile/SPIRV-Tools/external/SPIRV-Headers \

.include <bsd.port.mk>
