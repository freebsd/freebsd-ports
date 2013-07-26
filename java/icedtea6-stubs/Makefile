# Created by: Brian Gardner <brian@experts-exchange.com>
# $FreeBSD$

PORTNAME=	icedtea6-stubs
PORTVERSION=	1.6b
CATEGORIES=	java devel
MASTER_SITES=	http://www.intricatesoftware.com/distfiles/
DISTNAME=	jdk-7-icedtea-plugs-${PORTVERSION}

MAINTAINER=	openjdk@getsnappy.com
COMMENT=	IcedTea6 binary plugs for openjdk

BUILD_DEPENDS+=	${LOCALBASE}/bin/unzip:${PORTSDIR}/archivers/unzip
BUILD_DEPENDS+=	zip:${PORTSDIR}/archivers/zip

DEPRECATED=	Broken for more than 6 month
EXPIRATION_DATE=	2013-08-27

BROKEN=		Does not build with any of the supported Java vendors

WRKSRC=		${WRKDIR}/jdk-7-icedtea-plugs

USE_JAVA=	yes
JAVA_VENDOR=	openjdk
JAVA_VERSION=	1.6
USE_ANT=	yes

pre-build:
	cd ${WRKSRC} && ${UNZIP_CMD} -u src.zip

do-install:
	${MKDIR} ${JAVAJARDIR}/jdk-7-icedtea-plugs/jre/lib/
	${CP} ${WRKSRC}/jre/lib/rt-closed.jar ${JAVAJARDIR}/jdk-7-icedtea-plugs/jre/lib/

PLIST_FILES+=	%%JAVAJARDIR%%/jdk-7-icedtea-plugs/jre/lib/rt-closed.jar

.include <bsd.port.mk>
