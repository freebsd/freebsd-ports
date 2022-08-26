PORTNAME=	lottie
PORTVERSION=	${QT6_VERSION}
CATEGORIES=	graphics
PKGNAMEPREFIX=	qt6-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 6 player software for a certain json-based for 2d animations

BUILD_DEPENDS=	vulkan-headers>0:graphics/vulkan-headers
LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon

USES=		cmake compiler:c++11-lang gl pkgconfig qt-dist:6
USE_GL=		gl opengl
USE_QT=		base declarative websockets

.include <bsd.port.mk>
