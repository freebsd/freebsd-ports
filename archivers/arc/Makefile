# New ports collection makefile for:    arc
# Date created:         31 Dec 1994
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	arc
PORTVERSION=	5.21j
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ache@FreeBSD.org
COMMENT=	Create & extract files from DOS .ARC files

MAN1=		arc.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/arc ${WRKSRC}/marc ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/arc.1 ${PREFIX}/man/man1
	${MKDIR} ${PREFIX}/share/doc/arc
	${INSTALL_DATA} ${WRKSRC}/Arc521.doc ${PREFIX}/share/doc/arc

.include <bsd.port.mk>
