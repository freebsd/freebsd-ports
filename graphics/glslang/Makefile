PORTNAME=	glslang
DISTVERSION=	15.4.0
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OpenGL and OpenGL ES shader front end and validator
WWW=		https://www.khronos.org/opengles/sdk/tools/Reference-Compiler/

LICENSE=	APACHE20 BSD2CLAUSE BSD3CLAUSE GPLv3+ MIT
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	spirv-tools>=2024.4.r2:graphics/spirv-tools
RUN_DEPENDS=	spirv-tools>0:graphics/spirv-tools
TEST_DEPENDS=	bash:shells/bash \
		gmake:devel/gmake

USES=		cmake:testing compiler:c++11-lib python:build
USE_GITHUB=	yes
GH_ACCOUNT=	KhronosGroup
CMAKE_ON=	ALLOW_EXTERNAL_SPIRV_TOOLS

.include <bsd.port.mk>
