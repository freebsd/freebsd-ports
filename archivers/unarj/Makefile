# New ports collection makefile for:    unarj
# Version required:     2.41
# Date created:         28 Dec 1994
# Whom:                 ache
#
# $Id: Makefile,v 1.5 1995/04/24 10:58:54 asami Exp $
#

DISTNAME=       unarj
PKGNAME=	unarj-2.41
CATEGORIES=	archivers
MASTER_SITES=	ftp://garbo.uwasa.fi/unix/arcers/
DISTFILES=      unarj241.tar.Z

MAINTAINER=     ache@FreeBSD.ORG

do-install:
	cd ${WRKSRC}; ${INSTALL_PROGRAM} ${DISTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
