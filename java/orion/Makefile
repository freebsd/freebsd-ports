# New ports collection makefile for:   orion
# Date created:        22 December 2000
# Whom:                Ernst de Haan <ernst@jollem.com>
#
# $FreeBSD$
#

PORTNAME=	orion
PORTVERSION=	1.4.0
CATEGORIES=	java www
MASTER_SITES=	ftp://ftp.sunet.se/pub/database/utils/orionserver/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ernst@jollem.com

RUN_DEPENDS=	${JAVADIR}/bin/java:${PORTSDIR}/java/jdk12-beta

USE_ZIP=	YES
NO_BUILD=	YES
PLIST_SUB=	ORIONSUBDIR=${DISTNAME}

WRKSRC=		${WRKDIR}/${PORTNAME}
JDK_VERSION=	1.2.2
JAVADIR=	${PREFIX}/jdk${JDK_VERSION}
ORION_DESTDIR=	${PREFIX}/${DISTNAME}
RECURSIVE_CP=	${CP} -R

.include <bsd.port.pre.mk>

do-install:
	@${MKDIR} ${ORION_DESTDIR}
	@${RECURSIVE_CP} ${WRKSRC}/* ${ORION_DESTDIR}

.include <bsd.port.post.mk>
