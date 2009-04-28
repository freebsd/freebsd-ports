# Ports collection makefile for:	javolution
# Date created:			22 September 2007
# Whom:				Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	javolution
PORTVERSION=	5.3.0
CATEGORIES=	devel java
MASTER_SITES=	http://javolution.org/target/
DISTNAME=	${PORTNAME}-${PORTVERSION}-bin

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A Java solution for real time and embedded systems

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.5+
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

PORTDOCS=	*

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar

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
