# New ports collection makefile for:	Art Of Illusion
# Date created:				Fri Jun 21 17:10:56 UTC 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	aoi
PORTVERSION=	2.0
CATEGORIES=	graphics java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	aoi
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An open source Java written 3D modelling and rendering studio

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

USE_JAVA=	yes
JAVA_VERSION=	1.4+
USE_ZIP=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/ArtOfIllusion${PORTVERSION}

EXTRACT_BEFORE_ARGS=	-a -q

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

SUB_FILES=	aoi.sh

do-install:
	${MKDIR} ${DATADIR}
	(cd ${WRKSRC} && ${FIND} ArtOfIllusion.jar Icons Plugins Scripts | \
	    ${CPIO} -pdmuv -R${SHAREOWN}:${SHAREGRP} ${DATADIR})
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} HISTORY LICENSE README ${DOCSDIR})
	${INSTALL_SCRIPT} ${WRKDIR}/aoi.sh ${PREFIX}/bin/aoi

.include <bsd.port.mk>
