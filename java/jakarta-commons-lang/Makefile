# New ports collection makefile for:	Jakarta Commons Lang
# Date created:				October 18, 2002
# Whom:					Ernst de Haan <znerd@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	commons-lang
PORTVERSION=	2.0
CATEGORIES=	java
MASTER_SITES=	${MASTER_SITE_APACHE_JAKARTA}
MASTER_SITE_SUBDIR=	commons/lang/source
PKGNAMEPREFIX=	jakarta-
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	hq@FreeBSD.org
COMMENT=	Jakarta library with helper utilities for the java.lang API

USE_JAVA=	yes
JAVA_VERSION=	1.2+

USE_ANT=	yes
USE_JIKES=	no

ALL_TARGET=	jar
.if !defined(NOPORTDOCS)
ALL_TARGET+=	javadoc
PORTDOCS=	*
.endif

JARFILE=	${PORTNAME}-${PORTVERSION}.jar
DESTJARFILE=	${PORTNAME}.jar
PLIST_FILES=	%%JAVAJARDIR%%/${DESTJARFILE}

do-install:
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/${DESTJARFILE}..."
	@${INSTALL_DATA} ${WRKSRC}/dist/${JARFILE} ${JAVAJARDIR}/${DESTJARFILE}
	@${ECHO_MSG} " [ DONE ]"

.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}/..."
	@cd ${WRKSRC}/dist/docs/api \
	  && ${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/{} \; \
	  && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
	@${ECHO_MSG} " [ DONE ]"
.endif

.include <bsd.port.mk>
