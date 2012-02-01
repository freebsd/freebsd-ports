# New ports collection makefile for:    deegree-wpvs
# Date created:         17 April, 2009
# Whom:                 wenheping@gmail.com
#
# $FreeBSD$
#

PORTNAME=	wpvs
PORTVERSION=	2.5
CATEGORIES=	graphics java
MASTER_SITES=	http://download.deegree.org/deegree${PORTVERSION}/
PKGNAMEPREFIX=	deegree-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}_${PORTVERSION}

MAINTAINER=	wenheping@gmail.com
COMMENT=	Deegree Web Terrain Service(WTS)/Web Perspective View Service(WPVS)

RUN_DEPENDS=	${LOCALBASE}/${TOMCATVER}/bin/bootstrap.jar:${PORTSDIR}/www/tomcat55

USE_ZIP=	yes
USE_JAVA=	1.5+

NO_BUILD=	yes
TOMCATVER=	tomcat5.5
TOMCATDIR=	${PREFIX}/${TOMCATVER}
WEBAPPDIR=	${TOMCATDIR}/webapps
PORTDOCS=	*
DOCSDIR=	${PREFIX}/share/doc/deegree-wpvs
PLIST_SUB=	TOMCATDIR=${TOMCATDIR:S|^${PREFIX}/||}

post-extract:
	@${MKDIR} ${WRKDIR}/${PORTDIRNAME}
	@${TAR} xf ${WRKDIR}/deegree-wpvs.war -C ${WRKDIR}/${PORTDIRNAME}

do-install:
	${INSTALL} -d -o ${WWWOWN} -g ${WWWGRP} ${TOMCATDIR}/webapps/${PORTDIRNAME}
	@cd ${WRKDIR}/${PORTDIRNAME} && ${COPYTREE_SHARE} \* ${WEBAPPDIR}/${PORTDIRNAME}

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/README.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/deegree_wpvs_documentation_en.pdf ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
