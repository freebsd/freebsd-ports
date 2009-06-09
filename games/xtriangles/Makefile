# New ports collection makefile for:	xtriangles
# Date created:		12 October 1996
# Whom:			Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	xtriangles
PORTVERSION=	5.5.2
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games/xpuzzles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Triangles puzzle

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_IMAKE=	yes
USE_XORG=	x11 xext xt sm ice
MAN1=		xtriangles.1
MANCOMPRESSED=	no
XFREE86_HTML_MAN=	no

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xtriangles ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/Triangles.ad \
		 ${PREFIX}/lib/X11/app-defaults/Triangles
	${INSTALL_MAN} ${WRKSRC}/xtriangles.man ${MANPREFIX}/man/man1/xtriangles.1

.include <bsd.port.mk>
