# New ports collection makefile for:    unarj
# Version required:     2.41
# Date created:         28 Dec 1994
# Whom:                 ache
#
# $Id: Makefile,v 1.2 1995/04/01 12:43:28 jkh Exp $
#

DISTNAME=       unarj
PKGNAME=	unarj-2.41
CATEGORIES+=	archivers
MASTER_SITES=	ftp://garbo.uwasa.fi/unix/arcers/
DISTFILES=      unarj241.tar.Z

MAINTAINER=     ache@FreeBSD.ORG

install:
	cd ${WRKSRC}; install -cs -o bin -g bin -m755 ${DISTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
