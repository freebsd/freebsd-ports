# Created by: Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
# $FreeBSD$

PORTNAME=	xtriangles
PORTVERSION=	5.5.2
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	XCONTRIB/games/xpuzzles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Triangles puzzle

WRKSRC=		${WRKDIR}/${PORTNAME}
USES=		imake xorg
USE_XORG=	x11 xext xt sm ice

PLIST_FILES=	bin/xtriangles \
		lib/X11/app-defaults/Triangles \
		man/man1/xtriangles.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xtriangles ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/Triangles.ad \
		 ${STAGEDIR}${PREFIX}/lib/X11/app-defaults/Triangles
	${INSTALL_MAN} ${WRKSRC}/xtriangles.man ${STAGEDIR}${MANPREFIX}/man/man1/xtriangles.1

.include <bsd.port.mk>
