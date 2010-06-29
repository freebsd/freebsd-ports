# Ports collection makefile for:	jiic
# Date created:			28 Jun 2010
# Whom:				Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jiic
PORTVERSION=	20100629
CATEGORIES=	devel multimedia java
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	ale

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A streaming-based Java implementation of ISO 9660

BUILD_DEPENDS=	${JAVALIBDIR}/sabre.jar:${PORTSDIR}/devel/sabre
RUN_DEPENDS=	${JAVALIBDIR}/sabre.jar:${PORTSDIR}/devel/sabre

LICENSE=	LGPL21

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.5+
USE_ANT=	yes
MAKE_ENV=	ANT_INCLUDE_SHARED_JARS=YES
ALL_TARGET=	jar

PLIST_FILES=	%%JAVAJARDIR%%/iso9660.jar

post-extract:
	@${CP} ${FILESDIR}/build.xml ${WRKSRC}

do-install:
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/iso9660.jar..."
	@${INSTALL_DATA} ${WRKSRC}/dist/iso9660.jar ${JAVAJARDIR}/
	@${ECHO_MSG} " [ DONE ]"

.include <bsd.port.mk>
