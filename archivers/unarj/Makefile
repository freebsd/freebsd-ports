# New ports collection makefile for:    unarj
# Version required:     2.41
# Date created:         28 Dec 1994
# Whom:                 ache
#
# $Id: Makefile,v 1.10 1998/08/18 22:56:50 asami Exp $
#

DISTNAME=	unarj241
PKGNAME=	unarj-2.41
CATEGORIES=	archivers
MASTER_SITES=	ftp://garbo.uwasa.fi/unix/arcers/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=     ache@FreeBSD.ORG

WRKSRC=		${WRKDIR}/unarj

do-install:
	cd ${WRKSRC}; ${INSTALL_PROGRAM} unarj ${PREFIX}/bin

.include <bsd.port.mk>
