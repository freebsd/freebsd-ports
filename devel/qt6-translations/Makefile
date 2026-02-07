PORTNAME=	translations
DISTVERSION=	${QT6_VERSION}
CATEGORIES=	devel
PKGNAMEPREFIX=	qt6-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 6 translation module

BUILD_DEPENDS=	${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers

USES=		cmake compiler:c++17-lang \
		qt-dist:6
USE_QT=		base tools
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

NO_ARCH=	yes

.include <bsd.port.mk>
