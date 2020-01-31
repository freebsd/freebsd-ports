# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xed
PORTVERSION=	2.4.2
CATEGORIES=	editors

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Small and lightweight graphical text editor

LICENSE=	GPLv2

BUILD_DEPENDS=	intltool-merge:textproc/intltool \
		itstool:textproc/itstool
LIB_DEPENDS=	libpeas-1.0.so:devel/libpeas \
		libxapp.so:x11/xapps
RUN_DEPENDS=	${LOCALBASE}/share/glib-2.0/schemas/org.gnome.desktop.interface.gschema.xml:devel/gsettings-desktop-schemas

USES=		desktop-file-utils gettext-tools gnome meson pkgconfig xorg
USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk30 gtksourceview3 \
		introspection pango
USE_XORG=	x11
GLIB_SCHEMAS=	org.x.editor.gschema.xml \
		org.x.editor.plugins.filebrowser.gschema.xml \
		org.x.editor.plugins.time.gschema.xml \
		org.x.editor.plugins.wordcompletion.gschema.xml

# XXX: should become OPTIONs
MESON_ARGS=	-Denable_spell=false

.include <bsd.port.mk>
