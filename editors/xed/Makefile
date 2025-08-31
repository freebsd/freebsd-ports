PORTNAME=	xed
PORTVERSION=	3.8.2
PORTREVISION=	4
CATEGORIES=	editors gnome
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Small but powerful text editor for GTK
WWW=		https://github.com/linuxmint/xed

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libenchant-2.so:textproc/enchant2 \
		libpeas-1.0.so:devel/libpeas1 \
		libxapp.so:x11/xapp
RUN_DEPENDS=	${LOCALBASE}/share/glib-2.0/schemas/org.gnome.desktop.interface.gschema.xml:devel/gsettings-desktop-schemas \
		${PYTHON_PKGNAMEPREFIX}libpeas1>=0:devel/py-libpeas1@${PY_FLAVOR} \
		yelp:x11/yelp

USES=		compiler:c++11-lang desktop-file-utils gettext-tools gnome meson \
		pkgconfig python:run xorg
USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint
USE_GNOME=	atk cairo gdkpixbuf glib20 gtk30 gtksourceview4 intltool \
		introspection pango
USE_LDCONFIG=	yes
USE_XORG=	x11
GLIB_SCHEMAS=	org.x.editor.gschema.xml \
		org.x.editor.plugins.filebrowser.gschema.xml \
		org.x.editor.plugins.time.gschema.xml \
		org.x.editor.plugins.wordcompletion.gschema.xml

PORTSCOUT=	limit:^[0-9.]+$$	# ignore master.mint* tags

OPTIONS_DEFINE=		DOCS GSPELL GVFS_METADATA
OPTIONS_DEFAULT=	DOCS GSPELL GVFS_METADATA
OPTIONS_SUB=		yes

GSPELL_DESC=		Spell checking support via gspell
GVFS_METADATA_DESC=	GVFS metadata

DOCS_BUILD_DEPENDS=	gtkdocize:textproc/gtk-doc
DOCS_MESON_TRUE=	docs

GSPELL_LIB_DEPENDS=	libgspell-1.so:textproc/gspell
GSPELL_MESON_TRUE=	enable_spell
GSPELL_VARS=	GLIB_SCHEMAS+=org.x.editor.plugins.spell.gschema.xml

GVFS_METADATA_MESON_TRUE=	enable_gvfs_metadata

.include <bsd.port.mk>
