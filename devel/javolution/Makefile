# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	javolution
PORTVERSION=	5.5.1
CATEGORIES=	devel java
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	ale

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Java solution for real time and embedded systems

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USE_JAVA=	yes
JAVA_VERSION=	1.6
USE_ANT=	yes
ALL_TARGET=	1.6

PORTDOCS=	*

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
.if ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} "s|doc, jar, _zip|doc, jar|" ${WRKSRC}/build.xml
.else
	@${REINPLACE_CMD} "s|doc, jar, _zip|jar|" ${WRKSRC}/build.xml
.endif

do-install:
	@${ECHO_MSG} -n ">> Installing JAR file as ${JAVAJARDIR}/${PORTNAME}.jar..."
	@${INSTALL_DATA} ${WRKSRC}/target/${PORTNAME}-${PORTVERSION}.jar \
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar
	@${ECHO_MSG} " [DONE]"
.if ${PORT_OPTIONS:MDOCS}
	@${ECHO_MSG} -n ">> Installing documentation..."
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC} && ${FIND} index.html css \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${DOCSDIR} > /dev/null 2>&1
	@cd ${WRKSRC}/target/site && ${FIND} apidocs \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${DOCSDIR} > /dev/null 2>&1
	@${ECHO_MSG} " [DONE]"
.endif

.include <bsd.port.mk>
