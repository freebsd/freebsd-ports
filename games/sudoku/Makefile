# Created by: ijliao
# $FreeBSD$

PORTNAME=	sudoku
PORTVERSION=	1.0.2
CATEGORIES=	games
MASTER_SITES=	http://chipstips.com/download/
EXTRACT_SUFX=	.tbz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Console based Sudoku games

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

USES=		ncurses tar:bzip2
PLIST_FILES=	bin/sudoku \
		man/man6/sudoku.6.gz \
		share/sudoku/template
PLIST_DIRS=	share/sudoku
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${GREP} -lR "/usr/lib/sudoku" ${WRKSRC} | ${XARGS} \
		${REINPLACE_CMD} -e "s,/usr/lib/sudoku,${DATADIR},"

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o ${PORTNAME} sudoku.c -lcurses

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/sudoku.6 ${STAGEDIR}${MAN6PREFIX}/man/man6
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/template ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/sudoku.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
