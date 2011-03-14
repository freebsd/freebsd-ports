# New ports collection makefile for:	jasmin
# Date created:			May 26, 2004
# Whom:				Volker Stolz <vs@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jasmin
PORTVERSION=	2.4
PORTEPOCH=	1
CATEGORIES=	java lang
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java Assembler Interface

USE_ZIP=	yes
USE_ANT=	yes
ALL_TARGET=	jasmin
USE_JAVA=	yes
JAVA_VERSION=	1.2+
USE_DOS2UNIX=	yes
DOS2UNIX_REGEX=	.*\.(txt|xml|j|class|java|mf|css|bnf|html)

SUB_FILES=	jasmin.sh

do-install:
	${INSTALL_DATA} ${WRKSRC}/jasmin.jar ${JAVAJARDIR}
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/examples ; \
	  ${FIND} . -type d -exec ${MKDIR} ${EXAMPLESDIR}/\{} \; ;\
	  ${FIND} . -type f -exec ${INSTALL_DATA} \{} ${EXAMPLESDIR}/\{} \;
.endif
	${INSTALL_SCRIPT} ${WRKDIR}/jasmin.sh ${PREFIX}/bin/jasmin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCDIR}
	cd ${WRKSRC}/docs ; \
	  ${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/\{} \; ;\
	  ${FIND} . -type f -exec ${INSTALL_DATA} \{} ${DOCSDIR}/\{} \;
.endif

.include <bsd.port.mk>
