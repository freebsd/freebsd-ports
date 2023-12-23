PORTNAME=	drawing
DISTVERSION=	1.0.2
PORTREVISION=	2
CATEGORIES=	graphics

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Drawing application for the GNOME desktop
WWW=		https://maoschanz.github.io/drawing/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cairo>=0:graphics/py-cairo@${PY_FLAVOR} \
		itstool:textproc/itstool
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cairo>=0:graphics/py-cairo@${PY_FLAVOR}

USES=		desktop-file-utils gettext gnome meson pkgconfig python \
		shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	maoschanz
USE_GNOME=	glib20 gtk30 pygobject3

GLIB_SCHEMAS=	com.github.maoschanz.drawing.gschema.xml
SHEBANG_FILES=	build-aux/meson/postinstall.py

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes
NLS_MESON_TRUE=	enable-translations-and-appdata

.include <bsd.port.mk>
