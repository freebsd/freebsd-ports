# New ports collection makefile for: btoa
# Version required:                  5.2
# Date created:                      4 Apr 1996
# Whom:                              Brent J. Nordquist <bjn@visi.com>
#
# $Id: Makefile,v 1.4 1997/01/28 08:11:09 asami Exp $
#

DISTNAME=          btoa-5.2
PKGNAME=           btoa-5.2.1
CATEGORIES=        converters
MASTER_SITES=      ftp://freefall.freebsd.org/pub/FreeBSD/LOCAL_PORTS/

PATCH_SITES=       ${MASTER_SITES}
PATCHFILES=        btoa-5.2-patch1.gz

MAINTAINER=        bjn@visi.com

MAKE_FLAGS=        DESTDIR=${PREFIX} -f
MAKEFILE=          Makefile.sun
MAN1=		   btoa.1

# Turn off the default from bsd.port.mk (-p0), which screws things up
PATCH_DIST_STRIP=  

.include <bsd.port.mk>
