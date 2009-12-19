# New ports collection makefile for:	eclipse-emf
# Date created:				January 13, 2004
# Whom:					alex@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	emf
PORTVERSION=	2.3.2
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_ECLIPSE:S,/eclipse/downloads/drops/,/modeling/emf/emf/downloads/drops/,}
MASTER_SITE_SUBDIR=${PORTVERSION}/R200802051830
PKGNAMEPREFIX=	eclipse-
DISTNAME=	emf-sdo-xsd-SDK-${PORTVERSION}
DIST_SUBDIR=	eclipse

MAINTAINER=	freebsd-eclipse@FreeBSD.org
COMMENT=	Eclipse Modeling Framework

RUN_DEPENDS=	eclipse:${PORTSDIR}/java/eclipse

DEPRECATED=	This plugin can be installed from within eclipse via the updater
EXPIRATION_DATE=2010-01-19

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.5+
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
