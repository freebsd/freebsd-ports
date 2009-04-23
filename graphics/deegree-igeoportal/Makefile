# New ports collection makefile for:    deegree-igeoportal
# Date created:         17 April, 2009
# Whom:                 wenheping@gmail.com
#
# $FreeBSD$
#

PORTNAME=	igeoportal
PORTVERSION=	2.2
CATEGORIES=	graphics java
MASTER_SITES=	http://download.deegree.org/deegree${PORTVERSION}/
PKGNAMEPREFIX=	deegree-
DISTNAME=	${PORTNAME}-std_v${PORTVERSION:S/./_/}

MAINTAINER=	wenheping@gmail.com
COMMENT=	Browserbased Client Handling WMS, WFS and Proxy Service

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
DOCSDIR=	${PREFIX}/share/doc/deegree-igeoportal
PLIST_FILES=	${TOMCATVER}/webapps/igeoportal-std.war

do-install:
	cd ${WRKDIR} && \
		${INSTALL} -g ${TOMCATGRP} -o ${TOMCATOWN} -m 444 igeoportal-std.war ${WEBAPPDIR};

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/README_igeoportal.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/deegree_igeoportal_documentation_en.pdf ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
