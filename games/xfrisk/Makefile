# New ports collection makefile for:   xfrisk
# Date created:        20 April 1997
# Whom:                Matthew Hunt <mph@pobox.com>
#
# $FreeBSD$
#

PORTNAME=	xfrisk
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://cvs.morphy.iki.fi/xfrisk/files/
DISTNAME=	XFrisk-${PORTVERSION}

MAINTAINER=	mph@freebsd.org
COMMENT=	A multi-player networked Risk game for X11

LIB_DEPENDS=	Xaw3d.${XAWVER}:${PORTSDIR}/x11-toolkits/Xaw3d

NO_CDROM=	Possible trademark infringement

USE_X_PREFIX=	yes
NO_INSTALL_MANPAGES=	yes
WRKSRC=		${WRKDIR}/XFrisk
USE_GMAKE=	yes
MAKE_ENV+=	XDIR=${X11BASE}

.include <bsd.port.mk>
