# New ports collection makefile for:	openjump
# Date created:				08 May, 2009
# Whom:					Wen Heping<wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	openjump
PORTVERSION=	1.3
CATEGORIES=	graphics java geography
MASTER_SITES=	SF/jump-pilot/OldFiles

MAINTAINER=	wenheping@gmail.com
COMMENT=	An open source GIS software written in Java

TARGET_DIR=	${PREFIX}/${PORTNAME}
USE_JAVA=	yes
JAVA_VERSION=	1.5+
USE_ZIP=	yes
NO_BUILD=	yes
PORTDOCS=	OJ_improvements_from_v1.2_to_v1.3.txt gpl2_license.txt \
		Using_MrSIDPlugIn.txt apache_license.txt readme.txt

.include <bsd.port.pre.mk>

do-install:
	@${ECHO_CMD} "---> Installing JAR files"
	${MKDIR} ${TARGET_DIR}/lib
	${INSTALL_DATA} ${WRKSRC}/lib/*.jar ${TARGET_DIR}/lib
	${MKDIR} ${TARGET_DIR}/lib/ext
	@cd ${WRKSRC}/lib/ext && ${COPYTREE_SHARE} . ${TARGET_DIR}/lib/ext
	@${ECHO_MSG} "Installing startup script"
	${MKDIR} ${TARGET_DIR}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/openjump.sh ${TARGET_DIR}/bin/openjump
	${INSTALL_DATA} ${WRKSRC}/bin/workbench-properties.xml ${TARGET_DIR}/bin/
	${INSTALL_DATA} ${WRKSRC}/bin/default-plugins.xml ${TARGET_DIR}/bin/
	${INSTALL_DATA} ${WRKSRC}/bin/log4j.xml ${TARGET_DIR}/bin/

.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "---> Installing documentation"
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.else
	@${ECHO_MSG} "---> Skipping documentation"
.endif

.include <bsd.port.post.mk>
