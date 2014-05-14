# Created by: ijliao
# $FreeBSD$

PORTNAME=	jfreechart
PORTVERSION=	1.0.14
CATEGORIES=	java graphics
MASTER_SITES=	SF/${PORTNAME}/1.%20JFreeChart/${PORTVERSION}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	A free Java class library for generating charts

RUN_DEPENDS=	${JAVALIBDIR}/jcommon.jar:${PORTSDIR}/java/jcommon

USE_JAVA=	yes
JAVA_VERSION=	1.6+

.if !defined(WITHOUT_COMPILE)
USE_ANT=	yes
ALL_TARGET=	compile
BUILD_WRKSRC=	${WRKSRC}/ant
.else
NO_BUILD=	yes
.endif

.if !defined(NOPORTDOCS) && !defined(WITHOUT_COMPILE)
ALL_TARGET+=	javadoc
PORTDOCS=	*
.endif

PLIST_FILES=	%%JAVAJARDIR%%/jfreechart.jar \
		%%JAVAJARDIR%%/gnujaxp.jar

pre-fetch:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You may use the following build options:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "    WITHOUT_COMPILE=yes    Install the pre-compiled .jar file"
	@${ECHO_MSG} ""

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/${PORTNAME}-${PORTVERSION}.jar ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar
	${INSTALL_DATA} ${WRKSRC}/lib/gnujaxp.jar ${STAGEDIR}${JAVAJARDIR}/gnujaxp.jar
.if !defined(NOPORTDOCS) && !defined(WITHOUT_COMPILE)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/javadoc && ${FIND} . \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
