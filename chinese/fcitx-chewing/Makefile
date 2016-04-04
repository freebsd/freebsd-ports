# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	fcitx-chewing
PORTVERSION=	0.2.2
CATEGORIES=	chinese
MASTER_SITES=	http://download.fcitx-im.org/${PORTNAME}/
DIST_SUBDIR=	fcitx

MAINTAINER=	lichray@gmail.com
COMMENT=	Chewing support for Fcitx

LICENSE=	GPLv2

LIB_DEPENDS=	libfcitx-config.so:chinese/fcitx \
		libchewing.so:chinese/libchewing

USES=		tar:xz cmake gettext pkgconfig
INSTALLS_ICONS=	yes

.include <bsd.port.mk>
