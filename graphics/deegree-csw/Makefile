# Created by: wenheping@gmail.com

PORTNAME=	csw
PORTVERSION=	2.5
PORTREVISION=	2
CATEGORIES=	graphics java
MASTER_SITES=	http://download.deegree.org/deegree${PORTVERSION}/
PKGNAMEPREFIX=	deegree-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Deegree Catalogue Service(CSW)

LICENSE=	LGPL21+

DEPRECATED=	Depends on expired www/tomcat7
EXPIRATION_DATE=2022-03-31

USES=		zip
USE_JAVA=	yes

NO_BUILD=	yes
NO_ARCH=	yes
TOMCATDIR=	${PREFIX}/${TOMCATVER}
APPHOME=	${LOCALBASE}/${TOMCATVER}
WEBAPPDIR=	${TOMCATDIR}/webapps
PORTDOCS=	README.txt deegree_csw_2.0.2_documentation_en.pdf \
		deegree_csw_documentation_de.pdf deegree_csw_documentation_en.pdf
DOCSDIR=	${PREFIX}/share/doc/${DISTNAME}
PLIST_SUB=	TOMCATDIR=${TOMCATDIR:S|^${PREFIX}/||} WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"
SUB_FILES=	pkg-message
SUB_LIST=	TCPORT=${TCPORT}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

TOMCATVER=	apache-tomcat-7.0
TCPORT=		8080
BUILD_DEPENDS+=	${APPHOME}/bin/bootstrap.jar:www/tomcat7
RUN_DEPENDS+=	${APPHOME}/bin/bootstrap.jar:www/tomcat7

post-extract:
	@${MKDIR} ${WRKDIR}/${PKGBASE}
	@${TAR} xf ${WRKDIR}/deegree-csw.war -C ${WRKDIR}/${PKGBASE}

do-install:
	@${MKDIR} ${STAGEDIR}${WEBAPPDIR}/${PKGBASE}
	@cd ${WRKDIR}/${PKGBASE} && ${COPYTREE_SHARE} \* ${STAGEDIR}${WEBAPPDIR}/${PKGBASE}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKDIR}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
