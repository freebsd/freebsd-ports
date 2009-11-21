# New ports collection makefile for:    antlrworks
# Date created:                         December, 5th 2006
# Whom:                                 Matthias Sund <m.sund@arcor.de>
#
# $FreeBSD$

PORTNAME=	antlrworks
PORTVERSION=	1.3.1
PORTEPOCH=	1
CATEGORIES=	devel java
MASTER_SITES=	http://www.antlr.org/download/
EXTRACT_SUFX=	.jar

MAINTAINER=	m.sund@arcor.de
COMMENT=	The ANTLR GUI Development Environment

USE_JAVA=	yes
JAVA_VERSION=	1.5+
NO_BUILD=	yes

DESKTOP_ENTRIES="ANTLRWorks" \
	"ANTLR GUI Development Environment" \
	"antlrworks.png" \
	"antlrworks" \
	"Application;Development;" \
	true

do-install:
	@${MKDIR} ${JAVASHAREDIR}/${PORTNAME}
	@${INSTALL_DATA} ${DISTDIR}/${DISTNAME}.jar ${JAVASHAREDIR}/${PORTNAME}/${DISTNAME}.jar
	@${ECHO_CMD} '#!/bin/sh' > ${WRKDIR}/antlrworks
	@${ECHO_CMD} "exec java -Xmx400m -jar ${JAVASHAREDIR}/${PORTNAME}/${DISTNAME}.jar" >> ${WRKDIR}/antlrworks
	@${INSTALL_SCRIPT} ${WRKDIR}/antlrworks ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/pixmaps
	@${INSTALL_DATA} ${WRKDIR}/icons/app_32x32.png ${PREFIX}/share/pixmaps/antlrworks.png

.include <bsd.port.mk>
