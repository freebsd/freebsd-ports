# New ports collection makefile for:	ltris
# Date created:				19 October 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ltris
PORTVERSION=	1.0.1
PORTEPOCH=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	lgames

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	SDL_mixer.2:${PORTSDIR}/audio/sdl_mixer

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}"

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
	@find ${WRKSRC} \( -name "*.[ch]" -or -name "*.cpp" \) | \
		xargs ${PERL} -pi -e 's|"SDL/SDL|"SDL|g ; s|<SDL/SDL|<SDL|g'

post-install:
	${CHOWN} root:games ${PREFIX}/bin/${PORTNAME}
	${CHMOD} 2755 ${PREFIX}/bin/${PORTNAME}
	${CHMOD} 664 /var/games/${PORTNAME}/ltris.hscr
	${CHOWN} root:games /var/games/${PORTNAME}/ltris.hscr

.include <bsd.port.mk>
