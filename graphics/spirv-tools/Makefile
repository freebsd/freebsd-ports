PORTNAME=	spirv-tools
DISTVERSIONPREFIX=	v
DISTVERSION=	2022.1
PORTREVISION=	1
CATEGORIES=	graphics

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	a73e724359a2.patch:-p1 # https://github.com/KhronosGroup/SPIRV-Tools/pull/4683
PATCHFILES+=	20b122b2e0d4.patch:-p1 # https://github.com/KhronosGroup/SPIRV-Tools/pull/4692
PATCHFILES+=	b846f8f1dc2d.patch:-p1 # https://github.com/KhronosGroup/SPIRV-Tools/pull/4690

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Tools for processing SPIR-V intermediate shader language modules

LICENSE=	APACHE20

USES=		cmake compiler:c++11-lib python:3.4+,build shebangfix
USE_LDCONFIG=	yes
SHEBANG_FILES=	tools/lesspipe/spirv-lesspipe.sh

USE_GITHUB=	yes
GH_ACCOUNT=	KhronosGroup
GH_PROJECT=	SPIRV-Tools
GH_TUPLE=	KhronosGroup:SPIRV-Headers:1.5.4.raytracing.fixed-137-gb42ba6d:headers/external/spirv-headers

CMAKE_ON=	SPIRV_SKIP_TESTS
CMAKE_OFF=	SPIRV_WERROR

.include <bsd.port.mk>
