# New ports collection makefile for:	jdk12
# Date created:				10 October 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jdk
PORTVERSION=	${JDK_VERSION}b${JDK_BETALEVEL}
CATEGORIES=	java devel
MASTER_SITES=	# http://www.sun.com/software/communitysource/java2/
#		 http://www.eyesbeyond.com/freebsddom/java/jdk.html
DISTFILES=	${PORTNAME}${JDK_VERSION:S/./_/g}-src${EXTRACT_SUFX} \
		freebsd-jdk122-patches-${JDK_BETALEVEL}.tar.gz

MAINTAINER=	sobomax@FreeBSD.org

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4 \
		zip:${PORTSDIR}/archivers/zip \
		${JDK11DIR}/bin/javac:${PORTSDIR}/java/jdk \
		${JDK12DIR}/bin/javac:${PORTSDIR}/java/linux-jdk \
		${X11BASE}/lib/libMrm.a:${PORTSDIR}/x11-toolkits/open-motif-devel \
		${NONEXISTENT}:${PORTSDIR}/java/jfc:extract
LIB_DEPENDS=	odbc.1:${PORTSDIR}/databases/unixODBC
RUN_DEPENDS=	${X11BASE}/lib/X11/fonts/URW/fonts.dir:${PORTSDIR}/x11-fonts/urwfonts \
		javavm:${PORTSDIR}/java/javavmwrapper

WRKSRC=		${WRKDIR}/build/freebsd

JDK_VERSION=	1.2.2
JDK_BETALEVEL=	10

JDK11DIR?=	${LOCALBASE}/jdk1.1.8
JFC11DIR?=	${WRKDIRPREFIX}${.CURDIR}/../../java/jfc/work/swing-1.1.1fcs
JDK12DIR?=	${LOCALBASE}/linux-jdk${JDK_VERSION}

ONLY_FOR_ARCHS=	i386
USE_GMAKE=	yes
RESTRICTED=	"Redistribution of pre-compiled binaries isn't permitted"
MAKEFILE=	GNUmakefile
MAKE_ENV=	HAVE_DPS="no" \
		ALT_BOOTDIR="${JDK12DIR}" \
		ALT_ODBCDIR="${LOCALBASE}" \
		ALT_MOTIF_DIR="${X11BASE}" \
		OPENWINHOME="${X11BASE}" \
		_JDK11DIR="${JDK11DIR}" \
		SYS_CFLAGS="${CFLAGS}" \
		CLASSPATH="" \
		JAVA_COMPILER=""
ALL_TARGET=	release-images
PATCH_CMD=	${PATCH} -p1 -s <
PLIST_SUB+=	JDK_VERSION=${JDK_VERSION}

JDKIMAGEDIR=	${WRKSRC}/jdk-image-i386
JDKIMAGEDIR_G=	${WRKSRC}/jdk-debug-image-i386
JREIMAGEDIR=	${WRKSRC}/jre-image-i386

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
IGNORE=You must manually fetch the source distribution and FreeBSD patches (${DISTFILES}) from http://www.sun.com/software/communitysource/java2/ and http://www.eyesbeyond.com/freebsddom/java/jdk.html, place it in ${DISTDIR} and then run make again
.endif
.endfor

pre-patch:
	@${MKDIR} ${WRKSRC}
.for dir in build src ext/i18n/build ext/i18n/src ext/iiimp/build 
	@cd ${WRKDIR}/${dir} && ${RM} -rf freebsd && ${CP} -R solaris freebsd
.endfor
	@cd ${WRKSRC}		&& ${PATCH_CMD} ${WRKDIR}/build.patches && \
	 cd ../share		&& ${PATCH_CMD} ${WRKDIR}/buildshare.patches && \
	 cd ../../src/freebsd	&& ${PATCH_CMD} ${WRKDIR}/src.patches && \
	 cd ../share		&& ${PATCH_CMD} ${WRKDIR}/srcshare.patches && \
	 cd ../../ext		&& ${PATCH_CMD} ${WRKDIR}/ext.patches
	@${MKDIR} ${WRKSRC}/1.1_libs
	@${CP} ${JFC11DIR}/*.jar ${WRKSRC}/1.1_libs

post-build:
	for dir in ${JDKIMAGEDIR} ${JDKIMAGEDIR_G} ${JREIMAGEDIR}; do \
		for file in `find $${dir} -type  f -name "*.so"`; do \
			if [ -f $${file}.${JDK_VERSION} ]; then \
				${RM} $${file}.${JDK_VERSION}; \
				${LN} -sf `${BASENAME} $${file}` $${file}.${JDK_VERSION}; \
			fi; \
		done; \
	done
	for dir in ${JDKIMAGEDIR} ${JREIMAGEDIR}; do \
		find $${dir} -type  f | xargs file | ${GREP} 'not stripped$$' | \
			${SED} 's|:.*$$||' | xargs strip; \
	done

.if !defined(NODEBUG)
pre-install:
	@${ECHO_MSG}
	@${ECHO_MSG} "Please use \`make -DNODEBUG' if you don't want to install libraries and binaries"
	@${ECHO_MSG} "with debugging support."
	@${ECHO_MSG}
.endif

do-install:
	${MKDIR} ${PREFIX}/jdk${JDK_VERSION}
	(cd ${JDKIMAGEDIR} && ${TAR} -c -f - .) \
		| (cd ${PREFIX}/jdk${JDK_VERSION} && ${TAR} --unlink -x -f -)
.if !defined(NODEBUG)
	(cd ${JDKIMAGEDIR_G} && ${TAR} -c -f - .) \
		| (cd ${PREFIX}/jdk${JDK_VERSION} && ${TAR} --unlink -x -f -)
.endif

post-install:
	${LOCALBASE}/bin/registervm "${PREFIX}/jdk${JDK_VERSION}/bin/java # JDK${JDK_VERSION}"

.include <bsd.port.post.mk>
