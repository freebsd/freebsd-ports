# Created by: Dave Chapeskie <dchapes@ddm.on.ca>
# $FreeBSD$

PORTNAME=	xmemory
PORTVERSION=	3.7
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	XCONTRIB/games/multiplayer

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multi-player memory game

USES=		imake tar:tgz xorg
USE_CXXSTD=	c++98
USE_XORG=	x11 xext
MAKE_ENV=	DATADIR="${DATADIR}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.man ${STAGEDIR}${MAN1PREFIX}/man/man1/${PORTNAME}.1
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.mem ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
