# New ports collection makefile for:    rar
# Version required:     2.00 beta
# Date created:         15 May 1996
# Whom:                 ache
#
# $Id: Makefile,v 1.4 1995/05/15 20:55:27 ache Exp $
#

DISTNAME=       rar2bsdb
PKGNAME=        rar-2.00b
CATEGORIES+=	archivers
MASTER_SITES=   ftp://ftp.relcom.ru/unix/arcers/
EXTRACT_SUFX=   .tgz

NO_BUILD=       yes

MAINTAINER=     ache@FreeBSD.ORG

do-install:
	cd ${WRKSRC}; \
	$(INSTALL) -c -m $(BINMODE) -o $(BINOWN) -g $(BINGRP) rar_bsd $(PREFIX)/bin/rar; \
	$(INSTALL) -c -m $(MANMODE) -o $(MANOWN) -g $(MANGRP) rar.man $(PREFIX)/man/cat1/rar.1

.include <bsd.port.mk>
