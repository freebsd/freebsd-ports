# New ports collection makefile for:	bomberclone
# Date created:				5 May 2003
# Whom:					Edwin Groothuis
#
# $FreeBSD$
#

PORTNAME=	bomberclone
PORTVERSION=	0.10.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

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
	${RM} -rf ${WRKSRC}/data/tileset/cemetery/.xvpics
	${RM} -rf ${WRKSRC}/data/tileset/hell/.xvpics
	${CHMOD} 755 ${WRKSRC}/data/tileset/cemetery
	${CHMOD} 755 ${WRKSRC}/data/tileset/farm
	${CHMOD} 755 ${WRKSRC}/data/tileset/hell
	${CHMOD} 755 ${WRKSRC}/data/tileset/sheep
	${CHMOD} 755 ${WRKSRC}/data/tileset/supermario

.include <bsd.port.mk>
