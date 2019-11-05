# Created by: swallace
# $FreeBSD$

PORTNAME=	xpipeman
PORTVERSION=	1.0
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	SUNSITE/games/strategy
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Connect the pipes to stop the leaks

USES=		imake tar:Z xorg
USE_XORG=	x11 xaw xext xmu xt sm ice
CFLAGS+=	-Wno-error=return-type

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xpipeman ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xpipeman.man ${STAGEDIR}${MANPREFIX}/man/man6/xpipeman.6
	${INSTALL} -c ${FILESDIR}/xpipescores ${STAGEDIR}${PREFIX}/lib/X11

.include <bsd.port.mk>
