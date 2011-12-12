# New ports collection makefile for:	mozc-server
# Date created:				26 June 2010
# Whom:					Daichi GOTO <daichi@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	mozc
PORTVERSION=	1.3.911.102
PORTREVISION=	1
CATEGORIES=	japanese
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PKGNAMEPREFIX?=	ja-
PKGNAMESUFFIX?=	-server

MAINTAINER=	daichi@FreeBSD.org
COMMENT?=	Mozc server for IBus, SCIM and others

LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl \
		gtest.0:${PORTSDIR}/devel/googletest \
		protobuf.7:${PORTSDIR}/devel/protobuf \
		zinnia.0:${PORTSDIR}/japanese/zinnia
RUN_DEPENDS=	xdg-open:${PORTSDIR}/devel/xdg-utils

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
USE_PYTHON=	yes

BUILD_MOZC_LIST?=	mozc_server

.if ${BUILD_MOZC_LIST:Mmozc_tool} == "mozc_tool"
USE_QT_VER=	4
QT_COMPONENTS=	gui dbus qmake_build moc_build uic_build rcc_build
.endif
.if ${BUILD_MOZC_LIST:Mibus_mozc} == "ibus_mozc" || ${BUILD_MOZC_LIST:Mscim_mozc} == "scim_mozc"
USE_GNOME=	pygtk2
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800107
BROKEN=		Does not compile on FreeBSD 7.X
.endif

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile: segfault
.endif

.if defined(WITH_DEBUG_CODE)
BUILD_MODE=	Debug
.else
BUILD_MODE=	Release
.endif

LOCALBASE_REPLACE_FILES= \
		build_mozc.py \
		gyp/common.gypi \
		unix/ibus/gen_mozc_xml.py \
		unix/ibus/mozc.xml \
		unix/ibus/path_util.cc \
		unix/scim/scim.gyp \
		unix/scim/scim_mozc.cc \
		base/util.cc \
		base/process.cc \
		gui/about_dialog/about_dialog.cc \
		handwriting/zinnia_handwriting.cc

BUILD_CMD=	${SETENV} ${MAKE_ENV} ${GMAKE}
BUILD_MOZC_CMD=	cd ${BUILD_WRKSRC} && \
		${SETENV} BUILD_COMMAND="${WRKSRC}/mozcmake" \
		PYTHONPATH=${WRKSRC}/third_party/gyp/local/lib/python${PYTHON_VER}/site-packages \
		FLOCK= \
		${PYTHON_CMD} build_mozc.py
BUILD_GYP_CMD=	cd ${WRKSRC}/third_party/gyp && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYSETUP}

post-patch:
	cd ${WRKSRC} && \
		${REINPLACE_CMD} "s/@@LOCALBASE@@/${LOCALBASE:S/\//\\\//g}/g" \
		${LOCALBASE_REPLACE_FILES}

pre-build:
	${PRINTF} "%s\n%s\n" "#!/bin/sh" 'exec ${BUILD_CMD} $$@' > ${WRKSRC}/mozcmake
	${CHMOD} +x ${WRKSRC}/mozcmake
	${BUILD_GYP_CMD} ${PYDISTUTILS_CONFIGURE_TARGET} ${PYDISTUTILS_CONFIGUREARGS}
	${BUILD_GYP_CMD} ${PYDISTUTILS_BUILD_TARGET} ${PYDISTUTILS_BUILDARGS}
	${BUILD_GYP_CMD} ${PYDISTUTILS_INSTALL_TARGET} --prefix=${WRKSRC}/third_party/gyp/local
	${BUILD_MOZC_CMD} gyp --gypdir=${WRKSRC}/third_party/gyp/local/bin
	${BUILD_MOZC_CMD} build_tools -c ${BUILD_MODE}

# mozc_server
.if ${BUILD_MOZC_LIST:Mmozc_server} == "mozc_server"
PLIST_FILES+=	bin/mozc_server

do-build-mozc_server:
	${BUILD_MOZC_CMD} build -c ${BUILD_MODE} server/server.gyp:mozc_server

do-install-mozc_server:
	@${INSTALL_PROGRAM} \
		${WRKSRC}/out_linux/${BUILD_MODE}/mozc_server \
		${PREFIX}/bin
.endif

# mozc_tool
.if ${BUILD_MOZC_LIST:Mmozc_tool} == "mozc_tool"
RUN_DEPENDS+=	${LOCALBASE}/share/tegaki/models/zinnia/handwriting-ja.model:${PORTSDIR}/japanese/tegaki-zinnia-japanese

PLIST_FILES+=	bin/mozc_tool \
		${DATADIR_REL}/icons/product_logo.png \
		${DATADIR_REL}/icons/update_uptodate.png
PLIST_DIRS+=	${DATADIR_REL}/icons ${DATADIR_REL}

do-build-mozc_tool:
	${BUILD_MOZC_CMD} build -c ${BUILD_MODE} gui/gui.gyp:mozc_tool

do-install-mozc_tool:
	@${INSTALL_PROGRAM} \
	       ${WRKSRC}/out_linux/${BUILD_MODE}/mozc_tool \
	       ${PREFIX}/bin
	@${MKDIR} ${DATADIR}/icons
	@${INSTALL_DATA} \
		${WRKSRC}/data/images/unix/ime_product_icon_opensource-32.png \
		${DATADIR}/icons/product_logo.png
	@${INSTALL_DATA} \
		${WRKSRC}/data/images/unix/ime_product_icon_opensource-32.png \
		${DATADIR}/icons/update_uptodate.png
.endif

# ibus_mozc
.if ${BUILD_MOZC_LIST:Mibus_mozc} == "ibus_mozc"
LIB_DEPENDS+=	ibus.2:${PORTSDIR}/textproc/ibus
RUN_DEPENDS+=	mozc_server:${PORTSDIR}/japanese/mozc-server \
		mozc_tool:${PORTSDIR}/japanese/mozc-tool \
		mozc_server_start:${PORTSDIR}/japanese/mozc-additions \
		${PYTHON_SITELIBDIR}/gtk-2.0/pynotify/_pynotify.so:${PORTSDIR}/devel/py-notify

PLIST_FILES+=	libexec/ibus-engine-mozc \
		share/ibus/component/mozc.xml \
		${DATADIR_REL}/icons/alpha_full.png \
		${DATADIR_REL}/icons/alpha_half.png \
		${DATADIR_REL}/icons/dictionary.png \
		${DATADIR_REL}/icons/direct.png \
		${DATADIR_REL}/icons/hiragana.png \
		${DATADIR_REL}/icons/katakana_full.png \
		${DATADIR_REL}/icons/katakana_half.png \
		${DATADIR_REL}/icons/product_logo.png \
		${DATADIR_REL}/icons/properties.png \
		${DATADIR_REL}/icons/tool.png
PLIST_DIRS+=	${DATADIR_REL}/icons ${DATADIR_REL}

do-build-ibus_mozc:
	${BUILD_MOZC_CMD} build -c ${BUILD_MODE} unix/ibus/ibus.gyp:ibus_mozc

do-install-ibus_mozc:
	${INSTALL_PROGRAM} \
		${WRKSRC}/out_linux/${BUILD_MODE}/ibus_mozc \
		${PREFIX}/libexec/ibus-engine-mozc
	${INSTALL_DATA} \
		${WRKSRC}/unix/ibus/mozc.xml \
		${PREFIX}/share/ibus/component/mozc.xml
	${MKDIR} ${DATADIR}/icons
.for F in ui-alpha_full ui-alpha_half ui-dictionary ui-direct \
	ui-hiragana ui-katakana_full ui-katakana_half ui-properties ui-tool
	${INSTALL_DATA} \
		${WRKSRC}/data/images/unix/${F}.png \
		${DATADIR}/icons/${F:S/^ui-//}.png
.endfor
	@${INSTALL_DATA} \
		${WRKSRC}/data/images/unix/ime_product_icon_opensource-32.png \
		${DATADIR}/icons/product_logo.png
.endif

# scim_mozc
.if ${BUILD_MOZC_LIST:Mscim_mozc} == "scim_mozc"
BUILD_DEPENDS+=	scim:${PORTSDIR}/textproc/scim
RUN_DEPENDS+=	scim:${PORTSDIR}/textproc/scim \
		mozc_server:${PORTSDIR}/japanese/mozc-server \
		mozc_tool:${PORTSDIR}/japanese/mozc-tool \
		mozc_server_start:${PORTSDIR}/japanese/mozc-additions \
		${PYTHON_SITELIBDIR}/gtk-2.0/pynotify/_pynotify.so:${PORTSDIR}/devel/py-notify

PLIST_FILES+=	lib/scim-1.0/1.4.0/IMEngine/mozc.so \
		lib/scim-1.0/1.4.0/SetupUI/mozc_setup.so \
		${DATADIR_REL}/icons/scim-mozc-alpha_full.png \
		${DATADIR_REL}/icons/scim-mozc-alpha_half.png \
		${DATADIR_REL}/icons/scim-mozc-dictionary.png \
		${DATADIR_REL}/icons/scim-mozc-direct.png \
		${DATADIR_REL}/icons/scim-mozc-hiragana.png \
		${DATADIR_REL}/icons/scim-mozc-katakana_full.png \
		${DATADIR_REL}/icons/scim-mozc-katakana_half.png \
		${DATADIR_REL}/icons/scim-mozc-properties.png \
		${DATADIR_REL}/icons/scim-mozc-tool.png \
		${DATADIR_REL}/icons/scim-mozc.png
PLIST_DIRS+=	${DATADIR_REL}/icons ${DATADIR_REL}

do-build-scim_mozc:
	${BUILD_MOZC_CMD} build -c ${BUILD_MODE} \
		unix/scim/scim.gyp:scim_mozc \
		unix/scim/scim.gyp:scim_mozc_setup

do-install-scim_mozc:
	${INSTALL_LIB} \
		${WRKSRC}/out_linux/${BUILD_MODE}/lib.target/libscim_mozc.so \
		${PREFIX}/lib/scim-1.0/1.4.0/IMEngine/mozc.so
	${INSTALL_LIB} \
		${WRKSRC}/out_linux/${BUILD_MODE}/lib.target/libscim_mozc_setup.so \
		${PREFIX}/lib/scim-1.0/1.4.0/SetupUI/mozc_setup.so
	@${MKDIR} ${DATADIR}/icons
.for F in ui-alpha_full ui-alpha_half ui-dictionary ui-direct \
	ui-hiragana ui-katakana_full ui-katakana_half ui-properties ui-tool
	@${INSTALL_DATA} \
		${WRKSRC}/data/images/unix/${F}.png \
		${DATADIR}/icons/${F:S/^ui-/scim-mozc-/}.png
.endfor
	@${INSTALL_DATA} \
		${WRKSRC}/data/images/unix/ime_product_icon_opensource-32.png \
		${DATADIR}/icons/scim-mozc.png
.endif

do-build: ${BUILD_MOZC_LIST:S/^/do-build-/}
do-install: ${BUILD_MOZC_LIST:S/^/do-install-/}

.include <bsd.port.post.mk>
