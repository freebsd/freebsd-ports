# New ports collection makefile for:	enigma
# Date created:				25 July 2002
# Whom:					Edwin Groothuis
#
# $FreeBSD$
#

PORTNAME=	enigma
PORTVERSION=	0.92
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	enigma
DISTNAME=	enigma-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Enigma is a reimplementation of Oxyd, a puzzle game

LIB_DEPENDS=	zipios.0:${PORTSDIR}/archivers/zipios++

USE_GCC=	3.4
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_LUA=	4.0
LUA_COMPS=	lua tolua
USE_SDL=	gfx image mixer sdl ttf
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--target="" \
		--with-libintl-prefix="${LOCALBASE}"
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" CXXFLAGS="${CXXFLAGS}" \
		LDFLAGS="${LDFLAGS}"
CPPFLAGS=	-I${LOCALBASE}/include -I${LUA_INCDIR}
CXXFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib -L${LUA_LIBDIR} ${PTHREAD_LIBS}

MAN6=		enigma.6

post-extract:
	${RM} -rf ${WRKSRC}/lib-src/lua
	${RM} -rf ${WRKSRC}/lib-src/zipios++

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
