PORTNAME=	fcitx5-rime
DISTVERSION=	5.1.12
CATEGORIES=	chinese textproc
MASTER_SITES=	https://download.fcitx-im.org/fcitx5/${PORTNAME}/

MAINTAINER=	khng@FreeBSD.org
COMMENT=	RIME support for Fcitx5
WWW=		https://github.com/fcitx/fcitx5-rime

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSES/LGPL-2.1-or-later.txt

BUILD_DEPENDS=	${_SCHEMA_DEPENDS}
LIB_DEPENDS=	libFcitx5Core.so:textproc/fcitx5 \
		librime.so:chinese/librime
RUN_DEPENDS=	${_SCHEMA_DEPENDS}

USES=		cmake compiler:c++17-lang gettext-tools kde:5 localbase \
		pkgconfig tar:zst

USE_KDE=	ecm

CONFLICTS_INSTALL=	zh-fcitx-rime # share/icons/hicolor/48x48/apps/fcitx-rime-deploy.png

_SCHEMA_DEPENDS=	\
	${LOCALBASE}/share/rime-data/bopomofo.schema.yaml:chinese/rime-bopomofo	\
	${LOCALBASE}/share/rime-data/cangjie5.schema.yaml:chinese/rime-cangjie	\
	${LOCALBASE}/share/rime-data/luna_pinyin.schema.yaml:chinese/rime-luna-pinyin	\
	${LOCALBASE}/share/rime-data/stroke.schema.yaml:chinese/rime-stroke

.include <bsd.port.mk>
