# New ports collection makefile for:	asc
# Date created:				16 February 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	asc
PORTVERSION=	1.10.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	asc-hq
DISTNAME=	${PORTNAME}-source-${PORTVERSION}

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	SDL-1.1.4:${PORTSDIR}/devel/sdl12 \
		SDL_image.10:${PORTSDIR}/graphics/sdl_image \
		gnugetopt.1:${PORTSDIR}/devel/libgnugetopt \
		SDLmm.8:${PORTSDIR}/devel/sdlmm \
		SDL_mixer.2:${PORTSDIR}/audio/sdl_mixer \
		paragui.3:${PORTSDIR}/x11-toolkits/paragui
.if !exists(/usr/bin/bzip2)
LIB_DEPENDS+=	bz2.1:${PORTSDIR}/archivers/bzip2
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config

USE_GMAKE=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}" \
		CPPFLAGS="`${SDL_CONFIG} --cflags`" \
		LIBS="`${SDL_CONFIG} --libs` -lgnugetopt -lm"

pre-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
	@find ${WRKSRC} \( -name "*.cpp" -or -name "*.h" \) | xargs \
		${REINPLACE_CMD} -e 's|malloc[.]h|stdlib.h|g'

pre-configure:
	@${RM} -f ${WRKSRC}/config.cache

.include <bsd.port.mk>
