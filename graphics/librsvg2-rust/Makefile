PORTNAME=	librsvg
DISTVERSION=	2.60.0
PORTREVISION=	5
CATEGORIES=	graphics gnome
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	2-rust
# XXX Teach USES=cargo to have proper default
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Library for parsing and rendering SVG vector-graphic files
WWW=		https://live.gnome.org/LibRsvg

LICENSE=	LGPL20

BUILD_DEPENDS=	cargo-cbuild:devel/cargo-c \
		rst2man:textproc/py-docutils
LIB_DEPENDS=	libdav1d.so:multimedia/dav1d \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libpng.so:graphics/png
TEST_DEPENDS=	urw-base35-fonts>0:x11-fonts/urw-base35-fonts

USES=		cargo compiler:c11 cpe gettext gnome meson pkgconfig \
		python:build shebangfix tar:xz
CPE_VENDOR=	gnome
SHEBANG_FILES=	meson/*.py \
		benchmarks/*.py \
		gdk-pixbuf-loader/*.py
USE_GNOME=	cairo gdkpixbuf libxml2 pango introspection:build
USE_LDCONFIG=	yes

CONFLICTS_INSTALL=	librsvg2
PORTSCOUT=	limitw:1,even

CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no

CONFIGURE_ENV=  ${CARGO_ENV}
MAKE_ENV=       ${CARGO_ENV}

MESON_ARGS=	-Dtests=true

OPTIONS_DEFINE=		DOCS VAPI
OPTIONS_DEFAULT=	VAPI
OPTIONS_SUB=		yes

DOCS_BUILD_DEPENDS=	gi-docgen:textproc/py-gi-docgen
DOCS_MESON_ENABLED=	docs

VAPI_MESON_ENABLED=	vala
VAPI_USES=		vala:build

post-install-DOCS-off:
	${LOCALBASE}/bin/rst2man --no-datestamp ${WRKSRC}/rsvg-convert.rst > ${STAGEDIR}${PREFIX}/share/man/man1/rsvg-convert.1

.include <bsd.port.mk>
