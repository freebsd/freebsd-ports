# New ports collection makefile for:	antlrworks
# Date created:				December, 5th 2006
# Whom:					Matthias Sund <m.sund@arcor.de>
#
# $FreeBSD$

PORTNAME=	antlrworks
PORTVERSION=	1.0.2
PORTEPOCH=	1
CATEGORIES=	devel java
MASTER_SITES=	http://www.antlr.org/download/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	m.sund@arcor.de
COMMENT=	The ANTLR GUI Development Environment

USE_ZIP=	yes
EXTRACT_AFTER_ARGS=	"-d${DISTNAME}"
USE_X_PREFIX=	yes

ONLY_FOR_ARCHS=	i386 amd64

USE_JAVA=	yes
JAVA_VERSION=	1.4+
JAVA_OS=	native
JAVA_RUN=	yes

USE_ANT=	yes
ALL_TARGET=	build

PLIST_FILES=	bin/antlrworks %%DATADIR%%/antlrworks.jar share/pixmaps/antlrworks.png
PLIST_DIRS=	%%DATADIR%%

DESKTOP_ENTRIES="ANTLRWorks" \
		"ANTLR GUI Development Environment" \
		"antlrworks.png" \
		"antlrworks" \
		"Application;Development;" \
		true

post-build:
	@${ECHO_CMD} '#!/bin/sh' > ${WRKSRC}/antlrworks
	@${ECHO_CMD} "exec java -Xmx400m -jar ${DATADIR}/antlrworks.jar" >> ${WRKSRC}/antlrworks

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/antlrworks ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/dist/antlrworks-1.0.2.jar ${DATADIR}/antlrworks.jar
	${MKDIR} ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/src/aw/org/antlr/works/icons/app_32x32.png ${PREFIX}/share/pixmaps/antlrworks.png

.include <bsd.port.mk>
