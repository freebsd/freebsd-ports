PORTNAME=	commons-jxpath
DISTVERSION=	1.4.0
CATEGORIES=	devel www java
MASTER_SITES=	APACHE_COMMONS_BINARIES
PKGNAMEPREFIX=	apache-
DISTNAME=	${PORTNAME}-${DISTVERSION}-bin

MAINTAINER=	atanubiswas484@gmail.com
COMMENT=	Utilities for manipulating Java Beans using the XPath syntax
WWW=		https://commons.apache.org/proper/commons-jxpath/

LICENSE=	APACHE20

USES=		java

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${JAVAJARDIR}/${PORTNAME}.jar
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_DATA} \
		${WRKDIR}/${PORTNAME}-${DISTVERSION}/${PORTNAME}-${DISTVERSION}.jar \
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar

do-install-DOCS-on:
	(cd ${WRKDIR}/${PORTNAME}-${DISTVERSION}/apidocs && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
