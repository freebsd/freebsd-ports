# New ports collection makefile for: OpenOffice
# Date created:		28 Februar 2002
# Whom:                 Martin Blapp
#
# $FreeBSD$
#

PORTNAME=	openoffice
PORTVERSION=	643
CATEGORIES+=	editors
MASTER_SITES+=	http://ny1.mirror.openoffice.org/developer/%SUBDIR%/ \
		http://ftp.gwdg.de/pub/misc/openoffice/developer/%SUBDIR%/ \
		${MASTER_SITE_RINGSERVER:S,developer/%SUBDIR%,misc/openoffice/&,} \
		ftp://ftp.cs.man.ac.uk/pub/toby/gpc/:gpc \
		http://ny1.mirror.openoffice.org/miscellaneous/helpcontent/:help \
		http://people.freebsd.org/~mbr/ooo/:moz
MASTER_SITE_SUBDIR=	${PORTVERSION}
DISTFILES+=	oo_${PORTVERSION}_src.tar.bz2 neon.tgz:moz \
		gpc231.tar.Z:gpc patch-openoffice-mozilla101-2002-10-14:moz
.if defined(L10NHELP)
DISTFILES+=	${L10NHELP:S/$/:help/}
.endif

SORT?=	/usr/bin/sort
FIND?=	/usr/bin/find
CUT?=	/usr/bin/cut
AWK?=	/usr/bin/awk
GREP?=	/usr/bin/grep
MOUNT?=	/sbin/mount
TCSH?=	/bin/tcsh
ZIP?=	${LOCALBASE}/bin/zip
UNZIP?=	${LOCALBASE}/bin/unzip
ANT?=   ${LOCALBASE}/bin/ant

.include <bsd.port.pre.mk>

PROCFS!=		${MOUNT} | ${GREP} ^procfs | ${AWK} '{print $1}'
INSTALLATION_BASEDIR=	OpenOffice.org-643
DIST_SUBDIR=		openoffice
DICT_DIR=               ${PREFIX}/${INSTALLATION_BASEDIR}/share/dict/ooo/

#
# configuration for language specific slave ports
#
.if !defined(LANG_EXT)
LANG_EXT=01
.else
#
# Add pkg-comment and pkg-descr if available
#
.if exists(${.CURDIR}/pkg-comment)
COMMENT=	${.CURDIR}/pkg-comment
.endif
.if exists(${.CURDIR}/pkg-descr)
DESCR=	${.CURDIR}/pkg-descr
.endif
#
# Set prefix and suffix
#
.if defined(LANG_PKGNAME)
PKGNAMEPREFIX=	${LANG_PKGNAME}-
.if defined(LANG_SUFFIX)
PKGNAMESUFFIX=	-${LANG_SUFFIX}
.endif
.endif # if defined(LANG_PKGNAME)
#
# LANG_CONFIGURE_ARG is missing for the german port
#
.if defined(LANG_EXT) && ${LANG_EXT}!=49
CONFIGURE_ARGS+=	--with-lang=${LANG_CONFIGURE_ARG},ENUS
.endif
.endif

.if ${OSVERSION} < 500000
#
# OO build is broken with the system gcc on STABLE.
#
USE_GCC=3.1
.else
.endif

.if ${OSVERSION} > 500000
#
# OO is still broken with the system gcc on CURRENT.
#
.if defined(USE_GCC) && ${USE_GCC} == 3.2
BUILD_DEPENDS+= gcc32:${PORTSDIR}/lang/gcc32
CC=		gcc32
CXX=		g++32
.endif
.endif

EXTRACT_ONLY=	oo_${PORTVERSION}_src.tar.bz2

MAINTAINER=	openoffice@FreeBSD.org
.if !defined(USE_GCC)
BUILD_DEPENDS=	${LOCALBASE}/lib/libstlport_gcc.so:${PORTSDIR}/devel/stlport
.endif
BUILD_DEPENDS+= zip:${PORTSDIR}/archivers/zip
BUILD_DEPENDS+=	unzip:${PORTSDIR}/archivers/unzip
BUILD_DEPENDS+= ${ANT}:${PORTSDIR}/devel/jakarta-ant
BUILD_DEPENDS+= ${JAVAVM}:${PORTSDIR}/java/jdk13
BUILD_DEPENDS+= ${X11BASE}/lib/libX11.so:${PORTSDIR}/x11/XFree86-4-libraries
.if !defined(DISPLAY)
BUILD_DEPENDS+= Xvfb:${PORTSDIR}/x11-servers/XFree86-4-VirtualFramebufferServer
.endif

USE_PERL5=	yes
USE_BZIP2=	yes
USE_BISON=	yes
USE_GMAKE=	yes

EXTRACT_BEFORE_ARGS_R= -dc
EXTRACT_AFTER_ARGS_R= | ${TAR} -xf -
EXTRACT_CMD_R= ${GZIP_CMD}
EXTRACT_REST=	gpc231.tar.Z neon.tgz

JDK13DIR?=      ${LOCALBASE}/jdk1.3.1
JAVAVM=         ${JDK13DIR}/bin/java

GNU_CONFIGURE=	yes
USE_AUTOCONF=	yes
WRKDIR=		${WRKDIRPREFIX}${.CURDIR}/work
WRKSRC=		${WRKDIR}/oo_${PORTVERSION}_src/config_office
LD_PATH1=	${WRKSRC}/../vos/unxfbsd.pro/lib/:${WRKSRC}/../ucbhelper/unxfbsd.pro/lib/
LD_PATH=	${LD_PATH1}:${WRKSRC}/../solver/643/unxfbsd.pro/lib/
.if defined(WITH_DEBUG)
CFLAGS+=	-g
.if ${WITH_DEBUG} == 2
BUILD=		dmake debug="true"
.else
BUILD=		dmake
.endif
.else
BUILD=		dmake strip="true"
.endif

.if !defined(DISPLAY)
DISPLAYHACK=localhost:1001
.endif

CONFIGURE_ENV=		PTHREAD_CFLAGS=${PTHREAD_CFLAGS} \
			PTHREAD_LIBS=${PTHREAD_LIBS}

CONFIGURE_ARGS+=	--with-jdk-home=${JDK13DIR} \
			--with-os-version=${OSVERSION} \
			--with-ant-home=${LOCALBASE}/jakarta-ant-1.5.1

.if !defined(USE_GCC)
CONFIGURE_ARGS+=	--with-stlport4-home=${PREFIX}
.endif

.if defined(WITH_DEBUG)
.if ${WITH_DEBUG} == 2
CONFIGURE_ARGS+=	--enable-debug
.endif
.endif

.if defined(USE_GCC) && (${USE_GCC} == 3.1 || ${USE_GCC} == 3.2)
CONFIGURE_ARGS+=	--enable-gcc3
.endif

.if ${OSVERSION} > 500000 && !defined(USE_GCC)
CONFIGURE_ARGS+=	--enable-gcc3
.endif

pre-fetch:
	@${ECHO}
	@${ECHO} "REQUIREMENTS:"
.if ${PROCFS}
	@${ECHO}
	@${ECHO} Check if procfs is running: YES
.else
	@${ECHO} -----------------------------------------------------------
	@${ECHO}
	@${ECHO} OpenOffice setup still needs a running procfs, which may
	@${ECHO} not be activated. Please read the procfs\(5\) manpage and
	@${ECHO} ensure the the following line is in /etc/fstab:
	@${ECHO}
	@${ECHO} proc /proc procfs rw 0 0
	@${ECHO}
	@${ECHO} -----------------------------------------------------------
.endif
.if !defined(USE_GCC) || !defined(WITH_DEBUG)
	@${ECHO}
	@${ECHO} "OPTIONS:"
.endif
.if !defined(USE_GCC)
	@${ECHO}
	@${ECHO} "You can compile OO with different"
	@${ECHO} "gcc compiler versions:"
	@${ECHO}
	@${ECHO} "Add USE_GCC=2.95 or USE_GCC=3.1"
	@${ECHO} "to compile openoffice with your"
	@${ECHO} "prefered compiler."
.endif
.if !defined(WITH_DEBUG)
	@${ECHO}
	@${ECHO} "You can compile OO with debug symbols"
	@${ECHO} "if you call make with WITH_DEBUG=1"
	@${ECHO}
	@${ECHO} "If you set WITH_DEBUG=2, you add internal"
	@${ECHO} "OO.org debug support.
	@${ECHO}
.endif
.if !defined(WITH_TTF_BYTECODE_ENABLED)
	@${ECHO}
	@${ECHO} "You may set WITH_TTF_BYTECODE_ENABLED=YES"
	@${ECHO} "if you like to use the Freetype library to"
	@${ECHO} "render TTF fonts. Normally the TTF lib is"
	@${ECHO} "not used to render fonts."
	@${ECHO}
	@${ECHO} "If you have licensed the Apple patents"
	@${ECHO} "US05155805 US05159668 and US05325479"
	@${ECHO} "you can enable this option to get better"
	@${ECHO} "quality of glyphs at small bitmap sizes."
	@${ECHO}
.endif
.if ${OSVERSION} < 450002
	@${ECHO}
	@${ECHO} "OS-VERSION ${OSVERSION} too low"
	@${ECHO}
	@${ECHO} "OO need some important libc_r and"
	@${ECHO} "gcc fixes to build. Please upgrade to 4.6"
	@${ECHO} "RELEASE or 4.6 STABLE."
	@${FALSE}
.endif
	@${ECHO}
	@${ECHO} "NOTICE:"
	@${ECHO}
	@${ECHO} "To build Openoffice, you should have a lot"
.if defined(WITH_DEBUG)
	@${ECHO} "of free diskspace (~ 8GB)."
.else
	@${ECHO} "of free diskspace (~ 4GB)."
.endif
	@${ECHO}
.if (defined(USE_GCC) && ${USE_GCC} == 2.95) || \
    (${OSVERSION} < 500000 && !defined(USE_GCC))
	@${ECHO} "KERNEL CONFIGURATION:"
	@${ECHO}
	@${ECHO} "Openoffice needs a larger stack- and"
	@${ECHO} "datasize to build. Check your limit"
	@${ECHO} "settings and and put this in /boot/loader.conf"
	@${ECHO} "if neccessary:"
	@${ECHO}
	@${ECHO} "kern.maxdsiz=\"1073741824\""
	@${ECHO} "kern.maxssiz=\"268435456\""
.endif
	@${ECHO}
	@${ECHO} "REQUIRED SYSTEM PATCHES:"
	@${ECHO}
	@${ECHO} "OO.org can crash if you enter a non existing path"
	@${ECHO} "or URL in the location bar. To fix these crashes"
	@${ECHO} "you need a uncommitted system patch for rtld:"
	@${ECHO}
	@${ECHO} "http://people.freebsd.org/~mbr/ooo/rtld-symlookup.diff"
	@${ECHO}
.if ${OSVERSION} < 460001
	@${ECHO}
	@${ECHO} "OO setup is broken on STABLE < 4.6"
	@${ECHO} "including 4.6 RELEASE."
	@${ECHO} "You'll need a system patch to solve"
	@${ECHO} "this problem:"
	@${ECHO}
	@${ECHO} "http://people.freebsd.org/~mbr/ooo/rtld-alloca.diff"
	@${ECHO}
.endif
.if ${OSVERSION} < 460002
	@${ECHO}
	@${ECHO} "OO.org soffice binary can deadlock. You can work around"
	@${ECHO} "this problem with this patch:"
	@${ECHO}
	@${ECHO} "http://people.freebsd.org/~mbr/ooo/rtld-deadlock.diff"
	@${ECHO}
.endif
.if ${OSVERSION} < 500000
	@${ECHO}
	@${ECHO} "OO.org build can deadlock in regmerge. You can work around"
	@${ECHO} "this problem with this patch:"
	@${ECHO}
	@${ECHO} "http://people.freebsd.org/~mbr/ooo/rtld-builddeadlock.diff"
	@${ECHO}
.endif
.if !exists(/usr/include/langinfo.h)
	@${ECHO}
	@${ECHO} "langinfo.h is missing !"
	@${ECHO}
	@${ECHO} "Please upgrade to 4.6 RELEASE or"
	@${ECHO} "4.6 STABLE."
	@${ECHO}
	@${FALSE}
.endif

post-extract:
	@for file in ${EXTRACT_REST}; do \
		if ! (cd ${WRKDIR} && ${EXTRACT_CMD_R} \
			${EXTRACT_BEFORE_ARGS_R} \
			${_DISTDIR}/$$file ${EXTRACT_AFTER_ARGS_R}) ; \
		then \
			exit 1; \
		fi \
	done
	@${CP} ${WRKDIR}/gpc231/gpc.c ${WRKSRC}/../external/gpc/
	@${CP} ${WRKDIR}/gpc231/gpc.h ${WRKSRC}/../external/gpc/
	@${CP} -r ${WRKDIR}/neon ${WRKSRC}/../
	@${MAKE} extract-mozilla
	@-${RM} ${WRKSRC}/../moz/zipped/*.zip
	@${CHMOD} +x ${WRKSRC}/../solenv/bin/zipdep.pl
.if defined(L10NHELP)
	@${ECHO_MSG} "===>  Extracting L10NHELP sub project"
	@${MKDIR} ${WRKDIR}/L10NHELP
	@cd ${WRKDIR}/L10NHELP && \
	    ${TAR} -xzf ${DISTDIR}/${DIST_SUBDIR}/${L10NHELP}
.endif

post-patch:
	@${MAKE} patch-mozilla
.if defined(WITH_TTF_BYTECODE_ENABLED)
	@if [ "`echo ${PATCHDIR}/optpatch-*`" != "${PATCHDIR}/optpatch-*" ]; then \
		${ECHO_MSG} "===>  Applying additional TTF bytecode patches for ${PKGNAME}" ; \
		if [ ${PATCH_DEBUG_TMP} = yes ]; then \
			${ECHO_MSG} "===>   Applying ${OPSYS} patch ${PATCHDIR}/optpatch-freetype::patch" ; \
		fi; \
		${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/optpatch-freetype+patch ; \
	fi
.endif
.if defined(WITH_DEBUG)
	@if [ "`echo ${PATCHDIR}/debugpatch-*`" != "${PATCHDIR}/debugpatch-*" ]; then \
		${ECHO_MSG} "===>  Applying additional debug ${OPSYS} patches for ${PKGNAME}" ; \
		PATCHES_APPLIED="" ; \
		for i in ${PATCHDIR}/debugpatch-*; do \
			case $$i in \
				*.orig|*.rej|*~) \
					${ECHO_MSG} "===>   Ignoring patchfile $$i" ; \
					;; \
				*) \
					if [ ${PATCH_DEBUG_TMP} = yes ]; then \
						${ECHO_MSG} "===>   Applying ${OPSYS} patch $$i" ; \
					fi; \
					if ${PATCH} ${PATCH_ARGS} < $$i ; then \
						PATCHES_APPLIED="$$PATCHES_APPLIED $$i" ; \
					else \
						${ECHO_MSG} `${ECHO_CMD} ">> Patch $$i failed to apply cleanly." | ${SED} "s|${PATCHDIR}/||"` ; \
						if [ x"$$PATCHES_APPLIED" != x"" ]; then \
							${ECHO_MSG} `${ECHO_CMD} ">> Patch(es) $$PATCHES_APPLIED applied cleanly." | ${SED} "s|${PATCHDIR}/||g"` ; \
						fi; \
						${FALSE} ; \
					fi; \
					;; \
			esac; \
		done; \
	fi;
.endif
	@${ECHO_MSG} "===>  Find old malloc.h defines and fix them in ${PKGNAME} source"
	@${FIND} ${WRKSRC}/.. | ${EGREP} "\.(cxx|h|c)$$" | ${XARGS} \
		${PERL} -pi -e "s|<malloc.h>|<stdlib.h>|g"

extract-mozilla:
.if ! exists(${WRKDIR}/mozilla/Makefile)
	@${ECHO_MSG} "===>  Extracting mozilla sub project"
	@${MKDIR} ${WRKDIR}/mozilla
	@${CP} -r ${PORTSDIR}/www/mozilla-vendor/files ${WRKDIR}/mozilla
	@${CP} ${PORTSDIR}/www/mozilla-vendor/Makefile ${WRKDIR}/mozilla
	@${CP} ${PORTSDIR}/www/mozilla-vendor/distinfo ${WRKDIR}/mozilla
	@${CP} ${PORTSDIR}/www/mozilla-vendor/pkg-comment ${WRKDIR}/mozilla
	@${CP} ${PORTSDIR}/www/mozilla-vendor/pkg-descr ${WRKDIR}/mozilla
	@${CP} ${PORTSDIR}/www/mozilla/pkg-message ${WRKDIR}/mozilla
.endif
	@cd ${WRKDIR}/mozilla && ${MAKE} extract WRKDIRPREFIX=""

patch-mozilla:
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/patch-openoffice-mozilla101-2002-10-14 \
		${WRKDIR}/mozilla/files/
	@cd ${WRKDIR}/mozilla && ${MAKE} patch WRKDIRPREFIX=""

build-mozilla:
.if ! exists(${WRKDIR}/FREEBSDGCCIruntime.zip)
	@${ECHO_MSG} "===>  Building mozilla sub project"
.if defined(WITH_DEBUG)
	@${CP} ${WRKDIR}/mozilla/Makefile ${WRKDIR}/mozilla/Makefile.new
	@${SED} -e 's|--disable-debug||' \
		-e 's|--disable-cpp-rtti||' \
		-e 's|--enable-strip||' \
		< ${WRKDIR}/mozilla/Makefile.new > ${WRKDIR}/mozilla/Makefile
.endif
.if defined(USE_GCC)
.if ${USE_GCC} == 3.1
	@cd ${WRKDIR}/mozilla && ${MAKE} CXX=${CXX} CC=${CC} CFLAGS="${CFLAGS}" USE_GCC=${USE_GCC} build WRKDIRPREFIX=""
.else
	@cd ${WRKDIR}/mozilla && ${MAKE} CFLAGS="${CFLAGS}" USE_GCC=${USE_GCC} build WRKDIRPREFIX=""
.endif
.else
	@cd ${WRKDIR}/mozilla && ${MAKE} CFLAGS="${CFLAGS}" build WRKDIRPREFIX=""
.endif
	@${CP} ${FILESDIR}/zipmoz.sh ${WRKDIR}
	@${CHMOD} 755 ${WRKDIR}/zipmoz.sh
	@${WRKDIR}/zipmoz.sh ${WRKDIR}/mozilla/work/mozilla/dist FREEBSDGCCI ${WRKDIR}
.endif

install-mozilla:
.if ! exists(${WRKDIR}/../moz/zipped/FREEBSDGCCIinc.zip)
	@${CP} ${WRKDIR}/FREEBSDGCCIinc.zip ${WRKSRC}/../moz/zipped/
	@${CP} ${WRKDIR}/FREEBSDGCCIlib.zip ${WRKSRC}/../moz/zipped/
	@${CP} ${WRKDIR}/FREEBSDGCCIruntime.zip ${WRKSRC}/../moz/zipped/
.endif

register-mozilla:
.if exists(${WRKDIR}/mozilla-runtime)
	@${RM} -rf ${WRKDIR}/mozilla-runtime
.endif
	@${MKDIR} ${WRKDIR}/mozilla-runtime
	@cd ${WRKDIR}/mozilla-runtime && ${UNZIP} -o ${WRKDIR}/FREEBSDGCCIruntime.zip
	@cd ${WRKDIR}/mozilla-runtime && ${UNZIP} -o ${WRKDIR}/FREEBSDGCCIlib.zip
	@${CP} ${WRKDIR}/mozilla/work/mozilla/dist/bin/regxpcom ${WRKDIR}/mozilla-runtime/
	@-${RM} ${WRKDIR}/mozilla-runtime/components/component.reg
	@cd ${WRKDIR}/mozilla-runtime && export MOZILLA_FIVE_HOME=. \
		&& export LD_LIBRARY_PATH=.:./lib && ./regxpcom 
	@${CP} ${WRKDIR}/mozilla-runtime/components/xpti.dat \
		${WRKDIR}/mozilla-runtime/components/xptitemp.dat
	@${RM} ${WRKDIR}/FREEBSDGCCIruntime.zip ${WRKDIR}/mozilla-runtime/regxpcom
	@cd ${WRKDIR}/mozilla-runtime && ${FIND} . -type f \
		| ${ZIP} ${WRKDIR}/FREEBSDGCCIruntime.zip -@

mozilla:
	@${MAKE} extract-mozilla
	@${MAKE} patch-mozilla
	@${MAKE} build-mozilla
	@${MAKE} register-mozilla
	@${MAKE} install-mozilla

do-build:
.if ! exists(${WRKDIR}/../moz/zipped/FREEBSDGCCIinc.zip)
	@${MAKE} mozilla
.endif
.if exists(${WRKDIR}/.Xvfb.pid)
	@-${CAT} ${WRKDIR}/.Xvfb.pid | xargs kill
	@${RM} -f ${WRKDIR}/.Xvfb.pid
.endif
.if !defined(DISPLAY)
	#
	# This is a UGLY hack to not have to specify a X-Display.
	#
	${X11BASE}/bin/Xvfb :1001 -screen 0 800x600x24 > /dev/null 2>&1 & ${ECHO} $$! > ${WRKDIR}/.Xvfb.pid
	@sleep 5
.endif
	@cd ${WRKSRC}/.. && PATH="${PATH}:${LOCALBASE}/bin:${LOCALBASE}/sbin" ./bootstrap
.if defined(L10NHELP)
	@${MKDIR} ${WRKSRC}/../solver/641/unxfbsd.pro/pck 
	@${CP} ${WRKDIR}/L10NHELP/*.zip ${WRKSRC}/../solver/641/unxfbsd.pro/pck
.endif
.if !defined(DISPLAY)
	@cd ${WRKSRC}/.. && DISPLAY=${DISPLAYHACK} PATH="${PATH}:${LOCALBASE}/bin:${LOCALBASE}/sbin" && \
		${TCSH} -c 'source FreeBSDEnv.Set && unsetenv TOP && ${BUILD}'
	@-${CAT} ${WRKDIR}/.Xvfb.pid | xargs kill
	@${RM} -f ${WRKDIR}/.Xvfb.pid
.else
	@cd ${WRKSRC}/.. && DISPLAY=${DISPLAY} PATH="${PATH}:${LOCALBASE}/bin:${LOCALBASE}/sbin" && \
		${TCSH} -c 'source FreeBSDEnv.Set && unsetenv TOP && ${BUILD}'
.endif
.if defined(LANG_PKGNAME)
	@cd ${WRKSRC}/.. && PATH="${PATH}:${LOCALBASE}/bin:${LOCALBASE}/sbin" && \
		${TCSH} -c 'source FreeBSDEnv.Set && unsetenv TOP && cd instsetoo/util && ${BUILD} LANGEXT=${LANGEXT}'
.endif

pre-install:
	@${SED} -e 's#%%PREFIX%%#${PREFIX}#g' < ${FILESDIR}/oo_setup.resp \
	   > ${WRKSRC}/../instsetoo/unxfbsd.pro/${LANG_EXT}/normal/oo_setup.resp

do-install:
.if !defined(DISPLAY)
	#
	# UGLY hack to not have to specify a X-Display.
	#
	${X11BASE}/bin/Xvfb :1001 -screen 0 800x600x24 > /dev/null 2>&1 & ${ECHO} $$! > ${WRKDIR}/.Xvfb.pid
	@sleep 5
	@-SAL_IGNOREXERRORS=1 PATH="/bin:${PATH}" LD_LIBRARY_PATH=${LD_PATH} \
		TEMP=${WRKDIR} DISPLAY=${DISPLAYHACK} \
		${WRKSRC}/../instsetoo/*.pro/${LANG_EXT}/normal/setup -r:oo_setup.resp
	@-${CAT} ${WRKDIR}/.Xvfb.pid | xargs kill
	@${RM} -f ${WRKDIR}/.Xvfb.pid
.else
	@-SAL_IGNOREXERRORS=1 PATH="/bin:${PATH}" LD_LIBRARY_PATH=${LD_PATH} \
		TEMP=${WRKDIR} DISPLAY=${DISPLAY} \
		${WRKSRC}/../instsetoo/*.pro/${LANG_EXT}/normal/setup -r:oo_setup.resp
.endif

install-user:
	@-SAL_IGNOREXERRORS=1 PATH="/bin:${PATH}" \
		${PREFIX}/${INSTALLATION_BASEDIR}/program/setup

post-install:
	@${ECHO_MSG} "===>  Add wrapper scripts";
	@${SED} -e 's#%%PREFIX%%#${PREFIX}#g' < ${FILESDIR}/openoffice-wrapper \
	   > ${WRKDIR}/openoffice
	@${INSTALL_SCRIPT} ${WRKDIR}/openoffice ${PREFIX}/bin/openoffice-643
	@${LN} -fs ${PREFIX}/bin/openoffice ${PREFIX}/bin/openoffice-sagenda-643
	@${LN} -fs ${PREFIX}/bin/openoffice ${PREFIX}/bin/openoffice-scalc-643
	@${LN} -fs ${PREFIX}/bin/openoffice ${PREFIX}/bin/openoffice-sdraw-643
	@${LN} -fs ${PREFIX}/bin/openoffice ${PREFIX}/bin/openoffice-setup-643
	@${LN} -fs ${PREFIX}/bin/openoffice ${PREFIX}/bin/openoffice-sfax-643
	@${LN} -fs ${PREFIX}/bin/openoffice ${PREFIX}/bin/openoffice-simpress-643
	@${LN} -fs ${PREFIX}/bin/openoffice ${PREFIX}/bin/openoffice-spadmin-643
	@${LN} -fs ${PREFIX}/bin/openoffice ${PREFIX}/bin/openoffice-sweb-643
	@${LN} -fs ${PREFIX}/bin/openoffice ${PREFIX}/bin/openoffice-swriter-643
	@cd ${PREFIX} && ${FIND} -s bin -type f | ${GREP} openoffice > ${TMPPLIST}
	@cd ${PREFIX} && ${FIND} -s bin -type l | ${GREP} openoffice >> ${TMPPLIST}
	@cd ${PREFIX} && ${FIND} -s ${INSTALLATION_BASEDIR} -type f >> ${TMPPLIST}
	@cd ${PREFIX} && ${FIND} -s ${INSTALLATION_BASEDIR} -type l >> ${TMPPLIST}
	@cd ${PREFIX} && ${FIND} -s ${INSTALLATION_BASEDIR} -type d > ${WRKDIR}/dir.tmp
	@${SORT} -r ${WRKDIR}/dir.tmp | ${XARGS} -n 1 ${ECHO_CMD} @dirrm >> ${TMPPLIST}

package-rename:
	@${ECHO_MSG} "===>   Rename package for OO.org mirror upload";
.if defined(LANG_SUFFIX)
	@${MV} ${WRKDIR}/../${PKGNAMEPREFIX}openoffice-${LANG_SUFFIX}-${PORTVERSION}_${PORTREVISION}.tbz2 \
	    ${WRKDIR}/../OOo_${PORTVERSION}_${OPSYS}Intel_install_${LANG_PKGNAME}-${LANG_SUFFIX}.tbz2
.else
	@${MV} ${WRKDIR}/../${PKGNAMEPREFIX}openoffice-${PORTVERSION}_${PORTREVISION}.tbz2 \
	    ${WRKDIR}/../OOo_${PORTVERSION}_${OPSYS}Intel_install_${LANG_PKGNAME}.tbz2
.endif

.include <bsd.port.post.mk>
