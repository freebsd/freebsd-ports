# Port for:		cutils
# Version required:	FreeBSD-2.1.5
# Date created:		26 November 1996
# Whom:			Sandro Sigala
#
# $Id$
#

DISTNAME=	cutils-1.3
CATEGORIES=	devel
MASTER_SITES=	ftp://freefall.freebsd.org/pub/FreeBSD/LOCAL_PORTS/
DISTFILES=	cutils-1.3.tar.gz

MAINTAINER=	ssigala@globalnet.it

post-install:
.if defined(NOMANCOMPRESS)
	(cd ${PREFIX} ; \
	gunzip -f `grep man ${PKGDIR}/PLIST` )
.endif

.include <bsd.port.mk>
