PORTNAME=	spirv-tools
DISTVERSIONPREFIX=	v
DISTVERSION=	2024.1
CATEGORIES=	graphics

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Tools for processing SPIR-V intermediate shader language modules
WWW=		https://github.com/KhronosGroup/SPIRV-Tools

LICENSE=	APACHE20

USES=		cmake compiler:c++11-lib python:build shebangfix
USE_LDCONFIG=	yes
SHEBANG_FILES=	tools/lesspipe/spirv-lesspipe.sh

USE_GITHUB=	yes
GH_ACCOUNT=	KhronosGroup
GH_PROJECT=	SPIRV-Tools
GH_TUPLE=	KhronosGroup:SPIRV-Headers:1.5.4.raytracing.fixed-351-g8b246ff:headers/external/spirv-headers

CMAKE_ON=	SPIRV_SKIP_TESTS

.include <bsd.port.mk>
