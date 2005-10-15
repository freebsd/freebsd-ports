# New ports collection makefile for:	eclipse-webtools
# Date created:				October 14, 2005
# Whom:					markhobden@gmail.com
#
# $FreeBSD$
#

PORTNAME=	webtools
PORTVERSION=	0.7
CATEGORIES=	java devel www
MASTER_SITES=	http://download.eclipse.org/webtools/downloads/drops/R-${PORTVERSION}-200507290654/
PKGNAMEPREFIX=	eclipse-
DISTNAME=	wtp-${PORTVERSION}
DIST_SUBDIR=	eclipse

MAINTAINER=	freebsd-eclipse@FreeBSD.org
COMMENT=	Webtools for eclipse

RUN_DEPENDS=	${LOCALBASE}/bin/eclipse:${PORTSDIR}/java/eclipse \
		${LOCALBASE}/eclipse/features/org.eclipse.emf_2.1.1/feature.xml:${PORTSDIR}/java/eclipse-emf \
		${LOCALBASE}/eclipse/features/org.eclipse.gef_3.1.1/feature.xml:${PORTSDIR}/java/eclipse-gef \
		${LOCALBASE}/eclipse/features/org.eclipse.jem_1.1.0.1/feature.xml:${PORTSDIR}/java/eclipse-vep

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
