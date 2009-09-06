# New ports collection makefile for:	jdk14
# Date created:				6 March 2003
# Whom:					Alexey Zelkin <phantom@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jdk
PORTVERSION=	${JDK_VERSION}p${JDK_PATCHSET_VERSION}
PORTREVISION=	16
CATEGORIES=	java devel
MASTER_SITES=	# http://www.sun.com/software/java2/download.html
#		 http://www.eyesbeyond.com/freebsddom/java/jdk14.html
SCSL_SRCFILE=	j2sdk-${JDK_VERSION:S/./_/g}-src-scsl.zip
SCSL_BINFILE=	j2sdk-${JDK_VERSION:S/./_/g}-bin-scsl.zip
PATCHSETFILE=	bsd-jdk14-patches-${JDK_PATCHSET_VERSION}.tar.gz
POLICYFILE=	jce_policy-${JDK_VERSION:S/./_/g}.zip
TZUPDATEFILE=	tzupdater-${TZUPDATE_VERSION}-${TZUPDATE_TZVERSION}.zip
DISTFILES=	${SCSL_SRCFILE} ${SCSL_BINFILE} ${PATCHSETFILE}

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	Java Development Kit 1.4.2

EXTRACT_DEPENDS=zip:${PORTSDIR}/archivers/zip
BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4 \
		zip:${PORTSDIR}/archivers/zip \
		${LOCALBASE}/include/nspr/prtypes.h:${PORTSDIR}/devel/nspr
RUN_DEPENDS=	javavm:${PORTSDIR}/java/javavmwrapper


OPTIONS=	DEBUG	"Enable debugging support"	off \
		IPV6	"Enable IPv6 support"		off \
		POLICY	"Install the Unlimited Strength Policy Files"	off \
		TZUPDATE	"Update the time zone data"		on \
		WEB	"Enable the browser plugin and Java Web Start"	on \
		JAIL	"Port is being built within a jail"		off

.if defined(WITH_OPENMOTIF_JDK)
BUILD_DEPENDS+=	${NONEXISTENT}:${PORTSDIR}/x11-toolkits/open-motif-jdk:extract
.else
BUILD_DEPENDS+=	${LOCALBASE}/lib/libXm.so:${PORTSDIR}/x11-toolkits/open-motif
.endif

PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
SUB_FILES+=	pkg-install \
		pkg-deinstall
SUB_LIST+=	JRE_HOME=${PREFIX}/jdk${JDK_VERSION}/jre \
		ARCH=${MACHINE_ARCH}

WRKSRC=		${WRKDIR}/control/make

JDK_VERSION=	1.4.2
JDK_PATCHSET_VERSION=	8
LATEST_LINK=	jdk14

TZUPDATE_VERSION=	1_3_18
TZUPDATE_TZVERSION=	2009k

SUN_LINUX_JDK_VERSION=  1.4.2

.if !defined(WITH_LINUX_BOOTSTRAP)
NATIVE_BOOTSTRAP_JDKS=	${LOCALBASE}/jdk1.4.2
.endif

LINUX_BOOTSTRAP_JDKS=	${LOCALBASE}/linux-sun-jdk1.4.2

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700042
BROKEN=		Does not compile with GCC 4.2
.endif

.if defined(WITH_IPV6)
CATEGORIES+=	ipv6
.endif

.if defined(WITH_POLICY)
DISTFILES+=	${POLICYFILE}
EXTRACT_ONLY+=	${POLICYFILE}
.endif

.if defined(WITH_TZUPDATE)
DISTFILES+=	${TZUPDATEFILE}
EXTRACT_ONLY+=	${TZUPDATEFILE}
.endif

.if defined(WITH_WEB)
RUN_DEPENDS+=	${LOCALBASE}/lib/X11/fonts/URW/fonts.dir:${PORTSDIR}/x11-fonts/urwfonts
.endif

.if defined(WITH_OPENMOTIF_JDK)
OPENMOTIF_DIR=	${WRKDIR}/jdkmotif
.else
OPENMOTIF_DIR=	${LOCALBASE}
.endif

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
EXTRACT_ONLY+=	${SCSL_SRCFILE} ${SCSL_BINFILE}

ONLY_FOR_ARCHS=	i386
USE_GMAKE=	YES
USE_XORG+=	x11 xext xi xmu xp xt xtst
RESTRICTED=	"Redistribution of pre-compiled binaries is not permitted"
NO_CDROM=	"Redistribution of pre-compiled binaries is not permitted"
MAKE_ENV=	ALT_BOOTDIR="${JDK14DIR}" \
		ALT_MOTIF_DIR="${OPENMOTIF_DIR}" \
		SYS_CFLAGS="${CFLAGS}" \
		DEV_ONLY="YES" \
		LANG="C" \
		JAVA_HOME="" \
		CLASSPATH="" \
		LD_LIBRARY_PATH="" \
		MAKEFLAGS=""
.if defined(WITHOUT_WEB)
MAKE_ENV+=	NO_PLUGIN="YES" \
		NO_JAVAWS="YES"
.endif
ALL_TARGET=	all

PLIST_FILES=	jdk${JDK_VERSION}/jre/.systemPrefs/.system.lock \
		jdk${JDK_VERSION}/jre/.systemPrefs/.systemRootModFile
PLIST_DIRS=	jdk${JDK_VERSION}/jre/.systemPrefs

JDKIMAGEDIR=	${WRKSRC}/../build/bsd-i586/j2sdk-image
JDKIMAGEDIR_G=	${WRKSRC}/../build/bsd-i586/j2sdk-debug-image

.if defined(WITHOUT_IPV6)
EXTRA_PATCHES+=	${PATCHDIR}/disable-ipv6.patch
.endif

.if defined(WITHOUT_WEB)
PKGNAMESUFFIX=	-minimal
.endif

LOCAL_FILES=	../../hotspot/src/os/bsd/vm/os_bsd.cpp
PTHREAD_FILES=	../../hotspot/build/bsd/makefiles/vm.make \
		../../j2se/make/common/Defs.gmk	\
		../../j2se/make/common/Program.gmk \
		../../j2se/make/common/Defs-bsd.gmk \
		../../j2se/make/java/hpi/hpi_common.gmk \
		../../j2se/make/java/hpi/native/Makefile \
		../../j2se/make/java/net/Makefile \
		../../deploy/make/common/Defs-bsd.gmk \
		../../deploy/make/plugin/common/config.gmk
X11_FILES=	../../j2se/src/solaris/native/sun/awt/fontpath.c

# Check for JDK sources and patch file
.if !defined(PACKAGE_BUILDING) && (!exists(${DISTDIR}/${SCSL_SRCFILE}) || !exists(${DISTDIR}/${SCSL_BINFILE}) || (defined(WITH_POLICY) && !exists(${DISTDIR}/${POLICYFILE})) || (defined(WITH_TZUPDATE) && !exists(${DISTDIR}/${TZUPDATEFILE})) || !exists(${DISTDIR}/${PATCHSETFILE}))#{
ECHO_MSG=/usr/bin/printf
IGNORE= :\n\
Due to licensing restrictions, certain files must be fetched manually.\n\n
.if !exists(${DISTDIR}/${SCSL_SRCFILE}) || !exists(${DISTDIR}/${SCSL_BINFILE})#{
IGNORE += Please open http://www.sun.com/software/java2/download.html\n\
in a web browser and follow the \"Download\" link for the\n\
\"Java 2 SDK ${JDK_VERSION}\".  You will be required to log in and register,\n\
but you can create an account on this page.  After registration and\n\
accepting the Sun Community Source License, download the\n
.if !exists(${DISTDIR}/${SCSL_SRCFILE})#{
IGNORE += SCSL Source file, ${SCSL_SRCFILE}
.endif#}
.if !exists(${DISTDIR}/${SCSL_BINFILE})#{
.if !exists(${DISTDIR}/${SCSL_SRCFILE})#{
IGNORE += and the\n
.endif#}
IGNORE += SCSL Binaries file, ${SCSL_BINFILE}
.endif#}
IGNORE += .\n\n
.endif#}
.if defined(WITH_POLICY) && !exists(${DISTDIR}/${POLICYFILE})#{
IGNORE += Please open http://java.sun.com/products/jce/index-14.html\n\
in a web browser and follow the \"Download JCE Unlimited Strength\n\
Jurisdiction Policy Files\" link for \"Other Downloads\" to obtain the\n\
JCE policy file, ${POLICYFILE}.\n\n
.endif#}
.if defined(WITH_TZUPDATE) && !exists(${DISTDIR}/${TZUPDATEFILE})#{
IGNORE += Please open http://java.sun.com/javase/downloads/index.jsp\n\
in a web browser and follow the \"Download\" link for\n\
\"JDK US DST Timezone Update Tool - ${TZUPDATE_VERSION}\" to obtain the\n\
time zone update file, ${TZUPDATEFILE}.\n\n
.endif#}
.if !exists(${DISTDIR}/${PATCHSETFILE})#{
IGNORE += Please download the patchset, ${PATCHSETFILE}, from\n\
http://www.eyesbeyond.com/freebsddom/java/jdk14.html.\n\n
.endif#}
IGNORE += Please place the downloaded file(s) in ${DISTDIR}
IGNORE += \n and restart the build.\n\n
.endif#}

# JDK 1.4.2 require recent version of FreeBSD due to recent libc_r updates.
# Make check for reqiuired primities as early as possible

TESTPROG=testos

check-os:
.if !defined(SKIP_OS_TEST)
	-@mkdir -p ${WRKDIR} ; \
	rm -f ${WRKDIR}/${TESTPROG} ; \
	gcc ${PTHREAD_LIBS} -o ${WRKDIR}/${TESTPROG} \
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

pre-patch:
	@cd ${WRKDIR} &&  \
		${GZIP_CMD} -dc ${DISTDIR}/${PATCHSETFILE} | ${TAR} -xf - && \
		${CHMOD} -R u+w * && \
		${PATCH} -p0 < ${WRKDIR}/jdk14.patches

post-patch:
	@for file in ${LOCAL_FILES}; do \
		${REINPLACE_CMD} -e "s:%%LOCALBASE%%:${LOCALBASE}:" \
			${WRKSRC}/$${file}; \
	done
	@for file in ${PTHREAD_FILES}; do \
		${REINPLACE_CMD} -e "s:-lkse:${PTHREAD_LIBS}:g" \
			${WRKSRC}/$${file}; \
	done
	@for file in ${X11_FILES}; do \
		${REINPLACE_CMD} -e "s:%%LOCALBASE%%:${LOCALBASE}:" \
			${WRKSRC}/$${file}; \
	done

pre-build-linuxcheck:
.if defined(WITH_LINUX_BOOTSTRAP)
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
.if !defined(WITH_JAIL)
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
.endif

pre-build:	pre-build-linuxcheck
.if defined(WITH_OPENMOTIF_JDK)
	cd ${PORTSDIR}/x11-toolkits/open-motif-jdk && \
		${MAKE} WITH_JDK_PATCH=${WRKDIR}/patch-java-dnd-fix \
		PREFIX=${OPENMOTIF_DIR} \
		NO_PKG_REGISTER=YES install
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
.if defined(WITH_TZUPDATE)
	@# Update time zones
	@-${JDKIMAGEDIR}/bin/java -jar \
		${WRKDIR}/tzupdater-${TZUPDATE_VERSION:S/_/./g}-${TZUPDATE_TZVERSION}/tzupdater.jar -u -bc
	@-${RM} -rf ${JDKIMAGEDIR}/jre/lib/zi.tzdata*
.endif

pre-install:
.if defined(WITHOUT_WEB)
	@${RM} -rf ${JDKIMAGEDIR}/demo
.endif

do-install:
	${MKDIR} ${PREFIX}/jdk${JDK_VERSION}
	cd ${JDKIMAGEDIR} && ${FIND} . \
	  | ${CPIO} -pdmu -R ${LIBOWN}:${LIBGRP} ${PREFIX}/jdk${JDK_VERSION}
	@${ECHO_MSG} "@unexec ${LOCALBASE}/bin/unregistervm ${PREFIX}/jdk${JDK_VERSION}/bin/java" >> ${TMPPLIST}
	${FIND} -s ${JDKIMAGEDIR} -not -type d | \
	  ${SED} -ne 's#${JDKIMAGEDIR}#jdk${JDK_VERSION}#p' >> ${TMPPLIST}
.if defined(WITH_DEBUG)
	cd ${JDKIMAGEDIR_G} && ${FIND} . \
	  | ${CPIO} -pdmu -R ${LIBOWN}:${LIBGRP} ${PREFIX}/jdk${JDK_VERSION}
	${FIND} -s ${JDKIMAGEDIR_G} -not -type d | \
	  ${SED} -ne 's#${JDKIMAGEDIR_G}#jdk${JDK_VERSION}#p' >> ${TMPPLIST}
.endif
	${INSTALL_DATA} ${FILESDIR}/cacerts \
		${PREFIX}/jdk${JDK_VERSION}/jre/lib/security/cacerts
.if defined(WITH_POLICY)
	${INSTALL_DATA} ${WRKDIR}/jce/*.jar ${PREFIX}/jdk${JDK_VERSION}/jre/lib/security
.endif
.if defined(WITH_WEB)
	${INSTALL_DATA} ${FILESDIR}/cacerts \
		${PREFIX}/jdk${JDK_VERSION}/jre/javaws/cacerts
.endif
	@${FIND} -s -d ${PREFIX}/jdk${JDK_VERSION} -type d | \
	  ${SED} -ne 's#^${PREFIX}/#@dirrm #p' >> ${TMPPLIST}
	@${ECHO_MSG} "@exec ${LOCALBASE}/bin/registervm ${PREFIX}/jdk${JDK_VERSION}/bin/java # FREEBSD-JDK${JDK_VERSION}" >> ${TMPPLIST}

post-install:
.if defined(WITH_WEB)
	${FIND} "${PREFIX}/jdk${JDK_VERSION}/jre/plugin" -type d | ${XARGS} ${CHMOD} a+rx
.endif
	@${LOCALBASE}/bin/registervm "${PREFIX}/jdk${JDK_VERSION}/bin/java # FREEBSD-JDK${JDK_VERSION}"
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
