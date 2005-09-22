# ex:ts=8
# Ports collection makefile for:	itext
# Date created:			Apr 2, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	itext
PORTVERSION=	1.3.4
PORTEPOCH=	1
CATEGORIES=	devel java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.jar

MAINTAINER=	sw@gegenunendlich.de
COMMENT=	A Java-PDF Library

USE_JAVA=	yes
JAVA_VERSION=	1.2+
NO_BUILD=	yes
EXTRACT_ONLY=	# empty

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar

do-install:
	${INSTALL_DATA} ${_DISTDIR}/${DISTFILES} ${JAVAJARDIR}/${PORTNAME}.jar

.include <bsd.port.mk>
