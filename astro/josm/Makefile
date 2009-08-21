# New ports collection makefile for:	josm
# Date created:		2009/02/24
# Whom:			Gleb Smirnoff <glebius@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	josm
PORTVERSION=	1981
CATEGORIES=	astro java
MASTER_SITES=	http://josm.openstreetmap.de/download/:josm \
		http://svn.openstreetmap.org/applications/editors/josm/plugins/wmsplugin/:wmsplugin
DISTNAME=	${PORTNAME}-snapshot-${PORTVERSION}.jar
DISTFILES=	${DISTNAME}:josm ${WEBKITIMG_SRC}:wmsplugin
EXTRACT_ONLY=

MAINTAINER=	glebius@FreeBSD.org
COMMENT=	A comprehensive editor for OpenStreetMap.org database

NO_WRKSUBDIR=	yes

USE_QT_VER=	4
QT_COMPONENTS=	corelib gui imageformats moc_build network script \
		rcc_build uic_build webkit

USE_JAVA=	YES
JAVA_VERSION=	1.5+

SUB_FILES=	josm.sh
SUB_LIST=	JARNAME=${DISTNAME}

WEBKITIMG=	webkit-image
WEBKITIMG_SRC=	${WEBKITIMG}.cpp

PLIST_FILES=	bin/josm ${JAVAJARDIR:C,${PREFIX}/?,,}/${DISTNAME} \
		bin/webkit-image

do-build:
	cd ${WRKSRC} && \
	    ${MOC} ${DISTDIR}/${WEBKITIMG_SRC} > ${WEBKITIMG}.h && \
	    ${CXX} ${CFLAGS} ${PTHREAD_LIBS} -I. -I${QT_INCDIR} -L${QT_LIBDIR} \
	    ${DISTDIR}/${WEBKITIMG_SRC} -o ${WEBKITIMG} -lQtCore -lQtWebKit \
	    -lQtGui

do-install:
	@${MKDIR} ${JAVAJARDIR}/
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME} ${JAVAJARDIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/josm.sh ${PREFIX}/bin/josm
	${INSTALL_PROGRAM} ${WRKDIR}/${WEBKITIMG} ${PREFIX}/bin

.include <bsd.port.mk>
