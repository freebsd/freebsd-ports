# New ports collection makefile for:	bomberclone
# Date created:				5 May 2003
# Whom:					Edwin Groothuis
#
# $FreeBSD$
#

PORTNAME=	bomberclone
PORTVERSION=	0.11.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	edwin@mavetju.org
COMMENT=	Reimplementation of Atomic Bomber Man

LIB_DEPENDS=	SDL_mixer.2:${PORTSDIR}/audio/sdl_mixer	\
		SDL_image.10:${PORTSDIR}/graphics/sdl_image

GNU_CONFIGURE=	yes
USE_XLIB=	yes
USE_SDL=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes
CONFIGURE_ARGS=	--target=""
CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}" \
		CXXFLAGS="${PTHREAD_CFLAGS} -I${X11BASE}/include"

.include <bsd.port.mk>
