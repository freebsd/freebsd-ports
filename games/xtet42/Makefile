# Created by: gmarco@giovannelli.it
# $FreeBSD$

PORTNAME=	xtet42
PORTVERSION=	2.21
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	http://utenti.gufi.org/~gmarco/files/distfiles/

MAINTAINER=	gmarco@giovannelli.it
COMMENT=	One or two player T*tris game

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var/games
USES=		xorg
USE_XORG=	x11
ALL_TARGET=	${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xtet42 ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xtet42.6 ${STAGEDIR}${MANPREFIX}/man/man6
	@${MKDIR} ${STAGEDIR}/var/games/xtet42
	${INSTALL_DATA} ${WRKSRC}/xtet42.hiscore ${STAGEDIR}/var/games/xtet42/.xtet42.hiscore.sample
	${INSTALL_DATA} ${WRKSRC}/xtet42.hiscore.single ${STAGEDIR}/var/games/xtet42/.xtet42.hiscore.single.sample
	${INSTALL_DATA} /dev/null ${STAGEDIR}/var/games/xtet42/.xtet42.unlock.sample
	${INSTALL_DATA} /dev/null ${STAGEDIR}/var/games/xtet42/.xtet42.log.sample

.include <bsd.port.mk>
