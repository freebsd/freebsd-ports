# $FreeBSD$

PORTNAME=	vulkan-validation-layers
DISTVERSIONPREFIX=	sdk-
DISTVERSION=	1.1.82.0
PORTREVISION=	1
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
		BUILD_WSI_WAYLAND_SUPPORT BUILD_WSI_MIR_SUPPORT
CMAKE_ARGS=	-DGLSLANG_INSTALL_DIR=${LOCALBASE}

.include <bsd.port.mk>
