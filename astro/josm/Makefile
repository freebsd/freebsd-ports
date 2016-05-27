# Created by: Gleb Smirnoff <glebius@FreeBSD.org>
# $FreeBSD$

PORTNAME=	josm
PORTVERSION=	10168
CATEGORIES=	astro java
MASTER_SITES=	http://josm.openstreetmap.de/download/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}-snapshot-${PORTVERSION}.jar
EXTRACT_SUFX=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Comprehensive editor for OpenStreetMap.org database

LICENSE=	GPLv2+

NO_WRKSUBDIR=	yes

USE_JAVA=	yes
JAVA_VERSION=	1.7+

JOSM_MEMORY_LIMIT?=1024

NO_BUILD=	yes
NO_ARCH=	yes

SUB_FILES=	josm.sh
SUB_LIST=	JARNAME=${DISTNAME} JOSM_MEMORY_LIMIT=${JOSM_MEMORY_LIMIT}

PLIST_FILES=	bin/josm ${JAVAJARDIR:C,${PREFIX}/?,,}/${DISTNAME}

pre-everything::
	@${ECHO_CMD} "You can change limit of memory available to josm by defining"
	@${ECHO_CMD} "JOSM_MEMORY_LIMIT variable in /etc/make.conf. Default is 1024 (MB)."

do-install:
	${MKDIR} ${STAGEDIR}${JAVAJARDIR}/
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME} ${STAGEDIR}${JAVAJARDIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/josm.sh ${STAGEDIR}${PREFIX}/bin/josm

.include <bsd.port.mk>
