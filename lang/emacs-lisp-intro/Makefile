# New ports collection makefile for:	emacs-lisp-intro
# Version required:	1.05
# Date created:		18 November 1997
# Whom:			Don Croyle <croyle@gelemna.ft-wayne.in.us>
#
# $Id: Makefile,v 1.2 1998/09/18 22:28:04 vanilla Exp $
#

DISTNAME=	emacs-lisp-intro-1.05
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	emacs

MAINTAINER=	croyle@gelemna.ft-wayne.in.us

pre-install:
	if [ ! -f ${PREFIX}/info/dir ]; then \
	  ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi

.include <bsd.port.mk>
