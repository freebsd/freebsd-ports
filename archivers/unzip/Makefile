# New ports collection makefile for:    unzip
# Version required:     5.3
# Date created:         17 October 1994
# Whom:                 jmz
#
# $Id: Makefile,v 1.8 1997/01/06 21:43:22 ache Exp $
#

DISTNAME=       unzip-5.3
CATEGORIES=	archivers
MASTER_SITES=   ftp://ftp.cdrom.com/pub/infozip/src/
DISTFILES=      unzip53.tar.gz

MAINTAINER=     ache@FreeBSD.ORG

NO_WRKSUBDIR=   YES
MAKEFILE=       unix/Makefile
ALL_TARGET=     bsd
MAKE_FLAGS=     LOCAL_UNZIP="${CFLAGS}" \
		INSTALL="install -c -o bin -g bin" \
		prefix=${PREFIX} -f
MAN1=		funzip.1 unzip.1 unzipsfx.1 zipinfo.1

.include <bsd.port.mk>
