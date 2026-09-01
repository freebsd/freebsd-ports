PORTNAME=	openxr
DISTVERSIONPREFIX=	release-
DISTVERSION=	1.1.62
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	vvd@FreeBSD.org
COMMENT=	OpenXR provides access to Augmented and Virtual Reality (XR-platforms)
WWW=		https://github.com/KhronosGroup/OpenXR-SDK

LICENSE=	APACHE20

BUILD_DEPENDS=	glslangValidator:graphics/glslang \
		glslc:graphics/shaderc \
		vulkan-headers>0:graphics/vulkan-headers \
		${LOCALBASE}/lib/libvulkan.so:graphics/vulkan-loader
LIB_DEPENDS=	libjsoncpp.so:devel/jsoncpp
RUN_DEPENDS=	vulkan-loader>0:graphics/vulkan-loader

USES=		cmake compiler:c++17-lang gl pathfix python:build
USE_GITHUB=	yes
GH_ACCOUNT=	KhronosGroup
GH_PROJECT=	OpenXR-SDK
USE_GL=		opengl
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_ALL_EXTENSIONS
CMAKE_OFF=	BUILD_TESTS

EXTRACT_AFTER_ARGS=	--exclude src/cmake/FindJsonCpp.cmake \
			--exclude src/external/jsoncpp \
			--no-same-owner --no-same-permissions

.include <bsd.port.mk>
