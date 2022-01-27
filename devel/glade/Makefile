# Created by: Koop Mast <kwm@FreeBSD.org>

PORTNAME=	glade
PORTVERSION=	3.38.2
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

PATCH_SITES=	https://gitlab.gnome.org/GNOME/${PORTNAME}/-/commit/
PATCHFILES+=	04ba6f96.patch:-p1 \
		61304b2e.patch:-p1

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	User interface builder for GTK+ 3

LICENSE=	GPLv2+ LGPL21+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING.GPL
LICENSE_FILE_LGPL21+ =	${WRKSRC}/COPYING.LGPL

BUILD_DEPENDS=	itstool:textproc/itstool \
		rarian-sk-config:textproc/rarian

CONFLICTS=	glade3-3.*
PORTSCOUT=	limitw:1,even

USES=		compiler:c11 desktop-file-utils gettext gnome localbase:ldflags \
		meson pathfix pkgconfig tar:xz
USE_GNOME=	cairo gtk30 intlhack introspection:build

DOCSDIR=	${PREFIX}/share/doc/gladeui-2

OPTIONS_SUB=		yes
OPTIONS_DEFINE=		GJS PYTHON WEBKIT
OPTIONS_DEFAULT=	GJS PYTHON WEBKIT

GJS_MESON_ENABLED=	gjs
GJS_LIB_DEPENDS=	libgjs.so:lang/gjs

PYTHON_MESON_ENABLED=	python
PYTHON_USES=		python:3.4+
PYTHON_USE=		GNOME=pygobject3

WEBKIT_DESC=		Webkit glade support
WEBKIT_MESON_ENABLED=	webkit2gtk
WEBKIT_LIB_DEPENDS=	libsoup-2.4.so:devel/libsoup \
			libwebkit2gtk-4.0.so:www/webkit2-gtk3

.include <bsd.port.mk>
