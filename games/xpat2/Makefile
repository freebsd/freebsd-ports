# New ports collection makefile for: xpat2
# Date created:		5 March 1997
# Whom:			Matthew Hunt <mph@pobox.com>
#
# $FreeBSD$
#

PORTNAME=	xpat2
PORTVERSION=	1.06
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	games/solitaires

MAINTAINER=	mph@freebsd.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_X_PREFIX=	yes
MAN6=		xpat2.6

post-install:
	${TOUCH} $(PREFIX)/lib/X11/xpat/xpat.log
	${CHOWN} root.games $(PREFIX)/lib/X11/xpat/xpat.log $(PREFIX)/bin/xpat2
	${CHMOD} 2555 $(PREFIX)/bin/xpat2
	${CHMOD} 664 $(PREFIX)/lib/X11/xpat/xpat.log

.include <bsd.port.mk>
