# New ports collection makefile for: xpat2
# Version required:	1.04
# Date created:		5 March 1997
# Whom:			Matthew Hunt <mph@pobox.com>
#
# $Id: Makefile,v 1.1.1.1 1997/03/06 09:22:35 tg Exp $
#

DISTNAME=	xpat2-1.04
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	games/solitaires
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	mph@pobox.com

USE_X11=	yes
MAN6=		xpat2.6

post-install:
	touch $(PREFIX)/lib/X11/xpat/xpat.log
	chown games $(PREFIX)/lib/X11/xpat/xpat.log $(PREFIX)/bin/xpat2
	chmod 4555 $(PREFIX)/bin/xpat2

.include <bsd.port.mk>

