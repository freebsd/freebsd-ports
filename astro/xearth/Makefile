# New ports collection makefile for:    xearth
# Version required:     1.0
# Date created:         29 October 1995
# Whom:                 piero
#
# $Id: Makefile,v 1.5 1995/10/01 21:53:49 roberto Exp $
#

DISTNAME=	xearth-1.0
CATEGORIES+=	x11
MASTER_SITES=	ftp://cag.lcs.mit.edu/pub/tuna/

USE_IMAKE=	yes

# Copy the list of FreeBSD sites
post-install:
	mkdir -p ${PREFIX}/lib/X11/xearth
	cp ${FILESDIR}/freebsd.core.markers ${PREFIX}/lib/X11/xearth
	cp ${FILESDIR}/freebsd.ftp.markers ${PREFIX}/lib/X11/xearth

.include <bsd.port.mk>
