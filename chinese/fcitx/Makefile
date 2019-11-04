# Created by: Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
# $FreeBSD$

PORTNAME=	fcitx
PORTVERSION=	4.2.9.6
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

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:misc/iso-codes \
		bash:shells/bash \
		${LOCALBASE}/libdata/pkgconfig/xkeyboard-config.pc:x11/xkeyboard-config
LIB_DEPENDS=	libcairo.so:graphics/cairo \
		libdbus-1.so:devel/dbus \
		libXfixes.so:x11/libXfixes \
		libXinerama.so:x11/libXinerama \
		libXrender.so:x11/libXrender \
		libxkbcommon.so:x11/libxkbcommon \
		libuuid.so:misc/e2fsprogs-libuuid
RUN_DEPENDS=	xdg-open:devel/xdg-utils \
		xkeyboard-config>=0:x11/xkeyboard-config

SUB_FILES=	pkg-message
SUB_LIST+=	PORTSDIR=${PORTSDIR}

CONFLICTS=	zh-scim-fcitx-3.*

USE_GNOME=	pango intltool libxml2 introspection
USE_KDE=	ecm
USE_XORG=	x11 xext xkbfile sm ice
USE_LDCONFIG=	yes
USES=		compiler:c++11-lang gnome tar:xz cmake:noninja desktop-file-utils \
		gettext-tools:build,run gettext-runtime iconv:wchar_t \
		kde:5 pkgconfig shared-mime-info compiler:c++14-lang xorg
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	GTK2 GTK3 OPENCC TPUNC DOCS
OPTIONS_DEFAULT=GTK2 GTK3
OPTIONS_SUB=	yes

GTK2_DESC=	Enable Gtk2 IM module
GTK2_USE=	GNOME=gtk20
GTK2_CMAKE_ON=	-DENABLE_GTK2_IM_MODULE=ON

GTK3_DESC=	Enable Gtk3 IM module
GTK3_USE=	GNOME=gtk30
GTK3_CMAKE_ON=	-DENABLE_GTK3_IM_MODULE=ON

OPENCC_DESC=	Enable OpenCC for Chinese Transform
TPUNC_DESC=	Use traditional quotation marks

.include <bsd.port.options.mk>

CMAKE_ARGS+=	-DENABLE_XDGAUTOSTART=OFF -DFORCE_ENCHANT=ON \
		-DLIBICONV_LIBC_HAS_ICONV_OPEN=OFF \
		-DDATADIR=${DATADIR} \
		-DDOCSDIR=${DOCSDIR} \
		-DGOBJECT_INTROSPECTION_GIRDIR=${PREFIX}/share/gir-1.0 \
		-DGOBJECT_INTROSPECTION_TYPELIBDIR=${PREFIX}/lib/girepository-1.0 \
		-DMANPREFIX=${MANPREFIX} \
		-DPREFIX=${PREFIX} \
		-DENABLE_QT=OFF -DENABLE_QT_IM_MODULE=OFF -DENABLE_QT_GUI=OFF

.if ${PORT_OPTIONS:MGTK2}
SUB_LIST+=	GTK2_IM=fcitx
.else
SUB_LIST+=	GTK2_IM=xim
.endif

.if ${PORT_OPTIONS:MGTK3}
PLIST_SUB+=	GTK3=""
SUB_LIST+=	GTK3_IM=fcitx
.else
PLIST_SUB+=	GTK3="@comment "
SUB_LIST+=	GTK3_IM=xim
.endif

.if ${PORT_OPTIONS:MOPENCC}
LIB_DEPENDS+=	libopencc.so:chinese/opencc
.else
CMAKE_ARGS+=	-DENABLE_OPENCC=OFF
.endif

.if ${PORT_OPTIONS:MTPUNC}
EXTRA_PATCHES+=	${FILESDIR}/tpunc-data_punc.mb.zh_CN
.endif

.if defined(WITH_DEBUG)
CMAKE_ARGS+=	-DENABLE_DEBUG=ON
.endif

_DICT_VER=	20121020
_PYSTROKE_VER=	20121124
_PYTABLE_VER=	20121124

post-patch:
	@${CP} ${_DISTDIR}/en_dict-${_DICT_VER}.tar.gz ${WRKSRC}/src/module/spell/dict/.
	@${CP} ${_DISTDIR}/pinyin.tar.gz ${WRKSRC}/src/im/pinyin/data/.
	@${CP} ${_DISTDIR}/py_stroke-${_PYSTROKE_VER}.tar.gz ${WRKSRC}/src/module/pinyin-enhance/data/.
	@${CP} ${_DISTDIR}/py_table-${_PYTABLE_VER}.tar.gz ${WRKSRC}/src/module/pinyin-enhance/data/.
	@${CP} ${_DISTDIR}/table.tar.gz ${WRKSRC}/src/im/table/data/.

.include <bsd.port.mk>
