# Created by:	wenheping@gmail.com
#
# $FreeBSD$

PORTNAME=	wcs
PORTVERSION=	2.5
PORTREVISION=	1
CATEGORIES=	graphics java
MASTER_SITES=	http://download.deegree.org/deegree${PORTVERSION}/
PKGNAMEPREFIX=	deegree-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}_${PORTVERSION}

MAINTAINER=	wenheping@gmail.com
COMMENT=	Deegree Web Coverage Service(WCS)

RUN_DEPENDS=	${LOCALBASE}/${TOMCATVER}/bin/bootstrap.jar:${PORTSDIR}/www/tomcat6

USE_ZIP=	yes
USE_JAVA=	1.5+

NO_BUILD=	yes
TOMCATVER=	apache-tomcat-6.0
TOMCATDIR=	${PREFIX}/${TOMCATVER}
WEBAPPDIR=	${TOMCATDIR}/webapps
PORTDOCS=	*
DOCSDIR=	${PREFIX}/share/doc/deegree-wcs
PLIST_SUB=	TOMCATDIR=${TOMCATDIR:S|^${PREFIX}/||}

post-extract:
	@${MKDIR} ${WRKDIR}/${PORTDIRNAME}
	@${TAR} xf ${WRKDIR}/deegree-wcs.war -C ${WRKDIR}/${PORTDIRNAME}

.include <bsd.port.options.mk>

do-install:
	cd ${WRKDIR} && \
	${INSTALL} -d -o ${WWWOWN} -g ${WWWGRP} ${TOMCATDIR}/webapps/${PORTDIRNAME}
	@cd ${WRKDIR}/${PORTDIRNAME} && ${COPYTREE_SHARE} \* ${WEBAPPDIR}/${PORTDIRNAME}

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/README.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/deegree_wcs_documentation_en.pdf ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
