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
JDK_REVISION=	17
DL_JDK_VERSION=	${JDK_VERSION}_${JDK_REVISION}
ONLY_FOR_ARCHS=	i386 amd64
DOWNLOAD_URL?=	http://java.sun.com/javase/downloads/index.jsp
APP_HOME=	${PREFIX}/${PKGNAMEPREFIX}${PORTNAME}${JDK_VERSION}
PACKED_JARS=	lib/tools.jar jre/lib/rt.jar jre/lib/jsse.jar jre/lib/charsets.jar jre/lib/deploy.jar jre/lib/ext/localedata.jar jre/lib/plugin.jar jre/lib/javaws.jar
UNPACK_CMD=	${APP_HOME}/bin/unpack200

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}) && !defined(PACKAGE_BUILDING)
IGNORE?=You must manually fetch the J2SE SDK self-extracting file for the Linux platform (${DISTNAME}${EXTRACT_SUFX}) from ${DOWNLOAD_URL}, place it in ${DISTDIR} and then run make again
.endif

pre-everything::
	@${CAT} ${PKGMESSAGE}

do-extract:
	@${MKDIR} ${WRKDIR}
	@cd ${WRKDIR} \
	&& ${TAIL} -n +553 ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} > ${WRKDIR}/install.sfx \
	&& ${CHMOD} +x ${WRKDIR}/install.sfx \
	&& ${WRKDIR}/install.sfx > /dev/null

post-patch:
	${REINPLACE_CMD} -i.orig -e 's:^#!/bin/bash:#!/bin/sh:' ${WRKSRC}/bin/jcontrol
	@${FIND} ${WRKSRC} -name '*.orig' -print | ${XARGS} ${RM} -f

# XXX: This is missing a "${BRANDELF} -t Linux <executables>".

do-install:
	${MKDIR} ${APP_HOME}
	cd ${WRKSRC} && ${FIND} . -print \
	  | ${CPIO} -pdmu -R ${LIBOWN}:${LIBGRP} ${APP_HOME}
	for i in ${PACKED_JARS}; do \
	  if [ -f ${APP_HOME}/`dirname $$i`/`basename $$i .jar`.pack ]; then \
	    ${UNPACK_CMD} ${APP_HOME}/`dirname $$i`/`basename $$i .jar`.pack ${APP_HOME}/$$i; \
	    ${RM} -f ${APP_HOME}/`dirname $$i`/`basename $$i .jar`.pack; \
	  fi \
	done

post-install:
	${LOCALBASE}/bin/registervm "${APP_HOME}/bin/java # Linux-Sun-JDK${PORTVERSION}"
	${SED} -e "s:%%JRE_HOME%%:${APP_HOME}/jre:g" \
	  < ${FILESDIR}/pkg-install.in > ${PKGINSTALL}
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
