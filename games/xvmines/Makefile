# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	xvmines
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	XCONTRIB/../R5contrib

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple minesweeper game for X Window System

LIB_DEPENDS=	libxview.so:x11-toolkits/xview

OPTIONS_DEFINE=	DOCS

USES=		imake tar:Z
USE_XORG=	x11

PORTDOCS=	Copyright
PLIST_FILES=	bin/xvmines man/man6/xvmines.6.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xvmines ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xvmines.man ${STAGEDIR}${MAN6PREFIX}/man/man6/xvmines.6
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Copyright ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
