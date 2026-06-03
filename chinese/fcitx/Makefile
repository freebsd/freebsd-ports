PORTNAME=	fcitx
DISTVERSION=	4.2.9.9
PORTREVISION=	3
CATEGORIES=	chinese x11
MASTER_SITES=	http://download.fcitx-im.org/fcitx/:fcitx \
		http://download.fcitx-im.org/data/:data
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:fcitx \
		en_dict-${_DICT_VER}.tar.gz:data \
		pinyin.tar.gz:data \
		py_stroke-${_PYSTROKE_VER}.tar.gz:data \
		py_table-${_PYTABLE_VER}.tar.gz:data \
		table.tar.gz:data
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	lichray@gmail.com
COMMENT=	Flexible Input Method Framework
WWW=		https://fcitx-im.org/wiki/Fcitx

LICENSE=	GPLv2

BUILD_DEPENDS=	iso-codes>=0:misc/iso-codes \
		bash:shells/bash \
		${LOCALBASE}/libdata/pkgconfig/xkeyboard-config.pc:x11/xkeyboard-config
LIB_DEPENDS=	libcairo.so:graphics/cairo \
		libdbus-1.so:devel/dbus \
		libenchant-2.so:textproc/enchant2 \
		libjson-c.so:devel/json-c \
		libXfixes.so:x11/libXfixes \
		libXinerama.so:x11/libXinerama \
		libXrender.so:x11/libXrender \
		libxkbcommon.so:x11/libxkbcommon \
		libuuid.so:misc/libuuid
RUN_DEPENDS=	xdg-open:devel/xdg-utils \
		xkeyboard-config>=0:x11/xkeyboard-config

USES=		compiler:c++11-lang gnome tar:xz cmake:noninja desktop-file-utils \
		gettext-tools:build,run gettext-runtime iconv:wchar_t \
		kde:5 pkgconfig shared-mime-info compiler:c++14-lang xorg
USE_GNOME=	intltool introspection libxml2 pango
USE_KDE=	ecm:build
USE_LDCONFIG=	yes
USE_XORG=	ice sm x11 xext xkbfile

CMAKE_ARGS=	-DDATADIR=${DATADIR} \
		-DGOBJECT_INTROSPECTION_GIRDIR=${PREFIX}/share/gir-1.0 \
		-DGOBJECT_INTROSPECTION_TYPELIBDIR=${PREFIX}/lib/girepository-1.0 \
		-DPREFIX=${PREFIX}
CMAKE_ON=	FORCE_ENCHANT
.if defined(WITH_DEBUG)
CMAKE_ON+=	ENABLE_DEBUG
.endif
CMAKE_OFF=	ENABLE_QT \
		ENABLE_QT_IM_MODULE \
		ENABLE_QT_GUI \
		ENABLE_XDGAUTOSTART \
		LIBICONV_LIBC_HAS_ICONV_OPEN \

CONFLICTS_INSTALL=	fcitx5 zh-fcitx5-chinese-addons # bin/createPYMB share/icons/hicolor/128x128/apps/fcitx.png share/icons/hicolor/16x16/apps/fcitx-fullwidth-active.png

SUB_FILES=	pkg-message
SUB_LIST=	DESKTOPDIR=${DESKTOPDIR}

OPTIONS_DEFINE=		DOCS GTK2 GTK3 OPENCC TPUNC
OPTIONS_DEFAULT=	GTK2 GTK3
OPTIONS_SUB=		yes

GTK2_DESC=	Enable Gtk2 IM module
GTK3_DESC=	Enable Gtk3 IM module
OPENCC_DESC=	Enable OpenCC for Chinese Transform
TPUNC_DESC=	Use traditional quotation marks

GTK2_USE=		GNOME=gtk20
GTK2_CMAKE_BOOL=	ENABLE_GTK2_IM_MODULE
GTK2_VARS=		SUB_LIST+=GTK2_IM=fcitx
GTK2_VARS_OFF=		SUB_LIST+=GTK2_IM=xim

GTK3_USE=		GNOME=gtk30
GTK3_CMAKE_BOOL=	ENABLE_GTK3_IM_MODULE
GTK3_VARS=		SUB_LIST+=GTK3_IM=fcitx
GTK3_VARS_OFF=		SUB_LIST+=GTK3_IM=xim

OPENCC_LIB_DEPENDS=	libopencc.so:chinese/opencc
OPENCC_CMAKE_BOOL=	ENABLE_OPENCC

TPUNC_EXTRA_PATCHES=	${PATCHDIR}/tpunc-data_punc.mb.zh_CN

_DICT_VER=	20121020
_PYSTROKE_VER=	20121124
_PYTABLE_VER=	20121124

post-patch:
	@${CP} ${_DISTDIR}/en_dict-${_DICT_VER}.tar.gz ${WRKSRC}/src/module/spell/dict/
	@${CP} ${_DISTDIR}/pinyin.tar.gz ${WRKSRC}/src/im/pinyin/data/
	@${CP} ${_DISTDIR}/py_stroke-${_PYSTROKE_VER}.tar.gz ${WRKSRC}/src/module/pinyin-enhance/data/
	@${CP} ${_DISTDIR}/py_table-${_PYTABLE_VER}.tar.gz ${WRKSRC}/src/module/pinyin-enhance/data/
	@${CP} ${_DISTDIR}/table.tar.gz ${WRKSRC}/src/im/table/data/

.include <bsd.port.mk>
