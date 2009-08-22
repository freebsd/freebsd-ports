# Ports collection makefile for:	FlexJson
# Date created:			20 Apr 2006
# Whom:				Nemo Liu <nemoliu@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	flexjson
PORTVERSION=	1.6
PORTREVISION=	1
CATEGORIES=	devel java
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/Flexjson%201.0
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A lightweight Java library to write JSON

USE_JAVA=	yes
JAVA_VERSION=	1.5+
NO_BUILD=	yes
USE_ZIP=	yes

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar

.if !defined(NOPORTDOCS)
PORTDOCS=	LICENSE-2.0.txt docs
.endif

do-install:
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/${PORTNAME}.jar..."
	@${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.jar \
		${JAVAJARDIR}/${PORTNAME}.jar

	@${ECHO_MSG} " [DONE]"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation..."
	@${MKDIR} ${DOCSDIR}/docs/
	@cd ${WRKDIR}/docs \
	  && ${INSTALL_DATA} example_object_model.jpg ${DOCSDIR}/docs/. \
	  && ${INSTALL_DATA} index.html ${DOCSDIR}/docs/.
	@${INSTALL_DATA} ${WRKDIR}/LICENSE-2.0.txt ${DOCSDIR}/
	@${ECHO_MSG} " [DONE]"
.endif

.include <bsd.port.mk>
