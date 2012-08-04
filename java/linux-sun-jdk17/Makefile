# New ports collection makefile for:	Sun Linux JDK 1.7.x
# Date created:				30 January 2012
# Whom:					Greg Lewis <glewis@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jdk
PORTVERSION=	${JDK_VERSION}.${JDK_UPDATE_VERSION}
CATEGORIES=	java devel
MASTER_SITES=	#
PKGNAMEPREFIX=	linux-sun-
DISTNAME=	jdk-7u${JDK_UPDATE_VERSION}-linux-i586

MAINTAINER=	java@FreeBSD.org
COMMENT=	Oracle Java 7 Development Kit for Linux

RUN_DEPENDS=	javavm:${PORTSDIR}/java/javavmwrapper

OPTIONS=	DEMO "Install demos and samples" off

NO_CDROM=	License does not allow distribution with fee
RESTRICTED=	Redistribution of repackaged binaries not permitted
LATEST_LINK=	linux-sun-jdk17

WRKSRC=		${WRKDIR}/jdk${DL_JDK_VERSION}
PLIST_SUB+=	T=${APP_HOME:S/^${PREFIX}\///} PORTVERSION=${PORTVERSION}
PKGINSTALL=	${WRKDIR}/pkg-install

NO_BUILD=	yes
USE_LINUX=	yes
USE_LINUX_APPS=	xorglibs
ONLY_FOR_ARCHS=	i386 amd64

JDK_VERSION=		7
JDK_INTERNAL_VERSION=	1.7.0
JDK_UPDATE_VERSION=	5
DL_JDK_VERSION=		${JDK_INTERNAL_VERSION}_0${JDK_UPDATE_VERSION}
DOWNLOAD_URL=		http://www.oracle.com/technetwork/java/javase/downloads/index.html

APP_HOME=	${PREFIX}/${PKGNAMEPREFIX}${PORTNAME}${JDK_INTERNAL_VERSION}
SCRIPT_FILES=	bin/jcontrol jre/bin/jcontrol
BIN_DIRS=	bin jre/bin

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}) && !defined(PACKAGE_BUILDING)
IGNORE?=You must manually fetch the J2SE SDK download for the Linux platform (${DISTNAME}${EXTRACT_SUFX}) from ${DOWNLOAD_URL}, place it in ${DISTDIR} and then run make again
.endif

.if defined(WITH_DEMO)
.if !exists(${DISTDIR}/${DISTNAME}-demos${EXTRACT_SUFX}) && !defined(PACKAGE_BUILDING)
IGNORE?=You must manually fetch the J2SE demos and samples for the Linux platform (${DISTNAME}-demos${EXTRACT_SUFX}) from ${DOWNLOAD_URL}, place it in ${DISTDIR} and then run make again
.endif
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}-demos${EXTRACT_SUFX}
PLIST_SUB+=	DEMO=""
.else
PLIST_SUB+=	DEMO="@comment "
.endif

pre-everything::
	@${CAT} ${PKGMESSAGE}

post-patch:
.for script in ${SCRIPT_FILES}
	@${REINPLACE_CMD} -i.orig -e 's:^#!/bin/bash:#!/bin/sh:' ${WRKSRC}/${script}
.endfor
	@${FIND} ${WRKSRC} -name '*.orig' -delete

do-install:
	@${MKDIR} ${APP_HOME}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${APP_HOME}
.for dir in ${BIN_DIRS}
	@${CHOWN} -R ${BINOWN}:${BINGRP} "${APP_HOME}/${dir}"
	@${FIND} ${APP_HOME}/${dir} -type f -exec "${CHMOD}" ${BINMODE} "{}" \;
.endfor

post-install:
	${LOCALBASE}/bin/registervm "${APP_HOME}/bin/java # Linux-Sun-JDK${PORTVERSION}"
	@${SED} -e "s:%%JRE_HOME%%:${APP_HOME}/jre:g" \
	  < ${FILESDIR}/pkg-install.in > ${PKGINSTALL}
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
