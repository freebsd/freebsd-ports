# New ports collection makefile for:	asc
# Date created:				16 February 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	asc
PORTVERSION=	1.13.7
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	asc-hq
DISTNAME=	${PORTNAME}-source-${PORTVERSION}

.if defined(WITH_MUSIC)
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} frontiers.mp3 time_to_strike.mp3 machine_wars.mp3
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
.endif

MAINTAINER=	yinjieh@csie.nctu.edu.tw
COMMENT=	A turn based, multiplayer strategic game with very nice graphics

LIB_DEPENDS=	SDL-1.1.5:${PORTSDIR}/devel/sdl12 \
		SDL_image.10:${PORTSDIR}/graphics/sdl_image \
		SDLmm.8:${PORTSDIR}/devel/sdlmm \
		SDL_mixer.2:${PORTSDIR}/audio/sdl_mixer \
		paragui.3:${PORTSDIR}/x11-toolkits/paragui

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config

USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_LIBTOOL=	yes
USE_GETOPT_LONG=	yes
CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}" \
		CPPFLAGS="`${SDL_CONFIG} --cflags`" \
		CXXFLAGS="-D_UNICODE_BROKEN_" \
		LIBS="`${SDL_CONFIG} --libs` -lgnugetopt -lm"

CONFIGURE_ARGS=	--disable-paraguitest

.if defined(WITH_MUSIC)
PLIST_SUB+=	MUSIC:=""
.else
PLIST_SUB+=	MUSIC:="@comment "
.endif

pre-configure:
.if defined(WITH_MUSIC)
	${CP}  ${DISTDIR}/frontiers.mp3 ${WRKSRC}/data/music
	${CP}  ${DISTDIR}/time_to_strike.mp3 ${WRKSRC}/data/music
	${CP}  ${DISTDIR}/machine_wars.mp3 ${WRKSRC}/data/music
.endif

pre-build:
	@${FIND} ${WRKSRC}/source -name \*.cpp | ${XARGS} ${REINPLACE_CMD} \
		-e 's|<malloc.h>|<stdlib.h>|'
	@${FIND} ${WRKSRC}/source -name \*.h | ${XARGS} ${REINPLACE_CMD} \
		-e 's|<malloc.h>|<stdlib.h>|'

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
