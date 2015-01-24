# Created by: alex@FreeBSD.org
# $FreeBSD$

PORTNAME=	vep
PORTVERSION=	1.2
PORTREVISION=	5
PORTEPOCH=	1
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_ECLIPSE:S,/eclipse/downloads/drops/,/tools/ve/downloads/drops/,}
MASTER_SITE_SUBDIR=	R-${PORTVERSION}-200606280938
PKGNAMEPREFIX=	eclipse-
DISTNAME=	VE-SDK-${PORTVERSION}
DIST_SUBDIR=	eclipse

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Framework for creating GUI builders for Eclipse

RUN_DEPENDS=	eclipse:${PORTSDIR}/java/eclipse \
		eclipse-emf>0:${PORTSDIR}/java/eclipse-emf \
		eclipse-gef>0:${PORTSDIR}/java/eclipse-gef

USES=		zip
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+
JAVA_OS=	native

do-install:
		@${MKDIR} ${STAGEDIR}${PREFIX}/lib/eclipse
		@${CP} -r ${WRKSRC}/eclipse/plugins ${STAGEDIR}${PREFIX}/lib/eclipse
		@${CP} -r ${WRKSRC}/eclipse/features ${STAGEDIR}${PREFIX}/lib/eclipse
		@(cd ${WRKSRC}; ${FIND} -s eclipse/features eclipse/plugins -not -type d) | ${SED} -e 's,^eclipse,lib/eclipse,' >> ${TMPPLIST}
		@(cd ${WRKSRC}; ${FIND} -s -d eclipse/features eclipse/plugins -type d -empty) \
			| ${GREP} -vE 'eclipse/plugins$$|eclipse/features$$' \
			| ${SED} -ne 's,^,@dir lib/,p' >> ${TMPPLIST}

.include <bsd.port.mk>
