# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	lollypop
DISTVERSION=	0.9.521
CATEGORIES=	audio

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Play and organize your music collection

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>=2.7.8:databases/py-sqlite3@${PY_FLAVOR} \
		itstool:textproc/itstool \
		${PYTHON_PKGNAMEPREFIX}dbus>=1.1.1:devel/py-dbus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gstreamer1>=1.4.0:multimedia/py-gstreamer1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pylast>=1.4.0:audio/py-pylast@${PY_FLAVOR}
LIB_DEPENDS=	libnotify.so:devel/libnotify \
		libappstream-glib.so:devel/appstream-glib \
		libtotem-plparser.so:multimedia/totem-pl-parser

USES=		python:3.4+ pkgconfig gettext meson shebangfix sqlite desktop-file-utils
USE_GITLAB=	yes
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	World
GL_COMMIT=	86ff0eac3231802b5dc49c50f6d89eec1aa08a7e
GL_TUPLE=	gnumdk:lollypop-po:1a41364ef42a2040292ec5c002cd2c8d93674c5e:po/subprojects/po
USE_GNOME=	glib20 gtk30 pygobject3 introspection:build intltool intlhack
USE_GSTREAMER1=	yes mpg123 ogg flac opus libav faad good speex
USE_PYTHON=	py3kplist noflavors
INSTALLS_ICONS=	yes

SHEBANG_FILES=	lollypop/*.py meson_post_install.py

GLIB_SCHEMAS=	org.gnome.Lollypop.gschema.xml

OPTIONS_DEFINE=	PULSEAUDIO
PULSEAUDIO_USE=	gstreamer1=pulse

SUB_FILES=	pkg-message

.include <bsd.port.mk>
