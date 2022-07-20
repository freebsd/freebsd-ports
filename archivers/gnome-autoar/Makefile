PORTNAME=	gnome-autoar
DISTVERSION=	0.4.3
CATEGORIES=	archivers
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Glib wrapper around libarchives

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	valac:lang/vala

USES=		cpe gettext-runtime gmake gnome libarchive meson pkgconfig \
		tar:xz

CPE_VENDOR=	gnome
USE_GNOME=	cairo gdkpixbuf2 gtk30 introspection:build

OPTIONS_DEFINE=	DOCS

DOCS_MESON_TRUE=	gtk_doc
DOCS_BUILD_DEPENDS=	gtk-doc>0:textproc/gtk-doc

.include <bsd.port.mk>
