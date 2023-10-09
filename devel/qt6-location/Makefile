PORTNAME=	location
PORTVERSION=	${QT6_VERSION}
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	qt6-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 6 API to create viable mapping solutions
WWW=		https://qt.io

BUILD_DEPENDS=	vulkan-headers>0:graphics/vulkan-headers
LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon

USES=		cmake compiler:c++17-lang gl pkgconfig qt-dist:6
USE_GL=		gl opengl
USE_QT=		base declarative positioning

.include <bsd.port.mk>
