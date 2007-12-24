# New ports collection makefile for:	Eclipse Hibernate Tools
# Date created:		Mon 24 Dec 2007 11:16:09 UTC
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hibernatetools
DISTVERSION=	3.2.0.beta9a
CATEGORIES=	java devel databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	jboss
PKGNAMEPREFIX=	eclipse-
DISTNAME=	HibernateTools-${DISTVERSION}
DIST_SUBDIR=	eclipse

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Hibernate3 Tools for the Eclipse IDE

## XXX - Notify the maintainer if the dependencies on java/eclipse-webtools change
RUN_DEPENDS=	eclipse:${PORTSDIR}/java/eclipse \
		${LOCALBASE}/eclipse/features/org.eclipse.wst.common_core.feature_1.5.2.v200610140800--AXrVWXbElCl05G/feature.xml:${PORTSDIR}/java/eclipse-webtools \
		${LOCALBASE}/eclipse/plugins/org.apache.xerces_2.8.0.v200606131651/plugin.properties:${PORTSDIR}/java/eclipse-webtools \
		${LOCALBASE}/eclipse/plugins/org.eclipse.wst.common.core_1.1.100.v200608220540.jar:${PORTSDIR}/java/eclipse-webtools \
		${LOCALBASE}/eclipse/plugins/org.eclipse.wst.common.environment_1.0.100.v200608251934.jar:${PORTSDIR}/java/eclipse-webtools \
		${LOCALBASE}/eclipse/plugins/org.eclipse.wst.common.project.facet.core_1.1.1.v200608112156.jar:${PORTSDIR}/java/eclipse-webtools \
		${LOCALBASE}/eclipse/plugins/org.eclipse.wst.common.project.facet.ui_1.1.1.v200608112156.jar:${PORTSDIR}/java/eclipse-webtools \
		${LOCALBASE}/eclipse/plugins/org.eclipse.wst.common.ui_1.1.100.v200608221521.jar:${PORTSDIR}/java/eclipse-webtools \
		${LOCALBASE}/eclipse/plugins/org.eclipse.wst.common.uriresolver_1.1.100.v200609200443.jar:${PORTSDIR}/java/eclipse-webtools \
		${LOCALBASE}/eclipse/plugins/org.eclipse.wst.dtd.core_1.1.1.v200609210600.jar:${PORTSDIR}/java/eclipse-webtools \
		${LOCALBASE}/eclipse/plugins/org.eclipse.wst.sse.core_1.1.100.v200609182120.jar:${PORTSDIR}/java/eclipse-webtools \
		${LOCALBASE}/eclipse/plugins/org.eclipse.wst.xml.core_1.1.1.v200609210600.jar:${PORTSDIR}/java/eclipse-webtools \
		${LOCALBASE}/eclipse/plugins/org.eclipse.wst.xml.ui_1.0.200.v200609221505.jar:${PORTSDIR}/java/eclipse-webtools

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.4+
JAVA_OS=	native

# remove plugins that are already installed
DUPLICATE_PLUGINS=	\
	org.eclipse.wst.common.core_1.1.100.v200608220540.jar \
	org.eclipse.wst.common.environment_1.0.100.v200608251934.jar \
	org.eclipse.wst.common.project.facet.core_1.1.1.v200608112156.jar \
	org.eclipse.wst.common.project.facet.ui_1.1.1.v200608112156.jar \
	org.eclipse.wst.common.ui_1.1.100.v200608221521.jar \
	org.eclipse.wst.common.uriresolver_1.1.100.v200609200443.jar \
	org.eclipse.wst.dtd.core_1.1.1.v200609210600.jar \
	org.eclipse.wst.sse.core_1.1.100.v200609182120.jar \
	org.eclipse.wst.xml.core_1.1.1.v200609210600.jar \
	org.eclipse.wst.xml.ui_1.0.200.v200609221505.jar

post-extract:
# avoid empty dirs since they break the automated PLIST generation
	@${FIND} ${WRKSRC} -type d -empty \
		-exec ${TOUCH} "{}/.keep_me" \;
# remove plugins that are already installed
.for plugin in ${DUPLICATE_PLUGINS}
	@${RM} ${WRKSRC}/plugins/${plugin}
.endfor
	@${RM} -Rf ${WRKSRC}/plugins/org.apache.xerces_2.8.0.v200606131651/

do-install:
# create destination dir
	@${MKDIR} ${PREFIX}/eclipse
# install both files and directories
	@(cd ${WRKSRC} && \
		${FIND} -s features plugins -type d \
			-exec ${MKDIR} "${PREFIX}/eclipse/{}" \; && \
		${FIND} -s features plugins -not -type d \
			-exec ${INSTALL_DATA} "{}" "${PREFIX}/eclipse/{}" \; \
	)

# used to manually generate the plist files
generate-plist-locally: build
# annotate installation files
	@(cd ${WRKSRC} && ${FIND} -s features plugins -not -type d) \
		| ${SED} -ne 's,^,eclipse/,p' > ${PLIST}
# annotate installation directories
	@(cd ${WRKSRC} && ${FIND} -s -d features plugins -type d) \
		| ${GREP} -vE '^plugins$$|^features$$' \
		| ${SED} -ne 's,^,@dirrm eclipse/,p' >> ${PLIST}

.include <bsd.port.mk>
