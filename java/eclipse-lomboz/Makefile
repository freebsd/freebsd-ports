# New ports collection makefile for:	eclipse-lomboz
# Date created:				June 18, 2004
# Whom:					sugimura@jp.FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	lomboz
PORTVERSION=	3.1.r2
PORTREVISION=	1
CATEGORIES=	java devel
MASTER_SITES=	http://download.forge.objectweb.org/lomboz/ \
		http://download.fr2.forge.objectweb.org/lomboz/ \
		http://download.zh.forge.objectweb.org/lomboz/
PKGNAMEPREFIX=	eclipse-
DISTNAME=	lomboz-emf-gef-jem-${PORTVERSION:S/.r/RC/}
DIST_SUBDIR=	eclipse

MAINTAINER=	sugimura@jp.FreeBSD.ORG
COMMENT=	A J2EE developer tool build as a plugin for the eclipse platform

RUN_DEPENDS=	${LOCALBASE}/bin/eclipse:${PORTSDIR}/java/eclipse

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
