# New ports collection makefile for:    xmris
# Date created:         21 September 1994
# Whom:                 jmz
#
# $FreeBSD$

PORTNAME=	xmris
PORTVERSION=	4.04
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games
DISTNAME=	${PORTNAME}.${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	jmz@FreeBSD.org

USE_GMAKE=	yes
USE_IMAKE=	yes
MAKE_FLAGS=	XAPPLOADDIR=${PREFIX}/lib/X11/app-defaults -f
ALL_TARGET=	xmris
MAN6=		xmred.6 xmris.6 xmsit.6

post-install:
	@${CHMOD} g+w ${X11BASE}/lib/X11/xmris

.include <bsd.port.mk>
