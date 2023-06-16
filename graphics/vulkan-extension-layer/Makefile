PORTNAME=	vulkan-extension-layer
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.254
CATEGORIES=	graphics

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Layer providing Vulkan features when native support is unavailable
WWW=		https://github.com/KhronosGroup/Vulkan-ExtensionLayer

LICENSE=	APACHE20

BUILD_DEPENDS=	vulkan-headers>0:graphics/vulkan-headers

USES=		cmake compiler:c++11-lib
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	KhronosGroup
GH_PROJECT=	Vulkan-ExtensionLayer
CMAKE_OFF=	BUILD_TESTS

.include <bsd.port.mk>
