# New ports collection makefile for:	downloader
# Version required:	1.0b2	
# Date Created:		23 June 1999
# Whom:			Ying-Chieh Liao <ijliao@csie.nctu.edu.tw>
#
# $FreeBSD$
#

DISTNAME=	nt-1.05-BETA
PKGNAME=	downloader-1.0b5
CATEGORIES=	ftp
MASTER_SITES=	http://www.krasu.ru/soft/chuchelo/

MAINTAINER=	ijliao@csie.nctu.edu.tw

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

WRKSRC=		${WRKDIR}/${DISTNAME}/main

do-install:
		cd ${WRKSRC}; ${INSTALL_PROGRAM} nt ${PREFIX}/bin

.include <bsd.port.mk>
