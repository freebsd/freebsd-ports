# New ports collection makefile for:	jdk12
# Date created:				10 October 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jdk
PORTVERSION=	${JDK_VERSION}p${JDK_PATCHSET_VERSION}
PORTREVISION=	3
CATEGORIES=	java devel
MASTER_SITES=	# http://www.sun.com/software/java2/download.html
#		 http://www.eyesbeyond.com/freebsddom/java/jdk.html
SRCFILE=	${PORTNAME}${JDK_VERSION:S/./_/g}-src${EXTRACT_SUFX}
PATCHSETFILE=	bsd-jdk122-patches-${JDK_PATCHSET_VERSION}.tar.gz
DISTFILES=	${SRCFILE} ${PATCHSETFILE}

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	Java Development Kit 1.2

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4 \
		zip:${PORTSDIR}/archivers/zip \
		${JDK11DIR}/bin/javac:${PORTSDIR}/java/jdk11 \
		${X11BASE}/lib/libXm.so:${PORTSDIR}/x11-toolkits/open-motif
PATCH_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/java/jfc:extract
LIB_DEPENDS=	odbc.1:${PORTSDIR}/databases/unixODBC
RUN_DEPENDS=	javavm:${PORTSDIR}/java/javavmwrapper \
		${X11BASE}/lib/libXm.so:${PORTSDIR}/x11-toolkits/open-motif \
		${X11BASE}/lib/X11/fonts/URW/fonts.dir:${PORTSDIR}/x11-fonts/urwfonts

WRKSRC=		${WRKDIR}/build/bsd

JDK_VERSION=	1.2.2
JDK_PATCHSET_VERSION=	11
LATEST_LINK=	jdk12

JDK11DIR?=	${LOCALBASE}/jdk1.1.8
JFC11DIR?=	${WRKDIRPREFIX}${.CURDIR}/../../java/jfc/work/swing-1.1.1fcs

ONLY_FOR_ARCHS=	i386
USE_GMAKE=	yes
USE_REINPLACE=	yes
RESTRICTED=	"Redistribution of pre-compiled binaries is not permitted"
NO_CDROM=	"Redistribution of pre-compiled binaries is not permitted"
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
PATCH_CMD=	${PATCH} -p1 <
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

.include <bsd.port.pre.mk>

.if !defined(JDK12DIR)
.if defined(WITH_LINUX_BOOTSTRAP) || !exists(${PREFIX}/jdk${JDK_VERSION}/bin/javac)
JDK12DIR=	${LOCALBASE}/linux-blackdown-jdk${JDK_VERSION}
BUILD_DEPENDS+=	${JDK12DIR}/bin/javac:${PORTSDIR}/java/linux-blackdown-jdk12
.else
JDK12DIR=	${LOCALBASE}/jdk${JDK_VERSION}
.endif
.endif

# Check for patchset
.if !exists(${DISTDIR}/${PATCHSETFILE}) && !defined(PACKAGE_BUILDING)
ECHO_MSG=/usr/bin/printf
IGNORE= :\n\
The source distribution exists on your system, but due to\n\
licensing restrictions you still need to download the\n\
patchset, ${PATCHSETFILE}, from\n\
http://www.eyesbeyond.com/freebsddom/java/jdk.html.\n\
Please place the patchset in ${DISTDIR}.\n
.endif

# Check for JDK sources
.if !exists(${DISTDIR}/${SRCFILE}) && !defined(PACKAGE_BUILDING)
ECHO_MSG=/usr/bin/printf
IGNORE= :\n\
Because of licensing restrictions, you must fetch the source distribution\n\
manually.  Please access http://www.sun.com/software/java2/download.html\n\
with a web browser and follow the second \"Download\" link for the\n\
\"Java(TM) SDK ${JDK_VERSION}\".  You will be required to log in and register,\n\
but you can create an account on this page.  After registration and\n\
accepting the Sun Community Source License, select \"JDK-${JDK_VERSION}\" and\n\
download the file \"${SRCFILE}\".  Please place this file in\n\
${DISTDIR}.\n
.endif

pre-patch:
	@${MKDIR} ${WRKSRC}
.for dir in build src ext/i18n/build ext/i18n/src ext/iiimp/build
	@cd ${WRKDIR}/${dir} && ${RM} -rf bsd && ${CP} -R solaris bsd
.endfor
	@cd ${WRKSRC}		&& ${PATCH_CMD} ${WRKDIR}/build.patches && \
	 cd ../share		&& ${PATCH_CMD} ${WRKDIR}/buildshare.patches && \
	 cd ../../src/bsd	&& ${PATCH_CMD} ${WRKDIR}/src.patches && \
	 cd ../share		&& ${PATCH_CMD} ${WRKDIR}/srcshare.patches && \
	 cd ../../ext		&& ${PATCH_CMD} ${WRKDIR}/ext.patches
	@${MKDIR} ${WRKSRC}/1.1_libs
	@${CP} ${JFC11DIR}/*.jar ${WRKSRC}/1.1_libs

post-patch:
	@${REINPLACE_CMD} -e "s:%%LOCALBASE%%:${LOCALBASE}:" \
		${WRKSRC}/../../src/bsd/javavm/runtime/javai_md.c

.if defined(WITH_LINUX_BOOTSTRAP) || !exists(${PREFIX}/jdk${JDK_VERSION}/bin/javac)
# Some checks for bootstrapping with a Linux JDK
pre-build:
	@if [ `${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/check_wrkdir_links.sh "${WRKDIRPREFIX}" "${LINUXBASE}" 2>/dev/null` ]; \
	then \
		${ECHO_MSG} "Please set WRKDIRPREFIX to something which doesn't"; \
		${ECHO_MSG} "have a matching symbolic link in ${LINUXBASE}."; \
		${ECHO_MSG} "This is known to cause problems during bootstrapping."; \
		exit 1; \
	fi
	@if [ `/sbin/sysctl -n compat.linux.osname` != "Linux" ]; \
	then \
		${ECHO_MSG} "Please set the value of the sysctl compat.linux.osname"; \
		${ECHO_MSG} "to 'Linux' with the command:"; \
		${ECHO_MSG} "	/sbin/sysctl compat.linux.osname=Linux"; \
		${ECHO_MSG} "Having it set to other values, such as 'FreeBSD',"; \
		${ECHO_MSG} "is known to cause problems during bootstrapping."; \
		exit 1; \
	fi
.endif

post-build:
	for dir in ${JDKIMAGEDIR} ${JDKIMAGEDIR_G} ${JREIMAGEDIR}; do \
		for file in `${FIND} $${dir} -type  f -name "*.so"`; do \
			if [ -f $${file}.${JDK_VERSION} ]; then \
				${RM} $${file}.${JDK_VERSION}; \
				${LN} -sf `${BASENAME} $${file}` $${file}.${JDK_VERSION}; \
			fi; \
		done; \
	done
	for dir in ${JDKIMAGEDIR} ${JREIMAGEDIR}; do \
		${FIND} $${dir} -type  f | ${XARGS} file | \
			${GREP} 'not stripped$$' | \
			${SED} 's|:.*$$||' | ${XARGS} strip; \
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
	cd ${JDKIMAGEDIR} && ${FIND} . \
	  | ${CPIO} -pdmu -R ${LIBOWN}:${LIBGRP} ${PREFIX}/jdk${JDK_VERSION}
.if !defined(NODEBUG)
	cd ${JDKIMAGEDIR_G} && ${FIND} . \
	  | ${CPIO} -pdmu -R ${LIBOWN}:${LIBGRP} ${PREFIX}/jdk${JDK_VERSION}
.endif
	${INSTALL_DATA} ${FILESDIR}/cacerts ${PREFIX}/jdk${JDK_VERSION}/jre/lib/security/cacerts
	${MKDIR} ${PREFIX}/share/doc/java

post-install:
	${LOCALBASE}/bin/registervm "${PREFIX}/jdk${JDK_VERSION}/bin/java # JDK${JDK_VERSION}"

.include <bsd.port.post.mk>
