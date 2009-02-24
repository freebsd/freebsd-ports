# New ports collection makefile for:	josm
# Date created:		2009/02/24
# Whom:			Gleb Smirnoff <glebius@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	josm
PORTVERSION=	1437
CATEGORIES=	astro java
MASTER_SITES=	http://josm.openstreetmap.de/download/
DISTNAME=	${PORTNAME}-snapshot-${PORTVERSION}
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	glebius@FreeBSD.org
COMMENT=	A comprehensive editor for OpenStreetMap.org database

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

USE_JAVA=	YES
JAVA_VERSION=	1.5+

SUB_FILES=	josm.sh
SUB_LIST=	JARNAME=${DISTFILES}

PLIST_FILES=	bin/josm ${DISTFILES:S,^,${JAVAJARDIR}/,:C,${PREFIX}/?,,}

do-install:
	@${MKDIR} ${JAVAJARDIR}/
	${INSTALL_DATA} ${DISTDIR}/${DISTFILES} ${JAVAJARDIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/josm.sh ${PREFIX}/bin/josm

.include <bsd.port.mk>
