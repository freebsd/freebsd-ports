# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	fcitx-ui-light
PORTVERSION=	0.1.3
PORTREVISION=	1
CATEGORIES=	chinese
MASTER_SITES=	http://download.fcitx-im.org/${PORTNAME}/
DIST_SUBDIR=	fcitx

MAINTAINER=	lichray@gmail.com
COMMENT=	Alternative light weight UI for Fcitx

LICENSE=	GPLv2

LIB_DEPENDS=	libfcitx-config.so:chinese/fcitx \
		libfontconfig.so:x11-fonts/fontconfig

USE_XORG=	x11 xft xpm
USES=		tar:bzip2 cmake gettext pkgconfig
USE_GNOME=	intltool

.include <bsd.port.mk>
