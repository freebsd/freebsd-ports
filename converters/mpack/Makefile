# New ports collection makefile for:    mpack
# Version required:     1.5
# Date created:         1 May 1995
# Whom:                 ache
#
# $FreeBSD$
#

DISTNAME=       mpack-1.5-src
PKGNAME=        mpack-1.5
CATEGORIES=     converters mail news
MASTER_SITES=   ftp://ftp.andrew.cmu.edu/pub/mpack/
EXTRACT_SUFX=   .tar.Z

MAINTAINER=     ache@FreeBSD.org

WRKSRC=         ${WRKDIR}/mpack
MAKEFLAGS=      -f
MAKE_ENV+=      DESTDIR=${PREFIX}
MAN1=		mpack.1 munpack.1

.include <bsd.port.mk>
