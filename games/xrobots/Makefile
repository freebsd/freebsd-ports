# New ports collection makefile for:    xrobots
# Version required:	1.0
# Date created:         2 Jan 1995
# Whom:                 swallace
#
# $FreeBSD$
#

DISTNAME=       xrobots-1.0-ss-10.20
PKGNAME=        xrobots-1.0
CATEGORIES=	games
MASTER_SITES=	ftp://hpux.csc.liv.ac.uk/hpux/Games/Arcade/xrobots-1.0/

MAINTAINER=	jseger@FreeBSD.org

USE_IMAKE=	yes
WRKSRC=		${WRKDIR}/xrobots-1.0
MAN6=		xrobots.6

post-install:
	${INSTALL} -c -g games -m 664 ${FILESDIR}/xrobotscores ${PREFIX}/lib/X11

.include <bsd.port.mk>
