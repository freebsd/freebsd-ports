# Created by: Jim Mock <jim@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wmtictactoe
DISTVERSION=	1.1-1
CATEGORIES=	games windowmaker afterstep
MASTER_SITES=	LOCAL/jim

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dockable TicTacToe game for WindowMaker and AfterStep

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/../COPYING

WRKSRC=		${WRKDIR}/wmtictactoe.app/wmtictactoe

USE_XORG=	x11 xext xpm
USES=		gmake

PLIST_FILES=	bin/wmtictactoe

.include <bsd.port.mk>
