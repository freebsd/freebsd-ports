PORTNAME=	sdl2_gpu
DISTVERSIONPREFIX=	v
DISTVERSION=	0.12.0
CATEGORIES=	graphics

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Hardware-accelerated 2D graphics library
WWW=		https://github.com/grimfang4/sdl-gpu

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake gl sdl pkgconfig
USE_LDCONFIG=	yes
USE_GL=		gl glew glu
USE_SDL=	sdl2
USE_GITHUB=	yes
GH_ACCOUNT=	grimfang4
GH_PROJECT=	sdl-gpu

CMAKE_ON=	USE_SYSTEM_GLEW DYNAMIC_GLES_3
CFLAGS+=	-Wno-incompatible-function-pointer-types

OPTIONS_DEFINE=	DOCS
DOCS_CMAKE_BOOL=	BUILD_DOCS
DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen
DOCS_ALL_TARGET=	doc

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${BUILD_WRKSRC} && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
