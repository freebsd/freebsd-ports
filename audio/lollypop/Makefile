PORTNAME=	lollypop
DISTVERSION=	1.4.41
PORTREVISION=	1
CATEGORIES=	audio

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Play and organize your music collection
WWW=		https://gitlab.gnome.org/World/lollypop/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS} \
		itstool:textproc/itstool
LIB_DEPENDS=	libnotify.so:devel/libnotify \
		libhandy-1.so:x11-toolkits/libhandy \
		libappstream-glib.so:devel/appstream-glib \
		libtotem-plparser.so:multimedia/totem-pl-parser
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>=2.7.8:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cairo>=1.0.0:graphics/py-cairo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.0.0:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dbus>=1.1.1:devel/py-dbus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gstreamer1>=1.4.0:multimedia/py-gstreamer1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pylast>=1.4.0:audio/py-pylast@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=7.0.0:graphics/py-pillow@${PY_FLAVOR}

USES=		desktop-file-utils gettext-tools gnome gstreamer meson \
		pkgconfig python shebangfix sqlite
USE_GITLAB=	yes
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	World
GL_TUPLE=	gnumdk:lollypop-po:b3cebddfcc906d5bb72dcfe8f77c7e228d17b1fa:po/subprojects/po
USE_GNOME=	glib20 gtk30 intlhack intltool introspection:build pygobject3
GLIB_SCHEMAS=	org.gnome.Lollypop.gschema.xml
USE_GSTREAMER=	faad flac good libav mpg123 ogg opus speex
USE_PYTHON=	py3kplist

SHEBANG_FILES=	lollypop.in search-provider/lollypop-sp.in meson_post_install.py

BINARY_ALIAS=	python3=${PYTHON_VERSION}
NO_ARCH=	yes

OPTIONS_DEFINE=	PULSEAUDIO
PULSEAUDIO_USE=	gstreamer=pulse

.include <bsd.port.mk>
