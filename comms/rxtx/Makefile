# Created by: Jean-Baptiste Quenot <jb.quenot@caraldi.com>
# $FreeBSD$

PORTNAME=	rxtx
PORTVERSION=	2.2p2
CATEGORIES=	comms java
MASTER_SITES=	http://rxtx.qbang.org/pub/rxtx/ \
		ftp://jarvi.dsl.frii.com/pub/rxtx/
PKGNAMESUFFIX=	-${JAVA_PORT:S/java\///}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/p/pre/}

MAINTAINER=	mirror176@cox.net
COMMENT=	Native interface to serial ports in Java

USE_ZIP=	yes
USE_GMAKE=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+
JAVA_OS=	native
GNU_CONFIGURE=	yes

USE_LDCONFIG=	yes
CONFIGURE_ENV=	JAVA_HOME=${JAVA_HOME}
PREFIX=		${JAVA_HOME}/jre
NO_MTREE=	yes

PLIST_SUB=	ARCH=${ARCH}

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/configure ${WRKSRC}/ltconfig

.include <bsd.port.mk>
