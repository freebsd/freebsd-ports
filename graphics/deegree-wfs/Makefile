# New ports collection makefile for:    deegree-wfs
# Date created:         17 April, 2009
# Whom:                 wenheping@gmail.com
#
# $FreeBSD$
#

PORTNAME=	wfs
PORTVERSION=	2.5
CATEGORIES=	graphics java
MASTER_SITES=	http://download.deegree.org/deegree${PORTVERSION}/
PKGNAMEPREFIX=	deegree-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}_${PORTVERSION}

MAINTAINER=	wenheping@gmail.com
COMMENT=	Deegree Web Feature Service(WFS)

RUN_DEPENDS=	${LOCALBASE}/${TOMCATVER}/bin/bootstrap.jar:${PORTSDIR}/www/tomcat55

USE_ZIP=	yes
USE_JAVA=	1.5+

NO_BUILD=	yes
TOMCATVER=	tomcat5.5
TOMCATDIR=	${PREFIX}/${TOMCATVER}
WEBAPPDIR=	${TOMCATDIR}/webapps
PORTDOCS=	*
DOCSDIR=	${PREFIX}/share/doc/deegree-wfs
PLIST_SUB=	TOMCATDIR=${TOMCATDIR:S|^${PREFIX}/||}

post-extract:
	@${MKDIR} ${WRKDIR}/${PORTDIRNAME}
	@${TAR} xf ${WRKDIR}/deegree-wfs.war -C ${WRKDIR}/${PORTDIRNAME}

do-install:
	cd ${WRKDIR} && \
	${INSTALL} -d -o ${WWWOWN} -g ${WWWGRP} ${TOMCATDIR}/webapps/${PORTDIRNAME}
	@cd ${WRKDIR}/${PORTDIRNAME} && ${COPYTREE_SHARE} \* ${WEBAPPDIR}/${PORTDIRNAME}

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/README.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/deegree_wfs_documentation_en.pdf ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
