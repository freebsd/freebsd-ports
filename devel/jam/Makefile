# New ports collection makefile for:	jam
# Date created:		10 July 1998
# Whom:			Jeffrey Hsu <hsu@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	jam
PORTVERSION=	2.3
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp1.perforce.com/pub/jam/

MAINTAINER=	ports@FreeBSD.org

NO_WRKSUBDIR=	yes
USE_ZIP=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin.freebsd/jam ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/jam
	${INSTALL_DATA} ${WRKSRC}/*.html ${PREFIX}/share/doc/jam
.endif

.include <bsd.port.mk>
