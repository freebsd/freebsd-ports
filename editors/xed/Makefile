# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>

PORTNAME=	xed
PORTVERSION=	3.0.2
CATEGORIES=	editors gnome
DIST_SUBDIR=	gnome

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Small but powerful graphical text editor

LICENSE=	GPLv2+

PORTSCOUT=	limit:^[0-9.]+$$	# ignore master.mint* tags

BUILD_DEPENDS=	intltool-merge:textproc/intltool \
		itstool:textproc/itstool
LIB_DEPENDS=	libpeas-1.0.so:devel/libpeas \
		libxapp.so:x11/xapp
RUN_DEPENDS=	${LOCALBASE}/share/glib-2.0/schemas/org.gnome.desktop.interface.gschema.xml:devel/gsettings-desktop-schemas \
		${PYTHON_PKGNAMEPREFIX}libpeas>=0:devel/py-libpeas@${PY_FLAVOR} \
		yelp:x11/yelp

USES=		compiler:c++11-lang desktop-file-utils gettext-tools gnome meson \
		pkgconfig python:3.6+,run xorg
USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk30 gtksourceview4 \
		introspection pango
USE_LDCONFIG=	yes
USE_XORG=	x11
GLIB_SCHEMAS=	org.x.editor.gschema.xml \
		org.x.editor.plugins.filebrowser.gschema.xml \
		org.x.editor.plugins.time.gschema.xml \
		org.x.editor.plugins.wordcompletion.gschema.xml

OPTIONS_DEFINE=	DOCS GSPELL
OPTIONS_DEFAULT=	GSPELL
GSPELL_DESC=	Spell checking support via gspell

DOCS_BUILD_DEPENDS=	gtkdoc-scan:textproc/gtk-doc
DOCS_MESON_ON=		-Ddocs=true

GSPELL_LIB_DEPENDS=	libgspell-1.so:textproc/gspell
GSPELL_MESON_OFF=	-Denable_spell=false
GSPELL_PLIST_FILES=	lib/xed/plugins/libspell.so \
			lib/xed/plugins/spell.plugin \
		${DATADIR_REL}/plugins/spell/xed-spell-setup-dialog.ui
GSPELL_VARS=	GLIB_SCHEMAS+=org.x.editor.plugins.spell.gschema.xml

.include <bsd.port.mk>
