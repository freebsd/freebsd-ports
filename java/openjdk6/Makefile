# New ports collection makefile for:    openjdk6
# Date created:         2009/2/21
# Whom:                 Brian Gardner <brian@experts-exchange.com>
#
# $FreeBSD$
#

PORTNAME=	openjdk6
PORTVERSION=	b16
CATEGORIES=	java devel
MASTER_SITES=	http://download.java.net/openjdk/jdk6/promoted/${PORTVERSION}/
DISTNAME=	openjdk-6-src-${PORTVERSION}-${OPENJDK_BUILDDATE}

MAINTAINER=	brian@experts-exchange.com
COMMENT=	Sun\'s java 6 virtual machine release under the GNUV2 license

RUN_DEPENDS=	javavm:${PORTSDIR}/java/javavmwrapper

OPENJDK_BUILDDATE=24_apr_2009

OPTIONS=	DEBUG   "Enable debugging support"	off \
		IPV6    "Enable IPv6 support"	off \
		POLICY  "Install the Unlimited Strength Policy Files"	off \

# java extracts directly to the cwd
WRKSRC=	${WRKDIR}

USE_GMAKE=	yes
USE_JAVA=	yes
JAVA_VENDOR=	freebsd bsdjava
JAVA_VERSION=	1.6
USE_MOTIF=	yes
USE_XORG=	xtst xi xt x11

LIB_DEPENDS+=	cups.2:${PORTSDIR}/print/cups-base
LIB_DEPENDS+=	freetype.9:${PORTSDIR}/print/freetype2
BUILD_DEPENDS+=	ant:${PORTSDIR}/devel/apache-ant
BUILD_DEPENDS+=	zip:${PORTSDIR}/archivers/zip
BUILD_DEPENDS+=	unzip:${PORTSDIR}/archivers/unzip
BUILD_DEPENDS+=	${JAVAJARDIR}/jdk-7-icedtea-plugs/jre/lib/rt-closed.jar:${PORTSDIR}/java/icedtea6-stubs

.include <bsd.port.pre.mk>

.if defined(WITH_IPV6)
CATEGORIES+=	ipv6
.endif

# avoid ARCH in MAKEFLAGS, breaks build
NOPRECIOUSMAKEVARS= yes

OPENJDK_OSARCH=	bsd-${ARCH:S/i386/i586/}

ONLY_FOR_ARCHS=	amd64 i386

BOOTSTRAP_JDKS=	${LOCALBASE}/diablo-jdk1.6.0

MAKE_ENV=	LANG=C LC_ALL=C \
		ALT_BOOTDIR=${BOOTSTRAP_JDKS} \
		ALT_FREETYPE_HEADERS_PATH=${LOCALBASE}/include \
		ALT_FREETYPE_LIB_PATH=${LOCALBASE}/lib \
		ALT_X11_PATH=${LOCALBASE} \
		ALT_PACKAGE_PATH=${LOCALBASE} \
		ALT_BINARY_PLUGS_PATH=${JAVAJARDIR}/jdk-7-icedtea-plugs \
		ANT_HOME=${LOCALBASE} \
		NO_DOCS=true

.if !defined(WITH_IPV6)
MAKE_ENV+=	DONT_ENABLE_IPV6="YES"
.endif

.if defined(WITH_DEBUG)
MAKE_ENV+=	SKIP_DEBUG_BUILD="false"
.endif

# perhaps we could check to see how many processors are availble and set this equivelent to that
MAKE_ENV+=	HOTSPOT_BUILD_JOBS=4

JDK_MAJOR_VERSION=	6
POLICYFILE=	jce_policy-${JDK_MAJOR_VERSION}.zip

.if defined(WITH_POLICY)
DISTFILES=	${DISTNAME}.tar.gz ${POLICYFILE}
.endif

.if defined(WITH_POLICY) && !exists(${DISTDIR}/${POLICYFILE})#{
DISTFILE_INSTRUCTIONS =\n\
Due to licensing restrictions, certain files must be fetched manually.\n\n
DISTFILE_INSTRUCTIONS += Please open http://java.sun.com/javase/downloads/index.jsp\n\
in a web browser and follow the \"Download\" link for\n\
\"Other Downloads\" to obtain the JCE policy file, ${POLICYFILE}.\n\
This file must be placed is ${PORTSDIR}/distfiles\n\n
.endif#}

pre-fetch:
.if defined(DISTFILE_INSTRUCTIONS)
	@${PRINTF} "${DISTFILE_INSTRUCTIONS}"
	@exit 1
.endif

COPYDIRS= \
	hotspot/src/os/linux/launcher \
	hotspot/src/os/linux/vm \
	hotspot/src/os_cpu/linux_x86/vm \
	hotspot/build/linux \
	hotspot/build/linux/makefiles \
	jdk/src/linux/doc/man

COPYFILES= \
	corba/make/common/Defs-linux.gmk \
	corba/make/common/shared/Defs-linux.gmk \
	jdk/make/common/Defs-linux.gmk \
	jdk/make/common/shared/Defs-linux.gmk \
	jdk/make/java/nio/mapfile-linux \
	jdk/make/netbeans/common/architectures/name-Linux.properties \
	jdk/make/sun/awt/mapfile-vers-linux \
	jdk/make/tools/sharing/classlist.linux \
	jdk/src/solaris/classes/java/lang/UNIXProcess.java.linux \
	jdk/src/solaris/classes/sun/awt/fontconfigs/linux.fontconfig.properties \
	jdk/src/solaris/classes/sun/tools/attach/LinuxAttachProvider.java \
	jdk/src/solaris/hpi/include/largefile_linux.h \
	jdk/src/solaris/native/java/net/linux_close.c \
	jdk/src/solaris/native/sun/tools/attach/LinuxVirtualMachine.c

post-extract:
	@for d in ${COPYDIRS}; do \
		${MKDIR} `echo ${WRKDIR}/$$d | ${SED} 's/linux/bsd/g;'`; \
		cd ${WRKDIR}/$$d; \
		for f in *; do \
			if [ -f $$f ]; then \
				t=`echo ${WRKDIR}/$$d/$$f | ${SED} 's/linux/bsd/g;'`; \
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
	@${CP} ${WRKDIR}/jdk/src/share/lib/security/java.security \
		${WRKDIR}/jdk/src/share/lib/security/java.security-openbsd

do-install:
	${MKDIR} ${PREFIX}/openjdk6/
	${CP} -Rp ${WRKSRC}/build/${OPENJDK_OSARCH}/j2sdk-image/ ${PREFIX}/openjdk6/
	${INSTALL_DATA} ${FILESDIR}/cacerts \
	      ${PREFIX}/openjdk6/jre/lib/security/cacerts
.if defined(WITH_POLICY)
	${INSTALL_DATA} ${WRKDIR}/jce/*.jar ${PREFIX}/openjdk6/jre/lib/security
.endif
	@${FIND} -s ${PREFIX}/openjdk6 -not -type d | \
		${SED} -e 's#^${PREFIX}/##' >> ${TMPPLIST}
	@${ECHO} "@exec mkdir ${PREFIX}/openjdk6/jre/lib/applet" >> ${TMPPLIST}
	@${FIND} ${PREFIX}/openjdk6 -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.post.mk>
