# New ports collection makefile for:    unzip
# Version required:     5.2
# Date created:         17 October 1994
# Whom:                 jmz
#
# $Id: Makefile,v 1.4 1995/04/15 04:45:17 asami Exp $
#

DISTNAME=       unzip-5.2
CATEGORIES+=	archivers
MASTER_SITES=   ftp://quest.jpl.nasa.gov/pub/
DISTFILES=      unzip52.tar.Z

MAINTAINER=     ache@FreeBSD.ORG

MAKEFILE=       unix/Makefile
ALL_TARGET=     bsd
MAKE_FLAGS=     LOCAL_UNZIP="${CFLAGS}" \
		INSTALL="install -c -o bin -g bin" \
		prefix=${PREFIX} -f

.include <bsd.port.mk>
