# $FreeBSD$

PORTNAME=	Open3D
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2
PORTREVISION=	3
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Modern library for 3D data processing

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/../LICENSE

LIB_DEPENDS=	libglfw.so:graphics/glfw \
		libjsoncpp.so:devel/jsoncpp \
		libpng16.so:graphics/png

USES=		cmake compiler:c++14-lang eigen:3 jpeg localbase:ldflags pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	IntelVCL
USE_GL=		gl glew glu
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BUILD_TESTS BUILD_PYBIND11 BUILD_PYTHON_MODULE BUILD_PYTHON_TUTORIALS

WRKSRC_SUBDIR=	src
LDFLAGS+=	-pthread # https://github.com/IntelVCL/Open3D/issues/510

post-install: # https://github.com/IntelVCL/Open3D/issues/509
.for d in include/Open3D/IO/FileFormat include/Open3D/Visualization/Shader/GLSL
	@${RMDIR} ${STAGEDIR}${PREFIX}/${d}
.endfor

.include <bsd.port.mk>
