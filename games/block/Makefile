# New ports collection makefile for:	block
# Date created:				10 May 1997
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	block
PORTVERSION=	0.6
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	games/strategy
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small text based maze game

WRKSRC=		${WRKDIR}/blocks
MAKEFILE=	makefile
ALL_TARGET=	block bed
MAN6=		block.6 bed.6

post-extract:
	@${RM} -f ${WRKSRC}/block
	@${RM} -f ${WRKSRC}/bed

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/block ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bed ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/block.6 ${PREFIX}/man/man6
	${INSTALL_MAN} ${WRKSRC}/bed.6 ${PREFIX}/man/man6
	@${MKDIR} ${PREFIX}/share/block
.for file in 1 2 3 4 5 6
	${INSTALL_DATA} ${WRKSRC}/${file}.block ${PREFIX}/share/block/${file}.block
.endfor

.include <bsd.port.mk>
