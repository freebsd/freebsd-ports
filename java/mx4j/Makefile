# Created by: Filippo Natali <filippo@widestore.net>
# $FreeBSD$

PORTNAME=	mx4j
PORTVERSION=	3.0.2
PORTREVISION=	1
CATEGORIES=	java devel
MASTER_SITES=	SF/${PORTNAME}/MX4J%20Binary/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open Source implementation of the Java Management Extensions (JMX)

USE_JAVA=	yes
NO_BUILD=	yes

JARFILES=	mx4j-examples.jar mx4j-impl.jar mx4j-jmx.jar \
		mx4j-remote.jar mx4j-rimpl.jar mx4j-rjmx.jar \
		mx4j-soap.war mx4j-tools.jar mx4j.jar

PLIST_FILES=	${JARFILES:S,^,%%JAVAJARDIR%%/,}
PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	(cd ${WRKSRC}/lib && ${INSTALL_DATA} ${JARFILES} ${STAGEDIR}${JAVAJARDIR})
	(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
