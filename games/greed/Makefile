PORTNAME=	greed
PORTVERSION=	4.2
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://catb.org/~esr/greed/
PKGNAMESUFFIX=	-game

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Text puzzle game with the aim of clearing the game field
WWW=		http://catb.org/~esr/greed/

LICENSE=	BSD2CLAUSE

USES=		ncurses
SCOREFILE?=	/var/games/greed.hs
CFLAGS+=	-DSCOREFILE=\"${SCOREFILE}\" -DNOTBSD -DRELEASE=\"${PORTVERSION}\"
LDFLAGS+=	-lncurses
PLIST_SUB+=	SCOREFILE=${SCOREFILE}

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -o greed greed.c ${LDFLAGS})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/greed ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/greed.6 ${STAGEDIR}${PREFIX}/share/man/man6/
	@${MKDIR} ${STAGEDIR}${SCOREFILE:H}
	${TOUCH} ${STAGEDIR}${SCOREFILE}.sample

.include <bsd.port.mk>
