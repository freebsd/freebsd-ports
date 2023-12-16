PORTNAME=	positioning
DISTVERSION=	${QT6_VERSION}
CATEGORIES=	devel
PKGNAMEPREFIX=	qt6-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 6 API to provide positioning information via QML and C++

BUILD_DEPENDS=	vulkan-headers>0:graphics/vulkan-headers
LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon

USES=		cmake compiler:c++17-lang gl pkgconfig qt-dist:6
USE_GL=		opengl
USE_QT=		base declarative serialport

.include <bsd.port.mk>
