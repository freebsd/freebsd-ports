# New ports collection makefile for:    zip
# Version required:     2.0.1
# Date created:         22 Dec 1994
# Whom:                 ache
#
# $Id: Makefile,v 1.1.1.1 1994/12/22 12:33:40 ache Exp $
#
DISTNAME=       zip201
EXTRACT_SUFX=   .tar.Z
MASTER_SITES=	ftp://garbo.uwasa.fi/unix/arcers/
CATEGORIES+=	archivers
ALL_TARGET=     freebsd

pre-install:
	@mkdir -p ${PREFIX}/bin
	@mkdir -p ${PREFIX}/man/man1

install:
	cd ${WRKSRC}; install -c -o bin -g bin zip.1 zipgrep.1 ${PREFIX}/man/man1
	cd ${WRKSRC}; install -c -o bin -g bin zip zipnote zipsplit zipcloak zipgrep ${PREFIX}/bin

.include <bsd.port.mk>
