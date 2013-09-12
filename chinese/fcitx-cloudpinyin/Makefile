# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	fcitx-cloudpinyin
PORTVERSION=	0.3.0
PORTREVISION=	1
CATEGORIES=	chinese
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DIST_SUBDIR=	fcitx

MAINTAINER=	lichray@gmail.com
COMMENT=	A cloud-based Pinyin module for Fcitx

LIB_DEPENDS=	fcitx-config:${PORTSDIR}/chinese/fcitx \
		curl:${PORTSDIR}/ftp/curl

USE_XZ=		yes
USES=		cmake gettext pkgconfig
USE_GNOME=	intltool

PROJECTHOST=	fcitx

.include <bsd.port.mk>
