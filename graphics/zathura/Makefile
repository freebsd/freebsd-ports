# Created by: Quentin Stievenart <acieroid@awesom.eu>
# $FreeBSD$

PORTNAME=	zathura
DISTVERSION=	0.4.3
PORTREVISION=	2
CATEGORIES=	graphics print
MASTER_SITES=	https://pwmt.org/projects/zathura/download/ \
		http://www.madpilot.net/~mad/pwmt.org/

MAINTAINER=	quentin.stievenart@gmail.com
COMMENT=	Customizable lightweight pdf viewer

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcairo.so:graphics/cairo \
		libgirara-gtk3.so:x11-toolkits/girara \
		libsynctex.so:devel/tex-synctex
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>0:textproc/py-sphinx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx_rtd_theme>0:textproc/py-sphinx_rtd_theme@${PY_FLAVOR}

USES=		compiler:c11 gettext-tools:build gnome meson ninja pkgconfig \
		python tar:xz
USE_GNOME=	glib20 gtk30 gdkpixbuf2
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=		SQLITE
OPTIONS_DEFAULT=	SQLITE

SQLITE_USES=		sqlite
SQLITE_MESON_ENABLED=	sqlite

.include <bsd.port.mk>
