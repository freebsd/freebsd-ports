# New ports collection makefile for:    unarj
# Version required:     2.41
# Date created:         28 Dec 1994
# Whom:                 ache
#
# $Id: Makefile,v 1.1.1.1 1994/12/28 01:55:04 ache Exp $
#
DISTFILES=      unarj241.tar.Z
DISTNAME=       unarj
MASTER_SITES=	ftp://garbo.uwasa.fi/unix/arcers/
CATEGORIES+=	archivers

install:
	cd ${WRKSRC}; install -cs -o bin -g bin -m755 ${DISTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
