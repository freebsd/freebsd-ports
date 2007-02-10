# New ports collection makefile for:	eclipse-webtools
# Date created:				October 14, 2005
# Whom:					markhobden@gmail.com
#
# $FreeBSD$
#

PORTNAME=	webtools
PORTVERSION=	1.5.2
CATEGORIES=	java devel www
MASTER_SITES=	${MASTER_SITE_ECLIPSE:S,/eclipse/downloads/drops/,/webtools/downloads/drops/,}
MASTER_SITE_SUBDIR=	R1.5/R-${PORTVERSION}-200610261841
PKGNAMEPREFIX=	eclipse-
DISTNAME=	wtp-R-${PORTVERSION}-200610261841
DIST_SUBDIR=	eclipse

MAINTAINER=	freebsd-eclipse@FreeBSD.org
COMMENT=	Webtools for eclipse

RUN_DEPENDS=	eclipse:${PORTSDIR}/java/eclipse \
		${LOCALBASE}/eclipse/features/org.eclipse.emf_2.2.1.v200609210005/feature.xml:${PORTSDIR}/java/eclipse-emf \
		${LOCALBASE}/eclipse/features/org.eclipse.gef_3.2.2.v20070208/feature.xml:${PORTSDIR}/java/eclipse-gef \
		${LOCALBASE}/eclipse/features/org.eclipse.ve_1.2.0.v20060530_RC2-0-a2N7MMl7/feature.xml:${PORTSDIR}/java/eclipse-vep

CONFLICTS=	eclipse-lomboz-3.*

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
