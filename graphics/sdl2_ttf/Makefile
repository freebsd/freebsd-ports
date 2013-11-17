# $FreeBSD$

PORTNAME=	sdl2_ttf
PORTVERSION=	2.0.12
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://www.libsdl.org/projects/SDL_ttf/release/
DISTNAME=	SDL2_ttf-${PORTVERSION}

MAINTAINER=	mva@FreeBSD.org
COMMENT=	A library to use TrueType fonts to render text in SDL applications

LICENSE=	ZLIB

LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2

USES=		pkgconfig:build pathfix gmake
USE_SDL=	sdl2
USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	OPENGL

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENGL}
USE_GL=	yes
.endif

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/.libs/glfont ${STAGEDIR}${PREFIX}/bin/sdl2-glfont
	${INSTALL_PROGRAM} ${WRKSRC}/.libs/showfont ${STAGEDIR}${PREFIX}/bin/sdl2-showfont

.include <bsd.port.mk>
