# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	fcitx-ui-light
PORTVERSION=	0.1.3
PORTREVISION=	1
CATEGORIES=	chinese
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DIST_SUBDIR=	fcitx

MAINTAINER=	lichray@gmail.com
COMMENT=	An alternative light weight UI for Fcitx

LIB_DEPENDS=	libfcitx-config.so:${PORTSDIR}/chinese/fcitx \
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig

USE_BZIP2=	yes
USE_XORG=	x11 xft xpm
USES=		cmake gettext pkgconfig
USE_GNOME=	intltool

PROJECTHOST=	fcitx

.include <bsd.port.mk>
