PORTNAME=	sdl2_ttf
PORTVERSION=	2.0.15
CATEGORIES=	graphics
MASTER_SITES=	https://www.libsdl.org/projects/SDL_ttf/release/
DISTNAME=	SDL2_ttf-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Library to use TrueType fonts to render text in SDL applications

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/COPYING.txt

LIB_DEPENDS=	libfreetype.so:print/freetype2

USES=		gmake libtool localbase pathfix pkgconfig sdl
USE_SDL=	sdl2
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	OPENGL
OPTIONS_SUB=	yes

OPENGL_DESC=	Build sdl2-glfont demo program
OPENGL_USES=	gl
OPENGL_USE=	GL=gl

post-patch-OPENGL-off:
	@${REINPLACE_CMD} -e '/have_opengl=yes/d' ${WRKSRC}/configure

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/.libs/showfont ${STAGEDIR}${PREFIX}/bin/sdl2-showfont

post-install-OPENGL-on:
	${INSTALL_PROGRAM} ${WRKSRC}/.libs/glfont ${STAGEDIR}${PREFIX}/bin/sdl2-glfont

.include <bsd.port.mk>
