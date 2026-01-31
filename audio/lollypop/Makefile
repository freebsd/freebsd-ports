PORTNAME=	lollypop
DISTVERSION=	1.4.45
CATEGORIES=	audio
MASTER_SITES=	https://adishatz.org/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Play and organize your music collection
WWW=		https://gitlab.gnome.org/World/lollypop/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libnotify.so:devel/libnotify \
		libhandy-1.so:x11-toolkits/libhandy \
		libtotem-plparser.so:multimedia/totem-pl-parser \
		libsecret-1.so:security/libsecret \
		libsoup-3.0.so:devel/libsoup3
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup>0:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR}

USES=		desktop-file-utils gettext-tools gnome gstreamer meson \
		pkgconfig python shebangfix sqlite tar:xz
USE_GNOME=	glib20 gtk30 introspection:build pygobject3
GLIB_SCHEMAS=	org.gnome.Lollypop.gschema.xml
USE_GSTREAMER=	faad flac lame libav ogg opus speex ugly vorbis wavpack
USE_PYTHON=	py3kplist

SHEBANG_FILES=	lollypop.in search-provider/lollypop-sp.in meson_post_install.py

BINARY_ALIAS=	python3=${PYTHON_VERSION}
NO_ARCH=	yes

OPTIONS_DEFINE=	PULSEAUDIO
PULSEAUDIO_USE=	gstreamer=pulse

.include <bsd.port.mk>
