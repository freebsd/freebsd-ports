# New ports collection makefile for:	toppler
# Date created:				18 Jan 2002
# Whom:					Dom Mitchell <dom@happygiraffe.net>
#
# $FreeBSD$
#

PORTNAME=	toppler
PORTVERSION=	0.71
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	toppler

MAINTAINER=	dom@happygiraffe.net

LIB_DEPENDS=	SDL-1.1.4:${PORTSDIR}/devel/sdl12
LIB_DEPENDS+=	SDL_mixer:${PORTSDIR}/audio/sdl_mixer

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}"

SCOREDIR?=	/var/games/${PORTNAME}
SCOREFILE?=	${PORTNAME}.hscr

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
	@find ${WRKSRC} \( -name "*.[ch]" -or -name "*.cc" \) | \
		xargs ${PERL} -pi -e 's|"SDL/SDL|"SDL|g ; s|<SDL/SDL|<SDL|g'

post-patch:
	@${PERL} -pi -e 's|%SCOREDIR%|${SCOREDIR}|g;' \
		-e 's|%SCOREFILE%|${SCOREFILE}|g' ${WRKSRC}/menu.cc

pre-install:
	${MKDIR} ${SCOREDIR}

post-install:
	${CHOWN} root:games ${PREFIX}/bin/${PORTNAME}
	${CHMOD} g+s ${PREFIX}/bin/${PORTNAME}
	${TOUCH} ${SCOREDIR}/${SCOREFILE}
	${CHMOD} 664 ${SCOREDIR}/${SCOREFILE}
	${CHOWN} root:games ${SCOREDIR}/${SCOREFILE}

.include <bsd.port.mk>
