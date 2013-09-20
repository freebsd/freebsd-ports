# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	barbecue
DISTVERSION=	1.5-beta1
CATEGORIES=	graphics print java
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTVERSION}/
DIST_SUBDIR=	java

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Java barcode generator

LICENSE=	BSD

RUN_DEPENDS=	${JAVALIBDIR}/jdom.jar:${PORTSDIR}/java/jdom

USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes

JARFILES=	${PORTNAME}-${DISTVERSION}.jar

TOMCATDIR=	${PREFIX}/${TOMCATVER}
APPHOME=	${LOCALBASE}/${TOMCATVER}
WEBAPPDIR=	${TOMCATDIR}/webapps

PORTDOCS=	*
PORTEXAMPLES=	*

PLIST_SUB=	TOMCATDIR=${TOMCATDIR:S|^${PREFIX}/||}

OPTIONS_SINGLE=	AS
OPTIONS_SINGLE_AS=	TOMCAT6 TOMCAT7
OPTIONS_DEFAULT=	TOMCAT6

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTOMCAT6}
TOMCATVER=	apache-tomcat-6.0
BUILD_DEPENDS+=	${APPHOME}/bin/bootstrap.jar:${PORTSDIR}/www/tomcat6
RUN_DEPENDS+=	${APPHOME}/bin/bootstrap.jar:${PORTSDIR}/www/tomcat6
.endif

.if ${PORT_OPTIONS:MTOMCAT7}
TOMCATVER=	apache-tomcat-7.0
BUILD_DEPENDS+=	${APPHOME}/bin/bootstrap.jar:${PORTSDIR}/www/tomcat7
RUN_DEPENDS+=	${APPHOME}/bin/bootstrap.jar:${PORTSDIR}/www/tomcat7
.endif

post-extract:
	${MV} ${WRKSRC}/${JARFILES} ${WRKSRC}/${JARFILES:S|-${DISTVERSION}||}
	${MKDIR} ${WRKDIR}/${PORTNAME}
	${TAR} xf ${WRKSRC}/${PORTNAME}.war -C ${WRKDIR}/${PORTNAME}

do-install:
	${INSTALL_DATA} ${JARFILES:S|-${DISTVERSION}||:S|^|${WRKSRC}/|} ${JAVAJARDIR}

.if ${PORT_OPTIONS:MTOMCAT6} || ${PORT_OPTIONS:MTOMCAT7}
	${INSTALL} -d -o ${WWWOWN} -g ${WWWGRP} ${WEBAPPDIR}/${PORTNAME}
	@(cd ${WRKDIR}/${PORTNAME} && ${COPYTREE_SHARE} \* ${WEBAPPDIR}/${PORTNAME})
	${TOUCH} ${WEBAPPDIR}/${PORTNAME}/WEB-INF/classes/net/sourceforge/barbecue/postnet/.empty
.endif

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${DOCSDIR}
	@(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} \* ${DOCSDIR})
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
