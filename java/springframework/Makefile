# New ports collection makefile for:            springframework
# Date created:         02 Jan 2008
# Whom:         Gerrit Beine <gerrit.beine@gmx.de>
#
# $FreeBSD$

PORTNAME=	springframework
PORTVERSION=	2.5.5
CATEGORIES=	java devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-2/${PORTVERSION}
DISTNAME=	spring-framework-${PORTVERSION}-with-dependencies

MAINTAINER=	gerrit.beine@gmx.de
COMMENT=	The Spring Framework for Java

WRKSRC=		${WRKDIR}/spring-framework-${PORTVERSION}

NO_BUILD=	yes
USE_JAVA=	yes
USE_ZIP=	yes
JAVA_VERSION=	1.5+

OPTIONS=	DOCS    "Install docs & examples" on \
		RESRCS  "Install resource files" off \
		MODULES "Install modules" on \
		WEAVING "Install weaving modules" off

PLIST_FILES=	%%JAVAJARDIR%%/spring.jar

.include <bsd.port.pre.mk>

.if defined(WITHOUT_DOCS) || !defined(WITH_DOCS)
NOPORTDOCS=	yes
.endif

.if !defined(WITHOUT_RESRCS) || defined(WITH_RESRCS)
PLIST_FILES+=	%%JAVASHAREDIR%%/spring-aop-2.0.xsd \
		%%JAVASHAREDIR%%/spring-aop-2.5.xsd \
		%%JAVASHAREDIR%%/spring-beans-2.0.dtd \
		%%JAVASHAREDIR%%/spring-beans-2.0.xsd \
		%%JAVASHAREDIR%%/spring-beans-2.5.xsd \
		%%JAVASHAREDIR%%/spring-beans.dtd \
		%%JAVASHAREDIR%%/spring-context-2.5.xsd \
		%%JAVASHAREDIR%%/spring-form.tld \
		%%JAVASHAREDIR%%/spring-jee-2.0.xsd \
		%%JAVASHAREDIR%%/spring-jee-2.5.xsd \
		%%JAVASHAREDIR%%/spring-jms-2.5.xsd \
		%%JAVASHAREDIR%%/spring-lang-2.0.xsd \
		%%JAVASHAREDIR%%/spring-lang-2.5.xsd \
		%%JAVASHAREDIR%%/spring-tool-2.0.xsd \
		%%JAVASHAREDIR%%/spring-tool-2.5.xsd \
		%%JAVASHAREDIR%%/spring-tx-2.0.xsd \
		%%JAVASHAREDIR%%/spring-tx-2.5.xsd \
		%%JAVASHAREDIR%%/spring-util-2.0.xsd \
		%%JAVASHAREDIR%%/spring-util-2.5.xsd \
		%%JAVASHAREDIR%%/spring.ftl \
		%%JAVASHAREDIR%%/spring.tld \
		%%JAVASHAREDIR%%/spring.vm
.endif

.if !defined(WITHOUT_MODULES) || defined(WITH_MODULES)
PLIST_FILES+=	%%JAVAJARDIR%%/spring-aop.jar \
		%%JAVAJARDIR%%/spring-beans.jar \
		%%JAVAJARDIR%%/spring-context-support.jar \
		%%JAVAJARDIR%%/spring-context.jar \
		%%JAVAJARDIR%%/spring-core.jar \
		%%JAVAJARDIR%%/spring-jdbc.jar \
		%%JAVAJARDIR%%/spring-jms.jar \
		%%JAVAJARDIR%%/spring-orm.jar \
		%%JAVAJARDIR%%/spring-test.jar \
		%%JAVAJARDIR%%/spring-tx.jar \
		%%JAVAJARDIR%%/spring-web.jar \
		%%JAVAJARDIR%%/spring-webmvc-portlet.jar \
		%%JAVAJARDIR%%/spring-webmvc-struts.jar \
		%%JAVAJARDIR%%/spring-webmvc.jar
.endif

.if !defined(WITHOUT_WEAVING) || defined(WITH_WEAVING)
PLIST_FILES+=	%%JAVAJARDIR%%/spring-agent.jar \
		%%JAVAJARDIR%%/spring-aspects.jar \
		%%JAVAJARDIR%%/spring-tomcat-weaver.jar
.endif

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

do-install:
	@${INSTALL_DATA} ${WRKSRC}/dist/spring.jar ${JAVAJARDIR}
.if !defined(WITHOUT_RESRCS) || defined(WITH_RESRCS)
	@${INSTALL_DATA} ${WRKSRC}/dist/resources/* ${JAVASHAREDIR}
.endif
.if !defined(WITHOUT_MODULES) || defined(WITH_MODULES)
	@${INSTALL_DATA} ${WRKSRC}/dist/modules/* ${JAVAJARDIR}
.endif
.if !defined(WITHOUT_WEAVING) || defined(WITH_WEAVING)
	@${INSTALL_DATA} ${WRKSRC}/dist/weaving/* ${JAVAJARDIR}
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/changelog.txt ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/notice.txt ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/readme.txt ${DOCSDIR}
	@cd ${WRKSRC}/docs/ \
	    && ${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/{} \; \
	    && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
	@${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKSRC}/samples/ \
	    && ${FIND} . -type d -exec ${MKDIR} ${EXAMPLESDIR}/{} \; \
	    && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${EXAMPLESDIR}/{} \;
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${FIND} -s ${WRKSRC}/samples -not -type d \
	    | ${SED} -ne 's,^${WRKSRC}/samples,${EXAMPLESDIR:S,^${PREFIX}/,,},p' >> ${TMPPLIST}
	@${FIND} -s -d ${WRKSRC}/samples -type d \
	    | ${SED} -ne 's,^${WRKSRC}/samples,@dirrm ${EXAMPLESDIR:S,^${PREFIX}/,,},p' >> ${TMPPLIST}
.endif

.include <bsd.port.post.mk>
