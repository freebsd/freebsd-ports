# New ports collection makefile for: gd
# Version required:     1.3
# Date created:         27 Mar 1998
# Whom:                 jeff@cetlink.net
#
# $Id: Makefile,v 1.4 1998/04/19 15:38:31 steve Exp $
#

DISTNAME=       gd1.3
PKGNAME=        gd-1.3
CATEGORIES=	graphics
MASTER_SITES=   http://www.boutell.com/gd/http/ \
		ftp://ftp.boutell.com/pub/boutell/gd/

MAINTAINER=     jeff@cetlink.net

FETCH_BEFORE_ARGS=	-b

pre-install:
	${MKDIR} ${PREFIX}/include/gd
	${MKDIR} ${PREFIX}/share/examples/gd

.include <bsd.port.mk>
