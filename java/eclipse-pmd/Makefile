# New ports collection makefile for:	eclipse-pmd
# Date created:				October 3, 2003
# Whom:					Bruno Van Den Bossche <brvdboss@spymac.com>
#
# $FreeBSD$
#

PORTNAME=	pmd
PORTVERSION=	2.0.5.v3
PORTREVISION=	2
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pmd
PKGNAMEPREFIX=	eclipse-
DISTNAME=	pmd-eclipse3-site-2.0.5
DIST_SUBDIR=	eclipse

MAINTAINER=	java@FreeBSD.org
COMMENT=	Scan Java source code and look for potential problems

RUN_DEPENDS=	${LOCALBASE}/bin/eclipse:${PORTSDIR}/java/eclipse

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_ZIP=	yes
USE_JAVA=	yes
JAVA_EXTRACT=	jre

CPIO?=		cpio --quiet -pdmu -R

PMDVERSION=	1.8.0.v3

PLUGIN_CORE_DIR="net.sourceforge.pmd.core_${PMDVERSION}"
PLUGIN_PMD_DIR=	"net.sourceforge.pmd.eclipse_${PORTVERSION}"

PLIST_SUB+=	PLUGIN_PMD_DIR="${PLUGIN_PMD_DIR}" \
		PLUGIN_CORE_DIR="${PLUGIN_CORE_DIR}"

post-extract:
		cd ${WRKDIR}/features && ${MKDIR} ${PLUGIN_PMD_DIR} \
		&& ${CP} ${PLUGIN_PMD_DIR}.jar ${PLUGIN_PMD_DIR} \
		&& cd ${PLUGIN_PMD_DIR} \
		&& ${JAR} xvf ${PLUGIN_PMD_DIR}.jar \
		&& ${RM} ${PLUGIN_PMD_DIR}.jar

		cd ${WRKDIR}/plugins && ${MKDIR} ${PLUGIN_PMD_DIR} \
		&& ${CP} ${PLUGIN_PMD_DIR}.jar ${PLUGIN_PMD_DIR} \
		&& cd ${PLUGIN_PMD_DIR} \
		&& ${JAR} xvf ${PLUGIN_PMD_DIR}.jar \
		&& ${RM} ${PLUGIN_PMD_DIR}.jar

		cd ${WRKDIR}/plugins && ${MKDIR} ${PLUGIN_CORE_DIR} \
		&& ${CP} ${PLUGIN_CORE_DIR}.jar ${PLUGIN_CORE_DIR} \
		&& cd ${PLUGIN_CORE_DIR} \
		&& ${JAR} xvf ${PLUGIN_CORE_DIR}.jar \
		&& ${RM} ${PLUGIN_CORE_DIR}.jar

do-install:
		@${MKDIR} ${PREFIX}/eclipse
		@${MKDIR} ${PREFIX}/eclipse/plugins
		@${MKDIR} ${PREFIX}/eclipse/plugins/${PLUGIN_PMD_DIR}
		@${MKDIR} ${PREFIX}/eclipse/plugins/${PLUGIN_CORE_DIR}
		@${MKDIR} ${PREFIX}/eclipse/features/${PLUGIN_PMD_DIR}
		cd ${WRKDIR}/features/${PLUGIN_PMD_DIR} && ${FIND} . \
		  | ${CPIO} ${SHAREOWN}:${SHAREGRP} \
		${PREFIX}/eclipse/features/${PLUGIN_PMD_DIR}
		cd ${WRKDIR}/plugins/${PLUGIN_PMD_DIR} && ${FIND} . \
		  | ${CPIO} ${SHAREOWN}:${SHAREGRP} \
		  ${PREFIX}/eclipse/plugins/${PLUGIN_PMD_DIR}
		cd ${WRKDIR}/plugins/${PLUGIN_CORE_DIR} && ${FIND} . \
		  | ${CPIO} ${SHAREOWN}:${SHAREGRP} \
		  ${PREFIX}/eclipse/plugins/${PLUGIN_CORE_DIR}

.include <bsd.port.mk>
