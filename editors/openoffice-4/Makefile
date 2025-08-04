PORTNAME=	apache-openoffice
PORTVERSION=	${AOOVERSION}
PORTREVISION=	6
CATEGORIES=	editors java
MASTER_SITES=	https://dlcdn.apache.org/openoffice/${PORTVERSION}/source/ \
		https://archive.apache.org/dist/openoffice/${PORTVERSION}/source/ \
		http://tools.openoffice.org/unowinreg_prebuild/680/:unoreg \
		LOCAL/truckman/openoffice:extsrc \
		SF/oooextras.mirror/:sf
.if defined(LANG_PKGNAME)
PKGNAMEPREFIX=		${LANG_PKGNAME}-
.endif
.if defined(LANG_SUFFIX)
PKGNAMESUFFIX=		-${LANG_SUFFIX}
.endif
DISTFILES=	${AOOSRC} ${EXTSRC}:extsrc ${PYTHON_DISTFILE}:sf \
		${GCC_EXTRA_DISTFILES:C/.*/&:sf/g}
DIST_SUBDIR=	openoffice
EXTRACT_ONLY=	${AOOSRC}

MAINTAINER=	office@FreeBSD.org
#de facto maintainer is truckman@FreeBSD.org
#Frequent Patch submitters should (optionally) sign the Apache iCLA
COMMENT=	Integrated wordprocessor/dbase/spreadsheet/drawing/chart/browser
WWW=		https://openoffice.apache.org/

LICENSE=		APACHE20 ADOBE BSD3CLAUSE BSD4CLAUSE BSL ICU MIT MPL10 \
			MPL11 PSFL TWAIN W3C
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
LICENSE_FILE_MPL10=	${WRKSRC}/LICENSE_MPL10
LICENSE_FILE_MPL11=	${WRKSRC}/LICENSE_MPL11
LICENSE_FILE_PSFL=	${WRKSRC}/LICENSE_PSFL
LICENSE_FILE_TWAIN=	${WRKSRC}/LICENSE_TWAIN
LICENSE_FILE_W3C=	${WRKSRC}/LICENSE_W3C
LICENSE_PERMS_ADOBE=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_PERMS_ICU=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_PERMS_TWAIN=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_PERMS_W3C=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

ONLY_FOR_ARCHS=	amd64 i386 powerpc64

BUILD_DEPENDS=								\
		p5-Archive-Zip>=0:archivers/p5-Archive-Zip		\
		${LOCALBASE}/bin/unzip:archivers/unzip			\
		zip:archivers/zip					\
		ant:devel/apache-ant					\
		dmake:devel/dmake					\
		${LOCALBASE}/bin/gperf:devel/gperf			\
		imake:devel/imake					\
		libunwind>=20211201_1:devel/libunwind			\
		gpatch:devel/patch					\
		${LOCALBASE}/include/sane/sane.h:graphics/sane-backends	\
		${JAVALIBDIR}/commons-lang.jar:java/apache-commons-lang \
		${JAVALIBDIR}/junit.jar:java/junit			\
		${JAVALIBDIR}/bsh.jar:lang/bsh				\
		bash:shells/bash					\
		${JAVALIBDIR}/lucene-core-3.6.2.jar:textproc/lucene	\
		p5-XML-Parser>=0:textproc/p5-XML-Parser			\
		p5-libwww>=0:www/p5-libwww				\
		p5-LWP-Protocol-https>0:www/p5-LWP-Protocol-https
LIB_DEPENDS=								\
		libapr-1.so:devel/apr1					\
		libnspr4.so:devel/nspr					\
		libcurl.so:ftp/curl					\
		libcairo.so:graphics/cairo				\
		libpng16.so:graphics/png				\
		libgraphite.so:graphics/silgraphite			\
		libblas.so:math/blas					\
		libCbcSolver.so:math/cbc				\
		libCgl.so:math/cgl					\
		libcoinasl.so:math/asl					\
		libClpSolver.so:math/clp				\
		libCoinMP.so:math/coinmp				\
		libCoinUtils.so:math/coinutils				\
		libcoinmumps.so:math/coin-or-mumps			\
		libnauty.so:math/nauty					\
		libopenblas.so:math/openblas				\
		libOsi.so:math/osi					\
		libfreetype.so:print/freetype2				\
		libharfbuzz.so:print/harfbuzz				\
		libnss3.so:security/nss					\
		libexpat.so:textproc/expat2				\
		libhunspell-1.7.so:textproc/hunspell			\
		libhyphen.so:textproc/hyphen				\
		libtextcat.so:textproc/libtextcat			\
		libmythes-1.2.so:textproc/mythes			\
		librdf.so:textproc/redland				\
		libserf-1.so:www/serf					\
		libfontconfig.so:x11-fonts/fontconfig
RUN_DEPENDS=								\
		${LOCALBASE}/share/icons/hicolor/index.theme:misc/hicolor-icon-theme \
		${JAVALIBDIR}/commons-lang.jar:java/apache-commons-lang \
		${JAVALIBDIR}/bsh.jar:lang/bsh				\
		${LOCALBASE}/share/fonts/Caladea/Caladea-Bold.ttf:x11-fonts/crosextrafonts-caladea-ttf \
		${LOCALBASE}/share/fonts/Carlito/Carlito-Bold.ttf:x11-fonts/crosextrafonts-carlito-ttf \
		${LOCALBASE}/share/fonts/ChromeOS/Arimo-Bold.ttf:x11-fonts/croscorefonts-fonts-ttf
# For libgfortran.so and libquadmath.so
BUILD_DEPENDS+=	gcc${GCC_DEFAULT}>0:lang/gcc${GCC_DEFAULT}
RUN_DEPENDS+=	gcc${GCC_DEFAULT}>0:lang/gcc${GCC_DEFAULT}

USES=		autoreconf bison compiler:c++11-lib cpe desktop-file-utils \
		gettext-runtime gl gmake gnome iconv java jpeg perl5 pkgconfig \
		shared-mime-info ssl tar:bzip2 xorg
USE_GL=		gl glu
USE_GNOME=	gdkpixbuf gdkpixbuf2xlib gtk20 libxslt glib20
JAVA_VENDOR=	openjdk
USE_PERL5=	build
USE_XORG=	ice sm x11 xau xaw xcomposite xcursor xdamage xext xfixes xi \
		xinerama xrandr xrender xt

CONFLICTS_INSTALL=	apache-openoffice-devel

AOOVERSION1=	4
AOOVERSION2=	1
AOOVERSION3=	15
# From solenv/inc/minor.mk SOURCEREVISION LAST_MINOR BUILD
AOOTAG=		AOO4115m2\(Build:9813\)
GITREVISION=	5f13fa0070
EXTSRC=		ApacheOpenOffice.ext_sources.${AOOVERSION1}.x.x.20150707.tar.gz

AOOVERSION=	${AOOVERSION1}.${AOOVERSION2}.${AOOVERSION3}
AOOXXX=		${AOOVERSION1}${AOOVERSION2}${AOOVERSION3}
AOOSUFFIX=	${AOOVERSION1}.${AOOVERSION2}
AOOSRC=		apache-openoffice-${AOOVERSION}-${GITREVISION}-src${EXTRACT_SUFX}

AOOUDIR=		.openoffice.org\/${AOOVERSION1}
INSTALLATION_BASEDIR?=	openoffice-${AOOSUFFIX}
PRINSTALLATION_BASEDIR=	${PREFIX}/${INSTALLATION_BASEDIR}
OOPATH=			${PRINSTALLATION_BASEDIR}/openoffice${AOOVERSION1}
XDGDIR=			${OOPATH}/share/xdg
XDGREL=			../../${INSTALLATION_BASEDIR}/openoffice${AOOVERSION1}/share/xdg
EXECBASE?=		openoffice-${AOOSUFFIX}

WITHOUT_CPU_CFLAGS=	true
CPE_PRODUCT=	${PORTNAME:S|apache-||}
CPE_VENDOR=	apache

OPTIONS_DEFINE=		CRASHDUMP CUPS DBGUTIL DEBUG GNOME \
			SDK WIKI_PUBLISHER
OPTIONS_DEFAULT=	CUPS GNOME WIKI_PUBLISHER
CRASHDUMP_DESC=		Enable crashdumps, you also need to set WITH_DEBUG_PORTS+=${PKGORIGIN}
DBGUTIL_DESC=		Enable assertions, object counting. (non-production)
DEBUG_DESC=		Compile with -O0, you also need to set WITH_DEBUG_PORTS+=${PKGORIGIN}
GNOME_DESC=		Screensaver presentation control via DBUS
SDK_DESC=		Build and install software development kit
WIKI_PUBLISHER_DESC=	Build and install Wiki Publisher extension

CRASHDUMP_CONFIGURE_ENABLE=	crashdump

CUPS_CONFIGURE_ENABLE=		cups
CUPS_LIB_DEPENDS=		libcups.so:print/cups

DBGUTIL_CONFIGURE_ENABLE=	dbgutil

DEBUG_CONFIGURE_ENABLE=		debug

GNOME_CONFIGURE_ENABLE=		dbus lockdown
GNOME_LIB_DEPENDS=		libdbus-1.so:devel/dbus \
				libdbus-glib-1.so:devel/dbus-glib

SDK_CONFIGURE_ENABLE=		odk
SDK_DISTFILES=			unowinreg.dll:unoreg

WIKI_PUBLISHER_CONFIGURE_ENABLE=	wiki-publisher
WIKI_PUBLISHER_CONFIGURE_WITH=						\
	commons-codec-jar=${JAVALIBDIR}/commons-codec.jar		\
	commons-httpclient-jar=${JAVALIBDIR}/commons-httpclient.jar	\
	commons-logging-jar=${JAVALIBDIR}/commons-logging.jar
WIKI_PUBLISHER_JAR_DEPENDS=						\
	${JAVALIBDIR}/commons-codec.jar:java/apache-commons-codec	\
	${JAVALIBDIR}/commons-httpclient.jar:java/apache-commons-httpclient \
	${JAVALIBDIR}/commons-logging.jar:java/apache-commons-logging
WIKI_PUBLISHER_BUILD_DEPENDS=	${WIKI_PUBLISHER_JAR_DEPENDS}
WIKI_PUBLISHER_RUN_DEPENDS=	${WIKI_PUBLISHER_JAR_DEPENDS}
WIKI_PUBLISHER_VARS=	BUNDLED_EXTENSIONS+=swext/wiki-publisher.oxt

# Don't run gnome-post-icons until after post-install generates the plist
TARGET_ORDER_OVERRIDE=	710:gnome-post-icons

# Force the SDK option on for makesum to ensure that unowinreg.dll is
# included in distinfo
.if make(makesum) || make(distclean)
WITH=	SDK
.endif

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1500000
# nm: '../unxfbsdi.pro/slo/b2dcubicbezier.o': Invalid argument
MAKE_JOBS_UNSAFE=	yes
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-symbols
.else
CONFIGURE_ARGS+=	--enable-strip-solver
.endif

.include <${FILESDIR}/Makefile.localized>

PYTHON_DISTFILE=	38c84292658ed4456157195f1c9bcbe1-Python-2.7.18.tgz
GCC_EXTRA_DISTFILES=	d6eef4b4cacb2183f2bf265a5a03a354-boost_1_55_0.tar.bz2 \
			d62650a6f908e85643e557a236ea989c-vigra1.6.0.tar.gz

.if ${CHOSEN_COMPILER_TYPE} == clang
CPPFLAGS+=		-I${LOCALBASE}/include
. if ${ARCH} == amd64
EXTRA_PATCHES+=		${FILESDIR}/extra-patch-align16
. endif
.endif

.if ${ARCH} == amd64
FREEBSD_ENV_SET=	FreeBSDAMDEnv.Set.sh
PACKAGE_MIDDLE=		${PORTVERSION}_${OPSYS}_x86-64
.elif ${ARCH} == i386
FREEBSD_ENV_SET=	FreeBSDX86Env.Set.sh
PACKAGE_MIDDLE=		${PORTVERSION}_${OPSYS}_x86
.elif ${ARCH} == powerpc64
FREEBSD_ENV_SET=	FreeBSDPPC64Env.Set.sh
PACKAGE_MIDDLE=		${PORTVERSION}_${OPSYS}_ppc64
.endif
PACKAGE_PREFIX=		Apache_OpenOffice

LOCALIZED_LANG?=	en-US

AOO_MAKE_ENV=	${MAKE_ENV:NCPPFLAGS=*:NCFLAGS=*:NCXXFLAGS=*:NLDFLAGS=*}

GNU_CONFIGURE=	yes
WRKSUBDIR=	${WRKDIR}/aoo-${AOOVERSION}
WRKSRC?=	${WRKSUBDIR}/main
SUB_FILES=	pkg-message
SUB_LIST=	EXECBASE=${EXECBASE} AOOTAG=${AOOTAG} AOOUDIR=${AOOUDIR} \
		AOOVERSION=${AOOVERSION}				\
		PRINSTALLATION_BASEDIR=${PRINSTALLATION_BASEDIR}

CONFIGURE_ARGS+=							\
			--disable-gconf					\
			--enable-gio					\
			--disable-gnome-vfs				\
			--with-unix-wrapper=${EXECBASE}			\
			--with-alloc=system				\
			--with-ant-home=${LOCALBASE}/share/java/apache-ant \
			--with-system-apache-commons=yes		\
			--with-commons-lang-jar=${JAVALIBDIR}/commons-lang.jar \
			--with-system-apr				\
			--with-system-apr-util				\
			--with-system-beanshell				\
			--with-beanshell-jar=${JAVALIBDIR}/bsh.jar	\
			--enable-category-b				\
			--with-system-cairo --enable-cairo		\
			--with-system-coinmp				\
			--with-system-curl				\
			--with-system-dicts				\
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
			--with-jdk-home=${JAVA_HOME}			\
			--with-system-jpeg				\
			--with-junit=${JAVALIBDIR}/junit.jar		\
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
			--without-system-python				\
			--with-system-redland				\
			--with-system-sane				\
			--with-system-serf				\
			--with-system-stdlibs				\
			--with-vendor="FreeBSD ports system"		\
			--with-build-version="PKGNAME: ${PKGNAME:S/,/@/g}" \
			--enable-verbose				\
			--with-system-xrender				\
			--with-system-zlib

.if defined (BUNDLED_EXTENSIONS)
CONFIGURE_ARGS+=	--with-bundled-prereg-extensions="${BUNDLED_EXTENSIONS}"
.endif

CREATE_TREE=	${WRKSRC}/sysui/desktop/share/create_tree.sh

.include <${FILESDIR}/Makefile.knobs>

pre-everything::
# really tweak, extremely useful when you build all localized language versions
# needed after when you build with ALL_LOCALIZED_LANGS.
.if defined(TWEAK_L10N)
	${RM} ${WRKDIR}/.PLIST*
	${RM} ${WRKDIR}/.install_done.*
	${RM} ${WRKDIR}/.package_done.*
	${RM} ${WRKDIR}/.extract_done.*
	${RM} ${WRKDIR}/.patch_done.*
	${RM} ${WRKDIR}/.configure_done.*
	${RM} ${WRKDIR}/.build_done.*
	${MKDIR} ${WRKDIR}
	${TOUCH} ${EXTRACT_COOKIE}
	${TOUCH} ${PATCH_COOKIE}
	${TOUCH} ${CONFIGURE_COOKIE}
	${TOUCH} ${BUILD_COOKIE}
.endif

do-extract-SDK-on:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/unowinreg.dll ${WRKSRC}/external/unowinreg/

post-extract:
	${TAR} -C ${WRKSUBDIR} -xzf ${DISTDIR}/${DIST_SUBDIR}/${EXTSRC}
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${PYTHON_DISTFILE} ${WRKSUBDIR}/ext_sources/${PYTHON_DISTFILE}
.for f in ${GCC_EXTRA_DISTFILES}
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${f} ${WRKSUBDIR}/ext_sources/${f}
.endfor
	${CP} ${FILESDIR}/freebsd-aoo-intro.png \
		${WRKSRC}/default_images/introabout/intro.png
	${CP} ${FILESDIR}/freebsd-aoo-about.png \
		${WRKSRC}/default_images/introabout/about.png
	${RM} -r ${WRKSRC}/l10n
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
	${SED}  -e '\|^For Multi-Dimensional Data|,/^__/p'		\
		-e '\|^For XSLT MathML Library|,/^__/p'			\
		-e d  ${WRKSRC}/LICENSE > ${LICENSE_FILE_MIT}
	${SED}  -e '\|^For XMLSec Library|,/^__/p'			\
		-e d  ${WRKSRC}/LICENSE_category_b >> ${LICENSE_FILE_MIT}
	${SED}  -e '\|^For Saxon|,/^__/p'				\
		-e d ${WRKSRC}/LICENSE_category_b > ${LICENSE_FILE_MPL10}
	${SED}  -e '\|^The following Licenses have some restrictions|,/^- For Network/p' \
		-e d ${WRKSRC}/LICENSE_category_b |			\
		${SED} -e :a -e '$d;N;2,3ba' -e 'P;D' > ${LICENSE_FILE_MPL11}
	${SED}  -e '\|^For main/filter/source/config/tools/merge/pyAltFCFGMerge|,/^__/p'	\
		-e d  ${WRKSRC}/LICENSE > ${LICENSE_FILE_PSFL}
	${ECHO} '' >> ${LICENSE_FILE_PSFL}
	${SED}  -e '\|^For Python|,/^__/p'	\
		-e d  ${WRKSRC}/LICENSE >> ${LICENSE_FILE_PSFL}
	${SED}  -e '\|^For main/twain|,/^__/p'				\
		-e d  ${WRKSRC}/LICENSE > ${LICENSE_FILE_TWAIN}
	${SED}  -e '\|^For main/MathMLDTD|,/^__/p'			\
		-e d  ${WRKSRC}/LICENSE > ${LICENSE_FILE_W3C}

post-patch:
	${REINPLACE_CMD} -e "/^ICONVERSION/s/=.*/= '${AOOVERSION1}'/" \
		${WRKSRC}/sysui/desktop/productversion.mk
	${REINPLACE_CMD} -e "s|%%JAVA_HOME%%|${JAVA_HOME}|" \
		${WRKSRC}/desktop/scripts/soffice.sh
	${REINPLACE_CMD} -e '/^mkdir -p/,$$d' ${CREATE_TREE}
.if ${CHOSEN_COMPILER_TYPE} == gcc
	# g++49 -Os sometimes leaves inline class methods undefined,
	# affects fmgridif.cxx and ColumnControl.cxx
	# See: <https://gcc.gnu.org/bugzilla/show_bug.cgi?id=65009>
	if [ ${CXX} = g++49  ]; then \
		${REINPLACE_CMD} -e "s/ := -Os/ := -Os -fno-devirtualize -fno-devirtualize-speculatively/" ${WRKSRC}/solenv/gbuild/platform/freebsd.mk; \
		${REINPLACE_CMD} -e "s/=-Os /=-Os -fno-devirtualize -fno-devirtualize-speculatively /" ${WRKSRC}/solenv/inc/unxfbsdi.mk; \
	fi
.elif ${ARCH} == i386 && ${CHOSEN_COMPILER_TYPE} == clang
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

# Verify that lucene was built with the CONTRIB option instead of
# failing mysteriously during the build
pre-configure:
	@if [ ! -f ${JAVALIBDIR}/lucene-analyzers-3.6.2.jar ]; then \
		${ECHO} "error: textproc/lucene must be built with the CONTRIB option enabled"; \
		exit 1; \
	fi

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
	export ${AOO_MAKE_ENV} ;					  \
	. ../${FREEBSD_ENV_SET} ;					  \
	build.pl --all -P$${numproc} -- -P$${dmproc}

PYDL=	${STAGEDIR}${OOPATH}/program/python-core-2.7.18/lib/lib-dynload

do-install:
	@${MKDIR} ${STAGEDIR}${PRINSTALLATION_BASEDIR} \
		${STAGEDIR}${PREFIX}/share/mime/packages
	@cd ${WRKSRC} ; \
		. ${FREEBSD_ENV_SET} ; \
		cd instsetoo_native/$${INPATH}/Apache_OpenOffice/archive/install/${LOCALIZED_LANG}/ ; \
		for i in *.tar.?z ; do \
			${ECHO_CMD} "extracting $$i" ; \
			${TAR} -s '|./[^/]*/||' -xz -f $$i \
				-C ${STAGEDIR}${PRINSTALLATION_BASEDIR} ; \
		done
	${RM} ${PYDL}/_sqlite3.so ${PYDL}/gdbm.so ${PYDL}/readline.so
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
	@${ECHO_CMD} "adding desktop support"
	@cd ${WRKSRC} ;						\
	    . ${FREEBSD_ENV_SET} ;				\
	    cd sysui/$${INPATH}/misc/openoffice ;		\
	    DESTDIR=${STAGEDIR}					\
		GNOMEDIR=${PREFIX}				\
		ICON_PREFIX=openoffice${AOOVERSION1}		\
		ICON_SOURCE_DIR=${WRKSRC}/sysui/desktop/icons	\
		ICON_THEMES="hicolor/??x??"			\
		KDEMAINDIR=${PREFIX}				\
		PREFIX=openoffice${AOOVERSION1}			\
		${SH} ${CREATE_TREE} ;				\
	    ${INSTALL_DATA} apacheopenoffice.xml		\
		${STAGEDIR}/${PREFIX}/share/mime/packages
	@cd ${STAGEDIR}${DESKTOPDIR}; for i in base calc draw impress \
		javafilter math printeradmin qstart startcenter writer ; do \
			${LN} -sf ${XDGREL}/$${i}.desktop ${EXECBASE}-$${i}.desktop ; \
	done

do-install-SDK-on:
	${TAR} -s '|./[^/]*/||' -xz -C ${STAGEDIR}${PRINSTALLATION_BASEDIR} \
		-f ${WRKSRC}/instsetoo_native/unxfbsd*.pro/Apache_OpenOffice_SDK/archive/install/${LOCALIZED_LANG}/*.tar.gz
	@f=${STAGEDIR}${OOPATH}/sdk/bin/unoapploader ; \
		${CHMOD} 644 $${f} ; ${STRIP_CMD} $${f} ; ${CHMOD} 444 $${f}

post-install:
	@${ECHO_CMD} "generating plist";
	@cd ${STAGEDIR}${PREFIX} ; (\
		${FIND} -s bin -name "${EXECBASE}*" ; \
		${FIND} -s ${INSTALLATION_BASEDIR} share/applications \
			share/application-registry share/icons \
			share/mime-info share/mime share/mimelnk \! -type d ; \
		${FIND} ${INSTALLATION_BASEDIR} -type d -empty | ${SORT} -r | \
			${SED} -e 's/^/@dir /' ; \
	) >> ${TMPPLIST}

.include <${FILESDIR}/Makefile.others>

.include <bsd.port.post.mk>
