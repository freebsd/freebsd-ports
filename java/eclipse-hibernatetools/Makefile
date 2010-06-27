# New ports collection makefile for:	Eclipse Hibernate Tools
# Date created:		Mon 24 Dec 2007 11:16:09 UTC
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hibernatetools
DISTVERSION=	3.2.3.GA
PORTREVISION=	2
CATEGORIES=	java devel databases
MASTER_SITES=	SF/jboss/JBossTools/JBossTools%202.1.2.GA
PKGNAMEPREFIX=	eclipse-
DISTNAME=	HibernateTools-${DISTVERSION}
DIST_SUBDIR=	eclipse

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Hibernate3 Tools for the Eclipse IDE

## XXX - Notify the maintainer if the dependencies on either
## java/eclipse-gef of java/eclipse-webtools change
RUN_DEPENDS=	eclipse:${PORTSDIR}/java/eclipse \
		${LOCALBASE}/eclipse/features/org.eclipse.gef_3.3.2.v20080129/feature.xml:${PORTSDIR}/java/eclipse-gef \
		${LOCALBASE}/eclipse/features/org.eclipse.wst.common_core.feature_2.0.2.v200802150100-7C78EKOE_EkMNlO6f7cjpz0/feature.xml:${PORTSDIR}/java/eclipse-webtools

LICENSE=	EPL LGPL3
LICENSE_COMB=	multi

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.5+
JAVA_OS=	native

post-extract:
# avoid empty dirs since they break the automated PLIST generation
	@${FIND} ${WRKSRC} -type d -empty \
		-exec ${TOUCH} "{}/.keep_me" \;

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
