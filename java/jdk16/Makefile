# New ports collection makefile for:	jdk16
# Date created:				17 June 2007
# Whom:					Greg Lewis <glewis@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jdk
PORTVERSION=	${JDK_VERSION}.${JDK_UPDATE_VERSION}p${JDK_PATCHSET_VERSION}
PORTREVISION=	27
CATEGORIES=	java devel
MASTER_SITES=	# http://download.java.net/jdk6/
#		 http://www.eyesbeyond.com/freebsddom/java/jdk16.html
#		 http://java.sun.com/javase/downloads/index.jsp
DISTFILES=	${JRL_SRCFILE} ${JRL_BINFILE} ${JRL_MOZFILE} ${PATCHSETFILE}
EXTRACT_ONLY=	${JRL_SRCFILE} ${JRL_BINFILE} ${JRL_MOZFILE}

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	Java Development Kit 1.6.0

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip \
		unzip:${PORTSDIR}/archivers/unzip \
		${LOCALBASE}/lib/libXm.so:${PORTSDIR}/x11-toolkits/open-motif \
		${LOCALBASE}/include/cups/cups.h:${PORTSDIR}/print/cups-client
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

USE_ZIP=	yes
MAKE_JOBS_UNSAFE=	yes
.if !defined(PACKAGE_BUILDING)
IS_INTERACTIVE=	yes
.endif

JRL_SRCFILE=	jdk-${JDK_MAJOR_VERSION}u${JDK_UPDATE_VERSION}-fcs-src-b${JDK_BUILD_NUMBER}-jrl-${JDK_BUILD_DATE}.jar
JRL_BINFILE=	jdk-${JDK_MAJOR_VERSION}u${JDK_UPDATE_VERSION}-fcs-bin-b${JDK_BUILD_NUMBER}-jrl-${JDK_BUILD_DATE}.jar
JRL_MOZFILE=	jdk-${JDK_MAJOR_VERSION}u${JDK_UPDATE_VERSION}-fcs-mozilla_headers-b${JDK_BUILD_NUMBER}-unix-${JDK_BUILD_DATE}.jar
PATCHSETFILE=	bsd-jdk16-patches-${JDK_PATCHSET_VERSION}.tar.bz2
POLICYFILE=	jce_policy-${JDK_MAJOR_VERSION}.zip
TZUPDATEFILE=	tzupdater-${TZUPDATE_VERSION}-${TZUPDATE_TZVERSION}.zip

JDK_VERSION=	1.6.0
JDK_MAJOR_VERSION=	6
JDK_UPDATE_VERSION=	3
JDK_PATCHSET_VERSION=	4
JDK_BUILD_NUMBER=	05
JDK_BUILD_DATE=		24_sep_2007
LATEST_LINK=	jdk16

TZUPDATE_VERSION=	1_3_42
TZUPDATE_TZVERSION=	2011k

.include <bsd.port.pre.mk>

BOOTSTRAP_JDKS=	${LOCALBASE}/diablo-jdk1.6.0 \
		${LOCALBASE}/jdk1.6.0 \
		${LOCALBASE}/openjdk6

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

# do we have valid bootstrap jdk installed?
.for CJDK in ${BOOTSTRAP_JDKS}
.  if !defined(BOOTSTRAPJDKDIR) && exists(${CJDK}/bin/javac)
BOOTSTRAPJDKDIR=	${CJDK}
.  endif
.endfor

# if no valid jdk found, set dependency
.if !defined(BOOTSTRAPJDKDIR)
BOOTSTRAPJDKDIR?=	${LOCALBASE}/diablo-jdk1.6.0
BUILD_DEPENDS+=		${BOOTSTRAPJDKDIR}/bin/javac:${PORTSDIR}/java/diablo-jdk16
.endif

.if !defined(WITHOUT_WEB)
USE_GNOME=	desktopfileutils
.endif

ONLY_FOR_ARCHS=	i386 amd64
USE_GMAKE=	YES
USE_ICONV=	YES
USE_XORG+=	x11 xext xi xtst
RESTRICTED=	Redistribution of pre-compiled binaries is not permitted
NO_CDROM=	Redistribution of pre-compiled binaries is not permitted

MAKE_ENV+=	ALT_BOOTDIR="${BOOTSTRAPJDKDIR}" \
		ALT_MOTIF_DIR="${LOCALBASE}" \
		ALT_DEVTOOLS_PATH="${LOCALBASE}" \
		LANG="C" \
		LC_ALL="C" \
		JAVA_HOME="" \
		CLASSPATH="" \
		LD_LIBRARY_PATH="" \
		MAKEFLAGS="" \
		SKIP_COMPARE_IMAGES="true" \
		SKIP_FASTDEBUG_BUILD="true" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

.if defined(WITH_DEBUG)
MAKE_ENV+=	SKIP_DEBUG_BUILD="false"
.endif

.if !defined(WITH_IPV6)
MAKE_ENV+=	DONT_ENABLE_IPV6="YES"
.endif

.if !defined(DISABLE_MAKE_JOBS)
.if defined(MAKE_JOBS_NUMBER)
BUILD_JOBS_NUMBER=	${MAKE_JOBS_NUMBER}
.else
BUILD_JOBS_NUMBER=	`${SYSCTL} -n kern.smp.cpus`
.endif
MAKE_ENV+=	HOTSPOT_BUILD_JOBS=${BUILD_JOBS_NUMBER}
.endif

ALL_TARGET=	all

PLIST_FILES=	jdk${JDK_VERSION}/jre/.systemPrefs/.system.lock \
		jdk${JDK_VERSION}/jre/.systemPrefs/.systemRootModFile
.if !defined(WITHOUT_WEB)
PLIST_FILES+=	share/applications/sun-java16.desktop \
		share/applications/sun-javaws16.desktop \
		share/applications/sun-jcontrol16.desktop
.endif
PLIST_DIRS=	jdk${JDK_VERSION}/jre/.systemPrefs

.if (${ARCH} == amd64)
HOTSPOTARCH=amd64
.else
HOTSPOTARCH=i586
.endif

JDKIMAGEDIR=	${WRKSRC}/../build/bsd-${HOTSPOTARCH}/j2sdk-image
JDKIMAGEDIR_G=	${WRKSRC}/../build/bsd-${HOTSPOTARCH}/j2sdk-debug-image

LOCAL_FILES=	../../hotspot/make/jprt.config \
		../../hotspot/src/os/bsd/vm/os_bsd.cpp \
		../../j2se/src/share/classes/com/sun/java/swing/plaf/gtk/Metacity.java \
		../../j2se/src/share/classes/sun/net/www/MimeTable.java \
		../../j2se/src/share/classes/sun/net/www/protocol/doc/DocURLConnection.java \
		../../j2se/src/share/classes/sun/net/www/protocol/doc/Handler.java \
		../../j2se/src/solaris/bin/java-rmi.cgi.sh \
		../../j2se/src/solaris/bin/java_md.c \
		../../j2se/src/solaris/classes/sun/security/smartcardio/PlatformPCSC.java

X11_FILES=	../../j2se/src/share/classes/com/sun/java/swing/plaf/gtk/Metacity.java \
		../../j2se/src/solaris/native/sun/awt/fontpath.c

DESKTOP_FILES=	../../deploy/src/desktop/freedesktop/applications/sun-java.desktop \
		../../deploy/src/desktop/freedesktop/applications/sun-javaws.desktop \
		../../deploy/src/plugin/solaris/controlpanel/sun_java.desktop

# Check for JDK sources and patch file
.if !defined(PACKAGE_BUILDING) && (!exists(${DISTDIR}/${JRL_SRCFILE}) || !exists(${DISTDIR}/${JRL_BINFILE}) || !exists(${DISTDIR}/${JRL_MOZFILE}) || (defined(WITH_POLICY) && !exists(${DISTDIR}/${POLICYFILE})) || (defined(WITH_TZUPDATE) && !exists(${DISTDIR}/${TZUPDATEFILE})) || !exists(${DISTDIR}/${PATCHSETFILE}))#{
DISTFILE_INSTRUCTIONS=\n\
Due to licensing restrictions, certain files must be fetched manually.\n\n
.if !exists(${DISTDIR}/${JRL_SRCFILE}) || !exists(${DISTDIR}/${JRL_BINFILE}) || !exists(${DISTDIR}/${JRL_MOZFILE})#{
DISTFILE_INSTRUCTIONS += Please download the
.if !exists(${DISTDIR}/${JRL_SRCFILE})#{
DISTFILE_INSTRUCTIONS += Update ${JDK_UPDATE_VERSION} Source from\n\
    http://www.java.net/download/jdk6/6u${JDK_UPDATE_VERSION}/promoted/b${JDK_BUILD_NUMBER}/${JRL_SRCFILE}\n
.endif#}
.if !exists(${DISTDIR}/${JRL_BINFILE})#{
.if !exists(${DISTDIR}/${JRL_SRCFILE})#{
DISTFILE_INSTRUCTIONS += and the
.endif#}
DISTFILE_INSTRUCTIONS += Source Binaries from\n\
    http://www.java.net/download/jdk6/6u${JDK_UPDATE_VERSION}/promoted/b${JDK_BUILD_NUMBER}/${JRL_BINFILE}\n
.endif#}
.if !exists(${DISTDIR}/${JRL_MOZFILE})#{
.if !exists(${DISTDIR}/${JRL_SRCFILE}) || !exists(${DISTDIR}/${JRL_BINFILE})#{
DISTFILE_INSTRUCTIONS += and the
.endif#}
DISTFILE_INSTRUCTIONS += Mozilla Headers from\n\
    http://www.java.net/download/jdk6/6u${JDK_UPDATE_VERSION}/promoted/b${JDK_BUILD_NUMBER}/${JRL_MOZFILE}\n
.endif#}
DISTFILE_INSTRUCTIONS += .\n\n
.endif#}
.if defined(WITH_POLICY) && !exists(${DISTDIR}/${POLICYFILE})#{
DISTFILE_INSTRUCTIONS += Please open http://www.oracle.com/technetwork/java/javase/downloads/index.html\n\
in a web browser and follow the \"Download\" link for\n\
\"Java Cryptography Extension (JCE) Unlimited Strength\n\
Jurisdiction Policy Files 6\" to obtain the JCE policy file, ${POLICYFILE}.\n\n
.endif#}
.if defined(WITH_TZUPDATE) && !exists(${DISTDIR}/${TZUPDATEFILE})#{
DISTFILE_INSTRUCTIONS += Please open http://www.oracle.com/technetwork/java/javase/downloads/index.html\n\
in a web browser and follow the \"Download\" link for\n\
\"JDK DST Timezone Update Tool - ${TZUPDATE_VERSION}\" to obtain the\n\
time zone update file, ${TZUPDATEFILE}.\n\n
.endif#}
.if !exists(${DISTDIR}/${PATCHSETFILE})#{
DISTFILE_INSTRUCTIONS += Please download the patchset, ${PATCHSETFILE}, from\n\
http://www.eyesbeyond.com/freebsddom/java/jdk16.html.\n\n
.endif#}
DISTFILE_INSTRUCTIONS += Please place the downloaded file(s) in ${DISTDIR}
DISTFILE_INSTRUCTIONS += \n and restart the build.\n\n
.endif#}

pre-fetch:
	@${ECHO_MSG}
	@${ECHO_MSG} "IMPORTANT: To build the JDK 1.6.0 port, you should have at least"
	@${ECHO_MSG} "2.5Gb of free disk space in the build area!"
	@${ECHO_MSG}
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
	@${MV} ${WRKDIR}/share/plugin ${WRKDIR}/deploy/src/plugin/share/
	@${RMDIR} ${WRKDIR}/share

pre-patch:
	@cd ${WRKDIR} &&  \
		${BZIP2_CMD} -dc ${DISTDIR}/${PATCHSETFILE} | ${TAR} -xf - && \
		${CHMOD} -R u+w * && \
		${PATCH} -p0 < ${WRKDIR}/jdk16.patches

post-patch:
	@for file in ${LOCAL_FILES}; do \
		${REINPLACE_CMD} -e "s:%%LOCALBASE%%:${LOCALBASE}:" \
			${WRKSRC}/$${file}; \
	done
	@for file in ${X11_FILES}; do \
		${REINPLACE_CMD} -e "s:%%LOCALBASE%%:${LOCALBASE}:" \
			${WRKSRC}/$${file}; \
	done
	@for file in ${DESKTOP_FILES}; do \
		${REINPLACE_CMD} -e "s:%%PREFIX%%:${PREFIX}:g" \
			-e "s:%%JDK_VERSION%%:${JDK_VERSION}:g" \
			${WRKSRC}/$${file}; \
	done
	@${REINPLACE_CMD} -e "s:%%OSVERSION%%:${OSVERSION}:g" \
		${WRKSRC}/../../j2se/make/common/Defs-bsd.gmk
.if defined(WITHOUT_WEB)
	@${RM} ${WRKDIR}/deploy/make/Makefile
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
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${JDKIMAGEDIR}/jre/lib/desktop/applications/sun-java.desktop \
		${PREFIX}/share/applications/sun-java16.desktop
	${INSTALL_DATA} ${JDKIMAGEDIR}/jre/lib/desktop/applications/sun-javaws.desktop \
		${PREFIX}/share/applications/sun-javaws16.desktop
	${INSTALL_DATA} ${JDKIMAGEDIR}/jre/lib/desktop/applications/sun_java.desktop \
		${PREFIX}/share/applications/sun-jcontrol16.desktop
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
