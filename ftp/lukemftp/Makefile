# New ports collection makefile for:	lukemftp
# Date created:				04 Aug 2000
# Whom:					Chris D. Faulhaber <jedgar@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lukemftp
PORTVERSION=	1.5
CATEGORIES=	ftp
MASTER_SITES=	ftp://ftp.netbsd.org/pub/NetBSD/misc/lukemftp/

MAINTAINER=	jedgar@FreeBSD.org
COMMENT=	Enhanced ftp client from NetBSD

GNU_CONFIGURE=	yes

MAN1=		lukemftp.1
PLIST_FILES=	bin/lukemftp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/ftp ${PREFIX}/bin/lukemftp
	${INSTALL_MAN} ${WRKSRC}/src/ftp.1 ${PREFIX}/man/man1/lukemftp.1

.include <bsd.port.mk>
