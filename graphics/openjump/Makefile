# New ports collection makefile for:	openjump
# Date created:				08 May, 2009
# Whom:					Wen Heping<wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	openjump
PORTVERSION=	1.4.2
CATEGORIES=	graphics java geography
MASTER_SITES=	SF/jump-pilot/OpenJUMP/${PORTVERSION}
DISTNAME=	${PORTNAME}-bin-${PORTVERSION}

MAINTAINER=	rhurlin@gwdg.de
COMMENT=	An open source GIS software written in Java

TARGET_DIR=	${PREFIX}/${PORTNAME}
USE_JAVA=	yes
JAVA_VERSION=	1.5+
USE_ZIP=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.pre.mk>

do-install:
	@${ECHO_CMD} "---> Installing JAR files"
	${MKDIR} ${TARGET_DIR}/lib
	${INSTALL_DATA} ${WRKSRC}/lib/*.jar ${TARGET_DIR}/lib
	${MKDIR} ${TARGET_DIR}/lib/ext
	@cd ${WRKSRC}/lib/ext && ${COPYTREE_SHARE} . ${TARGET_DIR}/lib/ext
	@${RM} ${PREFIX}/openjump/lib/ext/*.dll
	@${ECHO_MSG} "Installing startup script"
	${MKDIR} ${TARGET_DIR}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/oj_linux.sh ${TARGET_DIR}/bin/openjump
	${LN} -sf ${PREFIX}/openjump/bin/openjump ${PREFIX}/bin/openjump
	${INSTALL_DATA} ${WRKSRC}/bin/workbench-properties.xml ${TARGET_DIR}/bin/
	${INSTALL_DATA} ${WRKSRC}/bin/default-plugins.xml ${TARGET_DIR}/bin/
	${INSTALL_DATA} ${WRKSRC}/bin/log4j.xml ${TARGET_DIR}/bin/

.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "---> Installing documentation"
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Changes.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/licenses/apache_license.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/licenses/cpl-1.0.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/licenses/jdom_license.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/licenses/jmath_license.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/licenses/jython_license.txt ${DOCSDIR}
.else
	@${ECHO_MSG} "---> Skipping documentation"
.endif

.include <bsd.port.post.mk>
