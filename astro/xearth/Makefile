# New ports collection makefile for:    xearth
# Version required:     1.0
# Date created:         29 October 1995
# Whom:                 piero
#
# $Id: Makefile,v 1.8 1996/11/15 22:35:02 obrien Exp $
#

DISTNAME=	xearth-1.0
CATEGORIES=	astro x11
MASTER_SITES=	ftp://cag.lcs.mit.edu/pub/tuna/

MAINTAINER=	ports@FreeBSD.ORG

USE_IMAKE=	yes

# Copy the list of FreeBSD sites
post-install:
	${MKDIR} ${PREFIX}/lib/X11/xearth
	${CP} ${FILESDIR}/freebsd.core.markers ${PREFIX}/lib/X11/xearth
	${CP} ${FILESDIR}/freebsd.ftp.markers ${PREFIX}/lib/X11/xearth

.include <bsd.port.mk>
