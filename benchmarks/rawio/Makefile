# ex:ts=8
# Ports collection makefile for:  Rawio
# Date created:			  Sun Aug 08, 1999
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	rawio
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	benchmarks
MASTER_SITES=	ftp://ftp.lemis.com/pub/

MAINTAINER=	grog@FreeBSD.org
COMMENT=	Test performance of low-level storage devices

NO_WRKSUBDIR=	yes
MAN1=		rawio.1
PLIST_FILES=	bin/rawio

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rawio ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/rawio.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
