# New ports collection makefile for:	eclipse-sysdeo-tomcat
# Date created:				July 29, 2004
# Whom:					sugimura@jp.FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	sysdeo
PORTVERSION=	3
PORTREVISION=	2
CATEGORIES=	java
MASTER_SITES=	http://www.sysdeo.com/eclipse/
PKGNAMEPREFIX=	eclipse-
PKGNAMESUFFIX=	-tomcat
DISTNAME=	tomcatPluginV${PORTVERSION}
DIST_SUBDIR=	eclipse

MAINTAINER=	sugimura@jp.FreeBSD.ORG
COMMENT=	Sysdeo Tomcat Launcher plugin for Eclipse

RUN_DEPENDS+=	${LOCALBASE}/bin/eclipse:${PORTSDIR}/java/eclipse

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_ZIP=	yes

do-install:
		@${MKDIR} ${PREFIX}/eclipse
		@${CP} -r ${WRKSRC}/com.sysdeo.eclipse.tomcat_3.0.0 ${PREFIX}/eclipse/plugins

.include <bsd.port.mk>
