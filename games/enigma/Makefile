# New ports collection makefile for:	enigma
# Date created:				25 July 2002
# Whom:					Edwin Groothuis
#
# $FreeBSD$
#

PORTNAME=	enigma
PORTVERSION=	0.81
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://www.rzuser.uni-heidelberg.de/~dheck/ \
		${MASTER_SITE_SAVANNAH}	# savannah is locked temporarely
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	edwin@mavetju.org
COMMENT=	Enigma is a reimplementation of Oxyd, a puzzle game

BUILD_DEPENDS=	lua:${PORTSDIR}/lang/lua

GNU_CONFIGURE=	yes
USE_XLIB=	yes
USE_GMAKE=	yes
USE_SDL=	gfx image mixer sdl
CONFIGURE_ARGS=	--target=""
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}" \
		CXXFLAGS="${PTHREAD_CFLAGS} -I${X11BASE}/include"

MAN6=		enigma.6

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
