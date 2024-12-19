PORTNAME=	appstream-glib
PORTVERSION=	0.8.3
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://people.freedesktop.org/~hughsient/appstream-glib/releases/
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library to help with AppStream metadata
WWW=		https://github.com/hughsie/appstream-glib/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gcab:archivers/gcab
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libjson-glib-1.0.so:devel/json-glib \
		libyaml.so:textproc/libyaml \
		libuuid.so:misc/libuuid \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2
RUN_DEPENDS=	gcab:archivers/gcab

CONFLICTS_BUILD=	appstream-glib-0.5.*

USES=		compiler:c11 gettext gperf gnome libarchive meson \
		pkgconfig sqlite tar:xz
USE_GNOME=	cairo gdkpixbuf glib20 gtk30 introspection:build \
		libxml2:build pango
USE_LDCONFIG=	yes
MESON_ARGS=	-Drpm=false \
		-Dalpm=false

TESTING_UNSAFE=	not ok /AppStream/app - As:ERROR:../libappstream-glib/as-self-test.c:2134:as_test_app_func: assertion failed (as_app_get_update_contact (app) == "richard@hughsie.co.uk")

OPTIONS_DEFINE=	DOCS MANPAGES
OPTIONS_DEFAULT=MANPAGES
OPTIONS_SUB=	yes

DOCS_BUILD_DEPENDS=	gtkdoc-check:textproc/gtk-doc
DOCS_MESON_TRUE=	gtk-doc
DOCSDIR=		${PREFIX}/share/gtk-doc/html/appstream-glib

MANPAGES_MESON_TRUE=	man
MANPAGES_BUILD_DEPENDS=	docbook-xml>=0:textproc/docbook-xml \
			docbook-xsl>=0:textproc/docbook-xsl
MANPAGES_USE=	GNOME=libxslt:build

.include <bsd.port.mk>
