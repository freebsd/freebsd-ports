# $FreeBSD$

PORTNAME=	sdl2_ttf
PORTVERSION=	2.0.p2
CATEGORIES=	graphics
MASTER_SITES=	http://www.libsdl.org/tmp/SDL_ttf/release/
DISTNAME=	SDL2_ttf-2.0.12

MAINTAINER=	mva@FreeBSD.org
COMMENT=	A library to use TrueType fonts to render text in SDL applications

LIB_DEPENDS=	freetype:${PORTSDIR}/print/freetype2

USES=		pkgconfig:build pathfix
USE_SDL=	sdl2
USE_AUTOTOOLS=	libtool
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

OPTIONS_DEFINE=	OPENGL

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENGL}
USE_GL=	yes
.endif

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/.libs/glfont ${PREFIX}/bin/sdl2-glfont
	${INSTALL_PROGRAM} ${WRKSRC}/.libs/showfont ${PREFIX}/bin/sdl2-showfont

.include <bsd.port.mk>
