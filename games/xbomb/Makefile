# New ports collection makefile for:    xbomb
# Date created:         20 Feb 1998
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xbomb
PORTVERSION=	2.1a
CATEGORIES=	games
MASTER_SITES=	http://www.gedanken.demon.co.uk/download-xbomb/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Minesweeper with a couple of grid types

USE_X_PREFIX=	yes
MAN6=		xbomb.6

post-install:
	@${MKDIR} ${PREFIX}/lib/X11/xbomb
	@${TOUCH} ${PREFIX}/lib/X11/xbomb/xbomb3.hi
	@${TOUCH} ${PREFIX}/lib/X11/xbomb/xbomb4.hi
	@${TOUCH} ${PREFIX}/lib/X11/xbomb/xbomb6.hi
	@${CHOWN} root:games ${PREFIX}/lib/X11/xbomb/xbomb?.hi
	@${CHMOD} 664 ${PREFIX}/lib/X11/xbomb/xbomb?.hi
	@${CHOWN} root:games ${PREFIX}/bin/xbomb
	@${CHMOD} 2755 ${PREFIX}/bin/xbomb

.include <bsd.port.mk>
