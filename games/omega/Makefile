# New ports collection makefile for:	omega
# Date created:				14 May 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	omega
PORTVERSION=	0.90.4
CATEGORIES=	games
MASTER_SITES=	http://www.alcyone.com/binaries/omega/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A complex rogue-style game of dungeon exploration

WRKSRC=		${WRKDIR}/${PORTNAME}
ALL_TARGET=	# empty
MAN6=		omega.6

MYPORTDOCS=	buglist.txt docs/compile.all docs/omega.txt docs/readme.1st \
		docs/readme3 docs/readme4

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/omega ${PREFIX}/bin/omega-game
	@${CHOWN} root:games ${PREFIX}/bin/omega-game
	@${CHMOD} 2711 ${PREFIX}/bin/omega-game
	${INSTALL_MAN} ${WRKSRC}/docs/omega.6 ${PREFIX}/man/man6
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/lib/* ${DATADIR}
	@${RM} ${DATADIR}/license.old
	@${CHMOD} 0460 ${DATADIR}/omega.hi
	@${CHMOD} 0460 ${DATADIR}/omega.log
	${CP} ${DATADIR}/omega.hi ${DATADIR}/omegahi.bak
	@${CHMOD} 0460 ${DATADIR}/omegahi.bak
	@${CHOWN} -R root:games ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${MYPORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
