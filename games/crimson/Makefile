# New ports collection makefile for:	crimson
# Date created:				3 May 2001
# Whom:					Jan Jungnickel <jan@jungnickel.com>
#
# $FreeBSD$

PORTNAME=	crimson
PORTVERSION=	0.3.7
CATEGORIES=	games
MASTER_SITES=	http://crimson.seul.org/files/
PKGNAMESUFFIX=	-fields
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	Jan.Stocker@t-online.de
COMMENT=	Tactical war game in the tradition of Battle Isle

LIB_DEPENDS=	SDL_mixer.2:${PORTSDIR}/audio/sdl_mixer

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_SDL=	yes

MAN6=	crimson.6

.include <bsd.port.mk>
