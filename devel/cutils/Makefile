# New ports collection makefile for:	cutils
# Version required:		1.3.1
# Date created:			26 November 1996
# Whom:				Sandro Sigala
#
# $Id$
#

DISTNAME=	cutils-1.3.1
PKGNAME=	cutils-1.3.1
CATEGORIES=	devel
MASTER_SITES=	ftp://freefall.FreeBSD.ORG/pub/FreeBSD/LOCAL_PORTS/

MAINTAINER=	ssigala@globalnet.it

HAS_CONFIGURE=	yes

post-install:
.if defined(NOMANCOMPRESS)
	@(cd ${PREFIX} ; \
	gunzip -f `grep man ${PKGDIR}/PLIST` )
.endif

.include <bsd.port.mk>
