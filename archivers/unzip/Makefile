# New ports collection makefile for:    unzip
# Version required:     5.2
# Date created:         17 October 1994
# Whom:                 jmz
#
# $Id: Makefile,v 1.6 1996/11/12 02:17:43 obrien Exp $
#

DISTNAME=       unzip-5.2
CATEGORIES=	archivers
MASTER_SITES=   ftp://quest.jpl.nasa.gov/pub/
DISTFILES=      unzip52.tar.Z

MAINTAINER=     ache@FreeBSD.ORG

MAKEFILE=       unix/Makefile
ALL_TARGET=     bsd
MAKE_FLAGS=     LOCAL_UNZIP="${CFLAGS}" \
		INSTALL="install -c -o bin -g bin" \
		prefix=${PREFIX} -f
MAN1=		funzip.1 unzip.1 unzipsfx.1 zipinfo.1

.include <bsd.port.mk>
