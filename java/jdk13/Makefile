# New ports collection makefile for:	jdk13
# Date created:				10 October 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jdk
PORTVERSION=	${JDK_VERSION}p${JDK_PATCHSET_VERSION}
PORTREVISION=	2
CATEGORIES=	java devel
MASTER_SITES=	# http://www.sun.com/software/java2/download.html
#		 http://www.eyesbeyond.com/freebsddom/java/jdk13.html
SRCFILE=	j2sdk-${JDK_VERSION:S/./_/g}-src${EXTRACT_SUFX}
PATCHSETFILE=	bsd-jdk131-patches-${JDK_PATCHSET_VERSION}.tar.gz
DISTFILES=	${SRCFILE} ${PATCHSETFILE}

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	Java Development Kit 1.3

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4 \
		zip:${PORTSDIR}/archivers/zip \
		${X11BASE}/lib/libXm.so:${PORTSDIR}/x11-toolkits/open-motif
.if !defined(NATIVE_BOOTSTRAP)
BUILD_DEPENDS+=	${JDK13DIR}/bin/javac:${PORTSDIR}/java/linux-blackdown-jdk13
.endif
.if !defined(WITHOUT_PLUGIN)
BUILD_DEPENDS+=	msgfmt:${PORTSDIR}/devel/gettext
LIB_DEPENDS=	glib12.3:$(PORTSDIR)/devel/glib12 \
		gtk12.2:$(PORTSDIR)/x11-toolkits/gtk12 \
		nspr4.1:$(PORTSDIR)/devel/nspr
.endif
RUN_DEPENDS=	javavm:${PORTSDIR}/java/javavmwrapper \
		${X11BASE}/lib/libXm.so:${PORTSDIR}/x11-toolkits/open-motif \
		${X11BASE}/lib/X11/fonts/URW/fonts.dir:${PORTSDIR}/x11-fonts/urwfonts

.if defined(WITH_JAPANESE_FONTS)
RUN_DEPENDS+=	${X11BASE}/lib/X11/fonts/TrueType/fonts.dir.kochi:${PORTSDIR}/japanese/kochi-ttfonts
.endif
.if defined(WITH_RUSSIAN_FONTS)
RUN_DEPENDS+=	${X11BASE}/lib/X11/fonts/webfonts/fonts.dir:${PORTSDIR}/x11-fonts/webfonts
.endif
.if defined(WITH_CHINESE_FONTS)
RUN_DEPENDS+=	${LOCALBASE}/share/fonts/TrueType/arphic:${PORTSDIR}/chinese/arphicttf
.endif

WRKSRC=		${WRKDIR}/j2sdk1.3.1/make

JDK_VERSION=	1.3.1
JDK_PATCHSET_VERSION=	8

.if defined(NATIVE_BOOTSTRAP)
JDK13DIR?=	${LOCALBASE}/jdk${JDK_VERSION}
.else
JDK13DIR?=	${LOCALBASE}/linux-blackdown-jdk${JDK_VERSION}
.endif

ONLY_FOR_ARCHS=	i386
USE_GMAKE=	yes
RESTRICTED=	"Redistribution of pre-compiled binaries is not permitted"
NO_CDROM=	"Redistribution of pre-compiled binaries is not permitted"
MAKE_ENV=	ALT_BOOTDIR="${JDK13DIR}" \
		ALT_MOTIF_DIR="${X11BASE}" \
		OPENWINHOME="${X11BASE}" \
		SYS_CFLAGS="${CFLAGS}" \
		CLASSPATH="" \
		LD_LIBRARY_PATH="" \
		JAVA_COMPILER=""
.if !defined(WITHOUT_PLUGIN)
MAKE_ENV +=	LIBG_HDRS="${LOCALBASE}/include/glib12" \
		GTK_HDRS="${X11BASE}/include/gtk12" \
		LIBIDL_HDRS=
.endif
.if !defined(WITHOUT_PLUGIN)
ALL_TARGET=	all plugin images
.else
ALL_TARGET=	all images
.endif
PLIST_SUB+=	JDK_VERSION=${JDK_VERSION}

JDKIMAGEDIR=	${WRKSRC}/../build/bsd-i386/jdk-image-i386
JDKIMAGEDIR_G=	${WRKSRC}/../build/bsd-i386/jdk-debug-image-i386

SORT?=		/usr/bin/sort
CPIO?=		/usr/bin/cpio

.if defined(NODEBUG)
PLIST_SUB+=	DEBUG:="@comment "
PKGNAMESUFFIX=	-nodebug
.else
PLIST_SUB+=	DEBUG:=""
.endif

.if defined(WITH_NATIVE_THREADS) || defined(WITH_HOTSPOT)
PLIST_SUB+=    NATIVE:=""
MAKE_ARGS+=    HPIS="green native"
.else
PLIST_SUB+=    NATIVE:="@comment "
.endif

.if defined(WITHOUT_PLUGIN)
PLIST_SUB+=    PLUGIN:="@comment "
.else
PLIST_SUB+=    PLUGIN:=""
.endif

.if defined(WITH_HOTSPOT)
PLIST_SUB+=    HOTSPOT:=""
USE_REINPLACE= yes
.if defined(NODEBUG)
HOTSPOT_TARGETS=product1 product
.else
HOTSPOT_TARGETS=compiler1 compiler2
.endif
.else
PLIST_SUB+=    HOTSPOT:="@comment "
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_HOTSPOT) && ${OSVERSION} < 500039
USE_GCC=	3.2
BUILD_DEPENDS+=	gcc32:${PORTSDIR}/lang/gcc32
MAKE_ENV+=	ALT_COMPILER_PATH=${LOCALBASE}/bin
HOTSPOT_BUILD=	../ext/plugin/build/solaris/GNUmakefile \
	../../hotspot1.3.1/build/linux/makefiles/adlc.make \
	../../hotspot1.3.1/build/linux/platform_i486
.endif

.if ${OSVERSION} < 460101 || ( ${OSVERSION} >= 500000 && ${OSVERSION} < 500038 )
EXTRACT_DEPENDS+=	gtar:${PORTSDIR}/archivers/gtar
TAR=			gtar	# Necessary for proper extraction of sources
.endif

# Check for patchset
.if !exists(${DISTDIR}/${PATCHSETFILE}) && !defined(PACKAGE_BUILDING)
ECHO_MSG=/usr/bin/printf
IGNORE= :\n\
The source distribution exists on your system, but due to\n\
licensing restrictions you still need to download the\n\
patchset, ${PATCHSETFILE}, from\n\
http://www.eyesbeyond.com/freebsddom/java/jdk13.html.\n\
Please place the patchset in ${DISTDIR}.\n
.endif

# Check for JDK sources
.if !exists(${DISTDIR}/${SRCFILE}) && !defined(PACKAGE_BUILDING)
ECHO_MSG=/usr/bin/printf
IGNORE= :\n\
Because of licensing restrictions, you must fetch the source distribution\n\
manually.  Please access http://www.sun.com/software/java2/download.html\n\
with a web browser and follow the \"Download\" link for the\n\
\"Java(TM) SDK ${JDK_VERSION}\". You will be required to log in and register,\n\
but you can create an account on this page.  After registration and\n\
accepting the Sun Community Source License, select \"J2SESDK\" and\n\
download the source file, ${SRCFILE}.  Please place this file in\n\
${DISTDIR}.\n
.endif

# HotSpot and/or native threads require a recent version of FreeBSD
.if ( defined(WITH_NATIVE_THREADS) || defined(WITH_HOTSPOT) ) && ( ${OSVERSION} < 470101 || ( ${OSVERSION} >= 500000 && ${OSVERSION} < 500043 ) )
ECHO_MSG=/usr/bin/printf
IGNORE= :\n\
You must have a version of FreeBSD later than 4.7-STABLE February 2003\n\
or 5-CURRENT February 2003 to use either native threads or HotSpot.\n
.endif

# Warn user about HotSpot build
.if defined(WITH_HOTSPOT)
pre-everything:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You have set WITH_HOTSPOT to enable the build of the HotSpot VM."
	@${ECHO_MSG} "Please note that HotSpot development is still experimental and is"
	@${ECHO_MSG} "not suitable for use in a production environment."
	@${ECHO_MSG} "To use the browser plugin with HotSpot you will need to set the"
	@${ECHO_MSG} "THREADS_FLAG environment variable when running the browser, e.g."
	@${ECHO_MSG} "    setenv THREADS_FLAG native"
	@${ECHO_MSG} ""
.endif

pre-patch:
	@cd ${WRKDIR} &&  \
		${CHMOD} -R u+w * && \
		${MKDIR} j2sdk1.3.1/ext/plugin/oji-plugin/include/bsd/jdk12 && \
		${MKDIR} j2sdk1.3.1/ext/plugin/oji-plugin/include/solaris/navig5/private && \
		${MKDIR} j2sdk1.3.1/src/bsd/doc/man && \
		${MKDIR} hotspot1.3.1/build/bsd && \
		${MKDIR} hotspot1.3.1/build/bsd/makefiles && \
		${MKDIR} hotspot1.3.1/build/bsd/package && \
		${MKDIR} hotspot1.3.1/src/os/bsd/launcher && \
		${MKDIR} hotspot1.3.1/src/os/bsd/vm && \
		${MKDIR} hotspot1.3.1/src/os_cpu/bsd_i486/vm && \
			${PATCH} < ${WRKDIR}/jdk131.patches

post-patch:
.if defined(WITH_HOTSPOT)
.if defined(USE_GCC) && ${USE_GCC} == 3.2
	@for file in ${HOTSPOT_BUILD}; do \
        	${REINPLACE_CMD} -e "s:gcc:gcc32:g ; s:g\+\+:g\+\+32:g" ${WRKSRC}/$${file}; \
	done
	@${REINPLACE_CMD} -e "s:PATH[)]gcc:PATH)gcc32:g ; s:PATH[)]g\+\+:PATH)g\+\+32:g" ${WRKSRC}/common/Defs-bsd.gmk 
.endif
.endif

.if !defined(NATIVE_BOOTSTRAP)
pre-build:
	@if [ "$${WRKDIRPREFIX}" -a \
	     -L "/compat/linux/$${WRKDIRPREFIX}" -a \
	     x`ls -ld "/compat/linux/$${WRKDIRPREFIX}" 2>/dev/null | awk '/->/{print $$NF;exit 0}END{exit 1}'` = x"$${WRKDIRPREFIX}" ]; \
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
.endif

do-build:
	# Start of jdk build
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})
.if defined(WITH_HOTSPOT)
	# Start of HotSpot build
	@(cd ${WRKDIR}/hotspot1.3.1/build/linux ;  \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${HOTSPOT_TARGETS})
.endif

post-build:
.if defined(WITH_HOTSPOT)
	# Copy HotSpot VM to image dir
	${MKDIR} ${JDKIMAGEDIR}/jre/lib/i386/client
	${INSTALL_PROGRAM} ${WRKDIR}/hotspot1.3.1/build/linux/linux_i486_compiler1/product/libjvm.so ${JDKIMAGEDIR}/jre/lib/i386/client/
	${INSTALL_DATA} ${WRKDIR}/hotspot1.3.1/src/share/vm/Xusage.txt ${JDKIMAGEDIR}/jre/lib/i386/client/
	${MKDIR} ${JDKIMAGEDIR}/jre/lib/i386/server
	${INSTALL_PROGRAM} ${WRKDIR}/hotspot1.3.1/build/linux/linux_i486_compiler2/product/libjvm.so ${JDKIMAGEDIR}/jre/lib/i386/server/
	${INSTALL_DATA} ${WRKDIR}/hotspot1.3.1/src/share/vm/Xusage.txt ${JDKIMAGEDIR}/jre/lib/i386/server/
	@(cd ${JDKIMAGEDIR}/jre/lib/i386; ${LN} -sf client hotspot)
.if !defined(NODEBUG)
	# Copy debug version of HotSpot VM to image dir
	${MKDIR} ${JDKIMAGEDIR_G}/jre/lib/i386/client
	${INSTALL_PROGRAM} ${WRKDIR}/hotspot1.3.1/build/linux/linux_i486_compiler1/jvmg/libjvm_g.so ${JDKIMAGEDIR_G}/jre/lib/i386/client/
	${MKDIR} ${JDKIMAGEDIR_G}/jre/lib/i386/server
	${INSTALL_PROGRAM} ${WRKDIR}/hotspot1.3.1/build/linux/linux_i486_compiler2/jvmg/libjvm_g.so ${JDKIMAGEDIR_G}/jre/lib/i386/server/
.endif
.endif
	# Ensure SwingSet2 resources directory doesn't exist (sometimes it
	# does on FreeBSD 5.x)
	${RM} -rf ${JDKIMAGEDIR}/demo/jfc/SwingSet2/resources
	# Prune empty dirs
	${FIND} ${JDKIMAGEDIR} -type d | ${SORT} -r | \
		${XARGS} ${RMDIR} 2> /dev/null || ${TRUE}
	${FIND} ${JDKIMAGEDIR_G} -type d | ${SORT} -r | \
		${XARGS} ${RMDIR} 2> /dev/null || ${TRUE}

.if !defined(NODEBUG)
pre-install:
	@${ECHO_MSG}
	@${ECHO_MSG} "Please use \`make -DNODEBUG' if you don't want to install libraries and binaries"
	@${ECHO_MSG} "with debugging support."
	@${ECHO_MSG}
.endif

do-install:
	${MKDIR} ${PREFIX}/jdk${JDK_VERSION}
	cd ${JDKIMAGEDIR} && ${FIND} . \
	  | ${CPIO} -pdmu -R ${LIBOWN}:${LIBGRP} ${PREFIX}/jdk${JDK_VERSION}
.if !defined(NODEBUG)
	cd ${JDKIMAGEDIR_G} && ${FIND} . \
	  | ${CPIO} -pdmu -R ${LIBOWN}:${LIBGRP} ${PREFIX}/jdk${JDK_VERSION}
.endif
	${MKDIR} ${PREFIX}/jdk${JDK_VERSION}/jre/lib/ext
	${MKDIR} ${PREFIX}/share/doc/java

post-install:
	@${LOCALBASE}/bin/registervm "${PREFIX}/jdk${JDK_VERSION}/bin/java # FREEBSD-JDK${JDK_VERSION}"
.if !defined(WITHOUT_PLUGIN)
	@${ECHO_MSG}
	@${ECHO_MSG} To use the Java plugin with Mozilla you must create a
	@${ECHO_MSG} symbolic link from
	@${ECHO_MSG}
	@${ECHO_MSG} ${PREFIX}/jdk${JDK_VERSION}/jre/plugin/i386/ns600/libjavaplugin_oji.so
	@${ECHO_MSG}
	@${ECHO_MSG} to your Mozilla plugins directory, which is usually found at
	@${ECHO_MSG}
	@${ECHO_MSG} ${X11BASE}/lib/mozilla/plugins
	@${ECHO_MSG}
.endif

.include <bsd.port.post.mk>
