# Created by: Nemo Liu <nemoliu@FreeBSD.org>

PORTNAME=	commons-modeler
PORTVERSION=	2.0.1
CATEGORIES=	devel java
MASTER_SITES=	https://archive.apache.org/dist/commons/modeler/binaries/
PKGNAMEPREFIX=	apache-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mechanisms to create Model MBeans compatible with JMX specification

LICENSE=	APACHE20

DEPRECATED=	Abandoned upstream, last release in 2013
EXPIRATION_DATE=2022-03-31

USE_JAVA=	yes
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
