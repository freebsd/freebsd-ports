PORTREVISION=	2

.include "${.CURDIR}/Makefile.common"

MASTER_SITES=	https://download.documentfoundation.org/libreoffice/src/${LOVERSION}/ \
		https://dev-www.libreoffice.org/src/:src \
		https://dev-www.libreoffice.org/extern/:ext
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-help-${DISTVERSION}${EXTRACT_SUFX}
DIST_SUBDIR=	libreoffice
EXTRACT_ONLY:=	${DISTFILES}

COMMENT=	Full integrated office productivity suite
WWW?=		https://www.libreoffice.org/

BUILD_DEPENDS=	p5-Archive-Zip>=0:archivers/p5-Archive-Zip \
		zip:archivers/zip \
		pigz:archivers/pigz \
		${LOCALBASE}/include/sqlext.h:databases/unixODBC \
		cppunit-config:devel/cppunit \
		dmake:devel/dmake \
		gperf>=3.1:devel/gperf \
		${LOCALBASE}/include/libcuckoo/cuckoohash_map.hh:devel/libcuckoo \
		mdds>=2.1:devel/mdds \
		gpatch:devel/patch \
		${LOCALBASE}/include/sane/sane.h:graphics/sane-backends \
		vigra-config:graphics/vigra \
		${LOCALBASE}/include/glm/glm.hpp:math/glm \
		bash:shells/bash \
		gsed:textproc/gsed \
		${PYTHON_PKGNAMEPREFIX}lxml5>0:devel/py-lxml5@${PY_FLAVOR} \
		coreutils>=8.23:sysutils/coreutils \
		flex>=0.26:textproc/flex
LIB_DEPENDS=	libapr-1.so:devel/apr1 \
		libboost_date_time.so:devel/boost-libs \
		libbox2d.so:misc/box2d \
		libicutu.so:devel/icu \
		liblangtag.so:devel/liblangtag \
		libltdl.so:devel/libltdl \
		liborcus-0.18.so:devel/liborcus \
		libplds4.so:devel/nspr \
		libcurl.so:ftp/curl \
		libgraphite2.so:graphics/graphite2 \
		liblcms2.so:graphics/lcms2 \
		libcdr-0.1.so:graphics/libcdr01 \
		libepoxy.so:graphics/libepoxy \
		libetonyek-0.1.so:graphics/libetonyek01 \
		libfreehand-0.1.so:graphics/libfreehand \
		libwpg-0.3.so:graphics/libwpg03 \
		libzmf-0.0.so:graphics/libzmf \
		libpng.so:graphics/png \
		libpoppler.so:graphics/poppler \
		libtiff.so:graphics/tiff \
		libwebp.so:graphics/webp \
		liblpsolve55.so:math/lp_solve \
		libcmis-0.6.so:net/libcmis \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libharfbuzz-icu.so:print/harfbuzz-icu \
		libmspub-0.1.so:print/libmspub01 \
		libpagemaker-0.0.so:print/libpagemaker \
		libassuan.so:security/libassuan \
		libgpgme.so:security/gpgme \
		libgpgmepp.so:security/gpgmepp \
		libargon2.so:security/libargon2 \
		libgpg-error.so:security/libgpg-error \
		libnss3.so:security/nss \
		libxmlsec1-nss.so:security/xmlsec1 \
		libclucene-core.so:textproc/clucene \
		libexpat.so:textproc/expat2 \
		libhunspell-1.7.so:textproc/hunspell \
		libhyphen.so:textproc/hyphen \
		libabw-0.1.so:textproc/libabw \
		libe-book-0.1.so:textproc/libe-book \
		libepubgen-0.1.so:textproc/libepubgen \
		libexttextcat-2.0.so:textproc/libexttextcat \
		libmwaw-0.3.so:textproc/libmwaw03 \
		libnumbertext-1.0.so:textproc/libnumbertext \
		libodfgen-0.1.so:textproc/libodfgen01 \
		libqxp-0.0.so:textproc/libqxp \
		librevenge-0.0.so:textproc/librevenge \
		libstaroffice-0.0.so:textproc/libstaroffice \
		libvisio-0.1.so:textproc/libvisio01 \
		libwpd-0.10.so:textproc/libwpd010 \
		libwps-0.4.so:textproc/libwps \
		libmythes-1.2.so:textproc/mythes \
		libraptor2.so:textproc/raptor2 \
		librdf.so:textproc/redland \
		libZXing.so:textproc/zxing-cpp \
		libfontconfig.so:x11-fonts/fontconfig \
		libxcb-icccm.so:x11/xcb-util-wm \
		libserf-1.so:www/serf
LIB_DEPENDS+=	${LIB_DEPENDS_${ARCH}}
LIB_DEPENDS_aarch64=	libunwind.so:devel/libunwind
LIB_DEPENDS_amd64=	libunwind.so:devel/libunwind
LIB_DEPENDS_i386=	libunwind.so:devel/libunwind
LIB_DEPENDS_powerpc64=		libunwind.so:devel/libunwind
LIB_DEPENDS_powerpc64le=	libunwind.so:devel/libunwind

RUN_DEPENDS=	xdg-open:devel/xdg-utils \
		${LOCALBASE}/share/fonts/Caladea/Caladea-Bold.ttf:x11-fonts/crosextrafonts-caladea-ttf \
		${LOCALBASE}/share/fonts/Carlito/Carlito-Bold.ttf:x11-fonts/crosextrafonts-carlito-ttf \
		${LOCALBASE}/share/fonts/dejavu/DejaVuSans.ttf:x11-fonts/dejavu \
		${LOCALBASE}/share/fonts/twemoji-color-font-ttf/TwitterColorEmoji-SVGinOT.ttf:x11-fonts/twemoji-color-font-ttf \
		${LOCALBASE}/share/fonts/GentiumBasic/GenBasI.ttf:x11-fonts/gentium-basic \
		${LOCALBASE}/share/fonts/Liberation/LiberationMono-Bold.ttf:x11-fonts/liberation-fonts-ttf \
		${LOCALBASE}/share/fonts/LinLibertineG/LinLibertine_DR_G.ttf:x11-fonts/linuxlibertine-g

DISTFILES+=	f543e6e2d7275557a839a164941c0a86e5f2c3f2a0042bfc434c88c6dde9e140-opens___.ttf:ext
DISTFILES+=	dtoa-20180411.tgz:src
DISTFILES+=	dragonbox-1.1.3.tar.gz:src
DISTFILES+=	frozen-1.2.0.tar.gz:src
DISTFILES+=	skia-m130-3c64459d5df2fa9794b277f0959ed8a92552bf4c.tar.xz:src
DISTFILES+=	zxcvbn-c-2.5.tar.gz:src

NOT_FOR_ARCHS=		armv6 armv7
NOT_FOR_ARCHS_REASON=	Unsupported host_cpu

.if defined(PRERELEASE)
MASTER_SITES+=	https://dev-builds.libreoffice.org/pre-releases/src/
.endif

INSTALL_TARGET=	distro-pack-install

SHEBANG_GLOB=	*.py

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USES=		autoreconf:build bison compiler:c++20-lang cpe desktop-file-utils \
		gettext gl gmake gnome jpeg ldap localbase:ldflags perl5 pkgconfig \
		python shebangfix shared-mime-info ssl tar:xz xorg
USE_GL=		gl glew glu
USE_GNOME=	cairo glib20 libxml2 libxslt
USE_PERL5=	build
USE_XORG=	ice sm x11 xaw xcb xext xinerama xrandr xrender

USES+=		elfctl
ELF_FEATURES=	+wxneeded:instdir/program/soffice.bin

OPTIONS_DEFINE=	COINMP CUPS DOCS GNOME GTK3 GTK4 JAVA LTO MMEDIA PDFIUM PGSQL MARIADB SDK TEST WEBDAV
OPTIONS_RADIO=	QT KDE
OPTIONS_RADIO_QT=	QT5 QT6
OPTIONS_RADIO_KDE=	KF5 KF6
OPTIONS_DEFAULT=	CUPS DOCS JAVA MMEDIA PDFIUM QT5
#OPTIONS_EXCLUDE=	GTK4

COINMP_DESC=	Enable CoinMP (deprecated) math solver
GTK4_DESC=	GTK+ 4 GUI toolkit support (experimental, broken)
JAVA_DESC=	Add Java support (XML filters, macros, DB connections)
KF5_DESC=	KF5/Qt5 GUI toolkit support (implies QT5)
KF6_DESC=	KF6/Qt6 GUI toolkit support (implies QT6)
MMEDIA_DESC=	Enable multimedia backend for Impress
PDFIUM_DESC=	Enable PDFium secure engine
PGSQL_DESC=	Build with PostgreSQL-SDBC driver
MARIADB_DESC=	Build with MariaDB/MySQL-SDBC driver
QT_DESC=	Select Qt GUI engine version
KDE_DESC=	Select KDE GUI engine version
QT5_DESC=	Qt5 GUI toolkit support (default visual style)
QT6_DESC=	Qt6 GUI toolkit support (experimental visual style)
SDK_DESC=	Build with SDK
TEST_DESC=	Run all regression tests
WEBDAV_DESC=	Enable WebDAV protocol

COINMP_CONFIGURE_ENABLE=	coinmp
COINMP_CONFIGURE_ON=	--with-system-coinmp
COINMP_LIB_DEPENDS=	libCoinMP.so:math/coinmp

CUPS_CONFIGURE_ENABLE=	cups
CUPS_LIB_DEPENDS=	libcups.so:print/cups

DOCS_CONFIGURE_ON=	--with-help=html

GNOME_CONFIGURE_ENABLE=	dbus dconf
GNOME_IMPLIES=	GTK3
GNOME_LIB_DEPENDS=	libdbus-1.so:devel/dbus \
			libdbus-glib-1.so:devel/dbus-glib
GNOME_USE=	GNOME=dconf

GTK3_CONFIGURE_ENABLE=	gtk3
GTK3_USE=	GNOME=gtk30

GTK4_CONFIGURE_ENABLE=	gtk4
GTK4_LIB_DEPENDS=	libepoxy.so:graphics/libepoxy \
			libgraphene-1.0.so:graphics/graphene \
			libharfbuzz.so:print/harfbuzz \
			libvulkan.so:graphics/vulkan-loader
GTK4_USE=	GNOME=gtk40

JAVA_BUILD_DEPENDS=	ant:devel/apache-ant \
			${JAVAJARDIR}/commons-codec.jar:java/apache-commons-codec \
			${JAVAJARDIR}/commons-httpclient.jar:java/apache-commons-httpclient \
			${JAVAJARDIR}/commons-lang3.jar:java/apache-commons-lang3 \
			${JAVAJARDIR}/commons-logging.jar:java/apache-commons-logging \
			${JAVAJARDIR}/junit.jar:java/junit
JAVA_CATEGORIES=	java
JAVA_CONFIGURE_ON=	--with-ant-home=${LOCALBASE}/share/java/apache-ant \
			--with-commons-codec-jar=${JAVAJARDIR}/commons-codec.jar \
			--with-commons-httpclient-jar=${JAVAJARDIR}/commons-httpclient.jar \
			--with-commons-lang-jar=${JAVAJARDIR}/commons-lang3.jar \
			--with-commons-logging-jar=${JAVAJARDIR}/commons-logging.jar \
			--with-jdk-home="${JAVA_HOME}" \
			--with-junit=${JAVAJARDIR}/junit.jar \
			--with-hamcrest=${JAVAJARDIR}/hamcrest.jar \
			--with-system-jars \
			--without-system-beanshell \
			--without-system-java-websocket \
			--without-system-jfreereport \
			--without-system-rhino
JAVA_CONFIGURE_WITH=	java
# XXX jni.h from GNU classpath causes ABI conflicts.
JAVA_CONFLICTS_BUILD=	classpath-[0-9]*
JAVA_DISTFILES=	17410483b5b5f267aa18b7e00b65e6e0-hsqldb_1_8_0.zip:src \
		3404ab6b1792ae5f16bbd603bd1e1d03-libformula-1.1.7.zip:src \
		35c94d2df8893241173de1d16b6034c0-swingExSrc.zip:src \
		39bb3fcea1514f1369fcfc87542390fd-sacjava-1.3.zip:src \
		3bdf40c0d199af31923e900d082ca2dd-libfonts-1.1.6.zip:src \
		8249374c274932a21846fa7629c2aa9b-officeotron-0.7.4-master.jar:ext \
		8ce2fcd72becf06c41f7201d15373ed9-librepository-1.1.6.zip:src \
		97b2d4dba862397f446b217e2b623e71-libloader-1.1.6.zip:src \
		a084cd548b586552cb7d3ee51f1af969-odfvalidator-1.1.8-incubating-SNAPSHOT-jar-with-dependencies.jar:ext \
		ace6ab49184e329db254e454a010f56d-libxml-1.1.7.zip:src \
		ba2930200c9f019c2d93a8c88c651a0f-flow-engine-0.9.4.zip:src \
		d8bd5eed178db6e2b18eeed243f85aa8-flute-1.1.6.zip:src \
		db60e4fde8dd6d6807523deb71ee34dc-liblayout-0.2.10.zip:src \
		eeb2c7ddf0d302fba4bfc6e97eac9624-libbase-1.1.6.zip:src \
		f94d9870737518e3b597f9265f4e9803-libserializer-1.1.6.zip:src \
		Java-WebSocket-1.6.0.tar.gz:src \
		bsh-2.1.1-src.zip:src \
		rhino-1.7.15.zip:src
JAVA_USES=	java
JAVA_VARS=	JAVA_VERSION=17+

KF5_CONFIGURE_ENABLE=	kf5
KF5_USE=	kde=config,coreaddons,i18n,kio,windowsystem
KF5_USES=	kde:5
KF5_IMPLIES=	QT5
KF5_PREVENTS=	KF6
KF5_PREVENTS_MSG=	KF5 cannot coexist with KF6

KF6_CONFIGURE_ENABLE=	kf6
KF6_USE=	kde=config,coreaddons,i18n,kio,windowsystem
KF6_USES=	kde:6
KF6_IMPLIES=	QT6
KF6_PREVENTS=	KF5
KF6_PREVENTS_MSG=	KF6 cannot coexist with KF5

LTO_CONFIGURE_ENABLE=	lto

MMEDIA_USES=		gstreamer
MMEDIA_CONFIGURE_ENABLE=	gstreamer-1-0

PDFIUM_CONFIGURE_ENABLE=	pdfium
PDFIUM_DISTFILES=	pdfium-6764.tar.bz2:src
PDFIUM_LIB_DEPENDS=	libabsl_strings.so:devel/abseil \
			libopenjp2.so:graphics/openjpeg

PGSQL_CONFIGURE_ENABLE=	postgresql-sdbc
PGSQL_CONFIGURE_WITH=	gssapi krb5
PGSQL_USES=	pgsql

MARIADB_CONFIGURE_ENABLE=	mariadb-sdbc
MARIADB_USES=	mysql:client

QT5_CONFIGURE_ENABLE=	qt5
QT5_PREVENTS=	KF6
QT5_PREVENTS_MSG=	KF6 support require Qt6 engine
QT5_USE=	qt=buildtools:build,core,gui,network,qmake:build,widgets,x11extras
QT5_USES=	qt:5

QT6_CONFIGURE_ENABLE=	qt6
QT6_CONFIGURE_ENV=	QMAKE6=${QMAKE} MOC6=${MOC} PATH="${QT_TOOLDIR}:${PATH}"
QT6_PREVENTS=	KF5
QT6_PREVENTS_MSG=	KF5 support require Qt5 engine
QT6_USE=	qt=base,declarative,multimedia,tools:build
QT6_USES=	qt:6

SDK_BUILD_DEPENDS=	doxygen:devel/doxygen
SDK_CONFIGURE_ENABLE=	odk
SDK_CONFIGURE_OFF=	--without-doxygen
SDK_CONFIGURE_ON=	--with-doxygen=${LOCALBASE}/bin/doxygen
SDK_DISTFILES=	185d60944ea767075d27247c3162b3bc-unowinreg.dll:ext

TEST_ALL_TARGET=	build
TEST_ALL_TARGET_OFF=	build
TEST_CONFIGURE_ENABLE=	cve-tests

WEBDAV_CONFIGURE_ON=	--with-webdav=neon
WEBDAV_CONFIGURE_OFF=	--with-webdav=no
WEBDAV_LIB_DEPENDS=	libneon.so:www/neon

CONFIGURE_ARGS=	--disable-dependency-tracking \
		--disable-epm \
		--disable-fetch-external \
		--disable-firebird-sdbc \
		--disable-mergelibs \
		--disable-online-update \
		--enable-cairo-canvas \
		--enable-python=system \
		--enable-release-build \
		--enable-extension-integration \
		--disable-mpl-subset \
		--exec-prefix=${PREFIX} \
		--with-boost=${LOCALBASE} \
		--with-build-version="FreeBSD ports ${PKGVERSION}" \
		--with-external-dict-dir=${LOCALBASE}/share/hunspell \
		--with-external-hyph-dir=${LOCALBASE}/share/hyphen \
		--with-external-tar=${DISTDIR}/${DIST_SUBDIR} \
		--with-external-thes-dir=${LOCALBASE}/share/mythes \
		--with-gnu-patch=${LOCALBASE}/bin/gpatch \
		--with-os-version=${OSVERSION} \
		--with-parallelism=${MAKE_JOBS_NUMBER} \
		--with-system-abseil \
		--with-system-argon2 \
		--with-system-cppunit \
		--with-system-cuckoo \
		--with-system-curl \
		--with-system-dicts \
		--with-system-dragonbox=no \
		--with-system-frozen=no \
		--with-system-gpgmepp \
		--with-system-libfixmath=no \
		--with-system-libs \
		--with-system-libtiff \
		--with-system-libxml \
		--with-system-mdds \
		--with-system-nss \
		--with-system-openjpeg \
		--with-system-orcus \
		--with-system-zlib \
		--with-system-zxcvbn=no \
		--with-system-zxing \
		--with-tls=nss \
		--with-vendor="FreeBSD ports" \
		--without-fonts \
		--without-myspell-dicts

CONFIGURE_ENV=	DMAKE=${LOCALBASE}/bin/dmake \
		FLEX=${LOCALBASE}/bin/flex \
		CONFIG_SHELL=${LOCALBASE}/bin/bash \
		GNUTAR="${TAR}" \
		GPERF=${LOCALBASE}/bin/gperf \
		ICU_CFLAGS="`icu-config --cflags`" \
		ICU_LIBS="`icu-config --ldflags`" \
		PYTHON_CFLAGS="`${PYTHON_VERSION}-config --cflags`" \
		PYTHON_LIBS="`${PYTHON_VERSION}-config --libs`" \
		ZXING_CFLAGS="-I${LOCALBASE}/include/ZXing \
		CPLUS_INCLUDE_PATH="-I${LOCALBASE}/include \
		ac_cv_path_SED=${LOCALBASE}/bin/gsed

CONFIGURE_SHELL=	${LOCALBASE}/bin/bash
MAKE_SHELL=		${LOCALBASE}/bin/bash

MAKE_ARGS+=	TMPDIR=${WRKDIR}
MAKE_ENV+=	CXXFLAGS_WARN="${CXXFLAGS_WARN}"
MAKE_ENV+=	GNUSED=${LOCALBASE}/bin/gsed
MAKE_ENV+=	DISPLAY=
MAKE_ENV+=	verbose=1

BINARY_ALIAS=	sed=gsed

PIE_UNSAFE=	yes
#MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.options.mk>

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( \
    (${OSVERSION} >= 1400051 && ${OSVERSION} < 1400057))
BROKEN=	please update FreeBSD base system first to fix an ABI incompatibility
.endif

.if ${ARCH} == powerpc || ${ARCH} == powerpcspe || ${ARCH} == powerpc64
CONFIGURE_ARGS+=	--disable-skia
.endif

.if ${PORT_OPTIONS:MGTK3} && ${PORT_OPTIONS:MKF5}
CONFIGURE_ARGS+=	--enable-gtk3-kde5
.endif

.if ${PORT_OPTIONS:MLTO} && ${CHOSEN_COMPILER_TYPE} == clang && ${COMPILER_VERSION} < 130
LLVM_DEFAULT=	13
CPP=	${LOCALBASE}/bin/clang-cpp${LLVM_DEFAULT}
CC=	${LOCALBASE}/bin/clang${LLVM_DEFAULT}
CXX=	${LOCALBASE}/bin/clang++${LLVM_DEFAULT}
BUILD_DEPENDS+=	${LOCALBASE}/bin/clang${LLVM_DEFAULT}:devel/llvm${LLVM_DEFAULT}
LLD_UNSAFE=	yes
.endif

.if ${CHOSEN_COMPILER_TYPE} == clang
CXXFLAGS_WARN=	-Woverloaded-virtual -Wno-c++11-narrowing \
		-Wno-unused-parameter -Wno-unused-local-typedefs
.else
CXXFLAGS_WARN=	-Wshadow -Woverloaded-virtual
.endif

LDFLAGS+=	-Wl,--undefined-version

post-patch:
.if ${COMPILER_FEATURES:Mlibstdc++}
	${REINPLACE_CMD} -e 's/gb_CC/gb_CXX/' ${WRKSRC}/solenv/gbuild/platform/unxgcc.mk
.endif
	${CP} ${FILESDIR}/powerpc64le-skia.patch.0 ${WRKSRC}/external/skia/

pre-configure:
	@${TOUCH} ${WRKSRC}/autogen.lastrun

post-configure:
	@${TOUCH} ${WRKSRC}/src.downloaded

post-install:
	@cd ${STAGEDIR}${PREFIX} && \
	${FIND} -s lib/libreoffice -type d -empty \
	    -exec ${ECHO_CMD} "@dir {}" \; >> ${TMPPLIST}
	@cd ${STAGEDIR}${PREFIX} && \
	${FIND} -s bin lib -not -type d >> ${TMPPLIST}
.for subdir in applications bash-completion icons man metainfo mime
	@cd ${STAGEDIR}${PREFIX} && \
	${FIND} -s share/${subdir} -not -type d >> ${TMPPLIST}
.endfor

post-install-SDK-on:
.for subdir in share share/doc
	@cd ${STAGEDIR}${PREFIX} && \
	${FIND} -s ${subdir}/libreoffice -type d -empty \
	    -exec ${ECHO_CMD} "@dir {}" \; >> ${TMPPLIST}
.endfor
.for subdir in include share share/doc
	@cd ${STAGEDIR}${PREFIX} && \
	${FIND} -s ${subdir}/libreoffice -not -type d >> ${TMPPLIST}
.endfor

.include <bsd.port.post.mk>
