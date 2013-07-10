# Created by:	Brian Gardner <brian@experts-exchange.com>
# $FreeBSD$

PORTNAME=	openjdk6
PORTVERSION=	b27
PORTREVISION?=	3
CATEGORIES=	java devel
MASTER_SITES=	http://download.java.net/openjdk/jdk6/promoted/${PORTVERSION}/ \
		http://download.java.net/jaxp/openjdk/jdk6/:jaxp \
		http://download.java.net/glassfish/components/jax-ws/openjdk/jdk6/:jaxws \
		https://java.net/downloads/jax-ws/OpenJDK6/:jaf \
		http://icedtea.classpath.org/download/drops/:jaxp \
		http://icedtea.classpath.org/download/drops/:jaxws \
		http://icedtea.classpath.org/download/drops/:jaf \
		http://icedtea.wildebeest.org/download/drops/:jaxp \
		http://icedtea.wildebeest.org/download/drops/:jaxws \
		http://icedtea.wildebeest.org/download/drops/:jaf \
		${MASTER_SITE_APACHE:S,%SUBDIR%/,ant/binaries/:ant,} \
		http://download.java.net/openjdk/jtreg/promoted/4.1/${JTREGVERSION}/:jtreg
DISTNAME=	openjdk-6-src-${PORTVERSION}-${OPENJDK_BUILDDATE}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${JAXPFILE}:jaxp \
		${JAXWSFILE}:jaxws \
		${JAFFILE}:jaf \
		${ANTFILE}:ant
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX} ${ANTFILE}

MAINTAINER=	java@FreeBSD.org
COMMENT?=	Oracle's Java 6 virtual machine release under the GPL v2

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/bin/zip:${PORTSDIR}/archivers/zip \
		${LOCALBASE}/bin/unzip:${PORTSDIR}/archivers/unzip \
		${LOCALBASE}/include/cups/cups.h:${PORTSDIR}/print/cups-client
LIB_DEPENDS=	freetype:${PORTSDIR}/print/freetype2
RUN_DEPENDS=	javavm:${PORTSDIR}/java/javavmwrapper \
		${LOCALBASE}/lib/X11/fonts/dejavu:${PORTSDIR}/x11-fonts/dejavu

OPENJDK_BUILDDATE=	26_oct_2012

EXTRA_PATCHES=	${FILESDIR}/icedtea/jaxp.patch \
		${FILESDIR}/icedtea/jaxws.patch \
		${FILESDIR}/icedtea/security/20120830/7182135-impossible_to_use_some_editors_directly.patch \
		${FILESDIR}/icedtea/security/20130201/7201068.patch \
		${FILESDIR}/icedtea/security/20130201/6563318.patch \
		${FILESDIR}/icedtea/security/20130201/6664509.patch \
		${FILESDIR}/icedtea/security/20130201/6776941.patch \
		${FILESDIR}/icedtea/security/20130201/7141694.patch \
		${FILESDIR}/icedtea/security/20130201/7173145.patch \
		${FILESDIR}/icedtea/security/20130201/7186945.patch \
		${FILESDIR}/icedtea/security/20130201/7186948.patch \
		${FILESDIR}/icedtea/security/20130201/7186952.patch \
		${FILESDIR}/icedtea/security/20130201/7186954.patch \
		${FILESDIR}/icedtea/security/20130201/7192392.patch \
		${FILESDIR}/icedtea/security/20130201/7192393.patch \
		${FILESDIR}/icedtea/security/20130201/7192977.patch \
		${FILESDIR}/icedtea/security/20130201/7197546.patch \
		${FILESDIR}/icedtea/security/20130201/7200491.patch \
		${FILESDIR}/icedtea/security/20130201/7200500.patch \
		${FILESDIR}/icedtea/security/20130201/7201064.patch \
		${FILESDIR}/icedtea/security/20130201/7201066.patch \
		${FILESDIR}/icedtea/security/20130201/7201070.patch \
		${FILESDIR}/icedtea/security/20130201/7201071.patch \
		${FILESDIR}/icedtea/security/20130201/8000210.patch \
		${FILESDIR}/icedtea/security/20130201/8000537.patch \
		${FILESDIR}/icedtea/security/20130201/8000540.patch \
		${FILESDIR}/icedtea/security/20130201/8000631.patch \
		${FILESDIR}/icedtea/security/20130201/8001242.patch \
		${FILESDIR}/icedtea/security/20130201/8001307.patch \
		${FILESDIR}/icedtea/security/20130201/8001972.patch \
		${FILESDIR}/icedtea/security/20130201/8002325.patch \
		${FILESDIR}/icedtea/security/20130219/8006446.patch \
		${FILESDIR}/icedtea/security/20130219/8006777.patch \
		${FILESDIR}/icedtea/security/20130219/8007688.patch \
		${FILESDIR}/icedtea/security/20130304/8007014.patch \
		${FILESDIR}/icedtea/security/20130304/8007675.patch \
		${FILESDIR}/icedtea/openjdk/7036559-concurrenthashmap_improvements.patch \
		${FILESDIR}/icedtea/security/20130416/8009063.patch \
		${FILESDIR}/icedtea/openjdk/8004302-soap_test_failure.patch \
		${FILESDIR}/icedtea/security/20130416/6657673.patch \
		${FILESDIR}/icedtea/security/20130416/6657673-fixup.patch \
		${FILESDIR}/icedtea/openjdk/7133220-factory_finder_parser_transform_useBSClassLoader.patch \
		${FILESDIR}/icedtea/security/20130416/6657673-factory_finder.patch \
		${FILESDIR}/icedtea/openjdk/6669869-queries_per_appcontext.patch \
		${FILESDIR}/icedtea/openjdk/5102804-memory_leak.patch \
		${FILESDIR}/icedtea/openjdk/6963811-deadlock_fix.patch \
		${FILESDIR}/icedtea/openjdk/7064279-resource_release.patch \
		${FILESDIR}/icedtea/openjdk/7064279-fixup.patch \
		${FILESDIR}/icedtea/security/20130416/7200507.patch \
		${FILESDIR}/icedtea/security/20130416/8000724.patch \
		${FILESDIR}/icedtea/security/20130416/8004986.patch \
		${FILESDIR}/icedtea/openjdk/6501644-icu_sync.patch \
		${FILESDIR}/icedtea/openjdk/6886358-layout_update.patch \
		${FILESDIR}/icedtea/security/20130416/8001031.patch \
		${FILESDIR}/icedtea/openjdk/7017324-kerning_crash.patch \
		${FILESDIR}/icedtea/security/20130416/8001040.patch \
		${FILESDIR}/icedtea/security/20130416/8001322.patch \
		${FILESDIR}/icedtea/security/20130416/8001329.patch \
		${FILESDIR}/icedtea/security/20130416/8003335.patch \
		${FILESDIR}/icedtea/security/20130416/8003445.patch \
		${FILESDIR}/icedtea/security/20130416/8003543.patch \
		${FILESDIR}/icedtea/security/20130416/8004261.patch \
		${FILESDIR}/icedtea/security/20130416/8004336.patch \
		${FILESDIR}/icedtea/security/20130416/8005432.patch \
		${FILESDIR}/icedtea/security/20130416/8005943.patch \
		${FILESDIR}/icedtea/security/20130416/8006309.patch \
		${FILESDIR}/icedtea/security/20130416/8006435.patch \
		${FILESDIR}/icedtea/security/20130416/8006790.patch \
		${FILESDIR}/icedtea/security/20130416/8006795.patch \
		${FILESDIR}/icedtea/security/20130416/8007406.patch \
		${FILESDIR}/icedtea/security/20130416/8007617.patch \
		${FILESDIR}/icedtea/security/20130416/8007667.patch \
		${FILESDIR}/icedtea/security/20130416/8007918.patch \
		${FILESDIR}/icedtea/security/20130416/8009305.patch \
		${FILESDIR}/icedtea/security/20130416/8009699.patch \
		${FILESDIR}/icedtea/security/20130416/8009814.patch \
		${FILESDIR}/icedtea/security/20130416/8009857.patch

OPTIONS_DEFINE=	ICEDTEA IPV6 POLICY SOUND TZUPDATE
OPTIONS_DEFAULT=ICEDTEA IPV6 TZUPDATE
ICEDTEA_DESC=	Apply additional patches from IcedTea
POLICY_DESC=	Install the Unlimited Strength Policy Files
SOUND_DESC=	Enable sound support
TZUPDATE_DESC=	Update the time zone data

.if !defined(BUILD_JRE)
OPTIONS_DEFINE+=DEBUG FASTDEBUG TEST
DEBUG_DESC=	Enable legacy debugging support
FASTDEBUG_DESC=	Include fastdebug build
TEST_DESC=	Add support for running regression test
.endif

USES=		gmake motif

.include <bsd.port.options.mk>

# java extracts directly to the cwd
WRKSRC=		${WRKDIR}

USE_XORG=	x11 xext xi xt xtst

JAXP_BUILD=	144_05
JAXPFILE=	jaxp${JAXP_BUILD}.zip
JAXWS_BUILD=	2_1_6-2011_06_13
JAXWSFILE=	jdk6-jaxws${JAXWS_BUILD}.zip
JAF_BUILD=	b20
JAFFILE=	jdk6-jaf-${JAF_BUILD}.zip
JTREGVERSION=	b04
JTREGFILE=	jtreg-4.1-bin-${JTREGVERSION}_14_mar_2012.zip
UPDATE_VERSION=	32

# do not depend on devel/apache-ant to avoid circular dependency, but
# use .tar.bz2 distfile to avoid duplicated downloads
ANTVERSION=	1.8.4
ANTFILE=	apache-ant-${ANTVERSION}-bin.tar.bz2

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MIPV6}
CATEGORIES+=	ipv6
.endif

.if ${PORT_OPTIONS:MTZUPDATE}
RUN_DEPENDS+=  ${LOCALBASE}/share/java/zi:${PORTSDIR}/java/java-zoneinfo
.endif

# avoid ARCH in MAKEFLAGS, breaks build
NOPRECIOUSMAKEVARS=	yes

ONLY_FOR_ARCHS=	amd64 i386

BOOTSTRAP_JDKS=	${LOCALBASE}/openjdk6 \
		${LOCALBASE}/bootstrap-openjdk

# do we have valid native jdk installed?
.for CJDK in ${BOOTSTRAP_JDKS}
.  if !defined(BOOTSTRAPJDKDIR) && exists(${CJDK}/bin/javac)
BOOTSTRAPJDKDIR=	${CJDK}
.  endif
.endfor

# if no valid jdk found, set dependency
.if !defined(BOOTSTRAPJDKDIR)
BOOTSTRAPJDKDIR?=	${LOCALBASE}/bootstrap-openjdk
BUILD_DEPENDS+=		${BOOTSTRAPJDKDIR}/bin/javac:${PORTSDIR}/java/bootstrap-openjdk
.endif

FETCH_ARGS=	-Fpr
MAKE_ENV=	LANG=C LC_ALL=C OS= \
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
		JAVACMD=${BOOTSTRAPJDKDIR}/bin/java \
		BUILD_NUMBER=${PORTVERSION} \
		NO_DOCS=true \
		MILESTONE=fcs \
		JDK_UPDATE_VERSION=${UPDATE_VERSION}

# HotSpot wants CCC instead of CXX.  Also, HotSpot SA wants GCC.
MAKE_ENV+=	CCC="${CXX}" GCC="${CC}"

# XXX Turn off -Werror from HotSpot.
MAKE_ENV+=	WARNINGS_ARE_ERRORS="${WARNINGS_ARE_ERRORS}"

# XXX Turn off parallel build by default.
_MAKE_JOBS=	#
MAKE_ENV+=	ALT_PARALLEL_COMPILE_JOBS=${MAKE_JOBS_NUMBER} \
		HOTSPOT_BUILD_JOBS=${MAKE_JOBS_NUMBER}

.if ${PORT_OPTIONS:MDEBUG}
ALL_TARGET=	debug_build
OPENJDK_OSARCH=	bsd-${ARCH:S/i386/i586/}-debug
.else
OPENJDK_OSARCH=	bsd-${ARCH:S/i386/i586/}
WARNINGS_ARE_ERRORS?=	-w
.endif

# disable FASTDEBUG_BUILD by default to improve compile time.
.if ${PORT_OPTIONS:MFASTDEBUG}
MAKE_ENV+=	SKIP_FASTDEBUG_BUILD=false
.else
MAKE_ENV+=	SKIP_FASTDEBUG_BUILD=true
.endif

.if ${PORT_OPTIONS:MICEDTEA}
EXTRA_PATCHES+=	${FILESDIR}/icedtea/openjdk/7032388-work_without_cmov_instruction.patch \
		${FILESDIR}/icedtea/applet_hole.patch \
		${FILESDIR}/icedtea/jpegclasses.patch
.endif

.if empty(PORT_OPTIONS:MIPV6)
MAKE_ENV+=	DONT_ENABLE_IPV6="YES"
.endif

.if ${PORT_OPTIONS:MSOUND}
EXTRA_PATCHES+=	${FILESDIR}/alsa-enable.patch
LIB_DEPENDS+=	asound:${PORTSDIR}/audio/alsa-lib
RUN_DEPENDS+=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:${PORTSDIR}/audio/alsa-plugins
.else
EXTRA_PATCHES+=	${FILESDIR}/alsa-disable.patch
.endif

.if ${PORT_OPTIONS:MTEST}
DISTFILES+=	${JTREGFILE}:jtreg
EXTRACT_ONLY+=	${JTREGFILE}
BUILD_DEPENDS+=	${LOCALBASE}/lib/X11/fonts/dejavu:${PORTSDIR}/x11-fonts/dejavu
USE_DISPLAY=	yes
.endif

COPYDIRS=	\
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
		${MKDIR} `echo ${WRKSRC}/$$d | ${SED} 's/linux/bsd/g;'`; \
		cd ${WRKSRC}/$$d; \
		for f in *; do \
			if [ -f $$f ]; then \
				t=`echo ${WRKSRC}/$$d/$$f | ${SED} 's/linux/bsd/g; s/Linux/Bsd/g'`; \
				${SED} 's/linux/bsd/g; s/Linux/Bsd/g; s/LINUX/BSD/g' < $$f > $$t; \
			fi; \
		done; \
	done
	@for f in ${COPYFILES}; do \
		t=`echo $$f | ${SED} 's/linux/bsd/g; s/Linux/Bsd/g'`; \
		${SED} 's/linux/bsd/g; s/Linux/Bsd/g' < ${WRKSRC}/$$f > ${WRKSRC}/$$t; \
	done
	@${SED} 's/solaris/bsd/g; s/Solaris/Bsd/g' \
		< ${WRKSRC}/jdk/src/solaris/hpi/native_threads/src/threads_solaris.c \
		> ${WRKSRC}/jdk/src/solaris/hpi/native_threads/src/threads_bsd.c
	@${SED} "s|/usr/local|${LOCALBASE}|" < ${FILESDIR}/fontconfig.properties \
		> ${WRKSRC}/jdk/src/solaris/classes/sun/awt/fontconfigs/bsd.fontconfig.properties
	@${SED} "s|%%LOCALBASE%%|${LOCALBASE}|" < ${FILESDIR}/Makefile.test \
		> ${WRKSRC}/jdk/test/Makefile
	@${FIND} ${WRKSRC}/jdk/test -type f -name \*.sh -exec ${SED} -i "" -e s/Linux/FreeBSD/g {} \;

post-patch:
	@${REINPLACE_CMD} "s|/lib:/usr/lib|/lib:/usr/lib:${LOCALBASE}/lib|" \
		${WRKSRC}/hotspot/src/os/bsd/vm/os_bsd.cpp
.if ${PORT_OPTIONS:MPOLICY}
	@${REINPLACE_CMD} 's|build-policy install-limited|build-policy install-unlimited|' \
		${WRKSRC}/jdk/make/javax/crypto/Makefile
.endif

post-build:
.if ${PORT_OPTIONS:MTZUPDATE}
	@# Update time zones
.if defined(BUILD_JRE)
	@${RM} -rf ${WRKSRC}/build/${OPENJDK_OSARCH}/j2re-image/lib/zi
	@${LN} -s -f ${LOCALBASE}/share/java/zi \
		${WRKSRC}/build/${OPENJDK_OSARCH}/j2re-image/lib
.else
	@${RM} -rf ${WRKSRC}/build/${OPENJDK_OSARCH}/j2sdk-image/jre/lib/zi
	@${LN} -s -f ${LOCALBASE}/share/java/zi \
		${WRKSRC}/build/${OPENJDK_OSARCH}/j2sdk-image/jre/lib
.endif
.endif
.if ${PORT_OPTIONS:MTEST}
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

do-install:
.if defined(BUILD_JRE)
	@${MKDIR} ${PREFIX}/openjdk6-jre/
	@cd ${WRKSRC}/build/${OPENJDK_OSARCH}/j2re-image && \
		${COPYTREE_SHARE} . ${PREFIX}/openjdk6-jre
	@${CHOWN} ${BINOWN}:${BINGRP} ${PREFIX}/openjdk6-jre/bin/* \
		${PREFIX}/openjdk6-jre/lib/${ARCH}/jexec
	@${CHMOD} ${BINMODE} ${PREFIX}/openjdk6-jre/bin/* \
		${PREFIX}/openjdk6-jre/lib/${ARCH}/jexec
	@${ECHO_MSG} "@unexec ${LOCALBASE}/bin/unregistervm ${PREFIX}/openjdk6-jre/bin/java" >> ${TMPPLIST}
	@${FIND} -s ${PREFIX}/openjdk6-jre -not -type d | \
		${SED} -e 's#^${PREFIX}/##' >> ${TMPPLIST}
	@${ECHO} "@exec mkdir ${PREFIX}/openjdk6-jre/lib/applet" >> ${TMPPLIST}
	@${FIND} ${PREFIX}/openjdk6-jre -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
	@${ECHO_MSG} "@exec ${LOCALBASE}/bin/registervm '${PREFIX}/openjdk6-jre/bin/java # OpenJDK6 JRE'" >> ${TMPPLIST}
.else
	@${MKDIR} ${PREFIX}/openjdk6/
	@cd ${WRKSRC}/build/${OPENJDK_OSARCH}/j2sdk-image && \
		${COPYTREE_SHARE} . ${PREFIX}/openjdk6
	@${INSTALL_DATA} ${WRKSRC}/build/${OPENJDK_OSARCH}/btjars/compilefontconfig.jar ${WRKSRC}/build/${OPENJDK_OSARCH}/btjars/javazic.jar ${PREFIX}/openjdk6/jre/lib/
	@for dir in `${FIND} ${PREFIX}/openjdk6 -name bin -type d`; do \
		${CHOWN} -h -R ${BINOWN}:${BINGRP} $$dir; \
		${FIND} $$dir -type f -exec ${CHMOD} ${BINMODE} "{}" \; ; \
	done
	@${CHOWN} ${BINOWN}:${BINGRP} \
		${PREFIX}/openjdk6/jre/lib/${ARCH}/jexec
	@${CHMOD} ${BINMODE} \
		${PREFIX}/openjdk6/jre/lib/${ARCH}/jexec
.if ${PORT_OPTIONS:MFASTDEBUG}
	@${MKDIR} ${PREFIX}/openjdk6-fastdebug/
	@cd ${WRKSRC}/build/${OPENJDK_OSARCH}/j2sdk-image && \
		${COPYTREE_SHARE} . ${PREFIX}/openjdk6-fastdebug
	@for dir in `${FIND} ${PREFIX}/openjdk6-fastdebug -name bin -type d`; do \
		${CHOWN} -h -R ${BINOWN}:${BINGRP} $$dir; \
		${FIND} $$dir -type f -exec ${CHMOD} ${BINMODE} "{}" \; ; \
	done
	@${CHOWN} ${BINOWN}:${BINGRP} \
		${PREFIX}/openjdk6-fastdebug/jre/lib/${ARCH}/jexec
	@${CHMOD} ${BINMODE} \
		${PREFIX}/openjdk6-fastdebug/jre/lib/${ARCH}/jexec
.endif
	@${ECHO_MSG} "@unexec ${LOCALBASE}/bin/unregistervm ${PREFIX}/openjdk6/bin/java" >> ${TMPPLIST}
	@${FIND} -s ${PREFIX}/openjdk6 -not -type d | \
		${SED} -e 's#^${PREFIX}/##' >> ${TMPPLIST}
	@${ECHO} "@exec mkdir ${PREFIX}/openjdk6/jre/lib/applet" >> ${TMPPLIST}
	@${FIND} ${PREFIX}/openjdk6 -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
	@${ECHO_MSG} "@exec ${LOCALBASE}/bin/registervm '${PREFIX}/openjdk6/bin/java # OpenJDK6'" >> ${TMPPLIST}
.if ${PORT_OPTIONS:MFASTDEBUG}
	@${ECHO_MSG} "@unexec ${LOCALBASE}/bin/unregistervm ${PREFIX}/openjdk6-fastdebug/bin/java" >> ${TMPPLIST}
	@${FIND} -s ${PREFIX}/openjdk6-fastdebug -not -type d | \
		${SED} -e 's#^${PREFIX}/##' >> ${TMPPLIST}
	@${ECHO} "@exec mkdir ${PREFIX}/openjdk6-fastdebug/jre/lib/applet" >> ${TMPPLIST}
	@${FIND} ${PREFIX}/openjdk6-fastdebug -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
	@${ECHO_MSG} "@exec ${LOCALBASE}/bin/registervm '${PREFIX}/openjdk6-fastdebug/bin/java # OpenJDK6'" >> ${TMPPLIST}
.endif
.endif

post-install:
	@# Register the VM
.if defined(BUILD_JRE)
	@"${LOCALBASE}/bin/registervm" "${PREFIX}/openjdk6-jre/bin/java # OpenJDK6 JRE"
.else
	@"${LOCALBASE}/bin/registervm" "${PREFIX}/openjdk6/bin/java # OpenJDK6"
.if ${PORT_OPTIONS:MFASTDEBUG}
	@"${LOCALBASE}/bin/registervm" "${PREFIX}/openjdk6-fastdebug/bin/java # OpenJDK6"
.endif
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
