# New ports collection makefile for:	xdino
# Date created:		12 October 1996
# Whom:			Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	xdino
PORTVERSION=	5.5.2
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games/xpuzzles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dino puzzle game for X11

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_IMAKE=	yes
USE_XORG=	x11 xext xt sm ice
MAN1=		xdino.1
MANCOMPRESSED=	no
XFREE86_HTML_MAN=	no

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xdino ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/Dino.ad ${PREFIX}/lib/X11/app-defaults/Dino
	${INSTALL_MAN} ${WRKSRC}/xdino.man ${MANPREFIX}/man/man1/xdino.1

.include <bsd.port.mk>
