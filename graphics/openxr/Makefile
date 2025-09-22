PORTNAME=	openxr
DISTVERSIONPREFIX=	release-
DISTVERSION=	1.1.52
CATEGORIES=	graphics

MAINTAINER=	vvd@FreeBSD.org
COMMENT=	OpenXR provides access to Augmented and Virtual Reality (XR-platforms)
WWW=		https://github.com/KhronosGroup/OpenXR-SDK

LICENSE=	APACHE20

BUILD_DEPENDS=	glslangValidator:graphics/glslang \
		glslc:graphics/shaderc \
		vulkan-headers>0:graphics/vulkan-headers \
		${LOCALBASE}/lib/libvulkan.so:graphics/vulkan-loader \
		${LOCALBASE}/lib/libjsoncpp.a:devel/jsoncpp
RUN_DEPENDS=	vulkan-loader>0:graphics/vulkan-loader

USES=		cmake compiler:c++14-lang gl pathfix python:build
USE_GITHUB=	yes
GH_ACCOUNT=	KhronosGroup
GH_PROJECT=	OpenXR-SDK
USE_GL=		opengl
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_ALL_EXTENSIONS BUILD_WITH_SYSTEM_JSONCPP

.include <bsd.port.mk>
