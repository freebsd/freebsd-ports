# Ports collection makefile for:	jakarta-bcel
# Date created:				6 May 2002
# Whom:					des
# $FreeBSD$
#

PORTNAME=	bcel
PKGNAMEPREFIX=	jakarta-
PORTVERSION=	5.1
CATEGORIES=	java devel
MASTER_SITES=	http://www.apache.org/dist/jakarta/${PORTNAME}/binaries/ \
		http://nagoya.apache.org/mirror/jakarta/${PORTNAME}/binaries/ \
		http://www.powertech.no/apache/dist/jakarta/${PORTNAME}/binaries/ \

MAINTAINER=	des@FreeBSD.org
COMMENT=	A library for generating Java bytecode

NO_BUILD=	yes
USE_JAVA=	1.2+

do-install:
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}.jar \
	    ${JAVAJARDIR}/${PORTNAME}.jar
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}/docs && ${FIND} . -print | \
	    ${CPIO} -pdmu -R${DOCOWN}:${DOCGRP} ${DOCSDIR})
.endif

.include <bsd.port.mk>
