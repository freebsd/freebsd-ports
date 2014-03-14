# Created by: vj562001@yahoo.de
# $FreeBSD$

PORTNAME=	ocl
DISTVERSION=	1.1
PORTREVISION=	4
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_ECLIPSE:S,/eclipse/downloads/drops/,/modeling/mdt/ocl/downloads/drops/,}
MASTER_SITE_SUBDIR=${DISTVERSION}.0/R200706201142
PKGNAMEPREFIX=	eclipse-
DISTNAME=	mdt-ocl-SDK-${DISTVERSION}
DIST_SUBDIR=	eclipse

MAINTAINER=	vj562001@yahoo.de
COMMENT=	Implementation of the OCL OMG standard for EMF-based models

RUN_DEPENDS=	eclipse:${PORTSDIR}/java/eclipse \
		${LOCALBASE}/share/eclipse/dropins/emf:${PORTSDIR}/java/eclipse-emf

USES=		zip
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+
JAVA_OS=	native

NO_STAGE=	yes
do-install:
		@${MKDIR} ${PREFIX}/lib/eclipse
		@${CP} -r ${WRKSRC}/eclipse/plugins ${PREFIX}/lib/eclipse
		@${CP} -r ${WRKSRC}/eclipse/features ${PREFIX}/lib/eclipse
		@(cd ${WRKSRC}; ${FIND} -s eclipse/features eclipse/plugins -not -type d) | ${SED} -e 's,^eclipse,lib/eclipse,' >> ${TMPPLIST}
		@(cd ${WRKSRC}; ${FIND} -s -d eclipse/features eclipse/plugins -type d) \
			| ${GREP} -vE 'eclipse/plugins$$|eclipse/features$$' \
			| ${SED} -ne 's,^,@dirrm lib/,p' >> ${TMPPLIST}

.include <bsd.port.mk>
