# New ports collection makefile for:	java freebsd-commapi
# Date created:         2001/07/01
# Whom:			Ari Suutari <ari.suutari@syncrontech.com>
#
# $FreeBSD$
#

PORTNAME=	java-commapi-freebsd
PORTVERSION=	0.1
CATEGORIES=	comms java
MASTER_SITES=	http://homepages.ulb.ac.be/~jdricot/commapi/
DISTNAME=	CommAPI
EXTRACT_SUFX=	.tgz

MAINTAINER=	ari.suutari@syncrontech.com

BUILD_DEPENDS=	${JDK13DIR}/bin/javac:${PORTSDIR}/java/jdk13 \
		${JDK13DIR}/jre/lib/ext/comm.jar:${PORTSDIR}/comms/java-commapi
RUN_DEPENDS=	${JDK13DIR}/bin/java:${PORTSDIR}/java/jdk13 \
		${JDK13DIR}/jre/lib/ext/comm.jar:${PORTSDIR}/comms/java-commapi

JDK13DIR=	${LOCALBASE}/jdk1.3.1
WRKSRC=		${WRKDIR}/FreeBSD_CommAPI
USE_GMAKE=	yes

.include <bsd.port.mk>
