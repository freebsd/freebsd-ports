# New ports collection makefile for:    xpipeman
# Version required:	something real old
# Date created:         2 Jan 1995
# Whom:                 swallace
#
# $Id: Makefile,v 1.7 1996/11/18 11:26:38 asami Exp $
#

DISTNAME=       xpipeman
PKGNAME=        xpipeman-1.0
CATEGORIES=	games
MASTER_SITES=	ftp://iraun1.ira.uka.de/pub/x11/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	swallace@FreeBSD.org

USE_IMAKE=	yes

post-install:
	install -c -g games -m 664 ${.CURDIR}/files/xpipescores /usr/X11R6/lib/X11

.include <bsd.port.mk>
