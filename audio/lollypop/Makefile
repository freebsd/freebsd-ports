# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	lollypop
PORTVERSION=	0.9.15
CATEGORIES=	audio
MASTER_SITES=	https://github.com/gnumdk/${PORTNAME}/releases/download/${PORTVERSION}/

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Play and organize your music collection

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>=2.7.8:databases/py-sqlite3 \
	${PYTHON_PKGNAMEPREFIX}dbus>=1.1.1:devel/py3-dbus \
	${PYTHON_PKGNAMEPREFIX}gstreamer1>=1.4.0:multimedia/py3-gstreamer1
LIB_DEPENDS=	libnotify.so:devel/libnotify \
	libtotem-plparser.so:multimedia/totem-pl-parser

USES=	shebangfix python:3 pkgconfig gettext gmake sqlite tar:xz
GNU_CONFIGURE=	yes
USE_GNOME=	glib20 gtk30 py3gobject3 introspection:build intltool intlhack
USE_GSTREAMER1=	yes mad ogg flac opus libav faad good speex
USE_PYTHON=	py3kplist
INSTALLS_ICONS=	yes

SHEBANG_FILES=	src/*.py

GLIB_SCHEMAS=	org.gnome.Lollypop.gschema.xml

OPTIONS_DEFINE=	PULSEAUDIO
PULSEAUDIO_USE=	gstreamer1=pulse

SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

.if defined(PACKAGE_BUILDING) && ${PYTHON_VER} != ${PYTHON_DEFAULT}
IGNORE=	you have python ${PYTHON_DEFAULT} set as the default, and this needs ${PYTHON_VER}
.endif

.include <bsd.port.post.mk>
