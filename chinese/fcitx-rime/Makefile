# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	fcitx-rime
PORTVERSION=	0.3.2
PORTREVISION=	1
CATEGORIES=	chinese
MASTER_SITES=	http://download.fcitx-im.org/${PORTNAME}/
DIST_SUBDIR=	fcitx

MAINTAINER=	lichray@gmail.com
COMMENT=	RIME support for Fcitx

LICENSE=	GPLv2

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libfcitx-config.so:chinese/fcitx \
		librime.so:chinese/librime
RUN_DEPENDS=	${LOCALBASE}/share/brise/default.yaml:chinese/brise

USES=		cmake gettext gnome pkgconfig tar:xz
INSTALLS_ICONS=	yes

CMAKE_ARGS+=	-DBRISE_DIR=${LOCALBASE}/share/brise

.include <bsd.port.mk>
