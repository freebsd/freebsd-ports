# Created by: Martin Blapp
# $FreeBSD$

PORTNAME=	apache-openoffice
PORTVERSION=	${AOOVERSION}
CATEGORIES=	editors java
MASTER_SITES=	${MASTER_SITE_APACHE:S@%SUBDIR%@openoffice/${PORTVERSION}/source@} \
		${MASTER_SITE_LOCAL:S@%SUBDIR%@truckman/openoffice@}:extsrc
.if defined(LANG_PKGNAME)
PKGNAMEPREFIX=		${LANG_PKGNAME}-
.endif
.if defined(LANG_SUFFIX)
PKGNAMESUFFIX=		-${LANG_SUFFIX}
.endif
DISTFILES=	${OOOSRC} unowinreg.dll ${EXTSRC}:extsrc
EXTRACT_ONLY=	${OOOSRC}

MAINTAINER=	office@FreeBSD.org
#de facto maintainer is maho@FreeBSD.org
#Frequent Patch submitters should optionally sign Apache iCLA
COMMENT=	Integrated wordprocessor/dbase/spreadsheet/drawing/chart/browser

LICENSE=	APACHE20

BUILD_DEPENDS=								\
		p5-Archive-Zip>=0:${PORTSDIR}/archivers/p5-Archive-Zip	\
		${LOCALBASE}/bin/unzip:${PORTSDIR}/archivers/unzip	\
		zip:${PORTSDIR}/archivers/zip				\
		ant:${PORTSDIR}/devel/apache-ant			\
		dmake:${PORTSDIR}/devel/dmake				\
		epm:${PORTSDIR}/devel/epm				\
		${LOCALBASE}/bin/gperf:${PORTSDIR}/devel/gperf		\
		imake:${PORTSDIR}/devel/imake				\
		gpatch:${PORTSDIR}/devel/patch				\
		${LOCALBASE}/bin/vigra-config:${PORTSDIR}/graphics/vigra \
		${JAVALIBDIR}/commons-httpclient.jar:${PORTSDIR}/java/jakarta-commons-httpclient \
		${JAVALIBDIR}/commons-lang.jar:${PORTSDIR}/java/jakarta-commons-lang \
		${JAVALIBDIR}/junit.jar:${PORTSDIR}/java/junit		\
		${JAVALIBDIR}/bsh.jar:${PORTSDIR}/lang/bsh		\
		bash:${PORTSDIR}/shells/bash				\
		${JAVALIBDIR}/saxon9.jar:${PORTSDIR}/textproc/saxon-devel \
		${JAVALIBDIR}/lucene-core-3.6.2.jar:${PORTSDIR}/textproc/lucene \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
LIB_DEPENDS=								\
		libapr-1.so:${PORTSDIR}/devel/apr1			\
		libcurl.so:${PORTSDIR}/ftp/curl				\
		libcairo.so:${PORTSDIR}/graphics/cairo			\
		libjpeg.so:${PORTSDIR}/graphics/jpeg			\
		libpng.so:${PORTSDIR}/graphics/png			\
		libpoppler-glib.so:${PORTSDIR}/graphics/poppler-glib	\
		libCoinMP.so:${PORTSDIR}/math/coinmp			\
		libfreetype.so:${PORTSDIR}/print/freetype2		\
		libnss3.so:${PORTSDIR}/security/nss			\
		libexpat.so:${PORTSDIR}/textproc/expat2			\
		libhunspell-1.3.so:${PORTSDIR}/textproc/hunspell	\
		libhyphen.so:${PORTSDIR}/textproc/hyphen		\
		libtextcat.so:${PORTSDIR}/textproc/libtextcat		\
		libmythes-1.2.so:${PORTSDIR}/textproc/mythes		\
		librdf.so:${PORTSDIR}/textproc/redland			\
		libserf-1.so:${PORTSDIR}/www/serf
#		libgraphite.so:${PORTSDIR}/graphics/silgraphite
RUN_DEPENDS=								\
		${LOCALBASE}/share/icons/hicolor/index.theme:${PORTSDIR}/misc/hicolor-icon-theme \
		${JAVALIBDIR}/commons-httpclient.jar:${PORTSDIR}/java/jakarta-commons-httpclient \
		${JAVALIBDIR}/bsh.jar:${PORTSDIR}/lang/bsh \
		${JAVALIBDIR}/saxon9.jar:${PORTSDIR}/textproc/saxon-devel \
		${LOCALBASE}/lib/X11/fonts/ChromeOS/Arimo-Bold.ttf:${PORTSDIR}/x11-fonts/croscorefonts-fonts-ttf

AOOVERSION1=		4
AOOVERSION2=		1
AOOVERSION3=		1
AOOVERSION=		${AOOVERSION1}.${AOOVERSION2}.${AOOVERSION3}
AOOXXX=			${AOOVERSION1}${AOOVERSION2}${AOOVERSION3}
SVNREVISION=		1617669
OOOSRC=			apache-openoffice-${AOOVERSION}-r${SVNREVISION}-src${EXTRACT_SUFX}
EXTSRC=			ApacheOpenOffice.ext_sources.${AOOVERSION1}.x.x.20140809.tar.gz

OOODIR=			openoffice${AOOVERSION1}
AOOSUFFIX=		${PORTVERSION}
INSTALLATION_BASEDIR?=	openoffice-${AOOSUFFIX}
EXECBASE?=		openoffice-${AOOSUFFIX}
DIST_SUBDIR=		openoffice

NO_LATEST_LINK=	yes

ONLY_FOR_ARCHS=	i386 amd64

USE_GNOME=	gtk20 libxslt libidl glib20
USE_XORG=	x11 ice xaw xau xext xrender xrandr \
		xi xt xcursor xdamage xcomposite xfixes
USE_GL=		gl glu
USE_GSTREAMER=	yes
USE_GCC=	yes
USES+=		bison desktop-file-utils gmake perl5 pkgconfig python tar:bzip2
USE_PERL5=	build
WITHOUT_CPU_CFLAGS=	true
MAKE_JOBS_SAFE=	yes

OPTIONS_DEFINE=	GCONF GNOMEVFS CCACHE
OPTIONS_DEFAULT=GCONF GNOMEVFS
GNOMEVFS_DESC=	Enable GNOME Virtual File System
CCACHE_DESC=	Mimimize compile time of C/C++ programs

GCONF_USE=	GNOME=gconf2
GCONF_CONFIGURE_OFF=--disable-gconf

GNOMEVFS_USE=	GNOME=gnomevfs2
GNOMEVFS_CONFIGURE_OFF=--disable-gnome-vfs

.include <bsd.port.options.mk>

.include <bsd.port.pre.mk>

.include <${FILESDIR}/Makefile.localized>

USE_JAVA=	yes
JAVA_BUILD=	jdk
JAVA_VENDOR=	openjdk
JAVA_VERSION=	1.6+

.if ${ARCH} == amd64
FREEBSD_ENV_SET=	FreeBSDAMDEnv.Set.sh
.else
FREEBSD_ENV_SET=	FreeBSDX86Env.Set.sh
.endif

LOCALIZED_LANG?=	en-US

PACKAGE_PREFIX=		Apache_OpenOffice

.if ${ARCH} == amd64
PACKAGE_MIDDLE=		${PORTVERSION}_${OPSYS}_x86-64
.else
PACKAGE_MIDDLE=		${PORTVERSION}_${OPSYS}_x86
.endif

.if ${PORT_OPTIONS:MCCACHE} || defined(WITH_CCACHE)
BUILD_DEPENDS+=	ccache:${PORTSDIR}/devel/ccache
CCACHE_PREFIX=	ccache
OOOCC=		${CCACHE_PREFIX} ${CC}
OOOCXX=		${CCACHE_PREFIX} ${CXX}
.else
OOOCC=		${CC}
OOOCXX=		${CXX}
.endif
CONFIGURE_ENV+=	CC="${OOOCC}" CXX="${OOOCXX}"		\
		PATH=${WRKSRC}/solenv/bin:$$PATH

USE_AUTOTOOLS=	autoconf
GNU_CONFIGURE=	yes
WRKSUBDIR=	${WRKDIR}/aoo-${AOOVERSION}
WRKSRC?=	${WRKSUBDIR}/main
BASH?=		${PREFIX}/bin/bash
SUB_FILES=	pkg-message
SUB_LIST=	EXECBASE=${EXECBASE} OOOTAG=${OOOTAG} OOODIR=${OOODIR}

.if defined(DISABLE_MAKE_JOBS)
MAKE_JOBS_NUMBER=	4
.endif

CONFIGURE_ARGS+=							\
			--with-system-apache-commons=yes		\
			--with-commons-codec-jar=${JAVALIBDIR}/commons-codec.jar \
			--with-commons-lang-jar=${JAVALIBDIR}/commons-lang.jar \
			--with-commons-httpclient-jar=${JAVALIBDIR}/commons-httpclient.jar \
			--with-commons-logging-jar=${JAVALIBDIR}/commons-logging.jar \
			--with-system-apr				\
			--with-system-apr-util				\
			--with-system-beanshell				\
			--with-beanshell-jar=${JAVALIBDIR}/bsh.jar	\
			--enable-category-b				\
			--with-system-cairo --enable-cairo		\
			--with-system-coinmp				\
			--with-system-curl				\
			--enable-crashdump				\
			--enable-dbus					\
			--with-epm=${LOCALBASE}/bin/epm			\
			--with-system-expat				\
			--disable-fetch-external			\
			--without-fonts					\
			--with-gnu-patch=${LOCALBASE}/bin/gpatch	\
			--with-gperf=${LOCALBASE}/bin/gperf		\
			--enable-gstreamer				\
			--with-system-hunspell				\
			--with-system-hyphen				\
			--with-system-jpeg				\
			--with-junit=${LOCALBASE}/share/java/classes/junit.jar \
			--with-system-libtextcat			\
			--with-system-libxml				\
			--with-system-libxslt				\
			--enable-lockdown				\
			--with-system-lucene				\
			--with-lucene-core-jar=${JAVALIBDIR}/lucene-core-3.6.2.jar \
			--with-lucene-analyzers-jar=${JAVALIBDIR}/lucene-analyzers-3.6.2.jar \
			--with-system-mythes				\
			--with-system-nss				\
			--enable-opengl					\
			--with-system-openssl				\
			--with-package-format="archive"			\
			--with-system-poppler				\
			--with-system-python				\
			--with-system-redland				\
			--with-system-saxon				\
			--with-saxon-jar=${JAVALIBDIR}/saxon9.jar	\
			--with-system-serf				\
			--with-system-stdlibs				\
			--enable-symbols=small				\
			--without-stlport				\
			--with-vendor="FreeBSD ports system"		\
			--enable-verbose				\
			--with-system-vigra				\
			--enable-wiki-publisher				\
			--x-includes={LOCALBASE}/include		\
			--x-libraries=${LOCALBASE}lib			\
			--with-system-zlib
# system-graphite causes breakage when compiled with clang and linked
# with libc++ because aoo is compiled with gcc and linked with libstdc++.
#			--with-system-graphite

#OOOEXTENSIONS+=		minimizer/presentation-minimizer.oxt
#OOOEXTENSIONS+=		presenter/presenter-screen.oxt
#OOOEXTENSIONS+=		pdfimport/pdfimport.oxt
OOOEXTENSIONS+=		swext/wiki-publisher.oxt

ICONS=	${WRKSRC}/sysui/desktop/icons

.include <${FILESDIR}/Makefile.knobs>

pre-everything::
# really tweak, extremely useful when you build all localized language versions
# needed after when you build with ALL_LOCALIZED_LANGS.
.if defined(TWEAK_L10N)
	${RM} -f ${WRKDIR}/.PLIST*
	${RM} -f ${WRKDIR}/.install_done.*
	${RM} -f ${WRKDIR}/.package_done.*
	${RM} -f ${WRKDIR}/.extract_done.*
	${RM} -f ${WRKDIR}/.patch_done.*
	${RM} -f ${WRKDIR}/.configure_done.*
	${RM} -f ${WRKDIR}/.build_done.*
	${MKDIR} ${WRKDIR}
	${TOUCH} ${EXTRACT_COOKIE}
	${TOUCH} ${PATCH_COOKIE}
	${TOUCH} ${CONFIGURE_COOKIE}
	${TOUCH} ${BUILD_COOKIE}
.endif

post-extract:
	${TAR} -C ${WRKSUBDIR} -xzf ${DISTDIR}/${DIST_SUBDIR}/${EXTSRC}
	${CP} ${DISTDIR}/${DIST_SUBDIR}/unowinreg.dll ${WRKSRC}/external/unowinreg/
	${RM} -rf ${WRKSRC}/l10n

post-patch:
.if defined (USE_GCC)
	${REINPLACE_CMD} -e "s+%%RPATH%%+-Wl,-rpath=${_GCC_RUNTIME}+" ${WRKSRC}/solenv/inc/unxfbsd.mk
	${REINPLACE_CMD} -e "s+%%RPATH%%+-Wl,-rpath=${_GCC_RUNTIME}+" ${WRKSRC}/solenv/gbuild/platform/freebsd.mk
.else
	${REINPLACE_CMD} -e "s+%%RPATH%%++" ${WRKSRC}/solenv/inc/unxfbsd.mk
	${REINPLACE_CMD} -e "s+%%RPATH%%++" ${WRKSRC}/solenv/gbuild/platform/freebsd.mk
.endif

pre-configure:
	${LN} -sf ${UNZIP_CMD} ${WRKSRC}/solenv/bin/unzip

do-build:
	cd ${WRKSUBDIR} ; ${PRINTF} "[repositories]\n" > source_config
	cd ${WRKSUBDIR} ; ${PRINTF} "main=active\n" >> source_config
	cd ${WRKSUBDIR} ; ${PRINTF} "extras=active\n" >> source_config
	cd ${WRKSRC} ; ./bootstrap
	cd ${WRKSRC} ; ${SETENV} "LANG=C" "LC_ALL=C" ${BASH} -c "source ${FREEBSD_ENV_SET} ; cd instsetoo_native/util  ; build.pl --all -P${MAKE_JOBS_NUMBER} -- -P${MAKE_JOBS_NUMBER}"

do-install:
	cd ${WRKSRC}/instsetoo_native/unxfbsd?.pro/Apache_OpenOffice/archive/install/${LOCALIZED_LANG}/ ; ${LS} *.tar.?z > ${WRKDIR}/INSTALLFILES
	${RM} -Rf ${WRKDIR}/tmp
	${MKDIR} ${WRKDIR}/tmp
	@for i in `${CAT} ${WRKDIR}/INSTALLFILES`; do \
		${ECHO_CMD} "extracting $$i" ; \
		cd ${WRKDIR}/tmp ; ${TAR} xfz ${WRKSRC}/instsetoo_native/unxfbsd?.pro/Apache_OpenOffice/archive/install/${LOCALIZED_LANG}/$$i ; \
	done
	${MKDIR} ${STAGEDIR}${PREFIX}/${INSTALLATION_BASEDIR}
	cd ${WRKDIR}/tmp/*/ ; ${TAR} cf - -C . . | ${TAR} xf - -C ${STAGEDIR}${PREFIX}/${INSTALLATION_BASEDIR}
	${REINPLACE_CMD} -e 's/^UserInstallation.*$$/USERINSTALLATION/' ${STAGEDIR}${PREFIX}/${INSTALLATION_BASEDIR}/${OOODIR}/program/bootstraprc
	${REINPLACE_CMD} -e 's/USERINSTALLATION/UserInstallation=$$SYSUSERCONFIG\/\.openoffice\.org-devel\/${AOOVERSION1}/' ${STAGEDIR}${PREFIX}/${INSTALLATION_BASEDIR}/${OOODIR}/program/bootstraprc
	${MKDIR} ${STAGEDIR}${PREFIX}/${INSTALLATION_BASEDIR}/extensions/
	cd ${WRKSRC}/solver/${AOOXXX}/unxfbsd?.pro/bin/ ; ${INSTALL_DATA} ${OOOEXTENSIONS} ${STAGEDIR}${PREFIX}/${INSTALLATION_BASEDIR}/extensions/

post-install:
	${FIND} ${STAGEDIR}${PREFIX}/${INSTALLATION_BASEDIR}/${OOODIR}/program -type f \( -name '*.so*' -or -name '*.bin' \) -print0 | ${XARGS} -0 -n1 ${STRIP_CMD}
	for prog in crashrep pagein uri-encode javaldx regmerge regview; do \
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/${INSTALLATION_BASEDIR}/${OOODIR}/program/$${prog}; \
	done
	${FIND} ${STAGEDIR}${PREFIX}/${INSTALLATION_BASEDIR} -type d -exec ${CHMOD} 755 {} \;
	@${ECHO_MSG} "===>  Add wrapper scripts";
	${CP} ${FILESDIR}/openoffice-wrapper ${WRKDIR}/
	${REINPLACE_CMD} -e 's#%%PREFIX%%#${PREFIX}#g' \
			-e 's#%%SVNREVISION%%#${SVNREVISION}#g' \
			-e 's#%%OOODIR%%#${OOODIR}#g' \
			-e 's#%%INSTALLATION_BASEDIR%%#${INSTALLATION_BASEDIR}#g' \
			${WRKDIR}/openoffice-wrapper
	${INSTALL_SCRIPT} ${WRKDIR}/openoffice-wrapper \
		${STAGEDIR}${PREFIX}/bin/${EXECBASE}
	${LN} -fs ${EXECBASE} ${STAGEDIR}${PREFIX}/bin/${EXECBASE}-sbase
	${LN} -fs ${EXECBASE} ${STAGEDIR}${PREFIX}/bin/${EXECBASE}-scalc
	${LN} -fs ${EXECBASE} ${STAGEDIR}${PREFIX}/bin/${EXECBASE}-sdraw
	${LN} -fs ${EXECBASE} ${STAGEDIR}${PREFIX}/bin/${EXECBASE}-setofficelang
	${LN} -fs ${EXECBASE} ${STAGEDIR}${PREFIX}/bin/${EXECBASE}-simpress
	${LN} -fs ${EXECBASE} ${STAGEDIR}${PREFIX}/bin/${EXECBASE}-smath
	${LN} -fs ${EXECBASE} ${STAGEDIR}${PREFIX}/bin/${EXECBASE}-spadmin
	${LN} -fs ${EXECBASE} ${STAGEDIR}${PREFIX}/bin/${EXECBASE}-swriter
	${ECHO_CMD} "" > ${TMPPLIST}
	${ECHO_CMD} "share/licenses/${PKGNAME}/catalog.mk" >> ${TMPPLIST}
	${ECHO_CMD} "share/licenses/${PKGNAME}/LICENSE"    >> ${TMPPLIST}
	${ECHO_CMD} "share/licenses/${PKGNAME}/APACHE20"   >> ${TMPPLIST}
	cd ${STAGEDIR}${PREFIX} ; ${FIND} -s bin \( -type f -or -type l \) -name "${EXECBASE}*" >> ${TMPPLIST}
	cd ${STAGEDIR}${PREFIX} ; ${FIND} -s ${INSTALLATION_BASEDIR} \( -type f -or -type l \) >> ${TMPPLIST}
	cd ${STAGEDIR}${PREFIX} ; ${FIND} ${INSTALLATION_BASEDIR} -type d | ${SORT} -r | \
		${XARGS} -n 1 ${ECHO_CMD} @dirrm >> ${TMPPLIST}
	for app in base calc draw impress math writer; do \
		${REINPLACE_CMD} -e "s/^Exec.*/Exec=${EXECBASE} -$${app} %U/" \
			-e "s/^Icon.*/Icon=${EXECBASE}-$${app}.png/" \
		${STAGEDIR}${PREFIX}/${INSTALLATION_BASEDIR}/${OOODIR}/share/xdg/$${app}.desktop ; \
	done
	${REINPLACE_CMD} -e "s/^Exec.*/Exec=${EXECBASE}-spadmin %U/" \
		-e "s/^Icon.*/Icon=${EXECBASE}-printeradmin.png/" \
		${STAGEDIR}${PREFIX}/${INSTALLATION_BASEDIR}/${OOODIR}/share/xdg/printeradmin.desktop
	${REINPLACE_CMD} -e "s/^Exec.*/Exec=${EXECBASE} -quickstart -nologo -nodefault/" \
		${STAGEDIR}${PREFIX}/${INSTALLATION_BASEDIR}/${OOODIR}/share/xdg/startcenter.desktop
	${RM} ${STAGEDIR}${PREFIX}/${INSTALLATION_BASEDIR}/${OOODIR}/share/xdg/*.desktop.bak
	${RM} -f ${STAGEDIR}${DESKTOPDIR}/${EXECBASE}
	${MKDIR} ${STAGEDIR}${DESKTOPDIR}
	${LN} -sf ${PREFIX}/${INSTALLATION_BASEDIR}/${OOODIR}/share/xdg \
			${STAGEDIR}${DESKTOPDIR}/${EXECBASE}
	${ECHO_CMD} "share/applications/${EXECBASE}" >> ${TMPPLIST}
	for dir in `ls ${ICONS}/hicolor | ${GREP} -v CVS`; do \
		for app in base calc draw impress math printeradmin writer; do \
			if [ -r ${ICONS}/hicolor/$${dir}/apps/$${app}.png ]; then \
				${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/$${dir}/apps/ ; \
				${INSTALL_DATA} ${ICONS}/hicolor/$${dir}/apps/$${app}.png \
				    ${STAGEDIR}${PREFIX}/share/icons/hicolor/$${dir}/apps/${EXECBASE}-$${app}.png ; \
				${ECHO_CMD} "share/icons/hicolor/$${dir}/apps/${EXECBASE}-$${app}.png" >> ${TMPPLIST} ; \
			fi \
		done ; \
		for iconfile in `cd ${ICONS}/hicolor/$${dir}/mimetypes; ls *.png`; do \
			${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/$${dir}/mimetypes/ ; \
			${INSTALL_DATA} ${ICONS}/hicolor/$${dir}/mimetypes/$${iconfile} \
			    ${STAGEDIR}${PREFIX}/share/icons/hicolor/$${dir}/mimetypes/ ; \
			${ECHO_CMD} "share/icons/hicolor/$${dir}/mimetypes/$${iconfile}" >> ${TMPPLIST} ; \
		done ; \
	done
	${ECHO_CMD} "@unexec ${RM} %D/share/icons/hicolor/icon-theme.cache 2>/dev/null || ${TRUE}" >> ${TMPPLIST}
	${ECHO_CMD} "@exec ${PREFIX}/bin/gtk-update-icon-cache -q -f %D/share/icons/hicolor 2>/dev/null || ${TRUE}" >> ${TMPPLIST}
	${ECHO_CMD} "@unexec ${PREFIX}/bin/gtk-update-icon-cache -q -f %D/share/icons/hicolor 2>/dev/null || ${TRUE}" >> ${TMPPLIST}

.include <${FILESDIR}/Makefile.others>

.include <bsd.port.post.mk>
