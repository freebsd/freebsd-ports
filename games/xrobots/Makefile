# New ports collection makefile for:    xrobots
# Version required:	something real old
# Date created:         2 Jan 1995
# Whom:                 swallace
#
# $Id: Makefile,v 1.5 1995/04/20 18:21:16 asami Exp $
#

DISTNAME=       xrobots
PKGNAME=        xrobots-1.0
CATEGORIES+=	games
MASTER_SITES=	ftp://ftp.cs.orst.edu/pub/src/X11R4/contrib/games/

USE_IMAKE=	yes

post-install:
	install -c -g games -m 664 ${.CURDIR}/files/xrobotscores /usr/X11R6/lib/X11

.include <bsd.port.mk>
