# New ports collection makefile for:    arc
# Version required:     5.21e
# Date created:         31 Dec 1994
# Whom:                 ache
#
# $FreeBSD$
#

DISTNAME=       arc521e.pl8
PKGNAME=        arc-5.21e
CATEGORIES=	archivers
MASTER_SITES=   ftp://ftp.kiarchive.ru/pub/unix/arcers/
EXTRACT_SUFX=   .tar.Z

MAINTAINER=     ache@FreeBSD.org

NO_WRKSUBDIR=	yes
MAN1=		arc.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/arc ${WRKSRC}/marc ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/arc.1 ${PREFIX}/man/man1
	${MKDIR} ${PREFIX}/share/doc/arc
	${INSTALL_DATA} ${WRKSRC}/Arc521.doc ${PREFIX}/share/doc/arc

.include <bsd.port.mk>
