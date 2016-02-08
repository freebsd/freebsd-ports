# Created by: Joel Sutton <sutton@aardvark.apana.org.au>
# $FreeBSD$

PORTNAME=	yahtzee
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SUNSITE/games/strategy
DISTNAME=	${PORTNAME}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Curses version of the dice game for one or more players

USES=		ncurses tar:Z
WRKSRC=		${WRKDIR}/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/yahtzee ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} -m 0755 ${STAGEDIR}/var/games/yahtzee
	${TOUCH} ${STAGEDIR}/var/games/yahtzee/yahtzee.sco.sample

.include <bsd.port.mk>
