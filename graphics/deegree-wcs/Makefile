# Created by: wenheping@gmail.com
# $FreeBSD$

PORTNAME=	wcs
PORTVERSION=	2.5
PORTREVISION=	1
CATEGORIES=	graphics java
MASTER_SITES=	http://download.deegree.org/deegree${PORTVERSION}/
PKGNAMEPREFIX=	deegree-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Deegree Web Coverage Service(WCS)

LICENSE=	LGPL21+

USES=		zip
USE_JAVA=	yes

NO_BUILD=	yes
NO_ARCH=	yes
TOMCATDIR=	${PREFIX}/${TOMCATVER}
APPHOME=	${LOCALBASE}/${TOMCATVER}
WEBAPPDIR=	${TOMCATDIR}/webapps
PORTDOCS=	README.txt deegree_wcs_documentation_en.pdf
DOCSDIR=	${PREFIX}/share/doc/deegree-wcs
PLIST_SUB=	TOMCATDIR=${TOMCATDIR:S|^${PREFIX}/||} WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"
SUB_FILES=	pkg-message
SUB_LIST=	TCPORT=${TCPORT}

OPTIONS_SINGLE=	AS
OPTIONS_SINGLE_AS=	TOMCAT6 TOMCAT7
OPTIONS_DEFAULT=	TOMCAT6
OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTOMCAT6}
TOMCATVER=	apache-tomcat-6.0
TCPORT=		8180
BUILD_DEPENDS+=	${APPHOME}/bin/bootstrap.jar:www/tomcat6
RUN_DEPENDS+=	${APPHOME}/bin/bootstrap.jar:www/tomcat6
.endif

.if ${PORT_OPTIONS:MTOMCAT7}
TOMCATVER=	apache-tomcat-7.0
TCPORT=		8080
BUILD_DEPENDS+=	${APPHOME}/bin/bootstrap.jar:www/tomcat7
RUN_DEPENDS+=	${APPHOME}/bin/bootstrap.jar:www/tomcat7
.endif

post-extract:
	@${MKDIR} ${WRKDIR}/${PKGBASE}
	@${TAR} xf ${WRKDIR}/deegree-wcs.war -C ${WRKDIR}/${PKGBASE}

do-install:
	@${MKDIR} ${STAGEDIR}${WEBAPPDIR}/${PKGBASE}
	@cd ${WRKDIR}/${PKGBASE} && ${COPYTREE_SHARE} \* ${STAGEDIR}${WEBAPPDIR}/${PKGBASE}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKDIR}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
