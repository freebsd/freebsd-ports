# New ports collection makefile for: OpenOffice.org
# Date created:		28 February 2002
# Whom:                 Martin Blapp
#
# $FreeBSD$
#

PORTNAME?=	openoffice.org
PORTVERSION?=	${OOOVERSION}
CATEGORIES+=	editors java
MASTER_SITES+=	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,misc/openoffice/stable/${OOOVERSION}/&,} \
		http://openoffice.lunarshells.com/sources/ \
		http://ooopackages.good-day.net/pub/OpenOffice.org/sources/ \
		ftp://ftp.cs.man.ac.uk/pub/toby/gpc/:gpc \
		${MASTER_SITE_APACHE:S,%SUBDIR%/,ant/binaries/:antbin,} \
		${MASTER_SITE_MOZILLA:S/$/:mozsrc/}
MASTER_SITE_SUBDIR+=	mozilla/releases/mozilla${MOZILLA_VERSION}/source/:mozsrc
DISTFILES+=	OOo_${OOOVERSION}_src.tar.gz
.if defined(WITH_GPC)
DISTFILES+=     gpc231.tar.Z:gpc
.endif
.if defined(WITH_GNUGCJ)
DISTFILES+=     ${ANT_DISTFILE}:antbin
.endif
EXTRACT_ONLY=	OOo_${OOOVERSION}_src.tar.gz

MAINTAINER=	openoffice@FreeBSD.org
COMMENT?=	Integrated wordprocessor/dbase/spreadsheet/drawing/chart/browser

OOOVERSION=	2.0.2
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
USE_GMAKE=	yes
USE_PERL5=	yes
WITHOUT_CPU_CFLAGS=	true

ONLY_FOR_ARCHS=	i386

.if !defined(WITH_GNUGCJ)
USE_JAVA=	yes
JAVA_VERSION=	1.4+
JAVA_BUILD=	jdk
JAVA_VENDOR=	freebsd bsdjava
.endif

.include <bsd.port.pre.mk>
.include <${FILESDIR}/Makefile.localized>

.if ${PERL_LEVEL} < 500600
IGNORE=		install lang/perl5.8 then try again
.endif

CODELINE=		680
RELEASE_NR=		2.0
OOOTAG?=		OOB680_m5
INSTALLATION_BASEDIR?=	openoffice.org-${OOOVERSION}
EXECBASE?=		openoffice.org-${OOOVERSION}
DIST_SUBDIR=		openoffice.org2.0
SIMPLEOSVER=		${OSREL:C/\.//g}
PACKAGE_BASENAME=	OOo_${OOOVERSION}_${OPSYS}${SIMPLEOSVER}Intel

LOCALIZED_LANG?=	en-US
# FIXME (Somehow INDEX build fails)
.if defined(LANG_PKGNAME)
PKGNAMEPREFIX=          ${LANG_PKGNAME}-
.endif
.if defined(LANG_SUFFIX)
PKGNAMESUFFIX?=         -${LANG_SUFFIX}
.endif

.if defined(WITH_GNUGCJ)
#this wired part must be rewritten
GCCVER=4.1.1
BUILD_DEPENDS+=	${PREFIX}/lib/gcc/${MACHINE_ARCH}-portbld-freebsd${OSREL}/${GCCVER}/lib-gnu-java-awt-peer-gtk.so:${PORTSDIR}/lang/gcc41-withgcjawt
BUILD_DEPENDS+=	gjdoc:${PORTSDIR}/java/gjdoc
RUN_DEPENDS+=	${PREFIX}/lib/gcc/${MACHINE_ARCH}-portbld-freebsd${OSREL}/${GCCVER}/lib-gnu-java-awt-peer-gtk.so:${PORTSDIR}/lang/gcc41-withgcjawt
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
		bison2:${PORTSDIR}/devel/bison2 \
		imake:${X_IMAKE_PORT}
.if !defined(WITH_GNUGCJ)
BUILD_DEPENDS+=	ant:${PORTSDIR}/devel/apache-ant
.else
LIB_DEPENDS+=	xslt.2:${PORTSDIR}/textproc/libxslt
LIB_DEPENDS+=	xml2.5:${PORTSDIR}/textproc/libxml2
.endif
.if defined(WITH_GNUGCJ)
ANT_DISTFILE=   apache-ant-${ANT_VERSION}-bin.tar.bz2
ANT_VERSION=	1.6.5
.endif
.if !defined(WITH_GPC)
LIB_DEPENDS=	art_lgpl_2:${PORTSDIR}/graphics/libart_lgpl2
.endif

GNU_CONFIGURE=	yes
WRKSRC?=		${WRKDIR}/${OOOTAG}
CONFIGURE_WRKSRC=	${WRKSRC}/config_office
TCSH?=		/bin/tcsh
PKGMESSAGE=	${WRKDIR}/pkg-message
NUMOFPROCESSES?=	1
.if defined(WITH_GNUGCJ)
CONFIGURE_ENV+=      PATH="${WRKDIR}/gnugcj/bin:${PATH}"
.endif

CONFIGURE_ARGS+=	--with-gnu-cp=${LOCALBASE}/bin/gcp --with-gnu-patch=${LOCALBASE}/bin/gpatch --with-epm=internal --with-system-freetype --enable-crashdump=yes --enable-symbols=SMALL
#workarounds
CONFIGURE_ARGS+=	--with-system-xrender-headers=yes #i62713#

.if (${OSVERSION} <= 492000)
EXTRA_PATCHES+=	${FILESDIR}/fbsd4-workaroundpatch
.endif
.if defined(WITH_GNUGCJ)
EXTRA_PATCHES+=	${FILESDIR}/gcj-cws_jaxpapi ${FILESDIR}/gcj-patches ${FILESDIR}/gcj-fbsdworkaround
.endif
.if defined(WITHOUT_MOZILLA)
EXTRA_PATCHES+=	${FILESDIR}/moz-patch_i59729 #cws pj50
.endif
#.if defined(WITH_TTF_BYTECODE_ENABLED)
#EXTRA_PATCHES+=	 ${FILESDIR}/optpatch-freetype
#.endif

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
.if defined(WITH_GNUGCJ)
	@cd ${WRKDIR} ; ${CAT} ${DISTDIR}/${DIST_SUBDIR}/${ANT_DISTFILE} | ${BZIP2_CMD} -d | ${TAR} xf -
	@${RM} -Rf ${WRKDIR}/gnugcj
	@${MKDIR} ${WRKDIR}/gnugcj/bin
	@${LN} -s ${LOCALBASE}/bin/gcj41 ${WRKDIR}/gnugcj/bin/gcj
	@${LN} -s ${LOCALBASE}/bin/gij41 ${WRKDIR}/gnugcj/bin/gij
	@${LN} -s ${LOCALBASE}/bin/gjdoc ${WRKDIR}/gnugcj/bin/javadoc  # #iXXXXX# xmerge doesn't support gjdoc
	@${LN} -s ${LOCALBASE}/bin/fastjar41 ${WRKDIR}/gnugcj/bin/fastjar
	@${LN} -s ${LOCALBASE}/bin/gcj-dbtool41 ${WRKDIR}/gnugcj/bin/gcj-dbtool
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
	@cd ${WRKSRC} ;	${SETENV} "LANG=C" "LC_ALL=C" ${TCSH} -c "source FreeBSDEnv.Set ; cd instsetoo_native ; build.pl -P${NUMOFPROCESSES} --all"
.else
	@cd ${WRKSRC} ;	${SETENV} "LANG=C" "LC_ALL=C" ${TCSH} -c "source FreeBSDEnv.Set ; dmake"
.endif

do-install:
	@cd ${WRKSRC}/instsetoo_native/unxfbsd.pro/OpenOffice/bsd/install/${LOCALIZED_LANG}/freebsd-*/ ; ${LS} *.tgz > ${WRKDIR}/INSTALLFILES
	@${RM} -Rf ${WRKDIR}/tmp
	@${MKDIR} ${WRKDIR}/tmp
	@for i in `${CAT} ${WRKDIR}/INSTALLFILES`; do \
		${CP} ${WRKSRC}/instsetoo_native/unxfbsd.pro/OpenOffice/bsd/install/${LOCALIZED_LANG}/freebsd-*/$$i ${WRKDIR}/tmp ; \
		cd ${WRKDIR}/tmp ; ${TAR} xfz ${WRKDIR}/tmp/$$i ; \
	done
	@${MKDIR} ${PREFIX}/${INSTALLATION_BASEDIR}
	@cd ${WRKDIR}/tmp/opt/openoffice* ; ${TAR} cf - -C . . | ${TAR} xf - -C ${PREFIX}/${INSTALLATION_BASEDIR}

post-install:
	@${ECHO_MSG} "===>  Add wrapper scripts";
	@${CP} ${FILESDIR}/openoffice.org-wrapper ${WRKDIR}/
	@${REINPLACE_CMD} -e 's#%%PREFIX%%#${PREFIX}#g' \
			-e 's#%%RELEASE_NR%%#${RELEASE_NR}#g' \
			-e 's#%%OOOVERSION%%#${OOOVERSION}#g' \
			-e 's#%%INSTALLATION_BASEDIR%%#${INSTALLATION_BASEDIR}#g' \
			${WRKDIR}/openoffice.org-wrapper
	@${INSTALL_SCRIPT} ${WRKDIR}/openoffice.org-wrapper \
		${PREFIX}/bin/${EXECBASE}
	@${LN} -fs ${PREFIX}/bin/${EXECBASE} ${PREFIX}/bin/openoffice.org
	@${LN} -fs ${PREFIX}/bin/${EXECBASE} ${PREFIX}/bin/${EXECBASE}-sbase
	@${LN} -fs ${PREFIX}/bin/${EXECBASE} ${PREFIX}/bin/${EXECBASE}-scalc
	@${LN} -fs ${PREFIX}/bin/${EXECBASE} ${PREFIX}/bin/${EXECBASE}-sdraw
	@${LN} -fs ${PREFIX}/bin/${EXECBASE} ${PREFIX}/bin/${EXECBASE}-setofficelang
	@${LN} -fs ${PREFIX}/bin/${EXECBASE} ${PREFIX}/bin/${EXECBASE}-smath
	@${LN} -fs ${PREFIX}/bin/${EXECBASE} ${PREFIX}/bin/${EXECBASE}-simpress
	@${LN} -fs ${PREFIX}/bin/${EXECBASE} ${PREFIX}/bin/${EXECBASE}-spadmin
	@${LN} -fs ${PREFIX}/bin/${EXECBASE} ${PREFIX}/bin/${EXECBASE}-swriter
	@${PRINTF} "bin/openoffice.org\n" > ${TMPPLIST}
	@${REINPLACE_CMD} -e 's#${RELEASE_NR}#${OOOVERSION}#g' \
			-e '/^Exec/s/printeradmin/spadmin/' \
			${PREFIX}/${INSTALLATION_BASEDIR}/share/xdg/*.desktop
	@${RM} ${PREFIX}/${INSTALLATION_BASEDIR}/share/xdg/*.desktop.bak
.if defined(WITH_KDE)
	@ln -sf ${PREFIX}/${INSTALLATION_BASEDIR}/share/xdg \
			${PREFIX}/share/applnk/${EXECBASE}
	@${PRINTF} "share/applnk/${EXECBASE}\n" >> ${TMPPLIST}
.endif
	@for dir in `ls ${ICONS}/hicolor | grep -v CVS`; do \
		for app in base calc draw impress math printeradmin writer; do \
			if [ -r ${ICONS}/hicolor/$${dir}/apps/$${app}.png ]; then \
				${CP} ${ICONS}/hicolor/$${dir}/apps/$${app}.png \
				    ${PREFIX}/share/icons/hicolor/$${dir}/apps/openofficeorg-20-$${app}.png ; \
				${PRINTF} "share/icons/hicolor/$${dir}/apps/openofficeorg-20-$${app}.png\n" >> ${TMPPLIST} ; \
			fi \
		done ; \
		for file in `cd ${ICONS}/hicolor/$${dir}/mimetypes; ls *.png`; do \
			${CP} ${ICONS}/hicolor/$${dir}/mimetypes/$${file} \
			    ${PREFIX}/share/icons/hicolor/$${dir}/mimetypes/ ; \
			${PRINTF} "share/icons/hicolor/$${dir}/mimetypes/$${file}\n" >> ${TMPPLIST} ; \
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
			-e 's#%%RELEASE_NR%%#${RELEASE_NR}#g' \
			${PKGMESSAGE}
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <${FILESDIR}/Makefile.others>
.include <bsd.port.post.mk>
