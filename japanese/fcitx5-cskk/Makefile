PORTNAME=	fcitx5-cskk
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.0
PORTREVISION=	2
CATEGORIES=	japanese textproc

MAINTAINER=	syobon@syobon.net
COMMENT=	SKK input method plugin for fcitx5 that uses LibCSKK
WWW=		https://github.com/fcitx/fcitx5-cskk

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcskk.so:japanese/cskk \
		libFcitx5Core.so:textproc/fcitx5
RUN_DEPENDS=	${LOCALBASE}/share/skk/SKK-JISYO.L:japanese/skk-jisyo

USES=		cmake gettext kde pkgconfig
USE_KDE=	ecm:build
USE_GITHUB=	yes
GH_ACCOUNT=	fcitx

CMAKE_ARGS+=	-DSKK_DICT_DEFAULT_PATH="${LOCALBASE}/share/skk/SKK-JISYO.L"

OPTIONS_SUB=		yes
OPTIONS_DEFINE=		QT5
OPTIONS_DEFAULT=	QT5

QT5_DESC=		Enable Qt for GUI configuration
QT5_LIB_DEPENDS+=	libFcitx5Qt5WidgetsAddons.so:textproc/fcitx5-qt@qt5
QT5_CMAKE_BOOL=		ENABLE_QT
QT5_USES=		qt:5
QT5_USE=		QT=core,gui,widgets,buildtools:build,qmake:build

.include <bsd.port.mk>
