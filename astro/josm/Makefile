# New ports collection makefile for:	josm
# Date created:		2009/02/24
# Whom:			Gleb Smirnoff <glebius@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	josm
PORTVERSION=	5531
CATEGORIES=	astro java
MASTER_SITES=	http://josm.openstreetmap.de/download/:josm \
		http://mirror.amdmi3.ru/distfiles/:josm \
		http://mirror.amdmi3.ru/distfiles/:wmsplugin
DISTNAME=	${PORTNAME}-snapshot-${PORTVERSION}.jar
DISTFILES=	${DISTNAME}:josm ${WEBKITIMG_SRC}:wmsplugin
EXTRACT_ONLY=	# empty

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A comprehensive editor for OpenStreetMap.org database

NO_WRKSUBDIR=	yes

USE_JAVA=	YES
JAVA_VERSION=	1.5+

JOSM_MEMORY_LIMIT?=1024

NO_BUILD=	yes

SUB_FILES=	josm.sh
SUB_LIST=	JARNAME=${DISTNAME} JOSM_MEMORY_LIMIT=${JOSM_MEMORY_LIMIT}

WEBKITIMG=	webkit-image
WEBKITIMG_SRC=	${WEBKITIMG}.cpp

PLIST_FILES=	bin/josm ${JAVAJARDIR:C,${PREFIX}/?,,}/${DISTNAME}

pre-everything::
	@${ECHO_CMD} "You can change limit of memory available to josm by defining"
	@${ECHO_CMD} "JOSM_MEMORY_LIMIT variable in /etc/make.conf. Default is 1024 (MB)."

do-install:
	${MKDIR} ${JAVAJARDIR}/
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME} ${JAVAJARDIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/josm.sh ${PREFIX}/bin/josm
.if defined(WITH_WEBKIT_IMAGE)
	${INSTALL_PROGRAM} ${WRKDIR}/${WEBKITIMG} ${PREFIX}/bin
.endif

.include <bsd.port.mk>
