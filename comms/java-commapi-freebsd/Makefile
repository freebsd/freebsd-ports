# Created by: Ari Suutari <ari.suutari@syncrontech.com>
# $FreeBSD$

PORTNAME=	java-commapi-freebsd
PORTVERSION=	0.9
CATEGORIES=	comms java
MASTER_SITES=	http://www.syncrontech.org/freebsd/
DISTNAME=	freebsd-commapi-${PORTVERSION}

MAINTAINER=	ari.suutari@syncrontech.com
COMMENT=	Java Communication API for FreeBSD

BUILD_DEPENDS=	${JDKDIR}/jre/lib/ext/comm.jar:comms/java-commapi
RUN_DEPENDS=	${JDKDIR}/jre/lib/ext/comm.jar:comms/java-commapi

MAKE_JOBS_UNSAFE=	yes

USE_JAVA=	yes
JAVA_VERSION=	1.6+
JAVA_OS=	native
JAVA_BUILD=	yes

JDKDIR=		${JAVA_HOME}

MAKE_ENV=	JAVA_HOME=${JDKDIR}

PLIST_SUB+=	JAVA_HOME=${JAVA_HOME:S/${PREFIX}\///}
PLIST_FILES=	%%JAVA_HOME%%/jre/lib/ext/CommDriver.jar \
		%%JAVA_HOME%%/jre/lib/${MACHINE_ARCH}/libSerial.so \
		%%JAVA_HOME%%/jre/lib/${MACHINE_ARCH}/libParallel.so \
		%%JAVA_HOME%%/jre/lib/javax.comm.properties

.include <bsd.port.mk>
