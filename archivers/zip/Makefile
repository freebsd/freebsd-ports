# New ports collection makefile for:    zip
# Version required:     2.0.1
# Date created:         22 Dec 1994
# Whom:                 ache
#
# $Id: Makefile,v 1.3 1995/04/12 04:54:11 asami Exp $
#

DISTNAME=       zip201
PKGNAME=        zip-2.0.1
CATEGORIES+=	archivers
MASTER_SITES=	ftp://garbo.uwasa.fi/unix/arcers/
EXTRACT_SUFX=   .tar.Z

MAINTAINER=     ache@FreeBSD.ORG

ALL_TARGET=     freebsd

pre-install:
	@mkdir -p ${PREFIX}/bin
	@mkdir -p ${PREFIX}/man/man1

install: build
	cd ${WRKSRC}; install -c -o bin -g bin zip.1 zipgrep.1 ${PREFIX}/man/man1
	cd ${WRKSRC}; install -c -o bin -g bin zip zipnote zipsplit zipcloak zipgrep ${PREFIX}/bin

.include <bsd.port.mk>
