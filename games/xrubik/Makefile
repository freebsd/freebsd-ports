# New ports collection makefile for:	xrubik
# Date created:		20 October 1996
# Whom:			Yukihiro Nakai <nakai@mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	xrubik
PORTVERSION=	5.5.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games/xpuzzles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X-based rubik's cube(tm)

WRKSRC=		${WRKDIR}/xrubik
USE_IMAKE=	yes
MAN1=		xrubik.1
XFREE86_HTML_MAN=	no
NO_INSTALL_MANPAGES=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xrubik ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/Rubik.ad ${PREFIX}/lib/X11/app-defaults/Rubik
	${INSTALL_MAN} ${WRKSRC}/xrubik.man ${PREFIX}/man/man1/xrubik.1

.include <bsd.port.mk>
