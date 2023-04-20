PORTNAME=	vulkan-extension-layer
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.248
CATEGORIES=	graphics

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	62c6b62d0766.patch:-p1 # https://github.com/KhronosGroup/Vulkan-ExtensionLayer/pull/207

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

post-install:
# https://github.com/KhronosGroup/Vulkan-ExtensionLayer/commit/bd02fcde74f1
	@if [ `${CC} -dM -E -</dev/null | ${AWK} '/__SIZEOF_POINTER__/ { print $$3 }'` -eq 4 ]; then \
		${REINPLACE_CMD} '/shader_object/d' ${TMPPLIST}; \
	fi

.include <bsd.port.mk>
