# New ports collection makefile for:    unarj
# Version required:     2.4*
# Date created:         28 Dec 1994
# Whom:                 ache
#
# $Id: Makefile,v 1.11 1998/09/23 01:00:52 steve Exp $
#

DISTNAME=       unarj-2.43
CATEGORIES=	archivers
MASTER_SITES=   ftp://ftp.kiarchive.ru/pub/unix/arcers/
EXTRACT_SUFX=   .tgz

MAINTAINER=     ache@FreeBSD.ORG

do-install:
	${INSTALL} -d -m 755 -o $(SHAREOWN) -g ${SHAREGRP} \
		${PREFIX}/share/doc/unarj
	cd ${WRKSRC}; ${INSTALL_PROGRAM} unarj ${PREFIX}/bin
	cd ${WRKSRC}; ${INSTALL_DATA} unarj.doc technote.doc \
		${PREFIX}/share/doc/unarj

.include <bsd.port.mk>
