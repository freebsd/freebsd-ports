# New ports collection makefile for:	java freebsd-commapi
# Date created:         2001/07/01
# Whom:			Ari Suutari <ari.suutari@syncrontech.com>
#
# $FreeBSD$
#

PORTNAME=	java-commapi-freebsd
PORTVERSION=	0.6
CATEGORIES=	comms java
MASTER_SITES=	http://www.syncrontech.org/freebsd/
DISTNAME=	freebsd-commapi-${PORTVERSION}

MAINTAINER=	ari.suutari@syncrontech.com
COMMENT=	Java Communication API for FreeBSD

BUILD_DEPENDS=	${JDKDIR}/jre/lib/ext/comm.jar:${PORTSDIR}/comms/java-commapi
RUN_DEPENDS=	${JDKDIR}/jre/lib/ext/comm.jar:${PORTSDIR}/comms/java-commapi

USE_JAVA=	yes
JAVA_VERSION=	1.3+
JAVA_OS=	native
JAVA_BUILD=	yes

JDKDIR=		${JAVA_HOME}

MAKE_ENV=	JAVA_HOME=${JDKDIR}

PLIST_SUB+=	JAVA_HOME=${JAVA_HOME:S/${PREFIX}\///}
PLIST_FILES=	%%JAVA_HOME%%/jre/lib/ext/CommDriver.jar \
		%%JAVA_HOME%%/jre/lib/i386/libSerial.so \
		%%JAVA_HOME%%/jre/lib/i386/libParallel.so \
		%%JAVA_HOME%%/jre/lib/javax.comm.properties

.include <bsd.port.mk>
