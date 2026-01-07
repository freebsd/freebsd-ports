PORTNAME=	rxtx
PORTVERSION=	2.2p2
PORTREVISION=	4
CATEGORIES=	comms java
MASTER_SITES=	http://rxtx.qbang.org/pub/rxtx/
PKGNAMESUFFIX=	-${JAVA_PORT:S/java\///}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/p/pre/}

MAINTAINER=	james@elstone.net
COMMENT=	Native interface to serial ports in Java
WWW=		http://rxtx.qbang.org

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake java libtool zip
# jdk11: javah: not found
# jdk17+: error: invalid use of a restricted identifier 'yield'
JAVA_VERSION=	8

JAVA_OS=	native
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	JAVA_HOME=${JAVA_HOME}
INSTALL_TARGET=	install-strip

USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

PLIST_SUB=	JAVA_HOME=${JAVA_HOME:S,^${PREFIX}/,,}
PLIST_SUB+=	ARCH=${ARCH:C/armv.*/arm/:S/powerpc/ppc/}

.include <bsd.port.mk>
