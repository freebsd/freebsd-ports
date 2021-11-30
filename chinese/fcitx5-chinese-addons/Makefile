# Created by: Ka Ho Ng <khng300@gmail.com>

PORTNAME=	fcitx5-chinese-addons
DISTVERSION=	5.0.8
CATEGORIES=	chinese textproc
MASTER_SITES=	https://download.fcitx-im.org/data/:py_stroke,py_table
DISTFILES=	${PY_STROKE_TAR}:py_stroke \
		${PY_TABLE_TAR}:py_table
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	khng@FreeBSD.org
COMMENT=	Pinyin and table input method support for Fcitx5

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSES/LGPL-2.1-or-later.txt

BUILD_DEPENDS=	fcitx5-lua>0:textproc/fcitx5-lua
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libfmt.so:devel/libfmt \
		libopencc.so:chinese/opencc \
		libboost_iostreams.so:devel/boost-libs \
		libIMEPinyin.so:chinese/libime \
		libFcitx5Core.so:textproc/fcitx5
RUN_DEPENDS=	fcitx5-lua>0:textproc/fcitx5-lua

USES=		compiler:c++17-lang gettext cmake kde:5 localbase pkgconfig

OPTIONS_DEFINE=		GUI
OPTIONS_DEFAULT=	GUI

USE_LDCONFIG=	yes

GUI_DESC=	Configuration GUI
GUI_USES=	qt:5
GUI_USE=	qt=dbus,concurrent,webkit,buildtools_build,qmake_build
GUI_LIB_DEPENDS=	libFcitx5Qt5DBusAddons.so:textproc/fcitx5-qt
GUI_CMAKE_ON=	-DUSE_WEBKIT:BOOL=true

USE_GITHUB=	yes
GH_ACCOUNT=	fcitx

USE_KDE=	ecm

CMAKE_ON=	ENABLE_OPENCC
CMAKE_OFF=	ENABLE_TEST
MAKE_ENV=	FCITX5_DOWNLOAD_DISALLOWED=TRUE

# These must follow modules/pinyinhelper/CMakeLists.txt
PY_STROKE_VER=	20121124
PY_TABLE_VER=	20121124
PY_STROKE_TAR=	py_stroke-${PY_STROKE_VER}.tar.gz
PY_TABLE_TAR=	py_table-${PY_TABLE_VER}.tar.gz

post-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${PY_STROKE_TAR} ${WRKSRC}/modules/pinyinhelper
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${PY_TABLE_TAR} ${WRKSRC}/modules/pinyinhelper

.include <bsd.port.mk>
