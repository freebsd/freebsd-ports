# New ports collection makefile for:	oilwar
# Date created:				18 April 2003
# Whom:				Hendrik Scholz <hendrik@scholz.net>
#
# $FreeBSD$
#

PORTNAME=	oilwar
PORTVERSION=	1.2.1
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://www.2ndpoint.fi/projektit/filut/
DISTNAME=	OilWar-${PORTVERSION}

MAINTAINER=	hendrik@scholz.net
COMMENT=	Evil army wants to steal your oil

USE_SDL=	image mixer sdl
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|games/oilwar|${PORTNAME}|g ; \
		s|/var/games|\$$\(datadir\)/oilwar|g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
