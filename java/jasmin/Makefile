# New ports collection makefile for:	jasmin
# Date created:			May 26, 2004
# Whom:				Volker Stolz <vs@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jasmin
PORTVERSION=	1.1
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	java lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java Assembler Interface

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

USE_ZIP=	yes
USE_ANT=	yes
ALL_TARGET=	jasmin
USE_JAVA=	yes
JAVA_VERSION=	1.2+

SUB_FILES=	jasmin.sh

do-install:
	${INSTALL_DATA} ${WRKSRC}/jasmin.jar ${JAVAJARDIR}
	${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/examples ; \
	  ${FIND} . -type d -exec ${MKDIR} ${EXAMPLESDIR}/\{} \; ;\
	  ${FIND} . -type f -exec ${INSTALL_DATA} \{} ${EXAMPLESDIR}/\{} \;
	${INSTALL_SCRIPT} ${WRKDIR}/jasmin.sh ${PREFIX}/bin/jasmin

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCDIR}
	cd ${WRKSRC}/docs ; \
	  ${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/\{} \; ;\
	  ${FIND} . -type f -exec ${INSTALL_DATA} \{} ${DOCSDIR}/\{} \;
.endif

.include <bsd.port.mk>
