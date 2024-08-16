PORTNAME=	librsvg
PORTVERSION=	2.58.3
CATEGORIES=	graphics gnome
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	2-rust
# XXX Teach USES=cargo to have proper default
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Library for parsing and rendering SVG vector-graphic files
WWW=		https://live.gnome.org/LibRsvg

LICENSE=	LGPL20

BUILD_DEPENDS=	rst2man:textproc/py-docutils
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libpng.so:graphics/png

USES=		cargo compiler:c11 cpe gettext gmake gnome libtool pkgconfig tar:xz vala:build
CPE_VENDOR=	gnome
USE_GNOME=	cairo gdkpixbuf2 libxml2 pango introspection:build
USE_LDCONFIG=	yes

PORTSCOUT=	limitw:1,even
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--disable-Bsymbolic \
		--disable-dependency-tracking \
		--disable-static \
		--enable-vala
CONFIGURE_ENV=	${CARGO_ENV}
MAKE_ENV=	${CARGO_ENV}
CARGO_ENV=	RUST_TARGET=${CARGO_BUILD_TARGET}
CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

CONFLICTS_INSTALL=	librsvg2

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	gi-docgen:textproc/py-gi-docgen
DOCS_CONFIGURE_ENABLE=	gtk-doc

TESTING_UNSAFE=	ld: error: undefined symbol: pthread_condattr_init

post-patch:
# Add explicit <triple> subdir for --target from USES=cargo
	@${REINPLACE_CMD} 's/test "x$$cross_compiling" = "xyes"/true/' \
		${WRKSRC}/configure

.include <bsd.port.mk>
