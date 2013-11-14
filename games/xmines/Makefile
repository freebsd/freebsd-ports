# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	xmines
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SUNSITE
MASTER_SITE_SUBDIR=	games/strategy
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Minesweeper game for the X Window System

USE_XORG=	x11 xt
CFLAGS+=	-Wno-error=return-type

PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
