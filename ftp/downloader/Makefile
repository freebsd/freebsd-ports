# New ports collection makefile for:	downloader
# Version required:	0.98
# Date Created:		23 June 1999
# Whom:			Ying-Chieh Liao <ijliao@csie.nctu.edu.tw>
#
# $Id: Makefile,v 1.2 1999/06/23 00:46:26 cpiazza Exp $
#

DISTNAME=	nt-0.98
PKGNAME=	downloader-0.98
CATEGORIES=	ftp
MASTER_SITES=	http://www.krasu.ru/soft/chuchelo/ \
		ftp://linux.ru.net/pub/chuchelo/

MAINTAINER=	ijliao@csie.nctu.edu.tw

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

WRKSRC=		${WRKDIR}/${DISTNAME}/main

do-install:
		cd ${WRKSRC}; ${INSTALL_PROGRAM} nt ${PREFIX}/bin

.include <bsd.port.mk>
