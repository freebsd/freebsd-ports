# New ports collection makefile for:	heroes
# Date created:				15 August 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	heroes
PORTVERSION=	0.5
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	SDL-1.1.2:${PORTSDIR}/devel/sdl-devel \
		mikmod.2:${PORTSDIR}/audio/libmikmod \
		gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

SDL_CONFIG=	${LOCALBASE}/bin/sdl11-config

USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib -lgnugetopt"

MAN6=		heroes.6

post-install:
	@install-info --section="X11 Games" \
		--entry="* heroes: (heroes).           Game of yore similar to the "Tron" and "Nibbles"" \
		${PREFIX}/info/heroes.info ${PREFIX}/info/dir

.include <bsd.port.mk>
