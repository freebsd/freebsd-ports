# New ports collection makefile for:	tnftp
# Date created:				28 Jan 2004
# Whom:					Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $FreeBSD$
#

PORTNAME=	tnftp
PORTVERSION=	20030825
CATEGORIES=	ftp
MASTER_SITES=	ftp://ftp.netbsd.org/pub/NetBSD/misc/tnftp/

MAINTAINER=	tmclaugh@sdf.lonestar.org
COMMENT=	Enhanced ftp client from NetBSD

GNU_CONFIGURE=	yes

MAN1=		tnftp.1
PLIST_FILES=	bin/tnftp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/ftp ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/src/ftp.1 ${PREFIX}/man/man1/

.include <bsd.port.mk>
