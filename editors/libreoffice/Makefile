# New ports collection makefile for:	libreoffice
# Date created:		2010-12-06
# Whom:			Bapt <bapt@FreeBSD.Org>
#
# $FreeBSD$
#

PORTNAME=	libreoffice
PORTVERSION=	3.4.2
LOVERSION=	${PORTVERSION}.3
CATEGORIES=	editors
MASTER_SITES=	http://ftp.osuosl.org/pub/tdf/libreoffice/src/ \
		http://ftp.rediris.es/mirror/TDF/libreoffice/src/ \
		http://mirrors.supportex.net/tdf/libreoffice/src/ \
		http://mirror.netcologne.de/tdf/libreoffice/src/ \
		http://mirror.informatik.uni-mannheim.de/pub/mirrors/tdf/libreoffice/src/ \
		http://ftp.uni-muenster.de/pub/software/DocumentFoundation/libreoffice/src/ \
		http://ftp.rz.tu-bs.de/pub/mirror/tdf/tdf-pub/libreoffice/src/ \
		http://artfiles.org/documentfoundation.org/libreoffice/src/ \
		http://mirror.galpon.org/tdf/libreoffice/src/ \
		http://ftp.tu-chemnitz.de/pub/tdf/libreoffice/src/ \
		http://tdf.panu.it/libreoffice/src/ \
		http://ftp.wh2.tu-dresden.de/pub/mirrors/tdf/libreoffice/src/ \
		http://ftp.klid.dk/ftp/tdf/libreoffice/src/ \
		http://gd.tuwien.ac.at/tdf/libreoffice/src/ \
		http://archive.sunet.se/pub/Office/tdf/libreoffice/src/ \
		http://ftp.astral.ro/mirrors/tdf/libreoffice/src/ \
		http://ftp.roedu.net/mirrors/tdf/libreoffice/src/ \
		http://ftp.unicamp.br/pub/tdf/libreoffice/src/ \
		http://mirror.yongbok.net/tdf/libreoffice/src/ \
		http://mirror3.mirrors.tds.net/pub/documentfoundation.org/libreoffice/src/ \
		http://download.go-oo.org/src/:GoOOSrc \
		http://download.go-oo.org/extern/:GoOOExtern \
		http://www.numbertext.org/linux/:OOoDTP

MAINTAINER=	office@FreeBSD.org
COMMENT=	Full integrated office productivity suite

BROKEN=	build is too fragile and break too often

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
		1756c4fa6c616ae15973c104cd8cb256-Adobe-Core35_AFMs-314.tar.gz:GoOOSrc \
		0ff7d225d087793c8c2c680d77aac3e7-mdds_0.5.3.tar.bz2:GoOOSrc \
		37282537d0ed1a087b1c8f050dc812d9-dejavu-fonts-ttf-2.32.zip:GoOOSrc \
		ca4870d899fd7e943ffc310a5421ad4d-liberation-fonts-ttf-1.06.0.20100721.tar.gz:GoOOSrc \
		35efabc239af896dfb79be7ebdd6e6b9-gentiumbasic-fonts-1.10.zip:GoOOSrc \
		881af2b7dca9b8259abbca00bbbc004d-LinLibertineG-20110101.zip:OOoDTP

# rely on bsdtar ability to extract .gz and .bz2 archives
LIB_DEPENDS=	cairo.2:${PORTSDIR}/graphics/cairo \
		xml2.5:${PORTSDIR}/textproc/libxml2 \
		expat.6:${PORTSDIR}/textproc/expat2 \
		icutu.48:${PORTSDIR}/devel/icu \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		curl.6:${PORTSDIR}/ftp/curl \
		hunspell-1.3.0:${PORTSDIR}/textproc/hunspell \
		mythes-1.2.0:${PORTSDIR}/textproc/mythes \
		hyphen.2:${PORTSDIR}/textproc/hyphen \
		poppler.6:${PORTSDIR}/graphics/poppler \
		wpd-0.9.9:${PORTSDIR}/textproc/libwpd \
		wpg-0.2.2:${PORTSDIR}/graphics/libwpg \
		wps-0.2.2:${PORTSDIR}/textproc/libwps \
		rdf.0:${PORTSDIR}/textproc/redland \
		textcat.0:${PORTSDIR}/textproc/libtextcat \
		lpsolve55:${PORTSDIR}/math/lp_solve


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
USE_PYTHON=	yes
USE_OPENSSL=	yes
WANT_GNOME=	yes
USE_GSTREAMER=	yes
USE_XORG=	xaw
USE_GL=		gl glu
MAKE_JOBS_SAFE=	yes
INSTALLS_ICONS=	yes

OPTIONS=	WEBDAV	"Support webdav protocol" off \
		CUPS	"Support cups for printing" on \
		KDE4	"With Qt4/KDE4 vclplug support" off \
		GNOME	"Better integration in gnome environnement" off \
		JAVA	"Add Java support (XML Filters, macros)" off \
		SDK	"Build with SDK" off

CONFIGURE_ENV=		GPERF=${LOCALBASE}/bin/gperf \
			DMAKE=${LOCALBASE}/bin/dmake \
			LDFLAGS="" \
			OPENSSL_CFLAGS="-I${OPENSSLINC}" \
			OPENSSL_LIBS="-L${OPENSSLLIB} -lssl"

CONFIGURE_ARGS+=	--with-unix-wrapper="libreoffice" \
			--disable-fetch-external \
			--with-build-version="FreeBSD ports ${PKGVERSION}" \
			--with-vendor="FreeBSD ports ${PKGVERSION}" \
			--exec-prefix=${PREFIX} \
			--with-max-jobs=${MAKE_JOBS_NUMBER} \
			--with-external-tar=${DISTDIR}/${DIST_SUBDIR} \
			--with-gnu-patch=${LOCALBASE}/bin/gpatch \
			--with-system-libxml \
			--with-system-cairo --enable-cairo \
			--with-system-boost \
			--with-system-cppunit \
			--with-system-zlib \
			--with-system-icu \
			--with-system-python \
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
			--disable-kde \
			--without-stlport \
			--disable-nss-module \
			--without-system-mozilla \
			--with-system-translate-toolkit \
			--with-system-dicts \
			--with-external-thes-dir=${LOCALBASE}/share/mythes \
			--with-external-hyph-dir=${LOCALBASE}/share/hyphen \
			--with-external-dict-dir=${LOCALBASE}/share/hunspell

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

LDFLAGS=
MAKE_ENV+= 	USE_GMAKE=1 DESTDIR=${LODESTDIR}

CFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/db${BDB_VER} -L${LOCALBASE}/lib

USE_GNOME=	gtk20 desktopfileutils
USE_AUTOTOOLS=	autoconf automake:env

.if defined(WITH_WEBDAV)
CONFIGURE_ARGS+=	--enable-neon --with-system-neon
LIB_DEPENDS+=	neon.27:${PORTSDIR}/www/neon29
.else
CONFIGURE_ARGS+=	--disable-neon
.endif

.if defined(WITH_CUPS)
CONFIGURE_ARGS+=	--enable-cups
LIB_DEPENDS+=	cups.2:${PORTSDIR}/print/cups-client
.else
CONFIGURE_ARGS+=	--disable-cups
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
		af3c3acf618de6108d65fcdc92b492e1-commons-codec-1.3-src.tar.gz:GoOOSrc \
		3c219630e4302863a9a83d0efde889db-commons-logging-1.1.1-src.tar.gz:GoOOSrc \
		2ae988b339daec234019a7066f96733e-commons-lang-2.3-src.tar.gz:GoOOSrc \
		2c9b0f83ed5890af02c0df1c1776f39b-commons-httpclient-3.1-src.tar.gz:GoOOSrc \
		ea570af93c284aa9e5621cd563f54f4d-bsh-2.0b1-src.tar.gz:GoOOSrc \
		ada24d37d8d638b3d8a9985e80bc2978-source-9.0.0.7-bj.zip:GoOOSrc \
		eeb2c7ddf0d302fba4bfc6e97eac9624-libbase-1.1.6.zip:GoOOSrc \
		35c94d2df8893241173de1d16b6034c0-swingExSrc.zip:GoOOSrc \
		39bb3fcea1514f1369fcfc87542390fd-sacjava-1.3.zip:GoOOSrc \
		97b2d4dba862397f446b217e2b623e71-libloader-1.1.6.zip:GoOOSrc \
		d8bd5eed178db6e2b18eeed243f85aa8-flute-1.1.6.zip:GoOOSrc \
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
		${JAVALIBDIR}/junit.jar:${PORTSDIR}/java/junit \
		${JAVALIBDIR}/xercesImpl.jar:${PORTSDIR}/textproc/xerces-j \
		${JAVALIBDIR}/xalan.jar:${PORTSDIR}/textproc/xalan-j

CONFIGURE_ARGS+=	--with-ant-home=${LOCALBASE}/share/java/apache-ant/ \
			--with-junit=${JAVALIBDIR}/junit.jar \
			--with-jdk-home=${JAVA_HOME} \
			--with-system-xerces \
			--with-xerces-jar=${JAVALIBDIR}/xercesImpl.jar \
			--with-system-xml-apis \
			--with-xml-apis-jar=/${JAVALIBDIR}/xml-apis.jar \
			--with-system-xalan \
			--with-xalan-jar=${JAVALIBDIR}/xalan.jar \
			--with-serializer-jar=${JAVALIBDIR}/serializer.jar \
			--enable-ext-wiki-publisher
.else
BUILD_DEPENDS+=	xsltproc:${PORTSDIR}/textproc/libxslt
CONFIGURE_ARGS+=	--without-java
.endif

.if defined(WITH_SDK)
CONFIGURE_ARGS+=	--enable-odk
.else
CONFIGURE_ARGS+=	--disable-odk
.endif

EMPTYDIRS=	libreoffice/share/uno_packages/cache \
		libreoffice/share/prereg \
		libreoffice/basis3.4/program/plugin \
		libreoffice/basis3.4/program/addin \
		libreoffice/basis3.4/presets/wordbook \
		libreoffice/basis3.4/presets/uno_packages/cache \
		libreoffice/basis3.4/presets/template \
		libreoffice/basis3.4/presets/temp \
		libreoffice/basis3.4/presets/store \
		libreoffice/basis3.4/presets/psprint/fontmetric \
		libreoffice/basis3.4/presets/psprint/driver \
		libreoffice/basis3.4/presets/Scripts \
		libreoffice/basis3.4/presets/autocorr \
		libreoffice/basis3.4/presets/backup

.for LANG in ${LOCALIZED_LANG}
EMPTYDIRS+=	libreoffice/basis3.4/share/samples/${LANG}
.endfor
.if !defined(LOCALIZED_LANG)
EMPTYDIRS+=	libreoffice/basis3.4/share/samples/en-US
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
	@${MKDIR} ${LODESTDIR}/${PREFIX}/share/applications
.for component in writer printeradmin math javafilter base calc startcenter qstart draw impress
	@cd ${LODESTDIR}/${PREFIX}/share/applications; ${LN} -s ../../lib/${PORTNAME}/share/xdg/${component}.desktop ${component}.desktop
.endfor
	@for dir in ${EMPTYDIRS}; do ${TOUCH} ${LODESTDIR}/${PREFIX}/lib/$$dir/.keep; done

	@cd ${LODESTDIR}/${PREFIX}/lib && ${FIND} -H -s * -type f -o -type l | \
		${SED} -e 's|^|lib/|' >> ${PLISTF}
	@cd ${LODESTDIR}/${PREFIX}/lib && ${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrm lib/|' >> ${PLISTD}

	@cd ${LODESTDIR}/${PREFIX}/share/applications && ${FIND} -H -s * -type f -o -type l | \
		${SED} -e 's|^|share/applications/|' >> ${PLISTF}

	@${ECHO_CMD} "@unexec ${RMDIR} %D/share/applications 2>/dev/null || ${TRUE}" >> ${PLISTD}

	@cd ${LODESTDIR}/${PREFIX}/bin && ${FIND} -H -s * -type f -o -type l | \
		${SED} -e 's|^|bin/|' >> ${PLISTF}

	@${ECHO_CMD} "@exec ${LOCALBASE}/bin/update-desktop-database > /dev/null || ${TRUE}" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ${LOCALBASE}/bin/update-desktop-database > /dev/null || ${TRUE}" >> ${TMPPLIST}
	@${SORT} ${WRKDIR}/plist_files >> ${TMPPLIST}
	@${SORT} -r ${WRKDIR}/plist_dirs >> ${TMPPLIST}

	@cd ${LODESTDIR}/${PREFIX} ; ${TAR} cfp - . | ${TAR} xfp - -C ${PREFIX}
	@${LOCALBASE}/bin/update-desktop-database 2>/dev/null || ${TRUE}

.include <bsd.port.post.mk>
