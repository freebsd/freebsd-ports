# New ports collection makefile for:    rar
# Version required:     2.00 beta
# Date created:         15 May 1996
# Whom:                 ache
#
# $Id: Makefile,v 1.1.1.1 1996/05/15 19:19:40 ache Exp $
#

DISTNAME=       rar2bsdb
PKGNAME=        rar-2.00b
CATEGORIES=	archivers
MASTER_SITES=   ftp://ftp.relcom.ru/unix/arcers/
EXTRACT_SUFX=   .tgz

MAINTAINER=     ache@FreeBSD.ORG

NO_BUILD=       yes

do-install:
	cd ${WRKSRC}; \
	${INSTALL_PROGRAM} rar_bsd ${PREFIX}/bin/rar; \
	${INSTALL_MAN} rar.man ${PREFIX}/man/cat1/rar.1

.include <bsd.port.mk>
