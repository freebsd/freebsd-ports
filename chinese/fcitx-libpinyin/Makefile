# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	fcitx-libpinyin
PORTVERSION=	0.3.2
CATEGORIES=	chinese
MASTER_SITES=	http://download.fcitx-im.org/${PORTNAME}/:body \
		http://download.fcitx-im.org/data/:data
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:body \
		model.text.${_MODEL_VER}.tar.gz:data
DIST_SUBDIR=	fcitx
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	lichray@gmail.com
COMMENT=	Libpinyin support for Fcitx

LICENSE=	GPLv2

LIB_DEPENDS=	libfcitx-config.so:chinese/fcitx \
		libpinyin.so:chinese/libpinyin

USES=		tar:xz cmake gettext pkgconfig
INSTALLS_ICONS=	yes

_MODEL_VER=	20130308

OPTIONS_DEFINE=	QT4
OPTIONS_DEFAULT=QT4
QT4_DESC=	Enable Qt4 for dictmanager

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MQT4}
USE_QT4=	qmake_build moc_build rcc_build uic_build gui webkit
USE_LDCONFIG=	${PREFIX}/lib/fcitx/qt
PLIST_SUB+=	QT4=""
.else
CMAKE_ARGS+=	-DENABLE_QT=OFF
PLIST_SUB+=	QT4="@comment "
.endif

post-patch:
	@${CP} ${_DISTDIR}/model.text.${_MODEL_VER}.tar.gz ${WRKSRC}/data/.

.include <bsd.port.mk>
