# New ports collection makefile for:	GNU emacs
# Version required:	19.34
# Date created:		29 October 1994
# Whom:			jkh
#
# $Id: Makefile,v 1.23 1996/11/11 05:07:06 obrien Exp $
#

DISTNAME=	emacs-19.34
CATEGORIES=	editors
MASTER_SITES=	ftp://prep.ai.mit.edu/pub/gnu/

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	i386--freebsd --with-x-toolkit
STRIP=
MAN1=		emacs.1 etags.1 ctags.1

post-install:
	for file in emacs-19.34 emacsclient etags ctags b2m; do \
	  strip ${PREFIX}/bin/$$file; \
	done

.include <bsd.port.mk>
