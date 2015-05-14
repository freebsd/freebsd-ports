# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	sted
PORTVERSION=	0.2.2
CATEGORIES=	editors
MASTER_SITES=	LOCAL/gabor

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple/Small/Stupid Text Editor

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/sted

PORTDOCS=	CHANGES README
PLIST_FILES=	bin/sted man/man1/sted.1.gz

post-patch:
	@${REINPLACE_CMD} -e "s|CC = gcc|CC ?= gcc|" \
			-e "s|C_OPTS = -Wall -O2|C_OPTS = ${CFLAGS}|" \
			${WRKSRC}/Makefile
	@${REINPLACE_CMD} "s|<curses.h>|<ncurses.h>|" ${WRKSRC}/sted.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sted ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/sted.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
