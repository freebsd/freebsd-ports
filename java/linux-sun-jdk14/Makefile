# New ports collection makefile for:	Sun Linux JDK 1.4.x
# Date created:				25 May 2001
# Whom:					Ernst de Haan <znerd@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jdk
PORTVERSION=	${INSTALL_JDK_VERSION}
CATEGORIES=	java devel
MASTER_SITES=	#
PKGNAMEPREFIX=	linux-sun-
DISTNAME=	j2sdk-${DL_JDK_VERSION:S/./_/g}-linux-i586
EXTRACT_SUFX=	.bin

MAINTAINER=	znerd@FreeBSD.org
COMMENT=	Sun Java Development Kit 1.4 for Linux

EXTRACT_DEPENDS=	${LINUXBASE}/lib/libc.so.6:${PORTSDIR}/emulators/linux_base
BUILD_DEPENDS=  ${LINUXBASE}/lib/libc.so.6:${PORTSDIR}/emulators/linux_base
RUN_DEPENDS=	javavm:${PORTSDIR}/java/javavmwrapper

NO_CDROM=	"License does not allow distribution with fee"
RESTRICTED=	"Redistribution of repackaged binaries not permitted"

WRKSRC=		${WRKDIR}/j2sdk${DL_JDK_VERSION}
PLIST_SUB+=	T=${APP_HOME:S/^${PREFIX}\///} PORTVERSION=${PORTVERSION}
PKGINSTALL=	${WRKDIR}/pkg-install

NO_BUILD=	yes
USE_LINUX=	yes
JDK_VERSION=	1.4.2
JDK_REVISION=	02
DL_JDK_VERSION=	${JDK_VERSION}_${JDK_REVISION}
INSTALL_JDK_VERSION=	${DL_JDK_VERSION:S/_/./g}
ONLY_FOR_ARCHS=	i386
SUN_BUNDLE_ID=	9158
DOWNLOAD_URL?=	http://java.sun.com/webapps/download/Display?BundleId=${SUN_BUNDLE_ID}&Referer=http://java.sun.com/j2se/1.4.2/download.html
PORTTITLE=	Java 2 Development Kit ${DL_JDK_VERSION} for Linux
APP_HOME=	${PREFIX}/${PKGNAMEPREFIX}${PORTNAME}${JDK_VERSION}
CPIO?=		/usr/bin/cpio
PACKED_JARS=	lib/tools.jar jre/lib/rt.jar jre/lib/jsse.jar jre/lib/charsets.jar jre/lib/ext/localedata.jar jre/lib/plugin.jar jre/javaws/javaws.jar
UNPACK_CMD=	${APP_HOME}/lib/unpack

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}) && !defined(PACKAGE_BUILDING)
IGNORE=You must manually fetch the J2SE v1.4 SDK Linux GNUZIP Tar shell script (${DISTNAME}${EXTRACT_SUFX}) from ${DOWNLOAD_URL}, place it in ${DISTDIR} and then run make again
.endif

pre-everything::
	@${CAT} ${PKGMESSAGE}

do-extract:
	@${MKDIR} ${WRKDIR}
	@cd ${WRKDIR} \
	&& ${TAIL} -n 136144 ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} > ${WRKDIR}/install.sfx \
	&& ${CHMOD} +x ${WRKDIR}/install.sfx \
	&& ${WRKDIR}/install.sfx > /dev/null

post-patch:
	@${FIND} ${WRKSRC} -name '*.orig' -print | ${XARGS} ${RM} -f

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
