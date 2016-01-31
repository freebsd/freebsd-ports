# Created by: Andrey Zakhvatov <andy@icc.surw.chel.su>
# $FreeBSD$

PORTNAME=	omega
PORTVERSION=	0.90.4
CATEGORIES=	games
MASTER_SITES=	http://www.alcyone.com/binaries/omega/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Complex rogue-style game of dungeon exploration

USES=		gmake ncurses
WRKSRC=		${WRKDIR}/${PORTNAME}
ALL_TARGET=	# empty
CFLAGS+=	-Wno-return-type

MYPORTDOCS=	buglist.txt docs/compile.all docs/omega.txt docs/readme.1st \
		docs/readme3 docs/readme4

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/omega ${STAGEDIR}${PREFIX}/bin/omega-game
	${INSTALL_MAN} ${WRKSRC}/docs/omega.6 ${STAGEDIR}${MANPREFIX}/man/man6
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/lib/* ${STAGEDIR}${DATADIR}
	${CP} ${STAGEDIR}${DATADIR}/omega.hi ${STAGEDIR}${DATADIR}/omegahi.bak
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${MYPORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
