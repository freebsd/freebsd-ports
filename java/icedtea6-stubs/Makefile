# New ports collection makefile for:    icedtea6-stubs
# Date created:         2009/2/21
# Whom:                 Brian Gardner <brian@experts-exchange.com>
#
# $FreeBSD$
#

PORTNAME=	icedtea6-stubs
PORTVERSION=	1.6b
CATEGORIES=	java devel
MASTER_SITES=	http://www.intricatesoftware.com/distfiles/
DISTNAME=	jdk-7-icedtea-plugs-${PORTVERSION}

MAINTAINER=	brian@getsnappy.com
COMMENT=	IcedTea6 binary plugs for openjdk

BUILD_DEPENDS+=	unzip:${PORTSDIR}/archivers/unzip
BUILD_DEPENDS+=	zip:${PORTSDIR}/archivers/zip

WRKSRC=		${WRKDIR}/jdk-7-icedtea-plugs

USE_JAVA=	yes
JAVA_VENDOR=	freebsd bsdjava
JAVA_VERSION=	1.6
USE_ANT=	yes

pre-build:
	cd ${WRKSRC} && ${UNZIP_CMD} -u src.zip

do-install:
	${MKDIR} ${JAVAJARDIR}/jdk-7-icedtea-plugs/jre/lib/
	${CP} ${WRKSRC}/jre/lib/rt-closed.jar ${JAVAJARDIR}/jdk-7-icedtea-plugs/jre/lib/

PLIST_FILES+=	%%JAVAJARDIR%%/jdk-7-icedtea-plugs/jre/lib/rt-closed.jar

.include <bsd.port.mk>
