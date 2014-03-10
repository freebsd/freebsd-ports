# Created by: sugimura@jp.FreeBSD.org
# $FreeBSD$

PORTNAME=	lomboz
PORTVERSION=	3.1.r2
PORTREVISION=	5
CATEGORIES=	java devel
MASTER_SITES=	http://download.forge.objectweb.org/lomboz/ \
		http://download.fr2.forge.objectweb.org/lomboz/ \
		http://download.zh.forge.objectweb.org/lomboz/
PKGNAMEPREFIX=	eclipse-
DISTNAME=	lomboz-emf-gef-jem-${PORTVERSION:S/.r/RC/}
DIST_SUBDIR=	eclipse

MAINTAINER=	freebsd-eclipse@FreeBSD.org
COMMENT=	A J2EE developer tool build as a plugin for the eclipse platform

RUN_DEPENDS=	${LOCALBASE}/bin/eclipse:${PORTSDIR}/java/eclipse

CONFLICTS=	eclipse-webtools-0.7*

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
