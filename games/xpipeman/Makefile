# New ports collection makefile for:    xpipeman
# Date created:         2 Jan 1995
# Whom:                 swallace
#
# $Id: Makefile,v 1.2 1995/02/11 13:49:19 asami Exp $
#

DISTNAME=       xpipeman
MASTER_SITES=	ftp://iraun1.ira.uka.de/pub/x11/
CATEGORIES+=	games
EXTRACT_SUFX=	.tar.Z
USE_IMAKE=	yes

.include <bsd.port.mk>

install:
	install -c -g games -m 664 ${.CURDIR}/files/xpipescores /usr/X11R6/lib/X11
