# New ports collection makefile for:    splitmpg
# Date created:         Wed Jul 31 21:59:42 CDT 1996
# Whom:                 erich@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	splitmpg
PORTVERSION=	1.0
CATEGORIES=	graphics
MASTER_SITES=	ftp://metalab.unc.edu/pub/multimedia/utilities/ms-windows/mpegplay/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Splits an ISO 11172-1 into its components

NO_WRKSUBDIR=	yes
MAKEFILE=	makefile
MAN1=		splitmpeg.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/splitmpeg ${PREFIX}/bin
	${INSTALL_MAN} ${FILESDIR}/splitmpeg.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
