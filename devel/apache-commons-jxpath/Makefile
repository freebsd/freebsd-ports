# Created by: Nemo Liu <nemoliu@FreeBSD.org>
# $FreeBSD$

PORTNAME=	commons-jxpath
PORTVERSION=	1.3
CATEGORIES=	devel www java
MASTER_SITES=	APACHE_COMMONS_BINARIES
PKGNAMEPREFIX=	apache-
DISTNAME=	${PORTNAME}-${PORTVERSION}-bin

LICENSE=	APACHE20

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utilities for manipulating Java Beans using the XPath syntax

USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-${PORTVERSION}/${PORTNAME}-${PORTVERSION}.jar \
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar
	(cd ${WRKDIR}/${PORTNAME}-${PORTVERSION}/apidocs && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
