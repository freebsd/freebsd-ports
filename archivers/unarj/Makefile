# New ports collection makefile for:    unarj
# Version required:     2.41
# Date created:         28 Dec 1994
# Whom:                 ache
#
# $Id: Makefile,v 1.8 1998/01/26 10:11:37 asami Exp $
#

DISTNAME=	unarj
PKGNAME=	unarj-2.41
CATEGORIES=	archivers
MASTER_SITES=	ftp://garbo.uwasa.fi/unix/arcers/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=     ache@FreeBSD.ORG

do-install:
	cd ${WRKSRC}; ${INSTALL_PROGRAM} ${DISTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
