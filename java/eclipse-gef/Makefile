# New ports collection makefile for:	eclipse-gef
# Date created:				July 8, 2003
# Whom:					olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	gef
PORTVERSION=	3.0.1
PORTREVISION=	2
CATEGORIES=	java devel
MASTER_SITES=	http://download.eclipse.org/tools/gef/downloads/drops/R-3.0.1-200408311615/
PKGNAMEPREFIX=	eclipse-
DISTNAME=	GEF-SDK-${PORTVERSION}
DIST_SUBDIR=	eclipse

MAINTAINER=	java@FreeBSD.ORG
COMMENT=	Graphical Editing Framework for the Eclipse IDE

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
