# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	fcitx-sunpinyin
PORTVERSION=	0.4.2
PORTREVISION=	1
CATEGORIES=	chinese
MASTER_SITES=	http://download.fcitx-im.org/${PORTNAME}/
DIST_SUBDIR=	fcitx

MAINTAINER=	lichray@gmail.com
COMMENT=	SunPinyin support for Fcitx

LICENSE=	GPLv2

DEPRECATED=	Uses EOL Python 2.7 via chinese/fcitx
EXPIRATION_DATE=2021-06-23

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libfcitx-config.so:chinese/fcitx \
		libsunpinyin.so:chinese/sunpinyin

USES=		cmake gettext gnome pkgconfig tar:xz
INSTALLS_ICONS=	yes

.include <bsd.port.mk>
