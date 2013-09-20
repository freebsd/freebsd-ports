# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sdl_ttf
PORTVERSION=	2.0.11
CATEGORIES=	graphics
MASTER_SITES=	http://www.libsdl.org/projects/SDL_ttf/release/
DISTNAME=	SDL_ttf-${PORTVERSION}

MAINTAINER=	mva@FreeBSD.org
COMMENT=	A library to use TrueType fonts to render text in SDL applications

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2

USE_AUTOTOOLS=	libtool
USE_SDL=	sdl
USES=		gmake pathfix pkgconfig
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes

.if !defined(WITHOUT_X11) && !defined(WITHOUT_GL)
USE_GL=		yes
.endif

NO_STAGE=	yes
post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/.libs/glfont ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/.libs/showfont ${PREFIX}/bin/sdl-showfont

.include <bsd.port.mk>
