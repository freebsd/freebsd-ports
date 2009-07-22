# ex:ts=8
# Ports collection makefile for:	jcommon
# Date created:			Nov 11, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	jcommon
PORTVERSION=	1.0.16
CATEGORIES=	java devel
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	jfreechart

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A collection of useful classes used by JFreeChart and JFreeReport

USE_JAVA=	yes
JAVA_VERSION=	1.2+

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
	@${ECHO_MSG} -n  ">> Installing .jar files in ${JAVAJARDIR}/..."
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}-${PORTVERSION}.jar ${JAVAJARDIR}/${PORTNAME}.jar
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}-xml-${PORTVERSION}.jar ${JAVAJARDIR}/${PORTNAME}-xml.jar
	@${ECHO_MSG} " [DONE]"
.if !defined(NOPORTDOCS) && !defined(WITHOUT_COMPILE)
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/javadoc && ${FIND} . \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
	@${ECHO_MSG} " [DONE]"
.endif

.include <bsd.port.mk>
