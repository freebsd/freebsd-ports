# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	fcitx-ui-light
PORTVERSION=	0.1.3
PORTREVISION=	2
CATEGORIES=	chinese
MASTER_SITES=	http://download.fcitx-im.org/${PORTNAME}/
DIST_SUBDIR=	fcitx

MAINTAINER=	lichray@gmail.com
COMMENT=	Alternative light weight UI for Fcitx

LICENSE=	GPLv2

LIB_DEPENDS=	libfcitx-config.so:chinese/fcitx \
		libfontconfig.so:x11-fonts/fontconfig

USES=		tar:bzip2 cmake gettext gnome pkgconfig xorg
USE_XORG=	x11 xft xpm
USE_GNOME=	intltool

.include <bsd.port.mk>
