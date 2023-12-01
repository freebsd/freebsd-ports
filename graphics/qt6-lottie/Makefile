PORTNAME=	lottie
DISTVERSION=	${QT6_VERSION}
CATEGORIES=	graphics
PKGNAMEPREFIX=	qt6-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	QML API for rendering graphics and animations

BUILD_DEPENDS=	vulkan-headers>0:graphics/vulkan-headers
LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon

USES=		cmake compiler:c++17-lang gl pkgconfig qt-dist:6
USE_GL=		opengl
USE_QT=		base declarative

.include <bsd.port.mk>
