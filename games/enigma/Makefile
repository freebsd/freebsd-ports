# New ports collection makefile for:	enigma
# Date created:				25 July 2002
# Whom:					Edwin Groothuis
#
# $FreeBSD$
#

PORTNAME=	enigma
PORTVERSION=	0.90
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://savannah.nongnu.org/download/enigma/
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	enigma-${PORTVERSION}-beta

MAINTAINER=	edwin@mavetju.org
COMMENT=	Enigma is a reimplementation of Oxyd, a puzzle game

BUILD_DEPENDS=	${LOCALBASE}/lib/libzipios.a:${PORTSDIR}/archivers/zipios++
BUILD_DEPENDS+=	${LOCALBASE}/bin/tolua:${PORTSDIR}/lang/tolua4
LIB_DEPENDS=	lua.4:${PORTSDIR}/lang/lua4 \
		SDL_ttf.3:${PORTSDIR}/graphics/sdl_ttf

USE_GCC=	3.4

GNU_CONFIGURE=	yes
USE_XLIB=	yes
USE_GMAKE=	yes
USE_SDL=	gfx image mixer sdl
CONFIGURE_ARGS=	--target=""
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}" \
		CXXFLAGS="${PTHREAD_CFLAGS} -I${X11BASE}/include"

MAN6=		enigma.6

post-extract:
	${RM} -rf ${WRKSRC}/lib-src/lua
	${RM} -rf ${WRKSRC}/lib-src/zipios++

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
