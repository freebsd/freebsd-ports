# New ports collection makefile for:	eclipse-emf
# Date created:				January 13, 2004
# Whom:					alex@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	emf
PORTVERSION=	2.0.1
PORTREVISION=	3
CATEGORIES=	java devel
MASTER_SITES=	http://download.eclipse.org/tools/emf/downloads/drops/2.0.1/R200409171617/
PKGNAMEPREFIX=	eclipse-
DISTNAME=	emf-sdo-xsd-SDK-${PORTVERSION}
DIST_SUBDIR=	eclipse

MAINTAINER=	java@FreeBSD.ORG
COMMENT=	Eclipse Modeling Framework

RUN_DEPENDS=    ${LOCALBASE}/bin/eclipse:${PORTSDIR}/java/eclipse

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.4+
JAVA_OS=	native
PLIST_SUB=	RELEASEVERSION=${PORTVERSION}

do-install:
		@${MKDIR} ${PREFIX}/eclipse
		@${CP} -r ${WRKSRC}/eclipse/plugins ${PREFIX}/eclipse
		@${CP} -r ${WRKSRC}/eclipse/features ${PREFIX}/eclipse

.include <bsd.port.mk>
