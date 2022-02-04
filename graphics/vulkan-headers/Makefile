PORTNAME=	vulkan-headers
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.205
CATEGORIES=	graphics

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	b32da5329b50.patch:-p1 # https://github.com/KhronosGroup/Vulkan-Headers/pull/260

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Headers for the Vulkan graphics API

LICENSE=	APACHE20

USES=		cmake
STRIP=		# nothing to strip

USE_GITHUB=	yes
GH_ACCOUNT=	KhronosGroup
GH_PROJECT=	Vulkan-Headers

NO_ARCH=	yes

.include <bsd.port.mk>
