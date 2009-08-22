# New ports collection makefile for:	CrossIP
# Date created:				Mon Feb  9 20:27:00 CST 2004
# Whom:					Dan Smith <dan@algenta.com>
#
# $FreeBSD$
#

PORTNAME=	crossip
DISTVERSION=	1.2
PORTREVISION=	4
CATEGORIES=	dns java
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/CrossIP%20${PORTVERSION}

MAINTAINER=	dan@algenta.com
COMMENT=	Java DNS update client for the ThatIP protocol

USE_JAVA=	yes
JAVA_VERSION=	1.2+
USE_ZIP=	yes

NO_BUILD=	yes

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

SUB_FILES=	crossip.sh

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE.txt ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/lib/CrossIP.jar ${DATADIR}
	@${INSTALL_SCRIPT} ${WRKDIR}/crossip.sh ${PREFIX}/bin/crossip

.include <bsd.port.mk>
