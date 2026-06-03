PORTNAME=	vulkan-utility-libraries
DISTVERSIONPREFIX=	vulkan-sdk-
DISTVERSION=	1.4.350.0
CATEGORIES=	graphics

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	Utility libraries for Vulkan developers
WWW=		https://github.com/KhronosGroup/Vulkan-Utility-Libraries

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSES/Apache-2.0.txt

BUILD_DEPENDS=	vulkan-headers>0:graphics/vulkan-headers

USES=		cmake compiler:c++11-lib localbase
USE_GITHUB=	yes
GH_ACCOUNT=	KhronosGroup
GH_PROJECT=	Vulkan-Utility-Libraries

.include <bsd.port.mk>
