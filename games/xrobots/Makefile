# New ports collection makefile for:    xrobots
# Version required:	?
# Date created:         2 Jan 1995
# Whom:                 swallace
#
# $Id: Makefile,v 1.4 1995/04/11 00:20:56 asami Exp $
#

DISTNAME=       xrobots
CATEGORIES+=	games
MASTER_SITES=	ftp://ftp.cs.orst.edu/pub/src/X11R4/contrib/games/

USE_IMAKE=	yes

do-install:
	install -c -g games -m 664 ${.CURDIR}/files/xrobotscores /usr/X11R6/lib/X11

.include <bsd.port.mk>
