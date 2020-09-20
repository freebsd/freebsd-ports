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

USES=		gmake xorg
USE_XORG=	x11 xext xpm

WRKSRC=		${WRKDIR}/wmtictactoe.app/wmtictactoe

PLIST_FILES=	bin/wmtictactoe

post-patch: # fix for the build failure with -fno-common
	@${REINPLACE_CMD} 's|^Display|extern Display|; s|^Window|extern Window|' ${WRKSRC}/../wmgeneral/wmgeneral.h
	@${ECHO} "Display         *display;"           >> ${WRKSRC}/../wmgeneral/wmgeneral.c
	@${ECHO} "Window          Root, iconwin, win;" >> ${WRKSRC}/../wmgeneral/wmgeneral.c

.include <bsd.port.mk>
