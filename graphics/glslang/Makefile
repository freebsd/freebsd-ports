PORTNAME=	glslang
DISTVERSION=	14.0.0
CATEGORIES=	graphics

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	OpenGL and OpenGL ES shader front end and validator
WWW=		https://www.khronos.org/opengles/sdk/tools/Reference-Compiler/

LICENSE=	APACHE20 BSD2CLAUSE BSD3CLAUSE GPLv3+ MIT
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake:testing compiler:c++11-lib python:build
USE_GITHUB=	yes
GH_ACCOUNT=	KhronosGroup
CMAKE_ON=	ALLOW_EXTERNAL_SPIRV_TOOLS

.include <bsd.port.mk>
