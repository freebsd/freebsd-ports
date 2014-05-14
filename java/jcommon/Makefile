# Created by: ijliao
# $FreeBSD$

PORTNAME=	jcommon
PORTVERSION=	1.0.19
CATEGORIES=	java devel
MASTER_SITES=	SF/jfreechart/3.%20JCommon/${PORTVERSION}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	A collection of useful classes used by JFreeChart and JFreeReport

USE_JAVA=	yes
JAVA_VERSION=	1.6+

.if !defined(WITHOUT_COMPILE)
USE_ANT=	yes
ALL_TARGET=	compile-xml
BUILD_WRKSRC=	${WRKSRC}/ant
.else
NO_BUILD=	yes
.endif

.if !defined(NOPORTDOCS) && !defined(WITHOUT_COMPILE)
ALL_TARGET+=	javadoc
PORTDOCS=	*
.endif

PLIST_FILES=	%%JAVAJARDIR%%/jcommon.jar %%JAVAJARDIR%%/jcommon-xml.jar

pre-fetch:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You may use the following build options:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "    WITHOUT_COMPILE=yes    Install the pre-compiled .jar file"
	@${ECHO_MSG} ""

do-install:
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}-${PORTVERSION}.jar ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}-xml-${PORTVERSION}.jar ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}-xml.jar
.if !defined(NOPORTDOCS) && !defined(WITHOUT_COMPILE)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/javadoc && ${FIND} . \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
