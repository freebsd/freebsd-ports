# New ports collection makefile for:    deegree-wms
# Date created:         17 April, 2009
# Whom:                 wenheping@gmail.com
#
# $FreeBSD$
#

PORTNAME=	wms
PORTVERSION=	2.2
CATEGORIES=	graphics java
MASTER_SITES=	http://download.deegree.org/deegree${PORTVERSION}/
PKGNAMEPREFIX=	deegree-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}_v${PORTVERSION:S/./_/}

MAINTAINER=	wenheping@gmail.com
COMMENT=	Deegree Web Map Service(WMS)

RUN_DEPENDS=	${TOMCATDIR}:${PORTSDIR}/www/tomcat55

USE_ZIP=	yes
USE_JAVA=	1.5+

NO_BUILD=	yes
TOMCATVER=	tomcat5.5
TOMCATDIR=	${PREFIX}/${TOMCATVER}
TOMCATOWN=	www
TOMCATGRP=	www
WEBAPPDIR=	${TOMCATDIR}/webapps
PORTDOCS=	*
DOCSDIR=	${PREFIX}/share/doc/deegree-wms
PLIST_FILES=	${TOMCATVER}/webapps/deegree-wms.war

do-install:
	cd ${WRKDIR} && \
		${INSTALL} -g ${TOMCATGRP} -o ${TOMCATOWN} -m 444 deegree-wms.war ${WEBAPPDIR};

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/README_WMS.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/deegree_wms_documentation_en.pdf ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
