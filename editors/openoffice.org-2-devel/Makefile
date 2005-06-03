# New ports collection makefile for: OpenOffice.org
# Date created:		28 February 2002
# Whom:                 Martin Blapp
#
# $FreeBSD$
#

PORTNAME=	openoffice
PORTVERSION=	2.0.${SNAPDATE}
CATEGORIES+=	editors
MASTER_SITES+=	ftp://ooopackages.good-day.net/pub/OpenOffice.org/sources/ \
		ftp://ftp.cs.man.ac.uk/pub/toby/gpc/:gpc \
		${MASTER_SITE_MOZILLA:S,%SUBDIR%,mozilla/releases/mozilla${MOZILLA_VERSION}/&,}source/:mozsrc
DISTFILES+=	OOo_${RELEASE_NR}m${MILESTONE}_source.tar.bz2 gpc231.tar.Z:gpc
EXTRACT_ONLY=	OOo_${RELEASE_NR}m${MILESTONE}_source.tar.bz2

MAINTAINER=	openoffice@FreeBSD.org
COMMENT?=	Integrated wordprocessor/dbase/spreadheet/drawing/chart/browser(developer version)

NO_LATEST_LINK=	yes
USE_GNOME=	gtk20 gnomevfs2
MOZILLA_VERSION=	1.7.5
MOZILLA_SOURCE=		mozilla-source-${MOZILLA_VERSION}.tar.gz
.if !defined(WITHOUT_MOZILLA)
DISTFILES+=	${MOZILLA_SOURCE}:mozsrc
.endif

.if defined(WITH_KDE)
USE_KDELIBS_VER=        3
.endif
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PERL5=	yes
USE_REINPLACE=	yes

.if !defined(WITHOUT_JAVA)
USE_JAVA=	yes
JAVA_VERSION=	1.4+
JAVA_BUILD=	jdk
.endif

.include <bsd.port.pre.mk>
.include <${FILESDIR}/Makefile.localized>

.if (${OSVERSION} < 503001 && ${OSVERSION} >= 500000) || (${OSVERSION} <= 492000)
BROKEN=		"rtld depends on _end symbol. type make -DTRYBROKEN to see how to upgrade your rtld"
.endif

CODELINE=		680
RELEASE_NR=		1.9
MILESTONE=		107
SNAPDATE=		20050521
INSTALLATION_BASEDIR=	openoffice.org${RELEASE_NR}m${MILESTONE}
EXECBASE=		openoffice.org-${RELEASE_NR}m${MILESTONE}
DIST_SUBDIR=		openoffice.org2.0
SIMPLEOSVER!=		${UNAME} -r | ${SED} -e 's/\.//g' | ${SED} -e 's/-.*//'
PACKAGE_BASENAME=	OOo_${RELEASE_NR}m${MILESTONE}_${OPSYS}${SIMPLEOSVER}Intel

LOCALIZED_LANG?=	en-US
# FIXME (Somehow INDEX build fails)
.if defined(LANG_PKGNAME)
PKGNAMEPREFIX=          ${LANG_PKGNAME}-
.endif
.if defined(LANG_SUFFIX)
PKGNAMESUFFIX?=         -${LANG_SUFFIX}
.endif

BUILD_DEPENDS+=	gcc-ooo:${PORTSDIR}/lang/gcc-ooo
# FIXME (correctly add ccache before gcc and g++)
.if defined(WITH_CCACHE)
BUILD_DEPENDS+=	ccache:${PORTSDIR}/devel/ccache
CC=	ccache gcc-ooo
CXX=	ccache g++-ooo
.else
CC=	gcc-ooo
CXX=	g++-ooo
.endif
BUILD_DEPENDS+=	zip:${PORTSDIR}/archivers/zip \
		unzip:${PORTSDIR}/archivers/unzip \
		gcp:${PORTSDIR}/sysutils/coreutils \
		gpatch:${PORTSDIR}/devel/patch \
		xmkmf:${X_IMAKE_PORT} \
		${X11BASE}/lib/libXft.so:${PORTSDIR}/x11-fonts/libXft \
		${SITE_PERL}/Archive/Zip.pm:${PORTSDIR}/archivers/p5-Archive-Zip \
		bison-devel:${PORTSDIR}/devel/bison-devel
LIB_DEPENDS+=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		mng.1:${PORTSDIR}/graphics/libmng \
		freetype.9:${PORTSDIR}/print/freetype2 \
		IDL-2.0:${PORTSDIR}/devel/libIDL
.if defined(WITHOUT_JAVA)
LIB_DEPENDS+=	xslt.2:${PORTSDIR}/textproc/libxslt
.else
BUILD_DEPENDS+=	${ANT}:${PORTSDIR}/devel/apache-ant
.endif

GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}
CONFIGURE_WRKSRC=	${WRKSRC}/config_office
ANT?=		${LOCALBASE}/bin/ant
ZIP?=		${PREFIX}/bin/zip
TCSH?=		/bin/tcsh
PKGMESSAGE=	${WRKDIR}/pkg-message
NUMOFPROCESSES?=	1

CONFIGURE_ARGS+=	--with-gnu-cp=${LOCALBASE}/bin/gcp  --with-gnu-patch=${LOCALBASE}/bin/gpatch

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
	@cd ${WRKDIR} ; ${CAT} ${DISTDIR}/${DIST_SUBDIR}/gpc231.tar.Z | ${TAR} xfz -
	@${CP} ${WRKDIR}/gpc231/gpc.c ${WRKSRC}/external/gpc/
	@${CP} ${WRKDIR}/gpc231/gpc.h ${WRKSRC}/external/gpc/
.if !defined(WITHOUT_MOZILLA)
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${MOZILLA_SOURCE} ${WRKSRC}/moz/download
.endif

do-build:
	@cd ${WRKSRC} ; ./bootstrap
.if (${NUMOFPROCESSES}>1)
	@cd ${WRKSRC} ;	${SETENV} "DEFAULT_TO_ENGLISH_FOR_PACKING=yes" ${TCSH} -c "source FreeBSDEnv.Set ; cd instsetoo_native ; build.pl -P${NUMOFPROCESSES} --all"
.else
	@cd ${WRKSRC} ;	${SETENV} "DEFAULT_TO_ENGLISH_FOR_PACKING=yes"  ${TCSH} -c "source FreeBSDEnv.Set ; dmake"
.endif

do-install:
	@cd ${WRKSRC}/instsetoo_native/unxfbsd.pro/OpenOffice/install/${LOCALIZED_LANG}/freebsd-*/ ; ${LS} *.tgz > ${WRKDIR}/INSTALLFILES
	@${RM} -Rf ${WRKDIR}/tmp
	@${MKDIR} ${WRKDIR}/tmp
	@for i in `${CAT} ${WRKDIR}/INSTALLFILES`; do \
		${CP} ${WRKSRC}/instsetoo_native/unxfbsd.pro/OpenOffice/install/${LOCALIZED_LANG}/freebsd-*/$$i ${WRKDIR}/tmp ; \
		cd ${WRKDIR}/tmp ; ${TAR} xf ${WRKDIR}/tmp/$$i ; \
	done
	@${MKDIR} ${PREFIX}/${INSTALLATION_BASEDIR}
	@cd ${WRKDIR}/tmp/opt/openoffice* ; ${TAR} cf - -C . . | ${TAR} xf - -C ${PREFIX}/${INSTALLATION_BASEDIR}

post-install:
	@${ECHO_MSG} "===>  Add wrapper scripts";
	@${CP} ${FILESDIR}/openoffice-wrapper ${WRKDIR}/
	@${REINPLACE_CMD} -e 's#%%PREFIX%%#${PREFIX}#g' \
			-e 's#%%RELEASE_NR%%#${RELEASE_NR}#g' \
			-e 's#%%MILESTONE%%#${MILESTONE}#g' \
			-e 's#%%INSTALLATION_BASEDIR%%#${INSTALLATION_BASEDIR}#g' \
			${WRKDIR}/openoffice-wrapper
	@${INSTALL_SCRIPT} ${WRKDIR}/openoffice-wrapper \
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
	@${ECHO_MSG} "===>   Rename package for OpenOffice.org mirror upload";
	@${MV} ${PKGFILE} \
		${WRKDIR}/../${PACKAGE_BASENAME}_install_${LOCALIZED_LANG}${PKG_SUFX}

package-canonical:
	@${ECHO_MSG} "===>   Canonical packaging for OpenOffice.org";
	@cd ${WRKSRC}/instsetoo_native/unxfbsd.pro/OpenOffice/install/${LOCALIZED_LANG}/freebsd-*/ ;\
	${TAR} cfj ${WRKDIR}/../${PACKAGE_BASENAME}_native_install_${LOCALIZED_LANG}${PKG_SUFX} .
	@${CP} ${WRKSRC}/instsetoo_native/unxfbsd.pro/OpenOffice_languagepack/install/${LOCALIZED_LANG}/freebsd-*/openofficeorg-*.tgz .

sdk:
	@${ECHO_MSG} "===>   Make SDK of OpenOffice.org"
	@cd ${WRKSRC} ; ${TCSH} -c 'source FreeBSDEnv.Set ; cd sdk_oo ; build.pl ; deliver.pl'
	@${MV} ${WRKSRC}/solver/${CODELINE}/unxfbsd.pro/bin/OpenOffice.org2.0_SDK.tar.gz ${WRKDIR}/../${PACKAGE_BASENAME}_sdk.tar.gz

solver:
	@${ECHO_MSG} "===>   Make Solver of OpenOffice.org"
	@cd ${WRKSRC} ; ${TAR} cfj ${WRKDIR}/../${PACKAGE_BASENAME}_solver.tar.bz2 solver

languagepack:
	@${ECHO_MSG} "===>   Make languagepack of OpenOffice.org"
.if defined (ALL_LOCALIZED_LANGS)
	@cd ${WRKSRC} ; ${SETENV} "DEFAULT_TO_ENGLISH_FOR_PACKING=yes" ${TCSH} -c 'source FreeBSDEnv.Set ; cd instsetoo_native/util ; dmake ooolanguagepack'
.else
	@cd ${WRKSRC} ; ${SETENV} "DEFAULT_TO_ENGLISH_FOR_PACKING=yes" ${TCSH} -c 'source FreeBSDEnv.Set ; cd instsetoo_native/util ; dmake ooolanguagepack_${LOCALIZED_LANG}'
.endif

.if !defined (ALL_LOCALIZED_LANGS)
	@${RM} -fr ${WRKDIR}/langpack_tmp
	@${MKDIR} ${WRKDIR}/langpack_tmp
.if defined (LOCALIZED_LANG)
	@cd ${WRKDIR}/langpack_tmp ; \
		${TAR} xf ${WRKSRC}/instsetoo_native/unxfbsd.pro/OpenOffice_languagepack/install/${LOCALIZED_LANG}/freebsd-*/openofficeorg-*.tgz
	@cd ${WRKDIR}/langpack_tmp/opt/openoffice* ; \
		${MKDIR} ../${INSTALLATION_BASEDIR} ; \
		${MV} * ../${INSTALLATION_BASEDIR} ; cd .. ; \
		${TAR} cfj ${WRKDIR}/../${PACKAGE_BASENAME}_langpack_${LOCALIZED_LANG}.tar.bz2 ${INSTALLATION_BASEDIR}
.endif
.endif

.include <bsd.port.post.mk>
