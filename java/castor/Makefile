# Created by: Adam VanderHook <acidos@bandwidth-junkies.net>
# $FreeBSD$

PORTNAME=	castor
PORTVERSION=	1.3.2
CATEGORIES=	java devel
MASTER_SITES=	http://dist.codehaus.org/castor/${PORTVERSION}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Data binding for XML (JAXB) and SQL database (JDO)

LICENSE=	AL2

USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}-anttasks.jar \
		%%JAVAJARDIR%%/${PORTNAME}-codegen.jar \
		%%JAVAJARDIR%%/${PORTNAME}-core.jar \
		%%JAVAJARDIR%%/${PORTNAME}-ddlgen.jar \
		%%JAVAJARDIR%%/${PORTNAME}-xml-schema.jar \
		%%JAVAJARDIR%%/${PORTNAME}-xml.jar \
		%%JAVAJARDIR%%/${PORTNAME}.jar

PORTDOCS=	*.html *.txt *.css *.dtd *.xsd *.pdf \
		ora-mar-2k images rss

NO_STAGE=	yes
do-install:
.for f in ${PLIST_FILES:T:R}
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/${f}.jar..."
	@${INSTALL_DATA} \
		${WRKSRC}/${f:S/tor/tor-${PORTVERSION}/}.jar \
		${JAVAJARDIR}/${f}.jar
	@${ECHO_MSG} " [ DONE ]"
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/doc/ && ${COPYTREE_SHARE} \* ${DOCSDIR})
.endif

.include <bsd.port.mk>
