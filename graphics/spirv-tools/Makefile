PORTNAME=	spirv-tools
DISTVERSIONPREFIX=	v
DISTVERSION=	2021.3
PORTREVISION=	1
CATEGORIES=	graphics

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	ee30773650ec.patch:-p1 # https://github.com/KhronosGroup/SPIRV-Tools/pull/4492
PATCHFILES+=	bd3a271ce3fc.patch:-p1 # https://github.com/KhronosGroup/SPIRV-Tools/pull/4495
PATCHFILES+=	4ac8e5e541ea.patch:-p1 # https://github.com/KhronosGroup/SPIRV-Tools/pull/4520

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Tools for processing SPIR-V intermediate shader language modules

LICENSE=	APACHE20

USES=		cmake compiler:c++11-lib python:3.4+,build shebangfix
USE_LDCONFIG=	yes
SHEBANG_FILES=	tools/lesspipe/spirv-lesspipe.sh

USE_GITHUB=	yes
GH_ACCOUNT=	KhronosGroup
GH_PROJECT=	SPIRV-Tools
GH_TUPLE=	KhronosGroup:SPIRV-Headers:1.5.4.raytracing.fixed-98-g449bc98:headers/external/spirv-headers

CMAKE_ON=	SPIRV_SKIP_TESTS
CMAKE_OFF=	SPIRV_WERROR

.include <bsd.port.mk>
