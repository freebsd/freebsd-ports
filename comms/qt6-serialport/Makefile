PORTNAME=	serialport
DISTVERSION=	${QT6_VERSION}
CATEGORIES=	comms
PKGNAMEPREFIX=	qt6-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt functions to access serial ports

BUILD_DEPENDS=	vulkan-headers>0:graphics/vulkan-headers
LIB_DEPENDS=	libudev.so:devel/libudev-devd

USES=		cmake compiler:c++17-lang pkgconfig qt-dist:6
USE_QT=		base

.include <bsd.port.mk>
