# New ports collection makefile for:    unarj
# Version required:     2.41
# Date created:         28 Dec 1994
# Whom:                 ache
#
# $Id: Makefile,v 1.1.1.1 1994/12/26 09:10:32 ache Exp $
#
DISTFILES=      unarj241.tar.Z
DISTNAME=       unarj
MASTER_SITES=	ftp://garbo.uwasa.fi/unix/arcers/

install:
	cd ${WRKSRC}; install -cs -o bin -g bin -m755 ${DISTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
