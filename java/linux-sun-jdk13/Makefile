# New ports collection makefile for:	linux jdk 1.3.0
# Date created:				06 December 2000
# Whom:					Kevin Lo <kevlo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jdk
PORTVERSION=	${JDK_VERSION}.${JDK_REVISION}
PORTREVISION=	1
CATEGORIES=	java devel
MASTER_SITES=	#
PKGNAMEPREFIX=	linux-sun-
DISTNAME=	j2sdk-${JDK_VERSION:S/./_/g}_${JDK_REVISION}-linux-i586
EXTRACT_SUFX=	.bin

MAINTAINER=	znerd@FreeBSD.org

BUILD_DEPENDS=	${LINUXBASE}/lib/libc.so.6:${PORTSDIR}/emulators/linux_base
RUN_DEPENDS=	javavm:${PORTSDIR}/java/javavmwrapper

NO_CDROM=	"License does not allow distribution with fee"
RESTRICTED=	"Redistribution of repackaged binaries not permitted"

WRKSRC=		${WRKDIR}/${PORTNAME}${JDK_VERSION}_${JDK_REVISION}
PLIST_SUB+=	T=${TARGET_DIR:S/^${PREFIX}\///}

NO_BUILD=	yes
USE_LINUX=	yes
JDK_VERSION=	1.3.1
JDK_REVISION=	06
ONLY_FOR_ARCHS=	i386
TARGET_DIR?=	${PREFIX}/${PKGBASE}${JDK_VERSION}
DOWNLOAD_URL?=	http://java.sun.com/webapps/download/Display?BundleId=7163

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=	You must manually fetch the Java 2 Development Kit ${PORTVERSION}\
	archive (${DISTNAME}${EXTRACT_SUFX}) from ${DOWNLOAD_URL},\
	download the "Linux GNUZIP Tar shell script" into ${DISTDIR} and\
	then run make again
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
	&& ${TAIL} +291 ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} > ${WRKDIR}/install.sfx \
	&& ${CHMOD} +x ${WRKDIR}/install.sfx \
	&& ${WRKDIR}/install.sfx > /dev/null

post-patch:
	@find ${WRKSRC} -name '*.orig' -print | xargs ${RM} -f

do-install:
	@${MKDIR} ${PREFIX}/${PKGNAMEPREFIX}jdk${JDK_VERSION}
	@${TAR} -C ${WRKSRC} -cf- . | ${TAR} -C ${PREFIX}/${PKGNAMEPREFIX}jdk${JDK_VERSION} --unlink -xpf-
	@${LOCALBASE}/bin/registervm "${PREFIX}/${PKGNAMEPREFIX}jdk${JDK_VERSION}/bin/java # Linux-JDK${JDK_VERSION}"

.include <bsd.port.post.mk>
