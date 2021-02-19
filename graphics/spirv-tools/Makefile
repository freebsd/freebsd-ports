# $FreeBSD$

PORTNAME=	spirv-tools
DISTVERSIONPREFIX=	v
DISTVERSION=	2020.7
CATEGORIES=	graphics

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Tools for processing SPIR-V intermediate shader language modules

LICENSE=	APACHE20

USES=		cmake compiler:c++11-lib python:3.4+,build shebangfix
USE_LDCONFIG=	yes
SHEBANG_FILES=	tools/lesspipe/spirv-lesspipe.sh

USE_GITHUB=	yes
GH_ACCOUNT=	KhronosGroup
GH_PROJECT=	SPIRV-Tools
GH_TUPLE=	KhronosGroup:SPIRV-Headers:1.5.4.raytracing.fixed-29-g75b30a6:headers/external/spirv-headers

CMAKE_ON=	SPIRV_SKIP_TESTS
CMAKE_OFF=	SPIRV_WERROR

.include <bsd.port.mk>
