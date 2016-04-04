# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fcitx-hangul
PORTVERSION=	0.3.0
CATEGORIES=	korean
MASTER_SITES=	http://download.fcitx-im.org/${PORTNAME}/
DIST_SUBDIR=	fcitx

MAINTAINER=	lichray@gmail.com
COMMENT=	Hangul support for Fcitx

LICENSE=	GPLv2

LIB_DEPENDS=	libfcitx-config.so:chinese/fcitx \
		libhangul.so:korean/libhangul

USES=		cmake gettext pkgconfig tar:xz
INSTALLS_ICONS=	yes

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lintl

.include <bsd.port.mk>
