# New ports collection makefile for:    xrobots
# Version required:	something real old
# Date created:         2 Jan 1995
# Whom:                 swallace
#
# $Id: Makefile,v 1.8 1997/01/03 09:37:46 obrien Exp $
#

DISTNAME=       xrobots
PKGNAME=        xrobots-1.0
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.cs.orst.edu/pub/src/X11R4/contrib/games/

MAINTAINER=	swallace@FreeBSD.org

USE_IMAKE=	yes

post-install:
	${INSTALL} -c -g games -m 664 ${FILESDIR}/xrobotscores ${PREFIX}/lib/X11

.include <bsd.port.mk>
