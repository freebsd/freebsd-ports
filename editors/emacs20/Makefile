# New ports collection makefile for:	GNU emacs
# Version required:	19.29
# Date created:		29 October 1994
# Whom:			jkh
#
# $Id: Makefile,v 1.14 1995/04/09 06:11:09 asami Exp $
#

DISTNAME=	emacs-19.29
CATEGORIES+=	editors
MASTER_SITES=	ftp://prep.ai.mit.edu/pub/gnu/

HAS_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	i386--freebsd --prefix=${PREFIX}
STRIP=

post-install:
	gzip -9nf ${PREFIX}/man/man1/emacs.1
	gzip -9nf ${PREFIX}/man/man1/etags.1
	gzip -9nf ${PREFIX}/man/man1/ctags.1

.include <bsd.port.mk>
