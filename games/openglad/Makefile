# New ports collection makefile for:  	openglad
# Date created:       		13 May 2003
# Whom:  			Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	openglad
PORTVERSION=	0.98
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	snowstorm

MAINTAINER=	krion@FreeBSD.org
COMMENT=	SDL port of an old DOS game called Gladiator

LIB_DEPENDS=	SDL-1.1.5:${PORTSDIR}/devel/sdl12 \
		SDL_mixer.2:${PORTSDIR}/audio/sdl_mixer

SDL_CONFIG=	${LOCALBASE}/bin/sdl11-config

USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}" \
		CPPFLAGS="-I${X11BASE}/include"
PLIST_SUB=	DOCDIR=share/doc/${PORTNAME}

post-configure:
	${REINPLACE_CMD} -e 's|/path/to/data/dir|${LOCALBASE}/share/openglad|g' \
		${WRKSRC}/openglad.cfg

.include <bsd.port.mk>
