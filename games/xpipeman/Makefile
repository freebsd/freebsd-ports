# New ports collection makefile for:    xpipeman
# Date created:         2 Jan 1995
# Whom:                 swallace
#
# $FreeBSD$
#

PORTNAME=	xpipeman
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	games/strategy
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	jseger@FreeBSD.org

USE_IMAKE=	yes
MAN6=		xpipeman.6

post-install:
	${INSTALL} -c -g games -m 664 ${FILESDIR}/xpipescores ${PREFIX}/lib/X11

.include <bsd.port.mk>
