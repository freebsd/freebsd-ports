# Created by: Michael Winking <mwfp@foldl.net>
# $FreeBSD$

PORTNAME=	commons-dbutils
PORTVERSION=	1.6
CATEGORIES=	databases java
MASTER_SITES=	APACHE_COMMONS_BINARIES
PKGNAMEPREFIX=	jakarta-
DISTNAME=	${PORTNAME}-${PORTVERSION}-bin

MAINTAINER=	ports@FreeBSD.org
COMMENT=	JDBC helper library

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

do-install:
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/${PORTNAME}.jar..."
	${INSTALL_DATA} ${WRKSRC}/commons-dbutils-1.6.jar \
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar
	@${ECHO_MSG} " [DONE]"
	@${ECHO_MSG} -n ">> Installing documentation..."
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC}/apidocs && ${FIND} . \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${DOCSDIR} > /dev/null 2>&1
	${INSTALL_DATA} ${WRKSRC}/LICENSE.txt \
		${STAGEDIR}${DOCSDIR}/
	@${ECHO_MSG} " [DONE]"

.include <bsd.port.mk>
