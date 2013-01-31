# $FreeBSD$

.include "${.CURDIR}/Makefile.common"

PORTREVISION=	3

MASTER_SITE_SUBDIR=	src/${PORTVERSION}/
MASTER_SITES+=	http://dev-www.libreoffice.org/src/:ext \
		http://download.go-oo.org/src/:GoOOSrc \
		http://download.go-oo.org/extern/:GoOOExtern \
		http://www.numbertext.org/linux/:OOoDTP

COMMENT=	Full integrated office productivity suite

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip \
		gpatch:${PORTSDIR}/devel/patch \
		unzip:${PORTSDIR}/archivers/unzip \
		bash:${PORTSDIR}/shells/bash \
		dmake:${PORTSDIR}/devel/dmake \
		p5-Archive-Zip>=0:${PORTSDIR}/archivers/p5-Archive-Zip \
		${LOCALBASE}/bin/gperf:${PORTSDIR}/devel/gperf \
		${LOCALBASE}/lib/libboost_regex.a:${PORTSDIR}/devel/boost-libs \
		${LOCALBASE}/include/mdds/global.hpp:${PORTSDIR}/devel/mdds \
		vigra-config:${PORTSDIR}/graphics/vigra

LIB_DEPENDS=	cairo.2:${PORTSDIR}/graphics/cairo \
		xml2.5:${PORTSDIR}/textproc/libxml2 \
		xslt.2:${PORTSDIR}/textproc/libxslt \
		expat.6:${PORTSDIR}/textproc/expat2 \
		icutu:${PORTSDIR}/devel/icu \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		curl.6:${PORTSDIR}/ftp/curl \
		hunspell-1.3.0:${PORTSDIR}/textproc/hunspell \
		mythes-1.2.0:${PORTSDIR}/textproc/mythes \
		hyphen.2:${PORTSDIR}/textproc/hyphen \
		poppler-glib.8:${PORTSDIR}/graphics/poppler-glib \
		wpd-0.9.9:${PORTSDIR}/textproc/libwpd \
		wpg-0.2.2:${PORTSDIR}/graphics/libwpg \
		wps-0.2.2:${PORTSDIR}/textproc/libwps \
		rdf.0:${PORTSDIR}/textproc/redland \
		exttextcat-2.0.0:${PORTSDIR}/textproc/libexttextcat \
		lpsolve55:${PORTSDIR}/math/lp_solve \
		cups.2:${PORTSDIR}/print/cups-client \
		visio-0.0.0:${PORTSDIR}/textproc/libvisio \
		graphite2:${PORTSDIR}/graphics/graphite2 \
		nss3.1:${PORTSDIR}/security/nss \
		SampleICC.2:${PORTSDIR}/graphics/sampleicc \
		png15:${PORTSDIR}/graphics/png \
		cmis-0.2.0:${PORTSDIR}/net/libcmis \

RUN_DEPENDS=	${LOCALBASE}/lib/X11/fonts/Liberation/LiberationMono-Bold.ttf:${PORTSDIR}/x11-fonts/liberation-fonts-ttf \
		${LOCALBASE}/lib/X11/fonts/LinLibertineG/LinLibertine_DR_G.ttf:${PORTSDIR}/x11-fonts/linuxlibertine-g \
		${LOCALBASE}/lib/X11/fonts/dejavu/DejaVuSans.ttf:${PORTSDIR}/x11-fonts/dejavu \
		${LOCALBASE}/lib/X11/fonts/GentiumBasic/GenBasI.ttf:${PORTSDIR}/x11-fonts/gentium-basic

CONFLICTS_INSTALL=	libreoffice-legacy-[0-9]*

#LO_COMPONENTS=	binfilter dictionaries help translations
LO_COMPONENTS=	help

USE_XZ=	yes
USE_PYTHON=	yes
USE_QT4=	# empty but required
#l10n

DIST_SUBDIR=	libreoffice
WRKSRC=		${WRKDIR}/${PORTNAME}-core-${LOVERSION}

LODESTDIR=	${WRKDIR}/loinstall

DISTFILES+=	${PORTNAME}-core-${LOVERSION}${EXTRACT_SUFX}
.for components in ${LO_COMPONENTS}
DISTFILES+=	${PORTNAME}-${components}-${LOVERSION}${EXTRACT_SUFX}
.endfor

EXTRACT_ONLY:=	${DISTFILES}

#DISTFILES+=	f02578f5218f217a9f20e9c30e119c6a-boost_1_44_0.tar.bz2:ext

USE_BDB=	yes
USE_PERL5_BUILD=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_BISON=	build
WANT_GNOME=	yes

USE_XORG=	xaw xrandr
USE_GL=		gl glu
MAKE_JOBS_UNSAFE=	yes
USE_GETTEXT=	yes
USE_PKGCONFIG=	build

OPTIONS_DEFINE=	WEBDAV KDE4 GTK2 GTK3 GNOME JAVA SYSTRAY MMEDIA SDK SVG DEBUG PGSQL
OPTIONS_DEFAULT=	GTK2 SVG

PGSQL_DESC=	Build with PostgreSQL-SDBC driver
SDK_DESC=	Build with SDK
MMEDIA_DESC=	Enable multimedia backend for impress
SYSTRAY_DESC=	Enable systemtray quickstarter
WEBDAV_DESC=	Enable webdav protocol
JAVA_DESC=	Add java support (XML Filters, macros)

CONFIGURE_ENV=		DMAKE=${LOCALBASE}/bin/dmake \
			GPERF=${LOCALBASE}/bin/gperf

CONFIGURE_ARGS+=	--with-unix-wrapper="libreoffice" \
			--disable-fetch-external \
			--with-build-version="FreeBSD ports ${PKGVERSION}" \
			--with-vendor="FreeBSD ports ${PKGVERSION}" \
			--exec-prefix=${PREFIX} \
			--with-gnu-patch=${LOCALBASE}/bin/gpatch \
			--with-external-tar=${DISTDIR}/${DIST_SUBDIR} \
			--with-system-boost \
			--with-system-mdds \
			--with-system-libxml \
			--with-system-cairo \
			--enable-cairo-canvas \
			--with-system-zlib \
			--with-system-icu \
			--with-system-db \
			--with-system-jpeg \
			--with-system-expat \
			--with-system-openssl \
			--with-system-curl \
			--with-system-libvisio \
			--with-system-libwpd \
			--with-system-libwpg \
			--with-system-libwps \
			--with-system-poppler \
			--with-system-redland \
			--with-system-hunspell \
			--with-system-mythes \
			--with-system-altlinuxhyph \
			--with-system-libexttextcat \
			--with-system-lpsolve \
			--with-system-vigra \
			--with-alloc=system \
			--with-system-stdlibs \
			--with-system-mesa-headers \
			--disable-epm \
			--disable-mozilla \
			--disable-build-mozilla \
			--without-system-mozilla \
			--without-fonts \
			--without-afms \
			--without-ppds \
			--without-stlport \
			--disable-kde \
			--disable-kdeab \
			--with-system-nss \
			--without-myspell-dicts \
			--with-system-dicts \
			--disable-dependency-tracking \
			--with-external-thes-dir=${LOCALBASE}/share/mythes \
			--with-external-hyph-dir=${LOCALBASE}/share/hyphen \
			--with-external-dict-dir=${LOCALBASE}/share/hunspell \
			--disable-zenity \
			--enable-graphite \
			--with-system-graphite \
			--with-system-sampleicc \
			--enable-mergelibs \
			--enable-gio  \
			--disable-nsplugin \
			--disable-linkoo \
			--disable-online-update \
			--disable-xmlsec \
			--with-system-gettext \
			--with-system-libpng \
			--with-system-postgresql \
			--with-system-libcmis \
			--disable-gnome-vfs \
			--enable-python=system

# extensions
CONFIGURE_ARGS+=	--enable-ext-pdfimport \
			--enable-ext-report-builder
#			--enable-extra-gallery \
#			--enable-extra-template \
#			--enable-extra-sample \
#			--enable-extra-font

MAN1=	lobase.1 \
	lomath.1 \
	loffice.1 \
	localc.1 \
	unopkg.1 \
	loweb.1 \
	lowriter.1 \
	libreoffice.1 \
	lodraw.1 \
	lofromtemplate.1 \
	loimpress.1

MANCOMPRESSED=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	yes
WANT_PGSQL_VER=	90+
.else
CONFIGURE_ARGS+=	--disable-postgresql-sdbc
.endif
.if empty(PORT_OPTIONS:MSYSTRAY)
CONFIGURE_ARGS+=	--disable-systray
.endif

.if ${PORT_OPTIONS:MMMEDIA}
USE_GSTREAMER=	yes
.else
CONFIGURE_ARGS+=	--disable-gstreamer
.endif

.if ${PORT_OPTIONS:MSVG}
CONFIGURE_ARGS+=	--enable-librsvg=system
USE_GNOME+=	librsvg2
.else
CONFIGURE_ARGS+=	--enable-librsvg=no
.endif

.if ${PORT_OPTIONS:MGTK2} || ${PORT_OPTIONS:MGNOME}
USE_GNOME+=	gtk20 desktopfileutils
INSTALLS_ICONS=	yes
.else
CONFIGURE_ARGS+=	--disable-gtk
.endif

.if ${PORT_OPTIONS:MGTK3}
USE_GNOME+=	gtk30 desktopfileutils
INSTALLS_ICONS=	yes
.else
CONFIGURE_ARGS+=	--disable-gtk3
.endif

.if ${PORT_OPTIONS:MWEBDAV}
CONFIGURE_ARGS+=	--enable-neon --with-system-neon
LIB_DEPENDS+=	neon.27:${PORTSDIR}/www/neon29
.else
CONFIGURE_ARGS+=	--disable-neon
.endif

.if ${PORT_OPTIONS:MKDE4}
USE_KDE4=	kdelibs
USE_QT4+=	moc_build qmake_build
CONFIGURE_ENV+=		QT4DIR="${QT_PREFIX}" QT4LIB="${QT_LIBDIR}" QT4INC="${QT_INCDIR}" KDE4DIR="${KDE4_PREFIX}"
CONFIGURE_ARGS+=	--enable-kde4
.else
CONFIGURE_ARGS+=	--disable-kde4
.endif

.if ${PORT_OPTIONS:MGNOME}
USE_GNOME+=		gconf2
CONFIGURE_ARGS+=	--enable-gconf
.else
CONFIGURE_ARGS+=	--disable-gconf --disable-lockdown
.endif

.if ${PORT_OPTIONS:MJAVA}
#additionnal distfiles needed for java
DISTFILES+=	798b2ffdc8bcfe7bca2cf92b62caf685-rhino1_5R5.zip:GoOOSrc \
		17410483b5b5f267aa18b7e00b65e6e0-hsqldb_1_8_0.zip:GoOOSrc \
		2a177023f9ea8ec8bd00837605c5df1b-jakarta-tomcat-5.0.30-src.tar.gz:GoOOSrc \
		48d8169acc35f97e05d8dcdfd45be7f2-lucene-2.3.2.tar.gz:GoOOSrc \
		a7983f859eafb2677d7ff386a023bc40-xsltml_2.1.2.zip:GoOOSrc \
		ada24d37d8d638b3d8a9985e80bc2978-source-9.0.0.7-bj.zip:GoOOSrc \
		eeb2c7ddf0d302fba4bfc6e97eac9624-libbase-1.1.6.zip:GoOOSrc \
		35c94d2df8893241173de1d16b6034c0-swingExSrc.zip:GoOOSrc \
		39bb3fcea1514f1369fcfc87542390fd-sacjava-1.3.zip:GoOOSrc \
		97b2d4dba862397f446b217e2b623e71-libloader-1.1.6.zip:GoOOSrc \
		d8bd5eed178db6e2b18eeed243f85aa8-flute-1.1.6.zip:GoOOSrc \
		3c219630e4302863a9a83d0efde889db-commons-logging-1.1.1-src.tar.gz:GoOOSrc \
		f94d9870737518e3b597f9265f4e9803-libserializer-1.1.6.zip:GoOOSrc \
		3404ab6b1792ae5f16bbd603bd1e1d03-libformula-1.1.7.zip:GoOOSrc \
		3bdf40c0d199af31923e900d082ca2dd-libfonts-1.1.6.zip:GoOOSrc \
		ace6ab49184e329db254e454a010f56d-libxml-1.1.7.zip:GoOOSrc \
		8ce2fcd72becf06c41f7201d15373ed9-librepository-1.1.6.zip:GoOOSrc \
		db60e4fde8dd6d6807523deb71ee34dc-liblayout-0.2.10.zip:GoOOSrc \
		ba2930200c9f019c2d93a8c88c651a0f-flow-engine-0.9.4.zip:GoOOSrc

# LibreOffice works only with Java 6 -- which may not be the default
# if you specify the JAVA_VENDOR variable
CATEGORIES+=	java
USE_JAVA=	yes
JAVA_VERSION=	1.6
BUILD_DEPENDS+=	ant:${PORTSDIR}/devel/apache-ant \
		${JAVAJARDIR}/junit.jar:${PORTSDIR}/java/junit \
		${JAVAJARDIR}/xercesImpl.jar:${PORTSDIR}/textproc/xerces-j \
		${JAVAJARDIR}/xalan.jar:${PORTSDIR}/textproc/xalan-j \
		${JAVAJARDIR}/bsh.jar:${PORTSDIR}/lang/bsh
RUN_DEPENDS+=	${JAVAJARDIR}/bsh.jar:${PORTSDIR}/lang/bsh

CONFIGURE_ARGS+=	--with-ant-home=${LOCALBASE}/share/java/apache-ant/ \
			--with-junit=${JAVAJARDIR}/junit.jar \
			--with-jdk-home=${JAVA_HOME} \
			--with-system-beanshell \
			--with-beanshell-jar=${JAVAJARDIR}/bsh.jar \
			--with-system-xerces \
			--with-xerces-jar=${JAVAJARDIR}/xercesImpl.jar \
			--with-system-xml-apis \
			--with-xml-apis-jar=/${JAVAJARDIR}/xml-apis.jar \
			--with-system-xalan \
			--with-xalan-jar=${JAVAJARDIR}/xalan.jar \
			--with-serializer-jar=${JAVAJARDIR}/serializer.jar
.else
BUILD_DEPENDS+=	xsltproc:${PORTSDIR}/textproc/libxslt
CONFIGURE_ARGS+=	--without-java
.endif

.if ${PORT_OPTIONS:MSDK}
DISTFILES+=	185d60944ea767075d27247c3162b3bc-unowinreg.dll:GoOOExtern

CONFIGURE_ARGS+=	--enable-odk
.else
CONFIGURE_ARGS+=	--disable-odk
.endif

.if ${PORT_OPTIONS:MDEBUG}
IGNORE=			Known as broken
CONFIGURE_ARGS+=	--enable-debug \
			--enable-dbgutil \
			--enable-verbose \
			--enable-crashdump
.else
CONFIGURE_ARGS+=	--enable-release-build
.endif

.include <bsd.port.pre.mk>

# if compiled with clang on 8.x libreoffice exits with the following error:
# terminate called after throwing an instance of 'com::sun::star::ucb::InteractiveAugmentedIOException'
.if ${OSVERSION} < 900000
WITH_GCC=	yes
.endif

.if defined(WITH_GCC)
USE_GCC=	4.6+
DISTFILES+=	bd30e9cf5523cdfc019b94f5e1d7fd19-cppunit-1.12.1.tar.gz:ext
CONFIGURE_ENV+=	CXXCPP="${CPP}"
.else
.if exists(/usr/bin/clang) && ${OSVERSION} >= 900014
CC=		/usr/bin/clang
CPP=		/usr/bin/clang-cpp
CXX=		/usr/bin/clang++
CONFIGURE_ENV+=	CXXCPP="${CPP}"
.else
# XXX Clang PR13308 (http://llvm.org/bugs/show_bug.cgi?id=13308)
BUILD_DEPENDS+=	clang-devel>=3.2.r159895:${PORTSDIR}/lang/clang-devel
USE_BINUTILS=	yes
CC=		${LOCALBASE}/bin/clang
CPP=		${CC} -E
CXX=		${LOCALBASE}/bin/clang++
CONFIGURE_ENV+=	CXXCPP="${CXX} -E"
.endif
CONFIGURE_ARGS+=	--with-system-cppunit
BUILD_DEPENDS+=	${LOCALBASE}/lib/libcppunit.so:${PORTSDIR}/devel/cppunit
.endif

.if ${OSVERSION} < 900506
CONFIGURE_ARGS+=	--with-linker-hash-style=sysv
.endif

CPPFLAGS=	-I${LOCALBASE}/include -I${LOCALBASE}/include/db${BDB_VER}
LDFLAGS=	-L${LOCALBASE}/lib

MAKE_ENV+=	ENVCFLAGS="${CFLAGS}" ENVCXXFLAGS="${CXXFLAGS}"
MAKE_ENV+=	ENVLINKFLAGS="${LDFLAGS}"
MAKE_ENV+=	USE_GMAKE=1

post-extract:
	@${MKDIR} ${WRKSRC}/clone
	@${MKDIR} ${WRKSRC}/src
.for component in ${LO_COMPONENTS}
	@${MV} ${WRKDIR}/${PORTNAME}-${component}-${LOVERSION} ${WRKSRC}/clone/${component}
.endfor
	@${TOUCH} ${WRKSRC}/clone/repos_changed

post-patch:
	@${FIND} ${WRKSRC} -type f -print0 | \
	    ${XARGS} -0 ${REINPLACE_CMD} -i '' -e 's#-Wl,-rpath,#-Wl,-z,origin,-rpath,#g'
	@${REINPLACE_CMD} -e 's#5.1 5.0#${BDB_VER}#g' \
		 -e 's,-ldb$$dash$$dbver,-l${BDB_LIB_NAME},g' \
		 -e 's,"Linux" \&\& test "z$$enable_graphite","FreeBSD" \&\& test "z$$enable_graphite",g' \
		 -e 's,`dirname $$qt_lib_dir`/bin:,,g' \
		${WRKSRC}/configure
#install-gdb-printer is failing
	@${REINPLACE_CMD} -e "/gdb/d" ${WRKSRC}/solenv/prj/build.lst
	@${REINPLACE_CMD} -e 's#@SYSTEM_DB_CFLAGS@#@SYSTEM_DB_CFLAGS@ -I${BDB_INCLUDE_DIR}#' \
			-e 's#@DB_LIB@#${BDB_LIB_NAME}#' \
			${WRKSRC}/set_soenv.in
	@${REINPLACE_CMD} -e 's/sha1sum/sha1/g' ${WRKSRC}/configure
.if ${CC} == /usr/bin/clang && ${OSVERSION} < 900506
#Visibility is broken with clang
	@${REINPLACE_CMD} -e "s|HAVE_GCC_VISIBILITY_FEATURE=TRUE|HAVE_GCC_VISIBILITY_FEATURE=|g" \
		${WRKSRC}/configure
.endif

.if ${PORT_OPTIONS:MJAVA}
	@${REINPLACE_CMD} -e 's/^ANT_OPT/#ANT_OPT/g' \
		${WRKSRC}/apache-commons/java/codec/makefile.mk \
		${WRKSRC}/apache-commons/java/httpclient/makefile.mk \
		${WRKSRC}/apache-commons/java/lang/makefile.mk \
		${WRKSRC}/apache-commons/java/logging/makefile.mk
.endif

pre-configure:
	@${TOUCH} ${WRKSRC}/autogen.lastrun

post-configure:
	@cd ${WRKSRC} && ./bin/create_bootstrap_links
	@${TOUCH} ${WRKSRC}/src.downloaded

do-install:
	@cd ${WRKSRC} && ${SETENV} DESTDIR="${LODESTDIR}" \
	    ${GMAKE} distro-pack-install

post-install:
	@${RM} -f ${PLISTF} ${PLISTD}
	# It seems that the empty directories are necessary for libreoffice keep them for now
	@cd ${LODESTDIR}/${PREFIX} && ${FIND} -d lib/libreoffice -type d -empty \
		-exec ${ECHO_CMD} "@exec ${MKDIR} %D/{}" \; >> ${PLISTD}

	@cd ${LODESTDIR}/${PREFIX} && ${FIND} -H -s lib \( -type f -o -type l \) -print >> ${PLISTF}
	@cd ${LODESTDIR}/${PREFIX} && ${FIND} -d lib/libreoffice -type d -exec ${ECHO_CMD} "@dirrm {}" \; >> ${PLISTD}

.for subdir in applications icons mime mimelnk
	@cd ${LODESTDIR}/${PREFIX} && ${FIND}  -H -s share/${subdir} \( -type f -o -type l \) -print >> ${PLISTF}
	@cd ${LODESTDIR}/${PREFIX}/ && ${FIND} -d share/${subdir} -type d \
		-exec ${ECHO_CMD} "@unexec ${RMDIR} %D/{} 2>/dev/null || ${TRUE}" \; >> ${PLISTD}
.endfor
# do not add the subdir itself as dirrmtry
.for subdir in application-registry mime-info
	@cd ${LODESTDIR}/${PREFIX} && ${FIND} -H -s share/${subdir} \( -type f -o -type l \) -print >> ${PLISTF}
	@cd ${LODESTDIR}/${PREFIX}/ && ${FIND} -d share/${subdir}/* -type d \
		-exec ${ECHO_CMD} "@unexec ${RMDIR} %D/{} 2>/dev/null || ${TRUE}" \; >> ${PLISTD}
.endfor
	@cd ${LODESTDIR}/${PREFIX} && ${FIND} -H -s bin \( -type f -o -type l \) -print >> ${PLISTF}

.if ${PORT_OPTIONS:MGTK2} || ${PORT_OPTIONS:MGNOME} || ${PORT_OPTIONS:MGTK3}
	@${ECHO_CMD} "@exec ${LOCALBASE}/bin/update-desktop-database >/dev/null || ${TRUE}" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ${LOCALBASE}/bin/update-desktop-database >/dev/null || ${TRUE}" >> ${TMPPLIST}
.endif

.if ${PORT_OPTIONS:MSDK}
.for subdir in include share/idl share/libreoffice share/doc
	@cd ${LODESTDIR}/${PREFIX} && ${FIND} -H -s ${subdir} \( -type f -o -type l \) -print >> ${PLISTF}
	@cd ${LODESTDIR}/${PREFIX} && ${FIND} -d ${subdir} -type d -exec echo "@dirrm {}" \; >> ${PLISTD}
.endfor
.endif

	@${SORT} ${PLISTF} >> ${TMPPLIST}
	@${GREP} ^@exec ${PLISTD} | ${SORT} >> ${TMPPLIST}
	@${GREP} -v ^@exec ${PLISTD} | ${SORT} -r >> ${TMPPLIST}

.if ${PORT_OPTIONS:MSDK}
.for subdir in include share/idl share/libreoffice share/doc
	@${ECHO_CMD} "@unexec ${RMDIR} %D/${subdir} 2>/dev/null || ${TRUE}" >> ${TMPPLIST}
.endfor
.endif

	@cd ${LODESTDIR}/${PREFIX} ; ${PAX} -rw . ${PREFIX}
.if ${PORT_OPTIONS:MGTK2} || ${PORT_OPTIONS:MGNOME}
	@${LOCALBASE}/bin/update-desktop-database 2>/dev/null || ${TRUE}
.endif

.include <bsd.port.post.mk>
