# Created by: Mark Pulford <mark@kyne.com.au>
# $FreeBSD$

PORTNAME=	greed
PORTVERSION=	3.10
CATEGORIES=	games
MASTER_SITES=	http://catb.org/~esr/greed/ CENKES
PKGNAMESUFFIX=	-game

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Text puzzle game with the aim of clearing the game field

LICENSE=	BSD3CLAUSE

SCOREFILE?=	/var/games/greed.hs
CFLAGS+=	-DSCOREFILE=\"${SCOREFILE}\" -DNOTBSD -DRELEASE=\"${PORTVERSION}\"
LDFLAGS+=	-lcurses
PLIST_SUB+=	SCOREFILE=${SCOREFILE:S|^/||}

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -o greed greed.c ${LDFLAGS})

do-install:
	${INSTALL_PROGRAM} -m 2555 -o root -g games ${WRKSRC}/greed ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/greed.6 ${STAGEDIR}${MAN6PREFIX}/man/man6/
	@${MKDIR} ${STAGEDIR}${SCOREFILE:H}
	${TOUCH} ${STAGEDIR}${SCOREFILE}.sample

.include <bsd.port.mk>
