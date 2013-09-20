# Created by: Martin Tournoij <martin@arp242.net>
# $FreeBSD$

PORTNAME=	nlarn
PORTVERSION=	0.7.2
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	martin@arp242.net
COMMENT=	Roguelike game and as such a remake of the classic game Larn

LICENSE=	GPLv3

USES=		pkgconfig
USE_LUA=	5.1
USE_GNOME=	glib20
USE_GMAKE=	yes

NO_STAGE=	yes
post-configure:
	@${REINPLACE_CMD} 's|/usr/share/nlarn|${DATADIR}|' \
		${WRKSRC}/src/game.c

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/nlarn ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/README.txt ${WRKSRC}/nlarn.ini-sample ${WRKSRC}/lib/* ${DATADIR}/

.include <bsd.port.mk>
