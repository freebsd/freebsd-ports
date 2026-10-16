PORTNAME=	fcitx-libpinyin
PORTVERSION=	0.5.4
PORTREVISION=	4
CATEGORIES=	chinese
MASTER_SITES=	http://download.fcitx-im.org/${PORTNAME}/:body \
		http://download.fcitx-im.org/data/:data
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:body \
		model.text.${_MODEL_VER}.tar.gz:data
DIST_SUBDIR=	fcitx
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	lichray@gmail.com
COMMENT=	Libpinyin support for Fcitx
WWW=		https://fcitx-im.org/wiki/Fcitx

LICENSE=	GPLv2

BUILD_DEPENDS=	bash:shells/bash \
		zh-fcitx>0:chinese/fcitx
LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libpinyin.so:chinese/libpinyin

USES=		cmake gettext gnome pkgconfig tar:xz
USE_GNOME=	glib20

_MODEL_VER=	20161206

CMAKE_OFF=	ENABLE_QT

post-patch:
	@${CP} ${_DISTDIR}/model.text.${_MODEL_VER}.tar.gz ${WRKSRC}/data/.

.include <bsd.port.mk>
