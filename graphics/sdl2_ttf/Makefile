# $FreeBSD$

PORTNAME=	sdl2_ttf
PORTVERSION=	2.0.14
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.libsdl.org/projects/SDL_ttf/release/
DISTNAME=	SDL2_ttf-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Library to use TrueType fonts to render text in SDL applications

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/COPYING.txt

LIB_DEPENDS=	libfreetype.so:print/freetype2

USES=		pkgconfig:build pathfix gmake libtool localbase
USE_SDL=	sdl2
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	OPENGL

OPENGL_USE=	GL=yes

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/.libs/glfont ${STAGEDIR}${PREFIX}/bin/sdl2-glfont
	${INSTALL_PROGRAM} ${WRKSRC}/.libs/showfont ${STAGEDIR}${PREFIX}/bin/sdl2-showfont

.include <bsd.port.mk>
