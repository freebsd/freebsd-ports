# $FreeBSD$

PORTNAME=	jre
PORTVERSION=	${DL_JRE_VERSION:S/_/./g}
CATEGORIES=	java
MASTER_SITES=	#
PKGNAMEPREFIX=	linux-sun-
DISTNAME=	jre-6u${JRE_REVISION:S/^0//}-linux-i586
EXTRACT_SUFX=	.bin

MAINTAINER=	java@FreeBSD.org
COMMENT=	Sun Java Runtime Environment 1.6 for Linux

EXTRACT_DEPENDS=${LINUX_BASE_PORT}
RUN_DEPENDS=	javavm:${PORTSDIR}/java/javavmwrapper

NO_CDROM=	License does not allow distribution with fee
RESTRICTED=	Redistribution of repackaged binaries not permitted
PKGNAMESUFFIX=	16

WRKSRC=		${WRKDIR}/jre${DL_JRE_VERSION}
PLIST_SUB+=	T=${APP_HOME:S/^${PREFIX}\///} PORTVERSION=${PORTVERSION}

NO_BUILD=	yes
USE_LINUX=	yes
USE_LINUX_APPS=	xorglibs
JRE_VERSION=	1.6.0
JRE_REVISION=	45
DL_JRE_VERSION=	${JRE_VERSION}_${JRE_REVISION}
ONLY_FOR_ARCHS=	i386 amd64
DOWNLOAD_URL?=	http://www.oracle.com/technetwork/java/javase/downloads/index.html
APP_HOME=	${PREFIX}/${PKGNAMEPREFIX}${PORTNAME}${JRE_VERSION}
PACKED_JARS=	lib/charsets lib/deploy lib/ext/localedata lib/javaws lib/jsse lib/plugin lib/rt
UNPACK_CMD=	${WRKSRC}/bin/unpack200

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE?=You must manually fetch the JRE self-extracting file for the Linux platform (${DISTNAME}${EXTRACT_SUFX}) from ${DOWNLOAD_URL}, place it in ${DISTDIR} and then run make again
.endif

pre-everything::
	@${CAT} ${PKGMESSAGE}

do-extract:
	@${MKDIR} ${WRKDIR}
	@cd ${WRKDIR} \
	&& ${TAIL} -n +146 ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} > ${WRKDIR}/install.sfx \
	&& ${CHMOD} +x ${WRKDIR}/install.sfx \
	&& ${WRKDIR}/install.sfx -o > /dev/null
.for i in ${PACKED_JARS}
	@${UNPACK_CMD} -r ${WRKSRC}/${i}.pack ${WRKSRC}/${i}.jar
.endfor

post-patch:
	${REINPLACE_CMD} -i.orig -e 's:^#!/bin/bash:#!/bin/sh:' ${WRKSRC}/bin/jcontrol
	@${FIND} ${WRKSRC} -name '*.orig' -delete

# XXX: This is missing a "${BRANDELF} -t Linux <executables>".

do-install:
	${MKDIR} ${STAGEDIR}${APP_HOME}
	cd ${WRKSRC} && ${FIND} . -print \
	  | ${CPIO} -pdmu -R ${LIBOWN}:${LIBGRP} ${STAGEDIR}${APP_HOME}

post-install:
	${MKDIR} ${STAGEDIR}${APP_HOME}/.systemPrefs
	${TOUCH} ${STAGEDIR}${APP_HOME}/.systemPrefs/.system.lock
	${TOUCH} ${STAGEDIR}${APP_HOME}/.systemPrefs/.systemRootModFile
	${CHMOD} 644 ${STAGEDIR}${APP_HOME}/.systemPrefs/.system.lock
	${CHMOD} 644 ${STAGEDIR}${APP_HOME}/.systemPrefs/.systemRootModFile

.include <bsd.port.post.mk>
