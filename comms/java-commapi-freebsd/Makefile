# New ports collection makefile for:	java freebsd-commapi
# Date created:         2001/07/01
# Whom:			Ari Suutari <ari.suutari@syncrontech.com>
#
# $FreeBSD$
#

PORTNAME=	java-commapi-freebsd
PORTVERSION=	0.2
CATEGORIES=	comms java
MASTER_SITES=	http://www.syncrontech.org/freebsd/
DISTNAME=	freebsd-commapi-0.2

MAINTAINER=	ari.suutari@syncrontech.com
COMMENT=	Java Communication API for FreeBSD

BUILD_DEPENDS=	${JDKDIR}/bin/javac:${PORTSDIR}/java/jdk13 \
		${JDKDIR}/jre/lib/ext/comm.jar:${PORTSDIR}/comms/java-commapi
RUN_DEPENDS=	${JDKDIR}/bin/java:${PORTSDIR}/java/jdk13 \
		${JDKDIR}/jre/lib/ext/comm.jar:${PORTSDIR}/comms/java-commapi

JDKDIR=		${LOCALBASE}/jdk1.3.1
MAKE_ENV=	JAVA_HOME=${JDKDIR}

.include <bsd.port.mk>
