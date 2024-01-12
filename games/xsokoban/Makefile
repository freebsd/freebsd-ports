PORTNAME=	xsokoban
PORTVERSION=	3.3c
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.cs.cornell.edu/andru/release/ \
		ftp://ftp.pmg.lcs.mit.edu/pub/xsokoban/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Puzzle of pushing objects to the goals
WWW=		https://www.cs.cornell.edu/andru/xsokoban.html

LICENSE=	PD

USES=		imake xorg
USE_XORG=	xpm x11 xext
MAKE_ARGS+=	MANPATH="${PREFIX}/share/man"
WRKSRC=		${WRKDIR}/xsokoban
ALL_TARGET=	xsokoban

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/config.h

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/X11/xsokoban/screens
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/X11/xsokoban/bitmaps/defaults
	${INSTALL_DATA} ${WRKSRC}/screens/* ${STAGEDIR}${PREFIX}/lib/X11/xsokoban/screens
	${INSTALL_DATA} ${WRKSRC}/bitmaps/defaults/* \
		${STAGEDIR}${PREFIX}/lib/X11/xsokoban/bitmaps/defaults

	@${MKDIR} ${STAGEDIR}/var/games/xsokoban/scores
	@${MKDIR} ${STAGEDIR}/var/games/xsokoban/saves
# may be created by xsokoban -c
	@${PRINTF} "xs02\0\0" > ${STAGEDIR}/var/games/xsokoban/scores/scores.sample

.include <bsd.port.mk>
