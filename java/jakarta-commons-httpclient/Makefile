# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	commons-httpclient
DISTVERSION=	3.1
PORTREVISION=	1
CATEGORIES=	java www
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	httpcomponents/${PORTNAME}/source
PKGNAMEPREFIX=	jakarta-
DISTNAME=	${PORTNAME}-${DISTVERSION}-src

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A package implementing the client side of the HTTP standard

LICENSE=	APACHE20

BUILD_DEPENDS=	${JAVAJARDIR}/commons-logging.jar:${PORTSDIR}/java/jakarta-commons-logging
BUILD_DEPENDS+=	${JAVAJARDIR}/commons-codec.jar:${PORTSDIR}/java/jakarta-commons-codec
RUN_DEPENDS=	${JAVAJARDIR}/commons-logging.jar:${PORTSDIR}/java/jakarta-commons-logging
RUN_DEPENDS+=	${JAVAJARDIR}/commons-codec.jar:${PORTSDIR}/java/jakarta-commons-codec

USE_JAVA=	yes
JAVA_VERSION=	1.6+
USE_ANT=	yes
MAKE_ENV=	ANT_INCLUDE_SHARED_JARS=YES

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}
ALL_TARGET=	dist

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar

PORTDOCS=	*

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	@LANG=C ${REINPLACE_CMD} 's/Ortwin Gl.*ck/Ortwin Glueck/' \
		${WRKSRC}/src/java/org/apache/commons/httpclient/*.java \
		${WRKSRC}/src/java/org/apache/commons/httpclient/*/*.java

do-install:
	@${ECHO_MSG} -n ">> Installing JAR file as ${JAVAJARDIR}/${PORTNAME}.jar..."
	@${INSTALL_DATA} ${WRKSRC}/dist/${PORTNAME}.jar ${JAVAJARDIR}/
	@${ECHO_MSG} " [DONE]"
.if ${PORT_OPTIONS:MDOCS}
	@${ECHO_MSG} -n ">> Installing documentation..."
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/dist/docs && ${FIND} api \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR} > /dev/null 2>&1
	@${ECHO_MSG} " [DONE]"
.endif

.include <bsd.port.mk>
