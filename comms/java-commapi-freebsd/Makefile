# New ports collection makefile for:	java freebsd-commapi
# Date created:         2001/07/01
# Whom:			Ari Suutari <ari.suutari@syncrontech.com>
#
# $FreeBSD$
#

PORTNAME=	java-commapi-freebsd
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	comms java
MASTER_SITES=	http://www.syncrontech.org/freebsd/
DISTNAME=	freebsd-commapi-0.2

MAINTAINER=	ari.suutari@syncrontech.com
COMMENT=	Java Communication API for FreeBSD

BUILD_DEPENDS=	${JDKDIR}/jre/lib/ext/comm.jar:${PORTSDIR}/comms/java-commapi
RUN_DEPENDS=	${JDKDIR}/jre/lib/ext/comm.jar:${PORTSDIR}/comms/java-commapi

USE_JAVA=	1.1+

JDKDIR=		${JAVA_HOME}

MAKE_ENV=	JAVA_HOME=${JDKDIR}

PLIST_SUB+=	JAVA_HOME=${JAVA_HOME:S/${PREFIX}\///}

.include <bsd.port.mk>
