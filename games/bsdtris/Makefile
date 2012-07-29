# Ports collection makefile for:  bsdtris
# Date created:	                  01 Apr 2003
# Whom:                           Yonatan <onatan@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	bsdtris
PORTVERSION=	1.1
CATEGORIES=	games
MASTER_SITES=	http://www.mavetju.org/download/adopted/
DISTNAME=	${PORTNAME}-01092003

MAINTAINER=	onatan@gmail.com
COMMENT=	BSD version of text-based Tetris game

NO_WRKSUBDIR=	yes

MAN6=		bsdtris.6

post-patch:
	${REINPLACE_CMD} -E "s|%%PREFIX%%|${PREFIX}|" ${WRKSRC}/pathnames.h

post-install:
	${INSTALL_MAN} ${WRKSRC}/tetris.6 ${PREFIX}/man/man6/bsdtris.6

.include <bsd.port.mk>
