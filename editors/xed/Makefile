# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xed
PORTVERSION=	2.6.0
CATEGORIES=	editors

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Small and lightweight graphical text editor

LICENSE=	GPLv2+

PORTSCOUT=	limit:^[0-9.]+$$	# ignore master.mint* tags

BUILD_DEPENDS=	intltool-merge:textproc/intltool \
		itstool:textproc/itstool
LIB_DEPENDS=	libpeas-1.0.so:devel/libpeas \
		libxapp.so:x11/xapps
RUN_DEPENDS=	${LOCALBASE}/share/glib-2.0/schemas/org.gnome.desktop.interface.gschema.xml:devel/gsettings-desktop-schemas

USES=		compiler:c++11-lang desktop-file-utils gettext-tools gnome meson \
		pkgconfig xorg
USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk30 gtksourceview3 \
		introspection pango
USE_LDCONFIG=	yes
USE_XORG=	x11
GLIB_SCHEMAS=	org.x.editor.gschema.xml \
		org.x.editor.plugins.filebrowser.gschema.xml \
		org.x.editor.plugins.time.gschema.xml \
		org.x.editor.plugins.wordcompletion.gschema.xml

OPTIONS_DEFINE=	GSPELL
OPTIONS_DEFAULT=	GSPELL
GSPELL_DESC=	Spell checking support via gspell

GSPELL_LIB_DEPENDS=	libgspell-1.so:textproc/gspell
GSPELL_MESON_OFF=	-Denable_spell=false
GSPELL_PLIST_FILES=	lib/xed/plugins/libspell.so \
			lib/xed/plugins/spell.plugin \
		${DATADIR_REL}/plugins/spell/xed-spell-setup-dialog.ui
GSPELL_VARS=	GLIB_SCHEMAS+=org.x.editor.plugins.spell.gschema.xml

.include <bsd.port.mk>
