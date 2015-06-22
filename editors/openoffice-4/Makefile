# Created by: Martin Blapp
# $FreeBSD$

PORTNAME=	apache-openoffice
PORTVERSION=	${AOOVERSION}
PORTREVISION=	9
CATEGORIES=	editors java
MASTER_SITES=	APACHE/openoffice/${PORTVERSION}/source \
		http://tools.openoffice.org/unowinreg_prebuild/680/:unoreg \
		LOCAL/truckman/openoffice:extsrc
.if defined(LANG_PKGNAME)
PKGNAMEPREFIX=		${LANG_PKGNAME}-
.endif
.if defined(LANG_SUFFIX)
PKGNAMESUFFIX=		-${LANG_SUFFIX}
.endif
DISTFILES=	${OOOSRC} unowinreg.dll:unoreg ${EXTSRC}:extsrc
EXTRACT_ONLY=	${OOOSRC}

MAINTAINER=	office@FreeBSD.org
#de facto maintainer is truckman@FreeBSD.org
#Frequent Patch submitters should optionally sign Apache iCLA
COMMENT=	Integrated wordprocessor/dbase/spreadsheet/drawing/chart/browser

LICENSE=	APACHE20

BUILD_DEPENDS=								\
		p5-Archive-Zip>=0:${PORTSDIR}/archivers/p5-Archive-Zip	\
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww			\
		p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser	\
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
		${JAVALIBDIR}/lucene-core-3.6.2.jar:${PORTSDIR}/textproc/lucene \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
LIB_DEPENDS=								\
		libapr-1.so:${PORTSDIR}/devel/apr1			\
		libcurl.so:${PORTSDIR}/ftp/curl				\
		libcairo.so:${PORTSDIR}/graphics/cairo			\
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
		${LOCALBASE}/share/fonts/ChromeOS/Arimo-Bold.ttf:${PORTSDIR}/x11-fonts/croscorefonts-fonts-ttf

AOOVERSION1=	4
AOOVERSION2=	1
AOOVERSION3=	1
# From solenv/inc/minor.mk SOURCEREVISION LAST_MINOR BUILD
AOOTAG=		AOO411m6\(Build:9775\)
SVNREVISION=	1617669
EXTSRC=		ApacheOpenOffice.ext_sources.${AOOVERSION1}.x.x.20140918.tar.gz

AOOVERSION=	${AOOVERSION1}.${AOOVERSION2}.${AOOVERSION3}
AOOXXX=		${AOOVERSION1}${AOOVERSION2}${AOOVERSION3}
AOOSUFFIX=	${PORTVERSION}
OOOSRC=		apache-openoffice-${AOOVERSION}-r${SVNREVISION}-src${EXTRACT_SUFX}

OOODIR=			openoffice${AOOVERSION1}
AOOUDIR=		.openoffice.org\/${AOOVERSION1}
INSTALLATION_BASEDIR?=	openoffice-${AOOSUFFIX}
EXECBASE?=		openoffice-${AOOSUFFIX}
DIST_SUBDIR=		openoffice

NO_LATEST_LINK=	yes

ONLY_FOR_ARCHS=	i386 amd64

USE_GL=		gl glu
USE_GNOME=	gtk20 libxslt libidl glib20
USE_JAVA=	yes
JAVA_BUILD=	jdk
JAVA_VENDOR=	openjdk
JAVA_VERSION=	1.6+
USE_PERL5=	build
USE_XORG=	x11 ice xaw xau xext xrender xrandr \
		xi xt xcursor xdamage xcomposite xfixes
USES=		autoreconf:autoconf bison compiler cpe desktop-file-utils \
		gmake jpeg perl5 pkgconfig python tar:bzip2
WITHOUT_CPU_CFLAGS=	true
MAKE_JOBS_SAFE=	yes
CPE_PRODUCT=	${PORTNAME:S|apache-||}
CPE_VENDOR=	apache

OPTIONS_DEFINE=		CUPS GNOME GNOMEVFS MMEDIA CCACHE
OPTIONS_DEFAULT=	CUPS GNOME GNOMEVFS MMEDIA
GNOME_DESC=		GConf + screensaver presentation control via DBUS
GNOMEVFS_DESC=		GNOME Virtual File System
MMEDIA_DESC=		Multimedia backend for impress
CCACHE_DESC=		Mimimize compile time of C/C++ programs

CUPS_CONFIGURE_ENABLE=		cups
CUPS_LIB_DEPENDS=		libcups.so:${PORTSDIR}/print/cups-client

GNOME_CONFIGURE_ENABLE=		dbus gconf lockdown
GNOME_LIB_DEPENDS=		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib
GNOME_USE=			GNOME=gconf2

GNOMEVFS_CONFIGURE_ENABLE=	gnome-vfs
GNOMEVFS_CONFIGURE_OFF=		--enable-gio
GNOMEVFS_CONFIGURE_ON=		--disable-gio
GNOMEVFS_USE=			GNOME=gnomevfs2

MMEDIA_CONFIGURE_ENABLE=	gstreamer
MMEDIA_USE=			GSTREAMER=yes

.include <bsd.port.pre.mk>

.include <${FILESDIR}/Makefile.localized>

.if ${COMPILER_TYPE} == clang
. if ${COMPILER_VERSION} < 35 && ${ARCH} == amd64
BUILD_DEPENDS+=		clang35:${PORTSDIR}/lang/clang35
CPP=			clang-cpp35
CC=			clang35
CXX=			clang++35
. endif
CPPFLAGS+=		-I${LOCALBASE}/include
.else
USE_GCC=		yes
SUBST=			"s/-fexceptions/& -fno-enforce-eh-specs/;s/-DHAVE_STL_INCLUDE_PATH//"
.endif

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

GNU_CONFIGURE=	yes
WRKSUBDIR=	${WRKDIR}/aoo-${AOOVERSION}
WRKSRC?=	${WRKSUBDIR}/main
SUB_FILES=	pkg-message
SUB_LIST=	EXECBASE=${EXECBASE} AOOTAG=${AOOTAG} AOOUDIR=${AOOUDIR}

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
			--with-system-dicts				\
			--with-epm=${LOCALBASE}/bin/epm			\
			--with-system-expat				\
			--disable-fetch-external			\
			--without-fonts					\
			--with-gnu-patch=${LOCALBASE}/bin/gpatch	\
			--with-gperf=${LOCALBASE}/bin/gperf		\
			--enable-gtk					\
			--with-system-hunspell				\
			--with-external-dict-dir=${LOCALBASE}/share/hunspell \
			--with-system-hyphen				\
			--with-external-hyph-dir=${LOCALBASE}/share/hyphen \
			--with-system-jpeg				\
			--with-junit=${LOCALBASE}/share/java/classes/junit.jar \
			--with-system-libtextcat			\
			--disable-kde					\
			--disable-kde4					\
			--with-system-libxml				\
			--with-system-libxslt				\
			--with-system-lucene				\
			--with-lucene-core-jar=${JAVALIBDIR}/lucene-core-3.6.2.jar \
			--with-lucene-analyzers-jar=${JAVALIBDIR}/lucene-analyzers-3.6.2.jar \
			--with-system-mythes				\
			--with-external-thes-dir=${LOCALBASE}/share/mythes \
			--with-system-nss				\
			--enable-opengl					\
			--with-system-openssl				\
			--with-package-format="archive"			\
			--with-system-poppler				\
			--with-system-python				\
			--with-system-redland				\
			--with-system-serf				\
			--with-system-stdlibs				\
			--enable-symbols=small				\
			--without-stlport				\
			--with-vendor="FreeBSD ports system"		\
			--enable-verbose				\
			--with-system-vigra				\
			--enable-wiki-publisher				\
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
	${REINPLACE_CMD} -e ${SUBST} ${WRKSRC}/solenv/gbuild/platform/freebsd.mk
	${REINPLACE_CMD} -e ${SUBST} ${WRKSRC}/solenv/inc/unxfbsd.mk
.endif
.if ${ARCH} == i386
	# g++49 -Os sometimes leaves inline class methods undefined
	# autodoc core dumps when built with with -Os clang 3.6 on i386
	if [ ${CXX} = g++49 -o \
	     ${COMPILER_TYPE} = clang -a ${COMPILER_VERSION} = 36 ]; then \
		${REINPLACE_CMD} -e "s/ := -Os/ := -O0/" ${WRKSRC}/solenv/gbuild/platform/freebsd.mk; \
		${REINPLACE_CMD} -e "s/=-Os /=-O0 /" ${WRKSRC}/solenv/inc/unxfbsdi.mk; \
	fi
.endif

pre-configure:
	${LN} -sf ${UNZIP_CMD} ${WRKSRC}/solenv/bin/unzip

do-build:
	cd ${WRKSUBDIR} ; ${PRINTF} "[repositories]\n" > source_config
	cd ${WRKSUBDIR} ; ${PRINTF} "main=active\n" >> source_config
	cd ${WRKSUBDIR} ; ${PRINTF} "extras=active\n" >> source_config
	cd ${WRKSRC} ; ./bootstrap
	#
	# numproc controls the number of parallel makes.
	#
	# dmproc is passed to dmake and controls parallelization at that
	# level.
	#
	# dmproc > numproc seems to give shorter build times than
	# numproc > dmproc.
	#
	# Select values for numproc and dmproc such that:
	#  * numproc*dmproc >= MAKE_JOBS_NUMBER
	#  * minimize numproc*dmproc-MAKE_JOBS_NUMBER
	#  * dmproc >= numproc
	#  * dmproc <= 2*numproc if MAKE_JOBS_NUMBER <= 3
	#
	cd ${WRKSRC} ; . ${FREEBSD_ENV_SET} ; cd instsetoo_native/util ;  \
	 export LANG=C LC_ALL=C FBSD_LDFLAGS="${LDFLAGS}" ;		  \
	 if [ ${MAKE_JOBS_NUMBER} -le 3 ] ; then			  \
	  numproc=1 ; dmproc=${MAKE_JOBS_NUMBER} ;			  \
	 else								  \
	  a=1 ;								  \
	  while [ $$(( 2 * $${a} * $${a} )) -lt ${MAKE_JOBS_NUMBER} ]; do \
	   a=$$(( $${a} + 1 )) ;					  \
	  done ;							  \
	  b=$$(( $${a} + 1 )) ;						  \
	  ad=$$(( ( ${MAKE_JOBS_NUMBER} + $${a} - 1 ) / $${a} )) ;	  \
	  ap=$$(( $${a} * $${ad} )) ;					  \
	  bd=$$(( ( ${MAKE_JOBS_NUMBER} + $${b} - 1 ) / $${b} )) ;	  \
	  bp=$$(( $${b} * $${bd} )) ;					  \
	  if [ $${ap} -le $${bp} ]; then				  \
	   numproc=$${a} ; dmproc=$${ad} ;				  \
	  else								  \
	   numproc=$${b} ; dmproc=$${bd} ;				  \
	  fi ;								  \
	 fi ;								  \
	 build.pl --all -P$${numproc} -- -P$${dmproc}

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
	${REINPLACE_CMD} -e 's/USERINSTALLATION/UserInstallation=$$SYSUSERCONFIG\/${AOOUDIR}/' ${STAGEDIR}${PREFIX}/${INSTALLATION_BASEDIR}/${OOODIR}/program/bootstraprc
	${MKDIR} ${STAGEDIR}${PREFIX}/${INSTALLATION_BASEDIR}/extensions/
	cd ${WRKSRC}/solver/${AOOXXX}/unxfbsd?.pro/bin/ ; ${INSTALL_DATA} ${OOOEXTENSIONS} ${STAGEDIR}${PREFIX}/${INSTALLATION_BASEDIR}/extensions/
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
	cd ${STAGEDIR}${PREFIX} ; ${FIND} -s bin \( -type f -or -type l \) -name "${EXECBASE}*" >> ${TMPPLIST}
	cd ${STAGEDIR}${PREFIX} ; ${FIND} -s ${INSTALLATION_BASEDIR} \( -type f -or -type l \) >> ${TMPPLIST}
	cd ${STAGEDIR}${PREFIX} ; ${FIND} ${INSTALLATION_BASEDIR} -type d -empty | ${SORT} -r | \
		${XARGS} -n 1 ${ECHO_CMD} @dir >> ${TMPPLIST}
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
