PORTNAME=	glbinding
DISTVERSIONPREFIX=	v
DISTVERSION=	3.5.0
CATEGORIES=	graphics devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ binding for the OpenGL API
WWW=		https://glbinding.org \
		https://github.com/cginternals/glbinding

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libglfw.so:graphics/glfw \
		libgraphene-1.0.so:graphics/graphene \
		libgtk-4.so:x11-toolkits/gtk40 \
		libvulkan.so:graphics/vulkan-loader

USES=		cmake:testing compiler:c++11-lang gl gnome localbase:ldflags pkgconfig qt:5 sdl
USE_GNOME=	cairo gtk30
USE_QT=		core gui widgets buildtools:build qmake:build
USE_GL=		gl glew glu opengl
USE_SDL=	sdl2
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	cginternals

CMAKE_TESTING_ON=	OPTION_BUILD_TESTS

LDFLAGS+=	-lpthread # workaround for https://github.com/cginternals/glbinding/issues/327

CONFLICTS_INSTALL=	mesa-demos # both install bin/glinfo, see https://github.com/cginternals/glbinding/issues/341

# tests fail to compile, see https://github.com/cginternals/glbinding/issues/359

.include <bsd.port.mk>
