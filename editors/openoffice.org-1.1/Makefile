# New ports collection makefile for: OpenOffice.org
# Date created:		28 Februar 2002
# Whom:                 Martin Blapp
#
# $FreeBSD$
#

PORTNAME=	openoffice
PORTVERSION=	1.1.2
CATEGORIES+=	editors
MASTER_SITES+=  ${MASTER_SITE_RINGSERVER:S,%SUBDIR%,misc/openoffice/&,} \
		ftp://sunsite.cnlab-switch.ch/mirror/OpenOffice/%SUBDIR%/ \
		ftp://ftp.kddlabs.co.jp/office/openoffice/%SUBDIR%/ \
		ftp://ftp.tu-chemnitz.de/pub/openoffice/%SUBDIR%/ \
		http://ftp.stardiv.de/pub/OpenOffice.org/%SUBDIR%/ \
		http://ftp.gwdg.de/pub/misc/openoffice/%SUBDIR%/ \
		ftp://ftp.cs.man.ac.uk/pub/toby/gpc/:gpc \
		http://people.freebsd.org/~mbr/ooo/:moz \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,misc/openoffice/contrib/helpcontent/&,}:help \
		ftp://ftp.kddlabs.co.jp/office/openoffice/contrib/helpcontent/:help \
		ftp://sunsite.cnlab-switch.ch/mirror/OpenOffice/contrib/helpcontent/:help \
		http://ftp.services.openoffice.org/pub/OpenOffice.org/contrib/helpcontent/:help
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}
DISTFILES+=	OOo_${PORTVERSION}_source.tar.gz gpc231.tar.Z:gpc \
		patch-openoffice-mozilla101-2002-10-14:moz mozilla-vendor-1.0.2a.tgz:moz
EXTRACT_ONLY=	OOo_${PORTVERSION}_source.tar.gz

MAINTAINER=	openoffice@FreeBSD.org

USE_GNOME=	orbit gtk12 gtk20
USE_PERL5=	yes
USE_BISON=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes

.include <bsd.port.pre.mk>
.include <${FILESDIR}/Makefile.localized>

.if defined(ALL_LOCALIZED_LANGS)
DISTFILES+=	helpcontent_31_unix.tgz:help helpcontent_33_unix.tgz:help \
		helpcontent_34_unix.tgz:help helpcontent_39_unix.tgz:help \
		helpcontent_46_unix.tgz:help helpcontent_49_unix.tgz:help \
		helpcontent_55_unix.tgz:help \
		helpcontent_81_unix.tgz:help helpcontent_82_unix.tgz:help \
		helpcontent_86_unix.tgz:help helpcontent_88_unix.tgz:help
L10NHELPS=	helpcontent_31_unix.tgz helpcontent_33_unix.tgz \
		helpcontent_34_unix.tgz helpcontent_39_unix.tgz \
		helpcontent_46_unix.tgz helpcontent_49_unix.tgz \
		helpcontent_55_unix.tgz \
		helpcontent_81_unix.tgz helpcontent_82_unix.tgz \
		helpcontent_86_unix.tgz helpcontent_88_unix.tgz
.endif

.if ${OSVERSION} > 502010
BROKEN=		"Does not compile on 5-current"
.endif

COMMENT?=	Integrated wordprocessor/dbase/spreadheet/drawing/chart/browser

BUILD_NR=		645
RELEASE_NR=		${PORTVERSION}
INSTALLATION_BASEDIR=	OpenOffice.org${RELEASE_NR}
DIST_SUBDIR=		openoffice1.1
SIMPLEOSVER!=		${UNAME} -r | ${SED} -e 's/\.//' | ${SED} -e 's/\..*//'
.if defined(LANG_PKGNAME)
PKGNAMEPREFIX=		${LANG_PKGNAME}-
.endif
.if defined(LANG_SUFFIX)
PKGNAMESUFFIX?=		-${LANG_SUFFIX}
.endif
BUILD_DEPENDS+=	gcc32:${PORTSDIR}/lang/gcc32
USE_GCC=3.2
.if defined(WITH_CCACHE)
BUILD_DEPENDS+=	ccache:${PORTSDIR}/devel/ccache
CC=	ccache gcc32
CXX=	ccache g++32
.else
CC=	gcc32
CXX=	g++32
.endif

BUILD_DEPENDS+=	${JDKDIR}/bin/java:${PORTSDIR}/java/jdk14 \
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

JDKDIR?=	${LOCALBASE}/jdk1.4.2
GNU_CONFIGURE=	yes
USE_AUTOCONF_VER=	259
WRKDIR=		${WRKDIRPREFIX}${.CURDIR}/work
WRKSRC=		${WRKDIR}/oo_${RELEASE_NR}_src/config_office
ANT?=		${LOCALBASE}/bin/ant
TCSH?=		/bin/tcsh
ZIP?=		${PREFIX}/bin/zip
UNZIP?=		${PREFIX}/bin/unzip
BUILD=		dmake

.if !defined(DISPLAY)
DISPLAYHACK=localhost:1001
.endif

CONFIGURE_ENV=		PTHREAD_CFLAGS=${PTHREAD_CFLAGS} \
			PTHREAD_LIBS=${PTHREAD_LIBS}
CONFIGURE_ARGS+=	--with-gnu-cp=${LOCALBASE}/bin/gcp --with-jdk-home=${JDKDIR}
.if defined(WITHOUT_MOZILLA)
CONFIGURE_ARGS+=	--disable-mozilla
.endif

.if defined(LANG_EXT)
CONFIGURE_ARGS+=	--with-lang=${LANG_CONFIGURE_ARG},ENUS
.else
LANG_EXT=		01
.endif

.if defined(ALL_LOCALIZED_LANGS)
CONFIGURE_ARGS+=	--with-lang=ALL
.endif

.if defined(WITH_DEBUG)
.if ${WITH_DEBUG} == 2
CONFIGURE_ARGS+=	--enable-debug
.else
CONFIGURE_ARGS+=	--enable-symbols
.endif
.endif

pre-fetch:
	@${ECHO} "OPTIONS:"
.if !defined(WITH_DEBUG)
	@${ECHO}
	@${ECHO} "You can compile OOo with debug symbols"
	@${ECHO} "if you call make with WITH_DEBUG=1"
	@${ECHO}
	@${ECHO} "If you set WITH_DEBUG=2, you add internal"
	@${ECHO} "OOo debug support."
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
	@${ECHO}
	@${ECHO} "NOTICE:"
	@${ECHO}
	@${ECHO} "To build Openoffice, you should have a lot"
.if defined(WITH_DEBUG)
	@${ECHO} "of free diskspace (~ 8GB)."
.else
	@${ECHO} "of free diskspace (~ 4GB)."
.endif
	@${ECHO} "If you want SDK and/or solver, please type make sdk and/or make solver"

pre-everything::
# really tewak, extremely useful when you build all localized language versions
# needed after when you build with ALL_LOCALIZED_LANGS.
.if defined(TWEAK_L10N)
	@${RM} -f ${WRKDIR}/.PLIST*
	@${RM} -f ${WRKDIR}/.install_done.*
	@${RM} -f ${WRKDIR}/.package_done.*
	@${RM} -f ${WRKDIR}/.extract_done.*
	@${RM} -f ${WRKDIR}/.patch_done.*
	@${RM} -f ${WRKDIR}/.configure_done.*
	@${RM} -f ${WRKDIR}/.build_done.*
	@${TOUCH} ${EXTRACT_COOKIE}
	@${TOUCH} ${PATCH_COOKIE}
	@${TOUCH} ${CONFIGURE_COOKIE}
	@${TOUCH} ${BUILD_COOKIE}
.endif

post-extract:
	@cd ${WRKDIR} ; ${CAT} ${DISTDIR}/${DIST_SUBDIR}/gpc231.tar.Z | ${TAR} xfz -
	@${CP} ${WRKDIR}/gpc231/gpc.c ${WRKSRC}/../external/gpc/
	@${CP} ${WRKDIR}/gpc231/gpc.h ${WRKSRC}/../external/gpc/
.if defined(L10NHELP)
	@${ECHO_MSG} "===>  Extracting L10NHELP sub project"
	@${MKDIR} ${WRKDIR}/L10NHELP
	@cd ${WRKDIR}/L10NHELP ; \
		${CAT} ${DISTDIR}/${DIST_SUBDIR}/${L10NHELP} | ${GZIP_CMD} -d | ${TAR} xf -
.endif
.if defined(ALL_LOCALIZED_LANGS)
	@${ECHO_MSG} "===>  Extracting All available L10NHELPs"
	@${MKDIR} ${WRKDIR}/L10NHELP
	@cd ${WRKDIR}/L10NHELP ; \
	for file in ${L10NHELPS}; do \
		${CAT} ${DISTDIR}/${DIST_SUBDIR}/$$file | ${GZIP_CMD} -d | ${TAR} xf - ; \
	done
.endif

post-patch:
	@${REINPLACE_CMD} -e 's+%%PTHREAD_LIBS%%+${PTHREAD_LIBS}+g;' ${WRKSRC}/../odk/settings/settings.mk
	@${REINPLACE_CMD} -e 's+%%PTHREAD_CFLAGS%%+${PTHREAD_CFLAGS}+g' ${WRKSRC}/../odk/settings/settings.mk
.if defined(WITH_TTF_BYTECODE_ENABLED)
	@if [ "`echo ${PATCHDIR}/optpatch-*`" != "${PATCHDIR}/optpatch-*" ]; then \
		${ECHO_MSG} "===>  Applying additional TTF bytecode patches for ${PKGNAME}" ; \
		if [ ${PATCH_DEBUG_TMP} = yes ]; then \
			${ECHO_MSG} "===>   Applying ${OPSYS} patch ${PATCHDIR}/optpatch-freetype::patch" ; \
		fi; \
		${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/optpatch-freetype+patch ; \
	fi
.endif

.include <${FILESDIR}/Makefile.mozilla>

do-build:
.if !defined(WITHOUT_MOZILLA)
.if !exists(${WRKSRC}/../moz/zipped/FREEBSDGCCIruntime.zip)
.if !exists(${WRKSRC}/../moz/zipped/FREEBSDGCCIlib.zip)
.if !exists(${WRKSRC}/../moz/zipped/FREEBSDGCCIinc.zip)
	@${MAKE} mozilla
.endif
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
	@cd ${WRKSRC}/.. ; PATH="${PATH}:${LOCALBASE}/bin:${LOCALBASE}/sbin" ./bootstrap
.if defined(L10NHELP) || defined(ALL_LOCALIZED_LANGS)
	@${MKDIR} ${WRKSRC}/../solver/${BUILD_NR}/unxfbsd.pro/pck
	@${CP} ${WRKDIR}/L10NHELP/*.zip ${WRKSRC}/../solver/${BUILD_NR}/unxfbsd.pro/pck
.endif
.if !defined(DISPLAY)
	@cd ${WRKSRC}/.. ; DISPLAY=${DISPLAYHACK} PATH="${PATH}:${LOCALBASE}/bin:${LOCALBASE}/sbin" ; \
		${TCSH} -c 'source FreeBSDEnv.Set ; unsetenv TOP ; ${BUILD}'
	@-${CAT} ${WRKDIR}/.Xvfb.pid | ${XARGS} kill
	@${RM} -f ${WRKDIR}/.Xvfb.pid
.else
	@cd ${WRKSRC}/.. ; DISPLAY=${DISPLAY} PATH="${PATH}:${LOCALBASE}/bin:${LOCALBASE}/sbin" ; \
		${TCSH} -c 'source FreeBSDEnv.Set ; unsetenv TOP ; ${BUILD}'
.endif
.if defined(LANG_PKGNAME)
	@cd ${WRKSRC}/.. ; PATH="${PATH}:${LOCALBASE}/bin:${LOCALBASE}/sbin" ; \
		${TCSH} -c 'source FreeBSDEnv.Set ; unsetenv TOP ; cd instsetoo/util ; ${BUILD} LANGEXT=${LANG_EXT}'
.endif

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
	@${REINPLACE_CMD} -e 's#%%PREFIX%%#${PREFIX}#g' \
			-e 's#%%LANG%%#${USE_LANG}#g' \
			-e 's#%%BUILD_NR%%#${BUILD_NR}#g' \
			-e 's#%%RELEASE_NR%%#${RELEASE_NR}#g' \
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
	@cd ${PREFIX} ; ${FIND} -s bin -type f | ${GREP} openoffice-${RELEASE_NR} > ${TMPPLIST}
	@cd ${PREFIX} ; ${FIND} -s bin -type l | ${GREP} openoffice-${RELEASE_NR} >> ${TMPPLIST}
	@cd ${PREFIX} ; ${FIND} -s ${INSTALLATION_BASEDIR} -type f >> ${TMPPLIST}
	@cd ${PREFIX} ; ${FIND} -s ${INSTALLATION_BASEDIR} -type l >> ${TMPPLIST}
	@cd ${PREFIX} ; ${FIND} -s ${INSTALLATION_BASEDIR} -type d > ${WRKDIR}/dir.tmp
	@${SORT} -r ${WRKDIR}/dir.tmp | ${XARGS} -n 1 ${ECHO_CMD} @dirrm >> ${TMPPLIST}

package-rename:
	@${ECHO_MSG} "===>   Rename package for OOo mirror upload";
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
	@${ECHO_MSG} "===>   Make SDK of OOo"
.if !defined(DISPLAY)
	@cd ${WRKSRC}/.. ; DISPLAY=${DISPLAYHACK} PATH="${PATH}:${LOCALBASE}/bin:${LOCALBASE}/sbin" ; \
		${TCSH} -c 'source FreeBSDEnv.Set ; unsetenv TOP ; cd sdk_oo ; build.pl ; deliver.pl'
	@-${CAT} ${WRKDIR}/.Xvfb.pid | ${XARGS} kill
	@${RM} -f ${WRKDIR}/.Xvfb.pid
.else
	@cd ${WRKSRC}/.. ; DISPLAY=${DISPLAY} PATH="${PATH}:${LOCALBASE}/bin:${LOCALBASE}/sbin" ; \
		${TCSH} -c 'source FreeBSDEnv.Set ; unsetenv TOP ; cd sdk_oo ; build.pl ; deliver.pl'
.endif
	@${MV} ${WRKSRC}/../solver/${BUILD_NR}/unxfbsd.pro/bin/OpenOffice.org${RELEASE_NR}_SDK.tar.gz ${WRKDIR}/../OOo_${PORTVERSION}_${OPSYS}${SIMPLEOSVER}Intel_sdk.tar.gz

solver:
	@${ECHO_MSG} "===>   Make Solver of OOo"
	@cd ${WRKSRC}/.. ; ${TAR} cfz ${WRKDIR}/../OOo_${PORTVERSION}_${OPSYS}${SIMPLEOSVER}Intel_solver.tar.gz solver

.include <bsd.port.post.mk>
