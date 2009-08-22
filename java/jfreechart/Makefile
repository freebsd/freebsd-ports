# ex:ts=8
# Ports collection makefile for:	jfreechart
# Date created:			Nov 11, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	jfreechart
PORTVERSION=	1.0.10
CATEGORIES=	java graphics
MASTER_SITES=	SF/${PORTNAME}/1.%20JFreeChart/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A free Java class library for generating charts

RUN_DEPENDS=	${JAVALIBDIR}/jcommon.jar:${PORTSDIR}/java/jcommon

USE_JAVA=	yes
JAVA_VERSION=	1.2+

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
	@${ECHO_MSG} -n  ">> Installing .jar files in ${JAVAJARDIR}/..."
.if defined(WITHOUT_COMPILE)
	@${INSTALL_DATA} ${WRKSRC}/lib/${PORTNAME}-${PORTVERSION}.jar ${JAVAJARDIR}/${PORTNAME}.jar
.else
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}-${PORTVERSION}.jar ${JAVAJARDIR}/${PORTNAME}.jar
.endif
	@${INSTALL_DATA} ${WRKSRC}/lib/gnujaxp.jar ${JAVAJARDIR}/gnujaxp.jar
	@${ECHO_MSG} " [DONE]"
.if !defined(NOPORTDOCS) && !defined(WITHOUT_COMPILE)
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/javadoc && ${FIND} . \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
	@${ECHO_MSG} " [DONE]"
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
