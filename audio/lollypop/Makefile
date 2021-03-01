# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	lollypop
DISTVERSION=	1.4.16
CATEGORIES=	audio

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Play and organize your music collection

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
		${PY_PILLOW}

USES=		python:3.6+ pkgconfig gnome gettext meson shebangfix sqlite desktop-file-utils
USE_GITLAB=	yes
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	World
GL_COMMIT=	5b2d95f4f8509d80fa86ab7d65b118326dc82a95
GL_TUPLE=	gnumdk:lollypop-po:94a7300004ec15adfd596c7d2b8670bbf5c2e33a:po/subprojects/po
USE_GNOME=	glib20 gtk30 pygobject3 introspection:build intltool intlhack
USE_GSTREAMER1=	yes mpg123 ogg flac opus libav faad good speex
USE_PYTHON=	py3kplist
INSTALLS_ICONS=	yes

SHEBANG_FILES=	lollypop.in search-provider/lollypop-sp.in meson_post_install.py

GLIB_SCHEMAS=	org.gnome.Lollypop.gschema.xml

BINARY_ALIAS=	python3=${PYTHON_VERSION}

OPTIONS_DEFINE=	PULSEAUDIO
PULSEAUDIO_USE=	gstreamer1=pulse

.include <bsd.port.mk>
