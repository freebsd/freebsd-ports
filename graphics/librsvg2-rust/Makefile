# Created by: Ade Lovett <ade@FreeBSD.org>
# $FreeBSD$

PORTNAME=	librsvg
PORTVERSION=	2.46.4
PORTREVISION=	3
CATEGORIES=	graphics gnome
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	2-rust
DIST_SUBDIR=	gnome2

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Library for parsing and rendering SVG vector-graphic files

LICENSE=	LGPL20

BUILD_DEPENDS=	${RUST_DEFAULT}>=1.34.0:lang/${RUST_DEFAULT} \
		valac:lang/vala
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libpng.so:graphics/png \
		libcroco-0.6.so:textproc/libcroco

USES=		gettext gmake gnome libtool pkgconfig tar:xz
USE_GNOME=	cairo gdkpixbuf2 libxml2 pango gnomeprefix introspection:build
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-vala \
		--disable-Bsymbolic \
		--disable-dependency-tracking \
		--disable-static
# Make sure it uses the Rust toolchain from ports.
CONFIGURE_ENV=	CARGO=${LOCALBASE}/bin/cargo \
		RUSTC=${LOCALBASE}/bin/rustc
MAKE_ENV=	RUSTC=${LOCALBASE}/bin/rustc
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
