# Ports collection makefile for:  hspell
# Date created:	                  01 Apr 2003
# Whom:                           Yonatan <Yonatan@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	tetris
PORTVERSION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.mavetju.org/download/adopted/
DISTNAME=	${PORTNAME}-01042003

MAINTAINER=	yonatan@xpert.com
COMMENT=	Text-based tetris game

NO_WRKSUBDIR=	yes
USE_REINPLACE=	yes

MAN6=		tetris.6

post-patch:
	${REINPLACE_CMD} -E "s|%%PREFIX%%|${PREFIX}|" ${WRKSRC}/pathnames.h

post-install:
	${INSTALL_MAN} ${WRKSRC}/tetris.6 ${PREFIX}/man/man6/tetris.6

.include <bsd.port.mk>
