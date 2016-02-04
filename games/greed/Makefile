# Created by: Mark Pulford <mark@kyne.com.au>
# $FreeBSD$

PORTNAME=	greed
PORTVERSION=	4.1
CATEGORIES=	games
MASTER_SITES=	http://catb.org/~esr/greed/
PKGNAMESUFFIX=	-game

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Text puzzle game with the aim of clearing the game field

LICENSE=	BSD3CLAUSE

USES=		ncurses
SCOREFILE?=	/var/games/greed.hs
CFLAGS+=	-DSCOREFILE=\"${SCOREFILE}\" -DNOTBSD -DRELEASE=\"${PORTVERSION}\"
LDFLAGS+=	-lncurses
PLIST_SUB+=	SCOREFILE=${SCOREFILE}

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -o greed greed.c ${LDFLAGS})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/greed ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/greed.6 ${STAGEDIR}${MAN6PREFIX}/man/man6/
	@${MKDIR} ${STAGEDIR}${SCOREFILE:H}
	${TOUCH} ${STAGEDIR}${SCOREFILE}.sample

.include <bsd.port.mk>
