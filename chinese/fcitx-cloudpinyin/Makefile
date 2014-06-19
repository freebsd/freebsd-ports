# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	fcitx-cloudpinyin
PORTVERSION=	0.3.0
PORTREVISION=	1
CATEGORIES=	chinese
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DIST_SUBDIR=	fcitx

MAINTAINER=	lichray@gmail.com
COMMENT=	Cloud-based Pinyin module for Fcitx

LIB_DEPENDS=	libfcitx-config.so:${PORTSDIR}/chinese/fcitx \
		libcurl.so:${PORTSDIR}/ftp/curl

USES=		tar:xz cmake gettext pkgconfig
USE_GNOME=	intltool

PROJECTHOST=	fcitx

.include <bsd.port.mk>
