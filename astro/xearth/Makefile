# New ports collection makefile for:    xearth
# Version required:     1.0
# Date created:         29 October 1995
# Whom:                 piero
#
# $Id: Makefile,v 1.4 1995/04/12 20:31:54 asami Exp $
#

DISTNAME=	xearth-1.0
CATEGORIES+=	x11
MASTER_SITES=	ftp://cag.lcs.mit.edu/pub/tuna/

USE_IMAKE=	yes

# Copy the list of FreeBSD sites
post-install:
	cp ${FILESDIR}/freebsd.markers ${PREFIX}/lib/X11

.include <bsd.port.mk>
