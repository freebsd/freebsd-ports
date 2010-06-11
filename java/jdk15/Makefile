# New ports collection makefile for:	jdk15
# Date created:				12 January 2005
# Whom:					Alexey Zelkin <phantom@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jdk
PORTVERSION=	${JDK_VERSION}.${JDK_UPDATE_VERSION}p${JDK_PATCHSET_VERSION}
PORTREVISION=	6
PORTEPOCH=	1
CATEGORIES=	java devel
MASTER_SITES=	# http://download.java.net/tiger/
#		 http://www.eyesbeyond.com/freebsddom/java/jdk15.html
#		 http://java.sun.com/javase/downloads/index.jsp
DISTFILES=	${JRL_SRCFILE} ${JRL_BINFILE} ${PATCHSETFILE}
EXTRACT_ONLY=	${JRL_SRCFILE} ${JRL_BINFILE}

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	Java Development Kit 1.5.0

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4 \
		zip:${PORTSDIR}/archivers/zip \
		${LOCALBASE}/lib/libXm.so:${PORTSDIR}/x11-toolkits/open-motif
RUN_DEPENDS=	javavm:${PORTSDIR}/java/javavmwrapper

OPTIONS=	DEBUG	"Enable debugging support"	off \
		IPV6	"Enable IPv6 support"		off \
		WEB	"Enable the browser plugin and Java Web Start"	on \
		POLICY	"Install the Unlimited Strength Policy Files"	off \
		TZUPDATE	"Update the time zone data"		on \
		JAIL	"Port is being built within a jail"		off

WANT_GNOME=	yes
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
SUB_FILES+=	pkg-install \
		pkg-deinstall
SUB_LIST+=	JRE_HOME=${PREFIX}/jdk${JDK_VERSION}/jre \
		ARCH=${MACHINE_ARCH}

WRKSRC=		${WRKDIR}/control/make

USE_ZIP=	YES

JRL_SRCFILE=	jdk-${JDK_VERSION:S/./_/g}_${JDK_UPDATE_VERSION}-fcs-src-b${JDK_BUILD_NUMBER}-jrl-${JDK_BUILD_DATE}.jar
JRL_BINFILE=	jdk-${JDK_VERSION:S/./_/g}_${JDK_UPDATE_VERSION}-fcs-bin-b${JDK_BUILD_NUMBER}-jrl-${JDK_BUILD_DATE}.jar
PATCHSETFILE=	bsd-jdk15-patches-${JDK_PATCHSET_VERSION}.tar.bz2
POLICYFILE=	jce_policy-${JDK_VERSION:S/./_/g}.zip
TZUPDATEFILE=	tzupdater-${TZUPDATE_VERSION}-${TZUPDATE_TZVERSION}.zip

JDK_VERSION=	1.5.0
JDK_UPDATE_VERSION=	16
JDK_PATCHSET_VERSION=	9
JDK_BUILD_NUMBER=	02
JDK_BUILD_DATE=		28_may_2008
LATEST_LINK=	jdk15

TZUPDATE_VERSION=	1_3_29
TZUPDATE_TZVERSION=	2010f

.include <bsd.port.pre.mk>

.if !defined(WITH_LINUX_BOOTSTRAP)
NATIVE_BOOTSTRAP_JDKS=	${LOCALBASE}/diablo-jdk1.6.0 \
			${LOCALBASE}/diablo-jdk1.5.0 \
			${LOCALBASE}/jdk1.5.0 \
			${LOCALBASE}/jdk1.6.0 \
			${LOCALBASE}/jdk1.4.2
.endif

LINUX_BOOTSTRAP_JDKS=	${LOCALBASE}/linux-sun-jdk1.5.0 \
			${LOCALBASE}/linux-sun-jdk1.6.0 \
			${LOCALBASE}/linux-sun-jdk1.4.2

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

# do we have valid native jdk installed?
.if !defined(WITH_LINUX_BOOTSTRAP)
.for CJDK in ${NATIVE_BOOTSTRAP_JDKS}
.  if !defined(BOOTSTRAPJDKDIR) && exists(${CJDK}/bin/javac)
BOOTSTRAPJDKDIR=	${CJDK}
.  endif
.endfor
.endif

# do we have valid linux jdk installed?
.if !defined(BOOTSTRAPJDKDIR)
.for CJDK in ${LINUX_BOOTSTRAP_JDKS}
.  if !defined(BOOTSTRAPJDKDIR) && exists(${CJDK}/bin/javac)
BOOTSTRAPJDKDIR=	${CJDK}
WITH_LINUX_BOOTSTRAP=	YES
.  endif
.endfor
.endif

# if no valid jdk found, set dependency
.if !defined(BOOTSTRAPJDKDIR) || !exists(${BOOTSTRAPJDKDIR}/bin/javac)
BOOTSTRAPJDKDIR=	${LOCALBASE}/diablo-jdk1.6.0
BUILD_DEPENDS+=		${BOOTSTRAPJDKDIR}/bin/javac:${PORTSDIR}/java/diablo-jdk16
.endif

.if defined(WITHOUT_WEB)
MAKE_ENV+=	DONT_BUILD_DEPLOY="YES"
.else
USE_GNOME=	desktopfileutils
LIB_DEPENDS=    nspr4.1:$(PORTSDIR)/devel/nspr
.endif

ONLY_FOR_ARCHS=	i386 amd64
USE_GMAKE=	YES
USE_ICONV=	YES
USE_XORG+=	x11 xext xi xmu xp xt xtst
RESTRICTED=	Redistribution of pre-compiled binaries is not permitted
NO_CDROM=	Redistribution of pre-compiled binaries is not permitted

MAKE_ENV+=	ALT_BOOTDIR="${BOOTSTRAPJDKDIR}" \
		ALT_MOTIF_DIR="${LOCALBASE}" \
		X11DIR="${LOCALBASE}" \
		LOCALDIR="${LOCALBASE}" \
		DEFAULT_LD_LIBRARY_PATH="/usr/lib:${LOCALBASE}/lib" \
		SYS_CFLAGS="${CFLAGS}" \
		LANG="C" \
		JAVA_HOME="" \
		CLASSPATH="" \
		LD_LIBRARY_PATH="" \
		MAKEFLAGS="" \
		SKIP_COMPARE_IMAGES="YES"
.if !defined(WITH_IPV6)
MAKE_ENV+=	DONT_ENABLE_IPV6="YES"
.endif
.if defined(HOTSPOT_BUILD_JOBS)
MAKE_ENV+=	HOTSPOT_BUILD_JOBS=${HOTSPOT_BUILD_JOBS}
.endif

ALL_TARGET=	all

PLIST_FILES=	jdk${JDK_VERSION}/jre/.systemPrefs/.system.lock \
		jdk${JDK_VERSION}/jre/.systemPrefs/.systemRootModFile
.if !defined(WITHOUT_WEB)
PLIST_FILES+=	share/applications/sun_java15.desktop
.endif
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
X11_FILES=	../../j2se/src/share/classes/com/sun/java/swing/plaf/gtk/GTKLookAndFeel.java \
		../../j2se/src/share/classes/com/sun/java/swing/plaf/gtk/Metacity.java

# Check for JDK sources and patch file
.if !defined(PACKAGE_BUILDING) && (!exists(${DISTDIR}/${JRL_SRCFILE}) || !exists(${DISTDIR}/${JRL_BINFILE}) || (defined(WITH_POLICY) && !exists(${DISTDIR}/${POLICYFILE})) || (defined(WITH_TZUPDATE) && !exists(${DISTDIR}/${TZUPDATEFILE})) || !exists(${DISTDIR}/${PATCHSETFILE}))#{
DISTFILE_INSTRUCTIONS=\n\
Due to licensing restrictions, certain files must be fetched manually.\n\n
.if !exists(${DISTDIR}/${JRL_SRCFILE}) || !exists(${DISTDIR}/${JRL_BINFILE})#{
DISTFILE_INSTRUCTIONS += Please open http://download.java.net/tiger/\n\
in a web browser.  Download the\n
.if !exists(${DISTDIR}/${JRL_SRCFILE})#{
DISTFILE_INSTRUCTIONS += Update ${JDK_UPDATE_VERSION} Source, ${JRL_SRCFILE}
.endif#}
.if !exists(${DISTDIR}/${JRL_BINFILE})#{
.if !exists(${DISTDIR}/${JRL_SRCFILE})#{
DISTFILE_INSTRUCTIONS += and the\n
.endif#}
DISTFILE_INSTRUCTIONS += Source Binaries, ${JRL_BINFILE}
.endif#}
DISTFILE_INSTRUCTIONS += .\n\n
.endif#}
.if defined(WITH_POLICY) && !exists(${DISTDIR}/${POLICYFILE})#{
DISTFILE_INSTRUCTIONS += Please open http://java.sun.com/javase/downloads/index_jdk5.jsp\n\
in a web browser and follow the \"Download\" link for\n\
\"Java Cryptography Extension (JCE) Unlimited Strength Jurisdiction Policy\n\
Files 5.0\" to obtain the JCE policy file, ${POLICYFILE}.\n\n
.endif#}
.if defined(WITH_TZUPDATE) && !exists(${DISTDIR}/${TZUPDATEFILE})#{
DISTFILE_INSTRUCTIONS += Please open http://java.sun.com/javase/downloads/index.jsp\n\
in a web browser and follow the \"Download\" link for\n\
\"JDK US DST Timezone Update Tool - ${TZUPDATE_VERSION}\" to obtain the\n\
time zone update file, ${TZUPDATEFILE}.\n\n
.endif#}
.if !exists(${DISTDIR}/${PATCHSETFILE})#{
DISTFILE_INSTRUCTIONS += Please download the patchset, ${PATCHSETFILE}, from\n\
http://www.eyesbeyond.com/freebsddom/java/jdk15.html.\n\n
.endif#}
DISTFILE_INSTRUCTIONS += Please place the downloaded file(s) in ${DISTDIR}
DISTFILE_INSTRUCTIONS += \n and restart the build.\n\n
.endif#}

pre-fetch:
	@${ECHO_MSG}
	@${ECHO_MSG} "IMPORTANT: To build the JDK 1.5.0 port, you should have at least"
	@${ECHO_MSG} "2.5Gb of free disk space in the build area!"
	@${ECHO_MSG}
.if defined(WITH_LINUX_BOOTSTRAP)
	@${ECHO_MSG} "IMPORTANT: To build the JDK 1.5.0 port, you should have linux emulation"
	@${ECHO_MSG} "enabled in the kernel and the linux procfs (linprocfs) filesystem"
	@${ECHO_MSG} "mounted."
	@${ECHO_MSG}
.endif
.if defined(DISTFILE_INSTRUCTIONS)
	@${PRINTF} "${DISTFILE_INSTRUCTIONS}"
	@exit 1
.endif

# Get JRL agreement
.if !defined(PACKAGE_BUILDING)
pre-extract:
	${SH} ${FILESDIR}/license.sh
.endif

# Extract the files
do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@${CC} ${CFLAGS} -o ${WRKDIR}/x_x2zip ${FILESDIR}/x_x2zip.c
	@for file in ${EXTRACT_ONLY}; do \
		if ! (cd ${WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} "${DISTDIR}/$$file" ${EXTRACT_AFTER_ARGS}); \
		then \
			exit 1; \
		fi; \
		if [ `basename $$file .jar` != $$file ]; \
		then \
			if ! (cd ${WRKDIR} && ${WRKDIR}/x_x2zip 'YES I ACCEPT THE CLICK THROUGH LICENSE.  ' X_X && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${WRKDIR}/X_X.zip ${EXTRACT_AFTER_ARGS}); \
			then \
				exit 1; \
			fi; \
		fi \
	done

post-extract:
	cd ${WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		j2se/make/tools/crypto/pkcs11/sunpkcs11_src.zip \
		${EXTRACT_AFTER_ARGS}
	-${MKDIR} ${WRKDIR}/j2se/make/sun/security
	-${MKDIR} ${WRKDIR}/j2se/src/share/classes/sun/security
	-${MKDIR} ${WRKDIR}/j2se/src/share/native/sun/security
	-${MKDIR} ${WRKDIR}/j2se/src/solaris/native/sun/security
	${MV} ${WRKDIR}/make/sun/security/pkcs11 \
		${WRKDIR}/j2se/make/sun/security/pkcs11
	${MV} ${WRKDIR}/src/share/classes/sun/security/pkcs11 \
		${WRKDIR}/j2se/src/share/classes/sun/security/pkcs11
	${MV} ${WRKDIR}/src/share/native/sun/security/pkcs11 \
		${WRKDIR}/j2se/src/share/native/sun/security/pkcs11
	${MV} ${WRKDIR}/src/solaris/native/sun/security/pkcs11 \
		${WRKDIR}/j2se/src/solaris/native/sun/security/pkcs11
	cd ${WRKDIR} && ${RM} -rf src

pre-patch:
	@cd ${WRKDIR} &&  \
		${BZIP2_CMD} -dc ${DISTDIR}/${PATCHSETFILE} | ${TAR} -xf - && \
		${CHMOD} -R u+w * && \
		${PATCH} -p0 < ${WRKDIR}/jdk15.patches

post-patch:
	@for file in ${PTHREAD_FILES}; do \
		${REINPLACE_CMD} -e "s:-pthread:${PTHREAD_LIBS}:g" \
			${WRKSRC}/$${file}; \
	done
	@for file in ${X11_FILES}; do \
		${REINPLACE_CMD} -e "s:%%LOCALBASE%%:${LOCALBASE}:" \
			${WRKSRC}/$${file}; \
	done
	@${REINPLACE_CMD} -e "s:%%PREFIX%%:${PREFIX}:g" \
		-e "s:%%JDK_VERSION%%:${JDK_VERSION}:g"\
		${WRKSRC}/../../deploy/src/plugin/solaris/controlpanel/sun_java.desktop
	@${REINPLACE_CMD} -e "s:%%OSVERSION%%:${OSVERSION}:g" \
		${WRKSRC}/../../j2se/make/common/Defs-bsd.gmk

.if defined(WITH_LINUX_BOOTSTRAP)
pre-build:
	@if [ "$${WRKDIRPREFIX}" -a \
	     -L "/compat/linux/$${WRKDIRPREFIX}" -a \
	     x`${LS} -ld "/compat/linux/$${WRKDIRPREFIX}" 2>/dev/null | ${AWK} '/->/{print $$NF;exit 0}END{exit 1}'` = x"$${WRKDIRPREFIX}" ]; \
	then \
		${ECHO_MSG} "Please set WRKDIRPREFIX to something which doesn't"; \
		${ECHO_MSG} "have a matching symbolic link in /compat/linux."; \
		${ECHO_MSG} "This is known to cause problems during bootstrapping."; \
		exit 1; \
	fi
	@if [ `${SYSCTL} -n compat.linux.osname` != "Linux" ]; \
	then \
		${ECHO_MSG} "Please set the value of the sysctl compat.linux.osname"; \
		${ECHO_MSG} "to 'Linux' with the command:"; \
		${ECHO_MSG} "	${SYSCTL} compat.linux.osname=Linux"; \
		${ECHO_MSG} "Having it set to other values, such as 'FreeBSD',"; \
		${ECHO_MSG} "is known to cause problems during bootstrapping."; \
		exit 1; \
	fi
.if !defined(WITH_JAIL)#{
	@if [ "`/sbin/mount | ${GREP} ^linprocfs`" = "" ]; \
	then \
		${ECHO_MSG} "ERROR: You must have LINPROCFS mounted before" ; \
		${ECHO_MSG} "starting to build the native JDK 1.5.0." ; \
		${ECHO_MSG} "" ; \
		${ECHO_MSG} "You may do it with the following commands:" ; \
		${ECHO_MSG} "" ; \
		${ECHO_MSG} "# kldload linprocfs" ; \
		${ECHO_MSG} "" ; \
		${ECHO_MSG} "and" ; \
		${ECHO_MSG} "" ; \
		${ECHO_MSG} "# mount -t linprocfs linprocfs /compat/linux/proc" ; \
		${ECHO_MSG} "" ; \
		exit 1 ; \
	fi
.endif#}
.endif

do-build:
	# Start of jdk build
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})

post-build:
	@# XXX don't install japanese manpages
	@${RM} -rf ${JDKIMAGEDIR}/man/ja
	@${RM} -rf ${JDKIMAGEDIR}/man/ja_JP.eucJP
.if defined(WITH_TZUPDATE)
	@# Update time zones
	@-${JDKIMAGEDIR}/bin/java -jar \
		${WRKDIR}/tzupdater-${TZUPDATE_VERSION:S/_/./g}-${TZUPDATE_TZVERSION}/tzupdater.jar -u -bc
	@-${RM} -rf ${JDKIMAGEDIR}/jre/lib/zi.tzdata*
.endif

do-install:
	${MKDIR} ${PREFIX}/jdk${JDK_VERSION}
	cd ${JDKIMAGEDIR} && ${FIND} . \
	  | ${CPIO} -pdmu -R ${LIBOWN}:${LIBGRP} ${PREFIX}/jdk${JDK_VERSION}
.if !defined(WITHOUT_WEB)
	${INSTALL_DATA} ${JDKIMAGEDIR}/jre/plugin/desktop/sun_java.desktop \
		${PREFIX}/share/applications/sun_java15.desktop
.endif
	@${ECHO_MSG} "@unexec ${LOCALBASE}/bin/unregistervm ${PREFIX}/jdk${JDK_VERSION}/bin/java" >> ${TMPPLIST}
	@${FIND} -s ${JDKIMAGEDIR} -not -type d | \
	  ${SED} -ne 's#^${JDKIMAGEDIR}#jdk${JDK_VERSION}#p' >> ${TMPPLIST}
.if !defined(WITHOUT_WEB)
	@${ECHO_MSG} '@exec ${LOCALBASE}/bin/update-desktop-database > /dev/null || /usr/bin/true' >> ${TMPPLIST}
.endif
.if defined(WITH_DEBUG)
	cd ${JDKIMAGEDIR_G} && ${FIND} . \
	  | ${CPIO} -pdmu -R ${LIBOWN}:${LIBGRP} ${PREFIX}/jdk${JDK_VERSION}
	@${FIND} -s ${JDKIMAGEDIR_G} -not -type d | \
	  ${SED} -ne 's#^${JDKIMAGEDIR_G}#jdk${JDK_VERSION}#p' >> ${TMPPLIST}
.endif
	${INSTALL_DATA} ${FILESDIR}/cacerts \
	  ${PREFIX}/jdk${JDK_VERSION}/jre/lib/security/cacerts
.if defined(WITH_POLICY)
	${INSTALL_DATA} ${WRKDIR}/jce/*.jar ${PREFIX}/jdk${JDK_VERSION}/jre/lib/security
.endif
	@${FIND} -s -d ${PREFIX}/jdk${JDK_VERSION} -type d | \
	  ${SED} -ne 's#^${PREFIX}/#@dirrm #p' >> ${TMPPLIST}
	@${ECHO_MSG} "@exec ${LOCALBASE}/bin/registervm ${PREFIX}/jdk${JDK_VERSION}/bin/java # FREEBSD-JDK${JDK_VERSION}" >> ${TMPPLIST}
.if !defined(WITHOUT_WEB)
	@${ECHO_MSG} '@unexec ${LOCALBASE}/bin/update-desktop-database > /dev/null || /usr/bin/true' >> ${TMPPLIST}
.endif

# XXX: put unregistervm into install script ?
post-install:
	@${LOCALBASE}/bin/registervm "${PREFIX}/jdk${JDK_VERSION}/bin/java # FREEBSD-JDK${JDK_VERSION}"
.if !defined(WITHOUT_WEB)
	@-update-desktop-database
.endif
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
