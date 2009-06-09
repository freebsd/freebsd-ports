# New ports collection makefile for:    xpipeman
# Date created:         2 Jan 1995
# Whom:                 swallace
#
# $FreeBSD$
#

PORTNAME=	xpipeman
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	games/strategy
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Connect the pipes to stop the leaks

# LP64 issues
ONLY_FOR_ARCHS=	i386

USE_IMAKE=	yes
USE_XORG=	x11 xaw xext xmu xt sm ice
MAN6=		xpipeman.6

post-install:
	${INSTALL} -c -g games -m 664 ${FILESDIR}/xpipescores ${PREFIX}/lib/X11

.include <bsd.port.mk>
