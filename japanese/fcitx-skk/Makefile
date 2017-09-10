# $FreeBSD$

PORTNAME=	fcitx-skk
PORTVERSION=	0.1.2
PORTREVISION=	2
CATEGORIES=	japanese
MASTER_SITES=	http://download.fcitx-im.org/${PORTNAME}/
DIST_SUBDIR=	fcitx

MAINTAINER=	hiroto.kagotani@gmail.com
COMMENT=	SKK support for Fcitx

LICENSE=	GPLv3

RUN_DEPENDS=	${LOCALBASE}/share/skk/SKK-JISYO.L:japanese/skk-jisyo
LIB_DEPENDS=	libfcitx-config.so:chinese/fcitx \
		libskk.so:japanese/libskk

USES=		tar:xz compiler:c++11-lang cmake gettext pkgconfig
INSTALLS_ICONS=	yes
CMAKE_ARGS+=	-DSKK_DEFAULT_PATH=${LOCALBASE}/share/skk/SKK-JISYO.L

OPTIONS_DEFINE=	QT4
OPTIONS_DEFAULT=QT4
QT4_DESC=	Enable Qt for GUI configuration

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MQT4}
USE_QT4=	qmake_build moc_build rcc_build uic_build gui
USE_LDCONFIG=	${PREFIX}/lib/fcitx/qt
PLIST_SUB+=	QT4=""
.else
CMAKE_ARGS+=	-DENABLE_QT=OFF
PLIST_SUB+=	 QT4="@comment "
.endif

.include <bsd.port.mk>
