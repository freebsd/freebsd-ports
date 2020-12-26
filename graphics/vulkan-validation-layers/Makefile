# $FreeBSD$

PORTNAME=	vulkan-validation-layers
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.162
CATEGORIES=	graphics

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Validation layers for the Vulkan graphics API

LICENSE=	APACHE20

# NOTE: keep spirv-tools and glslang up to date when updating Vulkan
BUILD_DEPENDS=	${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers \
		${LOCALBASE}/include/spirv-tools/libspirv.h:graphics/spirv-tools \
		${LOCALBASE}/include/glslang/SPIRV/spirv.hpp:graphics/glslang

USES=		cmake compiler:c++11-lib pkgconfig python:3.4+,build
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	KhronosGroup
GH_PROJECT=	Vulkan-ValidationLayers
GH_TUPLE=	KhronosGroup:SPIRV-Headers:1.5.4.raytracing.fixed:headers/external/spirv-headers

# WSI_* in here are leftover from when all of Vulkan SDK was in one repo
CMAKE_OFF=	BUILD_TESTS ${WAYLAND XCB XLIB:L:C/.*/BUILD_WSI_&_SUPPORT/}
CMAKE_ON=	BUILD_LAYER_SUPPORT_FILES
CMAKE_ARGS=	-DGLSLANG_INSTALL_DIR:PATH="${LOCALBASE}" \
		-DSPIRV_HEADERS_INSTALL_DIR:PATH="${WRKSRC_headers}"

.include <bsd.port.mk>
