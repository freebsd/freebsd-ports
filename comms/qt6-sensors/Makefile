PORTNAME=	sensors
DISTVERSION=	${QT6_VERSION}
CATEGORIES=	comms
PKGNAMEPREFIX=	qt6-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt sensors module

BUILD_DEPENDS=	vulkan-headers>0:graphics/vulkan-headers

USES=		cmake compiler:c++17-lang pkgconfig qt-dist:6
USE_QT=		base declarative

.include <bsd.port.mk>
