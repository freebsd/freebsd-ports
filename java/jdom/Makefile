# New ports collection makefile for:	JDOM
# Date created:		June 1, 2001
# Whom:			Ernst de Haan <znerd@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jdom
PORTVERSION=	1.0b9
PORTREVISION=	1
CATEGORIES=	java
MASTER_SITES=	http://www.jdom.org/dist/source/
DISTNAME=	${PORTNAME}-${PORTVERSION:C/[0-9]*\.[0-9]*//}

MAINTAINER=	znerd@FreeBSD.org
COMMENT=	Java library for accessing and manipulating XML documents

BUILD_DEPENDS=	${ANT}:${PORTSDIR}/devel/apache-ant
RUN_DEPENDS=	${JAVAJARDIR}/jaxen-jdom.jar:${PORTSDIR}/java/jaxen

USE_JAVA=	yes
JAVA_VERSION=	1.2+

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:C/[0-9]*\.[0-9]*//}
ANT?=		${LOCALBASE}/bin/ant
ANT_TARGET=	package
.if !defined(NOPORTDOCS)
ANT_TARGET+=	javadoc
OTHERDOCS=	README.txt TODO.txt CHANGES.txt COMMITTERS.txt LICENSE.txt
PORTDOCS=	apidocs ${OTHERDOCS}
.endif

PLIST_FILES=	${JAVAJARDIR:S,^${PREFIX}/,,}/jdom.jar

do-build:
	@cd ${WRKSRC} && ${ANT} ${ANT_TARGET}

do-install:
	@${ECHO} -n ">> Installing JAR in ${JAVAJARDIR}..."
	@${MKDIR} ${JAVAJARDIR}
	@${CP} ${WRKSRC}/build/jdom.jar ${JAVAJARDIR}/
	@${ECHO} " jdom.jar [ DONE ]"
.if !defined(NOPORTDOCS)
	@${ECHO} -n ">> Installing samples in ${EXAMPLESDIR}..."
	@${MKDIR} ${EXAMPLESDIR}
	@${CP} -r ${WRKSRC}/samples/* ${EXAMPLESDIR}/
	@${ECHO} " [ DONE ]"
	@${ECHO} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${DOCSDIR}
.for PORTDOC in ${OTHERDOCS}
	@${CP} ${WRKSRC}/${PORTDOC} ${DOCSDIR}/
	@${ECHO} -n " ${PORTDOC}"
.endfor
	@${CP} -r ${WRKSRC}/build/apidocs ${DOCSDIR}/
	@${ECHO} " apidocs [ DONE ]"
.endif

.include <bsd.port.mk>
