# New ports collection makefile for:    xrobots
# Version required:	?
# Date created:         2 Jan 1995
# Whom:                 swallace
#
# $Id: Makefile,v 1.3 1995/04/01 12:45:37 jkh Exp $
#

DISTNAME=       xrobots
CATEGORIES+=	games
MASTER_SITES=	ftp://ftp.cs.orst.edu/pub/src/X11R4/contrib/games/

USE_IMAKE=	yes

.include <bsd.port.mk>

install:
	install -c -g games -m 664 ${.CURDIR}/files/xrobotscores /usr/X11R6/lib/X11
