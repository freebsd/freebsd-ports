# Created by: Zhihao Yuan <lichray@gmail.com>

PORTNAME=	fcitx-chewing
PORTVERSION=	0.2.3
PORTREVISION=	1
CATEGORIES=	chinese
MASTER_SITES=	http://download.fcitx-im.org/${PORTNAME}/
DIST_SUBDIR=	fcitx

MAINTAINER=	lichray@gmail.com
COMMENT=	Chewing support for Fcitx

LICENSE=	GPLv2

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libfcitx-config.so:chinese/fcitx \
		libchewing.so:chinese/libchewing

USES=		cmake gettext gnome pkgconfig tar:xz

CONFLICTS_INSTALL=	zh-fcitx5-chewing # share/icons/hicolor/48x48/apps/fcitx-chewing.png

.include <bsd.port.mk>
