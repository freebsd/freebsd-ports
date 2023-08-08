PORTNAME=	glbinding
DISTVERSIONPREFIX=	v
DISTVERSION=	3.3.0
CATEGORIES=	graphics devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ binding for the OpenGL API
WWW=		https://glbinding.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libglfw.so:graphics/glfw

USES=		cmake:testing compiler:c++11-lang gl qt:5
USE_QT=		core gui widgets buildtools:build qmake:build
USE_GL=		gl glew glu opengl
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	cginternals

CMAKE_TESTING_ON=	OPTION_BUILD_TESTS

LDFLAGS+=	-lpthread # workaround for https://github.com/cginternals/glbinding/issues/327

CONFLICTS_INSTALL=	mesa-demos # both install bin/glinfo, see https://github.com/cginternals/glbinding/issues/341

.include <bsd.port.mk>
