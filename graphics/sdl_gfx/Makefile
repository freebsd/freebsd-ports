# ex:ts=8
# Ports collection makefile for:	sdl_gfx
# Date created:			Apr 25, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	sdl_gfx
PORTVERSION=	2.0.9
CATEGORIES=	graphics
MASTER_SITES=	http://www.ferzkopp.net/Software/%SUBDIR%/
MASTER_SITE_SUBDIR=	SDL_gfx-${PORTVERSION:R}
DISTNAME=	SDL_gfx-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SDL graphics drawing primitives and other support functions

USE_SDL=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--disable-mmx
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.if defined(WITH_MMX) && (${ARCH} == "i386")
CFLAGS+=	-DUSE_MMX
.endif

post-patch:
	@${REINPLACE_CMD} 's|^libSDL_gfxincludedir.*|&/SDL11|' \
		${WRKSRC}/Makefile.in
.for file in configure SDL_gfxPrimitives.h SDL_framerate.h SDL_rotozoom.h
	@${REINPLACE_CMD} 's|<SDL/SDL|<SDL|g' ${WRKSRC}/${file}
.endfor

.include <bsd.port.post.mk>
