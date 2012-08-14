# New ports collection makefile for: Apache OpenOffice
# Date created:		28 February 2002
# Whom:                 Martin Blapp
#
# $FreeBSD$
#

PORTNAME=	apache-openoffice
PORTVERSION=	3.4.${SVNREVISION}
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	editors java
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	maho/openoffice
DISTFILES+=	${OOOSRC} ${EXTSRC} unowinreg.dll
EXTRACT_ONLY=	${OOOSRC} ${EXTSRC}

#de facto maintainer is maho@FreeBSD.org
#Frequent Patch submitters should optionally sign Apache iCLA
MAINTAINER=	office@FreeBSD.org
COMMENT=	Integrated wordprocessor/dbase/spreadsheet/drawing/chart/browser(developer version)

LICENSE=	AL2

NO_LATEST_LINK=	yes

USE_GNOME=	desktopfileutils gtk20 libxslt libidl glib20
USE_XORG=	x11 ice xaw xau xext xrender xrandr \
		xi xt xcursor xdamage xcomposite xfixes
USE_GL=		gl glu
USE_GSTREAMER=	yes
#USE_GCC=	4.6+
USE_GMAKE=	yes
USE_PYTHON=	yes
USE_PERL5_BUILD=	yes
USE_BZIP2=	yes
WITHOUT_CPU_CFLAGS=	true
MAKE_JOBS_SAFE=	yes

OPTIONS_DEFINE=	GCONF GNOMEVFS
OPTIONS_DEFAULT=GCONF GNOMEVFS
GNOMEVFS_DESC=	Enable GNOME Virtual File System

.include <bsd.port.pre.mk>

USE_JAVA=	yes
JAVA_BUILD=	jdk
JAVA_VENDOR=	freebsd bsdjava openjdk
JAVA_VERSION=	1.5 1.6

.if !defined(WITHOUT_GCONF)
USE_GNOME+=	gconf2
.else
CONFIGURE_ARGS+=--disable-gconf
.endif

.if !defined(WITHOUT_GNOMEVFS)
USE_GNOME+=	gnomevfs2
.else
CONFIGURE_ARGS+=--disable-gnome-vfs
.endif

.include <${FILESDIR}/Makefile.localized>

ONLY_FOR_ARCHS=	i386 amd64

.if ${ARCH} == amd64
FREEBSD_ENV_SET=	FreeBSDAMDEnv.Set.sh
.else
FREEBSD_ENV_SET=	FreeBSDX86Env.Set.sh
.endif

OOOSRC=			ApacheOpenOffice.r${SVNREVISION}${EXTRACT_SUFX}
EXTSRC=			ApacheOpenOffice.ext_sources.r${SVNREVISION}${EXTRACT_SUFX}
OOODIR=			openoffice.org3
SVNREVISION=		1371027
INSTALLATION_BASEDIR?=	openoffice-r${SVNREVISION}
EXECBASE?=		openoffice-r${SVNREVISION}
DIST_SUBDIR=		openoffice
SIMPLEOSVER=		${OSREL:C/\.//g}

PACKAGE_PREFIX=		Apache_OpenOffice_incubating
.if ${ARCH} == amd64
PACKAGE_MIDDLE=		${PORTVERSION}_${OPSYS}_x86-64
.else
PACKAGE_MIDDLE=		${PORTVERSION}_${OPSYS}_x86
.endif

LOCALIZED_LANG?=	en-US
.if defined(LANG_PKGNAME)
PKGNAMEPREFIX=		${LANG_PKGNAME}-
.endif
.if defined(LANG_SUFFIX)
PKGNAMESUFFIX=		-${LANG_SUFFIX}
.endif

RUN_DEPENDS+=	${LOCALBASE}/share/icons/hicolor/index.theme:${PORTSDIR}/misc/hicolor-icon-theme \
		${JAVALIBDIR}/commons-httpclient.jar:${PORTSDIR}/java/jakarta-commons-httpclient \
		${JAVALIBDIR}/bsh.jar:${PORTSDIR}/lang/bsh \
		${JAVALIBDIR}/saxon9.jar:${PORTSDIR}/textproc/saxon-devel \
		${LOCALBASE}/lib/X11/fonts/ChromeOS/Arimo-Bold.ttf:${PORTSDIR}/x11-fonts/croscorefonts-fonts-ttf

.if defined(WITH_CCACHE)
BUILD_DEPENDS+=	ccache:${PORTSDIR}/devel/ccache
CCACHE_PREFIX=	ccache
OOOCC=		${CCACHE_PREFIX} ${CC}
OOOCXX=		${CCACHE_PREFIX} ${CXX}
.else
OOOCC=		${CC}
OOOCXX=		${CXX}
.endif
CONFIGURE_ENV+=	CC="${OOOCC}" CXX="${OOOCXX}"		\
		PATH=${WRKSRC}/solenv/bin:$$PATH	\
		CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

LIB_DEPENDS=	cairo.2:${PORTSDIR}/graphics/cairo \
		expat.6:${PORTSDIR}/textproc/expat2 \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		curl.6:${PORTSDIR}/ftp/curl \
		hunspell-1.3.0:${PORTSDIR}/textproc/hunspell \
		poppler-glib.8:${PORTSDIR}/graphics/poppler-glib \
		rdf.0:${PORTSDIR}/textproc/redland \
		textcat.0:${PORTSDIR}/textproc/libtextcat \
		freetype.9:${PORTSDIR}/print/freetype2 \
		apr-1.4:${PORTSDIR}/devel/apr1 \
		CoinMP.7:${PORTSDIR}/math/coinmp \
		serf-1.0:${PORTSDIR}/www/serf \
		freetype.9:${PORTSDIR}/print/freetype2

.if exists(${LOCALBASE}/include/libexttextcat/textcat.h)
.if exists(${LOCALBASE}/include/textcat.h)
LIB_DEPENDS+=	exttextcat-1.0.0:${PORTSDIR}/textproc/libexttextcat
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-libexttextcat-lingucomponent
.else
IGNORE= textproc/libexttextcat needs COMPAT_TEXTCAT enabled
.endif
.else
LIB_DEPENDS+=	textcat.0:${PORTSDIR}/textproc/libtextcat
.endif

BUILD_DEPENDS+=	zip:${PORTSDIR}/archivers/zip \
		${LOCALBASE}/bin/unzip:${PORTSDIR}/archivers/unzip \
		gpatch:${PORTSDIR}/devel/patch \
		p5-Archive-Zip>=0:${PORTSDIR}/archivers/p5-Archive-Zip \
		bash:${PORTSDIR}/shells/bash \
		imake:${PORTSDIR}/devel/imake \
		${LOCALBASE}/bin/gperf:${PORTSDIR}/devel/gperf \
		ant:${PORTSDIR}/devel/apache-ant \
		${LOCALBASE}/lib/libboost_regex.a:${PORTSDIR}/devel/boost-libs \
		${LOCALBASE}/bin/vigra-config:${PORTSDIR}/graphics/vigra \
		${JAVALIBDIR}/junit.jar:${PORTSDIR}/java/junit \
		${JAVALIBDIR}/commons-httpclient.jar:${PORTSDIR}/java/jakarta-commons-httpclient \
		${JAVALIBDIR}/commons-lang.jar:${PORTSDIR}/java/jakarta-commons-lang \
		${JAVALIBDIR}/bsh.jar:${PORTSDIR}/lang/bsh \
		${JAVALIBDIR}/saxon9.jar:${PORTSDIR}/textproc/saxon-devel \
		epm:${PORTSDIR}/devel/epm \
		dmake:${PORTSDIR}/devel/dmake \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww

USE_AUTOTOOLS=	autoconf
USE_BISON=	build
GNU_CONFIGURE=	yes
WRKSRC?=	${WRKDIR}/ooo/main
BASH?=		${PREFIX}/bin/bash
SUB_FILES=	pkg-message
SUB_LIST=	EXECBASE=${EXECBASE} OOOTAG=${OOOTAG} OOODIR=${OOODIR}

.if defined(DISABLE_MAKE_JOBS)
MAKE_JOBS_NUMBER=	4
.endif

CONFIGURE_ARGS+=	--enable-verbose \
			--enable-symbols=small \
			--enable-crashdump \
			--with-vendor="FreeBSD ports system"	\
			--with-epm=${LOCALBASE}/bin/epm \
			--with-gnu-patch=${LOCALBASE}/bin/gpatch	\
			--with-gperf=${LOCALBASE}/bin/gperf	\
			--x-includes=${LOCALBASE}/include	\
			--x-libraries=${LOCALBASE}lib	\
			--with-system-libxml 		\
			--with-system-libxslt 		\
			--with-system-cairo --enable-cairo \
			--with-system-boost 		\
			--with-system-zlib		\
			--with-system-python		\
			--with-system-expat		\
			--with-system-openssl		\
			--with-system-curl		\
			--with-system-poppler \
			--with-system-redland \
			--with-system-libtextcat \
			--with-system-libtextcat-data=${LOCALBASE}/share/libtextcat \
			--with-system-vigra \
			--with-system-stdlibs \
			--with-system-apr \
			--with-system-apr-util \
			--with-system-coinmp \
			--with-commons-codec-jar=${JAVALIBDIR}/commons-codec.jar \
			--with-commons-lang-jar=${JAVALIBDIR}/commons-lang.jar	\
			--with-commons-httpclient-jar=${JAVALIBDIR}/commons-httpclient.jar \
			--with-commons-logging-jar=${JAVALIBDIR}/commons-logging.jar	\
			--with-junit=${LOCALBASE}/share/java/classes/junit.jar \
			--with-package-format="archive" \
			--enable-gstreamer \
			--enable-minimizer \
			--enable-presenter-console \
			--enable-wiki-publisher \
			--enable-dbus \
			--enable-opengl \
			--enable-category-b \
			--with-system-hunspell \
			--with-system-saxon     \
			--with-saxon-jar=${JAVALIBDIR}/saxon9.jar  \
			--with-system-beanshell	\
			--with-beanshell-jar=${JAVALIBDIR}/bsh.jar \
			--without-fonts

#			--with-system-serf \

OOOEXTENSIONS+=		minimizer/presentation-minimizer.oxt
OOOEXTENSIONS+=		presenter/presenter-screen.oxt
#OOOEXTENSIONS+=		pdfimport/pdfimport.oxt
OOOEXTENSIONS+=		swext/wiki-publisher.oxt

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
	@${MKDIR} ${WRKDIR}
	@${TOUCH} ${EXTRACT_COOKIE}
	@${TOUCH} ${PATCH_COOKIE}
	@${TOUCH} ${CONFIGURE_COOKIE}
	@${TOUCH} ${BUILD_COOKIE}
.endif

post-extract:
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/unowinreg.dll ${WRKSRC}/external/unowinreg/
#	@${MKDIR} ${WRKSRC}/../ext_sources
#	@${MV} ${WRKDIR}/ooo/ext_sources/* ${WRKSRC}/../ext_sources/
#	@${RM} -rf ${WRKSRC}/l10n

post-patch:
.if defined (USE_GCC)
	@${REINPLACE_CMD} -e "s+%%RPATH%%+-Wl,-rpath=${LOCALBASE}/lib/${_GCC_BUILD_DEPENDS}+" ${WRKSRC}/solenv/inc/unxfbsd.mk
	@${REINPLACE_CMD} -e "s+%%RPATH%%+-Wl,-rpath=${LOCALBASE}/lib/${_GCC_BUILD_DEPENDS}+" ${WRKSRC}/solenv/gbuild/platform/freebsd.mk
.else
	@${REINPLACE_CMD} -e "s+%%RPATH%%++" ${WRKSRC}/solenv/inc/unxfbsd.mk
	@${REINPLACE_CMD} -e "s+%%RPATH%%++" ${WRKSRC}/solenv/gbuild/platform/freebsd.mk
.endif

pre-configure:
	@${LN} -sf ${UNZIP_CMD} ${WRKSRC}/solenv/bin/unzip

do-build:
	@cd ${WRKDIR}/ooo ; ${PRINTF} "[repositories]\n" > source_config
	@cd ${WRKDIR}/ooo ; ${PRINTF} "main=active\n" >> source_config
	@cd ${WRKDIR}/ooo ; ${PRINTF} "extras=active\n" >> source_config
	@cd ${WRKSRC} ; ./bootstrap
	@cd ${WRKSRC} ; ${SETENV} "LANG=C" "LC_ALL=C" ${BASH} -c "source ${FREEBSD_ENV_SET} ; cd instsetoo_native/util  ; build.pl --all -P${MAKE_JOBS_NUMBER} -- -P${MAKE_JOBS_NUMBER}"

do-install:
	@cd ${WRKSRC}/instsetoo_native/unxfbsd?.pro/OpenOffice/archive/install/${LOCALIZED_LANG}/ ; ${LS} *.tar.?z > ${WRKDIR}/INSTALLFILES
	@${RM} -Rf ${WRKDIR}/tmp
	@${MKDIR} ${WRKDIR}/tmp
	@for i in `${CAT} ${WRKDIR}/INSTALLFILES`; do \
		${ECHO_CMD} "extracting $$i" ; \
		cd ${WRKDIR}/tmp ; ${TAR} xfz ${WRKSRC}/instsetoo_native/unxfbsd?.pro/OpenOffice/archive/install/${LOCALIZED_LANG}/$$i ; \
	done
	@${MKDIR} ${PREFIX}/${INSTALLATION_BASEDIR}
	@cd ${WRKDIR}/tmp/*/ ; ${TAR} cf - -C . . | ${TAR} xf - -C ${PREFIX}/${INSTALLATION_BASEDIR}
	@${REINPLACE_CMD} -e 's/^UserInstallation.*$$/USERINSTALLATION/' ${PREFIX}/${INSTALLATION_BASEDIR}/openoffice.org3/program/bootstraprc
	@${REINPLACE_CMD} -e 's/USERINSTALLATION/UserInstallation=$$SYSUSERCONFIG\/\.openoffice\.org-devel\/3/' ${PREFIX}/${INSTALLATION_BASEDIR}/openoffice.org3/program/bootstraprc
	@${MKDIR} ${PREFIX}/${INSTALLATION_BASEDIR}/extensions/
	@cd ${WRKSRC}/solver/3?0/unxfbsd?.pro/bin/ ; ${INSTALL_DATA} ${OOOEXTENSIONS} ${PREFIX}/${INSTALLATION_BASEDIR}/extensions/

post-install:
	@${FIND} ${PREFIX}/${INSTALLATION_BASEDIR} -type d -exec ${CHMOD} 755 {} \;
	@${ECHO_MSG} "===>  Add wrapper scripts";
	@${CP} ${FILESDIR}/openoffice-wrapper ${WRKDIR}/
	@${REINPLACE_CMD} -e 's#%%PREFIX%%#${PREFIX}#g' \
			-e 's#%%SVNREVISION%%#${SVNREVISION}#g' \
			-e 's#%%OOODIR%%#${OOODIR}#g' \
			-e 's#%%INSTALLATION_BASEDIR%%#${INSTALLATION_BASEDIR}#g' \
			${WRKDIR}/openoffice-wrapper
	@${INSTALL_SCRIPT} ${WRKDIR}/openoffice-wrapper \
		${PREFIX}/bin/${EXECBASE}
	@${LN} -fs ${PREFIX}/bin/${EXECBASE} ${PREFIX}/bin/${EXECBASE}-sbase
	@${LN} -fs ${PREFIX}/bin/${EXECBASE} ${PREFIX}/bin/${EXECBASE}-scalc
	@${LN} -fs ${PREFIX}/bin/${EXECBASE} ${PREFIX}/bin/${EXECBASE}-sdraw
	@${LN} -fs ${PREFIX}/bin/${EXECBASE} ${PREFIX}/bin/${EXECBASE}-setofficelang
	@${LN} -fs ${PREFIX}/bin/${EXECBASE} ${PREFIX}/bin/${EXECBASE}-simpress
	@${LN} -fs ${PREFIX}/bin/${EXECBASE} ${PREFIX}/bin/${EXECBASE}-smath
	@${LN} -fs ${PREFIX}/bin/${EXECBASE} ${PREFIX}/bin/${EXECBASE}-spadmin
	@${LN} -fs ${PREFIX}/bin/${EXECBASE} ${PREFIX}/bin/${EXECBASE}-swriter
	@${ECHO_CMD} "" > ${TMPPLIST}
	@${ECHO_CMD} "share/licenses/${PKGNAME}/catalog.mk" >> ${TMPPLIST}
	@${ECHO_CMD} "share/licenses/${PKGNAME}/LICENSE"    >> ${TMPPLIST}
	@${ECHO_CMD} "share/licenses/${PKGNAME}/AL2"        >> ${TMPPLIST}
	@${ECHO_CMD} "@dirrm share/licenses/${PKGNAME}"     >> ${TMPPLIST}
	@${ECHO_CMD} "@dirrm share/licenses"                >> ${TMPPLIST}
	@cd ${PREFIX} ; ${FIND} -s bin \( -type f -or -type l \) -name "${EXECBASE}*" >> ${TMPPLIST}
	@cd ${PREFIX} ; ${FIND} -s ${INSTALLATION_BASEDIR} \( -type f -or -type l \) >> ${TMPPLIST}
	@cd ${PREFIX} ; ${FIND} ${INSTALLATION_BASEDIR} -type d | ${SORT} -r | \
		${XARGS} -n 1 ${ECHO_CMD} @dirrm >> ${TMPPLIST}
	@for app in base calc draw impress math writer; do \
		${REINPLACE_CMD} -e "s/^Exec.*/Exec=${EXECBASE} -$${app} %U/" \
			-e "s/^Icon.*/Icon=${EXECBASE}-$${app}.png/" \
		${PREFIX}/${INSTALLATION_BASEDIR}/${OOODIR}/share/xdg/$${app}.desktop ; \
	done
	@${REINPLACE_CMD} -e "s/^Exec.*/Exec=${EXECBASE}-spadmin %U/" \
		-e "s/^Icon.*/Icon=${EXECBASE}-printeradmin.png/" \
		${PREFIX}/${INSTALLATION_BASEDIR}/${OOODIR}/share/xdg/printeradmin.desktop
	@${REINPLACE_CMD} -e "s/^Exec.*/Exec=${EXECBASE} -quickstart -nologo -nodefault/" \
		${PREFIX}/${INSTALLATION_BASEDIR}/${OOODIR}/share/xdg/startcenter.desktop
	@${RM} ${PREFIX}/${INSTALLATION_BASEDIR}/${OOODIR}/share/xdg/*.desktop.bak
	@${RM} -f ${DESKTOPDIR}/${EXECBASE}
	@${MKDIR} ${DESKTOPDIR}
	@${LN} -sf ${PREFIX}/${INSTALLATION_BASEDIR}/${OOODIR}/share/xdg \
			${DESKTOPDIR}/${EXECBASE}
	@${ECHO_CMD} "share/applications/${EXECBASE}" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ${RMDIR} %D/share/applications 2>/dev/null || ${TRUE}" >> ${TMPPLIST}
	@${PREFIX}/bin/update-desktop-database 2>/dev/null || ${TRUE}
	@${ECHO_CMD} "@exec ${PREFIX}/bin/update-desktop-database 2>/dev/null || ${TRUE}" >> ${TMPPLIST}
	@for dir in `ls ${ICONS}/hicolor | ${GREP} -v CVS`; do \
		for app in base calc draw impress math printeradmin writer; do \
			if [ -r ${ICONS}/hicolor/$${dir}/apps/$${app}.png ]; then \
				${INSTALL_DATA} ${ICONS}/hicolor/$${dir}/apps/$${app}.png \
				    ${PREFIX}/share/icons/hicolor/$${dir}/apps/${EXECBASE}-$${app}.png ; \
				${ECHO_CMD} "share/icons/hicolor/$${dir}/apps/${EXECBASE}-$${app}.png" >> ${TMPPLIST} ; \
			fi \
		done ; \
		for iconfile in `cd ${ICONS}/hicolor/$${dir}/mimetypes; ls *.png`; do \
			${INSTALL_DATA} ${ICONS}/hicolor/$${dir}/mimetypes/$${iconfile} \
			    ${PREFIX}/share/icons/hicolor/$${dir}/mimetypes/ ; \
			${ECHO_CMD} "share/icons/hicolor/$${dir}/mimetypes/$${iconfile}" >> ${TMPPLIST} ; \
		done ; \
	done
	@${PREFIX}/bin/gtk-update-icon-cache -q -f ${PREFIX}/share/icons/hicolor 2>/dev/null || ${TRUE}
	@${ECHO_CMD} "@unexec ${RM} %D/share/icons/hicolor/icon-theme.cache 2>/dev/null || ${TRUE}" >> ${TMPPLIST}
	@${ECHO_CMD} "@exec ${PREFIX}/bin/gtk-update-icon-cache -q -f %D/share/icons/hicolor 2>/dev/null || ${TRUE}" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ${PREFIX}/bin/gtk-update-icon-cache -q -f %D/share/icons/hicolor 2>/dev/null || ${TRUE}" >> ${TMPPLIST}
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <${FILESDIR}/Makefile.others>
.include <bsd.port.post.mk>
