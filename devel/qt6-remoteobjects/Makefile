PORTNAME=	remoteobjects
DISTVERSION=	${QT6_VERSION}
CATEGORIES=	devel
PKGNAMEPREFIX=	qt6-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt6 Remote Objects module

BUILD_DEPENDS=	vulkan-headers>0:graphics/vulkan-headers

USES=		cmake compiler:c++17-lang gl pkgconfig qt-dist:6
USE_GL=		opengl
USE_QT=		base declarative

.include <bsd.port.mk>
