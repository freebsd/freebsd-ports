# New ports collection makefile for:	xtrojka
# Date created:				22 march 2000
# Whom:					Edwin Mons
#
# $FreeBSD$
#

PORTNAME=	xtrojka
PORTVERSION=	1.1
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.funet.fi/pub/unix/games/
DISTNAME=	${PORTNAME}

MAINTAINER=	e@ik.nu
COMMENT=	Game of skill similar to T*tris

WRKSRC=		${WRKDIR}
MAN6=		xtrojka.6
MANCOMPRESSED=	yes
USE_XLIB=	yes

pre-install:
	${MKDIR} ${PREFIX}/share/xtrojka

post-install:
	${STRIP_CMD} ${PREFIX}/bin/xtrojka

.include <bsd.port.mk>
