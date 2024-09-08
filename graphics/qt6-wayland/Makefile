PORTNAME=	wayland
DISTVERSION=	${QT6_VERSION}
PORTREVISION=	1
CATEGORIES=	graphics wayland
PKGNAMEPREFIX=	qt6-

PATCH_SITES=	https://github.com/qt/qtwayland/commit/
PATCHFILES+=	92bcb8f6b7a852c7a5d662fc34de561692a7a454.patch:-p1
PATCHFILES+=	c2f61bc47baacf2e6a44c6c3c4e4cbf0abfa4095.patch:-p1
PATCHFILES+=	406995207eae8d644b6e5262aa716a48c7e471a8.patch:-p1
PATCHFILES+=	632127d7f1d86cba4dd17361f24f9fd70a0ae44c.patch:-p1

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt6 wrapper for Wayland

BUILD_DEPENDS=	${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers
LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon

USES=		cmake compiler:c++17-lang gl pkgconfig \
		qt-dist:6
USE_GL=		opengl egl
USE_QT=		base declarative
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

.include <bsd.port.mk>
