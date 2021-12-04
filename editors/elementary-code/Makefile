PORTNAME=	elementary-code
DISTVERSION=	6.0.0
PORTREVISION=	1
CATEGORIES=	editors

MAINTAINER=	miguel@gocobachi.dev
COMMENT=	Code editor designed for elementary OS

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	valac:lang/vala
RUN_DEPENDS=	droid-fonts-ttf>0:x11-fonts/droid-fonts-ttf \
		pkcheck:sysutils/polkit
LIB_DEPENDS=	libatk-1.0.so:accessibility/atk \
		libeditorconfig.so:editors/editorconfig-core-c \
		libfontconfig.so:x11-fonts/fontconfig \
		libgee-0.8.so:devel/libgee \
		libgit2-glib-1.0.so:devel/libgit2-glib \
		libgranite.so:x11-toolkits/granite \
		libgtkspell3-3.so:textproc/gtkspell3 \
		libhandy-1.so:x11-toolkits/libhandy \
		libpeas-1.0.so:devel/libpeas \
		libpeas-gtk-1.0.so:devel/libpeas \
		libsoup-2.4.so:devel/libsoup \
		libvala-0.48.so:lang/vala \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3 \
		libzeitgeist-2.0.so:sysutils/zeitgeist

USES=		compiler:c++11-lang desktop-file-utils gettext gnome meson \
		ninja pkgconfig python:3.6+,build xorg
USE_GITHUB=	yes
GH_ACCOUNT=	elementary
GH_PROJECT=	code
USE_GNOME=	cairo glib20 gtk30 gtksourceview4 pango vte3
GLIB_SCHEMAS=	io.elementary.code.gschema.xml \
		io.elementary.code.plugins.spell.gschema.xml \
		io.elementary.code.plugins.terminal.gschema.xml
USE_LDCONFIG=	yes
USE_XORG=	x11

BINARY_ALIAS=	python3=${PYTHON_CMD}

do-test:
	cd ${WRKSRC}/${MESON_BUILD_DIR} && ninja test

.include <bsd.port.mk>
