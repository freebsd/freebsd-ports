# New ports collection makefile for:    xmris
# Version required:     4.02
# Date created:         21 September 1994
# Whom:                 jmz
#
# $Id: Makefile,v 1.13 1996/12/06 23:25:56 asami Exp $

DISTNAME=	xmris.4.04
PKGNAME=	xmris-4.04
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games
EXTRACT_SUFX=	.tgz

MAINTAINER=	jmz@FreeBSD.org

USE_GMAKE=	yes
USE_IMAKE=      yes
MAKE_FLAGS=	XAPPLOADDIR=${PREFIX}/lib/X11/app-defaults -f
ALL_TARGET=	xmris

.include <bsd.port.mk>
