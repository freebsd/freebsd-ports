# New ports collection makefile for:	bomberclone
# Date created:				5 May 2003
# Whom:					Edwin Groothuis
#
# $FreeBSD$
#

PORTNAME=	bomberclone
PORTVERSION=	0.9.9
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.bz2 \
		${PORTNAME}-data-0.7.tar.bz2

MAINTAINER=	edwin@mavetju.org
COMMENT=	Reimplementation of Atomic Bomber Man

BUILD_DEPENDS=	sdl11-config:${PORTSDIR}/devel/sdl12 \
		${BZIP2_CMD}:${PORTSDIR}/archivers/bzip2
LIB_DEPENDS=	SDL_mixer.2:${PORTSDIR}/audio/sdl_mixer	\
		SDL_image.10:${PORTSDIR}/graphics/sdl_image

GNU_CONFIGURE=	yes
USE_XLIB=	yes
USE_REINPLACE=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes
SDL_CONFIG=	${LOCALBASE}/bin/sdl11-config
CONFIGURE_ARGS=	--target=""
CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}" \
		CXXFLAGS="${PTHREAD_CFLAGS} -I${X11BASE}/include"

post-extract:
	${RM} -rf ${WRKDIR}/data/tileset/default/.xvpics

post-install:
	${MKDIR} ${PREFIX}/share/bomberclone
	${CP} -R ${WRKDIR}/data/gfx ${PREFIX}/share/bomberclone
	${CP} -R ${WRKDIR}/data/maps ${PREFIX}/share/bomberclone
	${CP} -R ${WRKDIR}/data/player ${PREFIX}/share/bomberclone
	${CP} -R ${WRKDIR}/data/tileset ${PREFIX}/share/bomberclone

.include <bsd.port.mk>
