# New ports collection makefile for: xpat2
# Date created:		5 March 1997
# Whom:			Matthew Hunt <mph@pobox.com>
#
# $FreeBSD$
#

PORTNAME=	xpat2
PORTVERSION=	1.07
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	games/solitaires
DISTNAME=	${PORTNAME}-${PORTVERSION}-src
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

MAINTAINER=	mph@freebsd.org
COMMENT=	An X11 solitaire game with 14 variations

USE_IMAKE=	yes
USE_XPM=	yes
MAN6=		xpat2.6
MANCOMPRESSED=	no

post-install:
	${MV} ${PREFIX}/lib/xpat/man/man6/xpat2.6x ${PREFIX}/man/man6/xpat2.6
	${RMDIR} ${PREFIX}/lib/xpat/man/man6 ${PREFIX}/lib/xpat/man
	${TOUCH} /var/games/xpat.log
	${CHOWN} root:games /var/games/xpat.log $(PREFIX)/bin/xpat2
	${CHMOD} 2555 $(PREFIX)/bin/xpat2
	${CHMOD} 664 /var/games/xpat.log

.include <bsd.port.mk>
