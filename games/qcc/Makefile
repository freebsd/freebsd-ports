# New ports collection makefile for:		qcc
# Version required:				1.01
# Date created:					October 25th 1996
# Whom:						jfitz@FreeBSD.org
#
# $FreeBSD$
#

DISTNAME=	qcc
PKGNAME=	qcc-1.01
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.idsoftware.com/idstuff/source/

MAINTAINER=	jfitz@freebsd.org

WRKSRC=		${WRKDIR}/send
MAKEFILE=	makefile

do-install:	
		${INSTALL_PROGRAM} ${WRKSRC}/qcc ${PREFIX}/bin
		@ ${MKDIR} ${PREFIX}/share/qcc/v101qc
		${INSTALL_DATA} ${WRKSRC}/readme.txt ${PREFIX}/share/qcc
		${INSTALL_DATA} ${WRKSRC}/v101qc/* ${PREFIX}/share/qcc/v101qc

.include <bsd.port.mk>
