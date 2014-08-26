# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	fcitx-googlepinyin
PORTVERSION=	0.1.6
CATEGORIES=	chinese
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DIST_SUBDIR=	fcitx

MAINTAINER=	lichray@gmail.com
COMMENT=	Libgooglepinyin support for Fcitx

LIB_DEPENDS=	libfcitx-config.so:${PORTSDIR}/chinese/fcitx \
		libgooglepinyin.so:${PORTSDIR}/chinese/libgooglepinyin

USES=		tar:xz cmake gettext pkgconfig iconv
USE_GNOME=	intltool

PROJECTHOST=	fcitx

.include <bsd.port.mk>
