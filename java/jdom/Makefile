# New ports collection makefile for:	JDOM
# Date created:		June 1, 2001
# Whom:			Ernst de Haan <znerd@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jdom
PORTVERSION=	1.0b10
CATEGORIES=	java textproc
MASTER_SITES=	http://www.jdom.org/dist/source/
DISTNAME=	${PORTNAME}-${PORTVERSION:C/[0-9]*\.[0-9]*//}

MAINTAINER=	znerd@FreeBSD.org
COMMENT=	Java library for accessing and manipulating XML documents

RUN_DEPENDS=	${LOCAL_JAVAJARDIR}/jaxen-jdom.jar:${PORTSDIR}/java/jaxen

USE_JAVA=	yes
JAVA_VERSION=	1.2+
USE_ANT=	yes
USE_JIKES=	no

LOCAL_JAVAJARDIR=	${JAVAJARDIR:S,^${PREFIX},${LOCALBASE},}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:C/[0-9]*\.[0-9]*//}
ALL_TARGET=	package
.if !defined(NOPORTDOCS)
ALL_TARGET+=	javadoc
OTHERDOCS=	README.txt TODO.txt CHANGES.txt COMMITTERS.txt LICENSE.txt
PORTDOCS=	apidocs ${OTHERDOCS}
.endif

MAKE_ENV+=	CLASSPATH=${LOCAL_JAVAJARDIR}/jaxen-jdom.jar

PLIST_FILES=	%%JAVAJARDIR%%/jdom.jar

do-install:
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/jdom.jar..."
	@${MKDIR} ${JAVAJARDIR}
	@${INSTALL_DATA} ${WRKSRC}/build/jdom.jar ${JAVAJARDIR}/
	@${ECHO_MSG} " [ DONE ]"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing samples in ${EXAMPLESDIR}..."
	@cd ${WRKSRC}/build/samples/ && ${FIND} . \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR} > /dev/null 2>&1
	@${ECHO_MSG} " [ DONE ]"
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@cd ${WRKSRC}/build/ && ${FIND} apidocs \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR} > /dev/null 2>&1
	@${INSTALL_DATA} ${OTHERDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
	@${ECHO_MSG} " [ DONE ]"
.endif

.include <bsd.port.mk>
