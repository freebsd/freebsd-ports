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
SCSL_SRCFILE=	j2sdk-${JDK_VERSION:S/./_/g}-src-scsl.zip
SCSL_BINFILE=	j2sdk-${JDK_VERSION:S/./_/g}-bin-scsl.zip
PATCHSETFILE=	bsd-jdk14-patches-${JDK_PATCHSET_VERSION}.tar.gz
DISTFILES=	${SCSL_SRCFILE} ${SCSL_BINFILE} ${PATCHSETFILE}

MAINTAINER=	phantom@FreeBSD.org
COMMENT=	Java Development Kit 1.4.2

EXTRACT_DEPENDS=zip:${PORTSDIR}/archivers/zip
BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4 \
		zip:${PORTSDIR}/archivers/zip \
		${X11BASE}/lib/libXm.so:${PORTSDIR}/x11-toolkits/open-motif \
		${LOCALBASE}/include/nspr/prtypes.h:${PORTSDIR}/devel/nspr
RUN_DEPENDS=	javavm:${PORTSDIR}/java/javavmwrapper
.if !defined(MINIMAL)
RUN_DEPENDS+=	${X11BASE}/lib/X11/fonts/URW/fonts.dir:${PORTSDIR}/x11-fonts/urwfonts
.endif

WRKSRC=		${WRKDIR}/control/make

JDK_VERSION=	1.4.2
JDK_PATCHSET_VERSION=	6

SUN_LINUX_JDK_VERSION=  1.4.2

.if !defined(WITH_LINUX_BOOTSTRAP)
NATIVE_BOOTSTRAP_JDKS=	${LOCALBASE}/jdk1.4.2 \
			${LOCALBASE}/jdk1.4.1
.endif

LINUX_BOOTSTRAP_JDKS=	${LOCALBASE}/linux-sun-jdk1.4.2_03 \
			${LOCALBASE}/linux-sun-jdk1.4.2_02 \
			${LOCALBASE}/linux-sun-jdk1.4.2_01 \
			${LOCALBASE}/linux-sun-jdk1.4.2 \
			${LOCALBASE}/linux-sun-jdk1.4.1_02 \
			${LOCALBASE}/linux-sun-jdk1.4.1_01 \
			${LOCALBASE}/linux-sun-jdk1.4.1

.include <bsd.port.pre.mk>

# do we have valid native jdk installed?
.if !defined(WITH_LINUX_BOOTSTRAP)
.for CJDK in ${NATIVE_BOOTSTRAP_JDKS}
.  if !defined(JDK14DIR) && exists(${CJDK}/bin/javac)
JDK14DIR=	${CJDK}
.  endif
.endfor
.endif

# do we have valid linux jdk installed?
.if !defined(JDK14DIR)
.for CJDK in ${LINUX_BOOTSTRAP_JDKS}
.  if !defined(JDK14DIR) && exists(${CJDK}/bin/javac)
JDK14DIR=	${CJDK}
WITH_LINUX_BOOTSTRAP=	YES
.  endif
.endfor
.endif

# if no valid jdk found, set dependency
.if !defined(JDK14DIR)
JDK14DIR?=	${LOCALBASE}/linux-sun-jdk${SUN_LINUX_JDK_VERSION}
.endif

BUILD_DEPENDS+=	${JDK14DIR}/bin/javac:${PORTSDIR}/java/linux-sun-jdk14

# workaround to handle both 'zip' and 'tar.gz' distfiles
USE_ZIP=	YES
EXTRACT_ONLY=	${SCSL_SRCFILE} ${SCSL_BINFILE}

ONLY_FOR_ARCHS=	i386
USE_GMAKE=	YES
USE_REINPLACE=	YES
RESTRICTED=	"Redistribution of pre-compiled binaries is not permitted"
NO_CDROM=	"Redistribution of pre-compiled binaries is not permitted"
MAKE_ENV=	ALT_BOOTDIR="${JDK14DIR}" \
		ALT_MOTIF_DIR="${X11BASE}" \
		SYS_CFLAGS="${CFLAGS}" \
		DEV_ONLY="YES" \
		LANG="C" \
		JAVA_HOME="" \
		CLASSPATH="" \
		LD_LIBRARY_PATH=""
.if defined(MINIMAL)
MAKE_ENV+=	NO_PLUGIN="YES" \
		NO_JAVAWS="YES"
.endif
ALL_TARGET=	all
PLIST_SUB+=	JDK_VERSION=${JDK_VERSION}
PKGINSTALL=	${WRKDIR}/pkg-install

JDKIMAGEDIR=	${WRKSRC}/../build/bsd-i586/j2sdk-image
JDKIMAGEDIR_G=	${WRKSRC}/../build/bsd-i586/j2sdk-debug-image

.if !defined(WITH_IPV6)
EXTRA_PATCHES+=	${PATCHDIR}/disable-ipv6.patch
.endif

.if defined(MINIMAL)
PLIST_SUB+=	MINIMAL:="@comment "
PKGNAMESUFFIX=	-minimal
.else
PLIST_SUB+=	MINIMAL:=""
.endif

.if defined(WITH_DEBUG)
PLIST_SUB+=	DEBUG:=""
.else
PLIST_SUB+=	DEBUG:="@comment "
.endif

PTHREAD_FILES=	../../hotspot/build/bsd/makefiles/vm.make \
		../../j2se/make/common/Defs.gmk	\
		../../j2se/make/common/Program.gmk \
		../../j2se/make/common/Defs-bsd.gmk \
		../../j2se/make/java/hpi/hpi_common.gmk \
		../../j2se/make/java/hpi/native/Makefile \
		../../j2se/make/java/net/Makefile \
		../../deploy/make/common/Defs-bsd.gmk \
		../../deploy/make/plugin/common/config.gmk

LD_LIBRARY_PATH_FILES=	../../hotspot/src/os/bsd/vm/os_bsd.cpp

# Check for JDK sources
.if !exists(${DISTDIR}/${SCSL_SRCFILE}) && !defined(PACKAGE_BUILDING)
ECHO_MSG=/usr/bin/printf
IGNORE= :\n\
Because of licensing restrictions, you must fetch the source distribution\n\
manually.  Please access http://www.sun.com/software/java2/download.html\n\
with a web browser and follow the \"Download\" link for the\n\
\"Java(TM) SDK ${JDK_VERSION}\". You will be required to log in and register,\n\
but you can create an account on this page.  After registration and\n\
accepting the Sun Community Source License, select \"J2SESDK\" and\n\
download the source file, ${SCSL_SRCFILE}.  Please place this file in\n\
${DISTDIR}.\n
.endif
.if !exists(${DISTDIR}/${SCSL_BINFILE}) && !defined(PACKAGE_BUILDING)
ECHO_MSG=/usr/bin/printf
IGNORE= :\n\
Because of licensing restrictions, you must fetch the source distribution\n\
manually.  Please access http://www.sun.com/software/java2/download.html\n\
with a web browser and follow the \"Download\" link for the\n\
\"Java(TM) SDK ${JDK_VERSION}\". You will be required to log in and register,\n\
but you can create an account on this page.  After registration and\n\
accepting the Sun Community Source License, select \"J2SESDK\" and\n\
download the source file, ${SCSL_BINFILE}.  Please place this file in\n\
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

# JDK 1.4.2 require recent version of FreeBSD due to recent libc_r updates.
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
use JDK 1.4.2.\n\n" ; \
	exit 1 ; \
	fi
	@${WRKDIR}/${TESTPROG} 2>/dev/null
.endif

pre-fetch:	check-os
	@${ECHO_MSG}
	@${ECHO_MSG} "IMPORTANT: To build JDK 1.4.2 port, you should have at least"
	@${ECHO_MSG} "1.7Gb of free disk space in build area!"
	@${ECHO_MSG}
.if defined(WITH_LINUX_BOOTSTRAP)
	@${ECHO_MSG} "IMPORTANT: To build JDK 1.4.2 port, you should have linux emulation"
	@${ECHO_MSG} "enabled in the kernel and linux procfs (linprocfs) filesystem"
	@${ECHO_MSG} "mounted."
	@${ECHO_MSG}
.endif
	@${ECHO_MSG} "Following port compile time options are available:"
	@${ECHO_MSG}
	@${ECHO_MSG} "    WITH_DEBUG  - install JDK binaries and libraries"
	@${ECHO_MSG} "                  with debuging support"
	@${ECHO_MSG}
	@${ECHO_MSG} "    MINIMAL     - don't build/install mozilla java"
	@${ECHO_MSG} "                  plugin, javaws and JDK demos"
	@${ECHO_MSG}
	@${ECHO_MSG} "    WITH_IPV6   - enable JDK IPv6 support"
	@${ECHO_MSG}

pre-patch:
	@cd ${WRKDIR} &&  \
		${GZIP_CMD} -dc ${DISTDIR}/${PATCHSETFILE} | ${TAR} -xf - && \
		${CHMOD} -R u+w * && \
		${PATCH} -p0 < ${WRKDIR}/jdk14.patches

post-patch:
	@for file in ${LD_LIBRARY_PATH_FILES}; do \
		${REINPLACE_CMD} -e "s:%%LOCALBASE%%:${LOCALBASE}:" \
			${WRKSRC}/$${file}; \
	done
	@for file in ${PTHREAD_FILES}; do \
		${REINPLACE_CMD} -e "s:-lkse:${PTHREAD_LIBS}:g" \
			${WRKSRC}/$${file}; \
	done

.if defined(WITH_LINUX_BOOTSTRAP)
pre-build:
	@if [ "$${WRKDIRPREFIX}" -a \
	     -L "/compat/linux/$${WRKDIRPREFIX}" -a \
	     x`${LS} -ld "/compat/linux/$${WRKDIRPREFIX}" 2>/dev/null | awk '/->/{print $$NF;exit 0}END{exit 1}'` = x"$${WRKDIRPREFIX}" ]; \
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
		${ECHO_MSG} "starting to build of native JDK 1.4.2." ; \
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
	@# make sure that SwingSet2/resources does not exists
	@${RM} -rf ${JDKIMAGEDIR}/demo/jfc/SwingSet2/resources
	@${RM} -rf ${JDKIMAGEDIR}/demo/plugin/jfc/SwingSet2/resources
	@# XXX don't install japanese manpages
	@${RM} -rf ${JDKIMAGEDIR}/man/ja
	@${RM} -rf ${JDKIMAGEDIR}/man/ja_JP.eucJP

pre-install:
.if !defined(WITH_DEBUG)
	@${ECHO_MSG}
	@${ECHO_MSG} "Please use \`make -DWITH_DEBUG' if you want to install libraries and binaries"
	@${ECHO_MSG} "with debugging support."
	@${ECHO_MSG}
.endif
.if defined(MINIMAL)
	@${RM} -rf ${JDKIMAGEDIR}/demo
.endif

do-install:
	${MKDIR} ${PREFIX}/jdk${JDK_VERSION}
	cd ${JDKIMAGEDIR} && ${FIND} . \
	  | ${CPIO} -pdmu -R ${LIBOWN}:${LIBGRP} ${PREFIX}/jdk${JDK_VERSION}
.if defined(WITH_DEBUG)
	cd ${JDKIMAGEDIR_G} && ${FIND} . \
	  | ${CPIO} -pdmu -R ${LIBOWN}:${LIBGRP} ${PREFIX}/jdk${JDK_VERSION}
.endif
	${INSTALL_DATA} ${FILESDIR}/cacerts \
		${PREFIX}/jdk${JDK_VERSION}/jre/lib/security/cacerts
.if !defined(MINIMAL)
	${INSTALL_DATA} ${FILESDIR}/cacerts \
		${PREFIX}/jdk${JDK_VERSION}/jre/javaws/cacerts
.endif

post-install:
	@${LOCALBASE}/bin/registervm "${PREFIX}/jdk${JDK_VERSION}/bin/java # FREEBSD-JDK${JDK_VERSION}"
	@${SED} -e "s:%%JRE_HOME%%:${PREFIX}/jdk${JDK_VERSION}/jre:g" \
	  < ${FILESDIR}/pkg-install.in > ${PKGINSTALL}
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
