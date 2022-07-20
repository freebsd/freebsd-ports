PORTNAME=	ibus-rime
DISTVERSION=	1.5.0
CATEGORIES=	chinese

MAINTAINER=	khng300@gmail.com
COMMENT=	IBus engine for Rime users

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${_SCHEMA_DEPENDS}
LIB_DEPENDS=	libibus-1.0.so:textproc/ibus \
		libnotify.so:devel/libnotify \
		librime.so:chinese/librime
RUN_DEPENDS=	${_SCHEMA_DEPENDS}

USES=		cmake gnome pkgconfig
USE_CSTD=	c99

USE_GITHUB=	yes
GH_ACCOUNT=	rime

_SCHEMA_DEPENDS=	\
	${LOCALBASE}/share/rime-data/luna_pinyin.schema.yaml:chinese/rime-luna-pinyin	\
	${LOCALBASE}/share/rime-data/bopomofo.schema.yaml:chinese/rime-bopomofo	\
	${LOCALBASE}/share/rime-data/cangjie5.schema.yaml:chinese/rime-cangjie	\
	${LOCALBASE}/share/rime-data/stroke.schema.yaml:chinese/rime-stroke

.include <bsd.port.mk>
