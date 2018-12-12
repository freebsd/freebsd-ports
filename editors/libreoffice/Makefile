# $FreeBSD$

.include "${.CURDIR}/Makefile.common"

PORTREVISION=	3
MASTER_SITES=	https://download.documentfoundation.org/libreoffice/src/${PORTVERSION}/ \
		https://dev-www.libreoffice.org/src/:src \
		https://dev-www.libreoffice.org/extern/:ext
DISTFILES=	${PORTNAME}-${LOVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-help-${LOVERSION}${EXTRACT_SUFX}
DIST_SUBDIR=	libreoffice
EXTRACT_ONLY:=	${DISTFILES}

COMMENT=	Full integrated office productivity suite

BUILD_DEPENDS=	p5-Archive-Zip>=0:archivers/p5-Archive-Zip \
		zip:archivers/zip \
		${LOCALBASE}/include/sqlext.h:databases/unixODBC \
		cppunit-config:devel/cppunit \
		dmake:devel/dmake \
		${LOCALBASE}/bin/gperf:devel/gperf \
		${LOCALBASE}/include/mdds-1.2/mdds/global.hpp:devel/mdds \
		gpatch:devel/patch \
		ucpp:devel/ucpp \
		${LOCALBASE}/include/sane/sane.h:graphics/sane-backends \
		vigra-config:graphics/vigra \
		${LOCALBASE}/include/glm/glm.hpp:math/glm \
		bash:shells/bash \
		gsed:textproc/gsed
LIB_DEPENDS=	libapr-1.so:devel/apr1 \
		libboost_date_time.so:devel/boost-libs \
		libicutu.so:devel/icu \
		liblangtag.so:devel/liblangtag \
		libltdl.so:devel/libltdl \
		liborcus-0.13.so:devel/liborcus \
		libplds4.so:devel/nspr \
		libcurl.so:ftp/curl \
		libcairo.so:graphics/cairo \
		libgraphite2.so:graphics/graphite2 \
		liblcms2.so:graphics/lcms2 \
		libcdr-0.1.so:graphics/libcdr01 \
		libepoxy.so:graphics/libepoxy \
		libetonyek-0.1.so:graphics/libetonyek01 \
		libfreehand-0.1.so:graphics/libfreehand \
		libgltf-0.0.so:graphics/libgltf \
		libwpg-0.3.so:graphics/libwpg03 \
		libzmf-0.0.so:graphics/libzmf \
		libGeneratedSaxParser.so:graphics/opencollada \
		libpng.so:graphics/png \
		libpoppler.so:graphics/poppler \
		libCoinMP.so:math/coinmp \
		liblpsolve55.so:math/lp_solve \
		libcmis-0.5.so:net/libcmis \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libharfbuzz-icu.so:print/harfbuzz-icu \
		libmspub-0.1.so:print/libmspub01 \
		libpagemaker-0.0.so:print/libpagemaker \
		libnss3.so:security/nss \
		libxmlsec1-nss.so:security/xmlsec1 \
		libclucene-core.so:textproc/clucene \
		libexpat.so:textproc/expat2 \
		libhunspell-1.6.so:textproc/hunspell \
		libhyphen.so:textproc/hyphen \
		libabw-0.1.so:textproc/libabw \
		libe-book-0.1.so:textproc/libe-book \
		libepubgen-0.1.so:textproc/libepubgen \
		libexttextcat-2.0.so:textproc/libexttextcat \
		libmwaw-0.3.so:textproc/libmwaw03 \
		libodfgen-0.1.so:textproc/libodfgen01 \
		libqxp-0.0.so:textproc/libqxp \
		librevenge-0.0.so:textproc/librevenge \
		libstaroffice-0.0.so:textproc/libstaroffice \
		libvisio-0.1.so:textproc/libvisio01 \
		libwpd-0.10.so:textproc/libwpd010 \
		libwps-0.4.so:textproc/libwps \
		libxml2.so:textproc/libxml2 \
		libxslt.so:textproc/libxslt \
		libmythes-1.2.so:textproc/mythes \
		libraptor2.so:textproc/raptor2 \
		librdf.so:textproc/redland \
		libfontconfig.so:x11-fonts/fontconfig \
		libserf-1.so:www/serf
RUN_DEPENDS=	xdg-open:devel/xdg-utils \
		${LOCALBASE}/share/fonts/Caladea/Caladea-Bold.ttf:x11-fonts/crosextrafonts-caladea-ttf \
		${LOCALBASE}/share/fonts/Carlito/Carlito-Bold.ttf:x11-fonts/crosextrafonts-carlito-ttf \
		${LOCALBASE}/share/fonts/dejavu/DejaVuSans.ttf:x11-fonts/dejavu \
		${LOCALBASE}/share/fonts/twemoji-color-font-ttf/TwitterColorEmoji-SVGinOT.ttf:x11-fonts/twemoji-color-font-ttf \
		${LOCALBASE}/share/fonts/GentiumBasic/GenBasI.ttf:x11-fonts/gentium-basic \
		${LOCALBASE}/share/fonts/Liberation/LiberationMono-Bold.ttf:x11-fonts/liberation-fonts-ttf \
		${LOCALBASE}/share/fonts/LinLibertineG/LinLibertine_DR_G.ttf:x11-fonts/linuxlibertine-g

DISTFILES+=	4b87018f7fff1d054939d19920b751a0-collada2gltf-master-cb1d97788a.tar.bz2:src

NOT_FOR_ARCHS=		aarch64 armv6 armv7
NOT_FOR_ARCHS_REASON=	Unsupported host_cpu

.if defined(PRERELEASE)
MASTER_SITES+=	http://dev-builds.libreoffice.org/pre-releases/src/
.endif

INSTALL_TARGET=	distro-pack-install
WRKSRC=		${WRKDIR}/${PORTNAME}-${LOVERSION}

SHEBANG_GLOB=	*.py

GNU_CONFIGURE=	yes
USE_GL=		gl glew glu
USE_OPENLDAP=	yes
USE_PERL5=	build
USE_XORG=	ice sm x11 xaw xext xinerama xrandr xrender
USES=		autoreconf:build bison compiler:c++14-lang cpe gmake jpeg \
		perl5 pkgconfig python shebangfix shared-mime-info ssl tar:xz

OPTIONS_DEFINE=	CUPS DOCS GNOME GTK2 GTK3 JAVA KDE4 MMEDIA PGSQL SDK SYSTRAY \
		TEST WEBDAV
OPTIONS_DEFAULT=	CUPS GTK2 MMEDIA

GTK2_DESC=	GTK+ 2 GUI toolkit support
GTK3_DESC=	GTK+ 3 GUI toolkit support (experimental)
JAVA_DESC=	Add Java support (XML filters, macros, DB connections)
MMEDIA_DESC=	Enable multimedia backend for Impress
PGSQL_DESC=	Build with PostgreSQL-SDBC driver
SDK_DESC=	Build with SDK
SYSTRAY_DESC=	Enable systemtray quickstarter
TEST_DESC=	Run all regression tests
WEBDAV_DESC=	Enable WebDAV protocol

CUPS_CONFIGURE_ENABLE=	cups
CUPS_LIB_DEPENDS=	libcups.so:print/cups

DOCS_CONFIGURE_WITH=	help

GNOME_CONFIGURE_ENABLE=	dbus dconf
GNOME_IMPLIES=	GTK2
GNOME_LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib
GNOME_USE=	GNOME=dconf

GTK_USE_GNOME=	gtk-update-icon-cache
GTK_USES=	desktop-file-utils
GTK_VARS=	POST_PLIST=add-plist-gnome

GTK2_CONFIGURE_ENABLE=	gtk
GTK2_USE=	GNOME=gtk20,${GTK_USE_GNOME}
GTK2_USES=	${GTK_USES}
GTK2_VARS=	${GTK_VARS}

GTK3_CONFIGURE_ENABLE=	gtk3
GTK3_USE=	GNOME=gtk30,${GTK_USE_GNOME}
GTK3_USES=	${GTK_USES}
GTK3_VARS=	${GTK_VARS}

JAVA_BUILD_DEPENDS=	ant:devel/apache-ant \
			${JAVAJARDIR}/commons-codec.jar:java/jakarta-commons-codec \
			${JAVAJARDIR}/commons-httpclient.jar:java/jakarta-commons-httpclient \
			${JAVAJARDIR}/commons-lang.jar:java/jakarta-commons-lang \
			${JAVAJARDIR}/commons-logging.jar:java/jakarta-commons-logging \
			${JAVAJARDIR}/junit.jar:java/junit \
			${JAVAJARDIR}/bsh.jar:lang/bsh
JAVA_CATEGORIES=	java
JAVA_CONFIGURE_ON=	--with-ant-home=${LOCALBASE}/share/java/apache-ant \
			--with-beanshell-jar=${JAVAJARDIR}/bsh.jar \
			--with-commons-codec-jar=${JAVAJARDIR}/commons-codec.jar \
			--with-commons-httpclient-jar=${JAVAJARDIR}/commons-httpclient.jar \
			--with-commons-lang-jar=${JAVAJARDIR}/commons-lang.jar \
			--with-commons-logging-jar=${JAVAJARDIR}/commons-logging.jar \
			--with-jdk-home="${JAVA_HOME}" \
			--with-junit=${JAVAJARDIR}/junit.jar \
			--with-hamcrest=${JAVAJARDIR}/hamcrest.jar \
			--without-system-jfreereport
JAVA_CONFIGURE_WITH=	java
# XXX jni.h from GNU classpath causes ABI conflicts.
JAVA_CONFLICTS_BUILD=	classpath-[0-9]*
JAVA_DISTFILES=	17410483b5b5f267aa18b7e00b65e6e0-hsqldb_1_8_0.zip:src \
		3404ab6b1792ae5f16bbd603bd1e1d03-libformula-1.1.7.zip:src \
		35c94d2df8893241173de1d16b6034c0-swingExSrc.zip:src \
		39bb3fcea1514f1369fcfc87542390fd-sacjava-1.3.zip:src \
		3bdf40c0d199af31923e900d082ca2dd-libfonts-1.1.6.zip:src \
		798b2ffdc8bcfe7bca2cf92b62caf685-rhino1_5R5.zip:src \
		8249374c274932a21846fa7629c2aa9b-officeotron-0.7.4-master.jar:ext \
		8ce2fcd72becf06c41f7201d15373ed9-librepository-1.1.6.zip:src \
		97b2d4dba862397f446b217e2b623e71-libloader-1.1.6.zip:src \
		a084cd548b586552cb7d3ee51f1af969-odfvalidator-1.1.8-incubating-SNAPSHOT-jar-with-dependencies.jar:ext \
		ace6ab49184e329db254e454a010f56d-libxml-1.1.7.zip:src \
		ba2930200c9f019c2d93a8c88c651a0f-flow-engine-0.9.4.zip:src \
		d8bd5eed178db6e2b18eeed243f85aa8-flute-1.1.6.zip:src \
		db60e4fde8dd6d6807523deb71ee34dc-liblayout-0.2.10.zip:src \
		eeb2c7ddf0d302fba4bfc6e97eac9624-libbase-1.1.6.zip:src \
		f94d9870737518e3b597f9265f4e9803-libserializer-1.1.6.zip:src
JAVA_USE=	JAVA=yes
JAVA_VARS=	JAVA_BUILD=yes

KDE4_CONFIGURE_ENABLE=	kde4
KDE4_CONFIGURE_ENV=	KDE4DIR="${KDE_PREFIX}" \
			QT4DIR="${PREFIX}" \
			QT4INC="${QT_INCDIR}" \
			QT4LIB="${QT_LIBDIR}"
KDE4_USES=	kde:4 qt:4
KDE4_USE=	KDE=kdelibs QT=moc_build,qmake_build

MMEDIA_CONFIGURE_ENABLE=	gstreamer-1-0
MMEDIA_USE=	GSTREAMER1=yes

PGSQL_CONFIGURE_ENABLE=	postgresql-sdbc
PGSQL_CONFIGURE_WITH=	gssapi krb5
PGSQL_USES=	pgsql

SDK_BUILD_DEPENDS=	doxygen:devel/doxygen
SDK_CONFIGURE_ENABLE=	odk
SDK_CONFIGURE_OFF=	--without-doxygen
SDK_CONFIGURE_ON=	--with-doxygen=${LOCALBASE}/bin/doxygen
SDK_DISTFILES=	185d60944ea767075d27247c3162b3bc-unowinreg.dll:ext

SYSTRAY_CONFIGURE_ENABLE=	systray

TEST_ALL_TARGET_OFF=	build-nocheck
TEST_CONFIGURE_ENABLE=	cve-tests

WEBDAV_CONFIGURE_ENABLE=	neon
WEBDAV_LIB_DEPENDS=	libneon.so:www/neon

CPPFLAGS+=	-isystem ${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

COLLADA_MODS=	COLLADABaseUtils COLLADAFramework \
		COLLADASaxFrameworkLoader GeneratedSaxParser
COLLADA_CFLAGS=	${COLLADA_MODS:S|^|-isystem ${LOCALBASE}/include/opencollada/|}
COLLADA_LIBS=	-L${LOCALBASE}/lib/opencollada \
		${COLLADA_MODS:S|^COLLADA|OpenCOLLADA|:S|^|-l|}

CONFIGURE_ARGS=	--disable-dependency-tracking \
		--disable-epm \
		--disable-fetch-external \
		--disable-firebird-sdbc \
		--disable-mergelibs \
		--disable-online-update \
		--enable-cairo-canvas \
		--enable-python=system \
		--enable-release-build \
		--disable-pdfium \
		--exec-prefix=${PREFIX} \
		--with-alloc=system \
		--with-boost=${LOCALBASE} \
		--with-build-version="FreeBSD ports ${PKGVERSION}" \
		--with-external-dict-dir=${LOCALBASE}/share/hunspell \
		--with-external-hyph-dir=${LOCALBASE}/share/hyphen \
		--with-external-tar=${DISTDIR}/${DIST_SUBDIR} \
		--with-external-thes-dir=${LOCALBASE}/share/mythes \
		--with-gnu-patch=${LOCALBASE}/bin/gpatch \
		--with-os-version=${OSVERSION} \
		--with-parallelism=${MAKE_JOBS_NUMBER} \
		--with-system-cppunit \
		--with-system-curl \
		--with-system-dicts \
		--with-system-libs \
		--with-system-libxml \
		--with-system-opencollada \
		--with-system-ucpp \
		--with-system-zlib \
		--with-vendor="FreeBSD ports" \
		--without-fonts \
		--without-myspell-dicts

CONFIGURE_ENV=	DMAKE=${LOCALBASE}/bin/dmake \
		GNUTAR="${TAR}" \
		GPERF=${LOCALBASE}/bin/gperf \
		ICU_CFLAGS="`icu-config --cflags`" \
		ICU_LIBS="`icu-config --ldflags`" \
		OPENCOLLADA_CFLAGS="${COLLADA_CFLAGS}" \
		OPENCOLLADA_LIBS="${COLLADA_LIBS}" \
		PYTHON_CFLAGS="`${PYTHON_VERSION}-config --cflags`" \
		PYTHON_LIBS="`${PYTHON_VERSION}-config --libs`"

MAKE_ARGS+=	TMPDIR=${WRKDIR}
MAKE_ENV+=	CXXFLAGS_WARN="${CXXFLAGS_WARN}"
MAKE_ENV+=	GNUSED=${LOCALBASE}/bin/gsed
MAKE_ENV+=	DISPLAY=
MAKE_ENV+=	verbose=1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MKDE4}
DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2018-12-31
.endif

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == clang
CXXFLAGS_WARN=	-Woverloaded-virtual -Wno-unused-parameter -Wno-unused-local-typedefs
.else
CXXFLAGS_WARN=	-Wshadow -Woverloaded-virtual
.endif

post-patch:
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
	    ${WRKSRC}/shell/source/unix/exec/shellexec.cxx
.if ${COMPILER_FEATURES:Mlibstdc++}
	${REINPLACE_CMD} -e 's/gb_CC/gb_CXX/' ${WRKSRC}/solenv/gbuild/platform/unxgcc.mk
.endif

pre-configure:
	@${TOUCH} ${WRKSRC}/autogen.lastrun

post-configure:
	@${TOUCH} ${WRKSRC}/src.downloaded

post-install:
	@cd ${STAGEDIR}${PREFIX} && \
	${FIND} -s lib/libreoffice -type d -empty \
	    -exec ${ECHO_CMD} "@dir {}" \; >> ${TMPPLIST}
	@cd ${STAGEDIR}${PREFIX} && \
	${FIND} -s bin lib man -not -type d >> ${TMPPLIST}
.for subdir in appdata application-registry applications bash-completion icons mime mime-info
	@cd ${STAGEDIR}${PREFIX} && \
	${FIND} -s share/${subdir} -not -type d >> ${TMPPLIST}
.endfor

post-install-SDK-on:
.for subdir in include share share/doc share/idl
	@cd ${STAGEDIR}${PREFIX} && \
	${FIND} -s ${subdir}/libreoffice -not -type d >> ${TMPPLIST}
.endfor

add-plist-gnome:
.for subdir in gnome hicolor locolor
	@${ECHO_CMD} "@rmtry share/icons/${subdir}/icon-theme.cache" >> ${TMPPLIST}
	@${ECHO_CMD} "@postexec ${LOCALBASE}/bin/gtk-update-icon-cache -q -f %D/share/icons/${subdir} 2>/dev/null || ${TRUE}" >> ${TMPPLIST}
	@${ECHO_CMD} "@postunexec ${LOCALBASE}/bin/gtk-update-icon-cache -q -f %D/share/icons/${subdir} 2>/dev/null || ${TRUE}" >> ${TMPPLIST}
.endfor

.include <bsd.port.post.mk>
