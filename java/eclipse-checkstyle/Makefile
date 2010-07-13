# New ports collection makefile for:	eclipse-checkstyle
# Date created:				July 30, 2004
# Whom:					gldisater@gldis.ca
#
# $FreeBSD$
#

PORTNAME=	checkstyle
PORTVERSION=	3.4.1.0
PORTREVISION=	6
CATEGORIES=	java devel
MASTER_SITES=	SF/eclipse-cs/Eclipse%20Checkstyle%20Plug-in/v3.4.1
PKGNAMEPREFIX=	eclipse-
DISTNAME=	com.atlassw.tools.eclipse.checkstyle_${PORTVERSION}
DIST_SUBDIR=	eclipse

MAINTAINER=	freebsd-eclipse@FreeBSD.org
COMMENT=	Integrates the Checkstyle Java code auditor into Eclipse

RUN_DEPENDS=	eclipse:${PORTSDIR}/java/eclipse

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.4+
USE_ZIP=	yes

do-install:
	@${MKDIR} ${PREFIX}/lib/eclipse
	@${MKDIR} ${PREFIX}/lib/eclipse/plugins
	@${CP} -r ${WRKSRC}/com.atlassw.tools.eclipse.checkstyle_${PORTVERSION} ${PREFIX}/lib/eclipse/plugins

.include <bsd.port.mk>
