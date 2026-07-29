PORTNAME=	ibus-array
PORTVERSION=	0.3.2
CATEGORIES=	chinese

MAINTAINER=	jiashiun@gmail.com
COMMENT=	Array 30 input method for IBus
WWW=		https://github.com/lexical/ibus-array/

LICENSE=	GPLv2

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${PY_FLAVOR} \
		ibus-daemon:textproc/ibus \
		zh-opencc>=1.0:chinese/opencc
RUN_DEPENDS=	ibus-daemon:textproc/ibus \
		zh-opencc>=1.0:chinese/opencc

USES=		gettext-tools gnome meson ninja pkgconfig python sqlite
USE_GITHUB=	yes
GH_ACCOUNT=	lexical
GH_TAGNAME=	release-${PORTVERSION}
USE_GNOME+=	glib20

BINARY_ALIAS=	python3=${PYTHON_CMD}

.include <bsd.port.mk>
