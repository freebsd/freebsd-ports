# New ports collection makefile for:	toppler
# Date created:				18 Jan 2002
# Whom:					Dom Mitchell <dom@happygiraffe.net>
#
# $FreeBSD$
#

PORTNAME=	toppler
PORTVERSION=	1.0.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	toppler

MAINTAINER=	dom@happygiraffe.net
COMMENT=	A game where you have to climb the tower and avoid the monsters

LIB_DEPENDS=	SDL-1.1.5:${PORTSDIR}/devel/sdl12
LIB_DEPENDS+=	SDL_mixer:${PORTSDIR}/audio/sdl_mixer

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}"

MAN6=		toppler.6

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} \( -name "*.[ch]" -or -name "*.cc" \) | \
		${XARGS} ${PERL} -pi -e 's|"SDL/SDL|"SDL|g ; s|<SDL/SDL|<SDL|g'

post-install:
	@cd ${WRKSRC} && ${MAKE} global_highscore

.include <bsd.port.mk>
