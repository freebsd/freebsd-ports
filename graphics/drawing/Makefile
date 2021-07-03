PORTNAME=	drawing
DISTVERSION=	0.8.2
CATEGORIES=	graphics

MAINTAINER=	nc@FreeBSD.org
COMMENT=	Drawing application for the GNOME desktop

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cairo>=0:graphics/py-cairo@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cairo>=0:graphics/py-cairo@${PY_FLAVOR}

USES=		desktop-file-utils gettext gnome meson pkgconfig python:3.6+ \
		shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	maoschanz
USE_GNOME=	gtk30 pygobject3

GLIB_SCHEMAS=	com.github.maoschanz.drawing.gschema.xml
INSTALLS_ICONS=	yes
SHEBANG_FILES=	build-aux/meson/postinstall.py

.include <bsd.port.mk>
