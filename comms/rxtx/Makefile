# New ports collection makefile for:	rxtx
# Whom:					Jean-Baptiste Quenot <jb.quenot@caraldi.com>
# Date Created:				2004-04-10 00:15:35
#
# $FreeBSD$
#

PORTNAME=	rxtx
PORTVERSION=	2.1.7r2
CATEGORIES=	comms java
MASTER_SITES=	ftp://jarvi.dsl.frii.com/pub/rxtx/
PKGNAMESUFFIX=	-${JAVA_PORT:S/java\///}
DISTNAME=	${PORTNAME}-${PORTVERSION:C/\.([^\.]*)$/-\1/:S/p/pre/}

MAINTAINER=	jb.quenot@caraldi.com
COMMENT=	Native interface to serial ports in Java

USE_ZIP=	yes
USE_GMAKE=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.2+
JAVA_OS=	native
GNU_CONFIGURE=	yes

INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	JAVA_HOME=${JAVA_HOME}
PREFIX=		${JAVA_HOME}/jre
NO_MTREE=	yes

.include <bsd.port.mk>
