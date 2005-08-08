# New ports collection makefile for: OpenOffice.org
# Date created:		28 Februar 2002
# Whom:                 Martin Blapp
#
# $FreeBSD$
#

PORTNAME=	openoffice
PORTVERSION=	1.0.3
PORTREVISION=	4
CATEGORIES+=	editors
MASTER_SITES+=  ${MASTER_SITE_RINGSERVER:S,%SUBDIR%,misc/openoffice/stable/${PORTVERSION}/&,} \
		${MASTER_SITE_LOCAL:S,%SUBDIR%,maho/openoffice.org/&,}:moz \
		ftp://ftp.cs.man.ac.uk/pub/toby/gpc/:gpc \
		${MASTER_SITE_MOZILLA:S,%SUBDIR%,mozilla/releases/mozilla${MOZILLA_VERSION}/&,}src/:mozsrc \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,misc/openoffice/contrib/helpcontent-1.0/&,}:help \
		ftp://sunsite.cnlab-switch.ch/mirror/OpenOffice/contrib/helpcontent-1.0/:help \
		http://ftp.services.openoffice.org/pub/OpenOffice.org/contrib/helpcontent-1.0/:help \
		http://people.freebsd.org/~mbr/ooo/:mbr
DISTFILES+=	OOo_${RELEASE_NR}_source.tar.gz gpc231.tar.Z:gpc patch-translation-ru-1.0.3.bz2:mbr
EXTRACT_ONLY=	OOo_${RELEASE_NR}_source.tar.gz

MAINTAINER=	openoffice@FreeBSD.org
COMMENT?=	Integrated wordprocessor/dbase/spreadsheet/drawing/chart/browser

MOZILLA_PROJECT=	cws_srx645_mozooo.20040203.tar.gz
MOZILLA_VERSION=	1.0
MOZILLA_SOURCE=		mozilla-source-${MOZILLA_VERSION}.tar.gz
DISTFILES+=	${MOZILLA_PROJECT}:moz ${MOZILLA_SOURCE}:mozsrc
USE_GNOME=	orbit
USE_XLIB=	yes
USE_PERL5=	yes
USE_BISON=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.3
JAVA_BUILD=	jdk
NO_LATEST_LINK=	yes

.include <bsd.port.pre.mk>
.include <${FILESDIR}/Makefile.localized>

LANG_EXT?=	01
LANG_CONFIGURE_ARG?=	ENUS
L10NHELP?=     helpcontent_01_unix.tgz

DISTFILES+=	${L10NHELP}:help
.if defined(ALL_LOCALIZED_LANGS)
DISTFILES+=	helpcontent_01_unix.tgz:help helpcontent_07_unix.tgz:help \
		helpcontent_31_unix.tgz:help helpcontent_33_unix.tgz:help \
		helpcontent_34_unix.tgz:help helpcontent_35_unix.tgz:help \
		helpcontent_39_unix.tgz:help helpcontent_42_unix.tgz:help \
		helpcontent_46_unix.tgz:help helpcontent_49_unix.tgz:help \
		helpcontent_81_unix.tgz:help helpcontent_82_unix.tgz:help \
		helpcontent_86_unix.tgz:help helpcontent_88_unix.tgz:help
L10NHELPS=	helpcontent_01_unix.tgz helpcontent_07_unix.tgz \
		helpcontent_31_unix.tgz helpcontent_33_unix.tgz \
		helpcontent_34_unix.tgz helpcontent_35_unix.tgz \
		helpcontent_39_unix.tgz helpcontent_42_unix.tgz \
		helpcontent_46_unix.tgz helpcontent_49_unix.tgz \
		helpcontent_81_unix.tgz helpcontent_82_unix.tgz \
		helpcontent_86_unix.tgz helpcontent_88_unix.tgz
.endif

CODELINE=		641
RELEASE_NR=		1.0.3
INSTALLATION_BASEDIR=   OpenOffice.org${RELEASE_NR}
EXECBASE=               openoffice.org-${RELEASE_NR}
DIST_SUBDIR=		openoffice.org1.0
SIMPLEOSVER=		${OSREL:C/\.//g}
PACKAGE_BASENAME=       OOo_${RELEASE_NR}m${MILESTONE}_${OPSYS}${SIMPLEOSVER}Intel
DICT_DIR=               ${PREFIX}/${INSTALLATION_BASEDIR}/share/dict/ooo/

# FIXME (Somehow INDEX build fails)
.if defined(LANG_PKGNAME)
PKGNAMEPREFIX=          ${LANG_PKGNAME}-
.endif
.if defined(LANG_SUFFIX)
PKGNAMESUFFIX?=         -${LANG_SUFFIX}
.endif

# This port might build with gcc 2.95.2+
BUILD_DEPENDS+=	gcc32:${PORTSDIR}/lang/gcc32
# FIXME (correctly add ccache before gcc and g++)
.if defined(WITH_CCACHE)
BUILD_DEPENDS+=	ccache:${PORTSDIR}/devel/ccache
CC=	ccache gcc32
CXX=	ccache g++32
.else
CC=	gcc32
CXX=	g++32
.endif
BUILD_DEPENDS+=	zip:${PORTSDIR}/archivers/zip \
		unzip:${PORTSDIR}/archivers/unzip \
		imake:${X_IMAKE_PORT} \
		Xvfb:${X_VFBSERVER_PORT}
GNU_CONFIGURE=	yes
USE_AUTOCONF_VER= 253
WRKSRC=		${WRKDIR}/oo_${PORTVERSION}_src
CONFIGURE_WRKSRC=	${WRKSRC}/config_office
TCSH?=		/bin/tcsh
PKGMESSAGE=	${WRKDIR}/pkg-message

DISPLAYHACK=localhost:1001
CONFIGURE_ENV=		PTHREAD_CFLAGS=${PTHREAD_CFLAGS} \
			PTHREAD_LIBS=${PTHREAD_LIBS}
CONFIGURE_ARGS+=	--with-jdk-home="${JAVA_HOME}" \
			--with-os-version=${OSVERSION}
.include <${FILESDIR}/Makefile.knobs>

pre-everything::
# really tweak, extremely useful when you build all localized language versions
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
.if defined(WITH_TTF_BYTECODE_ENABLED)
	@cd ${WRKSRC} ; ${PATCH} < ${FILESDIR}/optpatch-freetype
.endif
#fix for gnome/kde wrapper
	#${REINPLACE_CMD} -e 's|"Exec", "\\"\<progpath\>/program/|"Exec", "\\"${PREFIX}/bin/openoffice.org-|' ${WRKSRC}/sysui/oounix/office/kde2/kdeint
	#${REINPLACE_CMD} -e 's|"Exec", "<progpath>/program/|"Exec", "${PREFIX}/bin/openoffice.org-|' ${WRKSRC}/sysui/oounix/office/gnome/gnomeint
#Russian and Ukrainian support
	#cd ${WRKDIR} ; ${CAT} ${DISTDIR}/${DIST_SUBDIR}/patch-support-RU-1.0.3.bz2 | ${BUNZIP2}
	#cd ${WRKDIR} ; ${CAT} ${DISTDIR}/${DIST_SUBDIR}/patch-support-UA-1.0.3.bz2 | ${BUNZIP2}
	@cd ${WRKDIR} ; ${CAT} ${DISTDIR}/${DIST_SUBDIR}/gpc231.tar.Z | ${TAR} xfz -
	@${CP} ${WRKDIR}/gpc231/gpc.c ${WRKSRC}/external/gpc/
	@${CP} ${WRKDIR}/gpc231/gpc.h ${WRKSRC}/external/gpc/
	@${CHMOD} +x ${WRKSRC}/solenv/bin/zipdep.pl

	@${MKDIR} ${WRKDIR}/L10NHELP
	@cd ${WRKDIR}/L10NHELP ; \
		${CAT} ${DISTDIR}/${DIST_SUBDIR}/${L10NHELP} | ${GZIP_CMD} -d | ${TAR} xf -
.if defined(ALL_LOCALIZED_LANGS)
	@cd ${WRKDIR}/L10NHELP ; \
	for helpfile in ${L10NHELPS}; do \
		${CAT} ${DISTDIR}/${DIST_SUBDIR}/$$helpfile | ${GZIP_CMD} -d | ${TAR} xf - ; \
	done
.endif
	@cd ${WRKSRC} ; ${MV} moz moz.old ; ${TAR} xfz ${DISTDIR}/${DIST_SUBDIR}/${MOZILLA_PROJECT} ; ${PATCH} < ${FILESDIR}/moz-patch
	@${MKDIR} ${WRKSRC}/moz/download
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${MOZILLA_SOURCE} ${WRKSRC}/moz/download

do-build:
	cd ${WRKSRC} ; ./bootstrap
	cd ${WRKSRC}/moz ; ${SETENV} "BUILD_MOZAB=TRUE" ${TCSH} -c 'source ../FreeBSDEnv.Set ; build.pl ; dmake zip' ; ${CP} unxfbsd.pro/zipped/FREEBSD*.zip ../moz/zipped
	@${MKDIR} ${WRKSRC}/solver/${CODELINE}/unxfbsd.pro/pck
	@${CP} ${WRKDIR}/L10NHELP/*.zip ${WRKSRC}/solver/${CODELINE}/unxfbsd.pro/pck
.if exists(${WRKDIR}/.Xvfb.pid)
	@-${CAT} ${WRKDIR}/.Xvfb.pid | ${XARGS} kill
	@${RM} -f ${WRKDIR}/.Xvfb.pid
.endif
	${X11BASE}/bin/Xvfb :1001 -screen 0 800x600x24 > /dev/null 2>&1 & ${ECHO} $$! > ${WRKDIR}/.Xvfb.pid
	@sleep 5
	cd ${WRKSRC} && DISPLAY=${DISPLAYHACK} ${TCSH} -c 'source FreeBSDEnv.Set ; ${BUILD}'
	-${CAT} ${WRKDIR}/.Xvfb.pid | ${XARGS} kill
	${RM} -f ${WRKDIR}/.Xvfb.pid

do-install:
.if exists(${WRKDIR}/.Xvfb.pid)
	@-${CAT} ${WRKDIR}/.Xvfb.pid | ${XARGS} kill
	@${RM} -f ${WRKDIR}/.Xvfb.pid
.endif
	${X11BASE}/bin/Xvfb :1001 -screen 0 800x600x24 > /dev/null 2>&1 & ${ECHO} $$! > ${WRKDIR}/.Xvfb.pid
	@sleep 5
	${SETENV} DISPLAY=${DISPLAYHACK} ${TCSH} -c "cd ${WRKSRC}/instsetoo/*.pro/${LANG_EXT}/normal ; ./install --prefix=${PREFIX}"
	@-${CAT} ${WRKDIR}/.Xvfb.pid | ${XARGS} kill
	@${RM} -f ${WRKDIR}/.Xvfb.pid
#temporary hack (contains space in dir name)
	@${RM} -rf ${PREFIX}/${INSTALLATION_BASEDIR}/share/kde/net/applnk

install-user:
	@${PREFIX}/${INSTALLATION_BASEDIR}/program/setup

post-install:
	@${ECHO_MSG} "===>  Add wrapper scripts";
	@${CP} ${FILESDIR}/openoffice.org-wrapper ${WRKDIR}/
	@${REINPLACE_CMD} -e 's#%%PREFIX%%#${PREFIX}#g' \
			-e 's#%%RELEASE_NR%%#${RELEASE_NR}#g' \
			-e 's#%%INSTALLATION_BASEDIR%%#${INSTALLATION_BASEDIR}#g' \
			${WRKDIR}/openoffice.org-wrapper
	@${INSTALL_SCRIPT} ${WRKDIR}/openoffice.org-wrapper \
		${PREFIX}/bin/${EXECBASE}
	@${LN} -fs ${PREFIX}/bin/${EXECBASE} ${PREFIX}/bin/openoffice.org
	@${LN} -fs ${PREFIX}/bin/${EXECBASE} ${PREFIX}/bin/${EXECBASE}-sagenda
	@${LN} -fs ${PREFIX}/bin/${EXECBASE} ${PREFIX}/bin/${EXECBASE}-scalc
	@${LN} -fs ${PREFIX}/bin/${EXECBASE} ${PREFIX}/bin/${EXECBASE}-sdraw
	@${LN} -fs ${PREFIX}/bin/${EXECBASE} ${PREFIX}/bin/${EXECBASE}-setup
	@${LN} -fs ${PREFIX}/bin/${EXECBASE} ${PREFIX}/bin/${EXECBASE}-sfax
	@${LN} -fs ${PREFIX}/bin/${EXECBASE} ${PREFIX}/bin/${EXECBASE}-smath
	@${LN} -fs ${PREFIX}/bin/${EXECBASE} ${PREFIX}/bin/${EXECBASE}-simpress
	@${LN} -fs ${PREFIX}/bin/${EXECBASE} ${PREFIX}/bin/${EXECBASE}-spadmin
	@${LN} -fs ${PREFIX}/bin/${EXECBASE} ${PREFIX}/bin/${EXECBASE}-sweb
	@${LN} -fs ${PREFIX}/bin/${EXECBASE} ${PREFIX}/bin/${EXECBASE}-swriter
	@${PRINTF} "bin/openoffice.org\n" > ${TMPPLIST}
	@cd ${PREFIX} ; ${FIND} -s bin -type f | ${GREP} ${EXECBASE} >> ${TMPPLIST}
	@cd ${PREFIX} ; ${FIND} -s bin -type l | ${GREP} ${EXECBASE} >> ${TMPPLIST}
	@cd ${PREFIX} ; ${FIND} -s ${INSTALLATION_BASEDIR} -type f >> ${TMPPLIST}
	@cd ${PREFIX} ; ${FIND} -s ${INSTALLATION_BASEDIR} -type l >> ${TMPPLIST}
	@cd ${PREFIX} ; ${FIND} -s ${INSTALLATION_BASEDIR} -type d > ${WRKDIR}/dir.tmp
	@${SORT} -r ${WRKDIR}/dir.tmp | ${XARGS} -n 1 ${ECHO_CMD} @dirrm >> ${TMPPLIST}
	@${CP} ${FILESDIR}/pkg-message.in ${PKGMESSAGE}
	@${REINPLACE_CMD} -e 's#%%PREFIX%%#${PREFIX}#g' \
			-e 's#%%INSTALLATION_BASEDIR%%#${INSTALLATION_BASEDIR}#g' \
			-e 's#%%EXECBASE%%#${EXECBASE}#g' \
			-e 's#%%MILESTONE%%#${MILESTONE}#g' \
			-e 's#%%RELEASE_NR%%#${RELEASE_NR}#g' \
			${PKGMESSAGE}
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

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
	@${ECHO_MSG} "===>   Make SDK of OpenOffice.org"
	@cd ${WRKSRC} ; ${TCSH} -c 'source FreeBSDEnv.Set ; cd sdk_oo ; build.pl ; deliver.pl'
	@${MV} ${WRKSRC}/solver/${CODELINE}/unxfbsd.pro/bin/OpenOffice.org${RELEASE_NR}_SDK.tar.gz ${WRKDIR}/../${PACKAGE_BASENAME}_sdk.tar.gz

solver:
	@${ECHO_MSG} "===>   Make Solver of OpenOffice.org"
	@cd ${WRKSRC} ; ${TAR} cfz ${WRKDIR}/../${PACKAGE_BASENAME}_solver.tar.gz solver

.include <bsd.port.post.mk>
