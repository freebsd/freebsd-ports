# New ports collection makefile for:	GNU emacs
# Version required:	19.29
# Date created:		29 October 1994
# Whom:			jkh
#
# $Id: Makefile,v 1.16 1995/06/26 08:25:34 asami Exp $
#

DISTNAME=	emacs-19.29
CATEGORIES+=	editors
MASTER_SITES=	ftp://prep.ai.mit.edu/pub/gnu/

HAS_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	i386--freebsd --prefix=${PREFIX} --with-x-toolkit
STRIP=

post-install:
	gzip -9nf ${PREFIX}/man/man1/emacs.1
	gzip -9nf ${PREFIX}/man/man1/etags.1
	gzip -9nf ${PREFIX}/man/man1/ctags.1
	for file in emacs-19.29 emacsclient etags ctags b2m; do \
	  strip ${PREFIX}/bin/$$file; \
	done

.include <bsd.port.mk>
