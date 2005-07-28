# New ports collection makefile for:	mk
# Date Created:				11 May 2002
# Whom:					William Josephson
#
# $FreeBSD$
#

PORTNAME=	mk
PORTVERSION=	1.5
CATEGORIES=	devel
MASTER_SITES=	http://www.cminusminus.org/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Andrew Hume's mk by way of Research Unix, Plan 9, & Inferno

MAN1=		mk.1
PLIST_FILES=	bin/mk

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mk ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mk.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
