# New ports collection makefile for:	ftpq
# Date created:				Mon 03 Jul 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	ftpq
PORTVERSION=	0.11
CATEGORIES=	ftp
MASTER_SITES=	http://www.tranchant.freeserve.co.uk/software/

MAINTAINER=	ports@FreeBSD.org

MAN1=		ftpq.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ftpq ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ftpq.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
