# New ports collection makefile for:	Sun Linux JDK 1.3.x
# Date created:				06 December 2000
# Whom:					Kevin Lo <kevlo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jdk
PORTVERSION=	${JDK_VERSION}.${JDK_REVISION}
CATEGORIES=	java devel
MASTER_SITES=	#
PKGNAMEPREFIX=	linux-sun-
DISTNAME=	j2sdk-${JDK_VERSION:S/./_/g}_${JDK_REVISION}-linux-i586
EXTRACT_SUFX=	.bin

MAINTAINER=	java@FreeBSD.org
COMMENT=	Sun Java Development Kit 1.3 for Linux

EXTRACT_DEPENDS=${LINUX_BASE_PORT}
RUN_DEPENDS=	javavm:${PORTSDIR}/java/javavmwrapper

NO_CDROM=	"License does not allow distribution with fee"
RESTRICTED=	"Redistribution of repackaged binaries not permitted"
LATEST_LINK=	linux-sun-jdk13

WRKSRC=		${WRKDIR}/${PORTNAME}${JDK_VERSION}_${JDK_REVISION}
PLIST_SUB+=	T=${TARGET_DIR:S/^${PREFIX}\///} \
		JDK_VERSION=${JDK_VERSION}

NO_BUILD=	yes
USE_LINUX=	yes
USE_XLIB=	yes
JDK_VERSION=	1.3.1
JDK_REVISION=	16
ONLY_FOR_ARCHS=	i386 amd64
TARGET_DIR?=	${PREFIX}/${PKGBASE}${JDK_VERSION}
DOWNLOAD_URL?=	http://javashoplm.sun.com/ECom/docs/Welcome.jsp?StoreId=22&PartDetailId=j2sdk-${JDK_VERSION}_${JDK_REVISION}-oth-JPR&SiteId=JSC&TransactionId=noreg

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}) && !defined(PACKAGE_BUILDING)
IGNORE=You must manually fetch the J2SE SDK self-extracting file for the Linux Platform (${DISTNAME}${EXTRACT_SUFX}) from ${DOWNLOAD_URL}, place it in ${DISTDIR} and then run make again
.endif

pre-extract:
	@if [ -z "`kldstat -v | ${GREP} -E 'linux(aout|elf)'`" ]; then \
		${ECHO} 'Linux mode is not enabled.\
			Loading Linux kernel module...' | fmt; \
		linux || { \
		${ECHO} 'The Linux kernel module could not be loaded.\
			Please manually load the module and retry.\
			See "man linux" for details.' | fmt; \
		${FALSE}; \
		};\
	fi

do-extract:
	@${MKDIR} ${WRKDIR}
	@cd ${WRKDIR} \
	&& ${TAIL} +292 ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} > ${WRKDIR}/install.sfx \
	&& ${CHMOD} +x ${WRKDIR}/install.sfx \
	&& ${WRKDIR}/install.sfx > /dev/null

post-patch:
	@${FIND} ${WRKSRC} -name '*.orig' -print | ${XARGS} ${RM} -f

# XXX: This is missing a "${BRANDELF} -t Linux <executables>".

do-install:
	${MKDIR} ${PREFIX}/${PKGNAMEPREFIX}jdk${JDK_VERSION}
	cd ${WRKSRC} && ${FIND} . -print \
	  | ${CPIO} -pdmu -R ${LIBOWN}:${LIBGRP} ${PREFIX}/${PKGNAMEPREFIX}jdk${JDK_VERSION}
	${LOCALBASE}/bin/registervm "${PREFIX}/${PKGNAMEPREFIX}jdk${JDK_VERSION}/bin/java # Linux-Sun-JDK${JDK_VERSION}"

.include <bsd.port.post.mk>
