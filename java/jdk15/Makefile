# New ports collection makefile for:	jdk15
# Date created:				12 January 2005
# Whom:					Alexey Zelkin <phantom@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jdk
PORTVERSION=	${JDK_VERSION}p${JDK_PATCHSET_VERSION}
CATEGORIES=	java devel
MASTER_SITES=	# http://www.sun.com/software/java2/download.html
#		 http://www.eyesbeyond.com/freebsddom/java/jdk15.html
SCSL_SRCFILE=	jdk-${JDK_VERSION:S/./_/g}-src-scsl.zip
SCSL_BINFILE=	jdk-${JDK_VERSION:S/./_/g}-bin-scsl.zip
PATCHSETFILE=	bsd-jdk15-patches-${JDK_PATCHSET_VERSION}.tar.bz2
DISTFILES=	${SCSL_SRCFILE} ${SCSL_BINFILE} ${PATCHSETFILE}

MAINTAINER=	phantom@FreeBSD.org
COMMENT=	Java Development Kit 1.5.0

# XXX: iconv dependency?
EXTRACT_DEPENDS=zip:${PORTSDIR}/archivers/zip
BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4 \
		zip:${PORTSDIR}/archivers/zip \
		${X11BASE}/lib/libXm.so:${PORTSDIR}/x11-toolkits/open-motif
RUN_DEPENDS=	javavm:${PORTSDIR}/java/javavmwrapper

PKGINSTALL=	${WRKDIR}/pkg-install

WRKSRC=		${WRKDIR}/control/make

JDK_VERSION=	1.5.0
JDK_PATCHSET_VERSION=	1
LATEST_LINK=	jdk15

SUN_LINUX_JDK_VERSION=  1.4.2

.if !defined(WITH_LINUX_BOOTSTRAP)
NATIVE_BOOTSTRAP_JDKS=	${LOCALBASE}/jdk1.4.2 \
			${LOCALBASE}/jdk1.5.0
.endif

LINUX_BOOTSTRAP_JDKS=	${LOCALBASE}/linux-sun-jdk1.4.2

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

# workaround to handle both 'zip' and 'tar.bz2' distfiles
USE_ZIP=	YES
EXTRACT_ONLY=	${SCSL_SRCFILE} ${SCSL_BINFILE}

ONLY_FOR_ARCHS=	i386 amd64
USE_GMAKE=	YES
USE_REINPLACE=	YES
RESTRICTED=	"Redistribution of pre-compiled binaries is not permitted"
NO_CDROM=	"Redistribution of pre-compiled binaries is not permitted"

MAKE_ENV=	ALT_BOOTDIR="${JDK14DIR}" \
		ALT_MOTIF_DIR="${X11BASE}" \
		SYS_CFLAGS="${CFLAGS}" \
		LANG="C" \
		JAVA_HOME="" \
		CLASSPATH="" \
		LD_LIBRARY_PATH="" \
		MAKEFLAGS="" \
		SKIP_COMPARE_IMAGES="YES" \
		DONT_BUILD_DOCS="YES" \
		DONT_BUILD_DEPLOY="YES" \
		DONT_BUILD_INSTALL="YES"
.if !defined(WITH_IPV6)
MAKE_ENV+=	DONT_ENABLE_IPV6="YES"
.endif

ALL_TARGET=	all

PLIST_FILES=	jdk${JDK_VERSION}/jre/.systemPrefs/.system.lock \
		jdk${JDK_VERSION}/jre/.systemPrefs/.systemRootModFile
PLIST_DIRS=	jdk${JDK_VERSION}/jre/.systemPrefs

.if (${ARCH} == amd64)
HOTSPOTARCH=amd64
.else
HOTSPOTARCH=i586
.endif

JDKIMAGEDIR=	${WRKSRC}/../build/bsd-${HOTSPOTARCH}/j2sdk-image
JDKIMAGEDIR_G=	${WRKSRC}/../build/bsd-${HOTSPOTARCH}/j2sdk-debug-image

PTHREAD_FILES=	../../hotspot/build/bsd/makefiles/vm.make \
		../../j2se/make/com/sun/java/pack/Makefile \
		../../j2se/make/common/Defs.gmk \
		../../j2se/make/common/Defs-bsd.gmk \
		../../j2se/make/common/Program.gmk \
		../../j2se/make/java/hpi/native/Makefile \
		../../j2se/make/java/net/Makefile \
		../../j2se/make/java/nio/Makefile \
		../../j2se/make/jpda/transport/socket/Makefile \
		../../j2se/make/sun/cmm/Makefile \
		../../j2se/make/sun/xawt/Makefile

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
http://www.eyesbeyond.com/freebsddom/java/jdk15.html.\n\
Please place the patchset in ${DISTDIR}.\n
.endif

pre-fetch:
	@${ECHO_MSG}
	@${ECHO_MSG} "IMPORTANT: To build JDK 1.5.0 port, you should have at least"
	@${ECHO_MSG} "1.7Gb of free disk space in build area!"
	@${ECHO_MSG}
.if defined(WITH_LINUX_BOOTSTRAP)
	@${ECHO_MSG} "IMPORTANT: To build JDK 1.5.0 port, you should have linux emulation"
	@${ECHO_MSG} "enabled in the kernel and linux procfs (linprocfs) filesystem"
	@${ECHO_MSG} "mounted."
	@${ECHO_MSG}
.endif
	@${ECHO_MSG} "Following port compile time options are available:"
	@${ECHO_MSG}
	@${ECHO_MSG} "    WITH_DEBUG  - install JDK binaries and libraries"
	@${ECHO_MSG} "                  with debuging support"
	@${ECHO_MSG}
	@${ECHO_MSG} "    WITH_IPV6   - enable JDK IPv6 support"
	@${ECHO_MSG}

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "WARNING: "
	@${ECHO_MSG} "WARNING: This is ALPHA quality software, and suitable for testing ONLY!"
	@${ECHO_MSG} "WARNING: "
	@${ECHO_MSG}

pre-patch:
	@cd ${WRKDIR} &&  \
		${BZIP2_CMD} -dc ${DISTDIR}/${PATCHSETFILE} | ${TAR} -xf - && \
		${CHMOD} -R u+w * && \
		${PATCH} -p0 < ${WRKDIR}/jdk15.patches

post-patch:
	@for file in ${LD_LIBRARY_PATH_FILES}; do \
		${REINPLACE_CMD} -e "s:%%LOCALBASE%%:${LOCALBASE}:" \
			${WRKSRC}/$${file}; \
	done
	@for file in ${PTHREAD_FILES}; do \
		${REINPLACE_CMD} -e "s:-pthread:${PTHREAD_LIBS}:g" \
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

do-install:
	${MKDIR} ${PREFIX}/jdk${JDK_VERSION}
	cd ${JDKIMAGEDIR} && ${FIND} . \
	  | ${CPIO} -pdmu -R ${LIBOWN}:${LIBGRP} ${PREFIX}/jdk${JDK_VERSION}
	@${ECHO_MSG} "@unexec ${LOCALBASE}/bin/unregistervm ${PREFIX}/jdk${JDK_VERSION}/bin/java" >> ${TMPPLIST}
	@${FIND} -s ${JDKIMAGEDIR} -not -type d | \
	  ${SED} -ne 's#^${JDKIMAGEDIR}#jdk${JDK_VERSION}#p' >> ${TMPPLIST}
.if defined(WITH_DEBUG)
	cd ${JDKIMAGEDIR_G} && ${FIND} . \
	  | ${CPIO} -pdmu -R ${LIBOWN}:${LIBGRP} ${PREFIX}/jdk${JDK_VERSION}
	@${FIND} -s ${JDKIMAGEDIR_G} -not -type d | \
	  ${SED} -ne 's#^${JDKIMAGEDIR}#jdk${JDK_VERSION}#p' >> ${TMPPLIST}
.endif
	@${FIND} -s -d ${PREFIX}/jdk${JDK_VERSION} -type d | \
	  ${SED} -ne 's#^${PREFIX}/#@dirrm #p' >> ${TMPPLIST}
	@${ECHO_MSG} "@exec ${LOCALBASE}/bin/registervm ${PREFIX}/jdk${JDK_VERSION}/bin/java # FREEBSD-JDK${JDK_VERSION}" >> ${TMPPLIST}

# XXX: put unregistervm into install script ?
post-install:
	@${LOCALBASE}/bin/registervm "${PREFIX}/jdk${JDK_VERSION}/bin/java # FREEBSD-JDK${JDK_VERSION}"
	@${SED} -e "s:%%JRE_HOME%%:${PREFIX}/jdk${JDK_VERSION}/jre:g" \
	  < ${FILESDIR}/pkg-install.in > ${PKGINSTALL}
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
