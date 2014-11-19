# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	block
PORTVERSION=	0.6
CATEGORIES=	games
MASTER_SITES=	SUNSITE/games/strategy
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small text based maze game

WRKSRC=		${WRKDIR}/blocks
MAKEFILE=	makefile
ALL_TARGET=	block bed

post-extract:
	@${RM} -f ${WRKSRC}/block
	@${RM} -f ${WRKSRC}/bed

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/block ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bed ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/block.6 ${STAGEDIR}${MAN6PREFIX}/man/man6
	${INSTALL_MAN} ${WRKSRC}/bed.6 ${STAGEDIR}${MAN6PREFIX}/man/man6
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for file in 1 2 3 4 5 6
	${INSTALL_DATA} ${WRKSRC}/${file}.block ${STAGEDIR}${DATADIR}/${file}.block
.endfor

.include <bsd.port.mk>
