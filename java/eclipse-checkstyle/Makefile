# Created by: gldisater@gldis.ca
# $FreeBSD$

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

USES=		zip
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} com.atlassw.tools.eclipse.checkstyle_${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/eclipse/plugins

.include <bsd.port.mk>
