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
DISTNAME=	${PORTNAME}-${JDK_VERSION:S/./_/g}-linux-i586

MAINTAINER=	znerd@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/bin/javavm:${PORTSDIR}/java/javavmwrapper
RUN_DEPENDS=	${LOCALBASE}/bin/javavm:${PORTSDIR}/java/javavmwrapper

WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION:R}
PLIST_SUB+=	T=${APP_HOME:S/^${PREFIX}\///}

NO_BUILD=	yes
USE_LINUX=	yes
JDK_VERSION=	1.2.2.013
ONLY_FOR_ARCHS=	i386

NO_CDROM=	"License does not allow distribution with fee"
RESTRICTED=	"Redistribution of repackaged binaries not permitted"

APP_HOME=	${PREFIX}/${PKGNAMEPREFIX}jdk1.2.2
DOWNLOAD_URL=	http://java.sun.com/Download5?config-file=${PORTNAME}-${JDK_VERSION:S/./_/g}.config&platform=linux-i586

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=You must manually fetch the Sun Java 2 Standard Edition SDK ${JDK_VERSION} for Linux archive (${DISTNAME}${EXTRACT_SUFX}) from ${DOWNLOAD_URL}, place it in ${DISTDIR} and then run make again.
.endif

post-patch:
	@${FIND} ${WRKSRC} -name '*.orig' -print | xargs ${RM} -f

do-install:
	@${ECHO_CMD} -n ">> Creating destination directory ${APP_HOME}..."
	@${MKDIR} ${APP_HOME}
	@${ECHO_CMD} " [ DONE ]"

	@${ECHO_CMD} -n ">> Copying files..."
	@${CP} -R ${WRKSRC}/* ${APP_HOME}
	@${ECHO_CMD} " [ DONE ]"

	@${ECHO_CMD} -n ">> Registering with javavm..."
	@${LOCALBASE}/bin/registervm "${APP_HOME}/bin/java # Sun-JDK${PORTVERSION}_${PORTREVISION}"
	@${ECHO_CMD} " [ DONE ]"

.include <bsd.port.post.mk>
