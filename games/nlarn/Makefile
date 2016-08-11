# Created by: Martin Tournoij <martin@arp242.net>
# $FreeBSD$

PORTNAME=	nlarn
PORTVERSION=	0.7.2
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	tz@FreeBSD.org
COMMENT=	Roguelike game and as such a remake of the classic game Larn

LICENSE=	GPLv3

USES=		gmake lua:51 pkgconfig
USE_GNOME=	glib20

post-configure:
	@${REINPLACE_CMD} 's|/usr/share/nlarn|${DATADIR}|' \
		${WRKSRC}/src/game.c

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/nlarn ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/README.txt ${WRKSRC}/nlarn.ini-sample ${WRKSRC}/lib/* ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
