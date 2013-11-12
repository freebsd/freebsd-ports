# Created by: Jim Mock <jim@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wmtictactoe
PORTVERSION=	1.1
PORTREVISION=	3
CATEGORIES=	games windowmaker afterstep
MASTER_SITES=	LOCAL/jim
DISTNAME=	${PORTNAME}-${PORTVERSION}-1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dockable TicTacToe game for WindowMaker and AfterStep

WRKSRC=		${WRKDIR}/wmtictactoe.app/wmtictactoe

USE_XORG=	xpm
USES=		gmake

PLIST_FILES=	bin/wmtictactoe

post-patch:
	@${REINPLACE_CMD} -e \
		's|^void .*main|int main|' ${WRKSRC}/wmtictactoe.c

post-install:
	@${ECHO_MSG} "===>   Run 'wmtictactoe --help' for the available options"

.include <bsd.port.mk>
