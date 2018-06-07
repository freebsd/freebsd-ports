# Created by: Stephen Hurd <shurd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	freedink-data
PORTVERSION=	1.08.${PORTVER}
CATEGORIES=	games
MASTER_SITES=	GNU/freedink

MAINTAINER=	shurd@FreeBSD.org
COMMENT=	Game data for games/freedink (Dink Smallwood)

USES=		gettext gmake
NO_BUILD=	yes

PORTVER=	20170409

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
