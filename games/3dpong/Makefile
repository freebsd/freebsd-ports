# New ports collection makefile for:	3dpong
# Date created:				10 March 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	3dpong
PORTVERSION=	0.4
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.sonic.net/pub/users/nbs/unix/x/3dpong/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X Window 3D Pong game for 1 or 2 players with a ball and paddles

USE_X_PREFIX=	yes
USE_REINPLACE=	yes
MAKEFILE=	makefile

post-patch:
	@${REINPLACE_CMD} -e 's.	chmod .	${CHMOD} .g' \
		${WRKSRC}/makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/3dpong ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/sounds/*.au ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
