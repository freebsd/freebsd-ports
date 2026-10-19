PORTNAME=	mozc
PORTVERSION=	3.35.6354.101
PORTREVISION=	1
CATEGORIES=	japanese
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTFILE_DEFAULT}

MAINTAINER=	hrs@FreeBSD.org
COMMENT?=	Mozc Japanese Input Method, Server
WWW=		https://github.com/google/mozc

USE_GITHUB=	yes
GH_TUPLE=	google:mozc:0136c35

BUILD_MOZC_LIST?=mozc_server
.if ${BUILD_MOZC_LIST:Mmozc_el} != "mozc_el" || make(makesum)
GH_TUPLE+=	bazelbuild:bazel-central-registry:9d03419:bcr \
		hiroyuki-komatsu:japanese-usage-dictionary:38d3462:udic/src/japanese_usage_dictionary \
		hiroyuki-komatsu:japanpost_zipcode:d630d72:zipcode/src/japanpost_zipcode
EXTRACT_ONLY+=	${DISTFILE_bcr} \
		${DISTFILE_udic} \
		${DISTFILE_zipcode}
.endif

BUILD_WRKSRC=	${WRKSRC}/src
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}
CONFLICTS_INSTALL=	${PKGNAMEPREFIX}${PORTNAME}3${PKGNAMESUFFIX}
.for P in ja-fcitx-mozc ja-ibus-mozc ja-mozc-tool ja-uim-mozc ja-mozc-el
CONFLICTS_INSTALL+=	${P}-2.*
.endfor

.if ${BUILD_MOZC_LIST:Mmozc_el} != "mozc_el"
BUILD_DEPENDS=	bazel9>=9.0.0:devel/bazel9 \
		bash:shells/bash
USES=		compiler:c++20-lang pkgconfig java:build python:3.12+,build
USE_CXXSTD=	c++20
JAVA_VERSION=	21
MAKE_ENV+=	JAVA_HOME=${JAVA_HOME:Q}
.endif

.if ${BUILD_MOZC_LIST:Mmozc_server} == "mozc_server"
PKGNAMEPREFIX=	ja-
PKGNAMESUFFIX=	-server
.elif ${BUILD_MOZC_LIST:Mmozc_tool} == "mozc_tool"
USES+=		gl qt:6
USE_GL=		gl
USE_QT=		base
.elif ${BUILD_MOZC_LIST:Mibus_mozc} == "ibus_mozc"
USES+=		gettext-runtime gnome gl qt:6
USE_GNOME+=	glib20
USE_GL=		gl
USE_QT=		base
.elif ${BUILD_MOZC_LIST:Mmozc_el} == "mozc_el"
CATEGORIES+=	elisp
USES+=		emacs
.elif ${BUILD_MOZC_LIST:Muim_mozc} == "uim_mozc"
USES+=		gettext-runtime
.elif ${BUILD_MOZC_LIST:Mfcitx5_mozc} == "fcitx5_mozc"
USES+=		gettext-tools
.endif

.include <bsd.port.pre.mk>
.if ${BUILD_MOZC_LIST:Mmozc_el} != "mozc_el"
. include "${FILESDIR}/Makefile.bazel"
.endif
.if ${BUILD_MOZC_LIST:Mmozc_el} != "mozc_el" || make(makesum)
. include "${FILESDIR}/Makefile.distfiles"
.endif
. include "${FILESDIR}/Makefile.licenses"

EMACS_SITE_LISPDIR?=	share/emacs/site-lisp
EXTRA_SUB_LIST=	PREFIX LOCALBASE DOCSDIR EMACS_SITE_LISPDIR
EXTRA_SUB_FILES= \
	config.bzl \
	bazel/pkg_config_repository.bzl
post-patch-apply-extra-slist:
	${REINPLACE_CMD} \
	    ${EXTRA_SUB_LIST:@v@-e 's|%%$v%%|${$v}|g'@} \
	    ${EXTRA_SUB_FILES:@v@${BUILD_WRKSRC}/$v@}
post-patch: post-patch-apply-extra-slist

.if ${BUILD_MOZC_LIST:Mmozc_el} != "mozc_el"
post-extract-zipcode:
	cd ${BUILD_WRKSRC} && ${UNZIP_NATIVE_CMD} -q \
	    japanpost_zipcode/ken_all.zip -d japanpost_zipcode
	cd ${BUILD_WRKSRC} && ${UNZIP_NATIVE_CMD} -q \
	    japanpost_zipcode/jigyosyo.zip -d japanpost_zipcode
post-extract: post-extract-zipcode
.endif

# mozc_server
.if ${BUILD_MOZC_LIST:Mmozc_server} == "mozc_server" || make(makesum)

PLIST_FILES+=	bin/mozc \
		bin/mozc_emacs_helper \
		libexec/mozc_server \
		libexec/mozc_emacs_helper \
		%%DATADIR%%/icons/mozc.png \
		%%DATADIR%%/icons/mozc.svg \
		%%DATADIR%%/icons/alpha_full.png \
		%%DATADIR%%/icons/alpha_full.svg \
		%%DATADIR%%/icons/alpha_half.png \
		%%DATADIR%%/icons/alpha_half.svg \
		%%DATADIR%%/icons/direct.png \
		%%DATADIR%%/icons/direct.svg \
		%%DATADIR%%/icons/hiragana.png \
		%%DATADIR%%/icons/hiragana.svg \
		%%DATADIR%%/icons/katakana_full.png \
		%%DATADIR%%/icons/katakana_full.svg \
		%%DATADIR%%/icons/katakana_half.png \
		%%DATADIR%%/icons/katakana_half.svg \
		%%DATADIR%%/icons/dictionary.png \
		%%DATADIR%%/icons/dictionary.svg \
		%%DATADIR%%/icons/properties.png \
		%%DATADIR%%/icons/properties.svg \
		%%DATADIR%%/icons/tool.png \
		%%DATADIR%%/icons/tool.svg \
		%%DATADIR%%/icons/white/dictionary.svg \
		%%DATADIR%%/icons/white/properties.svg \
		%%DATADIR%%/icons/white/tool.svg \
		%%DATADIR%%/icons/outlined/dictionary.svg \
		%%DATADIR%%/icons/outlined/properties.svg \
		%%DATADIR%%/icons/outlined/tool.svg
SUB_FILES+=	mozc

do-build-mozc_server:
	${BUILD_MOZC_CMD} \
	    //server:mozc_server \
	    //unix/emacs:mozc_emacs_helper \
	    //unix:icons

do-install-mozc_server:
	cd ${BUILD_WRKSRC} && ${INSTALL_PROGRAM} \
	    bazel-bin/server/mozc_server \
	    bazel-bin/unix/emacs/mozc_emacs_helper \
	    ${STAGEDIR}${PREFIX}/libexec
	${RLN} ${STAGEDIR}${PREFIX}/libexec/mozc_emacs_helper \
	    ${STAGEDIR}${PREFIX}/bin/mozc_emacs_helper
	${INSTALL_SCRIPT} \
	    ${WRKDIR}/mozc ${STAGEDIR}/${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}/icons
	${UNZIP_NATIVE_CMD} -q \
	    ${BUILD_WRKSRC}/bazel-bin/unix/icons.zip \
	    -d ${STAGEDIR}${DATADIR}/icons
.endif

# mozc_tool
.if ${BUILD_MOZC_LIST:Mmozc_tool} == "mozc_tool"
RUN_DEPENDS+=	${LOCALBASE}/libexec/mozc_server:japanese/mozc-server \
		xdg-open:devel/xdg-utils

PLIST_FILES+=	libexec/mozc_tool \
		bin/mozc_tool \
		%%DATADIR%%/icons/product_logo.png \
		%%DATADIR%%/icons/update_uptodate.png \
		%%DOCSDIR%%/credits_en.html
SUB_FILES+=	mozc_tool

do-build-mozc_tool:
	${BUILD_MOZC_CMD} //gui/tool:mozc_tool

do-install-mozc_tool:
	${INSTALL_PROGRAM} \
	    ${BUILD_WRKSRC}/bazel-bin/gui/tool/mozc_tool \
	    ${STAGEDIR}${PREFIX}/libexec
	${INSTALL_SCRIPT} ${WRKDIR}/mozc_tool ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}/icons
	${INSTALL_DATA} \
	    ${BUILD_WRKSRC}/data/images/unix/ime_product_icon_opensource-32.png \
	    ${STAGEDIR}${DATADIR}/icons/product_logo.png
	${INSTALL_DATA} \
	    ${BUILD_WRKSRC}/data/images/unix/ime_product_icon_opensource-32.png \
	    ${STAGEDIR}${DATADIR}/icons/update_uptodate.png
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} \
	    ${BUILD_WRKSRC}/data/installer/credits_en.html \
	    ${STAGEDIR}${DOCSDIR}
.endif

# ibus_mozc
.if ${BUILD_MOZC_LIST:Mibus_mozc} == "ibus_mozc"

LIB_DEPENDS+=	libibus-1.0.so:textproc/ibus
RUN_DEPENDS+=	${LOCALBASE}/libexec/mozc_server:japanese/mozc-server \
		mozc_tool:japanese/mozc-tool

PLIST_FILES+=	libexec/mozc_renderer \
		libexec/ibus-engine-mozc \
		share/ibus/component/mozc.xml

do-build-ibus_mozc:
	${BUILD_MOZC_CMD} \
	    //unix/ibus:ibus_mozc \
	    //unix/ibus:gen_mozc_xml \
	    //renderer/qt:mozc_renderer

do-install-ibus_mozc:
	${INSTALL_PROGRAM} \
	    ${BUILD_WRKSRC}/bazel-bin/renderer/qt/mozc_renderer \
	    ${STAGEDIR}${PREFIX}/libexec/mozc_renderer
	${INSTALL_PROGRAM} \
	    ${BUILD_WRKSRC}/bazel-bin/unix/ibus/ibus_mozc \
	    ${STAGEDIR}${PREFIX}/libexec/ibus-engine-mozc
	${MKDIR} ${STAGEDIR}${PREFIX}/share/ibus/component
	${INSTALL_DATA} \
	    ${BUILD_WRKSRC}/bazel-bin/unix/ibus/mozc.xml \
	    ${STAGEDIR}${PREFIX}/share/ibus/component/mozc.xml
.endif

# uim_mozc
.if ${BUILD_MOZC_LIST:Muim_mozc} == "uim_mozc" || make(makesum)
GH_TUPLE+=	e-kato:macuim:7beac7b:MU
EXTRACT_ONLY+=	${DISTFILE_MU}

LIB_DEPENDS+=	libuim.so:textproc/uim
RUN_DEPENDS+=	${LOCALBASE}/libexec/mozc_server:japanese/mozc-server \
		mozc_tool:japanese/mozc-tool

EXTRA_PATCHES=	${PATCHDIR}/extra-patch-src-MODULE-uim.bazel \
		${PATCHDIR}/extra-patch-src-unix-uim-mozc.cc \
		${PATCHDIR}/extra-patch-src-unix-uim-key_translator.h \
		${PATCHDIR}/extra-patch-src-unix-uim-key_translator.cc \
		${PATCHDIR}/extra-patch-src-unix-uim-scm-mozc-custom.scm \
		${PATCHDIR}/extra-patch-src-unix-uim-scm-mozc.scm
PLIST_FILES+=	lib/uim/plugin/libuim-mozc.so \
		%%DATADIR%%/mozc.scm \
		%%DATADIR%%/mozc-custom.scm \
		%%DATADIR%%/mozc-key-custom.scm \
		%%DATADIR%%/pixmaps/mozc.png \
		%%DATADIR%%/pixmaps/mozc_tool_selector.png \
		%%DATADIR%%/pixmaps/mozc_tool_config_dialog.png \
		%%DATADIR%%/pixmaps/mozc_tool_dictionary_tool.png \
		%%DATADIR%%/pixmaps/mozc_tool_word_register_dialog.png \
		%%DATADIR%%/pixmaps/mozc_tool_about_dialog.png \
		"@postexec ${LOCALBASE}/bin/uim-module-manager --register mozc" \
		"@preunexec ${LOCALBASE}/bin/uim-module-manager --unregister mozc"

post-extract-uim_mozc:
	${MV} ${WRKSRC_MU}/Mozc/uim ${BUILD_WRKSRC}/unix
	${MV} ${WRKSRC_MU}/Mozc/scm ${BUILD_WRKSRC}/unix/uim/scm
	${INSTALL_DATA} ${PATCHDIR}/extra-src-unix-uim-BUILD.bazel \
	    ${BUILD_WRKSRC}/unix/uim/BUILD.bazel

post-extract: post-extract-uim_mozc

post-patch-uim_mozc:
	${REINPLACE_CMD} -e "s,/usr/lib/mozc,${LOCALBASE}/libexec," \
	    ${BUILD_WRKSRC}/unix/uim/scm/mozc-custom.scm

post-patch: post-patch-uim_mozc

do-build-uim_mozc:
	${BUILD_MOZC_CMD} //unix/uim:uim-mozc

do-install-uim_mozc:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/uim/plugin
	${INSTALL_PROGRAM} \
	    ${BUILD_WRKSRC}/bazel-bin/unix/uim/libuim-mozc.so \
	    ${STAGEDIR}${PREFIX}/lib/uim/plugin
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${BUILD_WRKSRC}/unix/uim/scm && \
	    ${INSTALL_DATA} mozc.scm mozc-custom.scm mozc-key-custom.scm \
	    ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${DATADIR}/pixmaps
	${INSTALL_DATA} \
	    ${BUILD_WRKSRC}/data/images/product_icon_32bpp-128.png \
	    ${STAGEDIR}${DATADIR}/pixmaps/mozc.png
.for name icon in \
	selector tool \
	config_dialog properties \
	dictionary_tool dictionary \
	word_register_dialog dictionary \
	about_dialog mozc
	${LN} -sf ${LOCALBASE}/share/mozc/icons/${icon}.png \
	    ${STAGEDIR}${DATADIR}/pixmaps/mozc_tool_${name}.png
.endfor
.endif

# fcitx5_mozc
.if ${BUILD_MOZC_LIST:Mfcitx5_mozc} == "fcitx5_mozc" || make(makesum)
GH_TUPLE+=	fcitx:mozc:13ef96d:fcitx
EXTRACT_ONLY+=	${DISTFILE_fcitx}

MASTER_SITES+=	https://creativecommons.org/publicdomain/zero/1.0/:cc0
DISTFILES+=	legalcode.txt:cc0
.endif

.if ${BUILD_MOZC_LIST:Mfcitx5_mozc} == "fcitx5_mozc"
LIB_DEPENDS+=	libFcitx5Core.so:textproc/fcitx5
RUN_DEPENDS+=	${LOCALBASE}/libexec/mozc_server:japanese/mozc-server \
		xdg-open:devel/xdg-utils \
		mozc_tool:japanese/mozc-tool

EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-src-MODULE-fcitx5.bazel

PLIST_FILES+=	lib/fcitx5/fcitx5-mozc.so \
		share/fcitx5/addon/mozc.conf \
		share/fcitx5/inputmethod/mozc.conf \
		${FCITX5_MOZC_LOCALES:@l@share/locale/$l/LC_MESSAGES/fcitx5-mozc.mo@} \
		share/icons/hicolor/scalable/apps/fcitx_mozc.svg \
		${FCITX5_MOZC_ICONS:@i@share/icons/hicolor/scalable/apps/fcitx_mozc_$i.svg@} \
		share/metainfo/org.fcitx.Fcitx5.Addon.Mozc.metainfo.xml
FCITX5_MOZC_LOCALES=	ca da de fr he ja ka ko ru sv tr vi zh_CN zh_TW
FCITX5_MOZC_ICONS=	alpha_full alpha_half direct hiragana \
			katakana_full katakana_half dictionary properties tool

post-extract-fcitx5_mozc:
	${MV} ${WRKSRC_fcitx}/src/unix/fcitx5 ${BUILD_WRKSRC}/unix
	${MV} ${WRKSRC_fcitx}/src/unix/fcitx/gen_fcitx_mozc_i18n.sh \
	    ${BUILD_WRKSRC}/unix/fcitx5/

do-build-fcitx5_mozc:
	${BUILD_MOZC_CMD} //unix/fcitx5:fcitx5-mozc.so
	cd ${BUILD_WRKSRC}/unix/fcitx5 && \
	    ${LOCALBASE}/bin/msgfmt --xml -d po \
		--template org.fcitx.Fcitx5.Addon.Mozc.metainfo.xml.in \
		-o org.fcitx.Fcitx5.Addon.Mozc.metainfo.xml
	cd ${BUILD_WRKSRC}/unix/fcitx5 && \
	    ${SETENV} ${MAKE_ENV} ${SH} gen_fcitx_mozc_i18n.sh ./po

post-extract: post-extract-fcitx5_mozc

do-install-fcitx5_mozc:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/fcitx5 \
	    ${STAGEDIR}${PREFIX}/share/fcitx5/addon \
	    ${STAGEDIR}${PREFIX}/share/fcitx5/inputmethod
	${INSTALL_LIB} \
	    ${BUILD_WRKSRC}/bazel-bin/unix/fcitx5/fcitx5-mozc.so \
	    ${STAGEDIR}${PREFIX}/lib/fcitx5/
	${INSTALL_DATA} \
	    ${BUILD_WRKSRC}/unix/fcitx5/mozc-addon.conf \
	    ${STAGEDIR}${PREFIX}/share/fcitx5/addon/mozc.conf
	${INSTALL_DATA} \
	    ${BUILD_WRKSRC}/unix/fcitx5/mozc.conf \
	    ${STAGEDIR}${PREFIX}/share/fcitx5/inputmethod/mozc.conf
.for lang in ${FCITX5_MOZC_LOCALES}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/locale/${lang}/LC_MESSAGES
	${INSTALL_DATA} \
	    ${BUILD_WRKSRC}/unix/fcitx5/po/${lang}.mo \
	    ${STAGEDIR}${PREFIX}/share/locale/${lang}/LC_MESSAGES/fcitx5-mozc.mo
.endfor
	${MKDIR} ${STAGEDIR}${PREFIX}/share/metainfo
	${INSTALL_DATA} \
	    ${BUILD_WRKSRC}/unix/fcitx5/org.fcitx.Fcitx5.Addon.Mozc.metainfo.xml \
	    ${STAGEDIR}${PREFIX}/share/metainfo/
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${LN} -sf ${LOCALBASE}/share/mozc/icons/mozc.svg \
	    ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/fcitx_mozc.svg
.for icon in ${FCITX5_MOZC_ICONS}
	${LN} -sf ${LOCALBASE}/share/mozc/icons/${icon}.svg \
	    ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/fcitx_mozc_${icon}.svg
.endfor
.endif

# mozc_el
.if ${BUILD_MOZC_LIST:Mmozc_el} == "mozc_el"
RUN_DEPENDS+=	${LOCALBASE}/libexec/mozc_server:japanese/mozc-server

NO_ARCH=	yes
PLIST_FILES+=	${EMACS_SITE_LISPDIR}/mozc/mozc.el.gz \
		${EMACS_SITE_LISPDIR}/mozc/leim-list.el
PLIST_DIRS+=	${EMACS_SITE_LISPDIR}/mozc

EXTRA_SUB_FILES+= unix/emacs/mozc.el

do-build-mozc_el:
	cd ${BUILD_WRKSRC}/unix/emacs && ${GZIP_CMD} mozc.el

do-install-mozc_el:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/mozc
	${INSTALL_DATA} \
	    ${BUILD_WRKSRC}/unix/emacs/mozc.el.gz \
	    ${FILESDIR}/leim-list.el \
	    ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/mozc/
.endif

do-build: ${BUILD_MOZC_LIST:S/^/do-build-/}
do-install: ${BUILD_MOZC_LIST:S/^/do-install-/}

.include <bsd.port.post.mk>
