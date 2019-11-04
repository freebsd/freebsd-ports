# $FreeBSD$

PORTNAME=	vulkan-tools
DISTVERSIONPREFIX=	sdk-
DISTVERSION=	1.1.108.0
PORTREVISION=	1
CATEGORIES=	devel graphics

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Tools and demos for the Vulkan graphics API

LICENSE=	APACHE20

BUILD_DEPENDS=	${LOCALBASE}/include/vulkan/vulkan.h:devel/vulkan-headers \
		glslangValidator:devel/glslang
LIB_DEPENDS=	libvulkan.so:graphics/vulkan-loader

USES=		cmake compiler:c++11-lib pkgconfig python:3.4+,build xorg
USE_XORG=	x11 xcb xrandr sm ice xext

USE_GITHUB=	yes
GH_ACCOUNT=	KhronosGroup
GH_PROJECT=	Vulkan-Tools

CMAKE_OFF=	BUILD_TESTS BUILD_ICD \
		BUILD_WSI_WAYLAND_SUPPORT
CMAKE_ARGS=	-DGLSLANG_INSTALL_DIR=${LOCALBASE}

.include <bsd.port.mk>
