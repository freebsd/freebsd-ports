# New ports collection makefile for:	drjava
# Date created:		2006-04-13
# Whom:			Nicola Vitale	<nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	drjava
DISTVERSION=	20080904-r4668
#PORTREVISION=	0
CATEGORIES=	editors java
MASTER_SITES=	SF/${PORTNAME}/1.%20DrJava%20Stable%20Releases/${PORTNAME}-stable-20080904-r4668
DISTNAME=	${PORTNAME}-stable-${PORTVERSION:S|.|-|g}
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A lightweight IDE for writing Java programs

NO_BUILD=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.4+

SUB_FILES=	${PORTNAME}
SUB_LIST=	DRJAVAJAR=${DRJAVAJAR}
PLIST_SUB=	DRJAVAJAR=${DRJAVAJAR}

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

DRJAVAJAR=	${DISTFILES}

do-install:
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${DISTDIR}/${DISTFILES} ${DATADIR}/${DRJAVAJAR}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
