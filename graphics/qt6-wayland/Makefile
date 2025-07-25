PORTNAME=	wayland
DISTVERSION=	${QT6_VERSION}
PORTREVISION=	1
CATEGORIES=	graphics wayland
PKGNAMEPREFIX=	qt6-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt6 wrapper for Wayland

BUILD_DEPENDS=	${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers
LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon

USES=		cmake compiler:c++17-lang gl pkgconfig \
		qt-dist:6
USE_GL=		opengl egl
USE_QT=		base declarative svg
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

.include <bsd.port.mk>
