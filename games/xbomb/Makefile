# New ports collection makefile for:    xbomb
# Version required:     2.1
# Date created:         20 Feb 1998
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=       xbomb-2.1
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.demon.co.uk/pub/unix/xwindows/games/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

USE_X_PREFIX=	yes
MAN6=		xbomb.6

post-install:
	@${MKDIR} ${PREFIX}/lib/X11/xbomb
	@touch ${PREFIX}/lib/X11/xbomb/xbomb3.hi
	@touch ${PREFIX}/lib/X11/xbomb/xbomb4.hi
	@touch ${PREFIX}/lib/X11/xbomb/xbomb6.hi
	@${CHMOD} 666 ${PREFIX}/lib/X11/xbomb/xbomb?.hi

.include <bsd.port.mk>
