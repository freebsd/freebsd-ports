# New ports collection makefile for:	Sun Linux JDK 1.4.x
# Date created:				25 May 2001
# Whom:					Ernst de Haan <ernst@jollem.com>
#
# $FreeBSD$
#

PORTNAME=	jdk
PORTVERSION=	${JDK_VERSION:S/-//g}
CATEGORIES=	java devel
MASTER_SITES=	#
PKGNAMEPREFIX=	linux-
DISTFILES=	j2sdk-${JDK_VERSION:S/./_/g}-linux-i386.bin

MAINTAINER=	ernst@jollem.com

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
PLIST_SUB+=	TARGET_PREFIX=${TARGET_PREFIX:S/^${PREFIX}\///}

NO_BUILD=	yes
USE_LINUX=	yes
JDK_VERSION=	1.4.0-beta
ONLY_FOR_ARCHS=	i386
TARGET_PREFIX?=	${PREFIX}/${PKGBASE}${PORTVERSION}

.include <bsd.port.pre.mk>

.for file in ${DISTFILES}
.if !exists(${DISTDIR}/${file})
IGNORE=You must manually fetch the Java 2 Development Kit ${JDK_VERSION} for Linux archive (${DISTFILES}) from http://java.sun.com/j2se/1.3/download-linux.html, place it in ${DISTDIR} and then run make again
.endif
.endfor

post-fetch:
	@${CHMOD} +x ${DISTDIR}/${DISTFILES}

post-patch:
	find ${WRKSRC} -name '*.orig' -print | xargs ${RM} -f

do-install:
	${MKDIR} ${PREFIX}/${PKGNAMEPREFIX}jdk${PORTVERSION}
	${TAR} -C ${WRKSRC} -cf- . | ${TAR} -C ${PREFIX}/${PKGNAMEPREFIX}jdk${PORTVERSION} -xpf-
	${LOCALBASE}/bin/registervm "${PREFIX}/linux-jdk${PORTVERSION}/bin/java # Linux-JDK${PORTVERSION}"

.include <bsd.port.post.mk>
