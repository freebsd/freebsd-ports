# New ports collection makefile for:	eclipse-lomboz
# Date created:				June 18, 2004
# Whom:					sugimura@jp.FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	lomboz
PORTVERSION=	3.1.r2
PORTREVISION=	0
CATEGORIES=	java devel
MASTER_SITES=	http://download.fr2.forge.objectweb.org/lomboz/ \
		http://download.us.forge.objectweb.org/lomboz/ \
		http://download.forge.objectweb.org/lomboz/
PKGNAMEPREFIX=	eclipse-
DISTNAME=	lomboz-${PORTVERSION:S/.r/RC/}
DIST_SUBDIR=	eclipse

MAINTAINER=	sugimura@jp.FreeBSD.ORG
COMMENT=	A J2EE developer tool build as a plugin for the eclipse platform

RUN_DEPENDS=	${LOCALBASE}/bin/eclipse:${PORTSDIR}/java/eclipse \
		${LOCALBASE}/eclipse/features/org.eclipse.emf_2.1.1/feature.xml:${PORTSDIR}/java/eclipse-emf \
		${LOCALBASE}/eclipse/features/org.eclipse.gef_3.1.1/feature.xml:${PORTSDIR}/java/eclipse-gef \
		${LOCALBASE}/eclipse/features/org.eclipse.jem_1.1.0.1/feature.xml:${PORTSDIR}/java/eclipse-vep

CONFLICTS=	eclipse-webtools-0.7*

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.4+
JAVA_OS=	native

do-install:
		@${MKDIR} ${PREFIX}/eclipse
		@${CP} -r ${WRKSRC}/eclipse/plugins ${PREFIX}/eclipse
		@${CP} -r ${WRKSRC}/eclipse/features ${PREFIX}/eclipse
		@(cd ${WRKSRC}; ${FIND} -s eclipse/features eclipse/plugins -not -type d) >> ${TMPPLIST}
		@(cd ${WRKSRC}; ${FIND} -s -d eclipse/features eclipse/plugins -type d) \
			| ${GREP} -vE 'eclipse/plugins$$|eclipse/features$$' \
			| ${SED} -ne 's,^,@dirrm ,p' >> ${TMPPLIST}

.include <bsd.port.mk>
