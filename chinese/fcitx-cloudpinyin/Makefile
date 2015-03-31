# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	fcitx-cloudpinyin
PORTVERSION=	0.3.4
CATEGORIES=	chinese
MASTER_SITES=	http://download.fcitx-im.org/${PORTNAME}/
DIST_SUBDIR=	fcitx

MAINTAINER=	lichray@gmail.com
COMMENT=	Cloud-based Pinyin module for Fcitx

LICENSE=	GPLv2

LIB_DEPENDS=	libfcitx-config.so:${PORTSDIR}/chinese/fcitx \
		libcurl.so:${PORTSDIR}/ftp/curl

USES=		tar:xz cmake gettext pkgconfig

.include <bsd.port.mk>
