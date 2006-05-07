# New ports collection makefile for: OpenOffice.org
# Date created:		28 February 2002
# Whom:                 Martin Blapp
#
# $FreeBSD$
#

PORTNAME=	openoffice.org
PORTVERSION=	1.1.5.${SNAPDATE}
CATEGORIES+=	editors
MASTER_SITES+=	http://openoffice.lunarshells.com/sources/ \
		ftp://ooopackages.good-day.net/pub/OpenOffice.org/sources/ \
		${MASTER_SITE_LOCAL:S/$/:moz/} \
		${MASTER_SITE_MOZILLA:S/$/:mozsrc/} \
		ftp://ftp.cs.man.ac.uk/pub/toby/gpc/:gpc \
		http://openoffice.lunarshells.com/sources/helpcontent/:help \
		${MASTER_SITE_RINGSERVER:S/$/:help/} \
		${MASTER_SITE_RINGSERVER:S/$/:help3/} \
		ftp://ftp.kddlabs.co.jp/office/openoffice/contrib/helpcontent/:help \
		ftp://sunsite.cnlab-switch.ch/mirror/OpenOffice/contrib/helpcontent/:help \
		http://ftp.services.openoffice.org/pub/OpenOffice.org/contrib/helpcontent/:help \
		ftp://ftp.linux.cz/pub/localization/OpenOffice.org/1.1.5/build/Files/:help2
MASTER_SITE_SUBDIR+=	maho/openoffice.org/:moz \
		mozilla/releases/mozilla${MOZILLA_VERSION}/src/:mozsrc \
		misc/openoffice/contrib/helpcontent/:help \
		misc/openoffice/contrib/helpcontent-1.0/:help3
DISTFILES+=	OOo_SRX645_m${MILESTONE}_source.tar.bz2
.if defined(WITH_GPC)
DISTFILES+=	gpc231.tar.Z:gpc
.endif
EXTRACT_ONLY=	OOo_SRX645_m${MILESTONE}_source.tar.bz2

MAINTAINER=	openoffice@FreeBSD.org
COMMENT?=	Integrated wordprocessor/dbase/spreadsheet/drawing/chart/browser

NO_LATEST_LINK=	yes

MOZILLA_PROJECT=	cws_srx645_mozooo.20040203.tar.gz
MOZILLA_VERSION=	1.0
MOZILLA_SOURCE=		mozilla-source-${MOZILLA_VERSION}.tar.gz
.if !defined(WITHOUT_MOZILLA)
DISTFILES+=	${MOZILLA_PROJECT}:moz ${MOZILLA_SOURCE}:mozsrc
USE_GNOME+=	orbit
.endif

USE_XLIB=	yes
USE_PERL5=	yes
USE_BISON=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes
USE_GNOME+=	gtk20
WITHOUT_CPU_CFLAGS=	true

ONLY_FOR_ARCHS=	i386

.if !defined(WITHOUT_JAVA)
USE_JAVA=	yes
JAVA_VERSION=	1.4
JAVA_BUILD=	jdk
JAVA_VENDOR=	bsdjava
.endif

.include <bsd.port.pre.mk>
.include <${FILESDIR}/Makefile.localized>

.if ${OSVERSION} >= 600105
BROKEN=		Does not compile on FreeBSD >= 6.1
.endif

LANG_EXT?=	01
LANG_CONFIGURE_ARG?=	ENUS
L10NHELP?=     helpcontent_01_unix.tgz

DISTFILES+=	${L10NHELP}:help
.if defined(ALL_LOCALIZED_LANGS)
DISTFILES+=	helpcontent_07_unix.tgz:help3 \
		helpcontent_31_unix.tgz:help  helpcontent_33_unix.tgz:help \
		helpcontent_34_unix.tgz:help  helpcontent_39_unix.tgz:help \
		helpcontent_42_unix.tgz:help2 helpcontent_43_unix.tgz:help2 \
		helpcontent_46_unix.tgz:help  helpcontent_49_unix.tgz:help \
		helpcontent_50_unix.tgz:help2 helpcontent_55_unix.tgz:help \
		helpcontent_81_unix.tgz:help  helpcontent_82_unix.tgz:help \
		helpcontent_86_unix.tgz:help  helpcontent_88_unix.tgz:help \
		helpcontent_90_unix.tgz:help
L10NHELPS=	helpcontent_01_unix.tgz helpcontent_07_unix.tgz \
		helpcontent_31_unix.tgz helpcontent_33_unix.tgz \
		helpcontent_34_unix.tgz helpcontent_39_unix.tgz \
		helpcontent_42_unix.tgz helpcontent_43_unix.tgz \
		helpcontent_46_unix.tgz helpcontent_49_unix.tgz \
		helpcontent_50_unix.tgz helpcontent_55_unix.tgz \
		helpcontent_81_unix.tgz helpcontent_82_unix.tgz \
		helpcontent_86_unix.tgz helpcontent_88_unix.tgz \
		helpcontent_90_unix.tgz
.endif

CODELINE=		645
RELEASE_NR=		1.1.5
MILESTONE=		60
SNAPDATE=		20060114
INSTALLATION_BASEDIR=	OpenOffice.org${RELEASE_NR}
EXECBASE=		openoffice.org-${RELEASE_NR}m${MILESTONE}
DIST_SUBDIR=		openoffice.org1.1
SIMPLEOSVER=		${OSREL:C/\.//g}
PACKAGE_BASENAME=       OOo_${RELEASE_NR}m${MILESTONE}_${OPSYS}${SIMPLEOSVER}Intel

# FIXME (Somehow INDEX build fails)
.if defined(LANG_PKGNAME)
PKGNAMEPREFIX=          ${LANG_PKGNAME}-
.endif
.if defined(LANG_SUFFIX)
PKGNAMESUFFIX?=         -${LANG_SUFFIX}
.endif

BUILD_DEPENDS+=	gcc33:${PORTSDIR}/lang/gcc33
# FIXME (correctly add ccache before gcc and g++)
.if defined(WITH_CCACHE)
BUILD_DEPENDS+=	ccache:${PORTSDIR}/devel/ccache
CC=	ccache gcc33
CXX=	ccache g++33
.else
CC=	gcc33
CXX=	g++33
.endif
BUILD_DEPENDS+=	zip:${PORTSDIR}/archivers/zip \
		unzip:${PORTSDIR}/archivers/unzip \
		gcp:${PORTSDIR}/sysutils/coreutils \
		imake:${X_IMAKE_PORT}
.if defined(WITHOUT_JAVA)
LIB_DEPENDS+=	xslt.2:${PORTSDIR}/textproc/libxslt
.endif
.if !defined(WITH_GPC)
LIB_DEPENDS=	art_lgpl_2:${PORTSDIR}/graphics/libart_lgpl2
.endif
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}
CONFIGURE_WRKSRC=	${WRKSRC}/config_office
TCSH?=		/bin/tcsh
PKGMESSAGE=	${WRKDIR}/pkg-message
NUMOFPROCESSES?=	1

CONFIGURE_ARGS+=	--with-gnu-cp=${LOCALBASE}/bin/gcp --enable-pasf --enable-crashdump --enable-symbols=SMALL

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
.if defined(WITH_GPC)
	@cd ${WRKDIR} ; ${CAT} ${DISTDIR}/${DIST_SUBDIR}/gpc231.tar.Z | ${TAR} xfz -
	@${CP} ${WRKDIR}/gpc231/gpc.c ${WRKSRC}/external/gpc/
	@${CP} ${WRKDIR}/gpc231/gpc.h ${WRKSRC}/external/gpc/
.endif
	@${MKDIR} ${WRKDIR}/L10NHELP
	@cd ${WRKDIR}/L10NHELP ; \
		${CAT} ${DISTDIR}/${DIST_SUBDIR}/${L10NHELP} | ${GZIP_CMD} -d | ${TAR} xf -
.if defined(ALL_LOCALIZED_LANGS)
	@cd ${WRKDIR}/L10NHELP ; \
	for helpfile in ${L10NHELPS}; do \
		${CAT} ${DISTDIR}/${DIST_SUBDIR}/$$helpfile | ${GZIP_CMD} -d | ${TAR} xf - ; \
	done
.endif
.if !defined(WITHOUT_MOZILLA)
	@(cd ${WRKSRC} ; ${MV} moz moz.old ; ${TAR} xfz ${DISTDIR}/${DIST_SUBDIR}/${MOZILLA_PROJECT} ; ${PATCH} < ${FILESDIR}/moz-patch)
	@${MKDIR} ${WRKSRC}/moz/download
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${MOZILLA_SOURCE} ${WRKSRC}/moz/download
	@cd ${WRKSRC} ; ${MV} moz moz.runtime ; ${MV} moz.old moz
.endif

do-build:
	@cd ${WRKSRC} ; ./bootstrap
.if !defined(WITHOUT_MOZILLA)
	@cd ${WRKSRC}/moz.runtime ; ${SETENV} "BUILD_MOZAB=TRUE" ${TCSH} -c 'source ../FreeBSDEnv.Set ; build.pl ; dmake zip' ; ${CP} unxfbsd.pro/zipped/FREEBSD*.zip ../moz/zipped
.endif
	@${MKDIR} ${WRKSRC}/solver/${CODELINE}/unxfbsd.pro/pck
	@${CP} ${WRKDIR}/L10NHELP/*.zip ${WRKSRC}/solver/${CODELINE}/unxfbsd.pro/pck
# PR:84786
.if (${NUMOFPROCESSES}>1)
	@cd ${WRKSRC} ; ${SETENV} "LC_ALL=C" "LANG=C" ${TCSH} -c "source FreeBSDEnv.Set ; cd instsetoo ; build.pl -P${NUMOFPROCESSES} --all"
.else
	@cd ${WRKSRC} ; ${SETENV} "LC_ALL=C" "LANG=C" ${TCSH} -c "source FreeBSDEnv.Set ; dmake"
.endif

do-install:
	@cd ${WRKSRC}/instsetoo/*.pro/${LANG_EXT}/normal/ ; ./install --prefix=${PREFIX}

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
