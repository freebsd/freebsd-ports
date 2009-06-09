# New ports collection makefile for:   XFlame
# Date created:        2 January 1999
# Whom:                Kris Kennaway <kkennawa@physics.adelaide.edu.au>
#
# $FreeBSD$
#

PORTNAME=	xflame
PORTVERSION=	1.1.1
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=kris

MAINTAINER=	kris@FreeBSD.org
COMMENT=	A cool animated flame

USE_IMAKE=	yes
USE_XORG=	x11 xext

NO_INSTALL_MANPAGES=	yes
PLIST_FILES=		bin/xflame

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xflame ${PREFIX}/bin/xflame

.include <bsd.port.mk>
