# New ports collection makefile for:	Portlet API
# Date created:				October 04, 2005
# Whom:					Herve Quiroz <hq@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	portlet-api
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	devel java
MASTER_SITES=	http://www.ibiblio.org/maven/portlet-api/jars/
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=	# empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Portlet API (JSR-168)

USE_JAVA=	yes
JAVA_VERSION=	1.4+
NO_BUILD=	yes

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar

do-install:
	${INSTALL_DATA} ${_DISTDIR}/${DISTFILES} ${JAVAJARDIR}/${PORTNAME}.jar

.include <bsd.port.mk>
