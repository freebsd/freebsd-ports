# New ports collection makefile for:	jdk13
# Date created:				10 October 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jdk
PORTVERSION=	${JDK_VERSION}p${JDK_PATCHSET_VERSION}
CATEGORIES=	java devel
MASTER_SITES=	# http://www.sun.com/software/java2/download.html
#		 http://www.eyesbeyond.com/freebsddom/java/jdk13.html
DISTFILES=	j2sdk-${JDK_VERSION:S/./_/g}-src${EXTRACT_SUFX} \
		bsd-jdk131-patches-${JDK_PATCHSET_VERSION}.tar.gz

MAINTAINER=	java@FreeBSD.org

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4 \
		zip:${PORTSDIR}/archivers/zip \
		gtar:${PORTSDIR}/archivers/gtar \
		${JDK13DIR}/bin/javac:${PORTSDIR}/java/linux-jdk13 \
		${X11BASE}/lib/libMrm.a:${PORTSDIR}/x11-toolkits/open-motif-devel
RUN_DEPENDS=	javavm:${PORTSDIR}/java/javavmwrapper

WRKSRC=		${WRKDIR}/j2sdk1.3.1/make

JDK_VERSION=	1.3.1
JDK_PATCHSET_VERSION=	5

JDK13DIR?=	${LOCALBASE}/linux-jdk${JDK_VERSION}

ONLY_FOR_ARCHS=	i386
USE_GMAKE=	yes
RESTRICTED=	"Redistribution of pre-compiled binaries isn't permitted"
MAKE_ENV=	ALT_BOOTDIR="${JDK13DIR}" \
		ALT_MOTIF_DIR="${X11BASE}" \
		OPENWINHOME="${X11BASE}" \
		SYS_CFLAGS="${CFLAGS}" \
		CLASSPATH="" \
		LD_LIBRARY_PATH="" \
		JAVA_COMPILER=""
ALL_TARGET=	all images
TAR=		gtar	# Necessary for proper extraction of sources
BSD_TAR=	/usr/bin/tar
PLIST_SUB+=	JDK_VERSION=${JDK_VERSION}

JDKIMAGEDIR=	${WRKSRC}/../build/bsd-i386/jdk-image-i386
JDKIMAGEDIR_G=	${WRKSRC}/../build/bsd-i386/jdk-debug-image-i386

.if defined(NODEBUG)
PLIST_SUB+=	DEBUG:="@comment "
PKGNAMESUFFIX=	-nodebug
.else
PLIST_SUB+=	DEBUG:=""
.endif

.if defined(BATCH) || defined(PACKAGE_BUILDING)
IGNORE=		"You can not legally distribute pre-compiled binaries"
.endif

.include <bsd.port.pre.mk>

.for file in ${DISTFILES}
.if !exists(${DISTDIR}/${file})
IGNORE=You must manually fetch the source distribution and FreeBSD patches (${DISTFILES}) from http://www.sun.com/software/java2/download.html and http://www.eyesbeyond.com/freebsddom/java/jdk13.html, place it in ${DISTDIR} and then run make again
.endif
.endfor

pre-patch:
	@cd ${WRKDIR} &&  \
		${MKDIR} -p j2sdk1.3.1/ext/plugin/oji-plugin/include/bsd/jdk12 && \
		${MKDIR} -p j2sdk1.3.1/ext/plugin/oji-plugin/include/solaris/navig5/private && \
		${MKDIR} -p j2sdk1.3.1/src/bsd/doc/man && \
			${PATCH} < ${WRKDIR}/jdk131.patches

.if !defined(NODEBUG)
pre-install:
	@${ECHO_MSG}
	@${ECHO_MSG} "Please use \`make -DNODEBUG' if you don't want to install libraries and binaries"
	@${ECHO_MSG} "with debugging support."
	@${ECHO_MSG}
.endif

do-install:
	${MKDIR} ${PREFIX}/jdk${JDK_VERSION}
	(cd ${JDKIMAGEDIR} && ${BSD_TAR} -c -f - .) \
		| (cd ${PREFIX}/jdk${JDK_VERSION} && ${BSD_TAR} --unlink -x -f -)
.if !defined(NODEBUG)
	(cd ${JDKIMAGEDIR_G} && ${BSD_TAR} -c -f - .) \
		| (cd ${PREFIX}/jdk${JDK_VERSION} && ${BSD_TAR} --unlink -x -f -)
.endif

post-install:
	${LOCALBASE}/bin/registervm "${PREFIX}/jdk${JDK_VERSION}/bin/java # FREEBSD-JDK${JDK_VERSION}"

.include <bsd.port.post.mk>
