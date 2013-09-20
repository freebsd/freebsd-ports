# $FreeBSD$

PORTNAME=	bcel
PORTVERSION=	5.2
PORTREVISION=	2
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_APACHE_JAKARTA}
MASTER_SITE_SUBDIR=	${PORTNAME}/binaries
PKGNAMEPREFIX=	jakarta-

MAINTAINER=	java@FreeBSD.org
COMMENT=	A library for generating Java bytecode

NO_BUILD=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+

PLIST_FILES=	%%JAVAJARDIR%%/bcel.jar

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

NO_STAGE=	yes
do-install:
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}.jar \
	    ${JAVAJARDIR}/${PORTNAME}.jar
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}/docs && ${FIND} . -print | \
	    ${CPIO} -pdmu -R${DOCOWN}:${DOCGRP} ${DOCSDIR})
.endif

.include <bsd.port.mk>
