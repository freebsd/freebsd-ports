# New ports collection makefile for:	nuclearchess
# Date Created:				2006-05-26
# Whom:					Shaun Amott <shaun@inerd.com>
#
# $FreeBSD$
#

PORTNAME=	nuclearchess
PORTVERSION=	1.0.0
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	http://www.linux-games.com/nuclearchess/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A chess variant designed to be short and fun for all players

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

USE_SDL=	sdl image
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${DATADIR}
MAKE_JOBS_SAFE=	yes

.include <bsd.port.mk>
