# New ports collection makefile for:    openjdk6
# Date created:         2009/2/21
# Whom:                 Brian Gardner <brian@experts-exchange.com>
#
# $FreeBSD$
#

PORTNAME=	openjdk6
PORTVERSION=	b21
PORTREVISION=	3
CATEGORIES=	java devel
MASTER_SITES=	http://download.java.net/openjdk/jdk6/promoted/${PORTVERSION}/ \
		https://java.net/downloads/jaxp/jdk7/:jaxp \
		https://java.net/downloads/jax-ws/OpenJDK6/:jaxws \
		https://java.net/downloads/jax-ws/OpenJDK6/:jaf \
		http://icedtea.classpath.org/builds/icedtea6/src/ \
		http://icedtea.classpath.org/download/drops/:jaxp \
		http://icedtea.classpath.org/download/drops/:jaxws \
		http://icedtea.classpath.org/download/drops/:jaf \
		${MASTER_SITE_APACHE:S,%SUBDIR%/,ant/binaries/:ant,} \
		http://icedtea.classpath.org/download/source/:itweb \
		http://download.java.net/openjdk/jtreg/promoted/${JTREGVERSION}/:jtreg
DISTNAME=	openjdk-6-src-${PORTVERSION}-${OPENJDK_BUILDDATE}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${JAXPFILE}:jaxp \
		${JAXWSFILE}:jaxws \
		${JAFFILE}:jaf \
		${ANTFILE}:ant
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX} ${ANTFILE}

MAINTAINER=	java@FreeBSD.org
COMMENT=	Oracle's Java 6 virtual machine release under the GPL v2

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip \
		unzip:${PORTSDIR}/archivers/unzip \
		${LOCALBASE}/include/cups/cups.h:${PORTSDIR}/print/cups-client
LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2
RUN_DEPENDS=	javavm:${PORTSDIR}/java/javavmwrapper \
		${LOCALBASE}/lib/X11/fonts/dejavu:${PORTSDIR}/x11-fonts/dejavu

LICENSE=	GPLv2

OPENJDK_BUILDDATE=	20_jan_2011

OPTIONS=	DEBUG "Enable legacy debugging support" off \
		FASTDEBUG "Include fastdebug build" off \
		IPV6 "Enable IPv6 support" off \
		SOUND "Enable sound support" off \
		WEB "Enable the browser plugin and Java Web Start" off \
		POLICY "Install the Unlimited Strength Policy Files" off \
		TEST "Add support for running regression test" off

# java extracts directly to the cwd
WRKSRC=		${WRKDIR}

USE_GMAKE=	yes
USE_MOTIF=	yes
USE_XORG=	xtst xi xt x11
MAKE_JOBS_UNSAFE=	yes

JAXP_BUILD=	1_4_4
JAXPFILE=	jaxp-${JAXP_BUILD}.zip
JAXWS_BUILD=	b20
JAXWSFILE=	jdk6-jaxws-${JAXWS_BUILD}.zip
JAF_BUILD=	b20
JAFFILE=	jdk6-jaf-${JAF_BUILD}.zip
ITWEBVERSION=	1.0.1
ITWEBFILE=	icedtea-web-${ITWEBVERSION}${EXTRACT_SUFX}
JTREGVERSION=	b02
JTREGFILE=	jtreg-4.1-bin-${JTREGVERSION}_21_may_2010.zip

# do not depend on devel/apache-ant to avoid circular dependency, but
# use .tar.bz2 distfile to avoid duplicated downloads
ANTVERSION=	1.8.2
ANTFILE=	apache-ant-${ANTVERSION}-bin.tar.bz2

# rely on bsdtar ability to extract .gz, .bz2 and .zip archives
EXTRACT_CMD=	${CAT}
EXTRACT_BEFORE_ARGS=

.include <bsd.port.pre.mk>

.if defined(WITH_IPV6)
CATEGORIES+=	ipv6
.endif

# avoid ARCH in MAKEFLAGS, breaks build
NOPRECIOUSMAKEVARS=	yes

ONLY_FOR_ARCHS=	amd64 i386

BOOTSTRAP_JDKS=	${LOCALBASE}/openjdk6 \
		${LOCALBASE}/jdk1.6.0 \
		${LOCALBASE}/diablo-jdk1.6.0

# do we have valid native jdk installed?
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

MAKE_ENV=	LANG=C LC_ALL=C \
		ARCH=${ARCH} \
		ARCH_DATA_MODEL=64 \
		LIBARCH=${ARCH} \
		PLATFORM=bsd \
		OS_NAME=freebsd \
		ALT_JDK_IMPORT_PATH=${BOOTSTRAPJDKDIR} \
		ALT_BOOTDIR=${BOOTSTRAPJDKDIR} \
		ALT_CACERTS_FILE=${FILESDIR}/cacerts \
		ALT_CUPS_HEADERS_PATH=${LOCALBASE}/include \
		ALT_CUPS_LIB_PATH=${LOCALBASE}/lib \
		ALT_FREETYPE_HEADERS_PATH=${LOCALBASE}/include \
		ALT_FREETYPE_LIB_PATH=${LOCALBASE}/lib \
		ALT_X11_PATH=${LOCALBASE} \
		ALT_PACKAGE_PATH=${LOCALBASE} \
		ALT_DROPS_DIR=${DISTDIR} \
		ANT_HOME=${WRKDIR}/apache-ant-${ANTVERSION} \
		BUILD_NUMBER=${PORTVERSION} \
		NO_DOCS=true \
		MILESTONE=fcs

# disable FASTDEBUG_BUILD by default to improve compile time.
.if defined(WITH_FASTDEBUG)
MAKE_ENV+=	SKIP_FASTDEBUG_BUILD=false
.else
MAKE_ENV+=	SKIP_FASTDEBUG_BUILD=true
.endif

.if !defined(WITH_IPV6)
MAKE_ENV+=	DONT_ENABLE_IPV6="YES"
.endif

.if defined(WITH_DEBUG)
ALL_TARGET=	debug_build
OPENJDK_OSARCH=	bsd-${ARCH:S/i386/i586/}-debug
.else
OPENJDK_OSARCH=	bsd-${ARCH:S/i386/i586/}
.endif

.if defined(WITH_SOUND)
EXTRA_PATCHES+=	${FILESDIR}/alsa-enable.patch
LIB_DEPENDS+=	asound.2:${PORTSDIR}/audio/alsa-lib
RUN_DEPENDS+=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:${PORTSDIR}/audio/alsa-plugins
.else
EXTRA_PATCHES+=	${FILESDIR}/alsa-disable.patch
.endif

.if defined(WITH_WEB)
DISTFILES+=	${ITWEBFILE}:itweb
EXTRACT_ONLY+=	${ITWEBFILE}
EXTRA_PATCHES+=	${FILESDIR}/plugin.patch
BUILD_DEPENDS+=	${LOCALBASE}/bin/pkg-config:${PORTSDIR}/devel/pkg-config \
		${LOCALBASE}/libdata/pkgconfig/glib-2.0.pc:${PORTSDIR}/devel/glib20 \
		${LOCALBASE}/libdata/pkgconfig/gtk+-2.0.pc:${PORTSDIR}/x11-toolkits/gtk20 \
		${LOCALBASE}/libdata/pkgconfig/mozilla-plugin.pc:${PORTSDIR}/www/libxul
ITWEBDIR=	${WRKDIR}/icedtea-web-${ITWEBVERSION}
ITWEB_JAVAC=	${WRKSRC}/build/${OPENJDK_OSARCH}/j2sdk-image/bin/javac
ITWEB_JAR=	${WRKSRC}/build/${OPENJDK_OSARCH}/j2sdk-image/bin/jar
.if defined(WITH_DEBUG)
ITWEB_DEBUG_FLAGS=-g
.endif
ITWEB_JAVAC_FLAGS=${ITWEB_DEBUG_FLAGS} -encoding utf-8 -J-Xmx1024m -source 6 -target 6
.endif

.if defined(WITH_TEST)
DISTFILES+=	${JTREGFILE}:jtreg
EXTRACT_ONLY+=	${JTREGFILE}
BUILD_DEPENDS+=	${LOCALBASE}/lib/X11/fonts/dejavu:${PORTSDIR}/x11-fonts/dejavu
USE_DISPLAY=	yes
.endif

.if !defined(DISABLE_MAKE_JOBS)
.if defined(MAKE_JOBS_NUMBER)
BUILD_JOBS_NUMBER=	${MAKE_JOBS_NUMBER}
.else
BUILD_JOBS_NUMBER=	`${SYSCTL} -n kern.smp.cpus`
.endif
MAKE_ENV+=	HOTSPOT_BUILD_JOBS=${BUILD_JOBS_NUMBER}
.endif

COPYDIRS=	\
	hotspot/src/os/linux/launcher \
	hotspot/src/os/linux/vm \
	hotspot/src/os_cpu/linux_x86/vm \
	hotspot/agent/src/os/linux \
	hotspot/make/linux \
	hotspot/make/linux/makefiles \
	hotspot/agent/src/share/classes/sun/jvm/hotspot/debugger/linux \
	hotspot/agent/src/share/classes/sun/jvm/hotspot/debugger/linux/amd64 \
	hotspot/agent/src/share/classes/sun/jvm/hotspot/debugger/linux/x86 \
	hotspot/agent/src/share/classes/sun/jvm/hotspot/runtime/linux \
	hotspot/agent/src/share/classes/sun/jvm/hotspot/runtime/linux_amd64 \
	hotspot/agent/src/share/classes/sun/jvm/hotspot/runtime/linux_x86 \
	jdk/src/linux/doc/man

COPYFILES=	\
	corba/make/common/Defs-linux.gmk \
	corba/make/common/shared/Defs-linux.gmk \
	hotspot/agent/src/share/classes/sun/jvm/hotspot/LinuxVtblAccess.java \
	jdk/make/com/sun/tools/attach/mapfile-linux \
	jdk/make/common/Defs-linux.gmk \
	jdk/make/common/shared/Defs-linux.gmk \
	jdk/make/java/nio/mapfile-linux \
	jdk/make/netbeans/common/architectures/name-Linux.properties \
	jdk/make/sun/awt/mapfile-vers-linux \
	jdk/make/tools/sharing/classlist.linux \
	jdk/src/solaris/classes/java/lang/UNIXProcess.java.linux \
	jdk/src/solaris/classes/sun/tools/attach/LinuxAttachProvider.java \
	jdk/src/solaris/classes/sun/tools/attach/LinuxVirtualMachine.java \
	jdk/src/solaris/hpi/include/largefile_linux.h \
	jdk/src/solaris/native/java/net/linux_close.c \
	jdk/src/solaris/native/sun/tools/attach/LinuxVirtualMachine.c

post-extract:
	@for d in ${COPYDIRS}; do \
		${MKDIR} `echo ${WRKDIR}/$$d | ${SED} 's/linux/bsd/g;'`; \
		cd ${WRKDIR}/$$d; \
		for f in *; do \
			if [ -f $$f ]; then \
				t=`echo ${WRKDIR}/$$d/$$f | ${SED} 's/linux/bsd/g; s/Linux/Bsd/g'`; \
				${SED} 's/linux/bsd/g; s/Linux/Bsd/g' < $$f > $$t; \
			fi; \
		done; \
	done
	@for f in ${COPYFILES}; do \
		t=`echo $$f | ${SED} 's/linux/bsd/g; s/Linux/Bsd/g'`; \
		${SED} 's/linux/bsd/g; s/Linux/Bsd/g' < ${WRKDIR}/$$f > ${WRKDIR}/$$t; \
	done
	@${SED} 's/solaris/bsd/g; s/Solaris/Bsd/g' \
		< ${WRKDIR}/jdk/src/solaris/hpi/native_threads/src/threads_solaris.c \
		> ${WRKDIR}/jdk/src/solaris/hpi/native_threads/src/threads_bsd.c
	@${SED} "s|/usr/local|${LOCALBASE}|" < ${FILESDIR}/fontconfig.properties \
		> ${WRKDIR}/jdk/src/solaris/classes/sun/awt/fontconfigs/bsd.fontconfig.properties
	@${SED} "s|%%LOCALBASE%%|${LOCALBASE}|" < ${FILESDIR}/Makefile.test \
		> ${WRKDIR}/jdk/test/Makefile
	@${FIND} ${WRKDIR}/jdk/test -type f -name \*.sh -exec ${SED} -i "" -e s/Linux/FreeBSD/g {} \;

post-patch:
	@${REINPLACE_CMD} "s|/lib:/usr/lib|/lib:/usr/lib:${LOCALBASE}/lib|" \
		${WRKDIR}/hotspot/src/os/bsd/vm/os_bsd.cpp
.if defined(WITH_POLICY)
	@${REINPLACE_CMD} 's|build-policy install-limited|build-policy install-unlimited|' \
		${WRKSRC}/jdk/make/javax/crypto/Makefile
.endif

.if defined(WITH_WEB) || defined(WITH_TEST)
post-build:
.if defined(WITH_WEB)
	@${MKDIR} ${ITWEBDIR}/build/lib
	@( \
		cd ${ITWEBDIR}/plugin/icedteanp; \
		${MAKE} -f ${FILESDIR}/Makefile.plugin depend all install \
		    DEBUG_FLAGS="${ITWEB_DEBUG_FLAGS}" \
		    LIBDIR=${ITWEBDIR}/build/lib \
		    LIBOWN=${UID} \
		    LIBGRP=`${ID} -g` \
		    LOCALBASE=${LOCALBASE} \
		    JDK_UPDATE_VERSION=${PORTVERSION:S/^b//} \
		    PLUGIN_VERSION="IcedTea-Web ${ITWEBVERSION}" \
	)
	@${FIND} -s ${ITWEBDIR}/netx -name '*.java' > \
	    ${ITWEBDIR}/netx-source-files.txt
	@${MKDIR} ${ITWEBDIR}/netx.build/lib
	@${ITWEB_JAVAC} ${ITWEB_JAVAC_FLAGS} -d ${ITWEBDIR}/netx.build \
	    @${ITWEBDIR}/netx-source-files.txt
	@${CP} -r ${ITWEBDIR}/netx/net/sourceforge/jnlp/resources \
	    ${ITWEBDIR}/netx.build/net/sourceforge/jnlp
	@( \
		cd ${ITWEBDIR}/netx.build; \
		${ITWEB_JAR} cf ${ITWEBDIR}/build/lib/netx.jar \
		    javax/jnlp net \
	)
	@( \
		cd ${ITWEBDIR}/netx; \
		${ITWEB_JAR} uf ${ITWEBDIR}/build/lib/netx.jar \
		    `${FIND} . -type f -not -name '*.java'` \
	)
	@${CP} ${ITWEBDIR}/netx/net/sourceforge/jnlp/resources/about.jnlp \
	    ${ITWEBDIR}/build/lib
	@${FIND} -s ${ITWEBDIR}/plugin/icedteanp/java -name '*.java' > \
	    ${ITWEBDIR}/liveconnect-source-files.txt
	@${MKDIR} ${ITWEBDIR}/liveconnect/lib
	@${ITWEB_JAVAC} ${ITWEB_JAVAC_FLAGS} -d ${ITWEBDIR}/liveconnect \
	    -classpath ${ITWEBDIR}/netx.build \
	    @${ITWEBDIR}/liveconnect-source-files.txt
	@( \
		cd ${ITWEBDIR}/liveconnect; \
		${ITWEB_JAR} cf ${ITWEBDIR}/build/lib/plugin.jar \
		    netscape sun/applet \
	)
	@${FIND} -s ${ITWEBDIR}/extra -name '*.java' > \
	    ${ITWEBDIR}/extra-source-files.txt
	@${MKDIR} ${ITWEBDIR}/extra-lib
	@${ITWEB_JAVAC} ${ITWEB_JAVAC_FLAGS} -d ${ITWEBDIR}/extra-lib \
	    -classpath ${ITWEBDIR}/netx.build \
	    @${ITWEBDIR}/extra-source-files.txt
	@${CP} -r ${ITWEBDIR}/extra/net/sourceforge/jnlp/about/resources \
	    ${ITWEBDIR}/extra-lib/net/sourceforge/jnlp/about
	@( \
		cd ${ITWEBDIR}/extra-lib; \
		${ITWEB_JAR} cf ${ITWEBDIR}/build/lib/about.jar net \
	)
	@${MKDIR} ${ITWEBDIR}/build/lib/desktop
	@${SED} 's|PATH_TO_ITWEB_SETTINGS|${PREFIX}/openjdk6/bin/itweb-settings|' \
	    ${ITWEBDIR}/itweb-settings.desktop.in > \
	    ${ITWEBDIR}/build/lib/desktop/itweb-settings.desktop
	@${SED} 's|PATH_TO_JAVAWS|${PREFIX}/openjdk6/bin/javaws|' \
	    ${ITWEBDIR}/javaws.desktop.in > \
	    ${ITWEBDIR}/build/lib/desktop/javaws.desktop
	@${CP} ${ITWEBDIR}/javaws.png ${ITWEBDIR}/build/lib/desktop
	@${CP} -Rp ${ITWEBDIR}/build/lib \
	    ${WRKSRC}/build/${OPENJDK_OSARCH}/j2sdk-image/jre
	@${CP} ${ITWEBDIR}/netx/javaws.1 \
	    ${WRKSRC}/build/${OPENJDK_OSARCH}/j2sdk-image/man/man1/javaws.1
.endif
.if defined(WITH_TEST)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Run \"make test\" to execute regression test (it could take a few hours to complete)."
.if defined(DISPLAY)
	@${ECHO_MSG} "Unset the environment DISPLAY variable to run tests in a virtual X server."
.endif
	@${ECHO_MSG} ""

test: build-depends build
.if !defined(DISPLAY)
	@${LOCALBASE}/bin/Xvfb :1001 -screen 0 800x600x24 -fp ${LOCALBASE}/lib/X11/fonts/misc > /dev/null 2>&1 & ${ECHO} $$! > ${WRKDIR}/.Xvfb.pid
.endif
	@-(cd ${WRKSRC}/jdk/test; ${SETENV} ${MAKE_ENV} ${GMAKE} tests)
.if !defined(DISPLAY)
	@-${CAT} ${WRKDIR}/.Xvfb.pid | ${XARGS} kill
	@${RM} -f ${WRKDIR}/.Xvfb.pid
.endif
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You can run \"make test\" again to re-execute only the failed tests."
	@${ECHO_MSG} ""
.endif
.endif

do-install:
	@${MKDIR} ${PREFIX}/openjdk6/
	@${CP} -Rp ${WRKSRC}/build/${OPENJDK_OSARCH}/j2sdk-image/ ${PREFIX}/openjdk6/
.if defined(WITH_FASTDEBUG)
	@${MKDIR} ${PREFIX}/openjdk6-fastdebug/
	@${CP} -Rp ${WRKSRC}/build/${OPENJDK_OSARCH}-fastdebug/j2sdk-image/ ${PREFIX}/openjdk6-fastdebug/
.endif
	@${ECHO_MSG} "@unexec ${LOCALBASE}/bin/unregistervm ${PREFIX}/openjdk6/bin/java" >> ${TMPPLIST}
	@${FIND} -s ${PREFIX}/openjdk6 -not -type d | \
		${SED} -e 's#^${PREFIX}/##' >> ${TMPPLIST}
	@${ECHO} "@exec mkdir ${PREFIX}/openjdk6/jre/lib/applet" >> ${TMPPLIST}
	@${FIND} ${PREFIX}/openjdk6 -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
	@${ECHO_MSG} "@exec ${LOCALBASE}/bin/registervm '${PREFIX}/openjdk6/bin/java # OpenJDK6'" >> ${TMPPLIST}
.if defined(WITH_FASTDEBUG)
	@${ECHO_MSG} "@unexec ${LOCALBASE}/bin/unregistervm ${PREFIX}/openjdk6-fastdebug/bin/java" >> ${TMPPLIST}
	@${FIND} -s ${PREFIX}/openjdk6-fastdebug -not -type d | \
		${SED} -e 's#^${PREFIX}/##' >> ${TMPPLIST}
	@${ECHO} "@exec mkdir ${PREFIX}/openjdk6-fastdebug/jre/lib/applet" >> ${TMPPLIST}
	@${FIND} ${PREFIX}/openjdk6-fastdebug -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
	@${ECHO_MSG} "@exec ${LOCALBASE}/bin/registervm '${PREFIX}/openjdk6-fastdebug/bin/java # OpenJDK6'" >> ${TMPPLIST}
.endif

post-install:
	@# Register the VM
	@"${LOCALBASE}/bin/registervm" "${PREFIX}/openjdk6/bin/java # OpenJDK6"
.if defined(WITH_FASTDEBUG)
	@"${LOCALBASE}/bin/registervm" "${PREFIX}/openjdk6-fastdebug/bin/java # OpenJDK6"
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
