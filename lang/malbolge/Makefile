# New ports collection makefile for:   malbolge
# Date created:        14 June 2001
# Whom:                simond@irrelevant.org
#
# $FreeBSD$
#

PORTNAME=	malbolge
PORTVERSION=	1.0
CATEGORIES=	lang
MASTER_SITES=	http://www.mines.edu/students/b/bolmstea/malbolge/
DISTNAME=	malbolge

MAINTAINER=    simond@irrelevant.org
COMMENT=	An Infernal programming language

USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|<malloc.h>|<stdlib.h>|g' ${WRKSRC}/malbolge.c

do-build:
	${CC} ${CFLAGS} ${WRKSRC}/malbolge.c -o ${WRKSRC}/malbolge

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/malbolge ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/malbolge
	${INSTALL_DATA} ${WRKSRC}/malbolge.txt ${PREFIX}/share/doc/malbolge
	${INSTALL_DATA} ${WRKSRC}/malbolge.txt ${WRKSRC}/nop.mal \
		${PREFIX}/share/doc/malbolge
.endif

.include <bsd.port.mk>
