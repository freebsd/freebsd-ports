# New ports collection makefile for:	Sun Linux JDK 1.4.x
# Date created:				25 May 2001
# Whom:					Ernst de Haan <ernst@jollem.com>
#
# $FreeBSD$
#

PORTNAME=	jdk
PORTVERSION=	${INSTALL_JDK_VERSION}
CATEGORIES=	java devel
MASTER_SITES=	#
PKGNAMEPREFIX=	linux-
DISTNAME=	j2sdk-${DL_JDK_VERSION:S/./_/g}-linux-i386
EXTRACT_SUFX=	.bin

MAINTAINER=	ernst@jollem.com

BUILD_DEPENDS=  ${LINUXBASE}/lib/libc.so.6:${PORTSDIR}/emulators/linux_base
RUN_DEPENDS=	javavm:${PORTSDIR}/java/javavmwrapper

NO_CDROM=	"License doesn\'t allow distribution with fee"
RESTRICTED=	"Redistribution of repackaged binaries not permitted"

.if defined(BATCH) || defined(PACKAGE_BUILDING)
IGNORE="You can not legally distribute binaries"
.endif

EXTRACT_CMD=		# empty
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	# empty

WRKSRC=		${WRKDIR}/j2sdk1.4.0
PLIST_SUB+=	T=${TARGET_DIR:S/^${PREFIX}\///}

NO_BUILD=	yes
USE_LINUX=	yes
DL_JDK_VERSION=	1.4.0-beta3
INSTALL_JDK_VERSION=	1.4.0b3
ONLY_FOR_ARCHS=	i386
TARGET_DIR?=	${PREFIX}/${PKGBASE}${PORTVERSION}
DOWNLOAD_URL?=	http://java.sun.com/j2se/1.4/\#linux
PORTTITLE=	Java 2 Development Kit ${INSTALL_JDK_VERSION} for Linux

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=You must manually fetch the ${PORTTITLE} archive (${DISTNAME}${EXTRACT_SUFX}) from ${DOWNLOAD_URL}, place it in ${DISTDIR} and then run make again
.endif

post-fetch:
	@${CHMOD} +x ${DISTDIR}/${DISTFILES}

post-patch:
	find ${WRKSRC} -name '*.orig' -print | xargs ${RM} -f

do-install:
	${MKDIR} ${PREFIX}/${PKGNAMEPREFIX}jdk${PORTVERSION}
	${TAR} -C ${WRKSRC} -cf- . | ${TAR} -C ${PREFIX}/${PKGNAMEPREFIX}jdk${PORTVERSION} -xpf-
	${LOCALBASE}/bin/registervm "${TARGET_DIR}/bin/java # Linux-Sun-JDK${PORTVERSION}"

.include <bsd.port.post.mk>
