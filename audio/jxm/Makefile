# New ports collection makefile for:	jxm
# Date created:		07 March 2004
# Whom:			Nick Sayer <nsayer@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	jxm
PORTVERSION=	1.2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	javaxm
DISTNAME=	jxm-${PORTVERSION}
EXTRACT_SUFX=	.jar

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XMPCR (USB XM radio) control software

RUN_DEPENDS=	${JAVA_HOME}/jre/lib/ext/CommDriver.jar:${PORTSDIR}/comms/java-commapi-freebsd

USE_JAVA=	yes
JAVA_VERSION=	1.4+
JAVA_OS=	native

NO_BUILD=	yes

SUB_FILES=	jxm.sh
PLIST_FILES=	%%JAVAJARDIR%%/jxm.jar bin/jxm

do-extract:
	${MKDIR} ${WRKDIR}

do-install:
	${INSTALL_DATA} ${DISTDIR}/${DISTFILES} \
		${JAVAJARDIR}/jxm.jar
	${INSTALL_SCRIPT} ${WRKDIR}/jxm.sh \
		${PREFIX}/bin/jxm

.include <bsd.port.mk>
