# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sdl2pp
PORTVERSION=	0.16.0
PORTREVISION=	3
CATEGORIES=	devel

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	C++11 bindings/wrapper for SDL2

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/COPYING.txt

USE_GITHUB=	yes
GH_ACCOUNT=	libSDL2pp
GH_PROJECT=	libSDL2pp

USES=		cmake compiler:c++11-lib sdl
CMAKE_ARGS=	-DSDL2PP_ENABLE_LIVE_TESTS=OFF
USE_SDL=	sdl2 image2 mixer2 ttf2
TEST_TARGET=	test

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS DOXYGEN
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_ALL_TARGET=	all doxygen
DOXYGEN_IMPLIES=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/

post-install-DOXYGEN-on:
	cd ${CONFIGURE_WRKSRC} && ${COPYTREE_SHARE} doxygen ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
