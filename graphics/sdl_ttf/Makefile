# Created by: Maxim Sobolev <sobomax@FreeBSD.org>

PORTNAME=	sdl_ttf
PORTVERSION=	2.0.11
PORTREVISION=	8
CATEGORIES=	graphics
MASTER_SITES=	https://www.libsdl.org/projects/SDL_ttf/release/
DISTNAME=	SDL_ttf-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Library to use TrueType fonts to render text in SDL applications

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfreetype.so:print/freetype2

USES=		gmake iconv gl libtool pathfix pkgconfig sdl xorg
USE_SDL=	sdl
USE_XORG=	x11
USE_GL=		gl
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/.libs/glfont ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/.libs/showfont \
		${STAGEDIR}${PREFIX}/bin/sdl-showfont

.include <bsd.port.mk>
