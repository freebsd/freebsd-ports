# New ports collection makefile for:	lbreakout
# Date created:				19 October 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lbreakout
PORTVERSION=	001018
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	lgames

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	SDL-1.0.2:${PORTSDIR}/devel/sdl

SDL_CONFIG?=	${LOCALBASE}/bin/sdl-config

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-lcompat"

pre-patch:
	@${PERL} -pi -e 's|-lpthread|-pthread|g' ${WRKSRC}/configure
	@find ${WRKSRC} \( -name "*.[ch]" -or -name "*.cpp" \) | \
		xargs ${PERL} -pi -e 's|"SDL/SDL|"SDL|g ; s|<SDL/SDL|<SDL|g'

pre-install:
	${MKDIR} /var/games/${PORTNAME}

post-install:
	${CHOWN} root:games ${PREFIX}/bin/${PORTNAME}
	${CHMOD} 2755 ${PREFIX}/bin/${PORTNAME}
	${CHMOD} 664 /var/games/${PORTNAME}/${PORTNAME}.hscr
	${CHOWN} root:games /var/games/${PORTNAME}/${PORTNAME}.hscr

.include <bsd.port.mk>
