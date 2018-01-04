# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	lollypop
PORTVERSION=	0.9.15
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	https://github.com/gnumdk/${PORTNAME}/releases/download/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Play and organize your music collection

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>=2.7.8:databases/py-sqlite3@${PY_FLAVOR} \
		itstool:textproc/itstool \
	${PYTHON_PKGNAMEPREFIX}dbus>=1.1.1:devel/py-dbus@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}gstreamer1>=1.4.0:multimedia/py-gstreamer1@${PY_FLAVOR}
LIB_DEPENDS=	libnotify.so:devel/libnotify \
	libtotem-plparser.so:multimedia/totem-pl-parser

USES=	shebangfix python:3.4+ pkgconfig gettext gmake sqlite tar:xz
GNU_CONFIGURE=	yes
USE_GNOME=	glib20 gtk30 pygobject3 introspection:build intltool intlhack
USE_GSTREAMER1=	yes mpg123 ogg flac opus libav faad good speex
USE_PYTHON=	py3kplist
INSTALLS_ICONS=	yes

SHEBANG_FILES=	src/*.py

GLIB_SCHEMAS=	org.gnome.Lollypop.gschema.xml

OPTIONS_DEFINE=	PULSEAUDIO
PULSEAUDIO_USE=	gstreamer1=pulse

SUB_FILES=	pkg-message

.include <bsd.port.mk>
