PORTNAME=	glade
PORTVERSION=	3.40.0
PORTREVISION=	7
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	User interface builder for GTK 3
WWW=		https://glade.gnome.org/

LICENSE=	GPLv2+ LGPL21+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING.GPL
LICENSE_FILE_LGPL21+ =	${WRKSRC}/COPYING.LGPL

BUILD_DEPENDS=	itstool:textproc/itstool \
		docbook-xsl>=0:textproc/docbook-xsl \
		xsltproc:textproc/libxslt

CONFLICTS=	glade3-3.*
PORTSCOUT=	limitw:1,even

USES=		compiler:c11 desktop-file-utils gettext gnome \
		localbase:ldflags meson pathfix pkgconfig tar:xz
USE_GNOME=	cairo gtk30 intlhack introspection:build

DOCSDIR=	${PREFIX}/share/doc/gladeui-2

OPTIONS_SUB=		yes
OPTIONS_DEFINE=		GJS PYTHON WEBKIT
OPTIONS_DEFAULT=	GJS PYTHON WEBKIT

GJS_DESC=		GJS (JavaScript) support
GJS_MESON_ENABLED=	gjs
GJS_LIB_DEPENDS=	libgjs.so:lang/gjs

PYTHON_MESON_ENABLED=	python
PYTHON_USES=		python
PYTHON_USE=		GNOME=pygobject3

WEBKIT_DESC=		Webkit glade support
WEBKIT_MESON_ENABLED=	webkit2gtk
WEBKIT_LIB_DEPENDS=	libsoup-2.4.so:devel/libsoup \
			libwebkit2gtk-4.0.so:www/webkit2-gtk@40

.include <bsd.port.mk>
