PORTNAME=	3d
DISTVERSION=	${QT6_VERSION}
CATEGORIES=	graphics
PKGNAMEPREFIX=	qt6-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	C++ and QML APIs for easy inclusion of 3D graphics

BUILD_DEPENDS=	${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers
LIB_DEPENDS=	libassimp.so:multimedia/assimp \
		libxkbcommon.so:x11/libxkbcommon

USES=		cmake compiler:c++17-lang gl python:build \
		pkgconfig qt-dist:6
USE_GL=		opengl
USE_QT=		base declarative shadertools
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64 || ${ARCH} == i386
PLIST_SUB+=	SIMD=""
.else
PLIST_SUB+=	SIMD="@comment "
.endif

.include <bsd.port.post.mk>
