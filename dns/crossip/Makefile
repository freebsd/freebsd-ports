# Created by: Dan Smith <dan@algenta.com>
# $FreeBSD$

PORTNAME=	crossip
DISTVERSION=	1.2
PORTREVISION=	5
CATEGORIES=	dns java
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/CrossIP%20${PORTVERSION}

MAINTAINER=	dan@algenta.com
COMMENT=	Java DNS update client for the ThatIP protocol

LICENSE=	GPLv2

USES=		zip
USE_JAVA=	yes

NO_BUILD=	yes

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

SUB_FILES=	crossip.sh

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE.txt ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/lib/CrossIP.jar ${STAGEDIR}${DATADIR}
	@${INSTALL_SCRIPT} ${WRKDIR}/crossip.sh ${STAGEDIR}${PREFIX}/bin/crossip

.include <bsd.port.mk>
