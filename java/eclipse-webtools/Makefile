# New ports collection makefile for:	eclipse-webtools
# Date created:				October 14, 2005
# Whom:					markhobden@gmail.com
#
# $FreeBSD$
#

PORTNAME=	webtools
PORTVERSION=	2.0.3
PORTREVISION=	3
CATEGORIES=	java devel www
MASTER_SITES=	${MASTER_SITE_ECLIPSE:S,/eclipse/downloads/drops/,/webtools/downloads/drops/,}
MASTER_SITE_SUBDIR=	R2.0/R-${PORTVERSION}-20080710044639/
PKGNAMEPREFIX=	eclipse-
DISTNAME=	wtp-R-${PORTVERSION}-20080710044639
DIST_SUBDIR=	eclipse

MAINTAINER=	freebsd-eclipse@FreeBSD.org
COMMENT=	Webtools for eclipse

RUN_DEPENDS=	eclipse:${PORTSDIR}/java/eclipse \
		${LOCALBASE}/lib/eclipse/features/org.eclipse.emf_2.3.2.v200802051830/feature.xml:${PORTSDIR}/java/eclipse-emf \
		${LOCALBASE}/lib/eclipse/features/org.eclipse.gef_3.3.2.v20080129/feature.xml:${PORTSDIR}/java/eclipse-gef

CONFLICTS=	eclipse-lomboz-3.*

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.5+
JAVA_OS=	native

# remove files that already exist on the RUN_DEPENDS java/eclipse port
REMOVE_DUPLICATE_FILES=	\
	eclipse/plugins/javax.servlet.jsp_2.0.0.v200706191603.jar \
	eclipse/plugins/javax.servlet_2.4.0.v200706111738.jar \
	eclipse/plugins/org.apache.commons.el_1.0.0.v200706111724.jar \
	eclipse/plugins/org.apache.commons.logging_1.0.4.v200706111724.jar

post-extract:
.for file in ${REMOVE_DUPLICATE_FILES}
	@${RM} -f ${WRKSRC}/${file}
.endfor

do-install:
		@${MKDIR} ${PREFIX}/lib/eclipse
		@${CP} -r ${WRKSRC}/eclipse/plugins ${PREFIX}/lib/eclipse
		@${CP} -r ${WRKSRC}/eclipse/features ${PREFIX}/lib/eclipse
		@(cd ${WRKSRC}; ${FIND} -s eclipse/features eclipse/plugins -not -type d) | ${SED} -e 's,^eclipse,lib/eclipse,' >> ${TMPPLIST}
		@(cd ${WRKSRC}; ${FIND} -s -d eclipse/features eclipse/plugins -type d) \
			| ${GREP} -vE 'eclipse/plugins$$|eclipse/features$$' \
			| ${SED} -ne 's,^,@dirrm lib/,p' >> ${TMPPLIST}

.include <bsd.port.mk>
