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
COMMENT?=	Integrated wordprocessor/dbase/spreadsheet/drawing/chart/browser(developer version)

NO_LATEST_LINK=	yes
USE_GNOME=	gtk20 gnomevfs2
MOZILLA_VERSION=	1.7.5
MOZILLA_SOURCE=		mozilla-source-${MOZILLA_VERSION}.tar.gz
.if !defined(WITHOUT_MOZILLA)
DISTFILES+=	${MOZILLA_SOURCE}:mozsrc
USE_GNOME+=	libidl
.endif

.if defined(WITH_KDE)
USE_KDELIBS_VER=        3
.endif
USE_XLIB=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PERL5=	yes
USE_REINPLACE=	yes

.if !defined(WITHOUT_JAVA) && !defined(WITH_GNUGCJ)
USE_JAVA=	yes
JAVA_VERSION=	1.4
JAVA_BUILD=	jdk
.endif

.include <bsd.port.pre.mk>
.include <${FILESDIR}/Makefile.localized>

.if (${OSVERSION} < 503001 && ${OSVERSION} >= 500000) || (${OSVERSION} <= 492000)
BROKEN=		"rtld depends on _end symbol. type make -DTRYBROKEN to see how to upgrade your rtld"
.endif

CODELINE=		680
RELEASE_NR=		1.9
MILESTONE=		121
SNAPDATE=		20050725
INSTALLATION_BASEDIR=	openoffice.org${RELEASE_NR}m${MILESTONE}
EXECBASE=		openoffice.org-${RELEASE_NR}m${MILESTONE}
DIST_SUBDIR=		openoffice.org2.0
SIMPLEOSVER=		${OSREL:C/\.//g}
PACKAGE_BASENAME=	OOo_${RELEASE_NR}m${MILESTONE}_${OPSYS}${SIMPLEOSVER}Intel

LOCALIZED_LANG?=	en-US
# FIXME (Somehow INDEX build fails)
.if defined(LANG_PKGNAME)
PKGNAMEPREFIX=          ${LANG_PKGNAME}-
.endif
.if defined(LANG_SUFFIX)
PKGNAMESUFFIX?=         -${LANG_SUFFIX}
.endif

.if defined(WITH_GNUGCJ)
BUILD_DEPENDS+=	gcc41:${PORTSDIR}/lang/gcc41
BROKEN=	"still work in progress"
.else
BUILD_DEPENDS+=	gcc-ooo:${PORTSDIR}/lang/gcc-ooo
.endif

# FIXME (correctly add ccache before gcc and g++)
.if defined(WITH_CCACHE)
BUILD_DEPENDS+=	ccache:${PORTSDIR}/devel/ccache
.if defined(WITH_GNUGCJ)
CC=	ccache gcc41
CXX=	ccache g++41
.else
CC=	ccache gcc-ooo
CXX=	ccache g++-ooo
.endif #WITH_GNUGCJ
.endif #WITH_CCACHE
.if !defined(WITH_CCACHE)
.if defined(WITH_GNUGCJ)
CC=	gcc41
CXX=	g++41
.else
CC=	gcc-ooo
CXX=	g++-ooo
.endif #WITH_GNUGCJ
.endif #!WITH_CCACHE

BUILD_DEPENDS+=	zip:${PORTSDIR}/archivers/zip \
		unzip:${PORTSDIR}/archivers/unzip \
		gcp:${PORTSDIR}/sysutils/coreutils \
		gpatch:${PORTSDIR}/devel/patch \
		${SITE_PERL}/Archive/Zip.pm:${PORTSDIR}/archivers/p5-Archive-Zip \
		bison-devel:${PORTSDIR}/devel/bison-devel \
		imake:${X_IMAKE_PORT}
.if !defined(WITHOUT_JAVA)
BUILD_DEPENDS+=	${ANT}:${PORTSDIR}/devel/apache-ant
.else
LIB_DEPENDS+=	xslt.2:${PORTSDIR}/textproc/libxslt
.endif

GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}
CONFIGURE_WRKSRC=	${WRKSRC}/config_office
ANT?=		${LOCALBASE}/bin/ant
ZIP?=		${PREFIX}/bin/zip
TCSH?=		/bin/tcsh
PKGMESSAGE=	${WRKDIR}/pkg-message
NUMOFPROCESSES?=	1

CONFIGURE_ARGS+=	--with-gnu-cp=${LOCALBASE}/bin/gcp --with-gnu-patch=${LOCALBASE}/bin/gpatch --with-epm=internal --with-system-freetype

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
#.if defined(WITH_TTF_BYTECODE_ENABLED)
#	@cd ${WRKSRC} ; ${PATCH} < ${FILESDIR}/optpatch-freetype
#.endif
	@cd ${WRKDIR} ; ${CAT} ${DISTDIR}/${DIST_SUBDIR}/gpc231.tar.Z | ${TAR} xfz -
	@${CP} ${WRKDIR}/gpc231/gpc.c ${WRKSRC}/external/gpc/
	@${CP} ${WRKDIR}/gpc231/gpc.h ${WRKSRC}/external/gpc/
.if !defined(WITHOUT_MOZILLA)
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${MOZILLA_SOURCE} ${WRKSRC}/moz/download
.endif

do-build:
	@cd ${WRKSRC} ; ./bootstrap
.if (${NUMOFPROCESSES}>1)
	@cd ${WRKSRC} ;	${TCSH} -c "source FreeBSDEnv.Set ; cd instsetoo_native ; build.pl -P${NUMOFPROCESSES} --all"
.else
	@cd ${WRKSRC} ;	${TCSH} -c "source FreeBSDEnv.Set ; dmake"
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
	@${CP} ${FILESDIR}/openoffice.org-wrapper ${WRKDIR}/
	@${REINPLACE_CMD} -e 's#%%PREFIX%%#${PREFIX}#g' \
			-e 's#%%RELEASE_NR%%#${RELEASE_NR}#g' \
			-e 's#%%MILESTONE%%#${MILESTONE}#g' \
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

.include <${FILESDIR}/Makefile.others>
.include <bsd.port.post.mk>
