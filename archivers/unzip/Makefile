# New ports collection makefile for:    unzip
# Version required:     5.12
# Date created:         17 October 1994
# Whom:                 jmz
#
# $Id$
#

DISTNAME=	unzip-5.12
CATEGORIES+=	archivers
MASTER_SITES=	ftp://garbo.uwasa.fi/unix/arcers/
DISTFILES=	unzip512.tar.Z

MAKEFILE=       unix/Makefile
ALL_TARGET=     bsd
MAKE_FLAGS=     LOCAL_UNZIP="-O2 -DCHECK_EOF" \
		INSTALL="install -c -o bin -g bin" \
		prefix=${PREFIX} -f

pre-install:
	@mkdir -p ${PREFIX}/bin
	@mkdir -p ${PREFIX}/man/man1

.include <bsd.port.mk>
