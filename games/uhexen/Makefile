# New ports collection makefile for:	uhexen
# Date created:				10 February 2003
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	uhexen
PORTVERSION=	0.601
CATEGORIES=	games
MASTER_SITES=	http://uhexen.sourceforge.net/
DISTNAME=	${PORTNAME}-latest

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yet another port of Hexen, popular game from Raven Softrware

LIB_DEPENDS=	SDL-1.1.5:${PORTSDIR}/devel/sdl12 \
		SDL_mixer.2:${PORTSDIR}/audio/sdl_mixer

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config

USE_X_PREFIX=	yes
USE_GMAKE=	yes
MAKE_ENV=	SDL_CONFIG="${SDL_CONFIG}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/uhexen ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${TOUCH} ${DATADIR}/.keep_me

.include <bsd.port.mk>
