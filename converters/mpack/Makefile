# New ports collection makefile for:    mpack
# Version required:     1.5
# Date created:         1 May 1995
# Whom:                 ache
#
# $Id: Makefile,v 1.6 1996/11/18 14:04:07 asami Exp $
#

DISTNAME=       mpack-1.5-src
PKGNAME=        mpack-1.5
CATEGORIES=     converters mail news
MASTER_SITES=   ftp://ftp.andrew.cmu.edu/pub/mpack/
EXTRACT_SUFX=   .tar.Z

MAINTAINER=     ache@FreeBSD.ORG

WRKSRC=         ${WRKDIR}/mpack
MAKEFLAGS=      -DDESTDIR=${PREFIX} -f
MAN1=		mpack.1 munpack.1

.include <bsd.port.mk>
