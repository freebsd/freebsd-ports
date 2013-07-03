# Created by: Daichi GOTO <daichi@freebsd.org>
# $FreeBSD$

PORTNAME=	mozc
PORTVERSION=	1.10.1390.102
PORTREVISION=	5
CATEGORIES=	japanese
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	daichi@FreeBSD.org
COMMENT?=	Mozc Japanese Input Method, Server

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/third_party/gyp/LICENSE

EXTRACT_DEPENDS=${PYTHON_CMD}:${PYTHON_PORTSDIR}
LIB_DEPENDS=	protobuf:${PORTSDIR}/devel/protobuf \
		zinnia:${PORTSDIR}/japanese/zinnia
RUN_DEPENDS=	xdg-open:${PORTSDIR}/devel/xdg-utils

USES=		pkgconfig iconv
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PYTHON_BUILD=yes
USE_OPENSSL=	yes

MAKE_JOBS_SAFE=	yes

BUILD_MOZC_LIST?=	mozc_server

.if   ${BUILD_MOZC_LIST:Mmozc_server} == "mozc_server"
PKGNAMEPREFIX=	ja-
PKGNAMESUFFIX=	-server

LICENSE=		BSD NAISTL
LICENSE_COMB=		multi
LICENSE_FILE_BSD=	${WRKSRC}/third_party/gyp/LICENSE
LICENSE_DISTFILES_BSD=	${DISTNAME}${EXTRACT_SUFX}
LICENSE_NAME_NAISTL=	Nara Institute of Science and Technology License
LICENSE_PERMS_NAISTL=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_FILE_NAISTL=	${WRKSRC}/data/dictionary_oss/README.txt
LICENSE_DISTFILES_NAISTL=${DISTNAME}${EXTRACT_SUFX}
.elif ${BUILD_MOZC_LIST:Mmozc_tool} == "mozc_tool"
USE_GNOME=	glib20 gtk20
USE_QT4=	corelib gui qmake_build moc_build rcc_build uic_build
.elif ${BUILD_MOZC_LIST:Mibus_mozc} == "ibus_mozc"
USE_GNOME=	glib20 gtk20
.elif ${BUILD_MOZC_LIST:Mmozc_el} == "mozc_el"
USE_EMACS=	yes
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800107
BROKEN=		Does not compile on FreeBSD 7.X
.endif

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile: segfault
.endif

GYP_DEFINES=	use_libprotobuf=1 \
		channel_dev=0 \
		enable_unittest=0
BUILD_MODE=	Release
BUILD_CMD=	${SETENV} ${MAKE_ENV} PATH=/bin:/usr/bin:${PATH} ${GMAKE}
BUILD_MOZC_CMD=	cd ${BUILD_WRKSRC} && \
		${SETENV} BUILD_COMMAND="${WRKSRC}/mozcmake" \
		PYTHONPATH=${WRKSRC}/third_party/gyp/local/lib/python${PYTHON_VER}/site-packages \
		${DEBUG} \
		GYP_DEFINES="${GYP_DEFINES}" \
		CC_host="${CC}" \
		CXX_host="${CXX}" \
		LD_host="${CXX}" \
		AR_host="${AR}" \
		${PYTHON_CMD} build_mozc.py
BUILD_MOZC_CMD_BUILD=	${BUILD_MOZC_CMD} build -c ${BUILD_MODE} ${_MAKE_JOBS}
BUILD_GYP_CMD=	cd ${WRKSRC}/third_party/gyp && \
			${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYSETUP}

post-patch:
	${MKDIR} ${WRKSRC}/mozc_build_tools/linux
	${LN} -sf ${LOCALBASE}/bin/protoc ${WRKSRC}/mozc_build_tools/linux/
.if ${BUILD_MOZC_LIST:Mfcitx_mozc} == "fcitx_mozc"
	${REINPLACE_CMD} 's,/po/mo},%po}mo,g' \
		${WRKSRC}/unix/fcitx/gen_fcitx_mozc_i18n.sh
	${REINPLACE_CMD} "s,/usr,${LOCALBASE:Q}," \
		${WRKSRC}/unix/fcitx/mozc.conf
.endif

${WRKSRC}/mozcmake:
	${PRINTF} "%s\n%s\n" "#!/bin/sh" 'exec ${BUILD_CMD} $$@' \
		> ${WRKSRC}/mozcmake
	${CHMOD} +x ${WRKSRC}/mozcmake

post-configure: ${WRKSRC}/mozcmake
	${BUILD_GYP_CMD} ${PYDISTUTILS_CONFIGURE_TARGET} \
		${PYDISTUTILS_CONFIGUREARGS}
	${BUILD_GYP_CMD} ${PYDISTUTILS_BUILD_TARGET} ${PYDISTUTILS_BUILDARGS}
	${BUILD_GYP_CMD} ${PYDISTUTILS_INSTALL_TARGET} \
		--prefix=${WRKSRC}/third_party/gyp/local
	${BUILD_MOZC_CMD} gyp \
		--gypdir=${WRKSRC}/third_party/gyp/local/bin \
		--server_dir="${PREFIX}/bin" \
		--localbase="${LOCALBASE}" \
		--ldflags="${LDFLAGS} -fstack-protector -L${LOCALBASE}/lib" \
		--include_dirs="${LOCALBASE}/include" \
		--openssl_cflags="${OPENSSL_CFLAGS}" \
		--openssl_ldflags="${OPENSSL_LDFLAGS}" \
		--openssl_inc="-I${OPENSSLINC}" \
		--openssl_lib="-lssl -lcrypto -L${OPENSSLLIB}" \
		${GYP_OPTIONS}

pre-build:
	${BUILD_MOZC_CMD} build_tools -c ${BUILD_MODE} ${_MAKE_JOBS}

# mozc_server
.if ${BUILD_MOZC_LIST:Mmozc_server} == "mozc_server" || defined(makesum)
GYP_OPTIONS+=	--noqt
GYP_DEFINES+=	use_libibus=0 \
		enable_gtk_renderer=0

MASTER_SITES+=	LOCAL/kuriyama:zipcode
DISTFILES+= \
	ken_all-20130628.lzh:zipcode \
	jigyosyo-20130628.lzh:zipcode

EXTRACT_DEPENDS+=	lha:${PORTSDIR}/archivers/lha

PLIST_FILES+=	bin/mozc_server

post-extract-mozc_server:
	@for F in jigyosyo-20130628.lzh ken_all-20130628.lzh; do \
		${LHA_CMD} xfq2w=${WRKSRC}/data/dictionary_oss ${DISTDIR}/$$F; \
	done
	@cd ${WRKSRC}/data/dictionary_oss && \
		${PYTHON_CMD} ${WRKSRC}/dictionary/gen_zip_code_seed.py \
		--zip_code=ken_all.csv --jigyosyo=jigyosyo.csv \
		>> dictionary09.txt

post-extract: post-extract-mozc_server

do-build-mozc_server:
	${BUILD_MOZC_CMD_BUILD} server/server.gyp:mozc_server

do-install-mozc_server:
	${INSTALL_PROGRAM} \
		${WRKSRC}/out_linux/${BUILD_MODE}/mozc_server \
		${PREFIX}/bin
.endif

# mozc_tool
.if ${BUILD_MOZC_LIST:Mmozc_tool} == "mozc_tool"
GYP_DEFINES+=	use_libibus=0 \
		enable_gtk_renderer=1

RUN_DEPENDS+=	${LOCALBASE}/share/tegaki/models/zinnia/handwriting-ja.model:${PORTSDIR}/japanese/tegaki-zinnia-japanese

PLIST_FILES+=	bin/mozc_tool \
		%%DATADIR%%/icons/product_logo.png \
		%%DATADIR%%/icons/update_uptodate.png
PLIST_DIRS+=	%%DATADIR%%/icons ${DATADIR_REL}

do-build-mozc_tool:
	${BUILD_MOZC_CMD_BUILD} gui/gui.gyp:mozc_tool

do-install-mozc_tool:
	${INSTALL_PROGRAM} \
	       ${WRKSRC}/out_linux/${BUILD_MODE}/mozc_tool \
	       ${PREFIX}/bin
	@${MKDIR} ${DATADIR}/icons
	${INSTALL_DATA} \
		${WRKSRC}/data/images/unix/ime_product_icon_opensource-32.png \
		${DATADIR}/icons/product_logo.png
	${INSTALL_DATA} \
		${WRKSRC}/data/images/unix/ime_product_icon_opensource-32.png \
		${DATADIR}/icons/update_uptodate.png
.endif

# ibus_mozc
.if ${BUILD_MOZC_LIST:Mibus_mozc} == "ibus_mozc"
USE_XORG=	xcb
GYP_OPTIONS+=	--noqt
GYP_DEFINES+=	use_libibus=1 \
		enable_gtk_renderer=1

LIB_DEPENDS+=	ibus-1.0:${PORTSDIR}/textproc/ibus
RUN_DEPENDS+=	mozc_server:${PORTSDIR}/japanese/mozc-server \
		mozc_tool:${PORTSDIR}/japanese/mozc-tool \
		mozc_server_start:${PORTSDIR}/japanese/mozc-additions \
		${PYTHON_SITELIBDIR}/gtk-2.0/pynotify/__init__.py:${PORTSDIR}/devel/py-notify

PLIST_FILES+=	bin/mozc_renderer \
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
		${WRKSRC}/out_linux/${BUILD_MODE}/mozc_renderer \
		${PREFIX}/bin/mozc_renderer
	${INSTALL_PROGRAM} \
		${WRKSRC}/out_linux/${BUILD_MODE}/ibus_mozc \
		${PREFIX}/libexec/ibus-engine-mozc
	${INSTALL_DATA} \
		${WRKSRC}/out_linux/${BUILD_MODE}/obj/gen/unix/ibus/mozc.xml \
		${PREFIX}/share/ibus/component/mozc.xml
	@${MKDIR} ${DATADIR}/icons
.for F in ui-alpha_full ui-alpha_half ui-dictionary ui-direct \
	ui-hiragana ui-katakana_full ui-katakana_half ui-properties ui-tool
	${INSTALL_DATA} \
		${WRKSRC}/data/images/unix/${F}.png \
		${DATADIR}/icons/${F:S/^ui-//}.png
.endfor
	${INSTALL_DATA} \
		${WRKSRC}/data/images/unix/ime_product_icon_opensource-32.png \
		${DATADIR}/icons/product_icon.png
.endif

# fcitx_mozc
.if ${BUILD_MOZC_LIST:Mfcitx_mozc} == "fcitx_mozc" || make(makesum)
PATCH_SITES=	http://fcitx.googlecode.com/files/
PATCHFILES=	fcitx-${DISTNAME}.2.patch
.endif
.if ${BUILD_MOZC_LIST:Mfcitx_mozc} == "fcitx_mozc"
PATCH_DIST_STRIP=-p2

GYP_OPTIONS+=	--noqt
GYP_DEFINES+=	use_libibus=0 \
		enable_gtk_renderer=0

LIB_DEPENDS+=	fcitx-core:${PORTSDIR}/chinese/fcitx
RUN_DEPENDS+=	mozc_server:${PORTSDIR}/japanese/mozc-server \
		mozc_tool:${PORTSDIR}/japanese/mozc-tool \
		mozc_server_start:${PORTSDIR}/japanese/mozc-additions

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

do-build-fcitx_mozc:
	${BUILD_MOZC_CMD_BUILD} unix/fcitx/fcitx.gyp:fcitx-mozc

do-install-fcitx_mozc:
	@${MKDIR} \
		${PREFIX}/lib/fcitx \
		${PREFIX}/share/fcitx/addon \
		${PREFIX}/share/fcitx/inputmethod
	${INSTALL_LIB} \
		${WRKSRC}/out_linux/${BUILD_MODE}/fcitx-mozc.so \
		${PREFIX}/lib/fcitx/fcitx-mozc.so
	${INSTALL_DATA} \
		${WRKSRC}/unix/fcitx/fcitx-mozc.conf \
		${PREFIX}/share/fcitx/addon/fcitx-mozc.conf
	${INSTALL_DATA} \
		${WRKSRC}/unix/fcitx/mozc.conf \
		${PREFIX}/share/fcitx/inputmethod/mozc.conf
	@${MKDIR} ${DATADIR}/icon
.for F in ui-alpha_full ui-alpha_half ui-dictionary ui-direct \
	ui-hiragana ui-katakana_full ui-katakana_half ui-properties ui-tool
	${INSTALL_DATA} \
		${WRKSRC}/data/images/unix/${F}.png \
		${DATADIR}/icon/${F:S,^ui-,mozc-,}.png
.endfor
	${INSTALL_DATA} \
		${WRKSRC}/data/images/product_icon_32bpp-128.png \
		${DATADIR}/icon/mozc.png
.for L in ja zh_CN zh_TW
	${INSTALL_DATA} \
		${WRKSRC}/out_linux/${BUILD_MODE}/obj/gen/unix/fcitx/po/${L}.mo \
		${PREFIX}/share/locale/${L}/LC_MESSAGES/fcitx-mozc.mo
.endfor
.endif

# mozc_el
.if ${BUILD_MOZC_LIST:Mmozc_el} == "mozc_el"
GYP_OPTIONS+=	--noqt
GYP_DEFINES+=	use_libibus=0 \
		enable_gtk_renderer=0

CATEGORIES+=	elisp
RUN_DEPENDS+=	mozc_server:${PORTSDIR}/japanese/mozc-server \
		mozc_server_start:${PORTSDIR}/japanese/mozc-additions

PLIST_FILES+=	bin/mozc_emacs_helper \
		${EMACS_VERSION_SITE_LISPDIR}/mozc/mozc.el \
		${EMACS_VERSION_SITE_LISPDIR}/mozc/mozc.elc \
		${EMACS_VERSION_SITE_LISPDIR}/mozc/leim-list.el
PLIST_DIRS+=	${EMACS_VERSION_SITE_LISPDIR}/mozc

do-build-mozc_el:
	${BUILD_MOZC_CMD_BUILD} unix/emacs/emacs.gyp:mozc_emacs_helper
	cd ${WRKSRC}/unix/emacs && \
		${EMACS_CMD} -batch -q -no-site-file -no-init-file \
				-f batch-byte-compile mozc.el

do-install-mozc_el:
	${INSTALL_PROGRAM} \
		${WRKSRC}/out_linux/${BUILD_MODE}/mozc_emacs_helper \
		${PREFIX}/bin/
	@${MKDIR} ${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/mozc
	${INSTALL_DATA} \
		${WRKSRC}/unix/emacs/mozc.el \
		${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/mozc/
	${INSTALL_DATA} \
		${WRKSRC}/unix/emacs/mozc.elc \
		${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/mozc/
	${INSTALL_DATA} \
		${FILESDIR}/leim-list.el \
		${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/mozc/
.endif

do-build: ${BUILD_MOZC_LIST:S/^/do-build-/}
do-install: ${BUILD_MOZC_LIST:S/^/do-install-/}

.if defined(PKGMESSAGE) && exists(${PKGMESSAGE})
post-install:
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
