# New ports collection makefile for:	xcubes
# Date created:		12 October 1996
# Whom:			Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	xcubes
PORTVERSION=	5.5.2
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games/xpuzzles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cube puzzle for X11

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_IMAKE=	yes
USE_XORG=	x11 xext xt sm ice
MAN1=		xcubes.1
MANCOMPRESSED=	no
XFREE86_HTML_MAN=	no

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xcubes ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/Cubes.ad ${PREFIX}/lib/X11/app-defaults/Cubes
	${INSTALL_MAN} ${WRKSRC}/xcubes.man ${MANPREFIX}/man/man1/xcubes.1

.include <bsd.port.mk>
