# New ports collection makefile for:   dis
# Date created:        14 June 2001
# Whom:                simond@irrelevant.org
#
# $FreeBSD$
#

PORTNAME=	dis
PORTVERSION=	1.0
CATEGORIES=	lang
MASTER_SITES=	http://www.mines.edu/students/b/bolmstea/malbolge/
DISTNAME=	dis

MAINTAINER=    simond@irrelevant.org
COMMENT=	A moderately Infernal programming language

USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|<malloc.h>|<stdlib.h>|g' ${WRKSRC}/dis.c

do-build:
	${CC} ${CFLAGS} ${WRKSRC}/dis.c -o ${WRKSRC}/dis

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dis ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/dis
	${INSTALL_DATA} ${WRKSRC}/dis.txt ${PREFIX}/share/doc/dis
.endif
	${MKDIR} ${PREFIX}/share/examples/dis
	${INSTALL_DATA} ${WRKSRC}/666.dis ${PREFIX}/share/examples/dis
	${INSTALL_DATA} ${WRKSRC}/cat.dis ${PREFIX}/share/examples/dis
	${INSTALL_DATA} ${WRKSRC}/cat_expl.dis ${PREFIX}/share/examples/dis

.include <bsd.port.mk>
