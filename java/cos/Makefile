# New ports collection makefile for:	cos
# Date created:		1999/07/05
# Whom:			Jose Marques <noway@nohow.demon.co.uk>
#
# $FreeBSD$
#

PORTNAME=	cos
PORTVERSION=	2002.11.05
PORTEPOCH=	1
CATEGORIES=	java
MASTER_SITES=	http://www.servlets.com/cos/
DISTNAME=	${PORTNAME}-05Nov2002

MAINTAINER=	java@freebsd.org
COMMENT=	The O'Reilly package of utility classes for servlet developers

USE_ZIP=	yes
NO_WRKSUBDIR=	yes
USE_JAVA=	1.1+
NO_BUILD=	yes
RESTRICTED=	"Special conditions apply for commercial use, see licence"

do-install:
	@${MKDIR} ${PREFIX}/share/java/classes ${PREFIX}/share/java/cos
	@${INSTALL_DATA} ${WRKSRC}/lib/cos.jar ${PREFIX}/share/java/classes
	@cd ${WRKSRC}; \
	  ${CP} readme.txt ${PREFIX}/share/java/cos; \
	  ${CP} license.txt ${PREFIX}/share/java/cos; \
	  ${CP} -R doc ${PREFIX}/share/java/cos; \
	  ${CP} upload.war ${PREFIX}/share/java/cos/doc

.include <bsd.port.mk>
