# $FreeBSD$

.include "${.CURDIR}/Makefile.common"

PORTREVISION=	5

COMMENT=	Full integrated office productivity suite

BUILD_DEPENDS=	p5-Archive-Zip>=0:${PORTSDIR}/archivers/p5-Archive-Zip \
		unzip:${PORTSDIR}/archivers/unzip \
		zip:${PORTSDIR}/archivers/zip \
		${LOCALBASE}/lib/libboost_regex.a:${PORTSDIR}/devel/boost-libs \
		${LOCALBASE}/libdata/pkgconfig/cppunit.pc:${PORTSDIR}/devel/cppunit \
		dmake:${PORTSDIR}/devel/dmake \
		${LOCALBASE}/bin/gperf:${PORTSDIR}/devel/gperf \
		mdds>=0.9.0:${PORTSDIR}/devel/mdds \
		gpatch:${PORTSDIR}/devel/patch \
		ucpp:${PORTSDIR}/devel/ucpp \
		vigra-config:${PORTSDIR}/graphics/vigra \
		bash:${PORTSDIR}/shells/bash \
		${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex \
		gsed:${PORTSDIR}/textproc/gsed

LIB_DEPENDS=	libicutu.so:${PORTSDIR}/devel/icu \
		liblangtag.so:${PORTSDIR}/devel/liblangtag \
		liborcus-0.6.so:${PORTSDIR}/devel/liborcus \
		libcurl.so:${PORTSDIR}/ftp/curl \
		libcairo.so:${PORTSDIR}/graphics/cairo \
		libgraphite2.so:${PORTSDIR}/graphics/graphite2 \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		liblcms2.so:${PORTSDIR}/graphics/lcms2 \
		libcdr-0.0.so:${PORTSDIR}/graphics/libcdr \
		libfreehand-0.0.so:${PORTSDIR}/graphics/libfreehand00 \
		libwpg-0.2.so:${PORTSDIR}/graphics/libwpg \
		libpng15.so:${PORTSDIR}/graphics/png \
		libpoppler.so:${PORTSDIR}/graphics/poppler \
		liblpsolve55.so:${PORTSDIR}/math/lp_solve \
		libcmis-0.4.so:${PORTSDIR}/net/libcmis \
		libharfbuzz.so:${PORTSDIR}/print/harfbuzz \
		libmspub-0.0.so:${PORTSDIR}/print/libmspub \
		libnss3.so:${PORTSDIR}/security/nss \
		libclucene-core.so:${PORTSDIR}/textproc/clucene \
		libexpat.so:${PORTSDIR}/textproc/expat2 \
		libhunspell-1.3.so:${PORTSDIR}/textproc/hunspell \
		libhyphen.so:${PORTSDIR}/textproc/hyphen \
		libabw-0.0.so:${PORTSDIR}/textproc/libabw00 \
		libe-book-0.0.so:${PORTSDIR}/textproc/libe-book00 \
		libexttextcat-2.0.so:${PORTSDIR}/textproc/libexttextcat \
		libmwaw-0.2.so:${PORTSDIR}/textproc/libmwaw \
		libodfgen-0.0.so:${PORTSDIR}/textproc/libodfgen \
		libvisio-0.0.so:${PORTSDIR}/textproc/libvisio \
		libwpd-0.9.so:${PORTSDIR}/textproc/libwpd \
		libwps-0.2.so:${PORTSDIR}/textproc/libwps \
		libxml2.so:${PORTSDIR}/textproc/libxml2 \
		libxslt.so:${PORTSDIR}/textproc/libxslt \
		libmythes-1.2.so:${PORTSDIR}/textproc/mythes \
		librdf.so:${PORTSDIR}/textproc/redland

RUN_DEPENDS=	${LOCALBASE}/lib/X11/fonts/Caladea/Caladea-Bold.ttf:${PORTSDIR}/x11-fonts/crosextrafonts-caladea-ttf \
		${LOCALBASE}/lib/X11/fonts/Carlito/Carlito-Bold.ttf:${PORTSDIR}/x11-fonts/crosextrafonts-carlito-ttf \
		${LOCALBASE}/lib/X11/fonts/dejavu/DejaVuSans.ttf:${PORTSDIR}/x11-fonts/dejavu \
		${LOCALBASE}/lib/X11/fonts/GentiumBasic/GenBasI.ttf:${PORTSDIR}/x11-fonts/gentium-basic \
		${LOCALBASE}/lib/X11/fonts/Liberation/LiberationMono-Bold.ttf:${PORTSDIR}/x11-fonts/liberation-fonts-ttf \
		${LOCALBASE}/lib/X11/fonts/LinLibertineG/LinLibertine_DR_G.ttf:${PORTSDIR}/x11-fonts/linuxlibertine-g

_MAKE_JOBS=	#

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf aclocal
USE_GL=		gl glu
USE_OPENLDAP=	yes
USE_PERL5=	build
USE_PYTHON=	yes
USE_QT4=	# empty but required
USE_XORG=	xaw xrandr
USES=		bison compiler:c++11-lang gmake perl5 pkgconfig shared-mime-info tar:xz
WANT_GNOME=	yes

DISTFILES+=	${PORTNAME}-${LOVERSION}${EXTRACT_SUFX}
DISTFILES+=	${PORTNAME}-help-${LOVERSION}${EXTRACT_SUFX}

EXTRA_PATCHES+=	${FILESDIR}/extra-fix-ldl:-p1

EXTRACT_ONLY:=	${DISTFILES}

DISTFILES+=	1f24ab1d39f4a51faf22244c94a6203f-xmlsec1-1.2.14.tar.gz:src

DIST_SUBDIR=	libreoffice
WRKSRC=		${WRKDIR}/${PORTNAME}-${LOVERSION}

CONFIGURE_ENV=		DMAKE=${LOCALBASE}/bin/dmake \
			GNUTAR=${TAR} \
			GPERF=${LOCALBASE}/bin/gperf \
			FLEX=${LOCALBASE}/bin/flex \
			PYTHON_CFLAGS="`${PYTHON_VERSION}-config --cflags`" \
			PYTHON_LIBS="`${PYTHON_VERSION}-config --libs`" \
			TMPDIR=${WRKDIR} \
			OPENSSL_CFLAGS="-I/usr/include" \
			OPENSSL_LIBS="-lcrypto -lssl"

CONFIGURE_ARGS+=	--disable-dependency-tracking \
			--disable-fetch-external \
			--disable-online-update \
			--exec-prefix=${PREFIX} \
			--with-build-version="FreeBSD ports ${PKGVERSION}" \
			--with-external-tar=${DISTDIR}/${DIST_SUBDIR} \
			--with-gnu-patch=${LOCALBASE}/bin/gpatch \
			--with-os-version=${OSVERSION} \
			--with-parallelism=${MAKE_JOBS_NUMBER} \
			--with-solver-and-workdir-root=${WRKDIR} \
			--with-vendor="FreeBSD ports ${PKGVERSION}"

CONFIGURE_ARGS+=	--disable-epm \
			--disable-firebird-sdbc \
			--disable-gnome-vfs \
			--disable-gstreamer \
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
			--with-system-boost \
			--with-system-cairo \
			--with-system-clucene \
			--with-system-cppunit \
			--with-system-curl \
			--with-system-dicts \
			--with-system-expat \
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
			--with-system-liblangtag \
			--with-system-libmspub \
			--with-system-libmwaw \
			--with-system-libodfgen \
			--with-system-libpng \
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
			--with-system-openldap \
			--with-system-openssl \
			--with-system-orcus \
			--with-system-poppler \
			--with-system-postgresql \
			--with-system-redland \
			--with-system-ucpp \
			--with-system-vigra \
			--with-system-zlib \
			--without-afms \
			--without-fonts \
			--without-myspell-dicts \
			--without-system-npapi-headers

#XXX add: --with-system-libeot or --with-system-libatomic_ops

OPTIONS_DEFINE=	CUPS DEBUG GNOME GTK2 GTK3 JAVA KDE4 MMEDIA PGSQL SDK \
		SYSTRAY TEST VERBOSE WEBDAV
OPTIONS_DEFAULT=CUPS GTK2

JAVA_DESC=	Add java support (XML Filters, macros)
MMEDIA_DESC=	Enable multimedia backend for impress
PGSQL_DESC=	Build with PostgreSQL-SDBC driver
SDK_DESC=	Build with SDK
SYSTRAY_DESC=	Enable systemtray quickstarter
TEST_DESC=	Run all regression tests
VERBOSE_DESC=	Increase build verbosity
WEBDAV_DESC=	Enable webdav protocol

CUPS_LIB_DEPENDS=	libcups.so:${PORTSDIR}/print/cups-client
CUPS_CONFIGURE_ENABLE=	cups

DEBUG_CONFIGURE_ON=	--enable-crashdump --enable-dbgutil --enable-debug
DEBUG_CONFIGURE_OFF=	--enable-release-build

GNOME_LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib
GNOME_USE=	GNOME=gconf2
GNOME_CONFIGURE_ENABLE=	dbus gconf gio lockdown

GTK3_USE=		GNOME=gtk30
GTK3_CONFIGURE_ENABLE=	gtk3

JAVA_CATEGORIES=	java
JAVA_DISTFILES=	17410483b5b5f267aa18b7e00b65e6e0-hsqldb_1_8_0.zip:src \
		2c9b0f83ed5890af02c0df1c1776f39b-commons-httpclient-3.1-src.tar.gz:src \
		2e482c7567908d334785ce7d69ddfff7-commons-codec-1.6-src.tar.gz:src \
		3404ab6b1792ae5f16bbd603bd1e1d03-libformula-1.1.7.zip:src \
		35c94d2df8893241173de1d16b6034c0-swingExSrc.zip:src \
		39bb3fcea1514f1369fcfc87542390fd-sacjava-1.3.zip:src \
		3bdf40c0d199af31923e900d082ca2dd-libfonts-1.1.6.zip:src \
		3c219630e4302863a9a83d0efde889db-commons-logging-1.1.1-src.tar.gz:src \
		625ff5f2f968dd908bca43c9469d6e6b-commons-lang-2.4-src.tar.gz:src \
		798b2ffdc8bcfe7bca2cf92b62caf685-rhino1_5R5.zip:src \
		8ce2fcd72becf06c41f7201d15373ed9-librepository-1.1.6.zip:src \
		97b2d4dba862397f446b217e2b623e71-libloader-1.1.6.zip:src \
		a7983f859eafb2677d7ff386a023bc40-xsltml_2.1.2.zip:src \
		ace6ab49184e329db254e454a010f56d-libxml-1.1.7.zip:src \
		ba2930200c9f019c2d93a8c88c651a0f-flow-engine-0.9.4.zip:src \
		d8bd5eed178db6e2b18eeed243f85aa8-flute-1.1.6.zip:src \
		db60e4fde8dd6d6807523deb71ee34dc-liblayout-0.2.10.zip:src \
		ea570af93c284aa9e5621cd563f54f4d-bsh-2.0b1-src.tar.gz:src \
		eeb2c7ddf0d302fba4bfc6e97eac9624-libbase-1.1.6.zip:src \
		f94d9870737518e3b597f9265f4e9803-libserializer-1.1.6.zip:src
JAVA_BUILD_DEPENDS=	ant:${PORTSDIR}/devel/apache-ant \
			${JAVAJARDIR}/junit.jar:${PORTSDIR}/java/junit
# XXX jni.h from GNU classpath causes ABI conflicts.
JAVA_CONFLICTS_BUILD=	classpath-[0-9]*
JAVA_CONFIGURE_ON=	--enable-ext-wiki-publisher \
			--enable-report-builder \
			--with-ant-home=${LOCALBASE}/share/java/apache-ant \
			--with-jdk-home=${JAVA_HOME} \
			--with-junit=${JAVAJARDIR}/junit.jar
JAVA_CONFIGURE_OFF=	--without-java
# LibreOffice works only with Java 6 -- which may not be the default
# if you specify the JAVA_VENDOR variable
JAVA_BUILD=	yes
JAVA_VERSION=	1.6
JAVA_USE=	JAVA=yes

KDE4_USE=	KDE4=kdelibs QT4=moc_build QT4=qmake_build
KDE4_CONFIGURE_ENABLE=	kde4
KDE4_CONFIGURE_ENV=	KDE4DIR="${KDE4_PREFIX}" \
			QT4DIR="${QT_PREFIX}" \
			QT4INC="${QT_INCDIR}" \
			QT4LIB="${QT_LIBDIR}"

MMEDIA_USE=	GSTREAMER=yes
MMEDIA_CONFIGURE_ENABLE=	gstreamer-0-10

PGSQL_USES=	pgsql:9.0+
PGSQL_CONFIGURE_ENABLE=	postgresql-sdbc
PGSQL_CONFIGURE_WITH=	gssapi krb5

SDK_DISTFILES=	185d60944ea767075d27247c3162b3bc-unowinreg.dll:ext
SDK_BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen
SDK_CONFIGURE_ENABLE=	odk
SDK_CONFIGURE_ON=	--with-doxygen=${LOCALBASE}/bin/doxygen
SDK_CONFIGURE_OFF=	--without-doxygen

SYSTRAY_CONFIGURE_ENABLE=	systray

TEST_CONFIGURE_ENABLE=	cve-tests

WEBDAV_LIB_DEPENDS=	libneon.so:${PORTSDIR}/www/neon29
WEBDAV_CONFIGURE_ENABLE=	neon

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
IGNORE=			is broken with DEBUG option
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
INSTALLS_ICONS=	yes
.endif

.if empty(PORT_OPTIONS:MTEST)
EXTRA_PATCHES+=		${FILESDIR}/disable-cppunittester
.endif

.include <bsd.port.pre.mk>

.if ${CXX:M${LOCALBASE}/bin/clang++*}
USE_BINUTILS=	yes
LDFLAGS=	-B${LOCALBASE}/bin
.endif

.if ${COMPILER_FEATURES:Mlibc++}
EXTRA_PATCHES+=	${FILESDIR}/extra-libc++:-p1
EXTRA_PATCHES+=	${FILESDIR}/extra-libc++.i386:-p0
.endif

.if ${OSVERSION} < 900506
CONFIGURE_ARGS+=	--with-linker-hash-style=sysv
.endif

ACLOCAL_ARGS=	-I "${WRKSRC}/m4"
CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAKE_ENV+=	ENVCFLAGS="${CFLAGS}" ENVCFLAGSCXX="${CXXFLAGS}"
MAKE_ENV+=	ENVLINKFLAGS="${LDFLAGS}"
MAKE_ENV+=	LANG=C LC_ALL=C
MAKE_ENV+=	SED="${LOCALBASE}/bin/gsed" USE_GMAKE=1

INSTALL_TARGET= distro-pack-install

pre-configure:
	@${TOUCH} ${WRKSRC}/autogen.lastrun

post-configure:
	@${TOUCH} ${WRKSRC}/src.downloaded

post-install:
	@${RM} -f ${PLISTD} ${PLISTF}
	# It seems that the empty directories are necessary for libreoffice keep them for now
	@cd ${STAGEDIR}${PREFIX} && ${FIND} -d lib/libreoffice -type d \
	    -empty -exec ${ECHO_CMD} "@exec ${MKDIR} %D/{}" \; >> ${PLISTD}

	@cd ${STAGEDIR}${PREFIX} && ${FIND} -H -s bin etc lib man \
	    \( -type f -o -type l \) -print >> ${PLISTF}
	@cd ${STAGEDIR}${PREFIX} && ${FIND} -d lib/libreoffice -type d \
	    -exec ${ECHO_CMD} "@dirrm {}" \; >> ${PLISTD}
	@${ECHO_CMD} "@dirrmtry etc/bash_completion.d" >> ${PLISTD}

	@cd ${STAGEDIR}${PREFIX} && ${FIND} -H -s share/applications \
	    \( -type f -o -type l \) -print >> ${PLISTF}
.for subdir in icons mime mimelnk
	@cd ${STAGEDIR}${PREFIX} && ${FIND} -H -s share/${subdir} \
	    \( -type f -o -type l \) -print >> ${PLISTF}
	@cd ${STAGEDIR}${PREFIX} && ${FIND} -d share/${subdir} -type d \
	    -exec ${ECHO_CMD} "@dirrmtry {}" \; >> ${PLISTD}
.endfor
# do not add the subdir itself as dirrmtry
.for subdir in application-registry mime-info
	@cd ${STAGEDIR}${PREFIX} && ${FIND} -H -s share/${subdir} \
	    \( -type f -o -type l \) -print >> ${PLISTF}
.endfor

# XXX INSTALLS_ICONS does not work here, i.e., it runs *before* post-install.
.if defined(INSTALLS_ICONS)
	@for i in `${GREP} "^share/icons/.*/" ${PLISTF} | ${CUT} -d / -f 1-3 | ${SORT} -u`; do \
		${ECHO_CMD} "@unexec /bin/rm %D/$${i}/icon-theme.cache 2>/dev/null || /usr/bin/true" \
			>> ${TMPPLIST}.icons1; \
		${ECHO_CMD} "@exec ${LOCALBASE}/bin/gtk-update-icon-cache -q -f %D/$${i} 2>/dev/null || /usr/bin/true" \
			>> ${TMPPLIST}; \
		${ECHO_CMD} "@unexec ${LOCALBASE}/bin/gtk-update-icon-cache -q -f %D/$${i} 2>/dev/null || /usr/bin/true" \
			>> ${TMPPLIST}; \
	done
.endif

.if ${PORT_OPTIONS:MSDK}
.for subdir in include share share/doc share/idl
	@cd ${STAGEDIR}${PREFIX} && ${FIND} -H -s ${subdir}/libreoffice \
	    \( -type f -o -type l \) -print >> ${PLISTF}
	@cd ${STAGEDIR}${PREFIX} && ${FIND} -d ${subdir}/libreoffice \
	    -type d -exec echo "@dirrm {}" \; >> ${PLISTD}
.endfor
	@${ECHO_CMD} "@dirrmtry share/idl" >> ${PLISTD}
.endif

	@${SORT} -u ${PLISTF} >> ${TMPPLIST}
	@${GREP} '^@exec ' ${PLISTD} | ${SORT} -u >> ${TMPPLIST}
	@${GREP} '^@dirrm ' ${PLISTD} | ${SORT} -ru >> ${TMPPLIST}
	@${GREP} '^@dirrmtry ' ${PLISTD} | ${SORT} -ru | \
	    ${SED} -e '${PLIST_REINPLACE_DIRRMTRY}' >> ${TMPPLIST}

.include <bsd.port.post.mk>
