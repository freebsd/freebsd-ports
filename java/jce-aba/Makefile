# New ports collection makefile for:	Java Cryptograph Extension
# Date created:		2000/02/11
# Whom:			Kensaku Masuda <greg@greg.rim.or.jp>
#
# $FreeBSD$
#

PORTNAME=	jce-aba
PORTVERSION=	1.1
CATEGORIES=	java security
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	znerd

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Clean room implementation of the Java Cryptograph Extension (JCE) API

USE_JAVA=	yes

NO_BUILD=	yes

PLIST_FILES=	%%JAVAJARDIR%%/jce.zip

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

.include <bsd.port.pre.mk>

.if ${JAVA_PORT_VERSION:C/^([0-9])\.([0-9])(.*)$/\1.\2/} == "1.1"
JDKVERSION=	1.1
PKGNAMESUFFIX=	-java11
.else
JDKVERSION=	1.2
PKGNAMESUFFIX=	-java12
.endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib-${JDKVERSION}/jce.zip ${JAVAJARDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/docs-${JDKVERSION} && ${FIND} . \
	  | ${CPIO} -pdmu -R ${DOCOWN}:${DOCGRP} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
