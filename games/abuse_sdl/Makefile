# New ports collection makefile for:	abuse_sdl
# Date created:				11 May 2002
# Whom:					des
#
# $FreeBSD$
#

PORTNAME=	abuse_sdl
PORTVERSION=	0.6.1
CATEGORIES=	games
MASTER_SITES=	http://www.labyrinth.net.au/~trandor/abuse/files/

MAINTAINER=	des@freebsd.org

LIB_DEPENDS=	SDL-1.1.5:${PORTSDIR}/devel/sdl12:install

USE_GMAKE=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ENV=	CFLAGS="${CFLAGS}" SDL_CONFIG="${LOCALBASE}/bin/sdl11-config"
CONFIGURE_ARGS=	--prefix="${PREFIX}"

MAN6=		abuse-sdl.6

.include <bsd.port.mk>
