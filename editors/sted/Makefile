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
MASTER_SITES=	http://user.tninet.se/~uxm165t/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple/Small/Stupid Text Editor

DEPRECATED=	"master site disappeared"
EXPIRATION_DATE=2005-07-31

WRKSRC=		${WRKDIR}/sted

MAN1=		sted.1

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/sted ${PREFIX}/bin
	@ ${INSTALL_MAN} ${WRKSRC}/sted.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/sted
.for file in CHANGES COPYING README
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/sted
.endfor
.endif

.include <bsd.port.mk>
