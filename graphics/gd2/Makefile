# New ports collection makefile for: gd
# Version required:     1.3
# Date created:         27 Mar 1998
# Whom:                 jeff@cetlink.net
#
# $Id: Makefile,v 1.3 1998/04/04 14:25:47 vanilla Exp $
#

DISTNAME=       gd1.3
PKGNAME=        gd-1.3
CATEGORIES=	graphics
MASTER_SITES=   http://www.boutell.com/gd/http/

MAINTAINER=     jeff@cetlink.net

FETCH_BEFORE_ARGS=	-b

pre-install:
	${MKDIR} ${PREFIX}/include/gd
	${MKDIR} ${PREFIX}/share/examples/gd

.include <bsd.port.mk>
