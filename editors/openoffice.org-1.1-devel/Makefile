# New ports collection makefile for: OpenOffice.org
# Date created:		28 Februar 2002
# Whom:                 Martin Blapp
#
# $FreeBSD$
#

PORTNAME=	openoffice
PORTVERSION=	1.1.2.${SNAPDATE}
CATEGORIES+=	editors
MASTER_SITES+=	${MASTER_SITE_LOCAL} \
		ftp://ftp.cs.man.ac.uk/pub/toby/gpc/:gpc \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,misc/openoffice/contrib/helpcontent/&,}:help \
		ftp://ftp.kddlabs.co.jp/office/openoffice/contrib/helpcontent/:help \
		ftp://sunsite.cnlab-switch.ch/mirror/OpenOffice/contrib/helpcontent/:help \
		http://ftp.services.openoffice.org/pub/OpenOffice.org/contrib/helpcontent/:help \
		http://people.freebsd.org/~mbr/ooo/:moz
MASTER_SITE_SUBDIR=	maho/openoffice.org
LATEST_LINK=	${PORTNAME}-${PORTVERSION}-devel
DISTFILES+=	OOo_${PORTVERSION}_source.tar.bz2 gpc231.tar.Z:gpc \
		patch-openoffice-mozilla101-2002-10-14:moz mozilla-vendor-1.0.2a.tgz:moz
.if defined(L10NHELP)
DISTFILES+=	${L10NHELP:S/$/:help/}
.endif
EXTRACT_ONLY=	OOo_${PORTVERSION}_source.tar.bz2

ZIP?=	${PREFIX}/bin/zip
UNZIP?=	${PREFIX}/bin/unzip
ANT?=	${LOCALBASE}/bin/ant
TCSH?=	/bin/tcsh

USE_GNOME=	orbit gtk12 gtk20
USE_REINPLACE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		"Does not compile on 4.x (tries to link to libpthread)"
.endif

BUILD_NR=		645
RELEASE_NR=		1.1
FRELEASE_NR=		1.1.2
SNAPDATE=		20040518
INSTALLATION_BASEDIR=	OpenOffice.org${FRELEASE_NR}
DIST_SUBDIR=		openoffice1.1
DICT_DIR=               ${PREFIX}/${INSTALLATION_BASEDIR}/share/dict/ooo/
SIMPLEOSVER!=		${UNAME} -r | sed -e 's/\.//' | sed -e 's/\..*//'

#
# configuration for language specific slave ports
#
.if !defined(LANG_EXT)
LANG_EXT=01
.else
#
# Add pkg-descr and pkg-message if available
#
.if exists(${.CURDIR}/pkg-descr)
DESCR=  ${.CURDIR}/pkg-descr
.endif
.if exists(${.CURDIR}/pkg-message)
PKGMESSAGE=     ${.CURDIR}/pkg-message
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
.if defined(LANG_EXT)
CONFIGURE_ARGS+=	--with-lang=${LANG_CONFIGURE_ARG},ENUS
.endif
.endif

.if !defined (LANG) && !defined(USE_LANG)
USE_LANG=	en_US.ISO8859-15
LANG_LIST=	en_US.ISO8859-15 en_US.ISO8859-1 US-ASCII
.else
.if !defined(USE_LANG)
USE_LANG=	${LANG}
.endif
.endif

LANG_SORTED=`${ECHO} ${LANG_LIST} | ${TR} " " "\n" | ${PASTE} -d " " - -`

# OOo requires gcc 3.2 (currently 3.3 is not supported)
BUILD_DEPENDS+= gcc32:${PORTSDIR}/lang/gcc32
USE_GCC=3.2
# XXX dirty
CC=	gcc32
CXX=	g++32

MAINTAINER=	openoffice@FreeBSD.org
.if !defined(COMMENT)
COMMENT=	Integrated wordprocessor/dbase/spreadheet/drawing/chart/browser
.endif

#
# The JDK dependency needs to be at the first place, so all
# following dependencies use the same JDK.
#
BUILD_DEPENDS+= ${JAVAVM}:${PORTSDIR}/java/jdk14 \
		zip:${PORTSDIR}/archivers/zip \
		unzip:${PORTSDIR}/archivers/unzip \
		gcp:${PORTSDIR}/sysutils/coreutils \
		${ANT}:${PORTSDIR}/devel/apache-ant \
		${X11BASE}/lib/libXft.so:${PORTSDIR}/x11-fonts/libXft
.if !defined(DISPLAY)
BUILD_DEPENDS+= Xvfb:${X_VFBSERVER_PORT}
.endif

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		mng.1:${PORTSDIR}/graphics/libmng \
		freetype.9:${PORTSDIR}/print/freetype2

USE_PERL5=	yes
USE_BZIP2=	yes
USE_BISON=	yes
USE_GMAKE=	yes

EXTRACT_BEFORE_ARGS_R= -dc
EXTRACT_AFTER_ARGS_R= | ${TAR} -xf -
EXTRACT_CMD_R= ${GZIP_CMD}
EXTRACT_REST=	gpc231.tar.Z

JDKDIR?=	${LOCALBASE}/jdk1.4.2
JAVAVM=		${JDKDIR}/bin/java

GNU_CONFIGURE=	yes
USE_AUTOCONF_VER= 253
WRKDIR=		${WRKDIRPREFIX}${.CURDIR}/work
WRKSRC=		${WRKDIR}/oo_${FRELEASE_NR}_src/config_office
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
CONFIGURE_ARGS+=	--with-gnu-cp=${LOCALBASE}/bin/gcp --with-jdk-home=${JDKDIR}

.if defined(WITH_DEBUG)
.if ${WITH_DEBUG} == 2
CONFIGURE_ARGS+=	--enable-debug
.endif
.endif

pre-fetch:
	@${ECHO}
.if !defined(LANG)
	@${ECHO} "REQUIREMENTS:"
	@${ECHO}
	@${ECHO} "OO requires that the ENV variable LANG"
	@${ECHO} "is set to a proper value. Dependent on"
	@${ECHO} "which language port you use, OO does"
	@${ECHO} "automatically set LANG to a suitable"
	@${ECHO} "value. You can change this with:"
	@${ECHO}
	@${ECHO} "USE_LANG=\"preferred language\""
	@${ECHO}
	@${ECHO} "and set a different language"
	@${ECHO} "like:"
	@${ECHO}
	@${ECHO} "${LANG_SORTED}"
	@${ECHO}
	@${ECHO} "Your current setting is:"
	@${ECHO}
	@${ECHO} "USE_LANG=${USE_LANG}"
	@${ECHO}
	@${ECHO}
.endif
	@${ECHO} "OPTIONS:"
.if !defined(WITH_DEBUG)
	@${ECHO}
	@${ECHO} "You can compile OO with debug symbols"
	@${ECHO} "if you call make with WITH_DEBUG=1"
	@${ECHO}
	@${ECHO} "If you set WITH_DEBUG=2, you add internal"
	@${ECHO} "OO.org debug support."
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
.if !defined(WITH_GIF_LZW_COMPRESSION)
	@${ECHO}
	@${ECHO} "You may set WITH_GIF_LZW_COMPRESSION=YES"
	@${ECHO} "If you want to make compressed gif images"
	@${ECHO}
	@${ECHO} "If must have license from the Unisys and IBM patents"
	@${ECHO} "to enable this option to get compressed GIF images."
	@${ECHO} "According to http://www.unisys.com/about__unisys/lzw"
	@${ECHO} "Patent expires:"
	@${ECHO} "June 20, 2003 : U.S."
	@${ECHO} "June 18, 2004 : U.K., France, Germany and Italy"
	@${ECHO} "June 20, 2004 : Japan"
	@${ECHO} "July  7, 2004 : Canada"
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
.if ${OSVERSION} < 460002
	@${ECHO} "REQUIRED SYSTEM PATCHES:"
	@${ECHO}
.endif
.if ${OSVERSION} < 490100
	@${ECHO} "OO.org can crash if you enter a non existing path"
	@${ECHO} "or URL in the location bar. To fix these crashes"
	@${ECHO} "you need a uncommitted system patch for rtld:"
	@${ECHO}
	@${ECHO} "http://people.freebsd.org/~mbr/ooo/rtld-symlookup.diff"
	@${ECHO}
.endif
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
.if ${OSVERSION} < 490100
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
	@${ECHO} "If you want SDK and/or solver, please type make sdk and/or make solver"

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
	@${MAKE} extract-mozilla
	@-${RM} -f ${WRKSRC}/../moz/zipped/*.zip
	@${CHMOD} +x ${WRKSRC}/../solenv/bin/zipdep.pl
.if defined(L10NHELP)
	@${ECHO_MSG} "===>  Extracting L10NHELP sub project"
	@${MKDIR} ${WRKDIR}/L10NHELP
	@cd ${WRKDIR}/L10NHELP && \
		${CAT} ${DISTDIR}/${DIST_SUBDIR}/${L10NHELP} | ${GZIP_CMD} -d | ${TAR} xf -
.endif

post-patch:
	@${REINPLACE_CMD} -e 's+%%PTHREAD_LIBS%%+${PTHREAD_LIBS}+g;' ${WRKSRC}/../odk/settings/settings.mk
	@${REINPLACE_CMD} -e 's+%%PTHREAD_CFLAGS%%+${PTHREAD_CFLAGS}+g' ${WRKSRC}/../odk/settings/settings.mk
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
.if !defined(WITH_GIF_LZW_COMPRESSION)
	@if [ "`echo ${PATCHDIR}/gifpatch-*`" != "${PATCHDIR}/gifpatch-*" ]; then \
		${ECHO_MSG} "===>  Removing GIF LZW compression for ${PKGNAME}" ; \
		if [ ${PATCH_DEBUG_TMP} = yes ]; then \
			${ECHO_MSG} "===>   Applying GIF LZW compression ${OPSYS} patch" ; \
		fi; \
		${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/gifpatch-goodies+source+filter.vcl+egif+giflzwc.cxx ; \
		${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/gifpatch-goodies+source+filter.vcl+egif+giflzwc_disabled.cxx ; \
		${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/gifpatch-goodies+source+filter.vcl+egif+makefile.mk ; \
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

extract-mozilla:
.if ! exists(${WRKDIR}/mozilla/Makefile)
	@${ECHO_MSG} "===>  Extracting mozilla sub project"
	@cd ${WRKDIR} && tar -xzf ${DISTDIR}/${DIST_SUBDIR}/mozilla-vendor-1.0.2a.tgz
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
	@cd ${WRKDIR}/mozilla && ${MAKE} CXX="${CXX}" CC="${CC}" CFLAGS="${CFLAGS}" USE_GCC=${USE_GCC} build WRKDIRPREFIX=""
.else
	@cd ${WRKDIR}/mozilla && ${MAKE} CXX="${CXX}" CC="${CC}" CFLAGS="${CFLAGS}" build WRKDIRPREFIX=""
.endif
	@${CP} ${FILESDIR}/zipmoz.sh ${WRKDIR}
	@${CHMOD} 755 ${WRKDIR}/zipmoz.sh
	@${WRKDIR}/zipmoz.sh ${WRKDIR}/mozilla/work/mozilla/dist FREEBSDGCCI ${WRKDIR}
.endif

install-mozilla:
	@${CP} ${WRKDIR}/FREEBSDGCCIinc.zip ${WRKSRC}/../moz/zipped/
	@${CP} ${WRKDIR}/FREEBSDGCCIlib.zip ${WRKSRC}/../moz/zipped/
	@${CP} ${WRKDIR}/FREEBSDGCCIruntime.zip ${WRKSRC}/../moz/zipped/

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
.if ! exists(${WRKSRC}/../moz/zipped/FREEBSDGCCIruntime.zip)
.if ! exists(${WRKSRC}/../moz/zipped/FREEBSDGCCIlib.zip)
.if ! exists(${WRKSRC}/../moz/zipped/FREEBSDGCCIinc.zip)
	@${MAKE} mozilla
.endif
.endif
.endif
.if exists(${WRKDIR}/.Xvfb.pid)
	@-${CAT} ${WRKDIR}/.Xvfb.pid | ${XARGS} kill
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
	@${MKDIR} ${WRKSRC}/../solver/${BUILD_NR}/unxfbsd.pro/pck
	@${CP} ${WRKDIR}/L10NHELP/*.zip ${WRKSRC}/../solver/${BUILD_NR}/unxfbsd.pro/pck
.endif
.if !defined(DISPLAY)
	@cd ${WRKSRC}/.. && DISPLAY=${DISPLAYHACK} PATH="${PATH}:${LOCALBASE}/bin:${LOCALBASE}/sbin" && \
		${TCSH} -c 'source FreeBSDEnv.Set && unsetenv TOP && ${BUILD}'
	@-${CAT} ${WRKDIR}/.Xvfb.pid | ${XARGS} kill
	@${RM} -f ${WRKDIR}/.Xvfb.pid
.else
	@cd ${WRKSRC}/.. && DISPLAY=${DISPLAY} PATH="${PATH}:${LOCALBASE}/bin:${LOCALBASE}/sbin" && \
		${TCSH} -c 'source FreeBSDEnv.Set && unsetenv TOP && ${BUILD}'
.endif
.if defined(LANG_PKGNAME)
	@cd ${WRKSRC}/.. && PATH="${PATH}:${LOCALBASE}/bin:${LOCALBASE}/sbin" && \
		${TCSH} -c 'source FreeBSDEnv.Set && unsetenv TOP && cd instsetoo/util && ${BUILD} LANGEXT=${LANG_EXT}'
.endif

pre-install:
	@${MKDIR} ${WRKSRC}/../solver/${BUILD_NR}/unxfbsd.pro/bin/${LANG_EXT}/osl/

do-install:
.if !defined(DISPLAY)
	#
	# UGLY hack to not have to specify a X-Display.
	#
	${X11BASE}/bin/Xvfb :1001 -screen 0 800x600x24 > /dev/null 2>&1 & ${ECHO} $$! > ${WRKDIR}/.Xvfb.pid
	@sleep 5
	@cd ${WRKSRC}/../instsetoo/*.pro/${LANG_EXT}/normal/ ; \
	SAL_IGNOREXERRORS=1 TEMP=${WRKDIR} DISPLAY=${DISPLAY} ./install --prefix=${PREFIX}
	@-${CAT} ${WRKDIR}/.Xvfb.pid | ${XARGS} kill
	@${RM} -f ${WRKDIR}/.Xvfb.pid
.else
	@cd ${WRKSRC}/../instsetoo/*.pro/${LANG_EXT}/normal/ ; \
	SAL_IGNOREXERRORS=1 TEMP=${WRKDIR} DISPLAY=${DISPLAY} ./install --prefix=${PREFIX}
.endif

install-user:
	@SAL_IGNOREXERRORS=1 ${PREFIX}/${INSTALLATION_BASEDIR}/program/setup

post-install:
	@${ECHO_MSG} "===>  Add wrapper scripts";
	@${CP} ${FILESDIR}/openoffice-wrapper ${WRKDIR}/
	@${CP} ${FILESDIR}/freebsd-local.sh ${WRKDIR}/
	@${SED} -i orig -e 's#%%PREFIX%%#${PREFIX}#g' \
			-e 's#%%LANG%%#${USE_LANG}#g' \
			-e 's#%%BUILD_NR%%#${BUILD_NR}#g' \
			-e 's#%%RELEASE_NR%%#${RELEASE_NR}#g' \
			-e 's#%%FRELEASE_NR%%#${FRELEASE_NR}#g' \
			${WRKDIR}/openoffice-wrapper \
			${WRKDIR}/freebsd-local.sh
	@${INSTALL_SCRIPT} ${WRKDIR}/openoffice-wrapper \
		${PREFIX}/bin/openoffice-${RELEASE_NR}
	@${INSTALL_SCRIPT} ${WRKDIR}/freebsd-local.sh \
		${PREFIX}/${INSTALLATION_BASEDIR}/program/freebsd-local.sh
	@${LN} -fs ${PREFIX}/bin/openoffice-${RELEASE_NR} ${PREFIX}/bin/openoffice-${RELEASE_NR}-sagenda
	@${LN} -fs ${PREFIX}/bin/openoffice-${RELEASE_NR} ${PREFIX}/bin/openoffice-${RELEASE_NR}-scalc
	@${LN} -fs ${PREFIX}/bin/openoffice-${RELEASE_NR} ${PREFIX}/bin/openoffice-${RELEASE_NR}-sdraw
	@${LN} -fs ${PREFIX}/bin/openoffice-${RELEASE_NR} ${PREFIX}/bin/openoffice-${RELEASE_NR}-setup
	@${LN} -fs ${PREFIX}/bin/openoffice-${RELEASE_NR} ${PREFIX}/bin/openoffice-${RELEASE_NR}-sfax
	@${LN} -fs ${PREFIX}/bin/openoffice-${RELEASE_NR} ${PREFIX}/bin/openoffice-${RELEASE_NR}-smath
	@${LN} -fs ${PREFIX}/bin/openoffice-${RELEASE_NR} ${PREFIX}/bin/openoffice-${RELEASE_NR}-simpress
	@${LN} -fs ${PREFIX}/bin/openoffice-${RELEASE_NR} ${PREFIX}/bin/openoffice-${RELEASE_NR}-spadmin
	@${LN} -fs ${PREFIX}/bin/openoffice-${RELEASE_NR} ${PREFIX}/bin/openoffice-${RELEASE_NR}-sweb
	@${LN} -fs ${PREFIX}/bin/openoffice-${RELEASE_NR} ${PREFIX}/bin/openoffice-${RELEASE_NR}-swriter
	@cd ${PREFIX} && ${FIND} -s bin -type f | ${GREP} openoffice-${RELEASE_NR} > ${TMPPLIST}
	@cd ${PREFIX} && ${FIND} -s bin -type l | ${GREP} openoffice-${RELEASE_NR} >> ${TMPPLIST}
	@cd ${PREFIX} && ${FIND} -s ${INSTALLATION_BASEDIR} -type f >> ${TMPPLIST}
	@cd ${PREFIX} && ${FIND} -s ${INSTALLATION_BASEDIR} -type l >> ${TMPPLIST}
	@cd ${PREFIX} && ${FIND} -s ${INSTALLATION_BASEDIR} -type d > ${WRKDIR}/dir.tmp
	@${SORT} -r ${WRKDIR}/dir.tmp | ${XARGS} -n 1 ${ECHO_CMD} @dirrm >> ${TMPPLIST}

package-rename:
	@${ECHO_MSG} "===>   Rename package for OO.org mirror upload";
.if defined(LANG_SUFFIX)
	@${MV} ${PKGFILE} \
	    ${WRKDIR}/../OOo_${PORTVERSION}_${OPSYS}${SIMPLEOSVER}Intel_install_${LANG_PKGNAME}-${LANG_SUFFIX}${PKG_SUFX}
.elif defined(LANG_PKGNAME)
	@${MV} ${PKGFILE} \
	    ${WRKDIR}/../OOo_${PORTVERSION}_${OPSYS}${SIMPLEOSVER}Intel_install_${LANG_PKGNAME}${PKG_SUFX}
.else
	@${MV} ${PKGFILE} \
	    ${WRKDIR}/../OOo_${PORTVERSION}_${OPSYS}${SIMPLEOSVER}Intel_install${PKG_SUFX}
.endif

sdk:
	@${ECHO_MSG} "===>   Make SDK of OpenOffice.org"
.if !defined(DISPLAY)
	@cd ${WRKSRC}/.. && DISPLAY=${DISPLAYHACK} PATH="${PATH}:${LOCALBASE}/bin:${LOCALBASE}/sbin" && \
		${TCSH} -c 'source FreeBSDEnv.Set && unsetenv TOP && cd sdk_oo && build.pl && deliver.pl'
	@-${CAT} ${WRKDIR}/.Xvfb.pid | ${XARGS} kill
	@${RM} -f ${WRKDIR}/.Xvfb.pid
.else
	@cd ${WRKSRC}/.. && DISPLAY=${DISPLAY} PATH="${PATH}:${LOCALBASE}/bin:${LOCALBASE}/sbin" && \
		${TCSH} -c 'source FreeBSDEnv.Set && unsetenv TOP && cd sdk_oo && build.pl && deliver.pl'
.endif
	${MV} ${WRKSRC}/../solver/${BUILD_NR}/unxfbsd.pro/bin/OpenOffice.org${FRELEASE_NR}_SDK.tar.gz ${WRKDIR}/../OOo_${PORTVERSION}_${OPSYS}${SIMPLEOSVER}Intel_sdk.tar.gz 

solver:
	@${ECHO_MSG} "===>   Make Solver of OpenOffice.org"
	@cd ${WRKSRC}/.. ; ${TAR} cfz ${WRKDIR}/../OOo_${PORTVERSION}_${OPSYS}${SIMPLEOSVER}Intel_solver.tar.gz solver

update:
	@${MAKE} fetch
	@${MAKE} extract
	@cd ${WRKSRC}/.. && for dir in *; do \
	    if [ -d $$dir ]; then \
		cd $$dir; cvs update -d; cd ..; \
	    fi \
	done

.include <bsd.port.post.mk>
