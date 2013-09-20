# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	javolution
PORTVERSION=	5.5.1
CATEGORIES=	devel java
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	ale

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A Java solution for real time and embedded systems

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USE_JAVA=	yes
JAVA_VERSION=	1.6+
JDKMVERSION=	${JAVA_PORT_VERSION:C/^([0-9]\.[0-9])(.*)$/\1/}
USE_ANT=	yes
ALL_TARGET=	${JDKMVERSION}

PORTDOCS=	*

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar

NO_STAGE=	yes
post-patch:
.if !defined(NOPORTDOCS)
	@${REINPLACE_CMD} "s|doc, jar, _zip|doc, jar|" ${WRKSRC}/build.xml
.else
	@${REINPLACE_CMD} "s|doc, jar, _zip|jar|" ${WRKSRC}/build.xml
.endif

do-install:
	@${ECHO_MSG} -n ">> Installing JAR file as ${JAVAJARDIR}/${PORTNAME}.jar..."
	@${INSTALL_DATA} ${WRKSRC}/target/${PORTNAME}-${PORTVERSION}.jar ${JAVAJARDIR}/${PORTNAME}.jar
	@${ECHO_MSG} " [DONE]"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation..."
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${FIND} index.html css \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR} > /dev/null 2>&1
	@cd ${WRKSRC}/target/site && ${FIND} apidocs \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR} > /dev/null 2>&1
	@${ECHO_MSG} " [DONE]"
.endif

.include <bsd.port.mk>
