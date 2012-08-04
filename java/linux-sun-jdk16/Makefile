# New ports collection makefile for:	Sun Linux JDK 1.6.x
# Date created:				3 January 2007
# Whom:					Jung-uk Kim <jkim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jdk
PORTVERSION=	${DL_JDK_VERSION:S/_/./g}
CATEGORIES=	java devel
MASTER_SITES=	#
PKGNAMEPREFIX=	linux-sun-
DISTNAME=	jdk-6u${JDK_REVISION:S/^0//}-linux-i586
EXTRACT_SUFX=	.bin

MAINTAINER=	java@FreeBSD.org
COMMENT=	Sun Java Development Kit 1.6 for Linux

EXTRACT_DEPENDS=${LINUX_BASE_PORT}
RUN_DEPENDS=	javavm:${PORTSDIR}/java/javavmwrapper

OPTIONS=	DEMO "Install demos and samples" on

NO_CDROM=	License does not allow distribution with fee
RESTRICTED=	Redistribution of repackaged binaries not permitted
LATEST_LINK=	linux-sun-jdk16

WRKSRC=		${WRKDIR}/jdk${DL_JDK_VERSION}
PLIST_SUB+=	T=${APP_HOME:S/^${PREFIX}\///} PORTVERSION=${PORTVERSION}
PKGINSTALL=	${WRKDIR}/pkg-install

NO_BUILD=	yes
USE_LINUX=	yes
USE_LINUX_APPS=	xorglibs
JDK_VERSION=	1.6.0
JDK_REVISION=	33
DL_JDK_VERSION=	${JDK_VERSION}_${JDK_REVISION}
ONLY_FOR_ARCHS=	i386 amd64
DOWNLOAD_URL?=	http://www.oracle.com/technetwork/java/javase/downloads/index.html
APP_HOME=	${PREFIX}/${PKGNAMEPREFIX}${PORTNAME}${JDK_VERSION}
PACKED_JARS=	jre/lib/charsets jre/lib/deploy jre/lib/ext/localedata jre/lib/javaws jre/lib/jsse jre/lib/plugin jre/lib/rt lib/tools
UNPACK_CMD=	${WRKSRC}/bin/unpack200

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}) && !defined(PACKAGE_BUILDING)
IGNORE?=You must manually fetch the J2SE SDK self-extracting file for the Linux platform (${DISTNAME}${EXTRACT_SUFX}) from ${DOWNLOAD_URL}, place it in ${DISTDIR} and then run make again
.endif

.if defined(WITH_DEMO)
.if !exists(${DISTDIR}/${DISTNAME}-demos.tar.gz) && !defined(PACKAGE_BUILDING)
IGNORE?=You must manually fetch the J2SE demos and samples for the Linux platform (${DISTNAME}-demos.tar.gz) from ${DOWNLOAD_URL}, place it in ${DISTDIR} and then run make again
.endif
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}-demos.tar.gz
PLIST_SUB+=	DEMO=""
.else
PLIST_SUB+=	DEMO="@comment "
.endif

pre-everything::
	@${CAT} ${PKGMESSAGE}

do-extract:
	@${MKDIR} ${WRKDIR}
	@cd ${WRKDIR} \
	&& ${TAIL} -n +189 ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} > ${WRKDIR}/install.sfx \
	&& ${CHMOD} +x ${WRKDIR}/install.sfx \
	&& ${WRKDIR}/install.sfx -o > /dev/null
.for i in ${PACKED_JARS}
	@${UNPACK_CMD} -r ${WRKSRC}/${i}.pack ${WRKSRC}/${i}.jar
.endfor
.if defined(WITH_DEMO)
	@${TAR} -x -f ${DISTDIR}/${DISTNAME}-demos.tar.gz -C ${WRKDIR}
.endif

post-patch:
	${REINPLACE_CMD} -i.orig -e 's:^#!/bin/bash:#!/bin/sh:' ${WRKSRC}/bin/jcontrol
	@${FIND} ${WRKSRC} -name '*.orig' -delete

# XXX: This is missing a "${BRANDELF} -t Linux <executables>".

do-install:
	${MKDIR} ${APP_HOME}
	cd ${WRKSRC} && ${FIND} . -print \
	  | ${CPIO} -pdmu -R ${LIBOWN}:${LIBGRP} ${APP_HOME}

post-install:
	${LOCALBASE}/bin/registervm "${APP_HOME}/bin/java # Linux-Sun-JDK${PORTVERSION}"
	${SED} -e "s:%%JRE_HOME%%:${APP_HOME}/jre:g" \
	  < ${FILESDIR}/pkg-install.in > ${PKGINSTALL}
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
