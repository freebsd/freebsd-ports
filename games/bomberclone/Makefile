# New ports collection makefile for:	bomberclone
# Date created:				5 May 2003
# Whom:					Edwin Groothuis
#
# $FreeBSD$
#

PORTNAME=	bomberclone
PORTVERSION=	0.9.7
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTFILES=	${PORTNAME}-${PORTVERSION}.tgz \
		${PORTNAME}-data-0.5.tgz

MAINTAINER=	edwin@mavetju.org
COMMENT=	Reimplementation of Atomic Bomber Man

BUILD_DEPENDS=	sdl11-config:${PORTSDIR}/devel/sdl12
LIB_DEPENDS=	SDL_mixer.2:${PORTSDIR}/audio/sdl_mixer	\
		SDL_image.10:${PORTSDIR}/graphics/sdl_image

GNU_CONFIGURE=	yes
USE_XLIB=	yes
USE_REINPLACE=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
SDL_CONFIG=	${LOCALBASE}/bin/sdl11-config
CONFIGURE_ARGS=	--target=""
CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}" \
		CXXFLAGS="${PTHREAD_CFLAGS} -I${X11BASE}/include"

post-extract:
	${RM} -r ${WRKDIR}/data/bomberclone.gfx/CVS

post-patch:
	${REINPLACE_CMD} -e 's,@@LOCALBASE@@,${LOCALBASE},' \
		${WRKSRC}/src/configuration.c

post-install:
	${CP} -R ${WRKDIR}/data/bomberclone.gfx ${PREFIX}/share

.include <bsd.port.mk>
