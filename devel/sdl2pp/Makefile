# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sdl2pp
PORTVERSION=	0.13.0
CATEGORIES=	devel

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	C++11 bindings/wrapper for SDL2

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/COPYING.txt

USE_GITHUB=	yes
GH_ACCOUNT=	libSDL2pp
GH_PROJECT=	libSDL2pp

USES=		compiler:c++11-lib cmake
CMAKE_ARGS=	-DSDL2PP_ENABLE_LIVE_TESTS=OFF \
		-DSDL2PP_WITH_WERROR=ON
USE_SDL=	sdl2 image2 mixer2 ttf2
TEST_TARGET=	test

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS DOXYGEN
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_ALL_TARGET=	all doxygen
DOXYGEN_IMPLIES=	DOCS

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == gcc
CXXFLAGS+=	-D_GLIBCXX_USE_C99 # gcc c++11 support is broken on FreeBSD
.endif

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/

post-install-DOXYGEN-on:
	cd ${CONFIGURE_WRKSRC} && ${COPYTREE_SHARE} doxygen ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.post.mk>
