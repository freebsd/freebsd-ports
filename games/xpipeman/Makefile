# New ports collection makefile for:    xpipeman
# Version required:	?
# Date created:         2 Jan 1995
# Whom:                 swallace
#
# $Id: Makefile,v 1.4 1995/04/11 00:20:52 asami Exp $
#

DISTNAME=       xpipeman
CATEGORIES+=	games
MASTER_SITES=	ftp://iraun1.ira.uka.de/pub/x11/
EXTRACT_SUFX=	.tar.Z

USE_IMAKE=	yes

do-install:
	install -c -g games -m 664 ${.CURDIR}/files/xpipescores /usr/X11R6/lib/X11

.include <bsd.port.mk>
