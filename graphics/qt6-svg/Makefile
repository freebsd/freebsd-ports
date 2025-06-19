PORTNAME=	svg
DISTVERSION=	${QT6_VERSION}
PORTREVISION=	1
CATEGORIES=	graphics
PKGNAMEPREFIX=	qt6-

PATCH_SITES=	https://github.com/qt/qtsvg/commit/
PATCHFILES+=	07b3434f91c95d196f687c51e1a58a95a0b1ef2e.patch:-p1 # PR 287659

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt6 classes for displaying the contents of SVG files

BUILD_DEPENDS=	${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers
LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon

USES=		cmake compiler:c++17-lang gl \
		qt-dist:6
USE_GL=		opengl
USE_QT=		base
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

.include <bsd.port.mk>
