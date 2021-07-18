PORTNAME=	elementary-code
DISTVERSION=	3.4.1
PORTREVISION=	3
CATEGORIES=	editors

MAINTAINER=	miguel@gocobachi.dev
COMMENT=	Code editor designed for elementary OS

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libatk-1.0.so:accessibility/atk \
		libeditorconfig.so:editors/editorconfig-core-c \
		libfontconfig.so:x11-fonts/fontconfig \
		libgee-0.8.so:devel/libgee \
		libgit2-glib-1.0.so:devel/libgit2-glib \
		libgranite.so:x11-toolkits/granite \
		libgtksourceview-3.0.so:x11-toolkits/gtksourceview3 \
		libgtkspell3-3.so:textproc/gtkspell3 \
		libpeas-1.0.so:devel/libpeas \
		libpeas-gtk-1.0.so:devel/libpeas \
		libsoup-2.4.so:devel/libsoup \
		libvala-0.48.so:lang/vala \
		libvte-2.91.so:x11-toolkits/vte3 \
		libvterm.so:devel/libvterm \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3 \
		libzeitgeist-2.0.so:sysutils/zeitgeist

USES=		compiler:c++11-lang desktop-file-utils gettext gnome meson \
		ninja pkgconfig python:build xorg
USE_GITHUB=	yes
GH_ACCOUNT=	elementary
GH_PROJECT=	code
USE_GNOME=	cairo glib20 gtk30 gtksourceview3 pango
GLIB_SCHEMAS=	io.elementary.code.gschema.xml \
		io.elementary.code.plugins.spell.gschema.xml \
		io.elementary.code.plugins.terminal.gschema.xml
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
USE_XORG=	x11

BINARY_ALIAS=	python3=${PYTHON_CMD}

do-test:
	cd ${WRKSRC}/${MESON_BUILD_DIR} && ninja test

.include <bsd.port.mk>
