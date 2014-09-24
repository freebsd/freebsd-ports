# Created by: Jean-Baptiste Quenot <jb.quenot@caraldi.com>
# $FreeBSD$

PORTNAME=	rxtx
PORTVERSION=	2.2p2
PORTREVISION=	1
CATEGORIES=	comms java
MASTER_SITES=	http://rxtx.qbang.org/pub/rxtx/ \
		ftp://jarvi.dsl.frii.com/pub/rxtx/
PKGNAMESUFFIX=	-${JAVA_PORT:S/java\///}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/p/pre/}

MAINTAINER=	mirror176@cox.net
COMMENT=	Native interface to serial ports in Java

USES=		gmake zip libtool
USE_JAVA=	yes
JAVA_VERSION=	1.6+
JAVA_OS=	native
GNU_CONFIGURE=	yes

USE_LDCONFIG=	yes
CONFIGURE_ENV=	JAVA_HOME=${JAVA_HOME}
PREFIX=		${JAVA_HOME}/jre
NO_MTREE=	yes

PLIST_SUB=	ARCH=${ARCH}

.include <bsd.port.mk>
