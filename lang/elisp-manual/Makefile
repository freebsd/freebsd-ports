# New ports collection makefile for:  elisp-manual
# Version required:  19-2.4.2
# Date created:  18 November 1997
# Whom:  Don Croyle <croyle@gelemna.ft-wayne.in.us>
#
# $Id$
#

DISTNAME=	elisp-manual-19-2.4.2
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	croyle@gelemna.ft-wayne.in.us

ALL_TARGET=	elisp
post-install:
	if [ ! -f ${PREFIX}/info/dir ]; then \
	  ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi
	install-info ${PREFIX}/info/elisp ${PREFIX}/info/dir

.include <bsd.port.mk>
