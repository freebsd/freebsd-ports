# New ports collection makefile for:	CrossIP
# Date created:				Mon Feb  9 20:27:00 CST 2004
# Whom:					Dan Smith <dan@algenta.com>
#
# $FreeBSD$
#

PORTNAME=	crossip
DISTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	dns java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME:L}

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
	${CP} -R ${WRKSRC}/* ${DATADIR}
	${LN} -sf ${DATADIR}/lib/CrossIP.jar ${JAVAJARDIR}/CrossIP.jar
	@${INSTALL_SCRIPT} ${WRKDIR}/crossip.sh ${PREFIX}/bin/crossip

.include <bsd.port.mk>
