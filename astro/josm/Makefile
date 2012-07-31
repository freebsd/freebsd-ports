# New ports collection makefile for:	josm
# Date created:		2009/02/24
# Whom:			Gleb Smirnoff <glebius@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	josm
PORTVERSION=	5356
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

SUB_FILES=	josm.sh
SUB_LIST=	JARNAME=${DISTNAME} JOSM_MEMORY_LIMIT=${JOSM_MEMORY_LIMIT}

WEBKITIMG=	webkit-image
WEBKITIMG_SRC=	${WEBKITIMG}.cpp

PLIST_FILES=	bin/josm ${JAVAJARDIR:C,${PREFIX}/?,,}/${DISTNAME}

OPTIONS=	WEBKIT_IMAGE "Build webkit-image (needed for Yahoo imagery)" off

.include <bsd.port.options.mk>

pre-everything::
	@${ECHO_CMD} "You can change limit of memory available to josm by defining"
	@${ECHO_CMD} "JOSM_MEMORY_LIMIT variable in /etc/make.conf. Default is 1024 (MB)."

.if defined(WITH_WEBKIT_IMAGE)
PLIST_FILES+=	bin/webkit-image

USE_QT4=	corelib gui webkit moc_build

do-build:
	cd ${WRKSRC} && \
		${MOC} ${DISTDIR}/${WEBKITIMG_SRC} > ${WEBKITIMG}.h && \
		${CXX} ${CFLAGS} ${PTHREAD_LIBS} -I. -I${QT_INCDIR} -L${QT_LIBDIR} \
		${DISTDIR}/${WEBKITIMG_SRC} -o ${WEBKITIMG} -lQtCore -lQtWebKit \
		-lQtGui
.else
# setting NO_BUILD here won't work
do-build:
	@${DO_NADA}
.endif

do-install:
	${MKDIR} ${JAVAJARDIR}/
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME} ${JAVAJARDIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/josm.sh ${PREFIX}/bin/josm
.if defined(WITH_WEBKIT_IMAGE)
	${INSTALL_PROGRAM} ${WRKDIR}/${WEBKITIMG} ${PREFIX}/bin
.endif

.include <bsd.port.mk>
