# New ports collection makefile for:		elisp-manual
# Version required:	20-2.5
# Date created:		18 November 1997
# Whom:			Don Croyle <croyle@gelemna.ft-wayne.in.us>
#
# $Id: Makefile,v 1.1.1.1 1998/04/27 14:53:00 kuriyama Exp $
#

DISTNAME=	elisp-manual-20-2.5
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	croyle@gelemna.ft-wayne.in.us

GNU_CONFIGURE=	yes

ALL_TARGET=	elisp

pre-install:
	@if [ ! -f ${PREFIX}/info/dir ]; then \
	${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi

.include <bsd.port.mk>
