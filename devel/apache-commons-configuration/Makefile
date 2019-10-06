# Created by: Herve Quiroz <hq@FreeBSD.org>
# $FreeBSD$

PORTNAME=	commons-configuration
PORTVERSION=	1.10
CATEGORIES=	devel java
MASTER_SITES=	APACHE_COMMONS_BINARIES
PKGNAMEPREFIX=	apache-
DISTNAME=	${PORTNAME}-${PORTVERSION}-bin

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java package for the reading of configuration/preferences files

LICENSE=	APACHE20

RUN_DEPENDS=	${JAVALIBDIR}/commons-beanutils.jar:java/jakarta-commons-beanutils \
		${JAVALIBDIR}/commons-lang.jar:java/apache-commons-lang \
		${JAVALIBDIR}/commons-logging.jar:java/apache-commons-logging

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=	DOCS

USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes

PORTDOCS=	*
PLIST_FILES+=	%%JAVAJARDIR%%/${PORTNAME}.jar

do-install:
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}-${PORTVERSION}.jar \
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar
	cd ${WRKSRC}/apidocs && ${FIND} . -type d -exec ${MKDIR} \
		${STAGEDIR}${DOCSDIR}/{} \;
	cd ${WRKSRC}/apidocs && ${FIND} . -type f -exec ${INSTALL_DATA} {} \
		${STAGEDIR}${DOCSDIR}/{} \;

.include <bsd.port.mk>
