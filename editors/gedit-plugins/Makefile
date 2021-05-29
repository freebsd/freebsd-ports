# Created by: Adam Weinberger <adamw@FreeBSD.org>

PORTNAME=	gedit-plugins
PORTVERSION=	40.1
CATEGORIES=	editors gnome
MASTER_SITES=	GNOME/sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+)\..*/\1/}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Plugins for GEdit 3

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gedit>=0:editors/gedit \
		valac:lang/vala \
		itstool:textproc/itstool \
		${PYTHON_PKGNAMEPREFIX}dbus>=0:devel/py-dbus@${PY_FLAVOR}
LIB_DEPENDS=	libpeas-1.0.so:devel/libpeas \
		libgit2-glib-1.0.so:devel/libgit2-glib \
		libgucharmap_2_90.so:deskutils/gucharmap
RUN_DEPENDS=	gedit>=0:editors/gedit \
		${PYTHON_PKGNAMEPREFIX}dbus>=0:devel/py-dbus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}libpeas>=0:devel/py-libpeas@${PY_FLAVOR}

PORTSCOUT=	limitw:1,even

USES=		compiler:c11 gettext gnome localbase meson pkgconfig \
		python:3.4+ shebangfix tar:xz
USE_GNOME=	cairo gdkpixbuf2 gtk30 gtksourceview4 intlhack introspection \
		vte3
USE_CSTD=	c11
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
SHEBANG_FILES=	plugins/synctex/synctex/evince_dbus.py
BINARY_ALIAS=	python3=${PYTHON_CMD}

GLIB_SCHEMAS=	org.gnome.gedit.plugins.drawspaces.gschema.xml \
		org.gnome.gedit.plugins.wordcompletion.gschema.xml \
		org.gnome.gedit.plugins.terminal.gschema.xml \
		org.gnome.gedit.plugins.translate.gschema.xml

.include <bsd.port.mk>
