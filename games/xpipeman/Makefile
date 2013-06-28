# Created by: swallace
# $FreeBSD$

PORTNAME=	xpipeman
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	SUNSITE
MASTER_SITE_SUBDIR=	games/strategy
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Connect the pipes to stop the leaks

# LP64 issues
ONLY_FOR_ARCHS=	i386 amd64

USES=		imake
USE_XORG=	x11 xaw xext xmu xt sm ice
MAN6=		xpipeman.6
MANCOMPRESSED=	no
CFLAGS+=	-Wno-error=return-type
BINGRP=		games
BINMODE=	2555

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xpipeman ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xpipeman.man ${MANPREFIX}/man/man6/xpipeman.6
	${INSTALL} -c -g games -m 664 ${FILESDIR}/xpipescores ${PREFIX}/lib/X11

.include <bsd.port.mk>
