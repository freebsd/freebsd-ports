# New ports collection makefile for:	linux jdk 1.3.0
# Date created:				06 December 2000
# Whom:					Kevin Lo <kevlo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jdk
PORTVERSION=	${JDK_VERSION}
CATEGORIES=	java devel
MASTER_SITES=	#
PKGNAMEPREFIX=	linux-
DISTFILES=	j2sdk-1_3_0_02-linux.bin

MAINTAINER=	kevlo@FreeBSD.org

RUN_DEPENDS=	${LINUXBASE}/lib/libc.so.6:${PORTSDIR}/emulators/linux_base \
		javavm:${PORTSDIR}/java/javavmwrapper

JDK_VERSION=	1.3.0

NO_CDROM=	"License doesn\'t allow distribution with fee"
RESTRICTED=	"Redistribution of repackaged binaries not permitted"

.if defined(BATCH) || defined(PACKAGE_BUILDING)
IGNORE=	"You can not legally distribute binaries"
.endif

ONLY_FOR_ARCHS=	i386
EXTRACT_CMD=		# empty
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	#empty

WRKSRC=		${WRKDIR}/jdk1.3.0_02

NO_BUILD=	yes

.include <bsd.port.pre.mk>

.for file in ${DISTFILES}
.if !exists(${DISTDIR}/${file})
IGNORE=You must manually fetch the Java SDK 1.3.0 for Linux archive (j2sdk-1_3_0_02-linux.bin) from http://java.sun.com/j2se/1.3/download-linux.html, place it in ${DISTDIR} and then run make again.
.endif
.endfor

post-fetch:
	@${CHMOD} +x ${DISTDIR}/${DISTFILES}

post-patch:
	find ${WRKSRC} -name '*.orig' -print | xargs ${RM} -f

do-install:
	${MKDIR} ${PREFIX}/${PKGNAMEPREFIX}jdk${JDK_VERSION}
	${TAR} -C ${WRKSRC} -cf- . | ${TAR} -C ${PREFIX}/${PKGNAMEPREFIX}jdk${JDK_VERSION} -xpf-
	${LOCALBASE}/bin/registervm "${PREFIX}/linux-jdk${JDK_VERSION}/bin/java # Linux-JDK${JDK_VERSION}"

.include <bsd.port.post.mk>
