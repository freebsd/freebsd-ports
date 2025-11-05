PORTNAME=	fcitx5-cskk
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.0
PORTREVISION=   1
CATEGORIES=	japanese textproc

MAINTAINER=	syobon@syobon.net
COMMENT=	SKK input method plugin for fcitx5 that uses LibCSKK
WWW=		https://github.com/fcitx/fcitx5-cskk

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcskk.so:japanese/cskk \
		libFcitx5Core.so:textproc/fcitx5
RUN_DEPENDS=	${LOCALBASE}/share/skk/SKK-JISYO.L:japanese/skk-jisyo

USES=		cmake gettext pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	fcitx

CMAKE_ARGS+=	-DSKK_DICT_DEFAULT_PATH="${LOCALBASE}/share/skk/SKK-JISYO.L"

OPTIONS_SUB=		yes
OPTIONS_DEFINE=		QT5
OPTIONS_DEFAULT=	QT5

QT5_DESC=		Enable Qt for GUI configuration
QT5_LIB_DEPENDS+=	libFcitx5Qt5WidgetsAddons.so:textproc/fcitx5-qt@qt5
QT5_CMAKE_BOOL=		ENABLE_QT
QT5_USES=		kde:5 qt:5
QT5_USE=		KDE=ecm \
			QT=core,gui,widgets,buildtools:build,qmake:build

.include <bsd.port.mk>
