# ex:ts=8
# New ports collection makefile for:	sted
# Date created:				19 May 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	sted
PORTVERSION=	0.2.2
CATEGORIES=	editors
MASTER_SITES=	http://freebsd.t-hosting.hu/sted/

MAINTAINER=	gkovesdan@t-hosting.hu
COMMENT=	Simple/Small/Stupid Text Editor

WRKSRC=		${WRKDIR}/sted

MAN1=		sted.1
PORTDOCS=	CHANGES COPYING README
PLIST_FILES=	bin/sted

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/sted ${PREFIX}/bin
	@ ${INSTALL_MAN} ${WRKSRC}/sted.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
