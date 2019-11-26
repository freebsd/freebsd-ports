# Created by: Adam VanderHook <acidos@bandwidth-junkies.net>
# $FreeBSD$

PORTNAME=	castor
PORTVERSION=	1.3.2
CATEGORIES=	java devel
MASTER_SITES=	http://dist.codehaus.org/castor/${PORTVERSION}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Data binding for XML (JAXB) and SQL database (JDO)

BROKEN=		unfetchable

LICENSE=	APACHE20

USES=		cpe
USE_JAVA=	yes
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

OPTIONS_DEFINE=	DOCS

do-install:
.for f in ${PLIST_FILES:T:R}
	${INSTALL_DATA} \
		${WRKSRC}/${f:S/tor/tor-${PORTVERSION}/}.jar \
		${STAGEDIR}${JAVAJARDIR}/${f}.jar
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC}/doc/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
