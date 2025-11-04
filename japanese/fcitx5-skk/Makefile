PORTNAME=	fcitx5-skk
DISTVERSION=	5.1.8
CATEGORIES=	japanese textproc
MASTER_SITES=	https://download.fcitx-im.org/fcitx5/fcitx5-skk/

MAINTAINER=	mew14930xvi@inbox.lv
COMMENT=	SKK Kana-Kanji inputmethod for fcitx5
WWW=		https://github.com/fcitx/fcitx5-skk

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSES/GPL-3.0-or-later.txt

LIB_DEPENDS=	libFcitx5Core.so:textproc/fcitx5 \
		libskk.so:japanese/libskk
RUN_DEPENDS=	${LOCALBASE}/share/skk/SKK-JISYO.L:japanese/skk-jisyo

USES=		cmake compiler:c++17-lang gettext-tools gnome pkgconfig tar:zst
USE_GNOME=	glib20

CMAKE_ARGS+=	-DSKK_DEFAULT_PATH=${LOCALBASE}/share/skk/SKK-JISYO.L

OPTIONS_DEFINE=	QT6
OPTIONS_DEFAULT=	QT6
OPTIONS_SUB=	yes

QT6_DESC=	Enable Qt for GUI configuration
QT6_LIB_DEPENDS=	libFcitx5Qt6WidgetsAddons.so:textproc/fcitx5-qt@qt6
QT6_USES=	kde:6 qt:6
QT6_USE=	KDE=ecm QT=tools:build,base
QT6_CMAKE_BOOL=	ENABLE_QT

.include <bsd.port.mk>
