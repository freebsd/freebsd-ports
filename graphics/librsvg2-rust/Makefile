# Created by: Ade Lovett <ade@FreeBSD.org>

PORTNAME=	librsvg
PORTVERSION=	2.52.5
PORTREVISION=	2
CATEGORIES=	graphics gnome
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	2-rust
DIST_SUBDIR=	gnome2

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Library for parsing and rendering SVG vector-graphic files

LICENSE=	LGPL20

BUILD_DEPENDS=	${RUST_DEFAULT}>=1.39.0:lang/${RUST_DEFAULT} \
		valac:lang/vala
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libpng.so:graphics/png

USES=		compiler:c11 cpe gettext gmake gnome libtool pkgconfig tar:xz
CPE_VENDOR=	gnome
USE_GNOME=	cairo gdkpixbuf2 gnomeprefix libxml2 pango introspection:build
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-Bsymbolic \
		--disable-dependency-tracking \
		--disable-static \
		--enable-vala
# Make sure it uses the Rust toolchain from ports.
CONFIGURE_ENV=	CARGO=${LOCALBASE}/bin/cargo \
		RUSTC=${LOCALBASE}/bin/rustc \
		RUSTFLAGS="${RUSTFLAGS} -C linker=${CC:Q} ${LDFLAGS:C/.+/-C link-arg=&/}"
MAKE_ENV=	CARGO_BUILD_JOBS=${MAKE_JOBS_NUMBER} \
		RUSTC=${LOCALBASE}/bin/rustc \
		RUSTFLAGS="${RUSTFLAGS} -C linker=${CC:Q} ${LDFLAGS:C/.+/-C link-arg=&/}"
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

CONFLICTS_INSTALL=	librsvg2

post-patch:
# Disable vendor checksums
	@${REINPLACE_CMD} -e 's/"files":{[^}]*}/"files":{}/' \
		${WRKSRC}/vendor/*/.cargo-checksum.json

pre-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${LOCALBASE}/bin/cargo update

.include <bsd.port.mk>
