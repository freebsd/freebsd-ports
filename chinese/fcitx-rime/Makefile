PORTNAME=	fcitx-rime
DISTVERSION=	0.3.2
PORTREVISION=	3
CATEGORIES=	chinese
MASTER_SITES=	https://download.fcitx-im.org/${PORTNAME}/
DIST_SUBDIR=	fcitx

PATCH_SITES=	https://github.com/fcitx/${PORTNAME}/commit/
PATCHFILES=	a3a9fffb6ee89adc327ad8a7dec05d5f35414f9d.patch:-p1

MAINTAINER=	khng300@gmail.com
COMMENT=	RIME support for Fcitx
WWW=		https://fcitx-im.org/wiki/Fcitx

LICENSE=	GPLv2

BROKEN=		does not compile against currect chinese/librime

BUILD_DEPENDS=	bash:shells/bash \
		${_SCHEMA_DEPENDS}
LIB_DEPENDS=	libfcitx-config.so:chinese/fcitx \
		librime.so:chinese/librime
RUN_DEPENDS=	${_SCHEMA_DEPENDS}

USES=		cmake gettext gnome localbase pkgconfig tar:xz

CONFLICTS_INSTALL=	zh-fcitx5-rime # share/icons/hicolor/48x48/apps/fcitx-rime-deploy.png

_SCHEMA_DEPENDS=	\
	${LOCALBASE}/share/rime-data/luna_pinyin.schema.yaml:chinese/rime-luna-pinyin	\
	${LOCALBASE}/share/rime-data/bopomofo.schema.yaml:chinese/rime-bopomofo	\
	${LOCALBASE}/share/rime-data/cangjie5.schema.yaml:chinese/rime-cangjie	\
	${LOCALBASE}/share/rime-data/stroke.schema.yaml:chinese/rime-stroke

.include <bsd.port.mk>
