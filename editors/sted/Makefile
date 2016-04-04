# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	sted
PORTVERSION=	0.2.2
CATEGORIES=	editors
MASTER_SITES=	LOCAL/gabor

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple/Small/Stupid Text Editor

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		ncurses
WRKSRC=		${WRKDIR}/sted
MAKE_ARGS=	CC="${CC}" C_OPTS="${CFLAGS}" L_OPTS="${LDFLAGS} -lncurses"

PORTDOCS=	CHANGES README
PLIST_FILES=	bin/sted man/man1/sted.1.gz

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} "s|<curses.h>|<ncurses.h>|" ${WRKSRC}/sted.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sted ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/sted.1 ${STAGEDIR}${MANPREFIX}/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
