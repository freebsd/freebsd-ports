# New ports collection makefile for: btoa
# Version required:                  5.2
# Date created:                      4 Apr 1996
# Whom:                              Brent J. Nordquist <nordquist@platinum.com>
#
# $Id$
#

DISTNAME=          btoa-5.2
PKGNAME=           btoa-5.2.1
CATEGORIES+=       misc
MASTER_SITES=      ftp://freefall.freebsd.org/pub/FreeBSD/LOCAL_PORTS/

PATCH_SITES=       ${MASTER_SITES}
PATCHFILES=        btoa-5.2-patch1.gz

MAINTAINER=        nordquist@platinum.com

MAKE_FLAGS=        DESTDIR=${PREFIX} -f
MAKEFILE=          Makefile.sun

# Turn off the default from bsd.port.mk (-p0), which screws things up
PATCH_DIST_STRIP=  

post-install:
.if !defined(NOMANCOMPRESS)
	gzip -9nf ${PREFIX}/man/man1/btoa.1
.endif

.include <bsd.port.mk>
