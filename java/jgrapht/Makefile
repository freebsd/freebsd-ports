# Created by: ijliao
# $FreeBSD$

PORTNAME=	jgrapht
PORTVERSION=	0.7.3
PORTREVISION=	1
CATEGORIES=	java math
MASTER_SITES=	SF/${PORTNAME}/JGraphT/Version%20${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java package for mathematical graph-theory objects and algorithms

USES=		zip
USE_JAVA=	yes
JAVA_VERSION=	1.6+

.if !defined(WITHOUT_COMPILE)
USE_ANT=	yes
ALL_TARGET=	jar
.if !defined(NOPORTDOCS)
ALL_TARGET+=	javadoc
.endif
.else
NO_BUILD=	yes
.endif

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar

NO_STAGE=	yes
.include <bsd.port.pre.mk>

JAVA_PORT_API=	${LOCALBASE}/share/doc/jdk${JAVA_PORT_VERSION:C/([0-9]\.[0-9])\.[0-9]/\1/}/api
.if exists(${JAVA_PORT_API})
MAKE_ARGS+=	-Djdk.api="${JAVA_PORT_API}"
.endif

pre-fetch:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You may use the following build options:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "    WITHOUT_COMPILE=yes    Install the pre-compiled .jar file"
	@${ECHO_MSG} ""

do-install:
	@${ECHO_MSG} -n  ">> Installing JAR as ${JAVAJARDIR}/${PORTNAME}.jar..."
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}-jdk${JAVA_PORT_VERSION:C/1\.4\.[0-9]/1.4/:C/1\.[56]\.[0-9]/1.5/}.jar ${JAVAJARDIR}/${PORTNAME}.jar
	@${ECHO_MSG} " [DONE]"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@cd ${WRKSRC}/javadoc && ${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/{} \;
	@cd ${WRKSRC}/javadoc && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
	@${ECHO_MSG} " [DONE]"
.endif

.include <bsd.port.post.mk>
