# New ports collection makefile for: OpenOffice.org
# Date created:		28 February 2002
# Whom:                 Martin Blapp
#
# $FreeBSD$
#

PORTNAME=	openoffice
PORTVERSION=	2.0.${SNAPDATE}
CATEGORIES+=	editors
MASTER_SITES+=	${MASTER_SITE_LOCAL} \
		ftp://ftp.cs.man.ac.uk/pub/toby/gpc/:gpc \
		${MASTER_SITE_MOZILLA:S,%SUBDIR%,mozilla/releases/mozilla1.7b/src/&,}:mozsrc \
		http://ftp.services.openoffice.org/pub/OpenOffice.org/contrib/helpcontent/:help
MASTER_SITE_SUBDIR=	maho/openoffice.org
DISTFILES+=	OOo_${BUILD_NR}${MILESTONE}_${SNAPDATE}_source.tar.bz2 gpc231.tar.Z:gpc
EXTRACT_ONLY=	OOo_${BUILD_NR}${MILESTONE}_${SNAPDATE}_source.tar.bz2

MAINTAINER=	openoffice@FreeBSD.org
COMMENT?=	Integrated wordprocessor/dbase/spreadheet/drawing/chart/browser(developer version)

BROKEN=         "Bison 1.875a or newer is required, and doesn't work atm"

SNAPDATE=	20041122
NO_LATEST_LINK=	yes
USE_GNOME=	gtk20
MOZILLA_PROJECT=	cws_srx645_mozooo.20041016.tar.gz
MOZILLA_SOURCE=		mozilla-source-1.7b-source.tar.gz
.if !defined(WITHOUT_MOZILLA)
DISTFILES+=	${MOZILLA_PROJECT} ${MOZILLA_SOURCE}:mozsrc
USE_GNOME+=	orbit gtk12
.endif

USE_PERL5=	yes
#USE_BISON=	yes #this bison should be later than bison1.875a
USE_REINPLACE=	yes
USE_BZIP2=	yes

.if !defined(WITHOUT_JAVA)
USE_JAVA=	yes
JAVA_VERSION=	1.4+
JAVA_BUILD=	jdk
.endif

.include <bsd.port.pre.mk>
.include <${FILESDIR}/Makefile.localized>

LANG_PKGNAME?=	en-US
LANG_EXT?=	01

.if defined(L10NHELP)
DISTFILES+=	${L10NHELP}:help
.endif
.if defined(ALL_LOCALIZED_LANGS)
DISTFILES+=	helpcontent_49_unix.tgz:help
L10NHELPS+=	helpcontent_49_unix.tgz
.endif

BUILD_NR=		680
MILESTONE=		m62
RELEASE_NR=		2.0
DIST_SUBDIR=		openoffice2.0
SIMPLEOSVER!=		${UNAME} -r | ${SED} -e 's/\.//' | ${SED} -e 's/\..*//'
# gcc 3.3
BUILD_DEPENDS+=	gcc33:${PORTSDIR}/lang/gcc33
# FIXME
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
		epm:${PORTSDIR}/devel/epm \
		gpatch:${PORTSDIR}/devel/patch \
		${X11BASE}/lib/libXft.so:${PORTSDIR}/x11-fonts/libXft \
		${SITE_PERL}/Archive/Zip.pm:${PORTSDIR}/archivers/p5-Archive-Zip
#		bison-devel:${PORTSDIR}/devel/bison-devel
LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		mng.1:${PORTSDIR}/graphics/libmng \
		freetype.9:${PORTSDIR}/print/freetype2
.if defined(WITHOUT_JAVA)
LIB_DEPENDS=	xslt.2:${PORTSDIR}/textproc/libxslt
.else
BUILD_DEPENDS+=	${ANT}:${PORTSDIR}/devel/apache-ant
.endif
GNU_CONFIGURE=	yes
USE_AUTOCONF_VER=	259

OOODIR=		oo_${RELEASE_NR}_src
WRKDIR=		${WRKDIRPREFIX}${.CURDIR}/work
WRKSRC=		${WRKDIR}/${OOODIR}
CONFIGURE_WRKSRC=	${WRKDIR}/${OOODIR}/config_office
ANT?=		${LOCALBASE}/bin/ant
TCSH?=		/bin/tcsh
ZIP?=		${PREFIX}/bin/zip
UNZIP?=		${PREFIX}/bin/unzip

CONFIGURE_ENV=		PTHREAD_CFLAGS=${PTHREAD_CFLAGS} \
			PTHREAD_LIBS=${PTHREAD_LIBS}
CONFIGURE_ARGS+=	--with-gnu-cp=${LOCALBASE}/bin/gcp  --with-gnu-patch=${LOCALBASE}/bin/gpatch

.if defined(WITHOUT_JAVA)
CONFIGURE_ARGS+=	--disable-java
.else
CONFIGURE_ARGS+=	--with-jdk-home="${JAVA_HOME}" --with-ant-home=${LOCALBASE}/ant
.endif

.if defined(WITHOUT_MOZILLA)
CONFIGURE_ARGS+=	--disable-mozilla
.endif

.if defined(ALL_LOCALIZED_LANGS)
CONFIGURE_ARGS+=	--with-lang=ALL
.else
CONFIGURE_ARGS+=	--with-lang=${LANG_PKG_NAME}
.endif

.if defined(WITH_DEBUG)
.if ${WITH_DEBUG} == 2
CONFIGURE_ARGS+=	--enable-debug
.else
CONFIGURE_ARGS+=	--enable-symbols
.endif
.endif

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
	@cd ${WRKDIR} ; ${CAT} ${DISTDIR}/${DIST_SUBDIR}/gpc231.tar.Z | ${TAR} xfz -
	@${CP} ${WRKDIR}/gpc231/gpc.c ${WRKSRC}/external/gpc/
	@${CP} ${WRKDIR}/gpc231/gpc.h ${WRKSRC}/external/gpc/
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
	for helpfile in ${L10NHELPS}; do \
		${CAT} ${DISTDIR}/${DIST_SUBDIR}/$$helpfile | ${GZIP_CMD} -d | ${TAR} xf - ; \
	done
.endif
.if !defined(WITHOUT_MOZILLA)
	cd ${WRKSRC} ; ${MV} moz moz.old ; ${TAR} xfz ${DISTDIR}/${DIST_SUBDIR}/${MOZILLA_PROJECT} ; ${PATCH} < ${FILESDIR}/moz-patch
	${MKDIR} ${WRKSRC}/moz/download
	${CP} ${DISTDIR}/${DIST_SUBDIR}/mozilla-source-1.7b-source.tar.gz ${WRKSRC}/moz/download
	cd ${WRKSRC} ; ${MV} moz moz.runtime ; ${MV} moz.old moz
.endif

post-patch:
	@${REINPLACE_CMD} -e 's+%%PTHREAD_LIBS%%+${PTHREAD_LIBS}+g;' ${WRKSRC}/odk/settings/settings.mk
	@${REINPLACE_CMD} -e 's+%%PTHREAD_CFLAGS%%+${PTHREAD_CFLAGS}+g' ${WRKSRC}/odk/settings/settings.mk

do-build:
	@cd ${WRKSRC} ; ./bootstrap
.if defined(L10NHELP) || defined(ALL_LOCALIZED_LANGS)
	@${MKDIR} ${WRKSRC}/solver/${BUILD_NR}/unxfbsd.pro/pck
	@${CP} ${WRKDIR}/L10NHELP/*.zip ${WRKSRC}/solver/${BUILD_NR}/unxfbsd.pro/pck
.endif
.if !defined(WITHOUT_MOZILLA)
	cd ${WRKSRC}/moz.runtime ; ${SETENV} "BUILD_MOZAB=TRUE" ${TCSH} -c 'source ../FreeBSDEnv.Set ; build.pl ; dmake zip' ; ${CP} unxfbsd.pro/zipped/FREEBSD*.zip ../moz/zipped
.endif
	@cd ${WRKSRC} ;	${TCSH} -c 'source FreeBSDEnv.Set ; dmake'

pre-install:
	@${CP} ${FILESDIR}/oo_setup.resp \
		${WRKSRC}/instsetoo/unxfbsd.pro/${LANG_PKGNAME}/normal/
	@${REINPLACE_CMD} -e 's#%%PREFIX%%#${PREFIX}#g' \
			-e 's#%%RELEASE_NR%%#${RELEASE_NR}#g' \
		${WRKSRC}/instsetoo/unxfbsd.pro/${LANG_PKGNAME}/normal/oo_setup.resp

do-install:
	TEMP=${WRKDIR} ${WRKSRC}/instsetoo/*.pro/${LANG_PKGNAME}/normal/setup -r:oo_setup.resp

install-user:
	${PREFIX}/${INSTALLATION_BASEDIR}/program/setup

post-install:
	@${ECHO_MSG} "===>  Add wrapper scripts";
	@${CP} ${FILESDIR}/openoffice-wrapper ${WRKDIR}/
	@${REINPLACE_CMD} -e 's#%%PREFIX%%#${PREFIX}#g' \
			-e 's#%%LANG%%#${USE_LANG}#g' \
			-e 's#%%BUILD_NR%%#${BUILD_NR}#g' \
			-e 's#%%RELEASE_NR%%#${RELEASE_NR}#g' \
			${WRKDIR}/openoffice-wrapper
	@${INSTALL_SCRIPT} ${WRKDIR}/openoffice-wrapper \
		${PREFIX}/bin/openoffice-${RELEASE_NR}
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
	@cd ${WRKSRC} && ${SH} -c 'source FreeBSDEnv.Set ; cd sdk_oo ; build.pl ; deliver.pl'
	${MV} ${WRKSRC}/solver/${BUILD_NR}/unxfbsd.pro/bin/OpenOffice.org${RELEASE_NR}_SDK.tar.gz ${WRKDIR}/../OOo_${BUILD_NR}${MILESTONE}_${OPSYS}${SIMPLEOSVER}Intel_sdk.tar.gz

solver:
	@${ECHO_MSG} "===>   Make Solver of OpenOffice.org"
	@cd ${WRKSRC} ; ${TAR} cfz ${WRKDIR}/../OOo_${BUILD_NR}${MILESTONE}_${OPSYS}${SIMPLEOSVER}Intel_solver.tar.gz solver

.include <bsd.port.post.mk>
