# $FreeBSD$

PORTNAME=	xtrojka
PORTVERSION=	1.2.3
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SUNSITE/games/arcade/tetris
DISTNAME=	${PORTNAME}${PORTVERSION:C/\.//g}

MAINTAINER=	ports@edwinm.ik.nu
COMMENT=	Game of skill similar to T*tris

USE_XORG=	x11 xt xproto xaw xmu xext
MAKE_JOBS_UNSAFE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}
INSTALL_TARGET=	install PREFIX=${STAGEDIR}${PREFIX}

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/xtrojka

.include <bsd.port.mk>
