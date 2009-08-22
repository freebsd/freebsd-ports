# New ports collection makefile for:	jxm
# Date created:		07 March 2004
# Whom:			Nick Sayer <nsayer@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	jxm
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	audio java
MASTER_SITES=	SF/javaxm/JAR%20file%20only/${PORTVERSION}
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XMPCR (USB XM radio) control software

RUN_DEPENDS=	${JAVA_HOME}/jre/lib/ext/CommDriver.jar:${PORTSDIR}/comms/java-commapi-freebsd

USE_JAVA=	yes
JAVA_VERSION=	1.4+
JAVA_OS=	native

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

SUB_FILES=	jxm.sh
PLIST_FILES=	%%JAVAJARDIR%%/jxm.jar bin/jxm

do-install:
	@${INSTALL_DATA} ${DISTDIR}/${DISTFILES} ${JAVAJARDIR}/jxm.jar
	@${INSTALL_SCRIPT} ${WRKDIR}/jxm.sh ${PREFIX}/bin/jxm

.include <bsd.port.mk>
