# $FreeBSD$

PORTNAME=	vulkan-validation-layers
DISTVERSIONPREFIX=	sdk-
DISTVERSION=	1.2.135.0
CATEGORIES=	devel graphics

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Validation layers for the Vulkan graphics API

LICENSE=	APACHE20

# NOTE: keep spirv-tools and glslang up to date when updating Vulkan
BUILD_DEPENDS=	${LOCALBASE}/include/vulkan/vulkan.h:devel/vulkan-headers \
		${LOCALBASE}/include/spirv-tools/libspirv.h:devel/spirv-tools \
		${LOCALBASE}/include/SPIRV/spirv.hpp:devel/glslang

USES=		cmake compiler:c++11-lib pkgconfig python:3.4+,build
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	KhronosGroup
GH_PROJECT=	Vulkan-ValidationLayers

# WSI_* in here are leftover from when all of Vulkan SDK was in one repo
CMAKE_OFF=	BUILD_TESTS BUILD_WSI_XCB_SUPPORT BUILD_WSI_XLIB_SUPPORT \
		BUILD_WSI_WAYLAND_SUPPORT
CMAKE_ON=	BUILD_LAYER_SUPPORT_FILES
CMAKE_ARGS=	-DGLSLANG_INSTALL_DIR=${LOCALBASE} \
		-DCMAKE_INSTALL_INCLUDEDIR=${LOCALBASE}/include \
		-DCMAKE_BUILD_TYPE=Release

post-install:
# Avoid conflict with devel/xxhash
	@${RM} ${STAGEDIR}${PREFIX}/include/xxhash.*

.include <bsd.port.mk>
