# New ports collection makefile for:	Sun Linux JDK 1.2.x
# Date created:				27 April 2002
# Whom:					Ernst de Haan <znerd@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jdk
PORTVERSION=	${JDK_VERSION}
PORTREVISION=	1
CATEGORIES=	java
MASTER_SITES=	#
PKGNAMEPREFIX=	linux-sun-
DISTNAME=	${PORTNAME}-${JDK_VERSION:S/./_/g}-linux-i586

MAINTAINER=	java@FreeBSD.org
COMMENT=	Sun Java Development Kit 1.2 for Linux

EXTRACT_DEPENDS=	${LOCALBASE}/bin/javavm:${PORTSDIR}/java/javavmwrapper
BUILD_DEPENDS=	${LOCALBASE}/bin/javavm:${PORTSDIR}/java/javavmwrapper
RUN_DEPENDS=	${LOCALBASE}/bin/javavm:${PORTSDIR}/java/javavmwrapper

WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION:R}
PLIST_SUB+=	T=${APP_HOME:S/^${PREFIX}\///}
LATEST_LINK=	linux-sun-jdk12

NO_BUILD=	yes
USE_LINUX=	yes
JDK_VERSION=	1.2.2.017
ONLY_FOR_ARCHS=	i386 amd64

NO_CDROM=	"License does not allow distribution with fee"
RESTRICTED=	"Redistribution of repackaged binaries not permitted"

APP_HOME=	${PREFIX}/${PKGNAMEPREFIX}jdk1.2.2
SUN_BUNDLE_ID?=	9153
DOWNLOAD_URL?=	http://java.sun.com/webapps/download/Display?BundleId=${SUN_BUNDLE_ID}

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}) && !defined(PACKAGE_BUILDING)
IGNORE=You must manually fetch the Sun Java 2 Standard Edition SDK ${JDK_VERSION} for Linux archive (${DISTNAME}${EXTRACT_SUFX}) from ${DOWNLOAD_URL}, place it in ${DISTDIR} and then run make again.
.endif

post-patch:
	@${FIND} ${WRKSRC} -name '*.orig' -print | ${XARGS} ${RM} -f

do-install:
	@${ECHO_CMD} -n ">> Creating destination directory ${APP_HOME}..."
	@${MKDIR} ${APP_HOME}
	@${ECHO_CMD} " [ DONE ]"

	@${ECHO_CMD} -n ">> Copying files..."
	@${CP} -R ${WRKSRC}/* ${APP_HOME}
	@${INSTALL_DATA} ${FILESDIR}/cacerts ${APP_HOME}/jre/lib/security/cacerts
	@${CHOWN} -h -R ${LIBOWN}:${LIBGRP} ${APP_HOME}
	@${ECHO_CMD} " [ DONE ]"

	@${ECHO_CMD} -n ">> Registering with javavm..."
	@${LOCALBASE}/bin/registervm "${APP_HOME}/bin/java # Linux-Sun-JDK${PORTVERSION}_${PORTREVISION}"
	@${ECHO_CMD} " [ DONE ]"

.include <bsd.port.post.mk>
