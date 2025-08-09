PORTNAME=	fcitx5-chinese-addons
DISTVERSION=	5.1.8
PORTREVISION=	2
CATEGORIES=	chinese textproc
MASTER_SITES=	https://download.fcitx-im.org/fcitx5/${PORTNAME}/ \
		https://download.fcitx-im.org/data/:py_stroke,py_table
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PY_STROKE_TAR}:py_stroke \
		${PY_TABLE_TAR}:py_table
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	khng@FreeBSD.org
COMMENT=	Pinyin and table input method support for Fcitx5
WWW=		https://github.com/fcitx/fcitx5-chinese-addons

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSES/LGPL-2.1-or-later.txt

BUILD_DEPENDS=	fcitx5-lua>0:textproc/fcitx5-lua
LIB_DEPENDS=	libboost_iostreams.so:devel/boost-libs \
		libcurl.so:ftp/curl \
		libFcitx5Core.so:textproc/fcitx5 \
		libfmt.so:devel/libfmt \
		libIMEPinyin.so:chinese/libime \
		libopencc.so:chinese/opencc
RUN_DEPENDS=	fcitx5-lua>0:textproc/fcitx5-lua

USES=		cmake compiler:c++17-lang gettext kde:5 localbase pkgconfig \
		tar:zst

OPTIONS_DEFINE=		GUI
OPTIONS_DEFAULT=	GUI

USE_LDCONFIG=	yes

GUI_DESC=	Configuration GUI
GUI_USES=	qt:5
GUI_USE=	qt=concurrent,dbus,webengine,buildtools:build,qmake:build
GUI_LIB_DEPENDS=	libFcitx5Qt5DBusAddons.so:textproc/fcitx5-qt@qt5
GUI_CMAKE_ON=	-DUSE_WEBKIT:BOOL=false

USE_KDE=	ecm
USE_QT=		core gui network widgets

CMAKE_ON=	ENABLE_OPENCC
CMAKE_OFF=	ENABLE_TEST USE_QT6
MAKE_ENV=	FCITX5_DOWNLOAD_DISALLOWED=TRUE

CONFLICTS_INSTALL=	zh-fcitx # share/icons/hicolor/16x16/apps/fcitx-fullwidth-active.png

# These must follow modules/pinyinhelper/CMakeLists.txt
PY_STROKE_VER=	20121124
PY_TABLE_VER=	20121124
PY_STROKE_TAR=	py_stroke-${PY_STROKE_VER}.tar.gz
PY_TABLE_TAR=	py_table-${PY_TABLE_VER}.tar.gz

post-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${PY_STROKE_TAR} ${WRKSRC}/modules/pinyinhelper
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${PY_TABLE_TAR} ${WRKSRC}/modules/pinyinhelper

.include <bsd.port.mk>
