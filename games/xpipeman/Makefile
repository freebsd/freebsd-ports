# New ports collection makefile for:    xpipeman
# Version required:	something real old
# Date created:         2 Jan 1995
# Whom:                 swallace
#
# $Id: Makefile,v 1.9 1997/07/21 19:36:27 max Exp $
#

DISTNAME=       xpipeman
PKGNAME=        xpipeman-1.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	games/strategy
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	jseger@FreeBSD.org

USE_IMAKE=	yes

post-install:
	${INSTALL} -c -g games -m 664 ${FILESDIR}/xpipescores ${PREFIX}/lib/X11

.include <bsd.port.mk>
