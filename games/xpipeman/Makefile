# New ports collection makefile for:    xpipeman
# Version required:	?
# Date created:         2 Jan 1995
# Whom:                 swallace
#
# $Id: Makefile,v 1.3 1995/04/01 12:45:33 jkh Exp $
#

DISTNAME=       xpipeman
CATEGORIES+=	games
MASTER_SITES=	ftp://iraun1.ira.uka.de/pub/x11/
EXTRACT_SUFX=	.tar.Z

USE_IMAKE=	yes

.include <bsd.port.mk>

install:
	install -c -g games -m 664 ${.CURDIR}/files/xpipescores /usr/X11R6/lib/X11
