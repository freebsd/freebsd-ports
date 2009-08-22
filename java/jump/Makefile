# New ports collection makefile for:	JUMP Ultimate Math Package
# Date created:				June 13, 2002
# Whom:					Ernst de Haan <znerd@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jump
PORTVERSION=	0.5
PORTREVISION=	2
CATEGORIES=	java math
MASTER_SITES=	SF/${PORTNAME}-math/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java library for arbitrary precision computations

USE_JAVA=	yes
JAVA_VERSION=	1.2+
USE_ANT=	yes

.if defined(NOPORTDOCS)
ALL_TARGET=	jar
.else
ALL_TARGET=	jar apidocs
.endif
JARFILE=	${PORTNAME}.jar

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

PLIST_FILES+=	%%JAVAJARDIR%%/${JARFILE}

do-install:
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/${JARFILE}..."
	@${INSTALL_DATA} ${WRKSRC}/build/${JARFILE} ${JAVAJARDIR}/${JARFILE}
	@${ECHO_MSG} " [ DONE ]"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/build/apidocs/ && ${FIND} . \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR} > /dev/null 2>&1
	@${ECHO_MSG} " [ DONE ]"
.endif

.include <bsd.port.mk>
