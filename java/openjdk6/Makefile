# Created by: Brian Gardner <brian@experts-exchange.com>
# $FreeBSD$

PORTNAME=	openjdk6
PORTVERSION=	b28
PORTREVISION?=	4
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_APACHE:S,%SUBDIR%/,ant/binaries/:ant,} \
		http://download.java.net/openjdk/jtreg/promoted/4.1/b05/:jtreg \
		https://java.net/projects/openjdk6/downloads/download/ \
		LOCAL
MASTER_SITE_SUBDIR=	jkim
DISTNAME=	openjdk-6-src-${PORTVERSION}-${OPENJDK_BUILDDATE}
DISTFILES=	${ANTFILE}:ant \
		${DISTNAME}${EXTRACT_SUFX}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX} ${ANTFILE}

MAINTAINER=	java@FreeBSD.org
COMMENT?=	Oracle's Java 6 virtual machine release under the GPL v2

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

BUILD_DEPENDS=	${LOCALBASE}/bin/zip:${PORTSDIR}/archivers/zip \
		${LOCALBASE}/bin/unzip:${PORTSDIR}/archivers/unzip \
		${LOCALBASE}/include/cups/cups.h:${PORTSDIR}/print/cups-client
LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2
RUN_DEPENDS=	javavm:${PORTSDIR}/java/javavmwrapper \
		${LOCALBASE}/lib/X11/fonts/dejavu:${PORTSDIR}/x11-fonts/dejavu

OPENJDK_BUILDDATE=	04_oct_2013

OPTIONS_DEFINE=	ICEDTEA IPV6 POLICY SOUND TZUPDATE
OPTIONS_DEFAULT=ICEDTEA IPV6 TZUPDATE
ICEDTEA_DESC=	Apply additional patches from IcedTea
POLICY_DESC=	Install the Unlimited Strength Policy Files
SOUND_DESC=	Enable sound support
TZUPDATE_DESC=	Update the time zone data

.if !defined(BUILD_JRE)
OPTIONS_DEFINE+=TEST
OPTIONS_RADIO=	Debugging
OPTIONS_RADIO_Debugging=	DEBUG FASTDEBUG
DEBUG_DESC=	Enable legacy debugging support
FASTDEBUG_DESC=	Include fastdebug build
TEST_DESC=	Add support for running regression test
.endif

PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
PKGINSTALL=	${WRKDIR}/pkg-install

USES=		compiler gmake iconv motif

.include <bsd.port.options.mk>
.include "${.CURDIR}/../openjdk6/Makefile.icedtea"
.include "${.CURDIR}/../openjdk6/Makefile.test"

EXTRA_PATCHES+=	${ICEDTEA_PATCHES}

# java extracts directly to the cwd
WRKSRC=		${WRKDIR}

USE_XORG=	x11 xext xi xt xtst

# do not depend on devel/apache-ant to avoid circular dependency, but
# use .tar.bz2 distfile to avoid duplicated downloads
ANTVERSION=	1.9.2
ANTFILE=	apache-ant-${ANTVERSION}-bin.tar.bz2

JTREG_BUILD=	b05_29_nov_2012
JTREGFILE=	jtreg-4.1-bin-${JTREG_BUILD}.zip
UPDATE_VERSION=	32

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
		ANT_HOME=${WRKDIR}/apache-ant-${ANTVERSION} \
		JAVACMD=${BOOTSTRAPJDKDIR}/bin/java \
		BUILD_NUMBER=${PORTVERSION} \
		NO_DOCS=true \
		MILESTONE=fcs \
		JDK_UPDATE_VERSION=${UPDATE_VERSION}

# XXX Turn off parallel build by default.
_MAKE_JOBS=	#
MAKE_ENV+=	ALT_PARALLEL_COMPILE_JOBS=${MAKE_JOBS_NUMBER} \
		HOTSPOT_BUILD_JOBS=${MAKE_JOBS_NUMBER}

.if ${PORT_OPTIONS:MDEBUG}
ALL_TARGET=	debug_build
OPENJDK_OSARCH=	bsd-${ARCH:S/i386/i586/}-debug
.else
OPENJDK_OSARCH=	bsd-${ARCH:S/i386/i586/}
.endif

# disable FASTDEBUG_BUILD by default to improve compile time.
.if ${PORT_OPTIONS:MFASTDEBUG}
MAKE_ENV+=	SKIP_FASTDEBUG_BUILD=false
.else
MAKE_ENV+=	SKIP_FASTDEBUG_BUILD=true
.endif

.if empty(PORT_OPTIONS:MIPV6)
MAKE_ENV+=	DONT_ENABLE_IPV6="YES"
.endif

.if ${PORT_OPTIONS:MSOUND}
EXTRA_PATCHES+=	${FILESDIR}/alsa-enable.patch
LIB_DEPENDS+=	libasound.so:${PORTSDIR}/audio/alsa-lib
RUN_DEPENDS+=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:${PORTSDIR}/audio/alsa-plugins
.else
EXTRA_PATCHES+=	${FILESDIR}/alsa-disable.patch
.endif

.if ${PORT_OPTIONS:MTEST}
DISTFILES+=	${JTREGFILE}:jtreg
EXTRACT_ONLY+=	${JTREGFILE}
BUILD_DEPENDS+=	${LOCALBASE}/lib/X11/fonts/dejavu:${PORTSDIR}/x11-fonts/dejavu
USES+=		display:test
.else
EXTRA_PATCHES+=	${FILESDIR}/test_gamma-disable.patch
.endif

COPYDIRS=	\
	jdk/src/linux/doc/man

COPYFILES=	\
	corba/make/common/Defs-linux.gmk \
	corba/make/common/shared/Defs-linux.gmk \
	hotspot/src/os/linux/vm/decoder_linux.cpp \
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

.include <bsd.port.pre.mk>

.if ${ICONV_PREFIX} == "/usr"
ICONV_INCLUDE=
ICONV_LIBS=
.else
ICONV_INCLUDE=	-I${LOCALBASE}/include
ICONV_LIBS=	-L${LOCALBASE}/lib ${ICONV_LIB}
.endif
ZLIB_LIBS?=	-lz

.if ${COMPILER_TYPE} == "clang"
MAKE_ENV+=	COMPILER_WARNINGS_FATAL=false
.if empty(PORT_OPTIONS:MDEBUG) && empty(PORT_OPTIONS:MFASTDEBUG)
MAKE_ENV+=	WARNINGS_ARE_ERRORS=-w
.endif
.endif

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
	    ${WRKSRC}/jdk/src/solaris/hpi/native_threads/src/threads_solaris.c > \
	    ${WRKSRC}/jdk/src/solaris/hpi/native_threads/src/threads_bsd.c
	@${SED} "s|/usr/local|${LOCALBASE}|" \
	    ${FILESDIR}/fontconfig.properties > \
	    ${WRKSRC}/jdk/src/solaris/classes/sun/awt/fontconfigs/bsd.fontconfig.properties
	@${SED} "s|%%LOCALBASE%%|${LOCALBASE}|" ${FILESDIR}/Makefile.test.in > \
	    ${WRKSRC}/jdk/test/Makefile
	@${FIND} ${WRKSRC}/jdk/test -type f -name \*.sh -exec ${SED} -i "" \
	    -e s/Linux/FreeBSD/g {} \;

post-patch:
	@${REINPLACE_CMD} -e "s|%%CXX_LIBS%%|${CXX_LIBS}|" \
	    ${WRKSRC}/corba/make/common/Defs-bsd.gmk \
	    ${WRKSRC}/jdk/make/common/Defs-bsd.gmk
	@${REINPLACE_CMD} -e "s|%%ICONV_INC%%|${ICONV_INCLUDE}|" \
	    -e "s|%%ICONV_LIB%%|${ICONV_LIBS}|" \
	    ${WRKSRC}/Makefile ${WRKSRC}/jdk/make/java/instrument/Makefile \
	    ${WRKSRC}/jdk/make/java/npt/Makefile \
	    ${WRKSRC}/jdk/make/sun/splashscreen/Makefile
	@${REINPLACE_CMD} -e "s|%%ZLIB_LIBS%%|${ZLIB_LIBS}|" \
	    ${WRKSRC}/jdk/make/com/sun/java/pack/Makefile \
	    ${WRKSRC}/jdk/make/common/Program.gmk \
	    ${WRKSRC}/jdk/make/java/jli/Makefile \
	    ${WRKSRC}/jdk/make/java/zip/Makefile \
	    ${WRKSRC}/jdk/make/tools/freetypecheck/Makefile
	@${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|" \
	    ${WRKSRC}/hotspot/src/os/bsd/vm/os_bsd.cpp \
	    ${WRKSRC}/jdk/src/share/classes/com/sun/java/swing/plaf/gtk/Metacity.java
.if ${PORT_OPTIONS:MPOLICY}
	@${REINPLACE_CMD} -e 's|%%POLICY%%|unlimited|' \
	    ${WRKSRC}/jdk/make/javax/crypto/Makefile
.else
	@${REINPLACE_CMD} -e 's|%%POLICY%%|limited|' \
	    ${WRKSRC}/jdk/make/javax/crypto/Makefile
.endif
.if defined(BUILD_JRE)
	@${REINPLACE_CMD} -e "s|%%JAVA_HOME%%|${PREFIX}/openjdk6-jre|" \
	    ${WRKSRC}/hotspot/src/os/posix/launcher/java_md.c \
	    ${WRKSRC}/jdk/src/solaris/bin/java_md.c
.else
	@${REINPLACE_CMD} -e "s|%%JAVA_HOME%%|${PREFIX}/openjdk6|" \
	    ${WRKSRC}/hotspot/src/os/posix/launcher/java_md.c \
	    ${WRKSRC}/jdk/src/solaris/bin/java_md.c
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
.endif

do-install:
.if defined(BUILD_JRE)
	@cd ${WRKSRC}/build/${OPENJDK_OSARCH}/j2re-image && \
	    ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/openjdk6-jre \
	    "-not ( -type d -name bin -prune )"
	@cd ${WRKSRC}/build/${OPENJDK_OSARCH}/j2re-image && \
	    ${COPYTREE_BIN} bin ${STAGEDIR}${PREFIX}/openjdk6-jre
	@cd ${WRKSRC}/build/${OPENJDK_OSARCH}/j2re-image && \
	    ${INSTALL_PROGRAM} lib/${ARCH}/jexec \
	    ${STAGEDIR}${PREFIX}/openjdk6-jre/lib/${ARCH}
.else
	@cd ${WRKSRC}/build/${OPENJDK_OSARCH}/j2sdk-image && \
	    ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/openjdk6 \
	    "-not ( -type d -name bin -prune )"
	@cd ${WRKSRC}/build/${OPENJDK_OSARCH}/j2sdk-image && \
	    ${COPYTREE_BIN} "bin jre/bin" ${STAGEDIR}${PREFIX}/openjdk6
	@cd ${WRKSRC}/build/${OPENJDK_OSARCH}/j2sdk-image && \
	    ${INSTALL_PROGRAM} jre/lib/${ARCH}/jexec \
	    ${STAGEDIR}${PREFIX}/openjdk6/jre/lib/${ARCH}
	@cd ${WRKSRC}/build/${OPENJDK_OSARCH}/btjars && \
	    ${INSTALL_DATA} compilefontconfig.jar javazic.jar \
	    ${STAGEDIR}${PREFIX}/openjdk6/jre/lib
.if ${PORT_OPTIONS:MFASTDEBUG}
	@cd ${WRKSRC}/build/${OPENJDK_OSARCH}-fastdebug/j2sdk-image && \
	    ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/openjdk6-fastdebug \
	    "-not ( -type d -name bin -prune )"
	@cd ${WRKSRC}/build/${OPENJDK_OSARCH}-fastdebug/j2sdk-image && \
	    ${COPYTREE_BIN} "bin jre/bin" \
	    ${STAGEDIR}${PREFIX}/openjdk6-fastdebug
	@cd ${WRKSRC}/build/${OPENJDK_OSARCH}-fastdebug/j2sdk-image && \
	    ${INSTALL_PROGRAM} jre/lib/${ARCH}/jexec \
	    ${STAGEDIR}${PREFIX}/openjdk6-fastdebug/jre/lib/${ARCH}
.endif
.endif
	@${ECHO_CMD} "#!/bin/sh" > ${PKGDEINSTALL}
	@${ECHO_CMD} "#!/bin/sh" > ${PKGINSTALL}
.if defined(BUILD_JRE)
	@cd ${STAGEDIR}${PREFIX}/openjdk6-jre && \
	    ${FIND} -s . -not -type d | \
	    ${SED} -e 's,^\./,openjdk6-jre/,' >> ${TMPPLIST}
	@cd ${STAGEDIR}${PREFIX}/openjdk6-jre && \
	    ${FIND} -s . -type d -empty | \
	    ${SED} 's,^\./,@exec ${MKDIR} %D/openjdk6-jre/,' >> ${TMPPLIST}
	@cd ${STAGEDIR}${PREFIX}/openjdk6-jre && \
	    ${FIND} . -type d -not -depth 0 | ${SORT} -r | \
	    ${SED} 's,^\.,@dirrm openjdk6-jre/,' >> ${TMPPLIST}
	@${ECHO_CMD} "@dirrm openjdk6-jre" >> ${TMPPLIST}
	@${ECHO_CMD} '${TEST} $$2 = DEINSTALL && ${LOCALBASE}/bin/unregistervm ${PREFIX}/openjdk6-jre/bin/java' >> ${PKGDEINSTALL}
	@${ECHO_CMD} '${TEST} $$2 = POST-INSTALL && ${LOCALBASE}/bin/registervm "${PREFIX}/openjdk6-jre/bin/java # OpenJDK6 JRE"' >> ${PKGINSTALL}
.else
	@cd ${STAGEDIR}${PREFIX}/openjdk6 && \
	    ${FIND} -s . -not -type d | \
	    ${SED} -e 's,^\./,openjdk6/,' >> ${TMPPLIST}
	@cd ${STAGEDIR}${PREFIX}/openjdk6 && \
	    ${FIND} -s . -type d -empty | \
	    ${SED} 's,^\./,@exec ${MKDIR} %D/openjdk6/,' >> ${TMPPLIST}
	@cd ${STAGEDIR}${PREFIX}/openjdk6 && \
	    ${FIND} . -type d -not -depth 0 | ${SORT} -r | \
	    ${SED} 's,^\./,@dirrm openjdk6/,' >> ${TMPPLIST}
	@${ECHO_CMD} "@dirrm openjdk6" >> ${TMPPLIST}
	@${ECHO_CMD} '${TEST} $$2 = DEINSTALL && ${LOCALBASE}/bin/unregistervm ${PREFIX}/openjdk6/bin/java' >> ${PKGDEINSTALL}
	@${ECHO_CMD} '${TEST} $$2 = POST-INSTALL && ${LOCALBASE}/bin/registervm "${PREFIX}/openjdk6/bin/java # OpenJDK6"' >> ${PKGINSTALL}
.if ${PORT_OPTIONS:MFASTDEBUG}
	@cd ${STAGEDIR}${PREFIX}/openjdk6-fastdebug && \
	    ${FIND} -s . -not -type d | \
	    ${SED} -e 's,^\./,openjdk6-fastdebug/,' >> ${TMPPLIST}
	@cd ${STAGEDIR}${PREFIX}/openjdk6-fastdebug && \
	    ${FIND} -s . -type d -empty | \
	    ${SED} 's,^\./,@exec ${MKDIR} %D/openjdk6-fastdebug/,' >> ${TMPPLIST}
	@cd ${STAGEDIR}${PREFIX}/openjdk6-fastdebug && \
	    ${FIND} . -type d -not -depth 0 | ${SORT} -r | \
	    ${SED} 's,^\./,@dirrm openjdk6-fastdebug/,' >> ${TMPPLIST}
	@${ECHO_CMD} "@dirrm openjdk6-fastdebug" >> ${TMPPLIST}
	@${ECHO_CMD} '${TEST} $$2 = DEINSTALL && ${LOCALBASE}/bin/unregistervm ${PREFIX}/openjdk6-fastdebug/bin/java' >> ${PKGDEINSTALL}
	@${ECHO_CMD} '${TEST} $$2 = POST-INSTALL && ${LOCALBASE}/bin/registervm "${PREFIX}/openjdk6-fastdebug/bin/java # OpenJDK6"' >> ${PKGINSTALL}
.endif
.endif
	@${ECHO_CMD} "exit 0" >> ${PKGDEINSTALL}
	@${ECHO_CMD} "exit 0" >> ${PKGINSTALL}

.include <bsd.port.post.mk>
