# New ports collection makefile for:	mk
# Date Created:				11 May 2002
# Whom:					William Josephson
#
# $FreeBSD$
#

PORTNAME=	mk
PORTVERSION=	1.3
CATEGORIES=	devel
MASTER_SITES=	http://www.cminusminus.org/download/

MAINTAINER=	mk-port@morphisms.net

MAN1=		mk.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mk ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mk.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
