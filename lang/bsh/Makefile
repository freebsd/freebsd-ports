# New ports collection makefile for:   bsh
# Date created:                25 January 2002
# Whom:                        Kimura Fuyuki <fuyuki@mj.0038.net>
#
# $FreeBSD$
#

PORTNAME=	bsh
PORTVERSION=	2.0.b4
CATEGORIES=	java
MASTER_SITES=	http://www.beanshell.org/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.b/b/}
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Java scripting environment

PLIST_FILES=	%%JAVAJARDIR%%/bsh.jar bin/bsh
USE_JAVA=	yes
JAVA_VERSION=	1.2+
NO_BUILD=	yes
SUB_FILES=	bsh.sh

do-install:
	${MKDIR} ${JAVALIBDIR}
	${INSTALL_DATA} ${DISTDIR}/${DISTFILES} ${JAVAJARDIR}/bsh.jar
	${INSTALL_SCRIPT} ${WRKDIR}/bsh.sh ${PREFIX}/bin/bsh

.include <bsd.port.mk>
