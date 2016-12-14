# Created by: Daichi GOTO <daichi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mozc
PORTVERSION=	2.17.2322.102
PORTREVISION=	3
CATEGORIES=	japanese

MAINTAINER=	hrs@FreeBSD.org
COMMENT?=	Mozc Japanese Input Method, Server

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	ninja:devel/ninja \
		gyp:devel/py-gyp
EXTRACT_DEPENDS=${PYTHON_CMD}:${PYTHON_PORTSDIR}
LIB_DEPENDS=	libprotobuf.so:devel/protobuf \
		libzinnia.so:japanese/zinnia
RUN_DEPENDS=	xdg-open:devel/xdg-utils

USE_GITHUB=	yes
GH_TUPLE=	google:${PORTNAME}:9b4c9e0 \
		hiroyuki-komatsu:japanese-usage-dictionary:e5b3425:udic

USES=		compiler:c++11-lang pkgconfig iconv:wchar_t gmake \
		tar:bzip2 python:2.7,build shebangfix
SHEBANG_FILES=	src/build_mozc.py
BUILD_WRKSRC=	${WRKSRC}/src

BUILD_MOZC_LIST?=	mozc_server

.if ${BUILD_MOZC_LIST:Mmozc_server} == "mozc_server"
PKGNAMEPREFIX=	ja-
PKGNAMESUFFIX=	-server

LICENSE=		BSD3CLAUSE NAISTL
LICENSE_COMB=		multi
LICENSE_FILE_BSD3CLAUSE=	${WRKSRC}/LICENSE
LICENSE_DISTFILES_BSD3CLAUSE=	${DISTNAME}${EXTRACT_SUFX}
LICENSE_NAME_NAISTL=	Nara Institute of Science and Technology License
LICENSE_PERMS_NAISTL=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_FILE_NAISTL=	${WRKSRC}/src/data/dictionary_oss/README.txt
LICENSE_DISTFILES_NAISTL=${DISTNAME}${EXTRACT_SUFX}
.elif ${BUILD_MOZC_LIST:Mmozc_tool} == "mozc_tool"
USE_GNOME=	glib20 gtk20
USE_QT4=	corelib gui qmake_build moc_build rcc_build uic_build
.elif ${BUILD_MOZC_LIST:Mibus_mozc} == "ibus_mozc"
USE_XORG=	xcb
USE_GNOME=	glib20 gtk20
.elif ${BUILD_MOZC_LIST:Mmozc_el} == "mozc_el"
USE_EMACS=	yes
.elif ${BUILD_MOZC_LIST:Mfcitx_mozc}
USES+=		gettext-tools
.endif

# Use GCC only when the stock clang does not have libc++.so.
.if exists(/usr/bin/clang) && exists(/usr/lib/libc++.so)
_CCTYPE=	clang
.else
USE_GCC=	yes
_CCTYPE=	gcc
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile: segfault
.endif

GYP_DEFINES=	use_libprotobuf=1 \
		channel_dev=0 \
		enable_unittest=0 \
		compiler_host="${_CCTYPE}" \
		compiler_target="${_CCTYPE}" \
		use_libzinnia=1 \
		zinnia_model_file="${LOCALBASE}/share/tegaki/models/zinnia/handwriting-ja.model" \
		ibus_mozc_icon_path="${LOCALBASE}/share/ibus-mozc/icons/product_icon.png" \
		ibus_mozc_path="${PREFIX}/libexec/ibus-engine-mozc"
BUILD_MODE=	Release
BUILD_CMD=	${SETENV} ${MAKE_ENV} PATH=/bin:/usr/bin:${PATH} ${MAKE_CMD}
BUILD_MOZC_CMD=	cd ${BUILD_WRKSRC} && \
		${SETENV} BUILD_COMMAND="${BUILD_WRKSRC}/mozcmake" \
		    GYP_DEFINES="${GYP_DEFINES}" \
		    PYTHONPATH=${PYTHON_SITELIBDIR}/gyp \
		    CC_host="${CC}" \
		    CC_target="${CC}" \
		    CXX_host="${CXX}" \
		    CXX_target="${CXX}" \
		    LD_host="${CXX}" \
		    AR_host="${AR}" \
		    ${PYTHON_CMD} build_mozc.py
BUILD_MOZC_CMD_BUILD=	${BUILD_MOZC_CMD} build -c ${BUILD_MODE} ${_MAKE_JOBS}
BUILD_GYP_CMD=	${SETENV} ${MAKE_ENV} ${LOCALBASE}/bin/gyp

post-patch:
	${REINPLACE_CMD} 's,-liconv,${ICONV_LIB},g' \
	    ${BUILD_WRKSRC}/gui/qt_libraries.gypi
	${FIND} ${BUILD_WRKSRC} \( -name '*.gyp' -o -name '*.gypi' \) -exec \
	    ${REINPLACE_CMD} "s,'python','${PYTHON_CMD}',g" {} \;
.if ${BUILD_MOZC_LIST:Mfcitx_mozc} == "fcitx_mozc"
	${REINPLACE_CMD} 's,/po/mo},%po}mo,g' \
	    ${BUILD_WRKSRC}/unix/fcitx/gen_fcitx_mozc_i18n.sh
	${REINPLACE_CMD} "s,/usr,${LOCALBASE:Q}," \
	    ${BUILD_WRKSRC}/unix/fcitx/mozc.conf
.endif

.if !${BUILD_MOZC_LIST:Mmozc_el}
${BUILD_WRKSRC}/mozcmake:
	${PRINTF} "%s\n\n%s\n" "#!/bin/sh" 'exec ${BUILD_CMD} "$$@"' \
	    > ${BUILD_WRKSRC}/mozcmake
	${CHMOD} +x ${BUILD_WRKSRC}/mozcmake

post-configure: ${BUILD_WRKSRC}/mozcmake
	${BUILD_MOZC_CMD} gyp \
	    --gypdir=${LOCALBASE}/bin \
	    --server_dir="${PREFIX}/bin" \
	    --tool_dir="${PREFIX}/libexec" \
	    --renderer_dir="${PREFIX}/libexec" \
	    --localbase="${LOCALBASE}" \
	    --ldflags="${LDFLAGS} -fstack-protector -L${LOCALBASE}/lib" \
	    --cflags="${CFLAGS:Q}" \
	    --cflags_cc="${CXXFLAGS:Q}" \
	    --include_dirs="${LOCALBASE}/include" \
	    ${GYP_OPTIONS}
.endif

# mozc_server
.if ${BUILD_MOZC_LIST:Mmozc_server} == "mozc_server" || make(makesum)
GYP_OPTIONS+=	--noqt
GYP_DEFINES+=	use_libibus=0 \
		enable_gtk_renderer=0

MASTER_SITES+=	LOCAL/kuriyama:zipcode
DISTFILES+= \
	ken_all-20160428.zip:zipcode \
	jigyosyo-20160428.zip:zipcode

PLIST_FILES+=	bin/mozc \
		bin/mozc_server \
		libexec/mozc_emacs_helper
SUB_FILES+=	mozc

post-extract-mozc_server:
	@for F in ${DISTFILES:M*\:zipcode:C/\:zipcode//}; do \
		${UNZIP_NATIVE_CMD} -L -d ${BUILD_WRKSRC}/data/dictionary_oss \
		    ${DISTDIR}/$$F; \
	done
	@cd ${BUILD_WRKSRC}/data/dictionary_oss && \
	    ${PYTHON_CMD} ${BUILD_WRKSRC}/dictionary/gen_zip_code_seed.py \
	    --zip_code=ken_all.csv --jigyosyo=jigyosyo.csv \
	    >> dictionary09.txt
	${MV} ${WRKSRC_udic}/usage_dict.txt \
	    ${BUILD_WRKSRC}/third_party/japanese_usage_dictionary

post-extract: post-extract-mozc_server

do-build-mozc_server:
	${BUILD_MOZC_CMD_BUILD} server/server.gyp:mozc_server
	${BUILD_MOZC_CMD_BUILD} unix/emacs/emacs.gyp:mozc_emacs_helper

do-install-mozc_server:
	${INSTALL_PROGRAM} \
	    ${BUILD_WRKSRC}/out_linux/${BUILD_MODE}/mozc_server \
	    ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} \
	    ${BUILD_WRKSRC}/out_linux/${BUILD_MODE}/mozc_emacs_helper \
	    ${STAGEDIR}${PREFIX}/libexec
	${INSTALL_SCRIPT} \
	    ${WRKDIR}/mozc ${STAGEDIR}/${PREFIX}/bin
.endif

# mozc_tool
.if ${BUILD_MOZC_LIST:Mmozc_tool} == "mozc_tool"
GYP_DEFINES+=	use_libibus=0 \
		enable_gtk_renderer=1

RUN_DEPENDS+=	${LOCALBASE}/share/tegaki/models/zinnia/handwriting-ja.model:japanese/tegaki-zinnia-japanese

PLIST_FILES+=	libexec/mozc_tool \
		bin/mozc_tool \
		%%DATADIR%%/icons/product_logo.png \
		%%DATADIR%%/icons/update_uptodate.png
SUB_FILES+=	mozc_tool

do-build-mozc_tool:
	${BUILD_MOZC_CMD_BUILD} gui/gui.gyp:mozc_tool

do-install-mozc_tool:
	${INSTALL_PROGRAM} \
	    ${BUILD_WRKSRC}/out_linux/${BUILD_MODE}/mozc_tool \
	    ${STAGEDIR}${PREFIX}/libexec
	${INSTALL_SCRIPT} ${WRKDIR}/mozc_tool ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}/icons
	${INSTALL_DATA} \
	    ${BUILD_WRKSRC}/data/images/unix/ime_product_icon_opensource-32.png \
	    ${STAGEDIR}${DATADIR}/icons/product_logo.png
	${INSTALL_DATA} \
	    ${BUILD_WRKSRC}/data/images/unix/ime_product_icon_opensource-32.png \
	    ${STAGEDIR}${DATADIR}/icons/update_uptodate.png
.endif

# ibus_mozc
.if ${BUILD_MOZC_LIST:Mibus_mozc} == "ibus_mozc"
GYP_OPTIONS+=	--noqt
GYP_DEFINES+=	use_libibus=1 \
		enable_gtk_renderer=1

LIB_DEPENDS+=	libibus-1.0.so:textproc/ibus
RUN_DEPENDS+=	mozc_server:japanese/mozc-server \
		mozc_tool:japanese/mozc-tool \
		${PYTHON_SITELIBDIR}/gtk-2.0/pynotify/__init__.py:devel/py-notify

PLIST_FILES+=	libexec/mozc_renderer \
		libexec/ibus-engine-mozc \
		%%DATADIR%%/icons/alpha_full.png \
		%%DATADIR%%/icons/alpha_half.png \
		%%DATADIR%%/icons/dictionary.png \
		%%DATADIR%%/icons/direct.png \
		%%DATADIR%%/icons/hiragana.png \
		%%DATADIR%%/icons/katakana_full.png \
		%%DATADIR%%/icons/katakana_half.png \
		%%DATADIR%%/icons/product_icon.png \
		%%DATADIR%%/icons/properties.png \
		%%DATADIR%%/icons/tool.png \
		share/ibus/component/mozc.xml
PLIST_DIRS+=	%%DATADIR%%/icons ${DATADIR_REL}

do-build-ibus_mozc:
	${BUILD_MOZC_CMD_BUILD} \
	    unix/ibus/ibus.gyp:ibus_mozc \
	    renderer/renderer.gyp:mozc_renderer

do-install-ibus_mozc:
	${INSTALL_PROGRAM} \
	    ${BUILD_WRKSRC}/out_linux/${BUILD_MODE}/mozc_renderer \
	    ${STAGEDIR}${PREFIX}/libexec/mozc_renderer
	${INSTALL_PROGRAM} \
	    ${BUILD_WRKSRC}/out_linux/${BUILD_MODE}/ibus_mozc \
	    ${STAGEDIR}${PREFIX}/libexec/ibus-engine-mozc
	${MKDIR} ${STAGEDIR}${PREFIX}/share/ibus/component
	${INSTALL_DATA} \
	    ${BUILD_WRKSRC}/out_linux/${BUILD_MODE}/gen/unix/ibus/mozc.xml \
	    ${STAGEDIR}${PREFIX}/share/ibus/component/mozc.xml
	@${MKDIR} ${STAGEDIR}${DATADIR}/icons
.for F in ui-alpha_full ui-alpha_half ui-dictionary ui-direct \
	ui-hiragana ui-katakana_full ui-katakana_half ui-properties ui-tool
	${INSTALL_DATA} \
	    ${BUILD_WRKSRC}/data/images/unix/${F}.png \
	    ${STAGEDIR}${DATADIR}/icons/${F:S/^ui-//}.png
.endfor
	${INSTALL_DATA} \
	    ${BUILD_WRKSRC}/data/images/unix/ime_product_icon_opensource-32.png \
	    ${STAGEDIR}${DATADIR}/icons/product_icon.png
.endif

# uim_mozc
.if ${BUILD_MOZC_LIST:Muim_mozc} == "uim_mozc" || make(makesum)
GH_TUPLE+=	e-kato:macuim:v0.6.16.2.1:MU

LIB_DEPENDS+=	libuim.so:textproc/uim
RUN_DEPENDS+=	mozc_server:japanese/mozc-server \
		mozc_tool:japanese/mozc-tool

EXTRA_PATCHES=	${PATCHDIR}/extra-patch-src-unix-uim-mozc.cc \
		${PATCHDIR}/extra-patch-src-unix-uim-uim.gyp
PLIST_FILES+=	lib/uim/plugin/libuim-mozc.so \
		%%DATADIR%%/mozc.scm \
		%%DATADIR%%/mozc-custom.scm \
		%%DATADIR%%/mozc-key-custom.scm \
		%%DATADIR%%/pixmaps/mozc.png \
		"@postexec ${LOCALBASE}/bin/uim-module-manager --register mozc" \
		"@preunexec ${LOCALBASE}/bin/uim-module-manager --unregister mozc"

GYP_OPTIONS+=	--noqt
GYP_DEFINES+=	use_libibus=0 \
		enable_gtk_renderer=0

post-extract-uim_mozc:
	${MV} ${WRKSRC_MU}/Mozc/uim ${BUILD_WRKSRC}/unix
	${REINPLACE_CMD} -e "s,/usr/lib/mozc,${LOCALBASE}/libexec," \
	    ${WRKSRC_MU}/Mozc/scm/mozc-custom.scm

post-extract: post-extract-uim_mozc

do-build-uim_mozc:
	${BUILD_MOZC_CMD_BUILD} \
	    unix/uim/uim.gyp:uim-mozc

do-install-uim_mozc:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/uim/plugin
	${INSTALL_PROGRAM} \
	    ${BUILD_WRKSRC}/out_linux/${BUILD_MODE}/libuim-mozc.so \
	    ${STAGEDIR}${PREFIX}/lib/uim/plugin
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC_MU}/Mozc/scm && \
	    ${INSTALL_DATA} mozc.scm mozc-custom.scm mozc-key-custom.scm \
	    ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${DATADIR}/pixmaps
	${INSTALL_DATA} \
	    ${BUILD_WRKSRC}/data/images/product_icon_32bpp-128.png \
	    ${STAGEDIR}${DATADIR}/pixmaps/mozc.png
.endif

# fcitx_mozc
.if ${BUILD_MOZC_LIST:Mfcitx_mozc} == "fcitx_mozc" || make(makesum)
PATCH_SITES=	http://download.fcitx-im.org/fcitx-mozc/
PATCHFILES=	fcitx-mozc-2.17.2313.102.1.patch
.endif
.if ${BUILD_MOZC_LIST:Mfcitx_mozc} == "fcitx_mozc"
PATCH_DIST_STRIP=-p1
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-src-unix-fcitx-eim.cc \
	${PATCHDIR}/extra-patch-src-unix-fcitx-surrounding_text_util.cc

GYP_OPTIONS+=	--noqt
GYP_DEFINES+=	use_libibus=0 \
		enable_gtk_renderer=0

LIB_DEPENDS+=	libfcitx-core.so:chinese/fcitx
RUN_DEPENDS+=	mozc_server:japanese/mozc-server \
		mozc_tool:japanese/mozc-tool

PLIST_FILES+=	lib/fcitx/fcitx-mozc.so \
		share/fcitx/addon/fcitx-mozc.conf \
		share/fcitx/inputmethod/mozc.conf \
		%%DATADIR%%/icon/mozc.png \
		%%DATADIR%%/icon/mozc-alpha_full.png \
		%%DATADIR%%/icon/mozc-alpha_half.png \
		%%DATADIR%%/icon/mozc-direct.png \
		%%DATADIR%%/icon/mozc-hiragana.png \
		%%DATADIR%%/icon/mozc-katakana_full.png \
		%%DATADIR%%/icon/mozc-katakana_half.png \
		%%DATADIR%%/icon/mozc-dictionary.png \
		%%DATADIR%%/icon/mozc-properties.png \
		%%DATADIR%%/icon/mozc-tool.png \
		share/locale/ja/LC_MESSAGES/fcitx-mozc.mo \
		share/locale/zh_CN/LC_MESSAGES/fcitx-mozc.mo \
		share/locale/zh_TW/LC_MESSAGES/fcitx-mozc.mo
PLIST_DIRS+=	%%DATADIR%%/icon ${DATADIR_REL}

post-extract-fcitx_mozc:
	${RM} ${BUILD_WRKSRC}/unix/fcitx/fcitx.gyp

post-extract: post-extract-fcitx_mozc

do-build-fcitx_mozc:
	${BUILD_MOZC_CMD_BUILD} unix/fcitx/fcitx.gyp:fcitx-mozc

do-install-fcitx_mozc:
	@${MKDIR} \
	    ${STAGEDIR}${PREFIX}/lib/fcitx \
	    ${STAGEDIR}${PREFIX}/share/fcitx/addon \
	    ${STAGEDIR}${PREFIX}/share/fcitx/inputmethod
	${INSTALL_LIB} \
	    ${BUILD_WRKSRC}/out_linux/${BUILD_MODE}/fcitx-mozc.so \
	    ${STAGEDIR}${PREFIX}/lib/fcitx/fcitx-mozc.so
	${INSTALL_DATA} \
	    ${BUILD_WRKSRC}/unix/fcitx/fcitx-mozc.conf \
	    ${STAGEDIR}${PREFIX}/share/fcitx/addon/fcitx-mozc.conf
	${INSTALL_DATA} \
	    ${BUILD_WRKSRC}/unix/fcitx/mozc.conf \
	    ${STAGEDIR}${PREFIX}/share/fcitx/inputmethod/mozc.conf
	@${MKDIR} ${STAGEDIR}${DATADIR}/icon
.for F in ui-alpha_full ui-alpha_half ui-dictionary ui-direct \
	ui-hiragana ui-katakana_full ui-katakana_half ui-properties ui-tool
	${INSTALL_DATA} \
	    ${BUILD_WRKSRC}/data/images/unix/${F}.png \
	    ${STAGEDIR}${DATADIR}/icon/${F:S,^ui-,mozc-,}.png
.endfor
	${INSTALL_DATA} \
	    ${BUILD_WRKSRC}/data/images/product_icon_32bpp-128.png \
	    ${STAGEDIR}${DATADIR}/icon/mozc.png
.for L in ja zh_CN zh_TW
	${INSTALL_DATA} \
	    ${BUILD_WRKSRC}/out_linux/${BUILD_MODE}/gen/unix/fcitx/po/${L}.mo \
	    ${STAGEDIR}${PREFIX}/share/locale/${L}/LC_MESSAGES/fcitx-mozc.mo
.endfor
.endif

# mozc_el
.if ${BUILD_MOZC_LIST:Mmozc_el} == "mozc_el"
CATEGORIES+=	elisp
RUN_DEPENDS+=	mozc_server:japanese/mozc-server

PLIST_FILES+=	${EMACS_VERSION_SITE_LISPDIR}/mozc/mozc.elc \
		${EMACS_VERSION_SITE_LISPDIR}/mozc/mozc.el.gz \
		${EMACS_VERSION_SITE_LISPDIR}/mozc/leim-list.el
PLIST_DIRS+=	${EMACS_VERSION_SITE_LISPDIR}/mozc

post-patch-mozc_el:
	${REINPLACE_CMD} "s,%%PREFIX%%,${PREFIX}," \
	    ${BUILD_WRKSRC}/unix/emacs/mozc.el

post-patch: post-patch-mozc_el

do-build-mozc_el:
	cd ${BUILD_WRKSRC}/unix/emacs && \
	    ${EMACS_CMD} -batch -q -no-site-file -no-init-file \
	    -f batch-byte-compile mozc.el && \
	    ${GZIP_CMD} mozc.el

do-install-mozc_el:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/mozc
	${INSTALL_DATA} \
	    ${BUILD_WRKSRC}/unix/emacs/mozc.el.gz \
	    ${BUILD_WRKSRC}/unix/emacs/mozc.elc \
	    ${FILESDIR}/leim-list.el \
	    ${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/mozc/
.endif

do-build: ${BUILD_MOZC_LIST:S/^/do-build-/}
do-install: ${BUILD_MOZC_LIST:S/^/do-install-/}

.include <bsd.port.post.mk>
