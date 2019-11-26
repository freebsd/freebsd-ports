# Created by: Gerrit Beine <gerrit.beine@gmx.de>
# $FreeBSD$

PORTNAME=	springframework
PORTVERSION=	3.2.1
CATEGORIES=	java devel
MASTER_SITES=	http://repo.springsource.org/libs-release-local/org/springframework/spring/${PORTVERSION}.RELEASE/
DISTNAME=	spring-framework-${PORTVERSION}.RELEASE-dist

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	The Spring Framework for Java

WRKSRC=		${WRKDIR}/spring-framework-${PORTVERSION}.RELEASE

CONFLICTS=	springframework-3.1.*

NO_BUILD=	yes
USE_JAVA=	yes
USES=		zip

OPTIONS_DEFINE=	DOCS RESRCS
RESRCS_DESC=	Install resource files

JAR_FILES=	spring-aop.jar \
		spring-aspects.jar \
		spring-beans.jar \
		spring-build-src.jar \
		spring-context-support.jar \
		spring-context.jar \
		spring-core.jar \
		spring-expression.jar \
		spring-instrument-tomcat.jar \
		spring-instrument.jar \
		spring-jdbc.jar \
		spring-jms.jar \
		spring-orm.jar \
		spring-oxm.jar \
		spring-struts.jar \
		spring-test.jar \
		spring-tx.jar \
		spring-web.jar \
		spring-webmvc-portlet.jar \
		spring-webmvc.jar

JAVADOC=	spring-aop-javadoc.jar \
		spring-aspects-javadoc.jar \
		spring-beans-javadoc.jar \
		spring-context-javadoc.jar \
		spring-context-support-javadoc.jar \
		spring-core-javadoc.jar \
		spring-expression-javadoc.jar \
		spring-instrument-javadoc.jar \
		spring-instrument-tomcat-javadoc.jar \
		spring-jdbc-javadoc.jar \
		spring-jms-javadoc.jar \
		spring-orm-javadoc.jar \
		spring-oxm-javadoc.jar \
		spring-struts-javadoc.jar \
		spring-test-javadoc.jar \
		spring-tx-javadoc.jar \
		spring-web-javadoc.jar \
		spring-webmvc-javadoc.jar \
		spring-webmvc-portlet-javadoc.jar

SOURCES=	spring-aop-sources.jar \
		spring-aspects-sources.jar \
		spring-beans-sources.jar \
		spring-context-sources.jar \
		spring-context-support-sources.jar \
		spring-core-sources.jar \
		spring-expression-sources.jar \
		spring-instrument-sources.jar \
		spring-instrument-tomcat-sources.jar \
		spring-jdbc-sources.jar \
		spring-jms-sources.jar \
		spring-orm-sources.jar \
		spring-oxm-sources.jar \
		spring-struts-sources.jar \
		spring-test-sources.jar \
		spring-tx-sources.jar \
		spring-web-sources.jar \
		spring-webmvc-portlet-sources.jar \
		spring-webmvc-sources.jar

.for FILE in ${JAR_FILES}
PLIST_FILES +=	%%JAVAJARDIR%%/${FILE}
.endfor

.for FILE in ${SOURCES}
PLIST_FILES +=	%%JAVAJARDIR%%/${FILE}
.endfor

.for FILE in ${JAVADOC}
PLIST_FILES +=	%%JAVAJARDIR%%/${FILE}
.endfor

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MRESRCS}
RESOURCE_FILES=	spring-aop-2.0.xsd \
		spring-aop-2.5.xsd \
		spring-aop-3.0.xsd \
		spring-aop-3.1.xsd \
		spring-aop-3.2.xsd \
		spring-beans-2.0.xsd \
		spring-beans-2.5.xsd \
		spring-beans-3.0.xsd \
		spring-beans-3.1.xsd \
		spring-beans-3.2.xsd \
		spring-cache-3.1.xsd \
		spring-cache-3.2.xsd \
		spring-context-2.5.xsd \
		spring-context-3.0.xsd \
		spring-context-3.1.xsd \
		spring-context-3.2.xsd \
		spring-jdbc-3.0.xsd \
		spring-jdbc-3.1.xsd \
		spring-jdbc-3.2.xsd \
		spring-jee-2.0.xsd \
		spring-jee-2.5.xsd \
		spring-jee-3.0.xsd \
		spring-jee-3.1.xsd \
		spring-jee-3.2.xsd \
		spring-jms-2.5.xsd \
		spring-jms-3.0.xsd \
		spring-jms-3.1.xsd \
		spring-jms-3.2.xsd \
		spring-lang-2.0.xsd \
		spring-lang-2.5.xsd \
		spring-lang-3.0.xsd \
		spring-lang-3.1.xsd \
		spring-lang-3.2.xsd \
		spring-mvc-3.0.xsd \
		spring-mvc-3.1.xsd \
		spring-mvc-3.2.xsd \
		spring-oxm-3.0.xsd \
		spring-oxm-3.1.xsd \
		spring-oxm-3.2.xsd \
		spring-task-3.0.xsd \
		spring-task-3.1.xsd \
		spring-task-3.2.xsd \
		spring-tool-2.0.xsd \
		spring-tool-2.5.xsd \
		spring-tool-3.0.xsd \
		spring-tool-3.1.xsd \
		spring-tool-3.2.xsd \
		spring-tx-2.0.xsd \
		spring-tx-2.5.xsd \
		spring-tx-3.0.xsd \
		spring-tx-3.1.xsd \
		spring-tx-3.2.xsd \
		spring-util-2.0.xsd \
		spring-util-2.5.xsd \
		spring-util-3.0.xsd \
		spring-util-3.1.xsd \
		spring-util-3.2.xsd

.for FILE in ${RESOURCE_FILES}
PLIST_FILES +=	%%JAVASHAREDIR%%/${FILE}
.endfor
.endif

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	*
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	@${MKDIR} ${STAGEDIR}${JAVASHAREDIR}
.for FILE in ${JAR_FILES}
	${INSTALL_DATA} ${WRKSRC}/libs/${FILE:S/.jar/-${PORTVERSION}.RELEASE.jar/} \
		${STAGEDIR}${JAVAJARDIR}/${FILE}
.endfor
.for FILE in ${SOURCES}
	${INSTALL_DATA} ${WRKSRC}/libs/${FILE:S/-sources.jar/-${PORTVERSION}.RELEASE-sources.jar/} \
		${STAGEDIR}${JAVAJARDIR}/${FILE}
.endfor
.for FILE in ${JAVADOC}
	${INSTALL_DATA} ${WRKSRC}/libs/${FILE:S/-javadoc.jar/-${PORTVERSION}.RELEASE-javadoc.jar/} \
		${STAGEDIR}${JAVAJARDIR}/${FILE}
.endfor
.for FILE in ${RESOURCE_FILES}
	${INSTALL_DATA} `${FIND} "${WRKSRC}" -name ${FILE} -print` \
		${STAGEDIR}${JAVASHAREDIR}/${FILE}
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/license.txt ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/notice.txt ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
