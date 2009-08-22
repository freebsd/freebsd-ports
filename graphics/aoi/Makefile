# New ports collection makefile for:	Art Of Illusion
# Date created:				Fri Jun 21 17:10:56 UTC 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	aoi
PORTVERSION=	2.5.1
PORTREVISION=	2
CATEGORIES=	graphics java
MASTER_SITES=	SF/${PORTNAME}/ArtOfIllusion/${PORTVERSION}
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An open source Java written 3D modelling and rendering studio

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

USE_JAVA=	yes
JAVA_VERSION=	1.4+
USE_ZIP=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/ArtOfIllusion${PORTVERSION:S/.//g}

EXTRACT_BEFORE_ARGS=	-a -q

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

SUB_FILES=	aoi.sh

do-install:
	@${ECHO_MSG} -n ">> Installing ..."
	${MKDIR} ${DATADIR}
	(cd ${WRKSRC} && ${FIND} ArtOfIllusion.jar Icons Plugins Scripts | \
	    ${CPIO} -pdmuv -R${SHAREOWN}:${SHAREGRP} ${DATADIR})
	${INSTALL_SCRIPT} ${WRKDIR}/aoi.sh ${PREFIX}/bin/aoi

.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}/..."
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} HISTORY LICENSE README ${DOCSDIR})
.endif

.include <bsd.port.mk>
