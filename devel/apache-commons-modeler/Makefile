# Created by: Nemo Liu <nemoliu@FreeBSD.org>
# $FreeBSD$

PORTNAME=	commons-modeler
PORTVERSION=	2.0.1
CATEGORIES=	devel java
MASTER_SITES=	APACHE_COMMONS_BINARIES
PKGNAMEPREFIX=	apache-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mechanisms to create Model MBeans compatible with JMX specification

LICENSE=	APACHE20

USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}-${PORTVERSION}.jar \
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar
	(cd ${WRKSRC} && ${COPYTREE_SHARE} docs ${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC} && ${INSTALL_DATA} LICENSE.txt NOTICE.txt \
		RELEASE-NOTES.txt ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
