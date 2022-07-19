PORTNAME=	msl
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.5
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

GH_TUPLE=	akb825:glslang:35ab1219e609c0fa91e04199c458b5379d9c06fd:akb825_glslang/Compile/glslang \
		KhronosGroup:SPIRV-Cross:d8d051381f65b9606fb8016c79b7c3bab872eec3:KhronosGroup_SPIRV_Cross/Compile/SPIRV-Cross \
		akb825:SPIRV-Tools:056da37af83cbb0b0aeaf459ef2e43fc599bb79a:akb825_SPIRV_Tools/Compile/SPIRV-Tools \
		KhronosGroup:SPIRV-Headers:4995a2f2723c401eb0ea3e10c81298906bf1422b:KhronosGroup_SPIRV_Headers/Compile/SPIRV-Tools/external/SPIRV-Headers \

.include <bsd.port.mk>
