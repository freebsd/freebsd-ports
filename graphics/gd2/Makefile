# New ports collection makefile for: gd
# Version required:     1.3
# Date created:         27 Mar 1998
# Whom:                 jeff@cetlink.net
#
# $Id: Makefile,v 1.5 1998/06/25 03:13:16 vanilla Exp $
#

DISTNAME=       gd1.3
PKGNAME=        gd-1.3
CATEGORIES=	graphics
MASTER_SITES=   http://www.boutell.com/gd/http/ \
		ftp://ftp.boutell.com/pub/boutell/gd/

MAINTAINER=     jeff@cetlink.net

RESTRICTED=	unavailable from master site due to legal problems

FETCH_BEFORE_ARGS=	-b

pre-install:
	${MKDIR} ${PREFIX}/include/gd
	${MKDIR} ${PREFIX}/share/examples/gd

.include <bsd.port.mk>
