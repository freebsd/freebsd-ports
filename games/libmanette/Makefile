PORTNAME=	libmanette
DISTVERSION=	0.2.6
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Simple GObject game controller library

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	vapigen:lang/vala \
		evdev-proto>0:devel/evdev-proto
LIB_DEPENDS=	libevdev.so:devel/libevdev \
		libgudev-1.0.so:devel/libgudev

USES=		compiler:c11 gnome meson pkgconfig tar:xz
USE_GNOME=	glib20 introspection
USE_LDCONFIG=	yes

MESON_ARGS=	-Dgudev=enabled

OPTIONS_DEFINE=	DOCS EXAMPLES TEST
OPTIONS_SUB=	yes

DOCS_BUILD_DEPENDS=	gtkdocize:textproc/gtk-doc
DOCS_MESON_TRUE=	doc
EXAMPLES_MESON_TRUE=	demos
TEST_MESON_TRUE=	build-tests

.include <bsd.port.mk>
