# New ports collection makefile for: OpenOffice.org
# Date created:		28 February 2002
# Whom:                 Martin Blapp
#
# $FreeBSD$
#

PORTNAME?=	openoffice.org
PORTVERSION?=	${OOOVERSION}
CATEGORIES+=	editors java
MASTER_SITES+=	http://openoffice.lunarshells.com/sources/ \
		http://ooopackages.good-day.net/pub/OpenOffice.org/sources/ \
		http://ooopackages.good-day.net/pub/OpenOffice.org/cws/:cws \
		ftp://ftp.cs.man.ac.uk/pub/toby/gpc/:gpc \
		${MASTER_SITE_APACHE:S,%SUBDIR%/,ant/binaries/:antbin,} \
		${MASTER_SITE_MOZILLA:S/$/:mozsrc/} \
		http://tools.openoffice.org/unowinreg_prebuild/680/:unowinreg
MASTER_SITE_SUBDIR+=	mozilla/releases/mozilla${MOZILLA_VERSION}/source/:mozsrc
DISTFILES+=	${OOOSRC} unowinreg.dll:unowinreg
.if defined(WITH_GPC)
DISTFILES+=	gpc231.tar.Z:gpc
.endif
.if defined(WITH_GNUGCJ)
DISTFILES+=	${ANT_DISTFILE}:antbin
.endif
EXTRACT_ONLY=	${OOOSRC}

MAINTAINER=	openoffice@FreeBSD.org
COMMENT?=	Integrated wordprocessor/dbase/spreadsheet/drawing/chart/browser

.if defined(WITH_CWS)
PORTNAME:=	openoffice.org-${OOOVERSION}-${WITH_CWS}
DISTFILES+=	${CWSARCHIVE}:cws
.endif
CWSARCHIVE=	${WITH_CWS}.tar.gz

OOOVERSION=	2.2.0
NO_LATEST_LINK=	yes
USE_GNOME=	gtk20
MOZILLA_VERSION=	1.7.5
MOZILLA_SOURCE=		mozilla-source-${MOZILLA_VERSION}.tar.gz
.if !defined(WITHOUT_MOZILLA)
DISTFILES+=	${MOZILLA_SOURCE}:mozsrc
USE_GNOME+=	libidl
.endif

.if defined(WITH_KDE)
USE_KDELIBS_VER=	3
.endif
USE_XLIB=	yes
USE_GMAKE=	yes
USE_PERL5=	yes
USE_BZIP2=	yes
WITHOUT_CPU_CFLAGS=	true

.if !defined(WITH_GNUGCJ)
USE_JAVA=	yes
JAVA_VERSION=	1.4+
JAVA_BUILD=	jdk
JAVA_VENDOR=	freebsd bsdjava
.endif

.include <bsd.port.pre.mk>
.include <${FILESDIR}/Makefile.localized>

ONLY_FOR_ARCHS=	i386 amd64

.if ${ARCH} == amd64
GCC_TARGET=		x86_64-portbld-freebsd${OSREL}
FREEBSD_ENV_SET=	FreeBSDAMDEnv.Set
.else
GCC_TARGET=		${ARCH}-portbld-freebsd${OSREL}
FREEBSD_ENV_SET=	FreeBSDX86Env.Set
.endif

CODELINE=		680
MILESTONE?=		14
OOOTAG?=		OOF680_m${MILESTONE}
OOOSRC?=		OOo_${OOOTAG}_source${EXTRACT_SUFX}
INSTALLATION_BASEDIR?=	openoffice.org-${OOOVERSION}
EXECBASE?=		openoffice.org-${OOOVERSION}
.if defined(WITH_CWS)
INSTALLATION_BASEDIR=	openoffice.org-${OOOVERSION}-${WITH_CWS}
EXECBASE=		openoffice.org-${OOOVERSION}-${WITH_CWS}
.endif
DIST_SUBDIR=		openoffice.org2.0
SIMPLEOSVER=		${OSREL:C/\.//g}
.if ${ARCH} == amd64
PACKAGE_BASENAME=	OOo_${OOOVERSION}_${OPSYS}${SIMPLEOSVER}X86_64
.else
PACKAGE_BASENAME=	OOo_${OOOVERSION}_${OPSYS}${SIMPLEOSVER}Intel
.endif

LOCALIZED_LANG?=	en-US
# FIXME (Somehow INDEX build fails)
.if defined(LANG_PKGNAME)
PKGNAMEPREFIX=		${LANG_PKGNAME}-
.endif
.if defined(LANG_SUFFIX)
PKGNAMESUFFIX=		-${LANG_SUFFIX}
.endif

RUN_DEPENDS+=	${LOCALBASE}/share/icons/hicolor/index.theme:${PORTSDIR}/misc/hicolor-icon-theme

.if defined(WITH_GNUGCJ)
GCCVER=41
BUILD_DEPENDS+=	${LOCALBASE}/libdata/ldconfig/gcc41-withgcjawt:${PORTSDIR}/lang/gcc41-withgcjawt
BUILD_DEPENDS+=	${LOCALBASE}/lib/jvm/java-gcj41/bin/java:${PORTSDIR}/java/java-gcj-compat
RUN_DEPENDS+=	${LOCALBASE}/libdata/ldconfig/gcc41-withgcjawt:${PORTSDIR}/lang/gcc41-withgcjawt
RUN_DEPENDS+=	${LOCALBASE}/lib/jvm/java-gcj41/bin/java:${PORTSDIR}/java/java-gcj-compat
.else
.if ${ARCH} == amd64
GCCVER=41
BUILD_DEPENDS+=	gcc41:${PORTSDIR}/lang/gcc41
RUN_DEPENDS+=	gcc41:${PORTSDIR}/lang/gcc41
.else
GCCVER=34
BUILD_DEPENDS+=	gcc-ooo:${PORTSDIR}/lang/gcc-ooo
.endif
.endif

.if defined(WITH_CCACHE)
BUILD_DEPENDS+=	ccache:${PORTSDIR}/devel/ccache
CCACHE_PREFIX=	ccache
.else
CCACHE_PREFIX=
.endif
.if (${GCCVER} == 41)
CC=	gcc41
CXX=	g++41
.endif
.if (${GCCVER} == 34)
CC=	gcc-ooo
CXX=	g++-ooo
.endif
CC:=	${CCACHE_PREFIX} ${CC}
CXX:=	${CCACHE_PREFIX} ${CXX}

BUILD_DEPENDS+=	zip:${PORTSDIR}/archivers/zip \
		unzip:${PORTSDIR}/archivers/unzip \
		gcp:${PORTSDIR}/sysutils/coreutils \
		gpatch:${PORTSDIR}/devel/patch \
		${SITE_PERL}/Archive/Zip.pm:${PORTSDIR}/archivers/p5-Archive-Zip \
		bison2:${PORTSDIR}/devel/bison2 \
		imake:${X_IMAKE_PORT}
.if defined(WITH_GNUGCJ)
LIB_DEPENDS+=	xslt.2:${PORTSDIR}/textproc/libxslt
LIB_DEPENDS+=	xml2.5:${PORTSDIR}/textproc/libxml2
ANT_DISTFILE=	apache-ant-${ANT_VERSION}-bin.tar.bz2
ANT_VERSION=	1.6.5
.else
BUILD_DEPENDS+=	ant:${PORTSDIR}/devel/apache-ant
.endif
.if !defined(WITH_GPC)
LIB_DEPENDS+=	art_lgpl_2:${PORTSDIR}/graphics/libart_lgpl
.endif

GNU_CONFIGURE=	yes
WRKSRC?=		${WRKDIR}/${OOOTAG}
CONFIGURE_WRKSRC=	${WRKSRC}/config_office
TCSH?=		/bin/tcsh
PKGMESSAGE=	${WRKDIR}/pkg-message
NUMOFPROCESSES?=	1
.if defined(WITH_GNUGCJ)
CONFIGURE_ENV+=		PATH="${LOCALBASE}/lib/jvm/java-gcj41/bin:${PATH}"
.endif

CONFIGURE_ARGS+=	--with-gnu-cp=${LOCALBASE}/bin/gcp		\
			--with-gnu-patch=${LOCALBASE}/bin/gpatch	\
			--enable-crashdump=yes				\
			--enable-symbols=SMALL

.if ${ARCH} == amd64 || ${GCCVER} == 41
WITHOUT_MOZILLA=	yes
.endif
.if (${GCCVER} == 41)
LIB_DEPENDS+=		boost_regex:${PORTSDIR}/devel/boost
CONFIGURE_ARGS+=	--with-system-boost=yes #i58343#
.endif
.if (${OSVERSION} <= 602102)
EXTRA_PATCHES+=	${FILESDIR}/rtld-workaround-i66667
.endif
.if defined(WITH_GNUGCJ)
EXTRA_PATCHES+=	${FILESDIR}/gcj-fbsdworkaround
.endif
.if !defined(WITH_SYSTEM_FREETYPE) && defined(WITH_TTF_BYTECODE_ENABLED)
EXTRA_PATCHES+=	 ${FILESDIR}/optpatch-freetype
.endif

ICONS=	${WRKSRC}/sysui/desktop/icons

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
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/unowinreg.dll ${WRKSRC}/external/unowinreg/
.if defined(WITH_CWS)
	cd ${WRKSRC} ; ${TAR} xvfz ${DISTDIR}/${DIST_SUBDIR}/${CWSARCHIVE}
.endif
.if defined(WITH_GNUGCJ)
	@cd ${WRKDIR} ; ${CAT} ${DISTDIR}/${DIST_SUBDIR}/${ANT_DISTFILE} | ${BZIP2_CMD} -d | ${TAR} xf -
.endif
.if defined(WITH_GPC)
	@cd ${WRKDIR} ; ${CAT} ${DISTDIR}/${DIST_SUBDIR}/gpc231.tar.Z | ${TAR} xfz -
	@${CP} ${WRKDIR}/gpc231/gpc.c ${WRKSRC}/external/gpc/
	@${CP} ${WRKDIR}/gpc231/gpc.h ${WRKSRC}/external/gpc/
.endif
.if !defined(WITHOUT_MOZILLA)
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${MOZILLA_SOURCE} ${WRKSRC}/moz/download
.endif

do-build:
	@cd ${WRKSRC} ; ./bootstrap
# PR:84786 #i53289#
.if (${NUMOFPROCESSES}>1)
	@cd ${WRKSRC} ; ${SETENV} "LANG=C" "LC_ALL=C" ${TCSH} -c "source ${FREEBSD_ENV_SET} ; cd instsetoo_native ; build.pl -P${NUMOFPROCESSES} --all"
.else
	@cd ${WRKSRC} ; ${SETENV} "LANG=C" "LC_ALL=C" ${TCSH} -c "source ${FREEBSD_ENV_SET} ; dmake"
.endif
.if ${LOCALIZED_LANG} == "all"
	@${MAKE} languagepack
.endif

do-install:
.if ${LOCALIZED_LANG} == "all"
	@cd ${WRKSRC}/instsetoo_native/unxfbsd?.pro/OpenOffice/bsd/install/en-US/freebsd-*/ ; ${LS} *.t?z > ${WRKDIR}/INSTALLFILES
	@cd ${WRKSRC}/instsetoo_native/unxfbsd?.pro/OpenOffice_languagepack/bsd/install/ ; ${LS} */freebsd*/*.t?z > ${WRKDIR}/LANGPACKFILES
	@${RM} -Rf ${WRKDIR}/tmp
	@${MKDIR} ${WRKDIR}/tmp
	@for i in `${CAT} ${WRKDIR}/INSTALLFILES`; do \
		${ECHO_CMD} "extracting $$i" ; \
		cd ${WRKDIR}/tmp ; ${TAR} xfz ${WRKSRC}/instsetoo_native/unxfbsd?.pro/OpenOffice/bsd/install/en-US/freebsd-*/$$i ; \
	done
	@for i in `${CAT} ${WRKDIR}/LANGPACKFILES`; do \
		${ECHO_CMD} "extracting $$i" ; \
		cd ${WRKDIR}/tmp ; ${TAR} xfz ${WRKSRC}/instsetoo_native/unxfbsd?.pro/OpenOffice_languagepack/bsd/install/$$i ;\
	done
	@${MKDIR} ${PREFIX}/${INSTALLATION_BASEDIR}
	@cd ${WRKDIR}/tmp/opt/openoffice* ; ${TAR} cf - -C . . | ${TAR} xf - -C ${PREFIX}/${INSTALLATION_BASEDIR}
.else
	@cd ${WRKSRC}/instsetoo_native/unxfbsd?.pro/OpenOffice/bsd/install/${LOCALIZED_LANG}/freebsd-*/ ; ${LS} *.t?z > ${WRKDIR}/INSTALLFILES
	@${RM} -Rf ${WRKDIR}/tmp
	@${MKDIR} ${WRKDIR}/tmp
	@for i in `${CAT} ${WRKDIR}/INSTALLFILES`; do \
		${ECHO_CMD} "extracting $$i" ; \
		cd ${WRKDIR}/tmp ; ${TAR} xfz ${WRKSRC}/instsetoo_native/unxfbsd?.pro/OpenOffice/bsd/install/${LOCALIZED_LANG}/freebsd-*/$$i ; \
	done
	@${MKDIR} ${PREFIX}/${INSTALLATION_BASEDIR}
	@cd ${WRKDIR}/tmp/opt/openoffice* ; ${TAR} cf - -C . . | ${TAR} xf - -C ${PREFIX}/${INSTALLATION_BASEDIR}
.endif

post-install:
	@${ECHO_MSG} "===>  Add wrapper scripts";
	@${CP} ${FILESDIR}/openoffice.org-wrapper ${WRKDIR}/
	@${REINPLACE_CMD} -e 's#%%PREFIX%%#${PREFIX}#g' \
			-e 's#%%OOOTAG%%#${OOOTAG}#g' \
			-e 's#%%OOOVERSION%%#${OOOVERSION}#g' \
			-e 's#%%INSTALLATION_BASEDIR%%#${INSTALLATION_BASEDIR}#g' \
			${WRKDIR}/openoffice.org-wrapper
	@${INSTALL_SCRIPT} ${WRKDIR}/openoffice.org-wrapper \
		${PREFIX}/bin/${EXECBASE}
	@${LN} -fs ${PREFIX}/bin/${EXECBASE} ${PREFIX}/bin/${EXECBASE}-sbase
	@${LN} -fs ${PREFIX}/bin/${EXECBASE} ${PREFIX}/bin/${EXECBASE}-scalc
	@${LN} -fs ${PREFIX}/bin/${EXECBASE} ${PREFIX}/bin/${EXECBASE}-sdraw
	@${LN} -fs ${PREFIX}/bin/${EXECBASE} ${PREFIX}/bin/${EXECBASE}-setofficelang
	@${LN} -fs ${PREFIX}/bin/${EXECBASE} ${PREFIX}/bin/${EXECBASE}-smath
	@${LN} -fs ${PREFIX}/bin/${EXECBASE} ${PREFIX}/bin/${EXECBASE}-simpress
	@${LN} -fs ${PREFIX}/bin/${EXECBASE} ${PREFIX}/bin/${EXECBASE}-spadmin
	@${LN} -fs ${PREFIX}/bin/${EXECBASE} ${PREFIX}/bin/${EXECBASE}-swriter
	@${ECHO_CMD} "" > ${TMPPLIST}
	@${REINPLACE_CMD} -e '/^Exec/s/printeradmin/spadmin/' \
			${PREFIX}/${INSTALLATION_BASEDIR}/share/xdg/*.desktop
	@for app in base calc draw impress math printeradmin writer; do \
		${REINPLACE_CMD} -e "s/^Exec.*/Exec=${EXECBASE} -$${app} %U/" \
		${PREFIX}/${INSTALLATION_BASEDIR}/share/xdg/$${app}.desktop ; \
	done
	@${RM} ${PREFIX}/${INSTALLATION_BASEDIR}/share/xdg/*.desktop.bak
	@${RM} -f ${DESKTOPDIR}/${EXECBASE}
	@${MKDIR} ${DESKTOPDIR}
	@${LN} -sf ${PREFIX}/${INSTALLATION_BASEDIR}/share/xdg \
			${DESKTOPDIR}/${EXECBASE}
	@${ECHO_CMD} "share/applications/${EXECBASE}" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ${RMDIR} %D/share/applications 2>/dev/null || ${TRUE}" >> ${TMPPLIST}
	@for dir in `ls ${ICONS}/hicolor | ${GREP} -v CVS`; do \
		for app in base calc draw impress math printeradmin writer; do \
			if [ -r ${ICONS}/hicolor/$${dir}/apps/$${app}.png ]; then \
				${CP} ${ICONS}/hicolor/$${dir}/apps/$${app}.png \
				    ${PREFIX}/share/icons/hicolor/$${dir}/apps/openofficeorg22-$${app}.png ; \
				${ECHO_CMD} "share/icons/hicolor/$${dir}/apps/openofficeorg22-$${app}.png" >> ${TMPPLIST} ; \
			fi \
		done ; \
		for file in `cd ${ICONS}/hicolor/$${dir}/mimetypes; ls *.png`; do \
			${CP} ${ICONS}/hicolor/$${dir}/mimetypes/$${file} \
			    ${PREFIX}/share/icons/hicolor/$${dir}/mimetypes/ ; \
			${ECHO_CMD} "share/icons/hicolor/$${dir}/mimetypes/$${file}" >> ${TMPPLIST} ; \
		done ; \
	done
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
			-e 's#%%OOOTAG%%#${OOOTAG}#g' \
			-e 's#%%OOOVERSION%%#${OOOVERSION}#g' \
			${PKGMESSAGE}
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <${FILESDIR}/Makefile.others>
.include <bsd.port.post.mk>
