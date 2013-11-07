# $FreeBSD$

PORTNAME=	xtrojka
PORTVERSION=	1.2.3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	games/arcade/tetris
DISTNAME=	${PORTNAME}${PORTVERSION:C/\.//g}

MAINTAINER=	ports@edwinm.ik.nu
COMMENT=	Game of skill similar to T*tris

USE_XORG=	x11 xt xproto xaw xmu xext
MAKE_JOBS_UNSAFE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}
MAKE_ARGS=	PREFIX=${STAGEDIR}${PREFIX}

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/xtrojka

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/xtrojka

.include <bsd.port.mk>
