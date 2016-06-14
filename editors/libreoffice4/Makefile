# $FreeBSD$

PORTNAME=	libreoffice
PORTVERSION=	4.3.7
PORTREVISION=	3
CATEGORIES=	editors
MASTER_SITES=	http://download.documentfoundation.org/libreoffice/ \
		http://dev-www.libreoffice.org/extern/:ext \
		http://dev-www.libreoffice.org/src/:src
PKGNAMESUFFIX=	4
DISTFILES=	${PORTNAME}-${LOVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-help-${LOVERSION}${EXTRACT_SUFX}
DIST_SUBDIR=	libreoffice
EXTRACT_ONLY:=	${DISTFILES}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Full integrated office productivity suite

LICENSE=	LGPL3 MPL
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Archive-Zip>=0:archivers/p5-Archive-Zip \
		zip:archivers/zip \
		${LOCALBASE}/lib/libboost_regex.a:devel/boost-libs \
		cppunit-config:devel/cppunit \
		dmake:devel/dmake \
		${LOCALBASE}/bin/gperf:devel/gperf \
		${LOCALBASE}/include/mdds/global.hpp:devel/mdds0 \
		gpatch:devel/patch \
		ucpp:devel/ucpp \
		vigra-config:graphics/vigra \
		${LOCALBASE}/include/glm/glm.hpp:math/glm \
		bash:shells/bash \
		gsed:textproc/gsed
LIB_DEPENDS=	libapr-1.so:devel/apr1 \
		libicutu.so:devel/icu \
		liblangtag.so:devel/liblangtag \
		liborcus-0.8.so:devel/liborcus07 \
		libcurl.so:ftp/curl \
		libcairo.so:graphics/cairo \
		libgraphite2.so:graphics/graphite2 \
		liblcms2.so:graphics/lcms2 \
		libcdr-0.1.so:graphics/libcdr01 \
		libetonyek-0.1.so:graphics/libetonyek01 \
		libfreehand-0.1.so:graphics/libfreehand \
		libgltf-0.0.so:graphics/libgltf \
		libwpg-0.3.so:graphics/libwpg03 \
		libGeneratedSaxParser.so:graphics/opencollada \
		libpng.so:graphics/png \
		libpoppler.so:graphics/poppler \
		liblpsolve55.so:math/lp_solve \
		libcmis-0.5.so:net/libcmis \
		libharfbuzz.so:print/harfbuzz \
		libmspub-0.1.so:print/libmspub01 \
		libnss3.so:security/nss \
		libclucene-core.so:textproc/clucene \
		libexpat.so:textproc/expat2 \
		libhunspell-1.3.so:textproc/hunspell \
		libhyphen.so:textproc/hyphen \
		libabw-0.1.so:textproc/libabw \
		libe-book-0.1.so:textproc/libe-book \
		libexttextcat-2.0.so:textproc/libexttextcat \
		libmwaw-0.3.so:textproc/libmwaw03 \
		libodfgen-0.1.so:textproc/libodfgen01 \
		librevenge-0.0.so:textproc/librevenge \
		libvisio-0.1.so:textproc/libvisio01 \
		libwpd-0.10.so:textproc/libwpd010 \
		libwps-0.3.so:textproc/libwps03 \
		libxml2.so:textproc/libxml2 \
		libxslt.so:textproc/libxslt \
		libmythes-1.2.so:textproc/mythes \
		librdf.so:textproc/redland \
		libserf-1.so:www/serf
RUN_DEPENDS=	${LOCALBASE}/share/fonts/Caladea/Caladea-Bold.ttf:x11-fonts/crosextrafonts-caladea-ttf \
		${LOCALBASE}/share/fonts/Carlito/Carlito-Bold.ttf:x11-fonts/crosextrafonts-carlito-ttf \
		${LOCALBASE}/share/fonts/dejavu/DejaVuSans.ttf:x11-fonts/dejavu \
		${LOCALBASE}/share/fonts/GentiumBasic/GenBasI.ttf:x11-fonts/gentium-basic \
		${LOCALBASE}/share/fonts/Liberation/LiberationMono-Bold.ttf:x11-fonts/liberation-fonts-ttf \
		${LOCALBASE}/share/fonts/LinLibertineG/LinLibertine_DR_G.ttf:x11-fonts/linuxlibertine-g

CONFLICTS_INSTALL=	libreoffice-5.*
ONLY_FOR_ARCHS=	amd64 i386

_MAKE_JOBS=	#

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf aclocal
USE_GL=		gl glew glu
USE_OPENLDAP=	yes
USE_PERL5=	build
USE_QT4=	# empty but required
USE_XORG=	xaw xrandr
USES=		bison compiler:c++11-lang cpe gmake jpeg perl5 pkgconfig python shared-mime-info tar:xz
WANT_GNOME=	yes

LOVERSION=	${PORTVERSION}.${RCVER}
RCVER=		2

DISTFILES+=	1f24ab1d39f4a51faf22244c94a6203f-xmlsec1-1.2.14.tar.gz:src \
		4b87018f7fff1d054939d19920b751a0-collada2gltf-master-cb1d97788a.tar.bz2:src

EXTRA_PATCHES=	${FILESDIR}/enable-opencollada:-p1
WRKSRC=		${WRKDIR}/${PORTNAME}-${LOVERSION}

COLLADA_MODS=		COLLADABaseUtils COLLADAFramework \
			COLLADASaxFrameworkLoader GeneratedSaxParser
COLLADA_CFLAGS=		${COLLADA_MODS:S|^|-I${LOCALBASE}/include/opencollada/|}
COLLADA_LIBS=		-L${LOCALBASE}/lib/opencollada \
			${COLLADA_MODS:S|^COLLADA|OpenCOLLADA|:S|^|-l|}

CONFIGURE_ENV=		DMAKE=${LOCALBASE}/bin/dmake \
			GNUTAR="${TAR}" \
			GPERF=${LOCALBASE}/bin/gperf \
			OPENCOLLADA_CFLAGS="${COLLADA_CFLAGS}" \
			OPENCOLLADA_LIBS="${COLLADA_LIBS}" \
			PYTHON_CFLAGS="`${PYTHON_VERSION}-config --cflags`" \
			PYTHON_LIBS="`${PYTHON_VERSION}-config --libs`"

CONFIGURE_ARGS+=	--disable-dependency-tracking \
			--disable-fetch-external \
			--disable-online-update \
			--exec-prefix=${PREFIX} \
			--with-build-version="FreeBSD ports ${PKGVERSION}" \
			--with-external-tar=${DISTDIR}/${DIST_SUBDIR} \
			--with-gnu-patch=${LOCALBASE}/bin/gpatch \
			--with-os-version=${OSVERSION} \
			--with-parallelism=${MAKE_JOBS_NUMBER} \
			--with-vendor="FreeBSD ports"

CONFIGURE_ARGS+=	--disable-coinmp \
			--disable-epm \
			--disable-firebird-sdbc \
			--disable-gnome-vfs \
			--disable-gstreamer-0-10 \
			--disable-kde \
			--disable-kdeab \
			--disable-mergelibs \
			--disable-packagekit \
			--enable-cairo-canvas \
			--enable-graphite \
			--enable-python=system \
			--with-alloc=system \
			--with-external-dict-dir=${LOCALBASE}/share/hunspell \
			--with-external-hyph-dir=${LOCALBASE}/share/hyphen \
			--with-external-thes-dir=${LOCALBASE}/share/mythes \
			--with-system-altlinuxhyph \
			--with-system-apr \
			--with-system-boost \
			--with-system-cairo \
			--with-system-clucene \
			--with-system-cppunit \
			--with-system-curl \
			--with-system-dicts \
			--with-system-expat \
			--with-system-glew \
			--with-system-glm \
			--with-system-graphite \
			--with-system-harfbuzz \
			--with-system-hunspell \
			--with-system-icu \
			--with-system-jpeg \
			--with-system-lcms2 \
			--with-system-libabw \
			--with-system-libcdr \
			--with-system-libcmis \
			--with-system-libebook \
			--with-system-libetonyek \
			--with-system-libexttextcat \
			--with-system-libfreehand \
			--with-system-libgltf \
			--with-system-liblangtag \
			--with-system-libmspub \
			--with-system-libmwaw \
			--with-system-libodfgen \
			--with-system-libpng \
			--with-system-librevenge \
			--with-system-libvisio \
			--with-system-libwpd \
			--with-system-libwpg \
			--with-system-libwps \
			--with-system-libxml \
			--with-system-lpsolve \
			--with-system-mdds \
			--with-system-mesa-headers \
			--with-system-mythes \
			--with-system-neon \
			--with-system-nss \
			--with-system-opencollada \
			--with-system-openldap \
			--with-system-openssl \
			--with-system-orcus \
			--with-system-poppler \
			--with-system-postgresql \
			--with-system-redland \
			--with-system-serf \
			--with-system-ucpp \
			--with-system-vigra \
			--with-system-zlib \
			--without-fonts \
			--without-myspell-dicts \
			--without-system-npapi-headers

#XXX add: --with-system-libeot or --with-system-libatomic_ops

OPTIONS_DEFINE=	CUPS DEBUG GNOME GTK2 GTK3 JAVA KDE4 MMEDIA PGSQL SDK \
		SYSTRAY TEST VERBOSE WEBDAV
OPTIONS_DEFAULT=CUPS GTK2

JAVA_DESC=	Add Java support (XML filters, macros)
MMEDIA_DESC=	Enable multimedia backend for impress
PGSQL_DESC=	Build with PostgreSQL-SDBC driver
SDK_DESC=	Build with SDK
SYSTRAY_DESC=	Enable systemtray quickstarter
TEST_DESC=	Run all regression tests
VERBOSE_DESC=	Increase build verbosity
WEBDAV_DESC=	Enable webdav protocol

CUPS_LIB_DEPENDS=	libcups.so:print/cups
CUPS_CONFIGURE_ENABLE=	cups

DEBUG_CONFIGURE_ON=	--enable-crashdump --enable-dbgutil --enable-debug
DEBUG_CONFIGURE_OFF=	--enable-release-build

GNOME_LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib
GNOME_USE=	GNOME=gconf2
GNOME_CONFIGURE_ENABLE=	dbus gconf lockdown

GTK3_USE=		GNOME=gtk30
GTK3_CONFIGURE_ENABLE=	gtk3

JAVA_CATEGORIES=	java
JAVA_DISTFILES=	048751f3271906db5126ab76870444c4-commons-codec-1.9-src.zip:src \
		17410483b5b5f267aa18b7e00b65e6e0-hsqldb_1_8_0.zip:src \
		2c9b0f83ed5890af02c0df1c1776f39b-commons-httpclient-3.1-src.tar.gz:src \
		3404ab6b1792ae5f16bbd603bd1e1d03-libformula-1.1.7.zip:src \
		35c94d2df8893241173de1d16b6034c0-swingExSrc.zip:src \
		39bb3fcea1514f1369fcfc87542390fd-sacjava-1.3.zip:src \
		3bdf40c0d199af31923e900d082ca2dd-libfonts-1.1.6.zip:src \
		798b2ffdc8bcfe7bca2cf92b62caf685-rhino1_5R5.zip:src \
		8ab049135b2d15313da5d9f0656894a1-commons-lang3-3.3.1-src.tar.gz:src \
		8ce2fcd72becf06c41f7201d15373ed9-librepository-1.1.6.zip:src \
		97b2d4dba862397f446b217e2b623e71-libloader-1.1.6.zip:src \
		a7983f859eafb2677d7ff386a023bc40-xsltml_2.1.2.zip:src \
		ace6ab49184e329db254e454a010f56d-libxml-1.1.7.zip:src \
		ba2930200c9f019c2d93a8c88c651a0f-flow-engine-0.9.4.zip:src \
		d8bd5eed178db6e2b18eeed243f85aa8-flute-1.1.6.zip:src \
		db60e4fde8dd6d6807523deb71ee34dc-liblayout-0.2.10.zip:src \
		e8e197d628436490886d17cffa108fe3-commons-logging-1.1.3-src.tar.gz:src \
		ea570af93c284aa9e5621cd563f54f4d-bsh-2.0b1-src.tar.gz:src \
		eeb2c7ddf0d302fba4bfc6e97eac9624-libbase-1.1.6.zip:src \
		f94d9870737518e3b597f9265f4e9803-libserializer-1.1.6.zip:src
JAVA_BUILD_DEPENDS=	ant:devel/apache-ant \
			${JAVAJARDIR}/junit.jar:java/junit
# XXX jni.h from GNU classpath causes ABI conflicts.
JAVA_CONFLICTS_BUILD=	classpath-[0-9]*
JAVA_CONFIGURE_ON=	--enable-ext-wiki-publisher \
			--enable-report-builder \
			--with-ant-home=${LOCALBASE}/share/java/apache-ant \
			--with-jdk-home="${JAVA_HOME}" \
			--with-junit=${JAVAJARDIR}/junit.jar \
			--with-hamcrest=${JAVAJARDIR}/hamcrest.jar
JAVA_CONFIGURE_OFF=	--without-java
JAVA_USE=	JAVA=yes
JAVA_VARS=	JAVA_BUILD=yes

KDE4_USE=	KDE4=kdelibs QT4=moc_build,qmake_build
KDE4_CONFIGURE_ENABLE=	kde4
KDE4_CONFIGURE_ENV=	KDE4DIR="${KDE4_PREFIX}" \
			QT4DIR="${QT_PREFIX}" \
			QT4INC="${QT_INCDIR}" \
			QT4LIB="${QT_LIBDIR}"

MMEDIA_USE=	GSTREAMER1=yes
MMEDIA_CONFIGURE_ENABLE=	gstreamer

PGSQL_USES=	pgsql:9.0+
PGSQL_CONFIGURE_ENABLE=	postgresql-sdbc
PGSQL_CONFIGURE_WITH=	gssapi krb5

SDK_DISTFILES=	185d60944ea767075d27247c3162b3bc-unowinreg.dll:ext
SDK_BUILD_DEPENDS=	doxygen:devel/doxygen
SDK_CONFIGURE_ENABLE=	odk
SDK_CONFIGURE_ON=	--with-doxygen=${LOCALBASE}/bin/doxygen
SDK_CONFIGURE_OFF=	--without-doxygen

SYSTRAY_CONFIGURE_ENABLE=	systray

TEST_CONFIGURE_ENABLE=	cve-tests

WEBDAV_LIB_DEPENDS=	libneon.so:www/neon
WEBDAV_CONFIGURE_ENABLE=	neon

# for dynamic plist generation
PLISTD?=	${WRKDIR}/plist_dirs
PLISTF?=	${WRKDIR}/plist_files

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
IGNORE=			is broken with DEBUG option
.else
EXTRA_PATCHES+=		${FILESDIR}/extra-Makefile.in
.endif

.if ${PORT_OPTIONS:MDEBUG} || ${PORT_OPTIONS:MVERBOSE}
CONFIGURE_ARGS+=	--enable-verbose
.endif

.if ${PORT_OPTIONS:MGNOME} || ${PORT_OPTIONS:MGTK2}
USE_GNOME+=	gtk20
CONFIGURE_ARGS+=	--enable-gtk
.else
CONFIGURE_ARGS+=	--disable-gtk
.endif

.if ${PORT_OPTIONS:MGNOME} || ${PORT_OPTIONS:MGTK2} || ${PORT_OPTIONS:MGTK3}
USES+=		desktop-file-utils
CONFIGURE_ARGS+=	--enable-gio
INSTALLS_ICONS=	yes
.else
CONFIGURE_ARGS+=	--disable-gio
.endif

.if empty(PORT_OPTIONS:MTEST)
EXTRA_PATCHES+=		${FILESDIR}/disable-cppunittester
.endif

.include <bsd.port.pre.mk>

.if ${COMPILER_FEATURES:Mlibc++}
EXTRA_PATCHES+=	${FILESDIR}/extra-libc++:-p1
EXTRA_PATCHES+=	${FILESDIR}/extra-libc++.i386:-p0
.endif

.if ${COMPILER_FEATURES:Mlibstdc++}
EXTRA_PATCHES+=	${FILESDIR}/extra-configure.ac
.endif

.if ${OSVERSION} < 1000033
BUILD_DEPENDS+=	${LOCALBASE}/bin/flex:textproc/flex
CONFIGURE_ENV+=	FLEX=${LOCALBASE}/bin/flex
.endif

ACLOCAL_ARGS=	-I "${WRKSRC}/m4"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAKE_ENV+=	ENVCFLAGS="${CFLAGS}" ENVCFLAGSCXX="${CXXFLAGS}"
MAKE_ENV+=	ENVLINKFLAGS="${LDFLAGS}"
MAKE_ENV+=	GNUSED=${LOCALBASE}/bin/gsed
MAKE_ENV+=	LANG=C LC_ALL=C

pre-configure:
	@${TOUCH} ${WRKSRC}/autogen.lastrun

post-configure:
	@${TOUCH} ${WRKSRC}/src.downloaded

do-install:
	@cd ${WRKSRC} && ${MAKE_CMD} ${MAKE_ARGS} distro-pack-install
	@${RM} -f ${PLISTD} ${PLISTF}
	@cd ${STAGEDIR}${PREFIX} && ${FIND} -d lib/libreoffice -type d \
	    -empty -exec ${ECHO_CMD} "@dir {}" \; >> ${PLISTD}
	@cd ${STAGEDIR}${PREFIX} && ${FIND} -H -s bin etc lib man \
	    \( -type f -o -type l \) -print >> ${PLISTF}
.for subdir in application-registry applications icons mime mime-info mimelnk
	@cd ${STAGEDIR}${PREFIX} && ${FIND} -H -s share/${subdir} \
	    \( -type f -o -type l \) -print >> ${PLISTF}
.endfor
.if ${PORT_OPTIONS:MSDK}
.for subdir in include share share/doc share/idl
	@cd ${STAGEDIR}${PREFIX} && ${FIND} -H -s ${subdir}/libreoffice \
	    \( -type f -o -type l \) -print >> ${PLISTF}
.endfor
.endif
	@${SORT} -u ${PLISTF} >> ${TMPPLIST}
	@${SORT} -u ${PLISTD} >> ${TMPPLIST}

.include <bsd.port.post.mk>
