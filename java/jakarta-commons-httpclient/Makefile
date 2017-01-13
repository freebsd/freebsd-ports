# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	commons-httpclient
DISTVERSION=	3.1
PORTREVISION=	1
CATEGORIES=	java www
MASTER_SITES=	APACHE/httpcomponents/${PORTNAME}/source
PKGNAMEPREFIX=	jakarta-
DISTNAME=	${PORTNAME}-${DISTVERSION}-src

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Package implementing the client side of the HTTP standard

LICENSE=	APACHE20

BUILD_DEPENDS=	${JAVALIBDIR}/commons-logging.jar:java/jakarta-commons-logging
BUILD_DEPENDS+=	${JAVALIBDIR}/commons-codec.jar:java/jakarta-commons-codec
RUN_DEPENDS=	${JAVALIBDIR}/commons-logging.jar:java/jakarta-commons-logging
RUN_DEPENDS+=	${JAVALIBDIR}/commons-codec.jar:java/jakarta-commons-codec

OPTIONS_DEFINE=	DOCS

USES+=		cpe
CPE_VENDOR=	apache
USE_JAVA=	yes
JAVA_VERSION=	1.6+
USE_ANT=	yes
MAKE_ENV=	ANT_INCLUDE_SHARED_JARS=YES
NO_ARCH=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}
ALL_TARGET=	dist

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar

PORTDOCS=	*

post-patch:
	@LANG=C ${REINPLACE_CMD} 's/Ortwin Gl.*ck/Ortwin Glueck/' \
		${WRKSRC}/src/java/org/apache/commons/httpclient/*.java \
		${WRKSRC}/src/java/org/apache/commons/httpclient/*/*.java

do-install:
	@${ECHO_MSG} -n ">> Installing JAR file as ${JAVAJARDIR}/${PORTNAME}.jar..."
	@${INSTALL_DATA} ${WRKSRC}/dist/${PORTNAME}.jar ${STAGEDIR}${JAVAJARDIR}/
	@${ECHO_MSG} " [DONE]"

do-install-DOCS-on:
	@${ECHO_MSG} -n ">> Installing documentation..."
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC}/dist/docs && ${FIND} api \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${DOCSDIR} > /dev/null 2>&1
	@${ECHO_MSG} " [DONE]"

.include <bsd.port.mk>
