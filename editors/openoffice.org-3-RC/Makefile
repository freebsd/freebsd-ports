# New ports collection makefile for: OpenOffice.org
# Date created:		28 February 2002
# Whom:                 Martin Blapp
#
# $FreeBSD$
#

PORTNAME=	openoffice
PORTVERSION=	2.0
CATEGORIES+=	editors
MASTER_SITES+=	${MASTER_SITE_LOCAL} \
		ftp://ftp.cs.man.ac.uk/pub/toby/gpc/:gpc \
		http://ftp.services.openoffice.org/pub/OpenOffice.org/contrib/helpcontent/:help \
		http://people.freebsd.org/~mbr/ooo/:moz
MASTER_SITE_SUBDIR=	maho/openoffice.org
DISTFILES+=	OOo_${BUILD_NR}${MILESTONE}_${SNAPDATE}_source.tar.bz2 gpc231.tar.Z:gpc \
		patch-openoffice-mozilla101-2002-10-14:moz mozilla-vendor-1.0.2a.tgz:moz
.if defined(L10NHELP)
DISTFILES+=	${L10NHELP:S/$/:help/}
.endif

MAINTAINER=	openoffice@FreeBSD.org
.if !defined(COMMENT)
COMMENT=	Integrated wordprocessor/dbase/spreadheet/drawing/chart/browser
.endif

IGNORE=		"Does not work yet, installation problems"

NO_LATEST_LINK=		yes
UNZIP?=			${LOCALBASE}/bin/unzip
ZIP?=			${LOCALBASE}/bin/zip
ANT?=			${LOCALBASE}/bin/ant
TCSH?=			/bin/tcsh
DIST_SUBDIR=		openoffice2.0
BUILD_NR=		680
MILESTONE=		m30
RELEASE_NR=		2.0
FRELEASE_NR=		2.0
SNAPDATE=		20040402
INSTALLATION_BASEDIR=	OpenOffice.org${RELEASE_NR}
EXTRACT_ONLY=		OOo_${BUILD_NR}${MILESTONE}_${SNAPDATE}_source.tar.bz2
USE_GNOME=		orbit gtk12
USE_REINPLACE=		yes
USE_PERL5=		yes
USE_BZIP2=		yes
USE_BISON=		yes
USE_GMAKE=		yes
LANG_EXT?=		01
LANG_CONFIGURE_ARG?=	ENUS
WRKDIR=			${WRKDIRPREFIX}${.CURDIR}/work
WRKSRC=			${WRKDIR}/oo_${BUILD_NR}${MILESTONE}_src/config_office

#XXX dirty
BUILD_DEPENDS+= gcc32:${PORTSDIR}/lang/gcc32
USE_GCC=3.2
CC=	gcc32
CXX=	g++32
BUILD_DEPENDS+= ${JAVAVM}:${PORTSDIR}/java/jdk14
BUILD_DEPENDS+= zip:${PORTSDIR}/archivers/zip
BUILD_DEPENDS+=	unzip:${PORTSDIR}/archivers/unzip
BUILD_DEPENDS+=	${ANT}:${PORTSDIR}/devel/apache-ant 
BUILD_DEPENDS+=	${X11BASE}/lib/libgdk-x11-2.0.so:${PORTSDIR}/x11-toolkits/gtk20
BUILD_DEPENDS+= ${X11BASE}/lib/libX11.so:${PORTSDIR}/x11/XFree86-4-libraries
BUILD_DEPENDS+= ${X11BASE}/lib/libXft.so:${PORTSDIR}/x11-fonts/libXft
.if !defined(DISPLAY)
BUILD_DEPENDS+= Xvfb:${PORTSDIR}/x11-servers/XFree86-4-VirtualFramebufferServer
.endif

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		mng.1:${PORTSDIR}/graphics/libmng \
		freetype.9:${PORTSDIR}/print/freetype2

.include <bsd.port.pre.mk>

#
# configuration for language specific slave ports
#
.if exists(${.CURDIR}/pkg-descr)
DESCR=	${.CURDIR}/pkg-descr
.endif
.if exists(${.CURDIR}/pkg-message)
PKGMESSAGE=	${.CURDIR}/pkg-message
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

.if !defined (LANG) && !defined(USE_LANG)
USE_LANG=	en_US.ISO8859-15
LANG_LIST=	en_US.ISO8859-15 en_US.ISO8859-1 US-ASCII
.else
.if !defined(USE_LANG)
USE_LANG=	${LANG}
.endif
.endif

LANG_SORTED=`${ECHO} ${LANG_LIST} | ${TR} " " "\n" | ${PASTE} -d " " - -`

EXTRACT_BEFORE_ARGS_R= -dc
EXTRACT_AFTER_ARGS_R= | ${TAR} -xf -
EXTRACT_CMD_R= ${GZIP_CMD}
EXTRACT_REST=	gpc231.tar.Z

JDKDIR?=	${LOCALBASE}/jdk1.4.2
JAVAVM=		${JDKDIR}/bin/java

GNU_CONFIGURE=	yes
USE_AUTOCONF_VER= 253
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
CONFIGURE_ARGS+=	--with-lang=${LANG_CONFIGURE_ARG}
CONFIGURE_ARGS+=	--with-jdk-home=${JDKDIR} --with-ant-home=${LOCALBASE}/ant  --with-gnu-cp=${LOCALBASE}/bin/gcp  --enable-mozilla=no

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
	@${ECHO} "If you want SDK and/or solver, please type make sdk and/or make solver"

.include <${FILESDIR}/Makefile.mozilla>

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
	@${CHMOD} +x ${WRKSRC}/../solenv/bin/zipdep.pl
.if defined(L10NHELP)
	@${ECHO_MSG} "===>  Extracting L10NHELP sub project"
	@${MKDIR} ${WRKDIR}/L10NHELP
	@cd ${WRKDIR}/L10NHELP && \
	    ${TAR} -xzf ${DISTDIR}/${DIST_SUBDIR}/${L10NHELP}
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
	@${CP} ${FILESDIR}/oo_setup.resp \
		${WRKSRC}/../instsetoo/unxfbsd.pro/${LANG_EXT}/normal/
	@${SED} -i orig -e 's#%%PREFIX%%#${PREFIX}#g' \
			-e 's#%%FRELEASE_NR%%#${FRELEASE_NR}#g' \
			${WRKSRC}/../instsetoo/unxfbsd.pro/${LANG_EXT}/normal/oo_setup.resp
	@${MKDIR} -p ${WRKSRC}/../solver/${BUILD_NR}/unxfbsd.pro/bin/${LANG_EXT}/osl/

do-install:
.if !defined(DISPLAY)
	#
	# UGLY hack to not have to specify a X-Display.
	#
	${X11BASE}/bin/Xvfb :1001 -screen 0 800x600x24 > /dev/null 2>&1 & ${ECHO} $$! > ${WRKDIR}/.Xvfb.pid
	@sleep 5
	@-SAL_IGNOREXERRORS=1 PATH="/bin:${PATH}" TEMP=${WRKDIR} DISPLAY=${DISPLAYHACK} \
		${WRKSRC}/../instsetoo/*.pro/${LANG_EXT}/normal/setup -r:oo_setup.resp
	@${CAT} ${WRKDIR}/.Xvfb.pid | ${XARGS} kill
	@${RM} -f ${WRKDIR}/.Xvfb.pid
.else
	@-SAL_IGNOREXERRORS=1 PATH="/bin:${PATH}" TEMP=${WRKDIR} DISPLAY=${DISPLAY} \
		${WRKSRC}/../instsetoo/*.pro/${LANG_EXT}/normal/setup -r:oo_setup.resp
.endif

install-user:
	@-SAL_IGNOREXERRORS=1 PATH="/bin:${PATH}" \
		${PREFIX}/${INSTALLATION_BASEDIR}/program/setup

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
	${WRKDIR}/../OOo_${BUILD_NR}${MILESTONE}_${OPSYS}${SIMPLEOSVER}Intel_install_${LANG_PKGNAME}-${LANG_SUFFIX}${PKG_SUFX}
.elif defined(LANG_PKGNAME)
	@${MV} ${PKGFILE} \
	${WRKDIR}/../OOo_${BUILD_NR}${MILESTONE}_${OPSYS}${SIMPLEOSVER}Intel_install_${LANG_PKGNAME}${PKG_SUFX}
.else
	@${MV} ${PKGFILE} \
	${WRKDIR}/../OOo_${BUILD_NR}${MILESTONE}_${OPSYS}${SIMPLEOSVER}Intel_install${PKG_SUFX}
.endif

sdk:
	@${ECHO_MSG} "===>   Make SDK of OpenOffice.org"
	@cd ${WRKSRC}/.. && DISPLAY=${DISPLAY} PATH="${PATH}:${LOCALBASE}/bin:${LOCALBASE}/sbin" && \
		${SH} -c 'source FreeBSDEnv.Set && unsetenv TOP && cd sdk_oo && build.pl && deliver.pl'
	${MV} ${WRKSRC}/../solver/${BUILD_NR}/unxfbsd.pro/bin/OpenOffice.org${RELEASE_NR}_SDK.tar.gz ${WRKDIR}/../OOo_${BUILD_NR}${MILESTONE}_${OPSYS}${SIMPLEOSVER}Intel_sdk.tar.gz

solver:
	@${ECHO_MSG} "===>   Make Solver of OpenOffice.org"
	@cd ${WRKSRC}/.. ; ${TAR} cfz ${WRKDIR}/../OOo_${BUILD_NR}${MILESTONE}_${OPSYS}${SIMPLEOSVER}Intel_solver.tar.gz solver

.include <bsd.port.post.mk>
