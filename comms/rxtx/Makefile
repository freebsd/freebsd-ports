# Created by: Jean-Baptiste Quenot <jb.quenot@caraldi.com>
# $FreeBSD$

PORTNAME=	rxtx
PORTVERSION=	2.2p2
PORTREVISION=	3
CATEGORIES=	comms java
MASTER_SITES=	http://rxtx.qbang.org/pub/rxtx/ \
		ftp://jarvi.dsl.frii.com/pub/rxtx/
PKGNAMESUFFIX=	-${JAVA_PORT:S/java\///}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/p/pre/}

MAINTAINER=	james@elstone.net
COMMENT=	Native interface to serial ports in Java

USES=		gmake libtool zip

USE_JAVA=	yes
JAVA_VERSION=	1.6+
JAVA_OS=	native
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	JAVA_HOME=${JAVA_HOME}
INSTALL_TARGET=	install-strip

USE_LDCONFIG=	yes

PLIST_SUB=	ARCH=${ARCH} JAVA_HOME=${JAVA_HOME:S,^${PREFIX}/,,}

.include <bsd.port.mk>
