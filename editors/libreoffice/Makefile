# New ports collection makefile for:	libreoffice
# Date created:		2010-12-06
# Whom:			Bapt <bapt@FreeBSD.Org>
#
# $FreeBSD$
#

PORTNAME=	libreoffice
PORTVERSION=	3.4.3
PORTREVISION=	2
LOVERSION=	${PORTVERSION}.2
CATEGORIES=	editors
MASTER_SITES=	http://ftp.osuosl.org/pub/tdf/libreoffice/src/${PORTVERSION}/ \
		http://ftp.rediris.es/mirror/TDF/libreoffice/src/${PORTVERSION}/ \
		http://mirrors.supportex.net/tdf/libreoffice/src/${PORTVERSION}/ \
		http://mirror.netcologne.de/tdf/libreoffice/src/${PORTVERSION}/ \
		http://mirror.informatik.uni-mannheim.de/pub/mirrors/tdf/libreoffice/src/${PORTVERSION}/ \
		http://ftp.uni-muenster.de/pub/software/DocumentFoundation/libreoffice/src/${PORTVERSION}/ \
		http://ftp.rz.tu-bs.de/pub/mirror/tdf/tdf-pub/libreoffice/src/${PORTVERSION}/ \
		http://artfiles.org/documentfoundation.org/libreoffice/src/${PORTVERSION}/ \
		http://mirror.galpon.org/tdf/libreoffice/src/${PORTVERSION}/ \
		http://ftp.tu-chemnitz.de/pub/tdf/libreoffice/src/${PORTVERSION}/ \
		http://tdf.panu.it/libreoffice/src/${PORTVERSION}/ \
		http://ftp.wh2.tu-dresden.de/pub/mirrors/tdf/libreoffice/src/${PORTVERSION}/ \
		http://ftp.klid.dk/ftp/tdf/libreoffice/src/${PORTVERSION}/ \
		http://gd.tuwien.ac.at/tdf/libreoffice/src/${PORTVERSION}/ \
		http://archive.sunet.se/pub/Office/tdf/libreoffice/src/${PORTVERSION}/ \
		http://ftp.astral.ro/mirrors/tdf/libreoffice/src/${PORTVERSION}/ \
		http://ftp.roedu.net/mirrors/tdf/libreoffice/src/${PORTVERSION}/ \
		http://ftp.unicamp.br/pub/tdf/libreoffice/src/${PORTVERSION}/ \
		http://mirror.yongbok.net/tdf/libreoffice/src/${PORTVERSION}/ \
		http://mirror3.mirrors.tds.net/pub/documentfoundation.org/libreoffice/src/${PORTVERSION}/ \
		http://download.go-oo.org/src/:GoOOSrc \
		http://download.go-oo.org/extern/:GoOOExtern \
		http://www.numbertext.org/linux/:OOoDTP

MAINTAINER=	office@FreeBSD.org
COMMENT=	Full integrated office productivity suite

CONFLICTS_INSTALL=	libreoffice-legacy-[0-9]*

LO_COMPONENTS=	artwork base calc components extensions \
		extras filters help impress libs-core libs-extern \
		libs-extern-sys libs-gui postprocess sdk testing \
		ure writer translations

USE_BZIP2=	yes
#l10n
INSTALL_TARGET= distro-pack-install

DIST_SUBDIR=	libreoffice
DISTFILES+=	${PORTNAME}-bootstrap-${LOVERSION}${EXTRACT_SUFX}
WRKSRC=		${WRKDIR}/${PORTNAME}-bootstrap-${LOVERSION}

LODESTDIR=	${WRKDIR}/loinstall

.for components in ${LO_COMPONENTS}
DISTFILES+=	${PORTNAME}-${components}-${LOVERSION}${EXTRACT_SUFX}
.endfor

LICENSE=	LGPL3 MPL
LICENSE_COMB=	dual

# for dynamic plist generation
PLISTD?=	${WRKDIR}/plist_dirs
PLISTF?=	${WRKDIR}/plist_files

# not tested on other platforms and at leat plist will be wrong because of LOARCH not expendanded correctly
ONLY_FOR_ARCH=	i386 amd64

EXTRACT_ONLY:=	${DISTFILES}

#additionnal components
DISTFILES+=	fdb27bfe2dbe2e7b57ae194d9bf36bab-SampleICC-1.3.2.tar.gz:GoOOSrc \
		067201ea8b126597670b5eff72e1f66c-mythes-1.2.0.tar.gz:GoOOSrc \
		1756c4fa6c616ae15973c104cd8cb256-Adobe-Core35_AFMs-314.tar.gz:GoOOSrc \
		0ff7d225d087793c8c2c680d77aac3e7-mdds_0.5.3.tar.bz2:GoOOSrc \
		37282537d0ed1a087b1c8f050dc812d9-dejavu-fonts-ttf-2.32.zip:GoOOSrc \
		ca4870d899fd7e943ffc310a5421ad4d-liberation-fonts-ttf-1.06.0.20100721.tar.gz:GoOOSrc \
		35efabc239af896dfb79be7ebdd6e6b9-gentiumbasic-fonts-1.10.zip:GoOOSrc \
		881af2b7dca9b8259abbca00bbbc004d-LinLibertineG-20110101.zip:OOoDTP

# rely on bsdtar ability to extract .gz and .bz2 archives
LIB_DEPENDS=	cairo.2:${PORTSDIR}/graphics/cairo \
		xml2.5:${PORTSDIR}/textproc/libxml2 \
		xslt.2:${PORTSDIR}/textproc/libxslt \
		expat.6:${PORTSDIR}/textproc/expat2 \
		icutu.48:${PORTSDIR}/devel/icu \
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
		textcat.0:${PORTSDIR}/textproc/libtextcat \
		lpsolve55:${PORTSDIR}/math/lp_solve \
		cups.2:${PORTSDIR}/print/cups-client


# dmake can't be used from ports

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip \
		gpatch:${PORTSDIR}/devel/patch \
		unzip:${PORTSDIR}/archivers/unzip \
		bash:${PORTSDIR}/shells/bash \
		oo2po:${PORTSDIR}/textproc/translate-toolkit \
		dmake:${PORTSDIR}/devel/dmake \
		${SITE_PERL}/Archive/Zip.pm:${PORTSDIR}/archivers/p5-Archive-Zip \
		${LOCALBASE}/bin/gperf:${PORTSDIR}/devel/gperf \
		${LOCALBASE}/lib/libcppunit.so:${PORTSDIR}/devel/cppunit \
		${LOCALBASE}/lib/libboost_regex.a:${PORTSDIR}/devel/boost-libs \
		vigra-config:${PORTSDIR}/graphics/vigra

USE_BDB=	yes
USE_PERL5_BUILD=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_BISON=	build
USE_OPENSSL=	yes
WANT_GNOME=	yes
USE_XORG=	xaw xrandr
USE_GL=		gl glu
MAKE_JOBS_UNSAFE=	yes
USE_AUTOTOOLS=	autoconf automake:env

OPTIONS=	WEBDAV	"Support webdav protocol" off \
		KDE4	"With Qt4/KDE4 vclplug support" off \
		GTK	"With GTK vclplug support" on \
		GNOME	"Better integration in gnome environnement" off \
		JAVA	"Add Java support (XML Filters, macros)" off \
		PYUNO	"Allow to script libreoffice in python" off \
		SYSTRAY	"Enable systemtry quickstarter" off \
		MMEDIA	"Enable multimedia backend for impress" off \
		SDK	"Build with SDK" off \
		DEBUG	"Build with debug symbols and verbose output" off

CONFIGURE_ENV=		GPERF=${LOCALBASE}/bin/gperf \
			DMAKE=${LOCALBASE}/bin/dmake \
			OPENSSL_CFLAGS="-I${OPENSSLINC}" \
			OPENSSL_LIBS="-L${OPENSSLLIB} -lssl"

CONFIGURE_ARGS+=	--with-unix-wrapper="libreoffice" \
			--disable-fetch-external \
			--with-build-version="FreeBSD ports ${PKGVERSION}" \
			--with-vendor="FreeBSD ports ${PKGVERSION}" \
			--exec-prefix=${PREFIX} \
			--with-external-tar=${DISTDIR}/${DIST_SUBDIR} \
			--with-gnu-patch=${LOCALBASE}/bin/gpatch \
			--with-system-libxml \
			--with-system-libxslt \
			--with-system-cairo --enable-cairo \
			--with-system-boost \
			--with-system-cppunit \
			--with-system-zlib \
			--with-system-icu \
			--with-system-db \
			--with-system-jpeg \
			--with-system-expat \
			--with-system-openssl \
			--with-system-curl \
			--with-system-libwpd \
			--with-system-libwpg \
			--with-system-libwps \
			--with-system-poppler \
			--with-system-redland \
			--with-system-hunspell \
			--with-system-mythes \
			--with-system-altlinuxhyph \
			--with-system-libtextcat \
			--with-system-lpsolve \
			--with-system-vigra \
			--with-fonts \
			--with-alloc=system \
			--with-system-stdlibs \
			--with-system-xrender-headers \
			--with-system-mesa-headers \
			--disable-epm \
			--disable-mozilla \
			--disable-build-mozilla \
			--without-system-mozilla \
			--disable-kde \
			--without-stlport \
			--disable-nss-module \
			--with-system-translate-toolkit \
			--with-system-dicts \
			--disable-dependency-tracking \
			--with-external-thes-dir=${LOCALBASE}/share/mythes \
			--with-external-hyph-dir=${LOCALBASE}/share/hyphen \
			--with-external-dict-dir=${LOCALBASE}/share/hunspell \
			--disable-zenity \
			--enable-cups

.if defined(LOCALIZED_LANG)
CONFIGURE_ARGS+=	--with-lang="${LOCALIZED_LANG}"
.endif

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

MAKE_ENV+=	USE_GMAKE=1 DESTDIR=${LODESTDIR}

CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/db${BDB_VER} -L${LOCALBASE}/lib

.if defined(WITHOUT_SYSTRAY)
CONFIGURE_ARGS+=	--disable-systray
.endif

.if defined(WITH_MMEDIA)
USE_GSTREAMER=	yes
.else
CONFIGURE_ARGS+=	--disable-gstreamer
.endif

.if defined(WITH_PYUNO)
USE_PYTHON=	yes
CONFIGURE_ARGS+=	--with-system-python
.else
CONFIGURE_ARGS+= --disable-python
.endif

.if defined(WITH_GTK) || defined(WITH_GNOME)
USE_GNOME=	gtk20 desktopfileutils
INSTALLS_ICONS=	yes
.else
CONFIGURE_ARGS+=	--disable-gtk
.endif

.if defined(WITH_WEBDAV)
CONFIGURE_ARGS+=	--enable-neon --with-system-neon
LIB_DEPENDS+=	neon.27:${PORTSDIR}/www/neon29
.else
CONFIGURE_ARGS+=	--disable-neon
.endif

.if defined(WITH_KDE4)
USE_KDE4=	kdelibs
USE_QT_VER=	4
CONFIGURE_ARGS+=	--enable-kde4 QT4DIR="${QT_PREFIX}" QT4LIB="${QT_LIBDIR}" QT4INC="${QT_INCDIR}" KDE4DIR="${KDE4_PREFIX}"
QT_COMPONENTS+=		moc_build
.else
CONFIGURE_ARGS+=	--disable-kde4
.endif

.if defined(WITH_GNOME)
USE_GNOME+=		gconf2  gnomevfs2
CONFIGURE_ARGS+=	--enable-gconf --enable-gnome-vfs
.else
CONFIGURE_ARGS+=	--disable-gconf --disable-gnome-vfs
.endif

.if defined(WITH_JAVA)
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

.if defined(WITH_SDK)
DISTFILES+=	185d60944ea767075d27247c3162b3bc-unowinreg.dll:GoOOExtern

CONFIGURE_ARGS+=	--enable-odk
.else
CONFIGURE_ARGS+=	--disable-odk
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug \
			--enable-dbgutil \
			--enable-verbose \
			--enable-crashdump
.endif

.include <bsd.port.pre.mk>
pre-fetch:
.if !defined(LOCALIZED_LANG)
	@${ECHO_CMD}
	@${ECHO_CMD} "you can build a localized version of libreoffice by setting"
	@${ECHO_CMD} "LOCALIZED_LANG=xx"
	@${ECHO_CMD} "where xx can one or more of the following:"
	@${ECHO_CMD} "af ar as ast be-BY bg bn bo br brx bs ca-XV ca cs cy da de dgo dz el"
	@${ECHO_CMD} "en-GB en-ZA eo es et eu fa fi fr ga gl gu he hi-IN hi hr hu id is it"
	@${ECHO_CMD} "ja ka kid kk km kn ko kok ks ku lo lt lv mai mk ml mn mni mr my nb ne"
	@${ECHO_CMD} "nl nn nr ns oc om or pa-IN pl pt-BR pt ro ru rw sa-IN sat sd sh si sk"
	@${ECHO_CMD} "sl sq sr ss st sv sw-TZ ta te tg th tn tr ts ug uk ur-IN uz ve vi xh"
	@${ECHO_CMD} "zh-CN zh-TW zu"
	@${ECHO_CMD}
	@${ECHO_CMD} "Current setting: ${LOCALIZED_LANG}"
.endif

post-extract:
	@${MKDIR} ${WRKSRC}/clone
	@${MKDIR} ${WRKSRC}/src
.for component in ${LO_COMPONENTS}
	@${MV} ${WRKDIR}/${PORTNAME}-${component}-${LOVERSION} ${WRKSRC}/clone/${component}
.endfor
	@${TOUCH} ${WRKSRC}/clone/repos_changed

post-patch:
	@${REINPLACE_CMD} -e 's#-5.1#${BDB_VER}#g' \
		-e 's#5.1#${BDB_LIB_NAME:S/db//}#g' \
			${WRKSRC}/configure.in
	@${REINPLACE_CMD} -e 's#/bin/bash#${LOCALBASE}/bin/bash#' \
			${WRKSRC}/bin/distro-install-desktop-integration

.if defined(WITH_KDE4)
	@${REINPLACE_CMD} -e 's#moc,#moc-qt4,#g' \
		${WRKSRC}/configure.in
.endif
#	@${LN} -s ${MD5} ${WRKSRC}/bin/md5sum
.if defined(WITH_JAVA)
	@${REINPLACE_CMD} -e 's/^ANT_OPT/#ANT_OPT/g' \
		${WRKSRC}/clone/extensions/apache-commons/java/codec/makefile.mk \
		${WRKSRC}/clone/extensions/apache-commons/java/httpclient/makefile.mk \
		${WRKSRC}/clone/extensions/apache-commons/java/lang/makefile.mk \
		${WRKSRC}/clone/extensions/apache-commons/java/logging/makefile.mk
.endif

post-configure:
	@cd ${WRKSRC} && ./bin/create_bootstrap_links
	@${TOUCH} ${WRKSRC}/src.downloaded

post-install:
	@${RM} -f ${PLISTF} ${PLISTD}
	# It seems that the empty directories are necessary for libreoffice keep them for now
	@find ${LODESTDIR}/${PREFIX}/lib -type d -empty -exec ${TOUCH} {}/.keep \;

	@cd ${LODESTDIR}/${PREFIX} && ${FIND} -H -s lib \( -type f -o -type l \) -print >> ${PLISTF}
	@cd ${LODESTDIR}/${PREFIX} && ${FIND} -d lib/libreoffice -type d -exec ${ECHO_CMD} "@dirrm {}" \; >> ${PLISTD}

.for subdir in applications icons mime mimelnk
	@cd ${LODESTDIR}/${PREFIX} && ${FIND}  -H -s share/${subdir} \( -type f -o -type l \) -print >> ${PLISTF}
	@cd ${LODESTDIR}/${PREFIX}/ && ${FIND} -d share/${subdir} -type d \
		-exec ${ECHO_CMD} "@unexec ${RMDIR} %D/{}  2>/dev/null || ${TRUE}" \; >> ${PLISTD}
.endfor
# do not add the subdir itself as dirrmtry
.for subdir in application-registry mime-info
	@cd ${LODESTDIR}/${PREFIX} && ${FIND} -H -s share/${subdir} \( -type f -o -type l \) -print >> ${PLISTF}
	@cd ${LODESTDIR}/${PREFIX}/ && ${FIND} -d share/${subdir}/* -type d \
		-exec ${ECHO_CMD} "@unexec ${RMDIR} %D/{}  2>/dev/null || ${TRUE}" \; >> ${PLISTD}
.endfor
	@cd ${LODESTDIR}/${PREFIX} && ${FIND} -H -s bin \( -type f -o -type l \) -print >> ${PLISTF}

#Fix .desktop files
	@${FIND} ${LODESTDIR}/${PREFIX} -name *.desktop -type f -exec ${SED} -i .bak -e 's|office34|office|g; s|office3.4|office|g' {} \;
	@${FIND} ${LODESTDIR}/${PREFIX} -name *.desktop.bak -delete

.if defined(WITH_GTK) || defined(WITH_GNOME)
	@${ECHO_CMD} "@exec ${LOCALBASE}/bin/update-desktop-database > /dev/null || ${TRUE}" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ${LOCALBASE}/bin/update-desktop-database > /dev/null || ${TRUE}" >> ${TMPPLIST}
.endif

.if defined(WITH_SDK)
.for subdir in include share/idl share/libreoffice share/doc
	@cd ${LODESTDIR}/${PREFIX} && ${FIND} -H -s ${subdir} \( -type f -o -type l \) -print >> ${PLISTF}
	@cd ${LODESTDIR}/${PREFIX} && ${FIND} -d ${subdir} -type d -exec echo "@dirrm {}" \; >> ${PLISTD}
.endfor
.endif

	@${SORT} ${WRKDIR}/plist_files >> ${TMPPLIST}
	@${SORT} -r ${WRKDIR}/plist_dirs >> ${TMPPLIST}

.if defined(WITH_SDK)
.for subdir in include share/idl share/libreoffice share/doc
	@${ECHO_CMD} "@unexec ${RMDIR} %D/${subdir} 2>/dev/null || ${TRUE}" >> ${TMPPLIST}
.endfor
.endif

	@cd ${LODESTDIR}/${PREFIX} ; ${PAX} -rw . ${PREFIX}
.if defined(WITH_GTK) || defined(WITH_GNOME)
	@${LOCALBASE}/bin/update-desktop-database 2>/dev/null || ${TRUE}
.endif

.include <bsd.port.post.mk>
