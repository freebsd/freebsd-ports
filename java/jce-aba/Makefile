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

MAINTAINER=	greg@greg.rim.or.jp
COMMENT=	Clean room implementation of the Java Cryptograph Extension (JCE) API

USE_JAVA=	1.1+

NO_BUILD=	yes
JDKVERSION=	1.1

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib-${JDKVERSION}/jce.zip ${PREFIX}/share/java/classes/
	${MKDIR} ${PREFIX}/share/java/jce-aba
	cd ${WRKSRC}/docs-${JDKVERSION} && ${FIND} . \
	  | ${CPIO} -pdmu -R ${DOCOWN}:${DOCGRP} ${PREFIX}/share/java/jce-aba

.include <bsd.port.mk>
