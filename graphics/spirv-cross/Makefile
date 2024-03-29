PORTNAME=	spirv-cross
DISTVERSION=	1.3.280.0
CATEGORIES=	graphics
DISTVERSIONPREFIX=	vulkan-sdk-

MAINTAINER=	vvd@FreeBSD.org
COMMENT=	Tool for parsing and converting SPIR-V to other shader languages
WWW=		https://github.com/KhronosGroup/SPIRV-Cross

LICENSE=	APACHE20

USES=		cmake compiler:c++11-lib python:build

USE_GITHUB=	yes
GH_ACCOUNT=	KhronosGroup
GH_PROJECT=	SPIRV-Cross

CMAKE_ON=	SPIRV_CROSS_SHARED
CMAKE_OFF=	SPIRV_CROSS_ENABLE_TESTS

PORTSCOUT=	limit:^[0-9]{1,3}\.

.include <bsd.port.mk>
