# ex:ts=8
# Ports collection makefile for:	java-getopt
# Date created:			Apr 7, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	getopt
PORTVERSION=	1.0.9
CATEGORIES=	java
MASTER_SITES=	ftp://ftp.urbanophile.com/pub/arenn/software/sources/
PKGNAMEPREFIX=	java-
DISTNAME=	${PKGNAME}
EXTRACT_SUFX=	.jar

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java version of GNU getopt family functions

PLIST_FILES=	share/java/classes/getopt.jar
USE_JAVA=	1.1+
NO_WRKSUBDIR=	yes
EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	.
NO_BUILD=	yes

do-install:
	@${MKDIR} ${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/${PKGNAME}.jar ${JAVAJARDIR}/${PORTNAME}.jar

.include <bsd.port.mk>
