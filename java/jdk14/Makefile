# New ports collection makefile for:	jdk14
# Date created:				6 March 2003
# Whom:					Alexey Zelkin <phantom@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jdk
PORTVERSION=	${JDK_VERSION}p${JDK_PATCHSET_VERSION}
PORTREVISION=	3
CATEGORIES=	java devel
MASTER_SITES=	# http://www.sun.com/software/java2/download.html
#		 http://www.eyesbeyond.com/freebsddom/java/jdk14.html
SRCFILE=	j2sdk-${JDK_VERSION:S/./_/g}-src-scsl.zip
PATCHSETFILE=	bsd-jdk14-patches-${JDK_PATCHSET_VERSION}.tar.gz
DISTFILES=	${SRCFILE} ${PATCHSETFILE}

MAINTAINER=	phantom@FreeBSD.org
COMMENT=	Java Development Kit 1.4.1

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4 \
		zip:${PORTSDIR}/archivers/zip \
		${X11BASE}/lib/libXm.so:${PORTSDIR}/x11-toolkits/open-motif
.if !defined(NATIVE_BOOTSTRAP)
BUILD_DEPENDS+=	${JDK14DIR}/bin/javac:${PORTSDIR}/java/linux-sun-jdk14
.endif
RUN_DEPENDS=	javavm:${PORTSDIR}/java/javavmwrapper \
		${X11BASE}/lib/libXm.so:${PORTSDIR}/x11-toolkits/open-motif \
		${X11BASE}/lib/X11/fonts/URW/fonts.dir:${PORTSDIR}/x11-fonts/urwfonts

WRKSRC=		${WRKDIR}/control/make

JDK_VERSION=	1.4.1
JDK_PATCHSET_VERSION=	3

SUN_LINUX_JDK_VERSION=	1.4.2

.if defined(NATIVE_BOOTSTRAP)
JDK14DIR?=	${LOCALBASE}/jdk${JDK_VERSION}
.else
JDK14DIR?=	${LOCALBASE}/linux-sun-jdk${SUN_LINUX_JDK_VERSION}
.endif

# workaround to handle both 'zip' and 'tar.gz' distfiles
USE_ZIP=	YES
EXTRACT_ONLY=	${SRCFILE}

ONLY_FOR_ARCHS=	i386
USE_GMAKE=	YES
RESTRICTED=	"Redistribution of pre-compiled binaries is not permitted"
NO_CDROM=	"Redistribution of pre-compiled binaries is not permitted"
MAKE_ENV=	ALT_BOOTDIR="${JDK14DIR}" \
		ALT_MOTIF_DIR="${X11BASE}" \
		SYS_CFLAGS="${CFLAGS}" \
		JAVAWS_OPTIONAL="YES" \
		NO_DOCS="YES" \
		LANG="C" \
		JAVA_HOME="" \
		CLASSPATH="" \
		LD_LIBRARY_PATH=""
ALL_TARGET=	all
PLIST_SUB+=	JDK_VERSION=${JDK_VERSION}

JDKIMAGEDIR=	${WRKSRC}/../build/bsd-i586/j2sdk-image
JDKIMAGEDIR_G=	${WRKSRC}/../build/bsd-i586/j2sdk-debug-image

SORT?=		/usr/bin/sort
CPIO?=		/usr/bin/cpio

.if defined(NODEBUG)
PLIST_SUB+=	DEBUG:="@comment "
PKGNAMESUFFIX=	-nodebug
.else
PLIST_SUB+=	DEBUG:=""
.endif

.include <bsd.port.pre.mk>

# Check for JDK sources
.if !exists(${DISTDIR}/${SRCFILE}) && !defined(PACKAGE_BUILDING)
ECHO_MSG=/usr/bin/printf
IGNORE= :\n\
Because of licensing restrictions, you must fetch the source distribution\n\
manually.  Please access http://www.sun.com/software/java2/download.html\n\
with a web browser and follow the \"Download\" link for the\n\
\"Java(TM) SDK ${JDK_VERSION}\". You will be required to log in and register,\n\
but you can create an account on this page.  After registration and\n\
accepting the Sun Community Source License, select \"J2SESDK\" and\n\
download the source file, ${SRCFILE}.  Please place this file in\n\
${DISTDIR}.\n
.endif

# Check for patchset
.if !exists(${DISTDIR}/${PATCHSETFILE}) && !defined(PACKAGE_BUILDING)
ECHO_MSG=/usr/bin/printf
IGNORE= :\n\
The source distribution exists on your system, but due to\n\
licensing restrictions you still need to download the\n\
patchset, ${PATCHSETFILE}, from\n\
http://www.eyesbeyond.com/freebsddom/java/jdk14.html.\n\
Please place the patchset in ${DISTDIR}.\n
.endif

# JDK 1.4.1 require recent version of FreeBSD due to recent libc_r updates.
# Make check for reqiuired primities as early as possible

TESTPROG=testos

.if ${OSVERSION} > 500000
LINKIT=	-lc_r
.else
LINKIT=	-pthread
.endif

check-os:
.if !defined(SKIP_OS_TEST)
	-@mkdir -p ${WRKDIR} ; \
	rm -f ${WRKDIR}/${TESTPROG} ; \
	gcc ${LINKIT} -o ${WRKDIR}/${TESTPROG} \
		${FILESDIR}/${TESTPROG}.c > /dev/null 2>&1
	@if [ ! -f ${WRKDIR}/${TESTPROG} ] ; \
	then \
	/usr/bin/printf "\n\
You must have a version of FreeBSD later than 4.7-STABLE\n\
February 2003 or 5-CURRENT February 2003 to compile and\n\
use JDK 1.4.1.\n\n" ; \
	exit 1 ; \
	fi
	@${WRKDIR}/${TESTPROG} 2>/dev/null
.endif

pre-fetch:	check-os
	@${ECHO_MSG}
	@${ECHO_MSG} "NOTICES:"
	@${ECHO_MSG}
	@${ECHO_MSG} "To build JDK 1.4.1 port, you should have at least"
	@${ECHO_MSG} "2.5Gb of free disk space in build area!"
	@${ECHO_MSG}
	@${ECHO_MSG} "To build JDK 1.4.1 port, you should have linux emulation"
	@${ECHO_MSG} "enabled in the kernel and linux procfs (linprocfs) filesystem"
	@${ECHO_MSG} "mounted."
	@${ECHO_MSG}
	@${ECHO_MSG} "NOTE: Please use \`make -DNODEBUG' if you don't want to"
	@${ECHO_MSG} "install libraries and binaries with debugging support."
	@${ECHO_MSG}

pre-patch:
	@cd ${WRKDIR} &&  \
		${GZIP_CMD} -dc ${DISTDIR}/${PATCHSETFILE} | ${TAR} -xf - && \
		${CHMOD} -R u+w * && \
		${PATCH} -p0 < ${WRKDIR}/jdk14.patches

.if !defined(NATIVE_BOOTSTRAP)
ECHO_MSG=echo
pre-build:
	@if [ "$${WRKDIRPREFIX}" -a \
	     -L "/compat/linux/$${WRKDIRPREFIX}" -a \
	     x`ls -ld "/compat/linux/$${WRKDIRPREFIX}" 2>/dev/null | awk '/->/{print $$NF;exit 0}END{exit 1}'` = x"$${WRKDIRPREFIX}" ]; \
	then \
		${ECHO_MSG} "Please set WRKDIRPREFIX to something which doesn't"; \
		${ECHO_MSG} "have a matching symbolic link in /compat/linux."; \
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
	@if [ "`/sbin/mount | grep ^linprocfs`" = "" ]; \
	then \
		${ECHO_MSG} "ERROR: You have to have LINPROCFS mounted before" ; \
		${ECHO_MSG} "starting to build of native JDK 1.4.1." ; \
		${ECHO_MSG} "" ; \
		${ECHO_MSG} "You may do it by following set of commands:" ; \
		${ECHO_MSG} "" ; \
		${ECHO_MSG} "# kldload linprocfs" ; \
		${ECHO_MSG} "" ; \
		${ECHO_MSG} "and" ; \
		${ECHO_MSG} "" ; \
		${ECHO_MSG} "# mount -t linprocfs linprocfs /compat/linux/proc" ; \
		${ECHO_MSG} "" ; \
		exit 1 ; \
	fi
.endif

do-build:
	# Start of jdk build
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})

post-build:
	@# XXX make sure that SwingSet2/resources does not exists
	@${RM} -rf ${JDKIMAGEDIR}/demo/jfc/SwingSet2/resources
	@# This file serves no purpose (in case of port)
	@${RM} -f ${JDKIMAGEDIR}/src.zip

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

post-install:
	@${LOCALBASE}/bin/registervm "${PREFIX}/jdk${JDK_VERSION}/bin/java # FREEBSD-JDK${JDK_VERSION}"

.include <bsd.port.post.mk>
