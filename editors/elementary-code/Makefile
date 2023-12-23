PORTNAME=	elementary-code
DISTVERSION=	7.1.0
PORTREVISION=	3
CATEGORIES=	editors

MAINTAINER=	miguel@gocobachi.dev
COMMENT=	Code editor designed for elementary OS
WWW=		https://github.com/elementary/code

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libeditorconfig.so:editors/editorconfig-core-c \
		libfontconfig.so:x11-fonts/fontconfig \
		libgee-0.8.so:devel/libgee \
		libgit2-glib-1.0.so:devel/libgit2-glib \
		libgranite.so:x11-toolkits/granite \
		libgtkspell3-3.so:textproc/gtkspell3 \
		libhandy-1.so:x11-toolkits/libhandy \
		libpeas-1.0.so:devel/libpeas \
		libpeas-gtk-1.0.so:devel/libpeas \
		libsoup-2.4.so:devel/libsoup \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3
RUN_DEPENDS=	droid-fonts-ttf>0:x11-fonts/droid-fonts-ttf \
		pkcheck:sysutils/polkit

USES=		compiler:c++11-lang desktop-file-utils gettext gnome meson \
		ninja pkgconfig python:build vala:lib xorg
USE_GITHUB=	yes
GH_ACCOUNT=	elementary
GH_PROJECT=	code
USE_GNOME=	atk cairo glib20 gtk30 gtksourceview4 pango vte3
GLIB_SCHEMAS=	io.elementary.code.gschema.xml \
		io.elementary.code.plugins.spell.gschema.xml
USE_LDCONFIG=	yes
USE_XORG=	x11

BINARY_ALIAS=	python3=${PYTHON_CMD}

do-test:
	cd ${WRKSRC}/${MESON_BUILD_DIR} && ninja test

.include <bsd.port.mk>
