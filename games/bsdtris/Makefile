# Created by: Yonatan <onatan@gmail.com>
# $FreeBSD$

PORTNAME=	bsdtris
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.mavetju.org/download/adopted/
DISTNAME=	${PORTNAME}-01092003

MAINTAINER=	ports@FreeBSD.org
COMMENT=	BSD version of text-based Tetris game

NO_WRKSUBDIR=	yes

post-patch:
	${REINPLACE_CMD} -E "s|%%PREFIX%%|${PREFIX}|" ${WRKSRC}/pathnames.h

.include <bsd.port.mk>
