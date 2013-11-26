# Created by: Yukihiro Nakai <nakai@mlab.t.u-tokyo.ac.jp>
# $FreeBSD$

PORTNAME=	xrubik
PORTVERSION=	5.5.2
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games/xpuzzles

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	X-based rubik's cube(tm)

WRKSRC=		${WRKDIR}/xrubik
USES=		imake
USE_XORG=	xt sm ice xext x11
XFREE86_HTML_MAN=	no

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xrubik ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/Rubik.ad ${STAGEDIR}${PREFIX}/lib/X11/app-defaults/Rubik
	${INSTALL_MAN} ${WRKSRC}/xrubik.man ${STAGEDIR}${PREFIX}/man/man1/xrubik.1

.include <bsd.port.mk>
