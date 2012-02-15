# New ports collection makefile for:	libreoffice
# Date created:		2010-12-06
# Whom:			Bapt <bapt@FreeBSD.Org>
#
# $FreeBSD$
#

PORTNAME=	libreoffice
PORTVERSION=	3.3.4
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
		http://hg.services.openoffice.org/binaries/:hgOOo \
		http://www.numbertext.org/linux/:OOoDTP
PKGNAMESUFFIX=	-legacy

MAINTAINER=	office@FreeBSD.org
COMMENT=	Full integrated office productivity suite

LICENSE=	LGPL3 MPL
LICENSE_COMB=	dual

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip \
		unzip:${PORTSDIR}/archivers/unzip \
		gcp:${PORTSDIR}/sysutils/coreutils \
		gpatch:${PORTSDIR}/devel/patch \
		bash:${PORTSDIR}/shells/bash \
		${SITE_PERL}/Archive/Zip.pm:${PORTSDIR}/archivers/p5-Archive-Zip \
		${LOCALBASE}/bin/gperf:${PORTSDIR}/devel/gperf \
		${LOCALBASE}/lib/libcppunit.so:${PORTSDIR}/devel/cppunit \
		${LOCALBASE}/lib/libmdbsql.a:${PORTSDIR}/databases/mdbtools \
		${LOCALBASE}/lib/libboost_regex.a:${PORTSDIR}/devel/boost-libs \
		vigra-config:${PORTSDIR}/graphics/vigra
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
		poppler-glib.8:${PORTSDIR}/graphics/poppler-glib \
		wpd-0.9.9:${PORTSDIR}/textproc/libwpd \
		wpg-0.2.2:${PORTSDIR}/graphics/libwpg \
		wps-0.2.2:${PORTSDIR}/textproc/libwps \
		rdf.0:${PORTSDIR}/textproc/redland \
		textcat.0:${PORTSDIR}/textproc/libtextcat \
		lpsolve55:${PORTSDIR}/math/lp_solve

BROKEN=		does not compile

CONFLICTS_INSTALL=	libreoffice-[0-9]*

LOVERSION=	${PORTVERSION}.1
LOFFICE_COMPONENTS=	artwork base bootstrap calc components extensions \
			extras filters help impress l10n libs-core libs-extern \
			libs-extern-sys libs-gui postprocess sdk testing \
			ure writer

DIST_SUBDIR=	libreoffice
DISTFILES+=	${PORTNAME}-build-${LOVERSION}.tar.gz
WRKSRC=		${WRKDIR}/${PORTNAME}-build-${LOVERSION}

LODESTDIR=	${WRKDIR}/loinstall

.for components in ${LOFFICE_COMPONENTS}
DISTFILES+=	${PORTNAME}-${components}-${LOVERSION}.tar.bz2
.endfor

# for dynamic plist generation
PLISTD?=	${WRKDIR}/plist_dirs
PLISTF?=	${WRKDIR}/plist_files

# not tested on other platforms and at leat plist will be wrong because of LOARCH not expendanded correctly
ONLY_FOR_ARCH=	i386 amd64

EXTRACT_ONLY:=	${DISTFILES}

#additionnal components
DISTFILES+=	fdb27bfe2dbe2e7b57ae194d9bf36bab-SampleICC-1.3.2.tar.gz \
		1756c4fa6c616ae15973c104cd8cb256-Adobe-Core35_AFMs-314.tar.gz \
		cf8a6967f7de535ae257fa411c98eb88-mdds_0.3.0.tar.bz2 \
		067201ea8b126597670b5eff72e1f66c-mythes-1.2.0.tar.gz \
		37282537d0ed1a087b1c8f050dc812d9-dejavu-fonts-ttf-2.32.zip \
		ca4870d899fd7e943ffc310a5421ad4d-liberation-fonts-ttf-1.06.0.20100721.tar.gz \
		35efabc239af896dfb79be7ebdd6e6b9-gentiumbasic-fonts-1.10.zip \
		881af2b7dca9b8259abbca00bbbc004d-LinLibertineG-20110101.zip:OOoDTP

# rely on bsdtar ability to extract .gz and .bz2 archives
EXTRACT_CMD=	${CAT}
EXTRACT_BEFORE_ARGS=

USE_BDB=	yes
USE_PERL5_BUILD=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_PYTHON=	yes
USE_OPENSSL=	yes
WANT_GNOME=	yes
USE_BISON=	build
USE_GSTREAMER=	yes
USE_XORG=	xaw
USE_GL=		gl glu
MAKE_JOBS_SAFE=	yes
INSTALLS_ICONS=	yes

OPTIONS=	WEBDAV	"Support webdav protocol" off \
		CUPS	"Support cups for printing" on \
		KDE4	"With Qt4/KDE4 vclplug support" off \
		GNOME	"Better integration in gnome environnement" off \
		JAVA	"Add Java support (XML Filters, macros)" off

LOCALIZED_LANG?=	en-US

CONFIGURE_ARGS+=	--without-download \
			--with-binsuffix=no \
			--with-dict="${LOCALIZED_LANG}" \
			--with-myspell-dicts \
			--with-lang="${LOCALIZED_LANG}"\
			--disable-odk \
			--with-build-version="FreeBSD ports ${PKGVERSION}" \
			--with-vendor="FreeBSD ports ${PKGVERSION}" \
			--exec-prefix=${PREFIX} \
			--with-num-cpus=${MAKE_JOBS_NUMBER} \
			--with-installed-ooo-dirname=${PORTNAME} \
			--without-git \
			--with-ooo-builddir=${WRKSRC}/build/${PORTNAME} \
			--with-srcdir=${DISTDIR}/${DIST_SUBDIR} \
			--with-external-tar=${DISTDIR}/${DIST_SUBDIR} \
			--with-docdir=${DOCSDIR} \
			--with-gnu-patch=${LOCALBASE}/bin/gpatch \
			--with-gnu-cp=${LOCALBASE}/bin/gcp \
			--enable-openxml \
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
			--with-system-mdbtools \
			--with-fonts \
			--with-alloc=system \
			--with-system-stdlibs \
			--with-system-xrender-headers \
			--with-system-mesa-headers \
			--disable-epm \
			--disable-hids \
			--disable-post-install-scripts \
			--disable-mozilla \
			--disable-build-mozilla \
			--disable-kde \
			--without-stlport \
			--disable-nss-module \
			--without-system-mozilla \
			--with-external-thes-dir=${LOCALBASE}/share/mythes \
			--with-external-hyph-dir=${LOCALBASE}/share/hyphen \
			--with-external-dict-dir=${LOCALBASE}/share/hunspell \
			--disable-zenity

# extensions

CONFIGURE_ARGS+=	--enable-ext-pdfimport \
			--enable-ext-wiki-publisher \
			--enable-ext-report-builder
#			--enable-extra-gallery \
#			--enable-extra-template \
#			--enable-extra-sample \
#			--enable-extra-font

MAN1=	libreoffice.1  \
	unopkg.1

.include <bsd.port.options.mk>

MAKE_ENV+=	GPERF=${LOCALBASE}/bin/gperf \
		X_LIBS=-L${LOCALBASE}/lib \
		OPENSSL_CFLAGS=-I${OPENSSLINC} OPENSSL_LIBS=-L${OPENSSLLIB} \
		LD_LIBRARY_PATH=. DESTDIR=${LODESTDIR}

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
DISTFILES+=	798b2ffdc8bcfe7bca2cf92b62caf685-rhino1_5R5.zip:hgOOo \
		17410483b5b5f267aa18b7e00b65e6e0-hsqldb_1_8_0.zip:hgOOo \
		2a177023f9ea8ec8bd00837605c5df1b-jakarta-tomcat-5.0.30-src.tar.gz:hgOOo \
		48d8169acc35f97e05d8dcdfd45be7f2-lucene-2.3.2.tar.gz:hgOOo \
		a7983f859eafb2677d7ff386a023bc40-xsltml_2.1.2.zip:hgOOo \
		af3c3acf618de6108d65fcdc92b492e1-commons-codec-1.3-src.tar.gz:hgOOo \
		3c219630e4302863a9a83d0efde889db-commons-logging-1.1.1-src.tar.gz:hgOOo \
		2ae988b339daec234019a7066f96733e-commons-lang-2.3-src.tar.gz:hgOOo \
		2c9b0f83ed5890af02c0df1c1776f39b-commons-httpclient-3.1-src.tar.gz \
		ea570af93c284aa9e5621cd563f54f4d-bsh-2.0b1-src.tar.gz:hgOOo \
		ada24d37d8d638b3d8a9985e80bc2978-source-9.0.0.7-bj.zip:hgOOo \
		8ea307d71d11140574bfb9fcc2487e33-libbase.zip:hgOOo \
		35c94d2df8893241173de1d16b6034c0-swingExSrc.zip:hgOOo \
		39bb3fcea1514f1369fcfc87542390fd-sacjava-1.3.zip:hgOOo \
		a06a496d7a43cbdc35e69dbe678efadb-libloader.zip:hgOOo \
		f3e2febd267c8e4b13df00dac211dd6d-flute.zip:hgOOo \
		5aba06ede2daa9f2c11892fbd7bc3057-libserializer.zip:hgOOo \
		d1a3205871c3c52e8a50c9f18510ae12-libformula.zip:hgOOo \
		f7925ba8491fe570e5164d2c72791358-libfonts.zip:hgOOo \
		67b42915c8432abf0a922438f00860a2-libxml.zip:hgOOo \
		dbb3757275dc5cc80820c0b4dd24ed95-librepository.zip:hgOOo \
		79600e696a98ff95c2eba976f7a8dfbb-liblayout.zip:hgOOo \
		d4c4d91ab3a8e52a2e69d48d34ef4df4-core.zip:hgOOo

USE_JAVA=	1.4+
CATEGORIES+=	java
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
			--with-serializer-jar=${JAVALIBDIR}/serializer.jar
.else
BUILD_DEPENDS+=	xsltproc:${PORTSDIR}/textproc/libxslt
CONFIGURE_ARGS+=	--without-java
.endif

EMPTYDIRS=	libreoffice/share/uno_packages/cache \
		libreoffice/share/prereg \
		libreoffice/basis3.3/program/plugin \
		libreoffice/basis3.3/program/addin \
		libreoffice/basis3.3/presets/wordbook \
		libreoffice/basis3.3/presets/uno_packages/cache \
		libreoffice/basis3.3/presets/template \
		libreoffice/basis3.3/presets/temp \
		libreoffice/basis3.3/presets/store \
		libreoffice/basis3.3/presets/psprint/fontmetric \
		libreoffice/basis3.3/presets/psprint/driver \
		libreoffice/basis3.3/presets/Scripts \
		libreoffice/basis3.3/presets/autocorr \
		libreoffice/basis3.3/presets/backup

.for LANG in ${LOCALIZED_LANG}
EMPTYDIRS+=	libreoffice/basis3.3/share/samples/${LANG}
.endfor

.include <bsd.port.pre.mk>
pre-fetch:
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

post-extract:
	@${MKDIR} ${WRKSRC}/build/${PORTNAME}
.for component in ${LOFFICE_COMPONENTS}
	@${MV} ${WRKDIR}/${PORTNAME}-${component}-${LOVERSION}/* ${WRKSRC}/build/${PORTNAME}/
	@${RMDIR} ${WRKDIR}/${PORTNAME}-${component}-${LOVERSION}/
.endfor
	@${TOUCH} ${WRKSRC}/build/${PORTNAME}/unpack
	@${MKDIR} ${WRKSRC}/clone
	@${TOUCH} ${WRKSRC}/clone/repos_changed

post-patch:
	@${REINPLACE_CMD} -e 's#-5.1#${BDB_VER}#g' \
		-e 's#5.1#${BDB_LIB_NAME:S/db//}#g' \
			${WRKSRC}/build/${PORTNAME}/configure.in

.if defined(WITH_KDE4)
	@${REINPLACE_CMD} -e 's#moc,#moc-qt4,#g' \
		${WRKSRC}/build/${PORTNAME}/configure.in
.endif
	@${LN} -s ${MD5} ${WRKSRC}/bin/md5sum
.if defined(WITH_JAVA)
	@${REINPLACE_CMD} -e 's/^ANT_OPT/#ANT_OPT/g' \
		${WRKSRC}/build/${PORTNAME}/apache-commons/java/codec/makefile.mk \
		${WRKSRC}/build/${PORTNAME}/apache-commons/java/httpclient/makefile.mk \
		${WRKSRC}/build/${PORTNAME}/apache-commons/java/lang/makefile.mk \
		${WRKSRC}/build/${PORTNAME}/apache-commons/java/logging/makefile.mk
.endif

post-install:
	@${RM} -f ${PLISTF} ${PLISTD}
	@${RM} ${LODESTDIR}/${PREFIX}/share/applications/*.desktop
	@${MV} ${LODESTDIR}/${PREFIX}/share/mime/packages/openoffice.xml ${LODESTDIR}/${PREFIX}/share/mime/packages/libreoffice.xml

	@for img in ${LODESTDIR}/${PREFIX}/share/icons/hicolor/*/apps/ooo-*; do ${MV} $$img `${ECHO_CMD} $$img | ${SED} "s/ooo-/libreoffice-/"`; done
	@for pix in ${LODESTDIR}/${PREFIX}/share/pixmaps/ooo-*; do ${RM} $$pix; ${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/`${BASENAME} $$pix | ${SED} "s/ooo-/libreoffice-/"` ${LODESTDIR}/${PREFIX}/share/pixmaps/; done
.for component in base calc draw math impress writer startcenter
	@cd ${LODESTDIR}/${PREFIX}/share/applications; ${LN} -s ../../lib/${PORTNAME}/share/xdg/${component}.desktop ${PORTNAME}-${component}.desktop
.endfor
	@for dir in ${EMPTYDIRS}; do ${TOUCH} ${LODESTDIR}/${PREFIX}/lib/$$dir/.keep; done

	@cd ${LODESTDIR}/${PREFIX}/lib && ${FIND} -H -s * -type f -o -type l | \
		${SED} -e 's|^|lib/|' >> ${PLISTF}
	@cd ${LODESTDIR}/${PREFIX}/lib && ${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrm lib/|' >> ${PLISTD}

.for subdir in icons pixmaps mime applications
	@cd ${LODESTDIR}/${PREFIX}/share/${subdir} && ${FIND} -H -s * -type f -o -type l | \
		${SED} -e 's|^|share/${subdir}/|' >> ${PLISTF}
.endfor

	@${ECHO_CMD} "@unexec ${RMDIR} %D/share/applications 2>/dev/null || ${TRUE}" >> ${PLISTD}

	@cd ${LODESTDIR}/${PREFIX}/bin && ${FIND} -H -s * -type f -o -type l | \
		${SED} -e 's|^|bin/|' >> ${PLISTF}

	@${ECHO_CMD} "@exec ${LOCALBASE}/bin/update-desktop-database > /dev/null || ${TRUE}" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ${LOCALBASE}/bin/update-desktop-database > /dev/null || ${TRUE}" >> ${TMPPLIST}
	@${SORT} ${WRKDIR}/plist_files >> ${TMPPLIST}
	@${SORT} -r ${WRKDIR}/plist_dirs >> ${TMPPLIST}

	@cd ${LODESTDIR}/${PREFIX} ; ${FIND} . -print | ${CPIO} -adpm --quiet ${PREFIX}
	@${LOCALBASE}/bin/update-desktop-database 2>/dev/null || ${TRUE}

.include <bsd.port.post.mk>
