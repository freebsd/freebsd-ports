PORTNAME=	greed
DISTVERSION=	4.4
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://catb.org/~esr/greed/
PKGNAMESUFFIX=	-game

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Text puzzle game with the aim of clearing the game field
WWW=		http://catb.org/~esr/greed/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		ncurses
SCOREFILE?=	/var/games/greed.hs
CFLAGS+=	-DSCOREFILE=\"${SCOREFILE}\" -DNOTBSD -DRELEASE=\"${DISTVERSION}\"
LDFLAGS+=	-lncurses
PLIST_SUB+=	SCOREFILE=${SCOREFILE}

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -o greed greed.c ${LDFLAGS})
	${REINPLACE_CMD} -e 's|/usr/lib/games/greed.hs|${SCOREFILE}|g' ${WRKSRC}/greed.adoc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/greed ${STAGEDIR}${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/greed.adoc ${STAGEDIR}${DOCSDIR}/README
	@${MKDIR} ${STAGEDIR}${SCOREFILE:H}
	${TOUCH} ${STAGEDIR}${SCOREFILE}.sample

.include <bsd.port.mk>
