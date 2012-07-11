# New ports collection makefile for:            springframework
# Date created:         02 Jan 2008
# Whom:         Gerrit Beine <gerrit.beine@gmx.de>
#
# $FreeBSD$

PORTNAME=	springframework
PORTVERSION=	3.0.5
CATEGORIES=	java devel
MASTER_SITES=	http://s3.amazonaws.com/dist.springframework.org/release/SPR/
DISTNAME=	spring-framework-${PORTVERSION}.RELEASE-with-docs

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Spring Framework for Java

WRKSRC=		${WRKDIR}/spring-framework-${PORTVERSION}.RELEASE

NO_BUILD=	yes
USE_JAVA=	yes
USE_ZIP=	yes
JAVA_VERSION=	1.5+

OPTIONS=	DOCS    "Install docs & examples" on \
		RESRCS  "Install resource files" off

JAR_FILES=	org.springframework.aop.jar \
		org.springframework.asm.jar \
		org.springframework.aspects.jar \
		org.springframework.beans.jar \
		org.springframework.context.jar \
		org.springframework.context.support.jar \
		org.springframework.core.jar \
		org.springframework.expression.jar \
		org.springframework.instrument.jar \
		org.springframework.instrument.tomcat.jar \
		org.springframework.jdbc.jar \
		org.springframework.jms.jar \
		org.springframework.orm.jar \
		org.springframework.oxm.jar \
		org.springframework.test.jar \
		org.springframework.transaction.jar \
		org.springframework.web.jar \
		org.springframework.web.portlet.jar \
		org.springframework.web.servlet.jar \
		org.springframework.web.struts.jar

.for f in ${JAR_FILES}
PLIST_FILES +=	%%JAVAJARDIR%%/${f}
.endfor

.include <bsd.port.options.mk>

.if defined(WITHOUT_DOCS)
NOPORTDOCS=	yes
.endif

.if defined(WITH_RESRCS)
RESOURCE_FILES=	spring-aop-2.0.xsd \
		spring-aop-2.5.xsd \
		spring-aop-3.0.xsd \
		spring-beans-2.0.dtd \
		spring-beans-2.0.xsd \
		spring-beans-2.5.xsd \
		spring-beans-3.0.xsd \
		spring-beans.dtd \
		spring-context-2.5.xsd \
		spring-context-3.0.xsd \
		spring-form.tld \
		spring-jdbc-3.0.xsd \
		spring-jee-2.0.xsd \
		spring-jee-2.5.xsd \
		spring-jee-3.0.xsd \
		spring-jms-2.5.xsd \
		spring-jms-3.0.xsd \
		spring-lang-2.0.xsd \
		spring-lang-2.5.xsd \
		spring-lang-3.0.xsd \
		spring-mvc-3.0.xsd \
		spring-oxm-3.0.xsd \
		spring-task-3.0.xsd \
		spring-tool-2.0.xsd \
		spring-tool-2.5.xsd \
		spring-tool-3.0.xsd \
		spring-tx-2.0.xsd \
		spring-tx-2.5.xsd \
		spring-tx-3.0.xsd \
		spring-util-2.0.xsd \
		spring-util-2.5.xsd \
		spring-util-3.0.xsd \
		spring.ftl \
		spring.tld \
		spring.vm

.for f in ${RESOURCE_FILES}
PLIST_FILES +=	%%JAVASHAREDIR%%/${f}
.endfor
.endif

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

do-install:
.for f in ${JAR_FILES}
	@${INSTALL_DATA} ${WRKSRC}/dist/${f:S/.jar/-${PORTVERSION}.RELEASE.jar/} \
		${JAVAJARDIR}/${f}
.endfor
.if !defined(WITHOUT_RESRCS) || defined(WITH_RESRCS)
.for f in ${RESOURCE_FILES}
	@${INSTALL_DATA} `${FIND} "${WRKSRC}" -name ${f} -print` \
		${JAVASHAREDIR}/${f}
.endfor
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/changelog.txt ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/license.txt ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/notice.txt ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/readme.txt ${DOCSDIR}
	@cd ${WRKSRC}/docs/ && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif

.include <bsd.port.mk>
