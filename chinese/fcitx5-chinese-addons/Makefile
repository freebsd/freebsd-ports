PORTNAME=	fcitx5-chinese-addons
DISTVERSION=	5.1.15
CATEGORIES=	chinese textproc
MASTER_SITES=	https://download.fcitx-im.org/fcitx5/${PORTNAME}/ \
		https://download.fcitx-im.org/data/:py_stroke,py_table
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PY_STROKE_TAR}:py_stroke \
		${PY_TABLE_TAR}:py_table
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Pinyin and table input method support for Fcitx5
WWW=		https://github.com/fcitx/fcitx5-chinese-addons

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSES/LGPL-2.1-or-later.txt

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs \
		fcitx5-lua>0:textproc/fcitx5-lua \
		nlohmann-json>=3.2:devel/nlohmann-json
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libFcitx5Core.so:textproc/fcitx5 \
		libIMEPinyin.so:chinese/libime \
		libopencc.so:chinese/opencc
RUN_DEPENDS=	fcitx5-lua>0:textproc/fcitx5-lua

USES=		cmake compiler:c++17-lang gettext-tools kde localbase pkgconfig \
		tar:zst

OPTIONS_DEFINE=		GUI
OPTIONS_DEFAULT=	GUI

USE_LDCONFIG=	yes

GUI_DESC=	Configuration GUI
GUI_USES=	qt:6
GUI_USE=	qt=base,webengine
GUI_LIB_DEPENDS=	libFcitx5Qt6WidgetsAddons.so:textproc/fcitx5-qt@qt6
GUI_CMAKE_ON=	-DUSE_WEBKIT:BOOL=false

USE_KDE=	ecm:build

CMAKE_ON=	ENABLE_OPENCC
CMAKE_OFF=	ENABLE_TEST
MAKE_ENV=	FCITX5_DOWNLOAD_DISALLOWED=TRUE

CONFLICTS_INSTALL=	zh-fcitx # share/icons/hicolor/16x16/apps/fcitx-fullwidth-active.png

# These must follow modules/pinyinhelper/CMakeLists.txt
PY_STROKE_VER=	20250329
PY_TABLE_VER=	20121124
PY_STROKE_TAR=	py_stroke-${PY_STROKE_VER}.tar.gz
PY_TABLE_TAR=	py_table-${PY_TABLE_VER}.tar.gz

post-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${PY_STROKE_TAR} ${WRKSRC}/modules/pinyinhelper
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${PY_TABLE_TAR} ${WRKSRC}/modules/pinyinhelper

.include <bsd.port.mk>
