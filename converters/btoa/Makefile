# New ports collection makefile for: btoa
# Version required:                  5.2
# Date created:                      4 Apr 1996
# Whom:                              Brent J. Nordquist <nordquist@platinum.com>
#
# $Id: Makefile,v 1.2 1996/11/11 05:49:14 obrien Exp $
#

DISTNAME=          btoa-5.2
PKGNAME=           btoa-5.2.1
CATEGORIES=        misc
MASTER_SITES=      ftp://freefall.freebsd.org/pub/FreeBSD/LOCAL_PORTS/

PATCH_SITES=       ${MASTER_SITES}
PATCHFILES=        btoa-5.2-patch1.gz

MAINTAINER=        nordquist@platinum.com

MAKE_FLAGS=        DESTDIR=${PREFIX} -f
MAKEFILE=          Makefile.sun
MAN1=		   btoa.1

# Turn off the default from bsd.port.mk (-p0), which screws things up
PATCH_DIST_STRIP=  

.include <bsd.port.mk>
