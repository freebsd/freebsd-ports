# New ports collection makefile for:    xpipeman
# Version required:	something real old
# Date created:         2 Jan 1995
# Whom:                 swallace
#
# $Id: Makefile,v 1.8 1997/01/03 09:37:38 obrien Exp $
#

DISTNAME=       xpipeman
PKGNAME=        xpipeman-1.0
CATEGORIES=	games
MASTER_SITES=	ftp://iraun1.ira.uka.de/pub/x11/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	swallace@FreeBSD.org

USE_IMAKE=	yes

post-install:
	${INSTALL} -c -g games -m 664 ${FILESDIR}/xpipescores ${PREFIX}/lib/X11

.include <bsd.port.mk>
