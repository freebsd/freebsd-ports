# New ports collection makefile for:    xrobots
# Date created:         2 Jan 1995
# Whom:                 swallace
#
# $Id: Makefile,v 1.1.1.1 1995/01/03 08:47:58 swallace Exp $
#

DISTNAME=       xrobots
MASTER_SITES=	ftp://ftp.cs.orst.edu/pub/src/X11R4/contrib/games/
USE_IMAKE=	yes

.include <bsd.port.mk>

install:
	install -c -g games -m 664 ${.CURDIR}/files/xrobotscores /usr/X11R6/lib/X11
