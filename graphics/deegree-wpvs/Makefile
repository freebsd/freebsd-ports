# Created by:	wenheping@gmail.com
#
# $FreeBSD$
#

PORTNAME=	wpvs
PORTVERSION=	2.5
PORTREVISION=	1
CATEGORIES=	graphics java
MASTER_SITES=	http://download.deegree.org/deegree${PORTVERSION}/
PKGNAMEPREFIX=	deegree-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}_${PORTVERSION}

MAINTAINER=	wenheping@gmail.com
COMMENT=	Deegree Web Terrain Service(WTS)/Web Perspective View Service(WPVS)

RUN_DEPENDS=	${LOCALBASE}/${TOMCATVER}/bin/bootstrap.jar:${PORTSDIR}/www/tomcat6

USE_ZIP=	yes
USE_JAVA=	1.5+

NO_BUILD=	yes
TOMCATVER=	apache-tomcat-6.0
TOMCATDIR=	${PREFIX}/${TOMCATVER}
WEBAPPDIR=	${TOMCATDIR}/webapps
PORTDOCS=	*
DOCSDIR=	${PREFIX}/share/doc/deegree-wpvs
PLIST_SUB=	TOMCATDIR=${TOMCATDIR:S|^${PREFIX}/||}

post-extract:
	@${MKDIR} ${WRKDIR}/${PORTDIRNAME}
	@${TAR} xf ${WRKDIR}/deegree-wpvs.war -C ${WRKDIR}/${PORTDIRNAME}

.include <bsd.port.options.mk>

do-install:
	${INSTALL} -d -o ${WWWOWN} -g ${WWWGRP} ${TOMCATDIR}/webapps/${PORTDIRNAME}
	@cd ${WRKDIR}/${PORTDIRNAME} && ${COPYTREE_SHARE} \* ${WEBAPPDIR}/${PORTDIRNAME}

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/README.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/deegree_wpvs_documentation_en.pdf ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
