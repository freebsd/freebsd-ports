# New ports collection makefile for:  emacs-lisp-intro
# Version required:  1.05
# Date created:  18 November 1997
# Whom:  Don Croyle <croyle@gelemna.ft-wayne.in.us>
#
# $Id$
#

DISTNAME=	emacs-lisp-intro-1.05
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	croyle@gelemna.ft-wayne.in.us

post-install:
	if [ ! -f ${PREFIX}/info/dir ]; then \
	  ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi
	install-info ${PREFIX}/info/emacs-lisp-intro.info ${PREFIX}/info/dir

.include <bsd.port.mk>
