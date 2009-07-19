# New ports collection makefile for:	nuclearchess
# Date Created:				2006-05-26
# Whom:					Shaun Amott <shaun@inerd.com>
#
# $FreeBSD$
#

PORTNAME=	nuclearchess
PORTVERSION=	1.0.0
CATEGORIES=	games
MASTER_SITES=	http://user.cs.tu-berlin.de/~karlb/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A chess variant designed to be short and fun for all players

GNU_CONFIGURE=	yes

USE_SDL=	sdl image

CONFIGURE_ARGS=	--prefix=${PREFIX}		\
		--localstatedir=${DATADIR}	\
		--program-prefix=

.include <bsd.port.mk>
