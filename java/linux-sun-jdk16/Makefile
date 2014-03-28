# $FreeBSD$

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

OPTIONS_DEFINE=	DEMO
DEMO_DESC=	Install demos and samples
OPTIONS_DEFAULT=DEMO

NO_CDROM=	License does not allow distribution with fee
RESTRICTED=	Redistribution of repackaged binaries not permitted
PKGNAMESUFFIX=	16

WRKSRC=		${WRKDIR}/jdk${DL_JDK_VERSION}
PLIST_SUB+=	T=${APP_HOME:S/^${PREFIX}\///} PORTVERSION=${PORTVERSION}

NO_BUILD=	yes
USES=	shebangfix
USE_LINUX=	yes
USE_LINUX_APPS=	xorglibs
JDK_VERSION=	1.6.0
JDK_REVISION=	45
DL_JDK_VERSION=	${JDK_VERSION}_${JDK_REVISION}
ONLY_FOR_ARCHS=	i386 amd64
DOWNLOAD_URL?=	http://www.oracle.com/technetwork/java/javase/downloads/index.html
APP_HOME=	${PREFIX}/${PKGNAMEPREFIX}${PORTNAME}${JDK_VERSION}
PACKED_JARS=	jre/lib/charsets jre/lib/deploy jre/lib/ext/localedata jre/lib/javaws jre/lib/jsse jre/lib/plugin jre/lib/rt lib/tools
UNPACK_CMD=	${WRKSRC}/bin/unpack200

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE?=You must manually fetch the J2SE SDK self-extracting file for the Linux platform (${DISTNAME}${EXTRACT_SUFX}) from ${DOWNLOAD_URL}, place it in ${DISTDIR} and then run make again
.endif

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEMO}
DEMO_UPDATE_VERSION=	${JDK_REVISION}
.if ${DEMO_UPDATE_VERSION} != ${JDK_REVISION}
DEMO_DISTNAME= jdk-6u${DEMO_UPDATE_VERSION}-linux-i586-demos
DEMO_WRKSRC=	${WRKDIR}/jdk${JDK_VERSION}_${DEMO_UPDATE_VERSION}
.else
DEMO_DISTNAME=	${DISTNAME}-demos
DEMO_WRKSRC=	${WRKSRC}
.endif
.if !exists(${DISTDIR}/${DEMO_DISTNAME}.tar.gz)
IGNORE?=You must manually fetch the J2SE demos and samples for the Linux platform (${DEMO_DISTNAME}.tar.gz) from ${DOWNLOAD_URL}, place it in ${DISTDIR} and then run make again
.endif
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DEMO_DISTNAME}.tar.gz
PLIST_SUB+=	DEMO=""
.else
PLIST_SUB+=	DEMO="@comment "
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
.if ${PORT_OPTIONS:MDEMO}
	@${TAR} -x -f ${DISTDIR}/${DEMO_DISTNAME}.tar.gz -C ${WRKDIR}
.endif

.if ${PORT_OPTIONS:MDEMO} && ${DEMO_WRKSRC} != ${WRKSRC}
post-extract:
	@${MV} ${DEMO_WRKSRC}/demo ${WRKSRC}/
	@${MV} ${DEMO_WRKSRC}/sample ${WRKSRC}/
.endif

post-patch:
	${REINPLACE_CMD} -i.orig -e 's:^#!/bin/bash:#!/bin/sh:' ${WRKSRC}/bin/jcontrol
	@${FIND} ${WRKSRC} -name '*.orig' -delete
	@(cd ${WRKSRC}/include; ${LN} -s linux freebsd)

# XXX: This is missing a "${BRANDELF} -t Linux <executables>".

do-install:
	${MKDIR} ${STAGEDIR}${APP_HOME}
	cd ${WRKSRC} && ${FIND} . -print \
	  | ${CPIO} -pdmu -R ${LIBOWN}:${LIBGRP} ${STAGEDIR}${APP_HOME}

post-install:
	 ${MKDIR} ${STAGEDIR}${APP_HOME}/jre/.systemPrefs
	 ${TOUCH} ${STAGEDIR}${APP_HOME}/jre/.systemPrefs/.system.lock
	 ${TOUCH} ${STAGEDIR}${APP_HOME}/jre/.systemPrefs/.systemRootModFile
	 ${CHMOD} 644 ${STAGEDIR}${APP_HOME}/jre/.systemPrefs/.system.lock
	 ${CHMOD} 644 ${STAGEDIR}${APP_HOME}/jre/.systemPrefs/.systemRootModFile

.include <bsd.port.post.mk>
