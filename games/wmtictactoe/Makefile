# New ports collection makefile for:	wmtictactoe
# Date created:			28 Apr 1999
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wmtictactoe
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	games windowmaker afterstep
MASTER_SITES=	http://atlas.ucpel.tche.br/~acamargo/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	jim
DISTNAME=	wmtictactoe-1.1-1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A dockable TicTacToe game for WindowMaker and AfterStep

USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/wmtictactoe.app/wmtictactoe
USE_X_PREFIX=	yes
USE_XPM=	yes

post-install:
	@${ECHO} "===>   Run 'wmtictactoe --help' for the available options"

.include <bsd.port.mk>
