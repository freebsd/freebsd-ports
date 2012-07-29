# ex:ts=8
# Ports collection makefile for:	sudoku
# Date created:			Feb 27, 2006
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	sudoku
PORTVERSION=	1.0.2
CATEGORIES=	games
MASTER_SITES=	http://chipstips.com/download/
EXTRACT_SUFX=	.tbz

MAINTAINER=	sterling@camdensoftware.com
COMMENT=	Console based Sudoku games

USE_BZIP2=	yes
USE_NCURSES=	yes
PLIST_FILES=	bin/sudoku \
		share/sudoku/template
PLIST_DIRS=	share/sudoku

MAN6=	sudoku.6

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

post-patch:
	@${GREP} -lR "/usr/lib/sudoku" ${WRKSRC} | ${XARGS} \
		${REINPLACE_CMD} -e "s,/usr/lib/sudoku,${DATADIR},"

do-build:
	@cd ${WRKSRC} && ${CC} ${CFLAGS} -o ${PORTNAME} sudoku.c -lcurses

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/${MAN6} ${MAN6PREFIX}/man/man6
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/template ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/sudoku.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
