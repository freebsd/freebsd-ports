# New ports collection makefile for:    xearth
# Version required:     0.92
# Date created:         29 October 1995
# Whom:                 piero
#
# $Id$
#

DISTNAME=	xearth-0.92
CATEGORIES+=	x11
MASTER_SITES=	ftp://cag.lcs.mit.edu/pub/tuna/

USE_IMAKE=	yes

# Copy the list of FreeBSD sites
pre-patch:
	cp ${FILESDIR}/freebsd.h ${WRKSRC}

.include <bsd.port.mk>
