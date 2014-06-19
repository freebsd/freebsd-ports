# Created by: Stephen Hurd <shurd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	freedink-data
PORTVERSION=	1.08.${PORTVER}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	freedink

MAINTAINER=	shurd@FreeBSD.org
COMMENT=	Game data for games/freedink (Dink Smallwood)

USES=		gettext gmake
NO_BUILD=	yes

PORTVER=	20121209

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
