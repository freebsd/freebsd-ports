# Created by: Martin Blapp
# $FreeBSD$

PORTNAME=	apache-openoffice
PORTVERSION=	${AOOVERSION1}.${AOOVERSION2}.${SVNREVISION}
PORTREVISION=	1
PORTEPOCH=	4
CATEGORIES=	editors java
MASTER_SITES=	https://dist.apache.org/repos/dist/dev/openoffice/${AOOVERSION}-${AOORC}-r${SVNREVISION}/source/ \
		http://tools.openoffice.org/unowinreg_prebuild/680/:unoreg \
		LOCAL/truckman/openoffice:snap,extsrc
.if defined(LANG_PKGNAME)
PKGNAMEPREFIX=		${LANG_PKGNAME}-
.endif
.if defined(LANG_SUFFIX)
PKGNAMESUFFIX=		-${LANG_SUFFIX}
.endif
PKGNAMESUFFIX=		-devel
DISTFILES=	${AOOSRC}${AOODISTTAG} unowinreg.dll:unoreg ${EXTSRC}:extsrc
DIST_SUBDIR=	openoffice
EXTRACT_ONLY=	${AOOSRC}

MAINTAINER=	office@FreeBSD.org
#de facto maintainer is truckman@FreeBSD.org
#Frequent Patch submitters should optionally sign Apache iCLA
COMMENT=	Integrated wordprocessor/dbase/spreadsheet/drawing/chart/browser (developer version)

LICENSE=		APACHE20 ADOBE BSD3CLAUSE BSD4CLAUSE BSL ICU MIT MPL \
			PSFL TWAIN W3C
LICENSE_COMB=		multi
LICENSE_NAME_ADOBE=	Adobe Systems Incorporated license
LICENSE_NAME_ICU=	ICU License
LICENSE_NAME_TWAIN=	TWAIN Working Group license
LICENSE_NAME_W3C=	W3C license
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE_ALv2
LICENSE_FILE_ADOBE=	${WRKSRC}/LICENSE_ADOBE
LICENSE_FILE_BSD3CLAUSE=	${WRKSRC}/LICENSE_BSD3CLAUSE
LICENSE_FILE_BSD4CLAUSE=	${WRKSRC}/LICENSE_BSD4CLAUSE
LICENSE_FILE_BSL=	${WRKSRC}/LICENSE_BSL
LICENSE_FILE_ICU=	${WRKSRC}/LICENSE_ICU
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE_MIT
LICENSE_FILE_MPL=	${WRKSRC}/LICENSE_MPL
LICENSE_FILE_PSFL=	${WRKSRC}/LICENSE_PSFL
LICENSE_FILE_TWAIN=	${WRKSRC}/LICENSE_TWAIN
LICENSE_FILE_W3C=	${WRKSRC}/LICENSE_W3C
LICENSE_PERMS_ADOBE=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_PERMS_ICU=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_PERMS_TWAIN=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_PERMS_W3C=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=								\
		p5-Archive-Zip>=0:${PORTSDIR}/archivers/p5-Archive-Zip	\
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww			\
		p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser	\
		${LOCALBASE}/bin/unzip:${PORTSDIR}/archivers/unzip	\
		zip:${PORTSDIR}/archivers/zip				\
		ant:${PORTSDIR}/devel/apache-ant			\
		${LOCALBASE}/include/boost/shared_ptr.hpp:${PORTSDIR}/devel/boost-libs \
		dmake:${PORTSDIR}/devel/dmake				\
		epm:${PORTSDIR}/devel/epm				\
		${LOCALBASE}/bin/gperf:${PORTSDIR}/devel/gperf		\
		imake:${PORTSDIR}/devel/imake				\
		gpatch:${PORTSDIR}/devel/patch				\
		${LOCALBASE}/include/sane/sane.h:${PORTSDIR}/graphics/sane-backends \
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
		libnspr4.so:${PORTSDIR}/devel/nspr			\
		libcurl.so:${PORTSDIR}/ftp/curl				\
		libcairo.so:${PORTSDIR}/graphics/cairo			\
		libpng.so:${PORTSDIR}/graphics/png			\
		libpoppler-glib.so:${PORTSDIR}/graphics/poppler-glib	\
		libgraphite.so:${PORTSDIR}/graphics/silgraphite		\
		libCoinMP.so:${PORTSDIR}/math/coinmp			\
		libfreetype.so:${PORTSDIR}/print/freetype2		\
		libnss3.so:${PORTSDIR}/security/nss			\
		libexpat.so:${PORTSDIR}/textproc/expat2			\
		libhunspell-1.3.so:${PORTSDIR}/textproc/hunspell	\
		libhyphen.so:${PORTSDIR}/textproc/hyphen		\
		libtextcat.so:${PORTSDIR}/textproc/libtextcat		\
		libmythes-1.2.so:${PORTSDIR}/textproc/mythes		\
		librdf.so:${PORTSDIR}/textproc/redland			\
		libserf-1.so:${PORTSDIR}/www/serf			\
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS=								\
		${LOCALBASE}/share/icons/hicolor/index.theme:${PORTSDIR}/misc/hicolor-icon-theme \
		${JAVALIBDIR}/commons-httpclient.jar:${PORTSDIR}/java/jakarta-commons-httpclient \
		${JAVALIBDIR}/bsh.jar:${PORTSDIR}/lang/bsh \
		${LOCALBASE}/share/fonts/Caladea/Caladea-Bold.ttf:${PORTSDIR}/x11-fonts/crosextrafonts-caladea-ttf \
		${LOCALBASE}/share/fonts/Carlito/Carlito-Bold.ttf:${PORTSDIR}/x11-fonts/crosextrafonts-carlito-ttf \
		${LOCALBASE}/share/fonts/ChromeOS/Arimo-Bold.ttf:${PORTSDIR}/x11-fonts/croscorefonts-fonts-ttf

AOOVERSION1=	4
AOOVERSION2=	1
AOOVERSION3=	2
# From solenv/inc/minor.mk SOURCEREVISION LAST_MINOR BUILD
AOOTAG=		AOO412m2\(Build:9781\)
SVNREVISION=	1707648
AOORC=rc2
EXTSRC=		ApacheOpenOffice.ext_sources.${AOOVERSION1}.x.x.20150707.tar.gz

AOOVERSION=	${AOOVERSION1}.${AOOVERSION2}.${AOOVERSION3}
AOOXXX=		${AOOVERSION1}${AOOVERSION2}${AOOVERSION3}
.if defined(AOORC)
AOOSUFFIX=	${AOOVERSION}-${AOORC}
AOOSRC=		apache-openoffice-${AOOVERSION}-r${SVNREVISION}-src${EXTRACT_SUFX}
AOODISTTAG=
TARTYPE=	bzip2
.else
AOOSUFFIX=	${PORTVERSION}
AOOSRC=		apache-openoffice-r${SVNREVISION}-src${EXTRACT_SUFX}
AOODISTTAG=	:snap
TARTYPE=	xz
.endif

AOOUDIR=		.openoffice.org\/${AOOVERSION1}
INSTALLATION_BASEDIR?=	openoffice-${AOOSUFFIX}
PRINSTALLATION_BASEDIR=	${PREFIX}/${INSTALLATION_BASEDIR}
OOPATH=			${PRINSTALLATION_BASEDIR}/openoffice${AOOVERSION1}
XDGDIR=			${OOPATH}/share/xdg
EXECBASE?=		openoffice-${AOOSUFFIX}

ONLY_FOR_ARCHS=	i386 amd64

USE_GL=		gl glu
USE_GNOME=	gtk20 libxslt libidl glib20
USE_JAVA=	yes
JAVA_BUILD=	jdk
JAVA_VENDOR=	openjdk
JAVA_VERSION=	1.6+
USE_PERL5=	build
USE_XORG=	ice x11 xau xaw xcomposite xcursor xdamage xext xfixes xi \
		xrandr xrender xt
USES=		autoreconf:autoconf bison compiler cpe desktop-file-utils \
		gettext-runtime gmake iconv jpeg perl5 pkgconfig python \
		tar:${TARTYPE}
INSTALLS_ICONS=	yes
WITHOUT_CPU_CFLAGS=	true
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
CPPFLAGS+=		-I${LOCALBASE}/include
.else
USE_GCC=		yes
.endif

.if ${ARCH} == amd64
FREEBSD_ENV_SET=	FreeBSDAMDEnv.Set.sh
PACKAGE_MIDDLE=		${PORTVERSION}_${OPSYS}_x86-64
.else
FREEBSD_ENV_SET=	FreeBSDX86Env.Set.sh
PACKAGE_MIDDLE=		${PORTVERSION}_${OPSYS}_x86
.endif
PACKAGE_PREFIX=		Apache_OpenOffice

LOCALIZED_LANG?=	en-US

.if ${PORT_OPTIONS:MCCACHE} || defined(WITH_CCACHE)
BUILD_DEPENDS+=	ccache:${PORTSDIR}/devel/ccache
CCACHE_PREFIX=	ccache
AOOCC=		${CCACHE_PREFIX} ${CC}
AOOCXX=		${CCACHE_PREFIX} ${CXX}
.else
AOOCC=		${CC}
AOOCXX=		${CXX}
.endif

CONFIGURE_ENV+=	CC="${AOOCC}" CXX="${AOOCXX}"		\
		PATH=${WRKSRC}/solenv/bin:$$PATH

GNU_CONFIGURE=	yes
WRKSUBDIR=	${WRKDIR}/aoo-${AOOVERSION}
WRKSRC?=	${WRKSUBDIR}/main
SUB_FILES=	pkg-message
SUB_LIST=	EXECBASE=${EXECBASE} AOOTAG=${AOOTAG} AOOUDIR=${AOOUDIR} \
		PRINSTALLATION_BASEDIR=${PRINSTALLATION_BASEDIR}

CONFIGURE_ARGS+=							\
			--with-unix-wrapper=${EXECBASE}			\
			--with-system-apache-commons=yes		\
			--with-commons-codec-jar=${JAVALIBDIR}/commons-codec.jar \
			--with-commons-lang-jar=${JAVALIBDIR}/commons-lang.jar \
			--with-commons-httpclient-jar=${JAVALIBDIR}/commons-httpclient.jar \
			--with-commons-logging-jar=${JAVALIBDIR}/commons-logging.jar \
			--with-system-apr				\
			--with-system-apr-util				\
			--with-system-beanshell				\
			--with-beanshell-jar=${JAVALIBDIR}/bsh.jar	\
			--with-system-boost				\
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
			--with-system-graphite				\
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
			--with-system-sane				\
			--with-system-serf				\
			--with-system-stdlibs				\
			--without-stlport				\
			--with-vendor="FreeBSD ports system"		\
			--enable-verbose				\
			--with-system-vigra				\
			--enable-wiki-publisher				\
			--with-system-xrender				\
			--with-system-zlib

#AOOEXTENSIONS+=		minimizer/presentation-minimizer.oxt
#AOOEXTENSIONS+=		presenter/presenter-screen.oxt
#AOOEXTENSIONS+=		pdfimport/pdfimport.oxt
AOOEXTENSIONS+=		swext/wiki-publisher.oxt

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
	${CP} ${FILESDIR}/freebsd-aoo-intro-developer.png ${WRKSRC}/default_images/introabout/intro.png
	${CP} ${FILESDIR}/freebsd-aoo-about-developer.png ${WRKSRC}/default_images/introabout/about.png
	${RM} -rf ${WRKSRC}/l10n
	${LN} -sf ${UNZIP_CMD} ${WRKSRC}/solenv/bin/unzip
	${SED}  -e '\|^For main/vcl/unx/generic/fontmanager/parseAFM|,/^__/p' \
		-e '\|^For PostScript(R) AFM|,/^__/p'			\
		-e d  ${WRKSRC}/LICENSE > ${LICENSE_FILE_ADOBE}
	${SED}  -e '\|^For main/unixODBC|,/^__/p'			\
		-e '\|^For main/connectivity|,/^__/p'			\
		-e '\|^For main/libtextcat/data|,/^__/p'		\
		-e '\|^For integration of HSQLDB|,/^__/p'		\
		-e '\|^For C preprocessor|,/^__/p'			\
		-e d  ${WRKSRC}/LICENSE > ${LICENSE_FILE_BSD3CLAUSE}
	${SED}  -e '\|^For ICC |,/^__/p'				\
		-e d  ${WRKSRC}/LICENSE > ${LICENSE_FILE_BSD4CLAUSE}
	${SED}  -e '\|^For integration of the C++ Boost |,/^__/p'	\
		-e d  ${WRKSRC}/LICENSE > ${LICENSE_FILE_BSL}
	${SED}  -e '\|^For main/i18npool/source/breakiterator|,/^__/p'	\
		-e d  ${WRKSRC}/LICENSE > ${LICENSE_FILE_ICU}
	${SED}  -e '\|^For Multi-Dimensional Data|,/^__/p'	\
		-e '\|^For XSLT MathML Library|,/^__/p'			\
		-e d  ${WRKSRC}/LICENSE > ${LICENSE_FILE_MIT}
	${SED}  -e '\|^For XMLSec Library|,/^__/p'	\
		-e d  ${WRKSRC}/LICENSE_category_b >> ${LICENSE_FILE_MIT}
	${SED}  -e '\|^For Graphite|,$$d'	\
		      ${WRKSRC}/LICENSE_category_b > ${LICENSE_FILE_MPL}
	${SED}  -e '\|^For main/filter/source/config/tools/merge/pyAltFCFGMerge|,/^__/p'	\
		-e d  ${WRKSRC}/LICENSE > ${LICENSE_FILE_PSFL}
	${SED}  -e '\|^For main/twain|,/^__/p'	\
		-e d  ${WRKSRC}/LICENSE > ${LICENSE_FILE_TWAIN}
	${SED}  -e '\|^For main/MathMLDTD|,/^__/p'	\
		-e d  ${WRKSRC}/LICENSE > ${LICENSE_FILE_W3C}

post-patch:
	${REINPLACE_CMD} -e "/^ICONVERSION/s/=.*/= '-${AOOSUFFIX}'/" \
		${WRKSRC}/sysui/desktop/productversion.mk
.if ${COMPILER_TYPE} == gcc
	# g++49 -Os sometimes leaves inline class methods undefined,
	# affects fmgridif.cxx and ColumnControl.cxx
	# See: <https://gcc.gnu.org/bugzilla/show_bug.cgi?id=65009>
	if [ ${CXX} = g++49  ]; then \
		${REINPLACE_CMD} -e "s/ := -Os/ := -Os -fno-devirtualize -fno-devirtualize-speculatively/" ${WRKSRC}/solenv/gbuild/platform/freebsd.mk; \
		${REINPLACE_CMD} -e "s/=-Os /=-Os -fno-devirtualize -fno-devirtualize-speculatively /" ${WRKSRC}/solenv/inc/unxfbsdi.mk; \
	fi
.elif ${ARCH} == i386 && ${COMPILER_TYPE} == clang && ${COMPILER_VERSION} >= 36
	# autodoc and uno (bridgetest) core dump when built with with -Os
	# on i386, affects file.cxx and bridgetest.cxx (at least).
	# Using -O2 optimiztion works, and -Os is essentially -O2 with out
	# loop unrolling.
	# Changing optimization in just unxfbsdi.mk is sufficient to get
	# a successful build, but change it in both places to avoid the
	# possibility of obscure runtime problems, which is likely
	# since this seems to be a generic bug in code generation for
	# exception handling.
	# See: <https://llvm.org/bugs/show_bug.cgi?id=24792>
	${REINPLACE_CMD} -e "s/=-Os /=-O2 -fno-unroll-loops /" ${WRKSRC}/solenv/inc/unxfbsdi.mk
	${REINPLACE_CMD} -e "s/ := -Os/ := -O2 -fno-unroll-loops/" ${WRKSRC}/solenv/gbuild/platform/freebsd.mk
.endif

do-build:
	${PRINTF} "[repositories]\nmain=active\nextras=active\n" > ${WRKSUBDIR}/source_config
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
	if [ ${MAKE_JOBS_NUMBER} -le 3 ] ; then				  \
	 numproc=1 ; dmproc=${MAKE_JOBS_NUMBER} ;			  \
	else								  \
	 a=1 ;								  \
	 while [ $$(( 2 * $${a} * $${a} )) -lt ${MAKE_JOBS_NUMBER} ]; do  \
	  a=$$(( $${a} + 1 )) ;						  \
	 done ;								  \
	 b=$$(( $${a} + 1 )) ;						  \
	 ad=$$(( ( ${MAKE_JOBS_NUMBER} + $${a} - 1 ) / $${a} )) ;	  \
	 ap=$$(( $${a} * $${ad} )) ;					  \
	 bd=$$(( ( ${MAKE_JOBS_NUMBER} + $${b} - 1 ) / $${b} )) ;	  \
	 bp=$$(( $${b} * $${bd} )) ;					  \
	 if [ $${ap} -le $${bp} ]; then					  \
	  numproc=$${a} ; dmproc=$${ad} ;				  \
	 else								  \
	  numproc=$${b} ; dmproc=$${bd} ;				  \
	 fi ;								  \
	fi ;								  \
	cd ${WRKSRC}/instsetoo_native ;					  \
	. ../${FREEBSD_ENV_SET} ; 					  \
	LANG=C LC_ALL=C build.pl --all -P$${numproc} -- -P$${dmproc}

do-install:
	@${MKDIR} ${STAGEDIR}${PRINSTALLATION_BASEDIR}/extensions \
		${STAGEDIR}${OOPATH}/uno_packages/cache/uno_packages \
		${STAGEDIR}${DESKTOPDIR}
	@cd ${WRKSRC}/instsetoo_native/unxfbsd?.pro/Apache_OpenOffice/archive/install/${LOCALIZED_LANG}/ ; \
		for i in *.tar.?z ; do \
			${ECHO_CMD} "extracting $$i" ; \
			${TAR} -s '|./[^/]*/||' -xz -f $$i - \
				-C ${STAGEDIR}${PRINSTALLATION_BASEDIR} ; \
		done
	@${ECHO_CMD} "installing extensions" ; \
	cd ${WRKSRC}/solver/${AOOXXX}/unxfbsd?.pro/bin/ ; \
		${INSTALL_DATA} ${AOOEXTENSIONS} \
			${STAGEDIR}${PRINSTALLATION_BASEDIR}/extensions/
	${FIND} ${STAGEDIR}${PRINSTALLATION_BASEDIR} -type d -exec ${CHMOD} 755 {} \;
	${REINPLACE_CMD} \
		-e '/^UserInstallation/s/=.*/=$$SYSUSERCONFIG\/${AOOUDIR}/' \
		${STAGEDIR}${OOPATH}/program/bootstraprc
	@${RM} ${STAGEDIR}${OOPATH}/program/bootstraprc.bak
	@${ECHO_CMD} "adding wrapper scripts";
	@${CP} ${FILESDIR}/openoffice-wrapper ${WRKDIR}/
	@${REINPLACE_CMD} -e 's#%%OOPATH%%#${OOPATH}#g' \
			-e 's#%%EXECBASE%%#${EXECBASE}#g' \
			${WRKDIR}/openoffice-wrapper
	${INSTALL_SCRIPT} ${WRKDIR}/openoffice-wrapper \
		${STAGEDIR}${PREFIX}/bin/${EXECBASE}
	@cd ${STAGEDIR}${PREFIX}/bin; for i in printeradmin sbase scalc sdraw \
		simpress smath spadmin swriter ; do \
			${LN} -f ${EXECBASE} ${EXECBASE}-$${i} ; \
	done
	${LN} -sf ${XDGDIR} ${STAGEDIR}${DESKTOPDIR}/${EXECBASE}
	@${ECHO_CMD} "installing application icons"
	@cd ${ICONS} ; for dir in hicolor/*/apps ; do \
		${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/$${dir} ; \
		for app in base calc draw impress math printeradmin startcenter writer; do \
			icon_src=$${dir}/$${app}.png; \
			icon_dst=share/icons/$${dir}/${EXECBASE}-$${app}.png; \
			if [ -r $${icon_src} ]; then \
				${INSTALL_DATA} $${icon_src} \
				    ${STAGEDIR}${PREFIX}/$${icon_dst} ; \
			fi \
		done ; \
	done
	@${ECHO_CMD} "installing mimetype icons"
	@cd ${ICONS} ; for dir in hicolor/*/mimetypes ; do \
		dstdir=${STAGEDIR}${PREFIX}/share/icons/$${dir} ; \
		${MKDIR} $${dstdir} ; \
		${INSTALL_DATA} $${dir}/*.png $${dstdir}/ ; \
	done
	@${ECHO_CMD} "generating plist";
	@cd ${STAGEDIR}${PREFIX} ; (\
		${ECHO_CMD} "share/applications/${EXECBASE}" ; \
		${FIND} -s bin -name "${EXECBASE}*" ; \
		${FIND} -s ${INSTALLATION_BASEDIR} share/icons \! -type d ; \
		${FIND} ${INSTALLATION_BASEDIR} -type d -empty | ${SORT} -r | \
			${SED} -e 's/^/@dir /' ; \
	) >> ${TMPPLIST}

.include <${FILESDIR}/Makefile.others>

.include <bsd.port.post.mk>
