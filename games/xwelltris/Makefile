# New ports collection makefile for:	xwelltris
# Date created:		1 Feb 2004
# Whom:			lev
#
# $FreeBSD$
#

PORTNAME=	xwelltris
PORTVERSION=	1.0.1
CATEGORIES=	games
MASTER_SITES=	http://www.xnc.dubna.su/xwelltris/src/
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	lev@FreeBSD.org
COMMENT=	3D Tetris, blockout-like game

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_SIZE=	yes
PLIST_FILES=	bin/xwelltris \
		share/xwelltris/board2.gif \
		share/xwelltris/font2.gif \
		share/xwelltris/polyomino.dat \
		share/xwelltris/topnine.gif \
		share/xwelltris/wellcuts.gif \
		share/xwelltris/wellintro.gif \
		share/xwelltris/welltris.scores
PLIST_DIRS=	share/xwelltris
GNU_CONFIGURE=	yes
USE_XLIB=	yes

.include <bsd.port.mk>
