# Created by: Jean-Baptiste Quenot <jb.quenot@caraldi.com>
# $FreeBSD$

PORTNAME=	rxtx
PORTVERSION=	2.2p2
PORTREVISION=	4
CATEGORIES=	comms java
MASTER_SITES=	http://rxtx.qbang.org/pub/rxtx/
PKGNAMESUFFIX=	-${JAVA_PORT:S/java\///}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/p/pre/}

MAINTAINER=	james@elstone.net
COMMENT=	Native interface to serial ports in Java

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_armv6=		fails to link: librxtxParallel.so: No such file or directory
BROKEN_armv7=		fails to link: librxtxParallel.so: No such file or directory

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
