# New ports collection makefile for:	linux-sun-jdk
# Date created:				27 April 2002
# Whom:					Ernst de Haan <znerd@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jdk
PORTVERSION=	${JDK_VERSION}
CATEGORIES=	java
MASTER_SITES=	#
PKGNAMEPREFIX=	linux-sun-
DISTNAME=	${PORTNAME}-${JDK_VERSION:S/./_/g}-linux-${ARCH}

MAINTAINER=	znerd@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/bin/javavm:${PORTSDIR}/java/javavmwrapper
RUN_DEPENDS=	${LOCALBASE}/bin/javavm:${PORTSDIR}/java/javavmwrapper

WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION:R}
PLIST_SUB+=	T=${APP_HOME:S/^${PREFIX}\///}

NO_BUILD=	yes
USE_LINUX=	yes
JDK_VERSION=	1.2.2.012
ONLY_FOR_ARCHS=	i386

NO_CDROM=	"License doesn\'t allow distribution with fee"
RESTRICTED=	"Redistribution of repackaged binaries not permitted"

.if defined(BATCH) || defined(PACKAGE_BUILDING)
IGNORE=	"You can not legally distribute binaries"
.endif

APP_HOME=	${PREFIX}/${PKGNAME}
DOWNLOAD_URL=	http://java.sun.com/Download5?config-file=${PORTNAME}-${JDK_VERSION:S/./_/g}.config&platform=linux-${ARCH}

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=You must manually fetch the Sun Java 2 Standard Edition SDK ${JDK_VERSION} for Linux archive (${DISTNAME}${EXTRACT_SUFX}) from ${DOWNLOAD_URL}, place it in ${DISTDIR} and then run make again.
.endif

do-install:
	${MKDIR} ${APP_HOME}
	${CP} -R ${WRKSRC}/* ${APP_HOME}
	${LOCALBASE}/bin/registervm "${APP_HOME}/bin/java # Sun-JDK${PORTVERSION}_${PORTREVISION}"

.include <bsd.port.post.mk>
