PORTNAME=	gedit
PORTVERSION=	48.1
CATEGORIES=	editors gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Small but powerful GTK text editor
WWW=		https://gitlab.gnome.org/World/gedit/gedit

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas \
		itstool:textproc/itstool
LIB_DEPENDS=	libgspell-1.so:textproc/gspell \
		libpeas-gtk-1.0.so:devel/libpeas1 \
		libgedit-gtksourceview-300.so:x11-toolkits/libgedit-gtksourceview \
		libgedit-gfls-1.so:filesystems/libgedit-gfls \
		libgedit-amtk-5.so:x11-toolkits/amtk \
		libgedit-tepl-6.so:x11-toolkits/tepl6
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}libpeas1>0:devel/py-libpeas1@${PY_FLAVOR}

USES=		compiler:c11 cpe desktop-file-utils gettext gnome localbase \
		meson pkgconfig python tar:xz vala:build xorg
USE_CSTD=	c11
USE_GNOME=	glib20 gtk30 introspection libxml2 \
		pygobject3
USE_XORG=	sm x11
USE_LDCONFIG=	yes
PLIST_SUB=	VERSION=${DISTVERSION}
MESON_ARGS=	-Dgtk_doc=false
BINARY_ALIAS=	python3=${PYTHON_CMD}
CPE_VENDOR=	gnome

GLIB_SCHEMAS=	org.gnome.gedit.enums.xml \
		org.gnome.gedit.gschema.xml \
		org.gnome.gedit.plugins.filebrowser.enums.xml \
		org.gnome.gedit.plugins.filebrowser.gschema.xml \
		org.gnome.gedit.plugins.spell.gschema.xml \
		org.gnome.gedit.plugins.time.enums.xml \
		org.gnome.gedit.plugins.time.gschema.xml

.include <bsd.port.mk>
