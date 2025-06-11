PORTNAME=	gedit-plugins
PORTVERSION=	48.1
CATEGORIES=	editors gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Plugins for gedit
WWW=		https://gitlab.gnome.org/World/gedit/gedit-plugins

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gedit>=48.1:editors/gedit \
		itstool:textproc/itstool
LIB_DEPENDS=	libpeas-1.0.so:devel/libpeas1 \
		libgucharmap_2_90.so:deskutils/gucharmap \
		libgedit-tepl-6.so:x11-toolkits/tepl6 \
		libgedit-gtksourceview-300.so:x11-toolkits/libgedit-gtksourceview
RUN_DEPENDS=	gedit>=48.1:editors/gedit \
		${PYTHON_PKGNAMEPREFIX}libpeas1>0:devel/py-libpeas1@${PY_FLAVOR}

USES=		compiler:c11 gettext gnome localbase meson pkgconfig \
		python tar:xz
USE_GNOME=	glib20 gtk30 introspection pygobject3 \
		vte3
USE_CSTD=	c11
USE_LDCONFIG=	yes
BINARY_ALIAS=	python3=${PYTHON_CMD}

GLIB_SCHEMAS=	org.gnome.gedit.plugins.drawspaces.gschema.xml \
		org.gnome.gedit.plugins.wordcompletion.gschema.xml \
		org.gnome.gedit.plugins.terminal.gschema.xml

.include <bsd.port.mk>
