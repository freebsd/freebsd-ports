PORTNAME=	spirv-tools
DISTVERSIONPREFIX=	v
DISTVERSION=	2022.4
PORTREVISION=	1
CATEGORIES=	graphics

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	381e3987b329.patch:-p1 # https://github.com/KhronosGroup/SPIRV-Tools/pull/4961

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Tools for processing SPIR-V intermediate shader language modules
WWW=		https://github.com/KhronosGroup/SPIRV-Tools

LICENSE=	APACHE20

USES=		cmake compiler:c++11-lib python:3.4+,build shebangfix
USE_LDCONFIG=	yes
SHEBANG_FILES=	tools/lesspipe/spirv-lesspipe.sh

USE_GITHUB=	yes
GH_ACCOUNT=	KhronosGroup
GH_PROJECT=	SPIRV-Tools
GH_TUPLE=	KhronosGroup:SPIRV-Headers:1.5.4.raytracing.fixed-187-g85a1ed2:headers/external/spirv-headers

CMAKE_ON=	SPIRV_SKIP_TESTS

.include <bsd.port.mk>
