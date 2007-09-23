# New ports collection makefile for:	eclipse-ocl
# Date created:				August, 25 2007
# Whom:					vj562001@yahoo.de
#
# $FreeBSD$
#

PORTNAME=	ocl
DISTVERSION=	1.1
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_ECLIPSE:S,/eclipse/downloads/drops/,/modeling/mdt/ocl/downloads/drops/,}
MASTER_SITE_SUBDIR=${DISTVERSION}.0/R200706201142
PKGNAMEPREFIX=	eclipse-
DISTNAME=	mdt-ocl-SDK-${DISTVERSION}
DIST_SUBDIR=	eclipse

MAINTAINER=	vj562001@yahoo.de
COMMENT=	Implementation of the OCL OMG standard for EMF-based models

RUN_DEPENDS=	eclipse:${PORTSDIR}/java/eclipse \
		${LOCALBASE}/eclipse/features/org.eclipse.emf_2.2.1.v200609210005/feature.xml:${PORTSDIR}/java/eclipse-emf

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
