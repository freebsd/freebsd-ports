# New ports collection makefile for: xpat2
# Version required:	1.06
# Date created:		5 March 1997
# Whom:			Matthew Hunt <mph@pobox.com>
#
# $Id: Makefile,v 1.7 1999/06/07 20:18:24 mph Exp $
#

DISTNAME=	xpat2-1.06
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	games/solitaires

MAINTAINER=	mph@freebsd.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_X_PREFIX=	yes
MAN6=		xpat2.6

post-install:
	${TOUCH} $(PREFIX)/lib/X11/xpat/xpat.log
	chown root.games $(PREFIX)/lib/X11/xpat/xpat.log $(PREFIX)/bin/xpat2
	chmod 2555 $(PREFIX)/bin/xpat2
	chmod 664 $(PREFIX)/lib/X11/xpat/xpat.log

.include <bsd.port.mk>
