PORTNAME=	imageformats
DISTVERSION=	${QT6_VERSION}
CATEGORIES=	graphics
PKGNAMEPREFIX=	qt6-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt6 plugins for additional image formats: TIFF, MNG, TGA, WBMP

BUILD_DEPENDS=	${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers
LIB_DEPENDS=	libjasper.so:graphics/jasper \
		libmng.so:graphics/libmng \
		libtiff.so:graphics/tiff \
		libwebp.so:graphics/webp

USES=		cmake compiler:c++17-lang gl jpeg pkgconfig \
		qt-dist:6
USE_GL=		opengl
USE_QT=		base
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

.include <bsd.port.mk>
