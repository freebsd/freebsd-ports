# New ports collection makefile for:    openjdk6
# Date created:         2009/2/21
# Whom:                 Brian Gardner <brian@experts-exchange.com>
#
# $FreeBSD$
#

PORTNAME=	openjdk6
PORTVERSION=	b17
CATEGORIES=	java devel
MASTER_SITES=	http://download.java.net/openjdk/jdk6/promoted/${PORTVERSION}/ \
		${MASTER_SITE_APACHE:S,%SUBDIR%/,ant/binaries/:ant,}
DISTNAME=	openjdk-6-src-${PORTVERSION}-${OPENJDK_BUILDDATE}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${ANTFILE}:ant

MAINTAINER=	openjdk@getsnappy.com
COMMENT=	Sun\'s java 6 virtual machine release under the GPL v2

RUN_DEPENDS=	javavm:${PORTSDIR}/java/javavmwrapper \
		${LOCALBASE}/lib/X11/fonts/dejavu:${PORTSDIR}/x11-fonts/dejavu

BUILD_NUMBER=	${PORTVERSION:S/b//}
OPENJDK_BUILDDATE=	14_oct_2009

OPTIONS=	DEBUG "Enable legacy debugging support" off \
		FASTDEBUG "Include fastdebug build" off \
		IPV6 "Enable IPv6 support" off \
		POLICY "Install the Unlimited Strength Policy Files" off

# java extracts directly to the cwd
WRKSRC=		${WRKDIR}

USE_GMAKE=	yes
USE_MOTIF=	yes
USE_XORG=	xtst xi xt x11

LIB_DEPENDS+=	freetype.9:${PORTSDIR}/print/freetype2
BUILD_DEPENDS+=	zip:${PORTSDIR}/archivers/zip
BUILD_DEPENDS+=	unzip:${PORTSDIR}/archivers/unzip
BUILD_DEPENDS+=	${LOCALBASE}/include/cups/cups.h:${PORTSDIR}/print/cups-client

# do not depend on devel/apache-ant to avoid circular dependency, but
# use .tar.bz2 distfile to avoid duplicated downloads
ANTVERSION=	1.7.1
ANTFILE=	apache-ant-${ANTVERSION}-bin.tar.bz2

# rely on bsdtar ability to extract .gz and .bz2 archives
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
		ALT_CUPS_HEADERS_PATH=${LOCALBASE}/include \
		ALT_CUPS_LIB_PATH=${LOCALBASE}/lib \
		ALT_FREETYPE_HEADERS_PATH=${LOCALBASE}/include \
		ALT_FREETYPE_LIB_PATH=${LOCALBASE}/lib \
		ALT_X11_PATH=${LOCALBASE} \
		ALT_PACKAGE_PATH=${LOCALBASE} \
		ANT_HOME=${WRKDIR}/apache-ant-${ANTVERSION} \
		BUILD_NUMBER=${BUILD_NUMBER} \
		HS_BUILD_NUMBER=${BUILD_NUMBER} \
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

BUILD_JOBS_NUMBER!=	${SYSCTL} -n kern.smp.cpus
MAKE_ENV+=	HOTSPOT_BUILD_JOBS=${BUILD_JOBS_NUMBER}

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
	@${CP} ${FILESDIR}/fontconfig.properties \
		${WRKDIR}/jdk/src/solaris/classes/sun/awt/fontconfigs/bsd.fontconfig.properties
	@${CP} ${FILESDIR}/cacerts \
		${WRKDIR}/jdk/src/share/lib/security/cacerts

.if defined(WITH_POLICY)
post-patch:
	@${REINPLACE_CMD} 's|build-policy install-limited|build-policy install-unlimited|' \
		${WRKSRC}/jdk/make/javax/crypto/Makefile
.endif

do-install:
	${MKDIR} ${PREFIX}/openjdk6/
	${CP} -Rp ${WRKSRC}/build/${OPENJDK_OSARCH}/j2sdk-image/ ${PREFIX}/openjdk6/
.if defined(WITH_FASTDEBUG)
	${MKDIR} ${PREFIX}/openjdk6-fastdebug/
	${CP} -Rp ${WRKSRC}/build/${OPENJDK_OSARCH}-fastdebug/j2sdk-image/ ${PREFIX}/openjdk6-fastdebug/
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
	# Register the VM
	"${LOCALBASE}/bin/registervm" "${PREFIX}/openjdk6/bin/java # OpenJDK6"
.if defined(WITH_FASTDEBUG)
	"${LOCALBASE}/bin/registervm" "${PREFIX}/openjdk6-fastdebug/bin/java # OpenJDK6"
.endif

.include <bsd.port.post.mk>
