# Created by: Andrey Zakhvatov <andy@icc.surw.chel.su>
# $FreeBSD$

PORTNAME=	omega
PORTVERSION=	0.90.4
CATEGORIES=	games
MASTER_SITES=	http://www.alcyone.com/binaries/omega/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Complex rogue-style game of dungeon exploration

USES=		gmake	# to allow -jX builds (rules with multiple outputs)
WRKSRC=		${WRKDIR}/${PORTNAME}
ALL_TARGET=	# empty
CFLAGS+=	-Wno-return-type
MAN6=		omega.6

MYPORTDOCS=	buglist.txt docs/compile.all docs/omega.txt docs/readme.1st \
		docs/readme3 docs/readme4

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/omega ${PREFIX}/bin/omega-game
	@${CHOWN} root:games ${PREFIX}/bin/omega-game
	@${CHMOD} 2711 ${PREFIX}/bin/omega-game
	${INSTALL_MAN} ${WRKSRC}/docs/omega.6 ${MANPREFIX}/man/man6
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/lib/* ${DATADIR}
	@${RM} ${DATADIR}/license.old
	@${CHMOD} 0460 ${DATADIR}/omega.hi
	@${CHMOD} 0460 ${DATADIR}/omega.log
	${CP} ${DATADIR}/omega.hi ${DATADIR}/omegahi.bak
	@${CHMOD} 0460 ${DATADIR}/omegahi.bak
	@${CHOWN} -R root:games ${DATADIR}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${MYPORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
