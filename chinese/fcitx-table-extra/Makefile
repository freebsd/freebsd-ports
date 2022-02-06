# Created by: Zhihao Yuan <lichray@gmail.com>

PORTNAME=	fcitx-table-extra
PORTVERSION=	0.3.8
PORTREVISION=	1
CATEGORIES=	chinese
MASTER_SITES=	http://download.fcitx-im.org/${PORTNAME}/
DIST_SUBDIR=	fcitx

MAINTAINER=	lichray@gmail.com
COMMENT=	Table-based input methods for Fcitx

LICENSE=	GPLv2

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libfcitx-config.so:chinese/fcitx

USES=		cmake gettext gnome tar:xz

CONFLICTS_INSTALL=	zh-fcitx5-table-extra # share/icons/hicolor/48x48/apps/fcitx-cantonese.png
STRIP=

.include <bsd.port.mk>
