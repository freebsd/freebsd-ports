# ex:ts=8
# Ports collection makefile for:  Rawio
# Version required: 0.0
# Date created:			  Sun Aug 08, 1999
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

DISTNAME=	rawio-1.1
CATEGORIES=	benchmarks
MASTER_SITES=	ftp://ftp.lemis.com/pub/

MAINTAINER=	obrien@FreeBSD.org

NO_WRKSUBDIR=	yes
MAN1=		rawio.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rawio ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/rawio.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
