# Created by: Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
# $FreeBSD$

PORTNAME=	xsokoban
PORTVERSION=	3.3c
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.cs.cornell.edu/andru/release/ \
		ftp://ftp.pmg.lcs.mit.edu/pub/xsokoban/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Puzzle of pushing objects to the goals

USES=		imake
USE_XORG=	xpm
WRKSRC=		${WRKDIR}/xsokoban
ALL_TARGET=	xsokoban

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/config.h

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/X11/xsokoban/scores \
		${STAGEDIR}${PREFIX}/lib/X11/xsokoban/bitmaps/defaults \
		${STAGEDIR}${PREFIX}/lib/X11/xsokoban/saves \
		${STAGEDIR}${PREFIX}/lib/X11/xsokoban/screens
	@${CHMOD} 777 ${STAGEDIR}${PREFIX}/lib/X11/xsokoban/scores
	@${CHMOD} 775 ${STAGEDIR}${PREFIX}/lib/X11/xsokoban/saves
	${INSTALL_DATA} ${WRKSRC}/screens/* ${STAGEDIR}${PREFIX}/lib/X11/xsokoban/screens
	${INSTALL_DATA} ${WRKSRC}/bitmaps/defaults/* \
		${STAGEDIR}${PREFIX}/lib/X11/xsokoban/bitmaps/defaults

.include <bsd.port.mk>
