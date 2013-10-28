# $FreeBSD$

.include "${.CURDIR}/Makefile.common"

PORTREVISION=	1

COMMENT=	Full integrated office productivity suite

BUILD_DEPENDS=	p5-Archive-Zip>=0:${PORTSDIR}/archivers/p5-Archive-Zip \
		unzip:${PORTSDIR}/archivers/unzip \
		zip:${PORTSDIR}/archivers/zip \
		${LOCALBASE}/lib/libboost_regex.a:${PORTSDIR}/devel/boost-libs \
		${LOCALBASE}/lib/libcppunit.so:${PORTSDIR}/devel/cppunit \
		dmake:${PORTSDIR}/devel/dmake \
		${LOCALBASE}/bin/gperf:${PORTSDIR}/devel/gperf \
		mdds>=0.9.0:${PORTSDIR}/devel/mdds \
		gpatch:${PORTSDIR}/devel/patch \
		ucpp:${PORTSDIR}/devel/ucpp \
		vigra-config:${PORTSDIR}/graphics/vigra \
		bash:${PORTSDIR}/shells/bash \
		gsed:${PORTSDIR}/textproc/gsed

LIB_DEPENDS=	libicutu.so:${PORTSDIR}/devel/icu \
		liblangtag.so:${PORTSDIR}/devel/liblangtag \
		liborcus-0.6.so:${PORTSDIR}/devel/liborcus \
		libcurl.so:${PORTSDIR}/ftp/curl \
		libcairo.so:${PORTSDIR}/graphics/cairo \
		libgraphite2.so:${PORTSDIR}/graphics/graphite2 \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libcdr-0.0.so:${PORTSDIR}/graphics/libcdr \
		liblcms2.so:${PORTSDIR}/graphics/lcms2 \
		libwpg-0.2.so:${PORTSDIR}/graphics/libwpg \
		libpng15.so:${PORTSDIR}/graphics/png \
		libpoppler.so:${PORTSDIR}/graphics/poppler \
		liblpsolve55.so:${PORTSDIR}/math/lp_solve \
		libcmis-0.4.so:${PORTSDIR}/net/libcmis \
		libmspub-0.0.so:${PORTSDIR}/print/libmspub \
		libnss3.so:${PORTSDIR}/security/nss \
		libclucene-core.so:${PORTSDIR}/textproc/clucene \
		libexpat.so:${PORTSDIR}/textproc/expat2 \
		libhunspell-1.3.so:${PORTSDIR}/textproc/hunspell \
		libhyphen.so:${PORTSDIR}/textproc/hyphen \
		libexttextcat-2.0.so:${PORTSDIR}/textproc/libexttextcat \
		libvisio-0.0.so:${PORTSDIR}/textproc/libvisio \
		libxml2.so:${PORTSDIR}/textproc/libxml2 \
		libxslt.so:${PORTSDIR}/textproc/libxslt \
		libwpd-0.9.so:${PORTSDIR}/textproc/libwpd \
		libwps-0.2.so:${PORTSDIR}/textproc/libwps \
		libmythes-1.2.so:${PORTSDIR}/textproc/mythes \
		librdf.so:${PORTSDIR}/textproc/redland

RUN_DEPENDS=	${LOCALBASE}/lib/X11/fonts/dejavu/DejaVuSans.ttf:${PORTSDIR}/x11-fonts/dejavu \
		${LOCALBASE}/lib/X11/fonts/GentiumBasic/GenBasI.ttf:${PORTSDIR}/x11-fonts/gentium-basic \
		${LOCALBASE}/lib/X11/fonts/Liberation/LiberationMono-Bold.ttf:${PORTSDIR}/x11-fonts/liberation-fonts-ttf \
		${LOCALBASE}/lib/X11/fonts/LinLibertineG/LinLibertine_DR_G.ttf:${PORTSDIR}/x11-fonts/linuxlibertine-g

CONFLICTS_INSTALL=	libreoffice-legacy-[0-9]*

_MAKE_JOBS=	#

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf aclocal
USE_GL=		gl glu
USE_OPENLDAP=	yes
USE_PERL5=	build
USE_PYTHON=	yes
USE_QT4=	# empty but required
USE_XORG=	xaw xrandr
USE_XZ=		yes
USES=		bison compiler:c++11-lang gmake perl5 pkgconfig
WANT_GNOME=	yes

DISTFILES+=	${PORTNAME}-${LOVERSION}${EXTRACT_SUFX}
DISTFILES+=	${PORTNAME}-help-${LOVERSION}${EXTRACT_SUFX}

EXTRACT_ONLY:=	${DISTFILES}

DISTFILES+=	1f24ab1d39f4a51faf22244c94a6203f-xmlsec1-1.2.14.tar.gz:src

DIST_SUBDIR=	libreoffice
LODESTDIR=	${WRKDIR}/loinstall
WRKSRC=		${WRKDIR}/${PORTNAME}-${LOVERSION}

CONFIGURE_ENV=		DMAKE=${LOCALBASE}/bin/dmake \
			GPERF=${LOCALBASE}/bin/gperf \
			PYTHON_CFLAGS="`${PYTHON_VERSION}-config --cflags`" \
			PYTHON_LIBS="`${PYTHON_VERSION}-config --libs`" \
			TMPDIR=${WRKDIR}

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
			--with-unix-wrapper="libreoffice" \
			--with-vendor="FreeBSD ports ${PKGVERSION}"

CONFIGURE_ARGS+=	--disable-epm \
			--disable-gnome-vfs \
			--disable-gstreamer \
			--disable-kde \
			--disable-kdeab \
			--disable-linkoo \
			--disable-mergelibs \
			--disable-zenity \
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
			--with-system-hunspell \
			--with-system-icu \
			--with-system-jpeg \
			--with-system-lcms2 \
			--with-system-libcdr \
			--with-system-libcmis \
			--with-system-libexttextcat \
			--with-system-liblangtag \
			--with-system-libmspub \
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
			--with-system-nss \
			--with-system-openldap \
			--with-system-openssl \
			--with-system-orcus \
			--with-system-poppler \
			--with-system-redland \
			--with-system-stdlibs \
			--with-system-ucpp \
			--with-system-vigra \
			--with-system-zlib \
			--without-afms \
			--without-fonts \
			--without-myspell-dicts \
			--without-system-mozilla

OPTIONS_DEFINE=	CUPS DEBUG GNOME GTK2 GTK3 JAVA KDE4 MMEDIA PGSQL SDK \
		SYSTRAY TEST WEBDAV
OPTIONS_DEFAULT=CUPS GTK2

JAVA_DESC=	Add java support (XML Filters, macros)
MMEDIA_DESC=	Enable multimedia backend for impress
PGSQL_DESC=	Build with PostgreSQL-SDBC driver
SDK_DESC=	Build with SDK
SYSTRAY_DESC=	Enable systemtray quickstarter
TEST_DESC=	Run all regression tests
WEBDAV_DESC=	Enable webdav protocol

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCUPS}
LIB_DEPENDS+=		libcups.so:${PORTSDIR}/print/cups-client
CONFIGURE_ARGS+=	--enable-cups --without-ppds
.else
CONFIGURE_ARGS+=	--disable-cups
.endif

.if ${PORT_OPTIONS:MDEBUG}
IGNORE=			known as broken
CONFIGURE_ARGS+=	--enable-debug \
			--enable-dbgutil \
			--enable-verbose \
			--enable-crashdump
.else
CONFIGURE_ARGS+=	--enable-release-build
.endif

.if ${PORT_OPTIONS:MGNOME}
LIB_DEPENDS+=		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib
USE_GNOME+=		gconf2
CONFIGURE_ARGS+=	--enable-dbus --enable-gconf --enable-gio \
			--enable-lockdown
.else
CONFIGURE_ARGS+=	--disable-dbus --disable-gconf --disable-gio \
			--disable-lockdown
.endif

.if ${PORT_OPTIONS:MGNOME} || ${PORT_OPTIONS:MGTK2}
USE_GNOME+=	gtk20
CONFIGURE_ARGS+=	--enable-gtk
.else
CONFIGURE_ARGS+=	--disable-gtk
.endif

.if ${PORT_OPTIONS:MGTK3}
USE_GNOME+=	gtk30
CONFIGURE_ARGS+=	--enable-gtk3
.else
CONFIGURE_ARGS+=	--disable-gtk3
.endif

.if ${PORT_OPTIONS:MGNOME} || ${PORT_OPTIONS:MGTK2} || ${PORT_OPTIONS:MGTK3}
USES+=		desktop-file-utils
INSTALLS_ICONS=	yes
.endif

.if ${PORT_OPTIONS:MJAVA}
# XXX jni.h from GNU classpath causes ABI conflicts.
CONFLICTS_BUILD=	classpath-[0-9]*
#additionnal distfiles needed for java
DISTFILES+=	17410483b5b5f267aa18b7e00b65e6e0-hsqldb_1_8_0.zip:src \
		2a177023f9ea8ec8bd00837605c5df1b-jakarta-tomcat-5.0.30-src.tar.gz:src \
		2ae988b339daec234019a7066f96733e-commons-lang-2.3-src.tar.gz:src \
		2c9b0f83ed5890af02c0df1c1776f39b-commons-httpclient-3.1-src.tar.gz:src \
		3404ab6b1792ae5f16bbd603bd1e1d03-libformula-1.1.7.zip:src \
		35c94d2df8893241173de1d16b6034c0-swingExSrc.zip:src \
		3c219630e4302863a9a83d0efde889db-commons-logging-1.1.1-src.tar.gz:src \
		3bdf40c0d199af31923e900d082ca2dd-libfonts-1.1.6.zip:src \
		39bb3fcea1514f1369fcfc87542390fd-sacjava-1.3.zip:src \
		798b2ffdc8bcfe7bca2cf92b62caf685-rhino1_5R5.zip:src \
		8ce2fcd72becf06c41f7201d15373ed9-librepository-1.1.6.zip:src \
		97b2d4dba862397f446b217e2b623e71-libloader-1.1.6.zip:src \
		a7983f859eafb2677d7ff386a023bc40-xsltml_2.1.2.zip:src \
		ace6ab49184e329db254e454a010f56d-libxml-1.1.7.zip:src \
		af3c3acf618de6108d65fcdc92b492e1-commons-codec-1.3-src.tar.gz:src \
		ba2930200c9f019c2d93a8c88c651a0f-flow-engine-0.9.4.zip:src \
		d8bd5eed178db6e2b18eeed243f85aa8-flute-1.1.6.zip:src \
		db60e4fde8dd6d6807523deb71ee34dc-liblayout-0.2.10.zip:src \
		ea570af93c284aa9e5621cd563f54f4d-bsh-2.0b1-src.tar.gz:src \
		eeb2c7ddf0d302fba4bfc6e97eac9624-libbase-1.1.6.zip:src \
		f94d9870737518e3b597f9265f4e9803-libserializer-1.1.6.zip:src

# LibreOffice works only with Java 6 -- which may not be the default
# if you specify the JAVA_VENDOR variable
CATEGORIES+=	java
USE_JAVA=	yes
JAVA_BUILD=	yes
JAVA_VERSION=	1.6
BUILD_DEPENDS+=	ant:${PORTSDIR}/devel/apache-ant \
		${JAVAJARDIR}/junit.jar:${PORTSDIR}/java/junit

CONFIGURE_ARGS+=	--enable-ext-report-builder \
			--enable-ext-wiki-publisher \
			--enable-scripting-beanshell \
			--enable-scripting-javascript \
			--with-ant-home=${LOCALBASE}/share/java/apache-ant/ \
			--with-jdk-home=${JAVA_HOME} \
			--with-junit=${JAVAJARDIR}/junit.jar

.else
CONFIGURE_ARGS+=	--without-java
.endif

.if ${PORT_OPTIONS:MKDE4}
USE_KDE4=	kdelibs
USE_QT4+=	moc_build qmake_build
CONFIGURE_ENV+=		QT4DIR="${QT_PREFIX}" QT4LIB="${QT_LIBDIR}" QT4INC="${QT_INCDIR}" KDE4DIR="${KDE4_PREFIX}"
CONFIGURE_ARGS+=	--enable-kde4
.else
CONFIGURE_ARGS+=	--disable-kde4
.endif

.if ${PORT_OPTIONS:MMMEDIA}
USE_GSTREAMER=	yes
CONFIGURE_ARGS+=	--enable-gstreamer-0-10
.else
CONFIGURE_ARGS+=	--disable-gstreamer-0-10
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	yes
WANT_PGSQL_VER=	90+
CONFIGURE_ARGS+=	--enable-postgresql-sdbc --with-system-postgresql
.else
CONFIGURE_ARGS+=	--disable-postgresql-sdbc \
			--without-gssapi --without-krb5
.endif

.if ${PORT_OPTIONS:MSDK}
DISTFILES+=	185d60944ea767075d27247c3162b3bc-unowinreg.dll:ext
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen
CONFIGURE_ARGS+=	--enable-odk --with-doxygen=${LOCALBASE}/bin/doxygen
.else
CONFIGURE_ARGS+=	--disable-odk
.endif

.if ${PORT_OPTIONS:MSYSTRAY}
CONFIGURE_ARGS+=	--enable-systray
.else
CONFIGURE_ARGS+=	--disable-systray
.endif

.if ${PORT_OPTIONS:MTEST}
CONFIGURE_ARGS+=	--enable-cve-tests
.else
EXTRA_PATCHES+=		${FILESDIR}/disable-cppunittester
CONFIGURE_ARGS+=	--disable-cve-tests
.endif

.if ${PORT_OPTIONS:MWEBDAV}
CONFIGURE_ARGS+=	--enable-neon --with-system-neon
LIB_DEPENDS+=	libneon.so:${PORTSDIR}/www/neon29
.else
CONFIGURE_ARGS+=	--disable-neon
.endif

.include <bsd.port.pre.mk>

.if ${CXX:M${LOCALBASE}/bin/clang++}
USE_BINUTILS=	yes
.endif

.if ${COMPILER_FEATURES:Mlibc++}
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-libc++
.endif

.if ${OSVERSION} < 900506
CONFIGURE_ARGS+=	--with-linker-hash-style=sysv
.endif

ACLOCAL_ARGS=	-I "${WRKSRC}/m4"
CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

MAKE_ENV+=	ENVCFLAGS="${CFLAGS}" ENVCXXFLAGS="${CXXFLAGS}"
MAKE_ENV+=	ENVLINKFLAGS="${LDFLAGS}"
MAKE_ENV+=	LANG=C LC_ALL=C
MAKE_ENV+=	SED="${LOCALBASE}/bin/gsed" USE_GMAKE=1

pre-configure:
	@${TOUCH} ${WRKSRC}/autogen.lastrun

post-configure:
	@${TOUCH} ${WRKSRC}/src.downloaded

do-build:
	@cd ${WRKSRC} && ${SETENV} DESTDIR="" ${MAKE_ENV} ${GMAKE}

do-install:
	@cd ${WRKSRC} && ${SETENV} DESTDIR="${LODESTDIR}" \
	    ${GMAKE} distro-pack-install

	@${RM} -f ${PLISTF} ${PLISTD}
	# It seems that the empty directories are necessary for libreoffice keep them for now
	@cd ${LODESTDIR}${PREFIX} && ${FIND} -d lib/libreoffice -type d \
	    -empty -exec ${ECHO_CMD} "@exec ${MKDIR} %D/{}" \; >> ${PLISTD}

	@cd ${LODESTDIR}${PREFIX} && ${FIND} -H -s bin lib man \
	    \( -type f -o -type l \) -print >> ${PLISTF}
	@cd ${LODESTDIR}${PREFIX} && ${FIND} -d lib/libreoffice -type d \
	    -exec ${ECHO_CMD} "@dirrm {}" \; >> ${PLISTD}

	@${ECHO_CMD} etc/bash_completion.d/libreoffice.sh >> ${PLISTF}
	@${ECHO_CMD} "@dirrmtry etc/bash_completion.d" >> ${PLISTD}

.for subdir in applications icons mime mimelnk
	@cd ${LODESTDIR}${PREFIX} && ${FIND} -H -s share/${subdir} \
	    \( -type f -o -type l \) -print >> ${PLISTF}
	@cd ${LODESTDIR}${PREFIX} && ${FIND} -d share/${subdir} -type d \
	    -exec ${ECHO_CMD} "@dirrmtry {}" \; >> ${PLISTD}
.endfor
# do not add the subdir itself as dirrmtry
.for subdir in application-registry mime-info
	@cd ${LODESTDIR}${PREFIX} && ${FIND} -H -s share/${subdir} \
	    \( -type f -o -type l \) -print >> ${PLISTF}
.endfor

.if ${PORT_OPTIONS:MSDK}
.for subdir in include share share/doc share/idl
	@cd ${LODESTDIR}${PREFIX} && ${FIND} -H -s ${subdir}/libreoffice \
	    \( -type f -o -type l \) -print >> ${PLISTF}
	@cd ${LODESTDIR}${PREFIX} && ${FIND} -d ${subdir}/libreoffice \
	    -type d -exec echo "@dirrm {}" \; >> ${PLISTD}
.endfor
	@${ECHO_CMD} "@dirrmtry share/idl" >> ${PLISTD}
.endif

	@${SORT} -u ${PLISTF} >> ${TMPPLIST}
	@${GREP} '^@exec ' ${PLISTD} | ${SORT} -u >> ${TMPPLIST}
	@${GREP} '^@dirrm ' ${PLISTD} | ${SORT} -ru >> ${TMPPLIST}
	@${GREP} '^@dirrmtry ' ${PLISTD} | ${SORT} -ru | \
	    ${SED} -e '${PLIST_REINPLACE_DIRRMTRY}' >> ${TMPPLIST}

	@cd ${LODESTDIR}${PREFIX} ; ${PAX} -rw . ${STAGEDIR}${PREFIX}
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	@${INSTALL_SCRIPT} ${LODESTDIR}/etc/bash_completion.d/libreoffice.sh \
	    ${STAGEDIR}${PREFIX}/etc/bash_completion.d

.include <bsd.port.post.mk>
